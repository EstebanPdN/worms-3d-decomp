// Estado GX en C++ y frontera con el backend de Metal.
//
// El juego usa la API GX (85 funciones, ver port/docs-data/sdk-boundary.json). sdk_gx.cpp traduce cada
// A<dirección> a una llamada de aquí. Decisiones que afectan a la fidelidad:
//
// - FIFO real: los vértices inmediatos y las listas se codifican con los mismos bytes que el hardware
//   (órdenes de primitiva con recuento big-endian y datos big-endian). Una lista vive en el búfer del
//   juego, sobrevive a su memcpy y GXCallDisplayList la decodifica con el VCD y el VAT del momento,
//   igual que la consola. Ver fifo_* y decode_stream en gx_state.cpp.
// - Matrices en memoria XF con las direcciones de la consola (id*4 palabras, posmatriz id>=64, normal id*3).
// - TEV en enteros de 8 bits con registros de 11 bits, como Dolphin y el hardware. Ver gx_shader.cpp.
// - Orden de bytes: las matrices y arrays de 16/32 bits en memoria del invitado están en el orden del
//   anfitrión (el lector de XOM ya convirtió); los colores RGBA8 de arrays y las texturas se leen
//   byte a byte. Los teselos de textura son big-endian: el juego los escribe con bytes sueltos
//   (d10d_*_tile_*, d26e_tile_*). La TLUT es de 16 bits en el orden del anfitrión: su único escritor
//   (d41j_mesh_bind_palette_8016c4f4) la guarda con *d = v.
#ifndef W3D_GX_INTERNAL_H
#define W3D_GX_INTERNAL_H
#include <stddef.h>
#include <stdint.h>

namespace w3d {
namespace gx {

typedef uint8_t u8;
typedef uint16_t u16;
typedef unsigned int u32;
typedef int8_t s8;
typedef int16_t s16;

enum {
    VA_PNMTX = 0, VA_TEX0MTX = 1, VA_POS = 9, VA_NRM = 10, VA_CLR0 = 11, VA_CLR1 = 12, VA_TEX0 = 13,
    VA_NBT = 25, VA_COUNT = 26,
    ATTR_NONE = 0, ATTR_DIRECT = 1, ATTR_INDEX8 = 2, ATTR_INDEX16 = 3,
    PRIM_QUADS = 0x80, PRIM_QUADS2 = 0x88, PRIM_TRIS = 0x90, PRIM_STRIP = 0x98, PRIM_FAN = 0xa0,
    PRIM_LINES = 0xa8, PRIM_LINESTRIP = 0xb0, PRIM_POINTS = 0xb8,
    TOPO_TRI = 0, TOPO_LINE = 1, TOPO_POINT = 2,
    TEX_I4 = 0, TEX_I8 = 1, TEX_IA4 = 2, TEX_IA8 = 3, TEX_RGB565 = 4, TEX_RGB5A3 = 5, TEX_RGBA8 = 6,
    TEX_CI4 = 8, TEX_CI8 = 9, TEX_CI14 = 10, TEX_CMPR = 14,
    TL_IA8 = 0, TL_RGB565 = 1, TL_RGB5A3 = 2,
    TLUT_SLOTS = 20,
};

struct VtxAttr { u8 cnt, type, frac; };

struct TexGen { u8 func, src, normalize; u32 mtx, post; };

struct ChanCtrl { u8 enable, amb_src, mat_src, diff, attn; u8 mask; };

// Disposición del GXLightObj de la consola (64 B): el juego lo ve como memoria opaca.
struct LightObj {
    u32 pad[3];
    u8 color[4];
    float a0, a1, a2, k0, k1, k2, px, py, pz, nx, ny, nz;
};
static_assert(sizeof(LightObj) == 64, "GXLightObj ocupa 64 B");

struct TevStage {
    u8 ca, cb, cc, cd, cop, cbias, cscale, cclamp, cout;
    u8 aa, ab, ac, ad, aop, abias, ascale, aclamp, aout;
    u8 ksel_c, ksel_a, ras_swap, tex_swap;
    u8 coord, map, chan;  // Tal como llega de GXSetTevOrder: 0xff es nulo, map&0x100 desactiva la textura.
    u8 ind_stage, ind_fmt, ind_bias, ind_mtx, ind_wrap_s, ind_wrap_t;  // GXSetTevIndirect o GXSetTevDirect.
    u8 pad0;
};

struct IndOrder { u8 coord, map, scale_s, scale_t; };

// Vista en memoria del invitado del GXTexObj (32 B). Formato en +0x14 como la consola; el resto es propio.
struct GTexObj {
    u8 wrap_s, wrap_t, min_filter, mag_filter;
    u8 min_lod16, max_lod16, aniso, mip;
    u16 width, height;
    u32 image;
    u32 tlut;
    u32 format;
    s16 bias32;
    u16 pad1;
    u32 pad2;
};
static_assert(sizeof(GTexObj) == 32, "GXTexObj ocupa 32 B");

struct GTlutObj { u32 lut; u16 count; u8 format; u8 pad; u32 pad2; };
static_assert(sizeof(GTlutObj) == 12, "GXTlutObj ocupa 12 B");

struct TlutSlot { u16 entries[16384]; u32 count; u8 format; uint64_t hash; u32 src; bool loaded; };   // v34: src/loaded, copia perezosa (tlut_data)

struct State {
    // Vértices.
    u8 vcd[VA_COUNT];
    VtxAttr vat[8][VA_COUNT];
    u32 array_base[VA_COUNT];
    u8 array_stride[VA_COUNT];
    // Memoria XF.
    float xf[256], post[256], nrm[96];
    float proj[6];
    u32 proj_type;
    u32 cur_pos;
    TexGen texgen[8];
    u8 num_texgens;
    LightObj lights[8];
    u8 amb[2][4], mat[2][4];
    ChanCtrl chan[4];  // 0 COLOR0, 1 COLOR1, 2 ALPHA0, 3 ALPHA1.
    u8 num_chans;
    // TEV.
    TevStage tev[16];
    u8 num_stages;
    s16 reg[4][4];
    u8 konst[4][4];
    u8 swap[4][4];
    u8 num_ind;
    IndOrder ind[4];
    float ind_mtx[3][6];
    s8 ind_exp[3];
    u8 cmp0, ref0, cmp_op, cmp1, ref1;
    // Texturas.
    GTexObj map[8];
    u8 map_valid[8];
    u32 tex_epoch;
    // Píxeles.
    float vp[6];
    u32 scissor[4];
    u8 cull;
    u8 blend_type, blend_src, blend_dst, logic_op;
    u8 color_update, alpha_update;
    u8 z_enable, z_func, z_update, z_before_tex;
    u8 pixel_fmt, z_fmt;
    // Copia a pantalla.
    u16 copy_src[4];
    u16 copy_dst[2];
    u32 copy_y_scale;
    u16 xfb_height;
    u8 clear_color[4];
    u32 clear_z;
    u8 gamma;
    u8 vfilter[7];
    u16 draw_token;
};

extern State g;

// Máquina de estado.
void init_state();
void touch();          // Antes de cambiar estado: vacía el lote pendiente, cuenta el cambio y sube g_state_gen.
void touch_keep();     // v34: igual sin subir g_state_gen (matrices, arrays y formato de vértices).
// v34: generación del estado de GX. Las funciones de estado (sdk_gx.cpp) solo la suben si un valor cambia; draw3ds
// (gx_pica.cpp) se salta el trabajo del estado mientras no cambie.
extern u32 g_state_gen;
void flush_batch();    // Lanza el lote pendiente.
void flush_any();      // v36: lo mismo desde el hilo del juego (a la cola de gx_mt.h si está activa).

// FIFO: cada escritura entra en big-endian, como el puerto 0xcc008000.
void begin(u32 prim, u32 fmt, u32 count);
void fifo_u8(u8 v);
void fifo_u16(u16 v);
void fifo_u32(u32 v);
void fifo_f32(float v);
void fifo_bytes(const void *p, u32 n);  // Bytes tal cual, por ejemplo un GXColor en memoria.

// v37: caminos nativos de la capa XGX (sdk_gx_xgx.cpp), tras GXBegin. Entregan lo mismo que la FIFO sin pasar por ella:
// el formato de vértice se comprueba con el VCD y el VAT del momento, y si no es el esperado devuelven nullptr/false y
// el llamante sigue por la FIFO. debug.ini: W3D_GX_NATIVE=<bits> (1 mallas, 2 cuadrados, 4 texto, 8 cambios de estado sin efecto
// que no se envían, en gx_mt.cpp; por defecto 15; 0 = v36).
// - Malla por índices: hasta 4 flujos de índices del juego (dirección 0 = índices secuenciales), de 1 o 2 bytes.
//   La identidad de la malla es el hash de los índices; el flujo solo se construye la primera vez que se ve.
struct MeshSrc { u32 ptr[4]; u8 isz[4]; u32 n; };
#if defined(__3DS__)
bool fifo_mesh(const MeshSrc &s, u32 count);
u8 *quads_begin(u32 count);   // sitio para `count` vértices de 24 B: posición float×3, RGBA8, uv float×2
void quads_end();
bool quad_s16(const s16 *q);  // 4 esquinas x, y, z, u, v en s16 (texto)
#else
inline bool fifo_mesh(const MeshSrc &, u32) { return false; }
inline u8 *quads_begin(u32) { return nullptr; }
inline void quads_end() {}
inline bool quad_s16(const s16 *) { return false; }
#endif

// Listas de visualización codificadas en el búfer del juego.
void dl_begin(u32 guest, u32 size);
u32 dl_end();
void dl_call(u32 guest, u32 size);
bool dl_recording();

// Copia a pantalla.
void copy_display(bool clear);

// Censo por imagen (W3D_GX_CENSUS=ruta).
struct Census {
    u32 begins, draws, vertices, triangles;
    u32 tev_stage_sum, tev_stage_max, ind_draws, blend_draws, alphatest_draws, lit_draws;
    u32 tex_binds, tex_unique, tex_uploads;
    u32 pos_mtx_loads, nrm_mtx_loads, tex_mtx_loads, mtx_per_draw_loads;
    u32 state_changes, pipeline_switches, dl_calls, lights_max;
};
extern Census census;
void census_end_frame();

// Texturas: decodifica un nivel a RGBA8. tlut en orden de anfitrión.
u32 tex_level_bytes(u32 w, u32 h, u32 fmt);
void tex_decode(const u8 *src, u32 w, u32 h, u32 fmt, const u16 *tlut, u32 tlut_fmt, u8 *rgba, u32 tlut_count = 0);
uint64_t tex_hash(const u8 *src, size_t bytes);
u32 tex_buffer_size(u32 w, u32 h, u32 fmt, bool mip, u32 max_lod);
const TlutSlot &tlut_slot(u32 name);
const u16 *tlut_data(const TlutSlot &t);   // v34: los colores de la paleta (se copian aquí si la carga no lo hizo)
void tlut_load(const GTlutObj &o, u32 name);
bool tlut_same(const GTlutObj &o, u32 name);   // v34: la ranura ya tiene esta paleta (GXLoadTlut no hace nada)

// Claves de sombreado. Se calculan desde State y se comparan como bytes.
struct VsKey {
    u16 attrs;   // bit 0 pos, 1 nrm, 2 clr0, 3 clr1, 4.. tex0..7.
    u8 num_texgens, num_chans;
    u8 point, pad[3];
    struct { u8 func, src, normalize, has_post; } tg[8];
    ChanCtrl ch[4];
};
struct FsKey {
    u8 num_stages, num_ind, tex_mask, logic;  // logic: 0 sin operación lógica, 1+op.
    u8 cmp0, cmp1, cmp_op, early;
    struct S {
        u8 ca, cb, cc, cd, cop, cbias, cscale, cclamp, cout;
        u8 aa, ab, ac, ad, aop, abias, ascale, aclamp, aout;
        u8 ksel_c, ksel_a, tex, ras;  // tex: mapa o 0xff; ras: 0 c0, 1 c1, 0xff nulo.
        u8 uv, ind, ind_bias, ind_mtx, ind_wrap;  // ind: etapa o 0xff.
        char ras_swz[4], tex_swz[4];
    } s[16];
    struct I { u8 uv, map, sx, sy; } ind[4];
};
struct RasterKey {
    u8 blend, src, dst, op;
    u8 write_rgb, write_a, dst_has_alpha, pad;
};
struct PipelineKey { VsKey vs; FsKey fs; RasterKey r; };

// Uniformes con la disposición de los sombreadores generados.
struct VsUniforms {
    float posmtx[12], nrmmtx[12], proj[16];
    float texmtx[8][12], postmtx[8][12];
    float amb[2][4], mat[2][4];
    struct { float color[4], cosatt[4], distatt[4], pos[4], dir[4]; } light[8];
};
struct FsUniforms {
    int32_t reg[4][4];
    int32_t konst[4][4];
    float ind_mtx[3][2][4];
    int32_t ref0, ref1, pad0, pad1;
    float lod_bias[8];
};

void build_pipeline_key(PipelineKey &k, u32 topology, u16 attrs);
void build_vs_uniforms(VsUniforms &u);
// Lienzo alto (Mac a dos pantallas, menús): el cuadro del juego va a la mitad de arriba de un EFB del doble de alto y
// el mundo 3D sigue en la de abajo, que es el fondo de la pantalla de abajo. Lo pone gx_metal.mm por dibujo.
extern bool g_tall_frame, g_tall_proj;
void build_fs_uniforms(FsUniforms &u);
// Fuente MSL para una clave. El backend la compila y la guarda en caché.
const char *shader_source(const PipelineKey &k);  // Vive hasta la siguiente llamada.

// Backend de Metal.
namespace backend {
void init();
void draw(const PipelineKey &key, const VsUniforms &vu, const FsUniforms &fu, const void *verts, u32 vert_bytes,
          u32 stride, const void *indices, u32 index_count, u32 topology);
void copy_display(bool clear, bool z_clear_only);
int efb_scale();
void draw3ds(const void *verts, u32 count, u32 stride, u16 attrs, const u16 *indices, u32 index_count, u32 topology);
// Geometría residente: una lista ya decodificada se dibuja desde su búfer de GPU, sin tocar vértices en la CPU.
bool list_try(u32 guest, u32 size, u16 attrs, u32 content);   // true: dibujada.
bool list_try_fast(u32 guest, u32 size, u16 attrs, u32 bases);   // Sin comparar contenido si nada se ha vaciado en sus páginas.
void list_set_ranges(const u32 *starts, const u32 *bytes, int n, u32 bases);
bool list_try_dyn(u32 guest, u32 size, u16 attrs, u32 bases_static);   // Malla con piel: solo posiciones y normales cambian.
bool list_vol_skip(u32 guest, u32 size, u16 attrs, u32 bases);   // v34: lista que cambia en cada cuadro y sigue tocándose: al anillo sin firma.
bool list_wants_maps();
void list_set_maps(const u16 *pos, const u16 *nrm, u32 n, u32 bases_static);
void list_capture_begin();
void list_capture_end();
}  // namespace backend

}  // namespace gx
}  // namespace w3d
#endif
