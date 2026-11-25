#include <stdlib.h>
// Claves de sombreado y generador de MSL.
//
// Vértices: XF de la consola (matriz actual, proyección reducida a 6 parámetros, generadores de coordenadas
// e iluminación por vértice). Píxeles: TEV en enteros, con la fórmula de Dolphin, porque el redondeo de 8 bits
// se nota en las rampas y el resultado de la consola se reproduce sin coma flotante.
#include "gx_internal.h"
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <string>

namespace w3d {
namespace gx {

namespace {

const char *cc_arg(int a) {
    static const char *t[16] = {"r0.rgb", "r0.aaa", "r1.rgb", "r1.aaa", "r2.rgb", "r2.aaa", "r3.rgb", "r3.aaa",
                                "tex.rgb", "tex.aaa", "ras.rgb", "ras.aaa", "int3(255)", "int3(128)", "k.rgb", "int3(0)"};
    return t[a & 15];
}
const char *ca_arg(int a) {
    static const char *t[8] = {"r0.a", "r1.a", "r2.a", "r3.a", "tex.a", "ras.a", "k.a", "0"};
    return t[a & 7];
}
std::string cmp_expr(int c, const char *r) {
    static const char *t[8] = {"false", "(a < ", "(a == ", "(a <= ", "(a > ", "(a != ", "(a >= ", "true"};
    c &= 7;
    if (c == 0 || c == 7) return t[c];
    return std::string(t[c]) + r + ")";
}

void ap(std::string &s, const char *f, ...) {
    char b[1024];
    va_list v;
    va_start(v, f);
    vsnprintf(b, sizeof b, f, v);
    va_end(v);
    s += b;
}

// Color constante de GXSetTevKColorSel.
std::string ksel_rgb(int s) {
    static const int fx[8] = {255, 223, 191, 159, 128, 96, 64, 32};
    char b[64];
    if (s < 8) snprintf(b, sizeof b, "int3(%d)", fx[s]);
    else if (s >= 0xc && s <= 0xf) snprintf(b, sizeof b, "u.konst[%d].rgb", s - 0xc);
    else if (s >= 0x10) snprintf(b, sizeof b, "u.konst[%d].%c%c%c", (s - 0x10) & 3, "rgba"[((s - 0x10) >> 2) & 3], "rgba"[((s - 0x10) >> 2) & 3], "rgba"[((s - 0x10) >> 2) & 3]);
    else snprintf(b, sizeof b, "int3(0)");
    return b;
}
std::string ksel_a(int s) {
    static const int fx[8] = {255, 223, 191, 159, 128, 96, 64, 32};
    char b[64];
    if (s < 8) snprintf(b, sizeof b, "%d", fx[s]);
    else if (s >= 0x10) snprintf(b, sizeof b, "u.konst[%d].%c", (s - 0x10) & 3, "rgba"[((s - 0x10) >> 2) & 3]);
    else snprintf(b, sizeof b, "0");
    return b;
}

// Combinador de un canal: 0 color, 1 alfa. Escribe en cres / ares.
void gen_combine(std::string &o, bool alpha, int op, int bias, int scale, int clamp_) {
    const char *t = alpha ? "ares" : "cres";
    const char *ia = alpha ? "ia.a" : "ia.rgb", *ib = alpha ? "ib.a" : "ib.rgb", *ic = alpha ? "ic.a" : "ic.rgb", *id = alpha ? "id.a" : "id.rgb";
    if (op <= 1) {
        int ls = scale == 1 ? 1 : scale == 2 ? 2 : 0, rs = scale == 3 ? 1 : 0;
        const char *bs = bias == 1 ? " + 128" : bias == 2 ? " - 128" : "";
        ap(o, "  {auto cc = %s; cc = cc + (cc >> 7); auto l = (((%s * (256 - cc) + %s * cc) << %d) + %d) >> 8;\n", ic, ia, ib, ls, op == 1 ? 127 : 128);
        ap(o, "   %s = ((((%s%s) << %d) %c l) >> %d);}\n", t, id, bs, ls, op == 1 ? '-' : '+', rs);
    } else {
        // Comparaciones: R8, GR16, BGR24, RGB8/A8. Los pares son >, los impares ==.
        const char *rel = (op & 1) ? "==" : ">";
        int kind = (op - 8) >> 1;
        if (kind == 3) {
            if (alpha) ap(o, "  %s = %s + ((ia.a %s ib.a) ? ic.a : 0);\n", t, id, rel);
            else ap(o, "  %s = %s + select(int3(0), ic.rgb, ia.rgb %s ib.rgb);\n", t, id, rel);
        } else {
            const char *pa = kind == 0 ? "ia.r" : kind == 1 ? "((ia.g << 8) | ia.r)" : "((ia.b << 16) | (ia.g << 8) | ia.r)";
            const char *pb = kind == 0 ? "ib.r" : kind == 1 ? "((ib.g << 8) | ib.r)" : "((ib.b << 16) | (ib.g << 8) | ib.r)";
            ap(o, "  %s = %s + ((%s %s %s) ? %s : %s);\n", t, id, pa, rel, pb, ic, alpha ? "0" : "int3(0)");
        }
    }
    if (clamp_) ap(o, "  %s = clamp(%s, %s, %s);\n", t, t, alpha ? "0" : "int3(0)", alpha ? "255" : "int3(255)");
    else ap(o, "  %s = clamp(%s, %s, %s);\n", t, t, alpha ? "-1024" : "int3(-1024)", alpha ? "1023" : "int3(1023)");
}

void gen_light(std::string &o, const char *acc, const char *comp, const ChanCtrl &c) {
    for (int i = 0; i < 8; i++) {
        if (!(c.mask & (1 << i))) continue;
        ap(o, "  {constant Light &l = U.light[%d]; float3 L = l.pos.xyz - vp; float att = 1.0, dif = 1.0;\n", i);
        if (c.attn == 0) {  // GX_AF_SPEC
            o += "   L = normalize(L); float x = dot(vn, L) >= 0.0 ? max(0.0, dot(vn, l.dir.xyz)) : 0.0;\n";
            o += "   float3 da = l.distatt.xyz;\n";
            if (c.diff == 0) o += "   da = normalize(da);\n";
            o += "   att = max(0.0, dot(l.cosatt.xyz, float3(1.0, x, x * x))) / dot(da, float3(1.0, x, x * x));\n";
        } else if (c.attn == 1) {  // GX_AF_SPOT
            o += "   float d2 = dot(L, L), d = sqrt(d2); L = L / d; float x = max(0.0, dot(L, l.dir.xyz));\n";
            o += "   att = max(0.0, dot(l.cosatt.xyz, float3(1.0, x, x * x))) / dot(l.distatt.xyz, float3(1.0, d, d2));\n";
        } else {
            o += "   L = normalize(L);\n";
        }
        if (c.diff == 1) o += "   dif = dot(L, vn);\n";
        else if (c.diff == 2) o += "   dif = max(0.0, dot(L, vn));\n";
        ap(o, "   %s += att * dif * l.color.%s;}\n", acc, comp);
    }
}

void gen_chan(std::string &o, const VsKey &k, int idx, const ChanCtrl &col, const ChanCtrl &alp) {
    const char *va = idx == 0 ? "v.c0" : "v.c1";
    bool has = k.attrs & (idx == 0 ? 4 : 8);
    std::string vc = has ? va : "float4(1.0)";
    ap(o, " {float4 vc = %s; float3 mc = %s; float ma = %s;\n", vc.c_str(), col.mat_src ? "vc.rgb" : (idx ? "U.mat[1].rgb" : "U.mat[0].rgb"), alp.mat_src ? "vc.a" : (idx ? "U.mat[1].a" : "U.mat[0].a"));
    if (col.enable) {
        ap(o, "  float3 ac = %s;\n", col.amb_src ? "vc.rgb" : (idx ? "U.amb[1].rgb" : "U.amb[0].rgb"));
        gen_light(o, "ac", "rgb", col);
        o += "  mc = mc * clamp(ac, 0.0, 1.0);\n";
    }
    if (alp.enable) {
        ap(o, "  float aa = %s;\n", alp.amb_src ? "vc.a" : (idx ? "U.amb[1].a" : "U.amb[0].a"));
        gen_light(o, "aa", "a", alp);
        o += "  ma = ma * clamp(aa, 0.0, 1.0);\n";
    }
    ap(o, "  o.c%d = float4(mc, ma);}\n", idx);
}

std::string gen_vs(const VsKey &k) {
    std::string o;
    o += "#include <metal_stdlib>\nusing namespace metal;\n";
    o += "struct Light { float4 color, cosatt, distatt, pos, dir; };\n";
    o += "struct VU { float4 posmtx[3]; float4 nrmmtx[3]; float4 proj[4]; float4 texmtx[24]; float4 postmtx[24];\n";
    o += " float4 amb[2]; float4 mat[2]; Light light[8]; };\n";
    o += "struct VI { float3 pos [[attribute(0)]];\n";
    if (k.attrs & 2) o += " float3 nrm [[attribute(1)]];\n";
    if (k.attrs & 4) o += " float4 c0 [[attribute(2)]];\n";
    if (k.attrs & 8) o += " float4 c1 [[attribute(3)]];\n";
    for (int i = 0; i < 8; i++) if (k.attrs & (16 << i)) ap(o, " float2 t%d [[attribute(%d)]];\n", i, 4 + i);
    o += "};\nstruct VO { float4 p [[position, invariant]]; float4 c0; float4 c1;\n";
    for (int i = 0; i < k.num_texgens; i++) ap(o, " float3 u%d;\n", i);
    if (k.point) o += " float ps [[point_size]];\n";
    o += "};\n";
    o += "vertex VO vs_main(VI v [[stage_in]], constant VU &U [[buffer(1)]]) {\n VO o;\n float4 p4 = float4(v.pos, 1.0);\n";
    o += " float3 vp = float3(dot(U.posmtx[0], p4), dot(U.posmtx[1], p4), dot(U.posmtx[2], p4));\n";
    if (k.attrs & 2) o += " float3 vn = normalize(float3(dot(U.nrmmtx[0].xyz, v.nrm), dot(U.nrmmtx[1].xyz, v.nrm), dot(U.nrmmtx[2].xyz, v.nrm)));\n";
    else o += " float3 vn = float3(0.0, 0.0, 1.0);\n";
    // El Z de la consola va de -w (cerca) a 0 (lejos); Metal de 0 a w.
    o += " float4 vp4 = float4(vp, 1.0);\n o.p = float4(dot(U.proj[0], vp4), dot(U.proj[1], vp4), dot(U.proj[2], vp4), dot(U.proj[3], vp4));\n o.p.z += o.p.w;\n";
    if (k.point) o += " o.ps = 1.0;\n";
    if (k.num_chans == 0) {
        o += (k.attrs & 4) ? " o.c0 = v.c0;\n" : " o.c0 = float4(1.0);\n";
    } else {
        gen_chan(o, k, 0, k.ch[0], k.ch[2]);
    }
    if (k.num_chans < 2) {
        o += (k.attrs & 8) ? " o.c1 = v.c1;\n" : " o.c1 = o.c0;\n";
    } else {
        gen_chan(o, k, 1, k.ch[1], k.ch[3]);
    }
    for (int i = 0; i < k.num_texgens; i++) {
        int src = k.tg[i].src, func = k.tg[i].func;
        ap(o, " {float4 s;\n");
        if (src == 0) o += "  s = p4;\n";
        else if (src == 1) o += (k.attrs & 2) ? "  s = float4(v.nrm, 1.0);\n" : "  s = float4(0.0, 0.0, 1.0, 1.0);\n";
        else if (src >= 4 && src <= 11) {
            if (k.attrs & (16 << (src - 4))) ap(o, "  s = float4(v.t%d, 1.0, 1.0);\n", src - 4);
            else o += "  s = float4(0.0, 0.0, 1.0, 1.0);\n";
        } else if (src >= 12 && src <= 18 && src - 12 < i) ap(o, "  s = float4(o.u%d, 1.0);\n", src - 12);
        else o += "  s = float4(0.0, 0.0, 1.0, 1.0);\n";
        if (func == 0) ap(o, "  float3 c = float3(dot(U.texmtx[%d], s), dot(U.texmtx[%d], s), dot(U.texmtx[%d], s));\n", i * 3, i * 3 + 1, i * 3 + 2);
        else if (func == 1) ap(o, "  float3 c = float3(dot(U.texmtx[%d], s), dot(U.texmtx[%d], s), 1.0);\n", i * 3, i * 3 + 1);
        else if (func == 10) ap(o, "  float3 c = float3(%s.r, %s.g, 1.0);\n", src == 20 ? "o.c1" : "o.c0", src == 20 ? "o.c1" : "o.c0");
        else o += "  float3 c = float3(s.xy, 1.0);\n";
        if (k.tg[i].normalize && func == 0) o += "  c = normalize(c);\n";
        if (k.tg[i].has_post) {
            o += "  float4 c4 = float4(c, 1.0);\n";
            ap(o, "  c = float3(dot(U.postmtx[%d], c4), dot(U.postmtx[%d], c4), dot(U.postmtx[%d], c4));\n", i * 3, i * 3 + 1, i * 3 + 2);
        }
        ap(o, "  o.u%d = c;}\n", i);
    }
    o += " return o;\n}\n";
    return o;
}

void gen_stage(std::string &o, const FsKey &k, const VsKey &vk, int i) {
    const FsKey::S &s = k.s[i];
    ap(o, " {// Etapa %d\n  int4 tex = int4(0), ras = int4(0);\n  int4 k = int4(0);\n", i);
    if (s.tex != 0xff) {
        char uv[64];
        if (s.uv < vk.num_texgens) snprintf(uv, sizeof uv, "(in.u%d.xy / in.u%d.z)", s.uv, s.uv);
        else snprintf(uv, sizeof uv, "float2(0.0)");
        if (s.ind != 0xff && s.ind < k.num_ind) {
            ap(o, "  float2 dim = float2(t%d.get_width(), t%d.get_height());\n", s.tex, s.tex);
            ap(o, "  int3 ic3 = ind%d.abg;\n", s.ind);
            if (s.ind_bias & 1) o += "  ic3.x -= 128;\n";
            if (s.ind_bias & 2) o += "  ic3.y -= 128;\n";
            if (s.ind_bias & 4) o += "  ic3.z -= 128;\n";
            if (s.ind_mtx >= 1 && s.ind_mtx <= 3) {
                ap(o, "  float3 ofs = float3(ic3);\n  float2 off = float2(dot(u.ind_mtx[%d][0].xyz, ofs), dot(u.ind_mtx[%d][1].xyz, ofs)) * u.ind_mtx[%d][0].w;\n", s.ind_mtx - 1, s.ind_mtx - 1, s.ind_mtx - 1);
            } else {
                o += "  float2 off = float2(0.0);\n";
            }
            // Desplazamiento en texeles: la coordenada base se conserva salvo con envoltura 0 (GXSetTevIndWarp con reemplazo).
            if (s.ind_wrap) ap(o, "  float2 suv = off / dim;\n");
            else ap(o, "  float2 suv = %s + off / dim;\n", uv);
        } else {
            ap(o, "  float2 suv = %s;\n", uv);
        }
        ap(o, "  tex = int4(round(t%d.sample(s%d, suv, bias(u.lod_bias[%d])) * 255.0)).%.4s;\n", s.tex, s.tex, s.tex, s.tex_swz);
    }
    if (s.ras != 0xff) ap(o, "  ras = int4(round(saturate(in.c%d) * 255.0)).%.4s;\n", s.ras, s.ras_swz);
    ap(o, "  k = int4(%s, %s);\n", ksel_rgb(s.ksel_c).c_str(), ksel_a(s.ksel_a).c_str());
    ap(o, "  int4 ia = int4(%s, %s) & 255;\n", cc_arg(s.ca), ca_arg(s.aa));
    ap(o, "  int4 ib = int4(%s, %s) & 255;\n", cc_arg(s.cb), ca_arg(s.ab));
    ap(o, "  int4 ic = int4(%s, %s) & 255;\n", cc_arg(s.cc), ca_arg(s.ac));
    ap(o, "  int4 id = int4(%s, %s);\n", cc_arg(s.cd), ca_arg(s.ad));
    o += "  int3 cres; int ares;\n";
    gen_combine(o, false, s.cop, s.cbias, s.cscale, s.cclamp);
    gen_combine(o, true, s.aop, s.abias, s.ascale, s.aclamp);
    ap(o, "  r%d.rgb = cres;\n  r%d.a = ares;\n }\n", s.cout, s.aout);
}

std::string gen_fs(const PipelineKey &pk) {
    const FsKey &k = pk.fs;
    const VsKey &vk = pk.vs;
    std::string o;
    o += "struct FU { int4 reg[4]; int4 konst[4]; float4 ind_mtx[3][2]; int ref0, ref1, pad0, pad1; float lod_bias[8]; };\n";
    o += "struct FO { float4 c [[color(0)]]; };\n";
    if (k.early) o += "[[early_fragment_tests]] ";
    o += "fragment FO fs_main(VO in [[stage_in]], constant FU &u [[buffer(0)]]";
    for (int i = 0; i < 8; i++) if (k.tex_mask & (1 << i)) ap(o, ", texture2d<float> t%d [[texture(%d)]], sampler s%d [[sampler(%d)]]", i, i, i, i);
    if (k.logic) o += ", float4 dstc [[color(0)]]";
    o += ") {\n FO f;\n int4 r0 = u.reg[0], r1 = u.reg[1], r2 = u.reg[2], r3 = u.reg[3];\n";
    for (int i = 0; i < k.num_ind; i++) {
        const FsKey::I &n = k.ind[i];
        ap(o, " int4 ind%d = int4(0);\n", i);
        if (n.map != 0xff) {
            char uv[64];
            if (n.uv < vk.num_texgens) snprintf(uv, sizeof uv, "(in.u%d.xy / in.u%d.z)", n.uv, n.uv);
            else snprintf(uv, sizeof uv, "float2(0.0)");
            ap(o, " ind%d = int4(round(t%d.sample(s%d, %s / float2(%d.0, %d.0)) * 255.0));\n", i, n.map, n.map, uv, 1 << n.sx, 1 << n.sy);
        }
    }
    for (int i = 0; i < k.num_stages; i++) gen_stage(o, k, vk, i);
    if (k.num_stages) {
        const FsKey::S &l = k.s[k.num_stages - 1];
        ap(o, " int4 prev = int4(r%d.rgb, r%d.a) & 255;\n", l.cout, l.aout);
    } else {
        o += " int4 prev = r0 & 255;\n";
    }
    bool always = (k.cmp0 == 7 && k.cmp1 == 7 && (k.cmp_op == 0 || k.cmp_op == 1));
    if (!always) {
        std::string c0 = cmp_expr(k.cmp0, "u.ref0"), c1 = cmp_expr(k.cmp1, "u.ref1");
        o += " int a = prev.a;\n";
        static const char *ops[4] = {"(%s && %s)", "(%s || %s)", "(%s != %s)", "(%s == %s)"};
        char expr[256];
        snprintf(expr, sizeof expr, ops[k.cmp_op & 3], c0.c_str(), c1.c_str());
        ap(o, " if (!%s) discard_fragment();\n", expr);
    }
    if (k.logic) {
        static const char *lo[16] = {"int4(0)", "s & d", "s & ~d", "s", "~s & d", "d", "s ^ d", "s | d", "~(s | d)", "~(s ^ d)", "~d", "s | ~d", "~s", "~s | d", "~(s & d)", "int4(255)"};
        o += " {int4 d = int4(round(dstc * 255.0)); int4 s = prev;\n";
        ap(o, "  prev = (%s) & 255;}\n", lo[(k.logic - 1) & 15]);
    }
    o += " f.c = float4(prev) / 255.0;\n return f;\n}\n";
    return o;
}

}  // namespace

void build_pipeline_key(PipelineKey &k, u32 topology, u16 attrs) {
    memset(&k, 0, sizeof k);
    VsKey &v = k.vs;
    v.attrs = attrs;
    v.num_texgens = g.num_texgens > 8 ? 8 : g.num_texgens;
    v.num_chans = g.num_chans > 2 ? 2 : g.num_chans;
    v.point = topology == TOPO_POINT;
    for (int i = 0; i < v.num_texgens; i++) {
        v.tg[i].func = g.texgen[i].func;
        v.tg[i].src = g.texgen[i].src;
        v.tg[i].normalize = g.texgen[i].normalize;
        v.tg[i].has_post = g.texgen[i].post != 125;
    }
    if (v.num_chans >= 1) { v.ch[0] = g.chan[0]; v.ch[2] = g.chan[2]; }
    if (v.num_chans >= 2) { v.ch[1] = g.chan[1]; v.ch[3] = g.chan[3]; }

    FsKey &f = k.fs;
    f.num_stages = g.num_stages > 16 ? 16 : g.num_stages;
    f.num_ind = g.num_ind > 4 ? 4 : g.num_ind;
    f.cmp0 = g.cmp0; f.cmp1 = g.cmp1; f.cmp_op = g.cmp_op;
    f.early = g.z_before_tex && g.z_enable;
    f.logic = g.blend_type == 2 ? 1 + (g.logic_op & 15) : 0;
    u8 mask = 0;
    for (int i = 0; i < f.num_ind; i++) {
        f.ind[i].uv = g.ind[i].coord;
        f.ind[i].map = g.ind[i].map < 8 ? g.ind[i].map : 0xff;
        f.ind[i].sx = g.ind[i].scale_s;
        f.ind[i].sy = g.ind[i].scale_t;
        if (f.ind[i].map != 0xff) mask |= (u8)(1 << f.ind[i].map);
    }
    for (int i = 0; i < f.num_stages; i++) {
        const TevStage &t = g.tev[i];
        FsKey::S &s = f.s[i];
        s.ca = t.ca; s.cb = t.cb; s.cc = t.cc; s.cd = t.cd; s.cop = t.cop; s.cbias = t.cbias; s.cscale = t.cscale; s.cclamp = t.cclamp; s.cout = t.cout & 3;
        s.aa = t.aa; s.ab = t.ab; s.ac = t.ac; s.ad = t.ad; s.aop = t.aop; s.abias = t.abias; s.ascale = t.ascale; s.aclamp = t.aclamp; s.aout = t.aout & 3;
        s.ksel_c = t.ksel_c; s.ksel_a = t.ksel_a;
        bool tex_on = t.map != 0xff && t.map < 8;
        s.tex = tex_on ? t.map : 0xff;
        s.uv = t.coord < 8 ? t.coord : 0;
        if (tex_on) mask |= (u8)(1 << t.map);
        // Tabla 0x80408b38: los canales de alfa comparten bus con su color.
        switch (t.chan) {
            case 0: case 2: case 4: s.ras = 0; break;
            case 1: case 3: case 5: s.ras = 1; break;
            default: s.ras = 0xff;
        }
        for (int c = 0; c < 4; c++) {
            s.ras_swz[c] = "rgba"[g.swap[t.ras_swap & 3][c] & 3];
            s.tex_swz[c] = "rgba"[g.swap[t.tex_swap & 3][c] & 3];
        }
        s.ind = t.ind_stage;
        s.ind_bias = t.ind_bias;
        s.ind_mtx = t.ind_mtx;
        s.ind_wrap = t.ind_wrap_s == 6;
    }
    f.tex_mask = mask;

    RasterKey &r = k.r;
    r.blend = g.blend_type;
    r.src = g.blend_src;
    r.dst = g.blend_dst;
    r.op = g.logic_op;
    r.write_rgb = g.color_update;
    r.write_a = g.alpha_update;
    r.dst_has_alpha = g.pixel_fmt == 1;
}

bool g_tall_frame, g_tall_proj;
void build_vs_uniforms(VsUniforms &u) {
    memcpy(u.posmtx, g.xf + g.cur_pos * 4, 12 * sizeof(float));
    const float *n = g.nrm + (g.cur_pos < 30 ? g.cur_pos : 0) * 3;
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) u.nrmmtx[r * 4 + c] = n[r * 3 + c];
        u.nrmmtx[r * 4 + 3] = 0;
    }
    // Proyección reducida como XF: perspectiva con w=-z, ortográfica con w=1.
    memset(u.proj, 0, sizeof u.proj);
    if (g.proj_type == 0) {
        u.proj[0] = g.proj[0]; u.proj[2] = g.proj[1];
        u.proj[5] = g.proj[2]; u.proj[6] = g.proj[3];
        u.proj[10] = g.proj[4]; u.proj[11] = g.proj[5];
        u.proj[14] = -1.f;
        // Mac a dos pantallas (W3D_DUAL=1, prueba de la UI de 3DS): la cámara se abre en horizontal para 5:3 como en
        // gx_pica.cpp (kAspectFix), y el 2D ocupa toda la pantalla de arriba.
        static const bool dual = getenv("W3D_DUAL") != nullptr;
        if (dual) { u.proj[0] *= 0.8f; u.proj[2] *= 0.8f; }
    } else {
        u.proj[0] = g.proj[0]; u.proj[3] = g.proj[1];
        u.proj[5] = g.proj[2]; u.proj[7] = g.proj[3];
        u.proj[10] = g.proj[4]; u.proj[11] = g.proj[5];
        u.proj[15] = 1.f;
    }
    // Lienzo alto: y' = 0,5 y + 0,5 w lleva la pantalla original a la mitad de arriba; lo de debajo sigue en la otra.
    if (g_tall_proj) for (int c = 0; c < 4; c++) u.proj[4 + c] = 0.5f * u.proj[4 + c] + 0.5f * u.proj[12 + c];
    static const float id[12] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0};
    for (int i = 0; i < 8; i++) {
        if (i < g.num_texgens) {
            u32 m = g.texgen[i].mtx;
            memcpy(u.texmtx[i], m < 64 ? g.xf + m * 4 : id, sizeof id);
            u32 p = g.texgen[i].post;
            if (p == 125 || p < 64 || p > 125) memcpy(u.postmtx[i], id, sizeof id);
            else memcpy(u.postmtx[i], g.post + (p - 64) * 4, sizeof id);
        } else {
            memcpy(u.texmtx[i], id, sizeof id);
            memcpy(u.postmtx[i], id, sizeof id);
        }
    }
    for (int c = 0; c < 2; c++) {
        for (int j = 0; j < 4; j++) {
            u.amb[c][j] = g.amb[c][j] / 255.f;
            u.mat[c][j] = g.mat[c][j] / 255.f;
        }
    }
    for (int i = 0; i < 8; i++) {
        const LightObj &l = g.lights[i];
        for (int j = 0; j < 4; j++) u.light[i].color[j] = l.color[j] / 255.f;
        u.light[i].cosatt[0] = l.a0; u.light[i].cosatt[1] = l.a1; u.light[i].cosatt[2] = l.a2; u.light[i].cosatt[3] = 0;
        u.light[i].distatt[0] = l.k0; u.light[i].distatt[1] = l.k1; u.light[i].distatt[2] = l.k2; u.light[i].distatt[3] = 0;
        u.light[i].pos[0] = l.px; u.light[i].pos[1] = l.py; u.light[i].pos[2] = l.pz; u.light[i].pos[3] = 1;
        u.light[i].dir[0] = l.nx; u.light[i].dir[1] = l.ny; u.light[i].dir[2] = l.nz; u.light[i].dir[3] = 0;
    }
}

void build_fs_uniforms(FsUniforms &u) {
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            u.reg[r][c] = g.reg[r][c];
            u.konst[r][c] = g.konst[r][c];
        }
    }
    for (int m = 0; m < 3; m++) {
        float sc = ldexpf(1.0f, g.ind_exp[m]);
        for (int r = 0; r < 2; r++) {
            for (int c = 0; c < 3; c++) u.ind_mtx[m][r][c] = g.ind_mtx[m][r * 3 + c];
            u.ind_mtx[m][r][3] = sc;
        }
    }
    u.ref0 = g.ref0;
    u.ref1 = g.ref1;
    u.pad0 = u.pad1 = 0;
    for (int i = 0; i < 8; i++) u.lod_bias[i] = g.map[i].bias32 / 32.f;
}

const char *shader_source(const PipelineKey &k) {
    static std::string s;
    s = gen_vs(k.vs) + gen_fs(k);
    return s.c_str();
}

}  // namespace gx
}  // namespace w3d
