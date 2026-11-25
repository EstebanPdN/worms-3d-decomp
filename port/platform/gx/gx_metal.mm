extern "C" int w3d_ui_panel_active();
#include "../macos/dual_layout.h"
// Backend de GX sobre Metal directo: tuberías por clave, caché de texturas, EFB, copia a XFB y presentación.
#include "gx_internal.h"
#include "../platform.h"
#include "w3d_ptr.h"
#import <Metal/Metal.h>
#import <QuartzCore/CAMetalLayer.h>
#include <dispatch/dispatch.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

extern "C" void w3d_ui_frame(void);        // platform/ui/ui_core.cpp
extern "C" void w3d_ui_after_frame(void);
extern "C" int w3d_ui_tall(void);         // menús y título: el fondo 3D sigue abajo
struct W3dUiSig { unsigned short w, h; unsigned char px[16][4]; };
extern "C" void w3d_ui_sig_make(const unsigned char *rgba, unsigned w, unsigned h, W3dUiSig *s);
extern "C" unsigned w3d_ui_hide_gen(void);
extern "C" int w3d_ui_sig_hidden(const W3dUiSig *s);
extern "C" void w3d_ui_hidden_drawn(int id);
extern "C" float w3d_ui_hidden_min_h(int id);
extern "C" const unsigned char *w3d_ui_tex_swap(const W3dUiSig *s, const unsigned char *rgba, unsigned *w, unsigned *h);

extern "C" int w3d_fe_game_mode(void);
extern "C" int w3d_hud_screen_camera(void);
extern "C" int w3d_ui_map_texture(float *,float *);
extern "C" int w3d_ui_hud_team_rows(void);
extern "C" int w3d_fe_prop_int(const char *,int);
extern "C" unsigned w3d_fe_prop_uint(const char *,unsigned);
extern "C" int w3d_fe_popup_depth(void);
extern "C" const char *w3d_fe_last_popup(void);
extern "C" int w3d_ui_popup_veil(void);   // ui_pages.cpp: 0 si la ventana del juego no oscurece
extern "C" void w3d_gx_flush_camera() { w3d::gx::flush_batch(); }
namespace w3d {
namespace gx {
namespace backend {

namespace {

const int kEfbW = 640, kEfbH = 528;
int efb_alloc_h = kEfbH;   // con dos pantallas, el doble (lienzo alto de los menús)
const int kInFlight = 3;

struct FrameBuf { id<MTLBuffer> vb, ib; size_t voff, ioff; };

id<MTLDevice> dev;
id<MTLCommandQueue> queue;
id<MTLTexture> efb_color, efb_depth;
id<MTLCommandBuffer> cmd;
id<MTLRenderCommandEncoder> enc;
dispatch_semaphore_t inflight;
FrameBuf frames[kInFlight];
int frame_index;
int scale = 1;
bool pending_clear_color = true, pending_clear_depth = true;
float clear_rgba[4] = {0, 0, 0, 1};
double clear_depth = 1.0;
id<MTLRenderPipelineState> copy_pipe, present_pipe;
id<MTLSamplerState> linear_clamp;
id<MTLTexture> black_tex;
std::vector<id<MTLTexture>> xfb_pool;
int xfb_next;

// Estado actual del codificador, para no repetir.
id<MTLRenderPipelineState> cur_pipe;
id<MTLDepthStencilState> cur_ds;
int cur_cull = -1;
MTLViewport cur_vp;
MTLScissorRect cur_sc;
bool have_vp, have_sc;
id<MTLTexture> cur_tex[8];
id<MTLSamplerState> cur_smp[8];

struct PipeEntry { PipelineKey key; id<MTLRenderPipelineState> ps; bool failed; };
std::unordered_map<uint64_t, std::vector<PipeEntry>> pipes;
std::unordered_map<std::string, id<MTLLibrary>> libraries;
std::unordered_map<u32, id<MTLDepthStencilState>> ds_cache;
std::unordered_map<uint64_t, id<MTLSamplerState>> smp_cache;

struct TexEntry {
    id<MTLTexture> tex;
    uint64_t hash;
    u32 epoch;
    u32 last_frame;
    size_t bytes;
    W3dUiSig sig;        // dos pantallas: firma para ocultar piezas del menú arriba (platform/ui/ui_hide.cpp)
    unsigned hide_gen;
    int hidden;          // 0, o el número de la imagen oculta (ui_hide.cpp)
};
bool g_tex_hidden;       // la última textura de texture_for está oculta
int g_tex_hidden_id;     // y su número en ui_hide.cpp
bool entry_hidden(TexEntry &e) {
    unsigned gen = w3d_ui_hide_gen();
    if (e.hide_gen != gen) { e.hide_gen = gen; e.hidden = e.sig.w ? w3d_ui_sig_hidden(&e.sig) : 0; }
    if (e.hidden) { w3d_ui_hidden_drawn(e.hidden); g_tex_hidden_id = e.hidden; }
    return e.hidden != 0;
}
std::unordered_map<uint64_t, TexEntry> textures;
u32 frame_counter;
size_t tex_total_bytes;
std::unordered_map<uint64_t, u32> frame_seen;

uint64_t hash_bytes(const void *p, size_t n) {
    const u8 *s = (const u8 *)p;
    uint64_t h = 0xcbf29ce484222325ull;
    for (size_t i = 0; i < n; i++) h = (h ^ s[i]) * 0x100000001b3ull;
    return h;
}

id<MTLSamplerState> sampler_for(const GTexObj &o) {
    uint64_t k = (uint64_t)o.wrap_s | (uint64_t)o.wrap_t << 4 | (uint64_t)o.min_filter << 8 | (uint64_t)o.mag_filter << 12 | (uint64_t)o.aniso << 16 | (uint64_t)o.min_lod16 << 24 | (uint64_t)o.max_lod16 << 32;
    auto it = smp_cache.find(k);
    if (it != smp_cache.end()) return it->second;
    MTLSamplerDescriptor *d = [MTLSamplerDescriptor new];
    auto wrap = [](u8 w) { return w == 1 ? MTLSamplerAddressModeRepeat : w == 2 ? MTLSamplerAddressModeMirrorRepeat : MTLSamplerAddressModeClampToEdge; };
    d.sAddressMode = wrap(o.wrap_s);
    d.tAddressMode = wrap(o.wrap_t);
    d.magFilter = o.mag_filter ? MTLSamplerMinMagFilterLinear : MTLSamplerMinMagFilterNearest;
    // GX_NEAR, LINEAR, NEAR_MIP_NEAR, LIN_MIP_NEAR, NEAR_MIP_LIN, LIN_MIP_LIN.
    d.minFilter = (o.min_filter == 1 || o.min_filter == 3 || o.min_filter == 5) ? MTLSamplerMinMagFilterLinear : MTLSamplerMinMagFilterNearest;
    d.mipFilter = o.min_filter < 2 ? MTLSamplerMipFilterNotMipmapped : o.min_filter < 4 ? MTLSamplerMipFilterNearest : MTLSamplerMipFilterLinear;
    d.lodMinClamp = o.min_lod16 / 16.f;
    d.lodMaxClamp = o.max_lod16 / 16.f;
    d.maxAnisotropy = o.aniso == 2 ? 4 : o.aniso == 1 ? 2 : 1;
    id<MTLSamplerState> s = [dev newSamplerStateWithDescriptor:d];
    smp_cache[k] = s;
    return s;
}

u32 mip_levels(const GTexObj &o) {
    if (!o.mip) return 1;
    u32 m = o.width > o.height ? o.width : o.height, l = 1;
    while (m > 1) { m >>= 1; l++; }
    return l;
}

// Textura de Metal para el objeto. Decodifica solo si cambió el contenido desde la última vez.
bool dual_mode();
id<MTLTexture> texture_for(const GTexObj &o) {
    g_tex_hidden = false;
    if (!o.image || !o.width || !o.height) return black_tex;
    u32 fmt = o.format & 0xf;
    u32 levels = mip_levels(o);
    bool ci = fmt == TEX_CI4 || fmt == TEX_CI8 || fmt == TEX_CI14;
    uint64_t key = (uint64_t)o.image | (uint64_t)o.width << 32 | (uint64_t)o.height << 44 | (uint64_t)fmt << 56 | (uint64_t)(o.mip & 1) << 60 | (uint64_t)(ci ? (o.tlut & 7) : 0) << 61;
    auto it = textures.find(key);
    TexEntry *e = it == textures.end() ? nullptr : &it->second;
    // Una comprobación por imagen y por GXInvalidateTexAll: un plano de película cambia sin invalidar.
    if (e && e->epoch == g.tex_epoch && e->last_frame == frame_counter) { g_tex_hidden = entry_hidden(*e); return e->tex; }
    const u8 *src = (const u8 *)g2h(o.image);
    size_t bytes = 0;
    {
        u32 w = o.width, h = o.height;
        for (u32 l = 0; l < levels; l++) {
            bytes += tex_level_bytes(w, h, fmt);
            w = w > 1 ? w >> 1 : 1;
            h = h > 1 ? h >> 1 : 1;
        }
    }
    const TlutSlot *tl = ci ? &tlut_slot(o.tlut) : nullptr;
    uint64_t hash = tex_hash(src, bytes) ^ (tl ? tl->hash : 0);
    if (e && e->hash == hash) {
        e->epoch = g.tex_epoch;
        e->last_frame = frame_counter;
        g_tex_hidden = entry_hidden(*e);
        return e->tex;
    }
    // Dos pantallas: algunas texturas del juego se cambian por una copia retocada, del mismo tamaño o mayor (mismas
    // coordenadas de textura): ui_hide.cpp, w3d_ui_tex_swap. Sus mips se hacen reduciendo la copia.
    const u8 *swap = nullptr; unsigned sw = 0, sh = 0;
    if (dual_mode()) {
        std::vector<u8> l0((size_t)o.width * o.height * 4);
        tex_decode(src, o.width, o.height, fmt, tl ? tl->entries : nullptr, tl ? tl->format : 0, l0.data());
        W3dUiSig s0; w3d_ui_sig_make(l0.data(), o.width, o.height, &s0);
        swap = w3d_ui_tex_swap(&s0, l0.data(), &sw, &sh);
    }
    u32 slevels = 1;
    if (swap && levels > 1) { u32 m = sw > sh ? sw : sh; while (m > 1) { m >>= 1; slevels++; } }
    MTLTextureDescriptor *td = [MTLTextureDescriptor texture2DDescriptorWithPixelFormat:MTLPixelFormatRGBA8Unorm width:swap ? sw : o.width height:swap ? sh : o.height mipmapped:(swap ? slevels : levels) > 1];
    if ((swap ? slevels : levels) > 1) td.mipmapLevelCount = swap ? slevels : levels;
    td.storageMode = MTLStorageModeShared;
    td.usage = MTLTextureUsageShaderRead;
    id<MTLTexture> t = [dev newTextureWithDescriptor:td];
    std::vector<u8> rgba;
    u32 w = o.width, h = o.height;
    const u8 *p = src;
    if (swap) {
        std::vector<u8> cur(swap, swap + (size_t)sw * sh * 4);
        u32 cw = sw, ch = sh;
        for (u32 l = 0; l < slevels; l++) {
            if (l) {   // 2x2 del nivel anterior
                const u32 nw = cw > 1 ? cw / 2 : 1, nh = ch > 1 ? ch / 2 : 1;
                std::vector<u8> next((size_t)nw * nh * 4);
                for (u32 y = 0; y < nh; y++) for (u32 x = 0; x < nw; x++) for (int c = 0; c < 4; c++) {
                    unsigned sum = 0;
                    for (int dy = 0; dy < 2; dy++) for (int dx = 0; dx < 2; dx++) sum += cur[((size_t)(MIN(y * 2 + dy, ch - 1)) * cw + MIN(x * 2 + dx, cw - 1)) * 4 + c];
                    next[((size_t)y * nw + x) * 4 + c] = (u8)(sum / 4);
                }
                cur.swap(next); cw = nw; ch = nh;
            }
            [t replaceRegion:MTLRegionMake2D(0, 0, cw, ch) mipmapLevel:l withBytes:cur.data() bytesPerRow:cw * 4];
        }
        levels = 0;   // the game's own levels are not uploaded
    }
    for (u32 l = 0; l < levels; l++) {
        rgba.resize((size_t)w * h * 4);
        tex_decode(p, w, h, fmt, tl ? tl->entries : nullptr, tl ? tl->format : 0, rgba.data());
        [t replaceRegion:MTLRegionMake2D(0, 0, w, h) mipmapLevel:l withBytes:rgba.data() bytesPerRow:w * 4];
        // W3D_TEXDUMP=<carpeta>: cada textura decodificada, sobre magenta para ver el alfa.
        static const char *texdump = getenv("W3D_TEXDUMP");
        if (texdump && l == 0) {
            static int n; char path[600]; snprintf(path, sizeof path, "%s/t%04d_%ux%u_f%u.ppm", texdump, n++, w, h, fmt);
            if (FILE *f = fopen(path, "wb")) {
                fprintf(f, "P6\n%u %u\n255\n", w, h);
                for (size_t i = 0; i < (size_t)w * h; i++) {
                    const u8 *c = &rgba[i * 4]; u8 o[3] = {(u8)((c[0] * c[3] + 255 * (255 - c[3])) / 255), (u8)(c[1] * c[3] / 255), (u8)((c[2] * c[3] + 255 * (255 - c[3])) / 255)};
                    fwrite(o, 1, 3, f);
                }
                fclose(f);
            }
        }
        p += tex_level_bytes(w, h, fmt);
        w = w > 1 ? w >> 1 : 1;
        h = h > 1 ? h >> 1 : 1;
    }
    census.tex_uploads++;
    if (!e) { textures[key] = TexEntry{t, hash, g.tex_epoch, frame_counter, bytes}; e = &textures[key]; }
    else { tex_total_bytes -= e->bytes; e->tex = t; e->hash = hash; e->epoch = g.tex_epoch; e->last_frame = frame_counter; e->bytes = bytes; }
    tex_total_bytes += bytes;
    memset(&e->sig, 0, sizeof e->sig); e->hide_gen = 0;
    if (dual_mode()) {
        std::vector<u8> l0((size_t)o.width * o.height * 4);
        tex_decode(src, o.width, o.height, fmt, tl ? tl->entries : nullptr, tl ? tl->format : 0, l0.data());
        w3d_ui_sig_make(l0.data(), o.width, o.height, &e->sig);
    }
    g_tex_hidden = entry_hidden(*e);
    return t;
}

// Las texturas sin uso durante un tiempo se liberan: el juego las recrea al volver a usarlas.
void evict_textures() {
    if (tex_total_bytes < (256u << 20)) return;
    for (auto it = textures.begin(); it != textures.end();) {
        if (frame_counter - it->second.last_frame > 300) {
            tex_total_bytes -= it->second.bytes;
            it = textures.erase(it);
        } else ++it;
    }
}

id<MTLRenderPipelineState> build_pipeline(const PipelineKey &k) {
    @autoreleasepool {
        std::string src = shader_source(k);
        id<MTLLibrary> lib = nil;
        auto li = libraries.find(src);
        if (li != libraries.end()) lib = li->second;
        else {
            MTLCompileOptions *co = [MTLCompileOptions new];
            co.preserveInvariance = YES;
            NSError *err = nil;
            lib = [dev newLibraryWithSource:[NSString stringWithUTF8String:src.c_str()] options:co error:&err];
            if (!lib) {
                fprintf(stderr, "[gx] error de MSL:\n%s\n---\n%s\n", err.localizedDescription.UTF8String, src.c_str());
                return nil;
            }
            libraries[src] = lib;
        }
        MTLRenderPipelineDescriptor *d = [MTLRenderPipelineDescriptor new];
        d.vertexFunction = [lib newFunctionWithName:@"vs_main"];
        d.fragmentFunction = [lib newFunctionWithName:@"fs_main"];
        d.colorAttachments[0].pixelFormat = MTLPixelFormatBGRA8Unorm;
        d.depthAttachmentPixelFormat = MTLPixelFormatDepth32Float;
        if (k.vs.point) d.inputPrimitiveTopology = MTLPrimitiveTopologyClassPoint;

        MTLVertexDescriptor *vd = [MTLVertexDescriptor vertexDescriptor];
        u32 off = 0;
        vd.attributes[0].format = MTLVertexFormatFloat3; vd.attributes[0].offset = 0; vd.attributes[0].bufferIndex = 0;
        off = 12;
        if (k.vs.attrs & 2) { vd.attributes[1].format = MTLVertexFormatFloat3; vd.attributes[1].offset = off; vd.attributes[1].bufferIndex = 0; off += 12; }
        if (k.vs.attrs & 4) { vd.attributes[2].format = MTLVertexFormatUChar4Normalized; vd.attributes[2].offset = off; vd.attributes[2].bufferIndex = 0; off += 4; }
        if (k.vs.attrs & 8) { vd.attributes[3].format = MTLVertexFormatUChar4Normalized; vd.attributes[3].offset = off; vd.attributes[3].bufferIndex = 0; off += 4; }
        for (int i = 0; i < 8; i++) {
            if (k.vs.attrs & (16 << i)) { vd.attributes[4 + i].format = MTLVertexFormatFloat2; vd.attributes[4 + i].offset = off; vd.attributes[4 + i].bufferIndex = 0; off += 8; }
        }
        vd.layouts[0].stride = off;
        d.vertexDescriptor = vd;

        MTLRenderPipelineColorAttachmentDescriptor *c = d.colorAttachments[0];
        MTLColorWriteMask mask = MTLColorWriteMaskNone;
        if (k.r.write_rgb) mask |= MTLColorWriteMaskRed | MTLColorWriteMaskGreen | MTLColorWriteMaskBlue;
        if (k.r.write_a) mask |= MTLColorWriteMaskAlpha;
        c.writeMask = mask;
        if (k.r.blend == 1 || k.r.blend == 3) {
            c.blendingEnabled = YES;
            auto src_f = [&](u8 f, bool alpha) -> MTLBlendFactor {
                switch (f) {
                    case 0: return MTLBlendFactorZero;
                    case 1: return MTLBlendFactorOne;
                    case 2: return alpha ? MTLBlendFactorDestinationAlpha : MTLBlendFactorDestinationColor;
                    case 3: return alpha ? MTLBlendFactorOneMinusDestinationAlpha : MTLBlendFactorOneMinusDestinationColor;
                    case 4: return MTLBlendFactorSourceAlpha;
                    case 5: return MTLBlendFactorOneMinusSourceAlpha;
                    case 6: return k.r.dst_has_alpha ? MTLBlendFactorDestinationAlpha : MTLBlendFactorOne;
                    default: return k.r.dst_has_alpha ? MTLBlendFactorOneMinusDestinationAlpha : MTLBlendFactorZero;
                }
            };
            auto dst_f = [&](u8 f, bool alpha) -> MTLBlendFactor {
                switch (f) {
                    case 0: return MTLBlendFactorZero;
                    case 1: return MTLBlendFactorOne;
                    case 2: return alpha ? MTLBlendFactorSourceAlpha : MTLBlendFactorSourceColor;
                    case 3: return alpha ? MTLBlendFactorOneMinusSourceAlpha : MTLBlendFactorOneMinusSourceColor;
                    case 4: return MTLBlendFactorSourceAlpha;
                    case 5: return MTLBlendFactorOneMinusSourceAlpha;
                    case 6: return k.r.dst_has_alpha ? MTLBlendFactorDestinationAlpha : MTLBlendFactorOne;
                    default: return k.r.dst_has_alpha ? MTLBlendFactorOneMinusDestinationAlpha : MTLBlendFactorZero;
                }
            };
            if (k.r.blend == 3) {
                // GX_BM_SUBTRACT: destino menos origen, sin factores.
                c.rgbBlendOperation = c.alphaBlendOperation = MTLBlendOperationReverseSubtract;
                c.sourceRGBBlendFactor = c.destinationRGBBlendFactor = MTLBlendFactorOne;
                c.sourceAlphaBlendFactor = c.destinationAlphaBlendFactor = MTLBlendFactorOne;
            } else {
                c.rgbBlendOperation = c.alphaBlendOperation = MTLBlendOperationAdd;
                c.sourceRGBBlendFactor = src_f(k.r.src, false);
                c.destinationRGBBlendFactor = dst_f(k.r.dst, false);
                c.sourceAlphaBlendFactor = src_f(k.r.src, true);
                c.destinationAlphaBlendFactor = dst_f(k.r.dst, true);
            }
        }
        NSError *err = nil;
        id<MTLRenderPipelineState> ps = [dev newRenderPipelineStateWithDescriptor:d error:&err];
        if (!ps) fprintf(stderr, "[gx] error de tubería: %s\n%s\n", err.localizedDescription.UTF8String, src.c_str());
        return ps;
    }
}

id<MTLDepthStencilState> depth_state() {
    u32 k = (u32)g.z_enable | (u32)g.z_func << 1 | (u32)g.z_update << 4;
    auto it = ds_cache.find(k);
    if (it != ds_cache.end()) return it->second;
    MTLDepthStencilDescriptor *d = [MTLDepthStencilDescriptor new];
    static const MTLCompareFunction f[8] = {MTLCompareFunctionNever, MTLCompareFunctionLess, MTLCompareFunctionEqual, MTLCompareFunctionLessEqual, MTLCompareFunctionGreater, MTLCompareFunctionNotEqual, MTLCompareFunctionGreaterEqual, MTLCompareFunctionAlways};
    // Sin comparación de Z tampoco se actualiza Z, como en la consola.
    d.depthCompareFunction = g.z_enable ? f[g.z_func & 7] : MTLCompareFunctionAlways;
    d.depthWriteEnabled = g.z_enable && g.z_update;
    id<MTLDepthStencilState> s = [dev newDepthStencilStateWithDescriptor:d];
    ds_cache[k] = s;
    return s;
}

void ensure_command() {
    if (cmd) return;
    dispatch_semaphore_wait(inflight, DISPATCH_TIME_FOREVER);
    cmd = [queue commandBuffer];
    dispatch_semaphore_t sem = inflight;
    [cmd addCompletedHandler:^(id<MTLCommandBuffer>) { dispatch_semaphore_signal(sem); }];
    FrameBuf &f = frames[frame_index];
    f.voff = f.ioff = 0;
}

void ensure_encoder() {
    ensure_command();
    if (enc) return;
    MTLRenderPassDescriptor *p = [MTLRenderPassDescriptor renderPassDescriptor];
    p.colorAttachments[0].texture = efb_color;
    p.colorAttachments[0].loadAction = pending_clear_color ? MTLLoadActionClear : MTLLoadActionLoad;
    p.colorAttachments[0].clearColor = MTLClearColorMake(clear_rgba[0], clear_rgba[1], clear_rgba[2], clear_rgba[3]);
    p.colorAttachments[0].storeAction = MTLStoreActionStore;
    p.depthAttachment.texture = efb_depth;
    p.depthAttachment.loadAction = pending_clear_depth ? MTLLoadActionClear : MTLLoadActionLoad;
    p.depthAttachment.clearDepth = clear_depth;
    p.depthAttachment.storeAction = MTLStoreActionStore;
    pending_clear_color = pending_clear_depth = false;
    enc = [cmd renderCommandEncoderWithDescriptor:p];
    [enc setFrontFacingWinding:MTLWindingClockwise];
    cur_pipe = nil;
    cur_ds = nil;
    cur_cull = -1;
    have_vp = have_sc = false;
    for (int i = 0; i < 8; i++) { cur_tex[i] = nil; cur_smp[i] = nil; }
}

void end_encoder() {
    if (enc) { [enc endEncoding]; enc = nil; }
}

id<MTLTexture> make_rt(MTLPixelFormat fmt, int w, int h, MTLTextureUsage usage) {
    MTLTextureDescriptor *td = [MTLTextureDescriptor texture2DDescriptorWithPixelFormat:fmt width:w height:h mipmapped:NO];
    td.storageMode = MTLStorageModePrivate;
    td.usage = usage;
    return [dev newTextureWithDescriptor:td];
}

const char *kCopySrc = R"MSL(
#include <metal_stdlib>
using namespace metal;
struct VO { float4 p [[position]]; float2 uv; };
struct CU { float4 rect; float4 vf; float dy; float pad[3]; };  // vf.w es 1/gamma.
vertex VO copy_vs(uint vid [[vertex_id]], constant CU &u [[buffer(0)]]) {
    float2 q = float2(vid & 1, (vid >> 1) & 1);
    VO o; o.p = float4(q.x * 2.0 - 1.0, 1.0 - q.y * 2.0, 0.0, 1.0);
    o.uv = u.rect.xy + q * u.rect.zw;
    return o;
}
fragment float4 copy_fs(VO in [[stage_in]], texture2d<float> t [[texture(0)]], sampler s [[sampler(0)]], constant CU &u [[buffer(0)]]) {
    float3 c = t.sample(s, in.uv).rgb * u.vf.y;
    if (u.vf.x > 0.0) c += t.sample(s, in.uv - float2(0.0, u.dy)).rgb * u.vf.x;
    if (u.vf.z > 0.0) c += t.sample(s, in.uv + float2(0.0, u.dy)).rgb * u.vf.z;
    c = saturate(c);
    if (u.vf.w != 1.0) c = pow(c, float3(u.vf.w));
    return float4(c, 1.0);
}
)MSL";

struct CopyUniforms { float rect[4]; float vf[3]; float rcp_gamma; float dy; float pad[3]; };

id<MTLRenderPipelineState> make_blit_pipeline(id<MTLLibrary> lib) {
    MTLRenderPipelineDescriptor *d = [MTLRenderPipelineDescriptor new];
    d.vertexFunction = [lib newFunctionWithName:@"copy_vs"];
    d.fragmentFunction = [lib newFunctionWithName:@"copy_fs"];
    d.colorAttachments[0].pixelFormat = MTLPixelFormatBGRA8Unorm;
    NSError *err = nil;
    id<MTLRenderPipelineState> ps = [dev newRenderPipelineStateWithDescriptor:d error:&err];
    if (!ps) fprintf(stderr, "[gx] error de tubería de copia: %s\n", err.localizedDescription.UTF8String);
    return ps;
}


// --- UI de dos pantallas en Mac (W3D_DUAL=1): la misma UI que la 3DS (platform/ui) sobre Metal ---
// Arriba: la imagen del juego reducida a 400x240 (como en la 3DS: el 2D ocupa toda la pantalla y la cámara se abre a
// 5:3, gx_shader.cpp) con la UI encima. Abajo: 320x240 de la UI. La ventana las muestra una encima de la otra al doble,
// sin suavizar, para ver los píxeles reales. W3D_SHOT guarda las dos a su tamaño de 3DS.
const char *kUiSrc = R"(
#include <metal_stdlib>
using namespace metal;
struct UV { packed_float2 p; packed_float2 uv; uint c; };   // 20 bytes, como UiVertex
struct UO { float4 p [[position]]; float2 uv; float4 c; };
vertex UO ui_vs(uint vid [[vertex_id]], const device UV *v [[buffer(0)]], constant float2 &scr [[buffer(1)]]) {
    UO o; UV x = v[vid];
    float2 q = float2(x.p);
    o.p = float4(q.x / scr.x * 2.0 - 1.0, 1.0 - q.y / scr.y * 2.0, 0.0, 1.0);
    o.uv = float2(x.uv); o.c = unpack_unorm4x8_to_float(x.c);
    return o;
}
// Triángulos con profundidad (el worm 3D de Crear equipo, menu_underlay): x, y en píxeles de la pantalla, z de 0 a 1.
struct UV3 { packed_float3 p; packed_float2 uv; uint c; };   // 24 bytes, como Ui3Vertex
vertex UO ui3_vs(uint vid [[vertex_id]], const device UV3 *v [[buffer(0)]], constant float2 &scr [[buffer(1)]]) {
    UO o; UV3 x = v[vid];
    float3 q = float3(x.p);
    o.p = float4(q.x / scr.x * 2.0 - 1.0, 1.0 - q.y / scr.y * 2.0, q.z, 1.0);
    o.uv = float2(x.uv); o.c = unpack_unorm4x8_to_float(x.c);
    return o;
}
fragment float4 ui_fs(UO i [[stage_in]], texture2d<float> t [[texture(0)]], sampler s [[sampler(0)]], constant int &tex [[buffer(0)]]) {
    float4 c = i.c;
    if (tex) c *= t.sample(s, i.uv);
    return c;
}
)";
bool dual_mode() { static int v = -1; if (v < 0) v = getenv("W3D_DUAL") ? 1 : 0; return v != 0; }
id<MTLTexture> ui_top, ui_bot;
id<MTLRenderPipelineState> ui_pipe, ui_pipe_max, ui3_pipe;
id<MTLDepthStencilState> ui3_ds;
id<MTLSamplerState> ui_smp, nearest_clamp;
std::vector<id<MTLTexture>> ui_textures;
struct UiVertex { float x, y, u, v; uint32_t c; };
struct Ui3Vertex { float x, y, z, u, v; uint32_t c; };
id<MTLBuffer> ui_vb[kInFlight];
size_t ui_voff;
id<MTLRenderCommandEncoder> ui_enc;
int ui_bound = -2;
void ui_init_metal() {
    NSError *err = nil;
    id<MTLLibrary> lib = [dev newLibraryWithSource:[NSString stringWithUTF8String:kUiSrc] options:[MTLCompileOptions new] error:&err];
    if (!lib) { fprintf(stderr, "[ui] MSL: %s\n", err.localizedDescription.UTF8String); return; }
    MTLRenderPipelineDescriptor *d = [MTLRenderPipelineDescriptor new];
    d.vertexFunction = [lib newFunctionWithName:@"ui_vs"];
    d.fragmentFunction = [lib newFunctionWithName:@"ui_fs"];
    MTLRenderPipelineColorAttachmentDescriptor *c = d.colorAttachments[0];
    c.pixelFormat = MTLPixelFormatBGRA8Unorm;
    c.blendingEnabled = YES;
    c.sourceRGBBlendFactor = MTLBlendFactorSourceAlpha; c.destinationRGBBlendFactor = MTLBlendFactorOneMinusSourceAlpha;
    c.sourceAlphaBlendFactor = MTLBlendFactorOne; c.destinationAlphaBlendFactor = MTLBlendFactorOneMinusSourceAlpha;
    ui_pipe = [dev newRenderPipelineStateWithDescriptor:d error:&err];
    if (!ui_pipe) fprintf(stderr, "[ui] tubería: %s\n", err.localizedDescription.UTF8String);
    c.rgbBlendOperation = c.alphaBlendOperation = MTLBlendOperationMax;
    c.sourceRGBBlendFactor = c.destinationRGBBlendFactor = c.sourceAlphaBlendFactor = c.destinationAlphaBlendFactor = MTLBlendFactorOne;
    ui_pipe_max = [dev newRenderPipelineStateWithDescriptor:d error:&err];
    // Con profundidad (menu_underlay, triángulos): mezcla normal y z-buffer propio.
    c.rgbBlendOperation = c.alphaBlendOperation = MTLBlendOperationAdd;
    c.sourceRGBBlendFactor = MTLBlendFactorSourceAlpha; c.destinationRGBBlendFactor = MTLBlendFactorOneMinusSourceAlpha;
    c.sourceAlphaBlendFactor = MTLBlendFactorOne; c.destinationAlphaBlendFactor = MTLBlendFactorOneMinusSourceAlpha;
    d.vertexFunction = [lib newFunctionWithName:@"ui3_vs"];
    d.depthAttachmentPixelFormat = MTLPixelFormatDepth32Float;
    ui3_pipe = [dev newRenderPipelineStateWithDescriptor:d error:&err];
    if (!ui3_pipe) fprintf(stderr, "[ui] tubería 3D: %s\n", err.localizedDescription.UTF8String);
    { MTLDepthStencilDescriptor *z = [MTLDepthStencilDescriptor new]; z.depthCompareFunction = MTLCompareFunctionLess; z.depthWriteEnabled = YES;
      ui3_ds = [dev newDepthStencilStateWithDescriptor:z]; }
    MTLSamplerDescriptor *sd = [MTLSamplerDescriptor new];
    sd.minFilter = sd.magFilter = MTLSamplerMinMagFilterLinear;
    sd.sAddressMode = sd.tAddressMode = MTLSamplerAddressModeClampToEdge;
    sd.mipFilter = MTLSamplerMipFilterLinear;   // solo cuenta en las texturas con mipmaps (uib_tex_create, fmt + 8)
    ui_smp = [dev newSamplerStateWithDescriptor:sd];
    sd.mipFilter = MTLSamplerMipFilterNotMipmapped;
    sd.minFilter = sd.magFilter = MTLSamplerMinMagFilterNearest;
    nearest_clamp = [dev newSamplerStateWithDescriptor:sd];
    ui_top = make_rt(MTLPixelFormatBGRA8Unorm, 400, 240, MTLTextureUsageRenderTarget | MTLTextureUsageShaderRead);
    ui_bot = make_rt(MTLPixelFormatBGRA8Unorm, 320, 240, MTLTextureUsageRenderTarget | MTLTextureUsageShaderRead);
    for (auto &b : ui_vb) b = [dev newBufferWithLength:(2u << 20) options:MTLResourceStorageModeShared];
}
void ui_end_encoder() { if (ui_enc) { [ui_enc endEncoding]; ui_enc = nil; } }
// Copia una textura (privada de la GPU) a un búfer compartido dentro del cuadro; dump_ppm la escribe tras completarlo.
id<MTLBuffer> grab(id<MTLCommandBuffer> c, id<MTLTexture> t) {
    size_t row = t.width * 4;
    id<MTLBuffer> b = [dev newBufferWithLength:row * t.height options:MTLResourceStorageModeShared];
    id<MTLBlitCommandEncoder> e = [c blitCommandEncoder];
    [e copyFromTexture:t sourceSlice:0 sourceLevel:0 sourceOrigin:MTLOriginMake(0, 0, 0) sourceSize:MTLSizeMake(t.width, t.height, 1) toBuffer:b destinationOffset:0 destinationBytesPerRow:row destinationBytesPerImage:row * t.height];
    [e endEncoding];
    return b;
}
void dump_ppm(id<MTLBuffer> buf, id<MTLTexture> t, const char *path) {
    const uint8_t *px = (const uint8_t *)buf.contents;
    if (FILE *f = fopen(path, "wb")) {
        fprintf(f, "P6\n%d %d\n255\n", (int)t.width, (int)t.height);
        for (size_t i = 0; i < t.width * t.height; i++) { uint8_t c[3] = {px[i * 4 + 2], px[i * 4 + 1], px[i * 4]}; fwrite(c, 1, 3, f); }
        fclose(f);
    }
}

// Native screen camera from d28i_scene_start: z=500, symmetric near plane.
// Route after CPU culling, so animated 3D HUD models retain their original bounds.
bool battle_hud_camera(const VsUniforms &u, const void *vertices, unsigned stride, const unsigned short *indices,unsigned count) {
    if(!dual_mode() || !g_tall_proj || w3d_fe_game_mode()!=7 || !w3d_hud_screen_camera()) return false;
    const float *v=(const float *)((const char *)vertices+indices[0]*stride);
    float z=u.posmtx[8]*v[0]+u.posmtx[9]*v[1]+u.posmtx[10]*v[2]+u.posmtx[11];
    const bool screen_projection=fabsf(g.proj[0]-1.4925373f)<.0001f || fabsf(g.proj[0]-1.5625f)<.0001f;
    if(!screen_projection) return false;
    if(fabsf(u.posmtx[11]+500.f)<.01f || fabsf(u.posmtx[11]+498.f)<.05f) return true;
    if(z < -550 || z > -450) return false;
    for(unsigned i=0;i<count;++i) {
        const float *p=(const float *)((const char *)vertices+indices[i]*stride);
        float vz=u.posmtx[8]*p[0]+u.posmtx[9]*p[1]+u.posmtx[10]*p[2]+u.posmtx[11];
        if(vz < -550 || vz > -450) return false;
    }
    return true;
}
// Lower-screen backdrop is UI artwork, never a captured copy of the 3D scene.
u32 battle_underlay_frame=~0u;
void battle_underlay() {
    if(w3d_ui_panel_active()) return;
    if(battle_underlay_frame==frame_counter) return;
    battle_underlay_frame=frame_counter;
    const unsigned eh=(unsigned)g.vp[3];
    ensure_encoder(); end_encoder();
    float uw=1,vh=1; int tid=w3d_ui_map_texture(&uw,&vh);
    id<MTLTexture> source=tid>=0 && tid<(int)ui_textures.size()?ui_textures[tid]:black_tex;
    MTLRenderPassDescriptor *p=[MTLRenderPassDescriptor renderPassDescriptor];
    p.colorAttachments[0].texture=efb_color;
    p.colorAttachments[0].loadAction=MTLLoadActionLoad;
    p.colorAttachments[0].storeAction=MTLStoreActionStore;
    id<MTLRenderCommandEncoder> e=[cmd renderCommandEncoderWithDescriptor:p];
    MTLViewport vp={64.0*scale,eh*(double)scale,512.0*scale,eh*(double)scale,0,1};
    [e setViewport:vp];
    CopyUniforms u={};u.rect[2]=uw;u.rect[3]=vh;
    u.vf[1]=0.45f;u.rcp_gamma=1;
    [e setRenderPipelineState:copy_pipe];
    [e setVertexBytes:&u length:sizeof u atIndex:0];[e setFragmentBytes:&u length:sizeof u atIndex:0];
    [e setFragmentTexture:source atIndex:0];[e setFragmentSamplerState:linear_clamp atIndex:0];
    [e drawPrimitives:MTLPrimitiveTypeTriangleStrip vertexStart:0 vertexCount:4];[e endEncoding];
}
// Menus: backgrounds the UI page asks for under the game's own controls (Land Select: the preview frame above, the
// ring panel below). Drawn once per frame with the UI pipeline on the upper or lower half of the tall canvas, at the
// first draw with the FE controls' projection (1.4925; the backdrop before them uses 1.5625 and would cover it).
// Also loose triangles with a colour per vertex (w3d_ui_menu_tris): the 3D worm of Create Team, drawn here at the game's
// resolution instead of the 400x240 UI layer, under the FE controls like the frames.
extern "C" int w3d_ui_menu_underlay(int,int *,float *,float *);
extern "C" int w3d_ui_menu_tris(int,int *,int *,const float **,const unsigned **);
u32 menu_underlay_frame=~0u;
id<MTLBuffer> under_vb[kInFlight];
void menu_underlay() {
    if(menu_underlay_frame==frame_counter || !ui_pipe) return;
    menu_underlay_frame=frame_counter;
    int tex; float uv[2],r[5];
    {
        int tt,ts; const float *tv; const unsigned *tc;
        if(!w3d_ui_menu_underlay(0,&tex,uv,r) && w3d_ui_menu_tris(0,&tt,&ts,&tv,&tc)<=0) return;
    }
    const unsigned eh=(unsigned)g.vp[3];
    ensure_encoder(); end_encoder();
    MTLRenderPassDescriptor *p=[MTLRenderPassDescriptor renderPassDescriptor];
    p.colorAttachments[0].texture=efb_color;
    p.colorAttachments[0].loadAction=MTLLoadActionLoad;
    p.colorAttachments[0].storeAction=MTLStoreActionStore;
    id<MTLRenderCommandEncoder> e=[cmd renderCommandEncoderWithDescriptor:p];
    [e setRenderPipelineState:ui_pipe];
    [e setFragmentSamplerState:ui_smp atIndex:0];
    for(int i=0;w3d_ui_menu_underlay(i,&tex,uv,r);++i) {
        // r[4]: 0 upper screen (400x240 over the full upper half), 1 lower (320x240, the centre of the lower half).
        const bool lower=r[4]!=0;
        MTLViewport vp=lower?MTLViewport{64.0*scale,eh*(double)scale,512.0*scale,eh*(double)scale,0,1}
                            :MTLViewport{0,0,640.0*scale,eh*(double)scale,0,1};
        [e setViewport:vp];
        float scr[2]={lower?320.f:400.f,240.f};
        [e setVertexBytes:scr length:sizeof scr atIndex:1];
        id<MTLTexture> t=tex>=0 && tex<(int)ui_textures.size()?ui_textures[tex]:nil;
        if(!t) continue;
        const float x0=r[0],y0=r[1],x1=r[0]+r[2],y1=r[1]+r[3];
        UiVertex v[6]={{x0,y0,0,0,0xffffffffu},{x1,y0,uv[0],0,0xffffffffu},{x1,y1,uv[0],uv[1],0xffffffffu},
                       {x0,y0,0,0,0xffffffffu},{x1,y1,uv[0],uv[1],0xffffffffu},{x0,y1,0,uv[1],0xffffffffu}};
        int use=1;
        [e setVertexBytes:v length:sizeof v atIndex:0];
        [e setFragmentTexture:t atIndex:0];
        [e setFragmentBytes:&use length:sizeof use atIndex:0];
        [e drawPrimitives:MTLPrimitiveTypeTriangle vertexStart:0 vertexCount:6];
    }
    [e endEncoding];
    // Triángulos con su propio z-buffer (del tamaño de la imagen del juego), en otro pase.
    {
        int tt,ts; const float *tv; const unsigned *tc;
        if(w3d_ui_menu_tris(0,&tt,&ts,&tv,&tc)<=0 || !ui3_pipe) return;
    }
    static id<MTLTexture> under_depth;
    if(!under_depth || under_depth.width!=efb_color.width || under_depth.height!=efb_color.height) {
        MTLTextureDescriptor *td=[MTLTextureDescriptor texture2DDescriptorWithPixelFormat:MTLPixelFormatDepth32Float width:efb_color.width height:efb_color.height mipmapped:NO];
        td.usage=MTLTextureUsageRenderTarget; td.storageMode=MTLStorageModePrivate;
        under_depth=[dev newTextureWithDescriptor:td];
    }
    p.depthAttachment.texture=under_depth;
    p.depthAttachment.loadAction=MTLLoadActionClear;
    p.depthAttachment.clearDepth=1.0;
    p.depthAttachment.storeAction=MTLStoreActionDontCare;
    e=[cmd renderCommandEncoderWithDescriptor:p];
    [e setRenderPipelineState:ui3_pipe];
    [e setDepthStencilState:ui3_ds];
    [e setFragmentSamplerState:ui_smp atIndex:0];
    if(!under_vb[frame_index]) under_vb[frame_index]=[dev newBufferWithLength:(1u<<20) options:MTLResourceStorageModeShared];
    size_t off=0;
    for(int i=0;;++i) {
        int ttex,screen; const float *xyzuv; const unsigned *rgba;
        const int n=w3d_ui_menu_tris(i,&ttex,&screen,&xyzuv,&rgba);
        if(n<=0) break;
        const size_t bytes=(size_t)n*sizeof(Ui3Vertex);
        if(off+bytes>under_vb[frame_index].length) break;
        Ui3Vertex *o=(Ui3Vertex *)((uint8_t *)under_vb[frame_index].contents+off);
        for(int k=0;k<n;++k) o[k]={xyzuv[k*5],xyzuv[k*5+1],xyzuv[k*5+2],xyzuv[k*5+3],xyzuv[k*5+4],rgba[k]};
        const bool lower=screen!=0;
        MTLViewport vp=lower?MTLViewport{64.0*scale,eh*(double)scale,512.0*scale,eh*(double)scale,0,1}
                            :MTLViewport{0,0,640.0*scale,eh*(double)scale,0,1};
        [e setViewport:vp];
        float scr[2]={lower?320.f:400.f,240.f};
        [e setVertexBytes:scr length:sizeof scr atIndex:1];
        id<MTLTexture> t=ttex>=0 && ttex<(int)ui_textures.size()?ui_textures[ttex]:nil;
        int use=t?1:0;
        [e setFragmentTexture:t?t:black_tex atIndex:0];
        [e setFragmentBytes:&use length:sizeof use atIndex:0];
        [e setVertexBuffer:under_vb[frame_index] offset:off atIndex:0];
        [e drawPrimitives:MTLPrimitiveTypeTriangle vertexStart:0 vertexCount:n];
        off=(off+bytes+15)&~(size_t)15;
    }
    [e endEncoding];
}
// Enlarge each original animated indicator around its own anchor. FE controls
// are on z=2 and keep their independent touchscreen layout.
bool health_band;   // the draw being routed is the game's team health bars
// 1: routed to the lower screen; 0: not drawn; -1: drawn where the game puts it (upper screen).
int position_battle_ui(VsUniforms &u,const void *vertices,unsigned stride,const unsigned short *indices,unsigned index_count,bool &fe) {
    const char *popup=w3d_fe_popup_depth()>0?w3d_fe_last_popup():nullptr;
    if(popup && (strstr(popup,"Confirm") || !strcmp(popup,"FE.PauseMenu"))) return false;
    float cx=0,cy=0,cz=0; unsigned count=0;
    for(unsigned i=0;i<index_count;++i) {
        const float *v=(const float *)((const char *)vertices+indices[i]*stride);
        float p[4]={0,0,0,1},q[4]={};
        for(int r=0;r<3;++r) p[r]=u.posmtx[r*4]*v[0]+u.posmtx[r*4+1]*v[1]+u.posmtx[r*4+2]*v[2]+u.posmtx[r*4+3];
        for(int r=0;r<4;++r) for(int c=0;c<4;++c) q[r]+=u.proj[r*4+c]*p[c];
        if(fabsf(q[3])<.001f) continue;
        cx+=160+200*q[0]/q[3]; cy+=240*(1-q[1]/q[3]); cz+=p[2]; ++count;
    }
    if(!count) return false;
    cx/=count;cy/=count;cz/=count;
    fe=w3d_fe_popup_depth()>0 && fabsf(cz+498.f)<.05f;
    if(w3d_fe_popup_depth()>0 && cx>65 && cx<255 && cy>30 && cy<205) fe=true;
    float factor=1,ax=0,ay=0,tx=0,ty=0;
    // W3D_HUD_LOG=<cuadro>: cada dibujo de la cámara de pantalla de ese cuadro, con su centro y textura (diagnóstico).
    { static const char *hl=getenv("W3D_HUD_LOG");
      static u32 h0=hl?(u32)atoi(hl):0, h1=hl&&strchr(hl,'-')?(u32)atoi(strchr(hl,'-')+1):h0;   // <cuadro> o <desde>-<hasta>
      if(hl && frame_counter>=h0 && frame_counter<=h1) fprintf(stderr,"[hud] f=%u c=%.0f,%.0f z=%.2f tz=%.2f n=%u tex=%ux%u fmt=%u img=%x fe=%d\n",frame_counter,cx,cy,cz,u.posmtx[11],index_count,g.map[0].width,g.map[0].height,g.map[0].format,g.map[0].image,(int)fe); }
    health_band=false;
    if(!fe) {
        if(w3d_fe_prop_uint("WeaponPanel.Open",0) || w3d_fe_popup_depth()>0) return false;
        // The four indicators lie on the screen camera's z=-500 plane, in their matrix or in their vertices. Only the
        // wind indicator (bottom right) has pieces in depth: its 64x64 streaks with their own matrix and a 128x128 piece
        // at z=-545. World markers drawn with the same camera are not indicators and stay off the lower screen: worm
        // names (font quads at their own depth) and the bouncing arrow over the active worm (64x64, z~-510, no matrix).
        const float tz=u.posmtx[11];
        const bool plane=fabsf(tz+500.f)<.05f || (fabsf(tz)<.01f && fabsf(cz+500.f)<1.f);
        // 64x64 quads with their own depth there are either the wind indicator's fan (its blades, all within ~15 px of
        // the indicator's centre, measured with W3D_HUD_LOG) or the map's grass seen through the HUD camera (further
        // out), which stays off the lower screen like everything else from the map.
        const bool sprite64=g.map[0].width==64 && g.map[0].height==64;
        const float wx=cx-281, wy=cy-198;
        const bool wind=cx>236 && cy>145 && (sprite64 ? fabsf(tz)>.01f && wx*wx+wy*wy<18*18 : fabsf(tz)<.01f);
        const bool font=g.map[0].width==256 && g.map[0].height==256;
        // Each indicator: only pieces near its own centre (radius in original pixels, measured with W3D_HUD_LOG).
        // Targets (lower-screen pixels) with up to two teams and with three or four (smaller, under a taller block of
        // bars). Owner's adjustments: all a little higher so the bottom row is not cut, the weapon 4 % further up from
        // the wind, the radar at the weapon's height (same gap above its lower neighbour), 1.5 % right of before.
        struct Corner { float x,y,r,tx,ty,ty4; };
        static const Corner kCorners[4]={{40,40,36,59,86,126},{280,40,34,260,86,126},{41,199,40,60,182,196},{281,198,34,260,182,196}};
        const Corner *k=nullptr;
        for(const Corner &c:kCorners) if((cx-c.x)*(cx-c.x)+(cy-c.y)*(cy-c.y)<c.r*c.r) k=&c;
        // Textures the indicators use (seen on their plane inside their disc), with the last frame: an indicator that
        // animates moves a little in depth and out of its disc, and must not be taken for a world marker or a message.
        static std::unordered_map<u32,u32> indicator_tex;
        const auto known_it=indicator_tex.find(g.map[0].image);
        const bool known=known_it!=indicator_tex.end() && frame_counter-known_it->second<600;
        if(k && plane) indicator_tex[g.map[0].image]=frame_counter;
        // The game's messages along the top of the screen ("X is on the move", "X couldn't swim"...): on the upper screen,
        // twice as big (owner: big, then 20 % smaller than 2.5x), still centred at the top.
        // (The font is shared with the indicators' numbers, so it counts as a message whenever it is outside the discs.)
        if(!k && (!known || font) && cy<45 && cx>40 && cx<280) {
            const float f=2.f, ax=160, ay=8, tx=160, ty=14, mdx=tx-f*ax, mdy=ty-f*ay;
            for(int c=0;c<4;++c) {
                u.proj[c]=f*u.proj[c]+((160*(f-1)+mdx)/200)*u.proj[12+c];
                u.proj[4+c]=f*u.proj[4+c]+(1-f-mdy/240)*u.proj[12+c];
            }
            return -2;
        }
        // World markers (worm names, the active worm's arrow, the weapon's aiming sight) belong to the upper screen; an
        // indicator's own texture in its disc stays an indicator even while it animates in depth (not the font: worm
        // names use it too).
        const bool indicator_motion=k && known && !font;
        if(!plane && !wind && !indicator_motion) return -1;
        // The game's own team health bars (bottom centre of the original HUD), unchanged, fixed at the top of the lower
        // screen. The HUD moves them (entry, reordering; the retreat is off, core/native/hud_energy.cpp): they are
        // placed by the top row of the previous frame, so the block stays put whatever height the game gives it. The
        // clip to the top band (health_band, draw()) keeps any remaining motion away from the indicators.
        // Long team names reach further left, into the clock's corner: the clock has no font quads (256x256), so those
        // letters still belong to the bars.
        const bool health=(cx>=110 && cx<=232 && cy>150) || (font && cx>=0 && cx<110 && cy>185);
        if(w3d_ui_panel_active() && (health || k || known)) return 0;
        health_band=health;
        if(health) {
            // Extent of the block (piece centres) in the previous frame: with 3 or 4 teams it is scaled down to fit the
            // band and the screen width, and it is always centred, so long team names are not cut.
            static u32 seen_frame; static float now_b[4]={1e9f,1e9f,-1e9f,-1e9f}, prev_b[4]={120,211,232,220};
            if(seen_frame!=frame_counter) {
                if(now_b[0]<1e8f) memcpy(prev_b,now_b,sizeof prev_b);
                now_b[0]=now_b[1]=1e9f; now_b[2]=now_b[3]=-1e9f; seen_frame=frame_counter;
            }
            now_b[0]=fminf(now_b[0],cx); now_b[1]=fminf(now_b[1],cy); now_b[2]=fmaxf(now_b[2],cx); now_b[3]=fmaxf(now_b[3],cy);
            const float band=w3d_ui_hud_team_rows()>2 ? 88.f : 52.f;
            const float w=prev_b[2]-prev_b[0]+30, h=prev_b[3]-prev_b[1]+10;
            factor=fminf(2.f,fminf(296.f/w,(band-8)/h));
            ax=(prev_b[0]+prev_b[2])/2; ay=prev_b[1]; tx=160; ty=4+5*factor;
        } else {
            // Off the four discs: a texture the indicators use is an indicator moving in or out (dropped, or it would
            // flash on the upper screen); anything else on the HUD plane (the aiming sight, the power bar) is the game's
            // upper-screen HUD, drawn where the game puts it.
            if(!k) return known ? 0 : -1;
            // Owner: the weapon indicator's "R" aiming hint is not needed below: its letter (four font quads around
            // (262,25)) here, its ring of arrows, painted inside HUD/Info_Back.tga, replaced
            // by a copy without it (ui_hide.cpp, w3d_ui_tex_swap).
            if(k==&kCorners[1] && (cx-262)*(cx-262)+(cy-25)*(cy-25)<9*9) return false;
            const bool many=w3d_ui_hud_team_rows()>2;
            factor=many?1.35f:1.55f;ax=k->x;ay=k->y;tx=k->tx;ty=many?k->ty4:k->ty;
        }
    }
    float dx=tx-factor*ax,dy=ty-factor*ay;
    for(int c=0;c<4;++c) {
        u.proj[c]=factor*u.proj[c]+((160*(factor-1)+dx)/200)*u.proj[12+c];
        u.proj[4+c]=factor*u.proj[4+c]+(1-factor-dy/240-1)*u.proj[12+c];
    }
    return true;
}

}  // namespace

int efb_scale() { return scale; }

void init() {
    if (dev) return;
    dev = (__bridge id<MTLDevice>)plat::metal_device();
    queue = (__bridge id<MTLCommandQueue>)plat::metal_queue();
    if (!dev || !queue) { fprintf(stderr, "[gx] plat::init no se ha llamado\n"); abort(); }
    if (const char *s = getenv("W3D_GX_SCALE")) { scale = atoi(s); if (scale < 1) scale = 1; if (scale > 8) scale = 8; }
    if (getenv("W3D_DUAL")) efb_alloc_h = kEfbH * 2;
    efb_color = make_rt(MTLPixelFormatBGRA8Unorm, kEfbW * scale, efb_alloc_h * scale, MTLTextureUsageRenderTarget | MTLTextureUsageShaderRead);
    efb_depth = make_rt(MTLPixelFormatDepth32Float, kEfbW * scale, efb_alloc_h * scale, MTLTextureUsageRenderTarget);
    inflight = dispatch_semaphore_create(kInFlight);
    for (auto &f : frames) {
        f.vb = [dev newBufferWithLength:(32u << 20) options:MTLResourceStorageModeShared];
        f.ib = [dev newBufferWithLength:(8u << 20) options:MTLResourceStorageModeShared];
    }
    NSError *err = nil;
    MTLCompileOptions *co = [MTLCompileOptions new];
    id<MTLLibrary> lib = [dev newLibraryWithSource:[NSString stringWithUTF8String:kCopySrc] options:co error:&err];
    if (!lib) { fprintf(stderr, "[gx] error de MSL de copia: %s\n", err.localizedDescription.UTF8String); abort(); }
    copy_pipe = make_blit_pipeline(lib);
    present_pipe = copy_pipe;
    MTLSamplerDescriptor *sd = [MTLSamplerDescriptor new];
    sd.minFilter = sd.magFilter = MTLSamplerMinMagFilterLinear;
    sd.sAddressMode = sd.tAddressMode = MTLSamplerAddressModeClampToEdge;
    linear_clamp = [dev newSamplerStateWithDescriptor:sd];
    MTLTextureDescriptor *td = [MTLTextureDescriptor texture2DDescriptorWithPixelFormat:MTLPixelFormatRGBA8Unorm width:1 height:1 mipmapped:NO];
    td.storageMode = MTLStorageModeShared;
    black_tex = [dev newTextureWithDescriptor:td];
    const u8 zero[4] = {0, 0, 0, 0};
    [black_tex replaceRegion:MTLRegionMake2D(0, 0, 1, 1) mipmapLevel:0 withBytes:zero bytesPerRow:4];
    if (dual_mode()) ui_init_metal();
}

void draw(const PipelineKey &key, const VsUniforms &vu, const FsUniforms &fu, const void *verts, u32 vert_bytes,
          u32 stride, const void *indices, u32 index_count, u32 topology) {
    if (!dev || !index_count) return;
    if (g.cull == 3 && topology == TOPO_TRI) return;  // GX_CULL_ALL.
    @autoreleasepool {
        // Shared sprite/font geometry contains unused slots and several HUD
        // elements in one draw. Route active triangles, not the buffer centroid.
        static bool splitting=false;
        const bool screen_camera=w3d_hud_screen_camera();
        if(!splitting && dual_mode() && g_tall_proj && w3d_fe_game_mode()==7 && screen_camera && topology==TOPO_TRI && index_count>6) {
            splitting=true;
            const u16 *ix=(const u16 *)indices;
            std::vector<u8> part(stride*6); const u16 local[6]={0,1,2,3,4,5};
            for(unsigned i=0;i<index_count;i+=6) {
                unsigned n=MIN(6u,index_count-i);
                for(unsigned j=0;j<n;++j) memcpy(part.data()+j*stride,(const u8 *)verts+ix[i+j]*stride,stride);
                draw(key,vu,fu,part.data(),stride*n,stride,local,n,topology);
            }
            splitting=false;
            return;
        }
        // The lower screen's backdrop every match frame, even while the whole HUD is away (otherwise it stayed black).
        if(dual_mode() && g_tall_proj && w3d_fe_game_mode()==7) battle_underlay();
        if(dual_mode() && g_tall_proj && w3d_fe_game_mode()==6 && fabsf(g.proj[0]-1.4925373f)<.0001f) menu_underlay();
        bool hud=battle_hud_camera(vu,verts,stride,(const u16 *)indices,index_count);
        VsUniforms positioned=vu; bool fe=false;
        if(hud) {
            battle_underlay();
            const int route=position_battle_ui(positioned,verts,stride,(const u16 *)indices,index_count,fe);
            if(!route) return;
            if(route==-1) { hud=false; positioned=vu; }
            if(route==-2) hud=false;   // upper screen, with the transform position_battle_ui applied
        }
        ensure_encoder();
        uint64_t h = hash_bytes(&key, sizeof key);
        auto &bucket = pipes[h];
        PipeEntry *pe = nullptr;
        for (auto &b : bucket) if (!memcmp(&b.key, &key, sizeof key)) { pe = &b; break; }
        if (!pe) {
            bucket.push_back(PipeEntry{key, build_pipeline(key), false});
            pe = &bucket.back();
        }
        if (!pe->ps) return;
        if (pe->ps != cur_pipe) {
            [enc setRenderPipelineState:pe->ps];
            cur_pipe = pe->ps;
            census.pipeline_switches++;
        }
        id<MTLDepthStencilState> ds = depth_state();
        // Dos pantallas: el oscurecido de las ventanas del juego (un cuadrado que ahora cubre las dos pantallas,
        // d24l_textbox_back_panel_802c1248) no pasaba la prueba de Z en la mitad de abajo del lienzo alto y se cortaba
        // a media pantalla. Se dibuja sin prueba de Z, como lo que es: un velo encima de todo lo anterior.
        if(dual_mode() && g_tall_proj && w3d_fe_game_mode()==6 && index_count==6 && w3d_fe_popup_depth()>0) {
            const u16 *ix=(const u16 *)indices; float y0=1e9f,y1=-1e9f;
            for(u32 i=0;i<6;i++) { const float *v=(const float *)((const char *)verts+ix[i]*stride); float p[4]={0,0,0,1},q1=0,q3=0;
                for(int r=0;r<3;r++) p[r]=vu.posmtx[r*4]*v[0]+vu.posmtx[r*4+1]*v[1]+vu.posmtx[r*4+2]*v[2]+vu.posmtx[r*4+3];
                for(int c=0;c<4;c++) { q1+=vu.proj[4+c]*p[c]; q3+=vu.proj[12+c]*p[c]; }
                if(fabsf(q3)>1e-6f) { y0=fminf(y0,q1/q3); y1=fmaxf(y1,q1/q3); } }
            if(y1-y0>2.5f) {
                // La ventana del equipo es una página de la UI con el worm 3D arriba (dibujado antes que el velo, que lo
                // apagaba) y los controles de Multijugador apartados: sin velo (ui_pages.cpp, w3d_ui_popup_veil).
                if(!w3d_ui_popup_veil()) return;
                static id<MTLDepthStencilState> veil;
                if(!veil) { MTLDepthStencilDescriptor *d=[MTLDepthStencilDescriptor new]; d.depthCompareFunction=MTLCompareFunctionAlways; d.depthWriteEnabled=NO; veil=[dev newDepthStencilStateWithDescriptor:d]; }
                ds=veil;
            }
        }
        if (ds != cur_ds) { [enc setDepthStencilState:ds]; cur_ds = ds; }
        if ((int)g.cull != cur_cull) {
            cur_cull = g.cull;
            [enc setCullMode:g.cull == 1 ? MTLCullModeFront : g.cull == 2 ? MTLCullModeBack : MTLCullModeNone];
        }
        // Lienzo alto: solo los dibujos a pantalla completa siguen hacia abajo (una vista parcial, como la previa del
        // escenario, se queda donde está).
        const bool tall = g_tall_proj;   // gx_state.cpp, con la misma vista
        MTLViewport vp = {g.vp[0] * scale, g.vp[1] * scale, g.vp[2] * scale, g.vp[3] * scale * (tall ? 2 : 1), g.vp[4], g.vp[5]};
        if (!have_vp || memcmp(&vp, &cur_vp, sizeof vp)) { [enc setViewport:vp]; cur_vp = vp; have_vp = true; }
        int sx = (int)g.scissor[0] * scale, sy = (int)g.scissor[1] * scale, sw = (int)g.scissor[2] * scale, sh = (int)g.scissor[3] * scale;
        if (tall && g.scissor[1] == 0 && g.scissor[3] >= 400) sh = efb_alloc_h * scale;
        if(dual_mode() && w3d_fe_game_mode()==7 && !hud)
            sh=MIN(sh,(int)g.vp[3]*scale-sy);
        if(hud) {
            sy=(int)g.vp[3]*scale;sh=(int)g.vp[3]*scale;
            if(!fe && health_band) sh=(int)(g.vp[3]*(w3d_ui_hud_team_rows()>2?88:52)/240)*scale;
            if(fe && w3d_fe_prop_uint("WeaponPanel.Open",0)) {
                sy+=(int)(g.vp[3]*28/240)*scale;
                sh=(int)(g.vp[3]*168/240)*scale;
            }
        }
        if (sx > kEfbW * scale) sx = kEfbW * scale;
        if (sy > efb_alloc_h * scale) sy = efb_alloc_h * scale;
        if (sx + sw > kEfbW * scale) sw = kEfbW * scale - sx;
        if (sy + sh > efb_alloc_h * scale) sh = efb_alloc_h * scale - sy;
        if (sw <= 0 || sh <= 0) return;
        MTLScissorRect sc = {(NSUInteger)sx, (NSUInteger)sy, (NSUInteger)sw, (NSUInteger)sh};
        if (!have_sc || memcmp(&sc, &cur_sc, sizeof sc)) { [enc setScissorRect:sc]; cur_sc = sc; have_sc = true; }
        bool hide_draw = false; int hide_id = 0;
        for (int i = 0; i < 8; i++) {
            if (!(key.fs.tex_mask & (1 << i))) continue;
            id<MTLTexture> t = g.map_valid[i] ? texture_for(g.map[i]) : black_tex;
            if (g_tex_hidden) { hide_draw = true; hide_id = g_tex_hidden_id; }
            id<MTLSamplerState> s = g.map_valid[i] ? sampler_for(g.map[i]) : linear_clamp;
            if (t != cur_tex[i]) { [enc setFragmentTexture:t atIndex:i]; cur_tex[i] = t; }
            if (s != cur_smp[i]) { [enc setFragmentSamplerState:s atIndex:i]; cur_smp[i] = s; }
            if (g.map_valid[i]) {
                uint64_t tk = (uint64_t)g.map[i].image | (uint64_t)g.map[i].width << 32;
                if (!frame_seen.count(tk)) { frame_seen[tk] = 1; census.tex_unique++; }
            }
        }
        // Oculta solo en sus piezas grandes de arriba (hide_top_big): en el lienzo alto la pantalla de arriba es y de 0 a 1
        // en la proyección del FE (240 píxeles por unidad); lo demás con esa textura se dibuja.
        if (hide_draw && dual_mode() && g_tall_proj) {
            const float min_h = w3d_ui_hidden_min_h(hide_id);
            if (min_h > 0) {
                const u16 *ix = (const u16 *)indices; float y0 = 1e9f, y1 = -1e9f;
                for (u32 i = 0; i < index_count; i++) {
                    const float *v = (const float *)((const char *)verts + ix[i] * stride); float p[4] = {0, 0, 0, 1}, q1 = 0, q3 = 0;
                    for (int r = 0; r < 3; r++) p[r] = vu.posmtx[r * 4] * v[0] + vu.posmtx[r * 4 + 1] * v[1] + vu.posmtx[r * 4 + 2] * v[2] + vu.posmtx[r * 4 + 3];
                    for (int c = 0; c < 4; c++) { q1 += vu.proj[4 + c] * p[c]; q3 += vu.proj[12 + c] * p[c]; }
                    if (fabsf(q3) > 1e-6f) { y0 = fminf(y0, q1 / q3); y1 = fmaxf(y1, q1 / q3); }
                }
                if (!(y0 >= 0 && (y1 - y0) * 240.f >= min_h)) hide_draw = false;
            }
        }
        if (hide_draw) return;   // pieza del menú que la pantalla de abajo sustituye (platform/ui/ui_hide.cpp)
        [enc setVertexBytes:&positioned length:sizeof positioned atIndex:1];
        [enc setFragmentBytes:&fu length:sizeof fu atIndex:0];
        FrameBuf &f = frames[frame_index];
        size_t ibytes = (size_t)index_count * 2;
        if (f.voff + vert_bytes > f.vb.length) {
            f.vb = [dev newBufferWithLength:MAX(f.vb.length * 2, (size_t)vert_bytes * 2) options:MTLResourceStorageModeShared];
            f.voff = 0;
        }
        if (f.ioff + ibytes > f.ib.length) {
            f.ib = [dev newBufferWithLength:MAX(f.ib.length * 2, ibytes * 2) options:MTLResourceStorageModeShared];
            f.ioff = 0;
        }
        memcpy((u8 *)f.vb.contents + f.voff, verts, vert_bytes);
        memcpy((u8 *)f.ib.contents + f.ioff, indices, ibytes);
        [enc setVertexBuffer:f.vb offset:f.voff atIndex:0];
        MTLPrimitiveType pt = topology == TOPO_TRI ? MTLPrimitiveTypeTriangle : topology == TOPO_LINE ? MTLPrimitiveTypeLine : MTLPrimitiveTypePoint;
        [enc drawIndexedPrimitives:pt indexCount:index_count indexType:MTLIndexTypeUInt16 indexBuffer:f.ib indexBufferOffset:f.ioff];
        f.voff = (f.voff + vert_bytes + 15) & ~(size_t)15;
        f.ioff = (f.ioff + ibytes + 3) & ~(size_t)3;
    }
}

void copy_display(bool clear, bool) {
    if (!dev) return;
    @autoreleasepool {
        ensure_command();
        // Si no hubo dibujo, aún hay que aplicar una limpieza pendiente.
        if (pending_clear_color || pending_clear_depth) ensure_encoder();
        end_encoder();
        int src_w = g.copy_src[2], src_h = g.copy_src[3];
        if (src_w <= 0) src_w = kEfbW;
        if (src_h <= 0) src_h = kEfbH;
        int dst_h = g.xfb_height ? g.xfb_height : src_h;
        if (xfb_pool.empty() || xfb_pool[0].width != (NSUInteger)(src_w * scale) || xfb_pool[0].height != (NSUInteger)(dst_h * scale)) {
            xfb_pool.clear();
            for (int i = 0; i < kInFlight + 1; i++) xfb_pool.push_back(make_rt(MTLPixelFormatBGRA8Unorm, src_w * scale, dst_h * scale, MTLTextureUsageRenderTarget | MTLTextureUsageShaderRead));
        }
        id<MTLTexture> xfb = xfb_pool[xfb_next];
        xfb_next = (xfb_next + 1) % (int)xfb_pool.size();
        {
            MTLRenderPassDescriptor *p = [MTLRenderPassDescriptor renderPassDescriptor];
            p.colorAttachments[0].texture = xfb;
            p.colorAttachments[0].loadAction = MTLLoadActionDontCare;
            p.colorAttachments[0].storeAction = MTLStoreActionStore;
            id<MTLRenderCommandEncoder> e = [cmd renderCommandEncoderWithDescriptor:p];
            CopyUniforms u = {};
            u.rect[0] = (float)g.copy_src[0] / kEfbW;
            u.rect[1] = (float)g.copy_src[1] / efb_alloc_h;
            u.rect[2] = (float)src_w / kEfbW;
            u.rect[3] = (float)src_h / efb_alloc_h;
            // Filtro vertical de la copia: 7 tomas sobre tres líneas, en sesenta y cuatroavos.
            u.vf[0] = (g.vfilter[0] + g.vfilter[1]) / 64.f;
            u.vf[1] = (g.vfilter[2] + g.vfilter[3] + g.vfilter[4]) / 64.f;
            u.vf[2] = (g.vfilter[5] + g.vfilter[6]) / 64.f;
            static const float gam[4] = {1.0f, 1.0f / 1.7f, 1.0f / 2.2f, 1.0f};
            u.rcp_gamma = gam[g.gamma & 3];
            u.dy = 1.f / (float)efb_alloc_h;
            [e setRenderPipelineState:copy_pipe];
            [e setVertexBytes:&u length:sizeof u atIndex:0];
            [e setFragmentBytes:&u length:sizeof u atIndex:0];
            [e setFragmentTexture:efb_color atIndex:0];
            [e setFragmentSamplerState:linear_clamp atIndex:0];
            [e drawPrimitives:MTLPrimitiveTypeTriangleStrip vertexStart:0 vertexCount:4];
            [e endEncoding];
        }
        plat::set_presented_texture((__bridge void *)xfb);
        if (dual_mode() && ui_pipe) {
            // Arriba: la imagen del juego a 400x240.
            MTLRenderPassDescriptor *p = [MTLRenderPassDescriptor renderPassDescriptor];
            p.colorAttachments[0].texture = ui_top;
            p.colorAttachments[0].loadAction = MTLLoadActionDontCare;
            p.colorAttachments[0].storeAction = MTLStoreActionStore;
            id<MTLRenderCommandEncoder> e = [cmd renderCommandEncoderWithDescriptor:p];
            CopyUniforms u = {}; u.rect[2] = u.rect[3] = 1; u.vf[1] = 1; u.rcp_gamma = 1;
            [e setRenderPipelineState:present_pipe];
            [e setVertexBytes:&u length:sizeof u atIndex:0];
            [e setFragmentBytes:&u length:sizeof u atIndex:0];
            [e setFragmentTexture:xfb atIndex:0];
            [e setFragmentSamplerState:linear_clamp atIndex:0];
            [e drawPrimitives:MTLPrimitiveTypeTriangleStrip vertexStart:0 vertexCount:4];
            [e endEncoding];
            // Abajo, con el lienzo alto: el mundo 3D que sigue bajo la pantalla de arriba (el centro de la mitad de abajo).
            if (g_tall_frame) {
                MTLRenderPassDescriptor *q = [MTLRenderPassDescriptor renderPassDescriptor];
                q.colorAttachments[0].texture = ui_bot;
                q.colorAttachments[0].loadAction = MTLLoadActionDontCare;
                q.colorAttachments[0].storeAction = MTLStoreActionStore;
                id<MTLRenderCommandEncoder> e2 = [cmd renderCommandEncoderWithDescriptor:q];
                CopyUniforms b = {};
                const float eh = (float)src_h;   // alto del cuadro del juego (454 en PAL): la mitad de abajo empieza ahí
                b.rect[0] = 64.f / kEfbW; b.rect[1] = eh / efb_alloc_h; b.rect[2] = 512.f / kEfbW; b.rect[3] = eh / efb_alloc_h;
                b.vf[1] = 1; b.rcp_gamma = 1; b.dy = 1.f / (float)efb_alloc_h;
                [e2 setRenderPipelineState:copy_pipe];
                [e2 setVertexBytes:&b length:sizeof b atIndex:0];
                [e2 setFragmentBytes:&b length:sizeof b atIndex:0];
                [e2 setFragmentTexture:efb_color atIndex:0];
                [e2 setFragmentSamplerState:linear_clamp atIndex:0];
                [e2 drawPrimitives:MTLPrimitiveTypeTriangleStrip vertexStart:0 vertexCount:4];
                [e2 endEncoding];
            }
            // La UI de las dos pantallas.
            ui_voff = 0;
            w3d_ui_after_frame();
            w3d_ui_frame();
            ui_end_encoder();
            g_tall_frame = w3d_ui_tall() != 0;   // para el cuadro siguiente
        }
        CAMetalLayer *layer = (__bridge CAMetalLayer *)plat::metal_layer();
        id<CAMetalDrawable> d = layer ? [layer nextDrawable] : nil;
        if (d && dual_mode() && ui_pipe) {
            MTLRenderPassDescriptor *p = [MTLRenderPassDescriptor renderPassDescriptor];
            p.colorAttachments[0].texture = d.texture;
            p.colorAttachments[0].loadAction = MTLLoadActionClear;
            p.colorAttachments[0].clearColor = MTLClearColorMake(0.08, 0.08, 0.09, 1);
            p.colorAttachments[0].storeAction = MTLStoreActionStore;
            id<MTLRenderCommandEncoder> e = [cmd renderCommandEncoderWithDescriptor:p];
            // Las dos pantallas en su sitio, a un múltiplo entero del tamaño de la 3DS.
            double dw = d.texture.width, dh = d.texture.height;
            DualLayout layout(dw, dh);
            double k = layout.scale, x0 = layout.x, y0 = layout.y;
            CopyUniforms u = {}; u.rect[2] = u.rect[3] = 1; u.vf[1] = 1; u.rcp_gamma = 1;
            [e setRenderPipelineState:present_pipe];
            [e setVertexBytes:&u length:sizeof u atIndex:0];
            [e setFragmentBytes:&u length:sizeof u atIndex:0];
            [e setFragmentSamplerState:linear_clamp atIndex:0];
            MTLViewport vt = {x0, y0, 400.0 * k, 240.0 * k, 0, 1};
            [e setViewport:vt]; [e setFragmentTexture:ui_top atIndex:0];
            [e drawPrimitives:MTLPrimitiveTypeTriangleStrip vertexStart:0 vertexCount:4];
            MTLViewport vb = {x0 + 40.0 * k, y0 + 240.0 * k, 320.0 * k, 240.0 * k, 0, 1};
            [e setViewport:vb]; [e setFragmentTexture:ui_bot atIndex:0];
            [e drawPrimitives:MTLPrimitiveTypeTriangleStrip vertexStart:0 vertexCount:4];
            [e endEncoding];
            [cmd presentDrawable:d];
            d = nil;
        }
        if (d) {
            MTLRenderPassDescriptor *p = [MTLRenderPassDescriptor renderPassDescriptor];
            p.colorAttachments[0].texture = d.texture;
            p.colorAttachments[0].loadAction = MTLLoadActionClear;
            p.colorAttachments[0].clearColor = MTLClearColorMake(0, 0, 0, 1);
            p.colorAttachments[0].storeAction = MTLStoreActionStore;
            id<MTLRenderCommandEncoder> e = [cmd renderCommandEncoderWithDescriptor:p];
            // Encaje 4:3 en la ventana.
            double dw = d.texture.width, dh = d.texture.height, w = dw, h = dw * 3.0 / 4.0;
            if (h > dh) { h = dh; w = dh * 4.0 / 3.0; }
            MTLViewport vp = {(dw - w) / 2, (dh - h) / 2, w, h, 0, 1};
            [e setViewport:vp];
            CopyUniforms u = {};
            u.rect[2] = u.rect[3] = 1;
            u.vf[1] = 1;
            u.rcp_gamma = 1;
            [e setRenderPipelineState:present_pipe];
            [e setVertexBytes:&u length:sizeof u atIndex:0];
            [e setFragmentBytes:&u length:sizeof u atIndex:0];
            [e setFragmentTexture:xfb atIndex:0];
            [e setFragmentSamplerState:linear_clamp atIndex:0];
            [e drawPrimitives:MTLPrimitiveTypeTriangleStrip vertexStart:0 vertexCount:4];
            [e endEncoding];
            [cmd presentDrawable:d];
        }
        // W3D_SHOT=<carpeta>[:<cada N cuadros>]: vuelca la imagen a PPM, para comprobar sin mirar la pantalla.
        static const char *shot_env = getenv("W3D_SHOT");
        id<MTLBuffer> shot_buf = nil; size_t shot_row = xfb.width * 4;
        if (shot_env) {
            static int every = 0; if (!every) { const char *c = strchr(shot_env, ':'); every = c ? atoi(c + 1) : 60; if (every < 1) every = 1; }
            if (frame_counter % every == 0) {
                shot_buf = [dev newBufferWithLength:shot_row * xfb.height options:MTLResourceStorageModeShared];
                id<MTLBlitCommandEncoder> b = [cmd blitCommandEncoder];
                [b copyFromTexture:xfb sourceSlice:0 sourceLevel:0 sourceOrigin:MTLOriginMake(0, 0, 0) sourceSize:MTLSizeMake(xfb.width, xfb.height, 1) toBuffer:shot_buf destinationOffset:0 destinationBytesPerRow:shot_row destinationBytesPerImage:shot_row * xfb.height];
                [b endEncoding];
            }
        }
        id<MTLBuffer> top_buf = nil, bot_buf = nil;
        if (shot_buf && dual_mode() && ui_pipe) { top_buf = grab(cmd, ui_top); bot_buf = grab(cmd, ui_bot); }
        [cmd commit];
        if (top_buf) {
            [cmd waitUntilCompleted];
            char dir[512]; snprintf(dir, sizeof dir, "%s", shot_env); if (char *c = strchr(dir, ':')) *c = 0;
            char path[600];
            snprintf(path, sizeof path, "%s/f%06d_top.ppm", dir, frame_counter); dump_ppm(top_buf, ui_top, path);
            snprintf(path, sizeof path, "%s/f%06d_bottom.ppm", dir, frame_counter); dump_ppm(bot_buf, ui_bot, path);
            shot_buf = nil;
        }
        if (shot_buf) {
            [cmd waitUntilCompleted];
            char dir[512]; snprintf(dir, sizeof dir, "%s", shot_env); if (char *c = strchr(dir, ':')) *c = 0;
            char path[600]; snprintf(path, sizeof path, "%s/f%06d.ppm", dir, frame_counter);
            if (FILE *f = fopen(path, "wb")) {
                fprintf(f, "P6\n%d %d\n255\n", (int)xfb.width, (int)xfb.height);
                const uint8_t *px = (const uint8_t *)shot_buf.contents;
                std::vector<uint8_t> row(xfb.width * 3);
                for (size_t y = 0; y < xfb.height; y++, px += shot_row) {
                    for (size_t x = 0; x < xfb.width; x++) { row[x * 3] = px[x * 4 + 2]; row[x * 3 + 1] = px[x * 4 + 1]; row[x * 3 + 2] = px[x * 4]; }
                    fwrite(row.data(), 1, row.size(), f);
                }
                fclose(f);
            }
        }
        cmd = nil;
        frame_index = (frame_index + 1) % kInFlight;
        frame_counter++;
        frame_seen.clear();
        evict_textures();
        if (clear) {
            // GXCopyDisp fuerza Z siempre; color y alfa respetan GXSetColorUpdate y GXSetAlphaUpdate.
            pending_clear_depth = true;
            clear_depth = g.clear_z / 16777215.0;
            if (g.color_update || g.alpha_update) {
                pending_clear_color = true;
                for (int i = 0; i < 4; i++) clear_rgba[i] = g.clear_color[i] / 255.f;
            }
        }
    }
}

}  // namespace backend
}  // namespace gx
}  // namespace w3d

// Backend de Mac de la UI (platform/ui/ui_backend.h).
using namespace w3d::gx::backend;
extern "C" {
int uib_tex_create(const uint8_t *rgba, unsigned w, unsigned h, int fmt, unsigned *pw, unsigned *ph) {
    if (!dev || !w || !h) return -1;
    unsigned tw = 8, th = 8; while (tw < w) tw <<= 1; while (th < h) th <<= 1;
    const bool mips = (fmt & 8) != 0;   // lo que se dibuja reducido (las piezas del logo del título)
    MTLTextureDescriptor *td = [MTLTextureDescriptor texture2DDescriptorWithPixelFormat:MTLPixelFormatRGBA8Unorm width:tw height:th mipmapped:mips ? YES : NO];
    td.storageMode = MTLStorageModeShared;
    id<MTLTexture> t = [dev newTextureWithDescriptor:td];
    std::vector<uint8_t> buf((size_t)tw * th * 4, 0);
    for (unsigned y = 0; y < h; y++) memcpy(&buf[(size_t)y * tw * 4], rgba + (size_t)y * w * 4, (size_t)w * 4);
    [t replaceRegion:MTLRegionMake2D(0, 0, tw, th) mipmapLevel:0 withBytes:buf.data() bytesPerRow:tw * 4];
    // Cada nivel, la media de 2x2 del anterior ponderada por el alfa (sin halos oscuros junto a lo transparente).
    std::vector<uint8_t> next;
    for (NSUInteger level = 1, cw = tw, ch = th; mips && level < t.mipmapLevelCount; level++) {
        const NSUInteger nw = cw > 1 ? cw / 2 : 1, nh = ch > 1 ? ch / 2 : 1;
        next.assign(nw * nh * 4, 0);
        for (NSUInteger y = 0; y < nh; y++) for (NSUInteger x = 0; x < nw; x++) {
            float c[3] = {0, 0, 0}, a = 0;
            for (NSUInteger k = 0; k < 4; k++) {
                const uint8_t *s = &buf[(MIN(y * 2 + k / 2, ch - 1) * cw + MIN(x * 2 + k % 2, cw - 1)) * 4];
                for (int e = 0; e < 3; e++) c[e] += s[e] * (float)s[3];
                a += s[3];
            }
            uint8_t *o = &next[(y * nw + x) * 4];
            if (a > 0) for (int e = 0; e < 3; e++) o[e] = (uint8_t)(c[e] / a + 0.5f);
            o[3] = (uint8_t)(a / 4 + 0.5f);
        }
        [t replaceRegion:MTLRegionMake2D(0, 0, nw, nh) mipmapLevel:level withBytes:next.data() bytesPerRow:nw * 4];
        buf.swap(next); cw = nw; ch = nh;
    }
    int id = -1;
    for (size_t i = 0; i < ui_textures.size(); i++) if (!ui_textures[i]) { id = (int)i; break; }
    if (id < 0) { id = (int)ui_textures.size(); ui_textures.push_back(nil); }
    ui_textures[id] = t;
    if (pw) *pw = tw;
    if (ph) *ph = th;
    return id;
}
void uib_tex_free(int id) { if (id >= 0 && id < (int)ui_textures.size()) ui_textures[id] = nil; }
void uib_tex_gc(void) {}
void uib_begin(int screen) {
    if (!ui_pipe || !cmd) return;
    ui_end_encoder();
    MTLRenderPassDescriptor *p = [MTLRenderPassDescriptor renderPassDescriptor];
    p.colorAttachments[0].texture = screen ? ui_bot : ui_top;
    p.colorAttachments[0].loadAction = MTLLoadActionLoad;
    p.colorAttachments[0].storeAction = MTLStoreActionStore;
    ui_enc = [cmd renderCommandEncoderWithDescriptor:p];
    [ui_enc setRenderPipelineState:ui_pipe];
    float scr[2] = {screen ? 320.f : 400.f, 240.f};
    [ui_enc setVertexBytes:scr length:sizeof scr atIndex:1];
    [ui_enc setFragmentSamplerState:ui_smp atIndex:0];
    ui_bound = -2;
}
void uib_quads(int tex, const float *v, const uint32_t *rgba, int n) {
    if (!ui_enc || n <= 0) return;
    id<MTLBuffer> b = ui_vb[frame_index];
    size_t bytes = (size_t)n * 6 * sizeof(UiVertex);
    if (ui_voff + bytes > b.length) return;
    UiVertex *o = (UiVertex *)((uint8_t *)b.contents + ui_voff);
    static const int kTri[6] = {0, 1, 2, 0, 2, 3};
    for (int q = 0; q < n; q++) for (int k = 0; k < 6; k++) { const float *c = v + q * 16 + kTri[k] * 4; *o++ = {c[0], c[1], c[2], c[3], rgba[q]}; }
    id<MTLTexture> t = tex >= 0 && tex < (int)ui_textures.size() ? ui_textures[tex] : nil;
    int use = t ? 1 : 0;
    if (tex != ui_bound) { [ui_enc setFragmentTexture:t ? t : black_tex atIndex:0]; ui_bound = tex; }
    [ui_enc setFragmentBytes:&use length:sizeof use atIndex:0];
    [ui_enc setVertexBuffer:b offset:ui_voff atIndex:0];
    [ui_enc drawPrimitives:MTLPrimitiveTypeTriangle vertexStart:0 vertexCount:n * 6];
    ui_voff += bytes;
}
// Triángulos sueltos con color por vértice (en Mac el worm de Crear equipo va por menu_underlay; esto es el camino directo).
void uib_tris(int tex, const float *v, const uint32_t *rgba, int n) {
    if (!ui_enc || n < 3) return;
    n -= n % 3;
    id<MTLBuffer> b = ui_vb[frame_index];
    size_t bytes = (size_t)n * sizeof(UiVertex);
    if (ui_voff + bytes > b.length) return;
    UiVertex *o = (UiVertex *)((uint8_t *)b.contents + ui_voff);
    for (int i = 0; i < n; i++) *o++ = {v[i * 4], v[i * 4 + 1], v[i * 4 + 2], v[i * 4 + 3], rgba[i]};
    id<MTLTexture> t = tex >= 0 && tex < (int)ui_textures.size() ? ui_textures[tex] : nil;
    int use = t ? 1 : 0;
    if (tex != ui_bound) { [ui_enc setFragmentTexture:t ? t : black_tex atIndex:0]; ui_bound = tex; }
    [ui_enc setFragmentBytes:&use length:sizeof use atIndex:0];
    [ui_enc setVertexBuffer:b offset:ui_voff atIndex:0];
    [ui_enc drawPrimitives:MTLPrimitiveTypeTriangle vertexStart:0 vertexCount:n];
    ui_voff += bytes;
}
void uib_end(void) { ui_end_encoder(); }
void uib_blend(int mode) { if (ui_enc) [ui_enc setRenderPipelineState:mode == 1 && ui_pipe_max ? ui_pipe_max : ui_pipe]; }
double uib_seconds(void) { return w3d::plat::now_seconds(); }
int uib_console_lang(void) {
    const char *l = getenv("W3D_LANG");
    if (!l) return 0;
    return !strcmp(l, "fr") ? 1 : !strcmp(l, "de") ? 2 : !strcmp(l, "it") ? 3 : !strcmp(l, "es") ? 4 : 0;
}
int uib_console_busy(void) { return 0; }
static int g_dev[2] = {1, 1};
int uib_dev_get(int which) { return g_dev[which & 1]; }
void uib_dev_set(int which, int v) { g_dev[which & 1] = v; }
int uib_test_running(void) { return 0; }
int uib_read_own(const char *name, unsigned char **data, long *size) {
    NSString *folder = [NSBundle.mainBundle.resourcePath stringByAppendingPathComponent:@"ui"];
    NSString *file = [folder stringByAppendingPathComponent:[NSString stringWithUTF8String:name]];
    FILE *f = fopen(file.fileSystemRepresentation, "rb");
    if (!f) return 0;
    fseek(f, 0, SEEK_END); long n = ftell(f); fseek(f, 0, SEEK_SET);
    unsigned char *d = (unsigned char *)malloc(n);
    bool ok = d && fread(d, 1, n, f) == (size_t)n;
    fclose(f);
    if (!ok) { free(d); return 0; }
    *data = d; *size = n;
    return 1;
}
void uib_free(void *p) { free(p); }
void uib_log(const char *fmt, ...) { va_list a; va_start(a, fmt); vfprintf(stderr, fmt, a); va_end(a); }
}
