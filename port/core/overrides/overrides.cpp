// Sustituciones por dirección de funciones del juego; cada una dice por qué.
#include "w3d_ptr.h"
#include <string.h>
using namespace w3d;
typedef w3d_u32 GA;

namespace {
// Stream del juego: la tabla virtual está en +0; +20 transferir, +28 saltar.
typedef int (*Transfer)(GA, GA, int, int);
typedef int (*Skip)(GA, int, int, int);
int read_u64s(GA self, GA buffer, unsigned count) {
    GA stream = *(w3d_u32 *)((char *)g2h(self) + 20);
    w3d_u32 *vt = (w3d_u32 *)g2h(*(w3d_u32 *)g2h(stream));
    if (!buffer) return ((Skip)g2h(vt[7]))(stream, (int)(count << 3), 1, 0);
    return ((Transfer)g2h(vt[5]))(stream, buffer, (int)(count << 3), 0);
}
}

static inline w3d_u32 *vtable_of(GA object) { return (w3d_u32 *)g2h(*(w3d_u32 *)g2h(object)); }

extern "C" {
// pushstr de lobject.c (Lua 5.0): faltaba y hacía abortar cualquier error de ejecución de un script al componer su mensaje.
GA A802d5e30(GA L, GA s, unsigned n);
void A802cff34(GA L, int n);
void A802d24ec(GA L, GA str) {
    w3d_u32 *top = (w3d_u32 *)g2h(*(w3d_u32 *)g2h(L + 8));
    top[0] = 4;
    top[1] = A802d5e30(L, str, (unsigned)strlen((const char *)g2h(str)));
    if ((int)(*(w3d_u32 *)g2h(L + 0x18) - *(w3d_u32 *)g2h(L + 8)) < 9) A802cff34(L, 1);
    *(w3d_u32 *)g2h(L + 8) += 8;
}
// Entrada del vector de claves del material. La llamada puede reasignar el vector: hay que leerlo después, como hacía GCC.
int A801720fc(GA self, int mode);
GA A801720c0(GA self, int mode) {
    int k = A801720fc(self, mode);
    GA vec = *(w3d_u32 *)g2h(self + 0x50);
    return *(w3d_u32 *)g2h(vec) + k * 16;
}
// Convierte una imagen TGA en superficie. Sustituye a la traducción mecánica: leía ancho y alto con lhz +2/+6, que en
// little-endian es la mitad alta de la palabra y vale 0, y la superficie salía de tamaño 0 con el heap desbordado después.
GA A801da28c(GA stream, GA name, int flip);
int A801b0a9c(GA pixels, int width, int height);
int A801b0b10(GA pixels, int width, int height);
void A801afac0(GA surface);
GA A8020b680(GA key);
GA A801ef048(GA ref, unsigned count, unsigned element, unsigned flags);
void A801dad70(GA image);
extern unsigned char w3d_dol_image[];
static GA dol_addr(GA a) { return h2g(w3d_dol_image) + (a - 0x8035f3e0u); }
struct TgaImage { int width, height, components, format, cmap_entries, cmap_format; w3d_u32 cmap, pixels; int depth; };
struct ArrayBlob { char u0[4]; unsigned short references; char u6[18]; unsigned count; unsigned short locks; char u1e[2]; unsigned char data[1]; };
// Bloqueo en línea del array por referencia: mismo fast path que el original y, si no, 0x801ef048.
static unsigned char *lock_array(GA ref, unsigned count, unsigned element, unsigned flags) {
    ArrayBlob *blob = (ArrayBlob *)g2h(*(w3d_u32 *)g2h(ref));
    if (blob->references == 1 && blob->count == count) { blob->locks++; return blob->data; }
    return (unsigned char *)g2h(A801ef048(ref, count, element, flags));
}
int A801d4858(GA self, GA stream, GA surface) {
    (void)self;
    char *s = (char *)g2h(surface);
    TgaImage *img = (TgaImage *)g2h(A801da28c(stream, dol_addr(0x803af114), 0));
    int kind, comps, alpha = 0;
    switch (img->format) {
    case 0x80e1: kind = 1; alpha = A801b0a9c(img->pixels, img->width, img->height); if (!alpha) kind = 0; comps = 4; break;
    case 0x80e0: kind = 0; comps = 3; break;
    case 0x1909: kind = 6; comps = 1; break;
    case 0x1900: comps = 1; kind = A801b0b10(img->pixels, img->width, img->height); break;
    default: return (int)0x80004005;
    }
    *(int *)(s + 0x18) = kind;
    *(unsigned short *)(s + 0x2e) = (unsigned short)img->width;
    *(unsigned short *)(s + 0x2a) = 1;
    *(unsigned short *)(s + 0x2c) = (unsigned short)img->height;
    *(unsigned short *)(s + 0x28) = (unsigned short)(alpha << 1);
    A801afac0(surface);
    ArrayBlob *blob = (ArrayBlob *)g2h(*(w3d_u32 *)(s + 0x30));
    unsigned char *dst = lock_array(surface + 0x30, blob->count, 1, 4);
    unsigned pitch = *(w3d_u32 *)((char *)g2h(*(w3d_u32 *)(s + 0x20)) + 0x20);
    const unsigned char *src = (const unsigned char *)g2h(img->pixels);
    int w = img->width, stride = w * comps;
    for (int y = img->height; y > 0; y--) {
        const unsigned char *in = src; unsigned char *out = dst;
        bool bgr = img->format == 0x80e0;
        switch (kind) {
        case 1:
            for (int x = 0; x < w; x++, in += 4, out += 4) { out[0] = in[bgr ? 0 : 2]; out[1] = in[1]; out[2] = in[bgr ? 2 : 0]; out[3] = in[3]; }
            break;
        case 0:
            for (int x = 0; x < w; x++, in += 3, out += 3) { out[0] = in[bgr ? 2 : 0]; out[1] = in[1]; out[2] = in[bgr ? 0 : 2]; }
            break;
        case 6: case 7:
            __builtin_memcpy(out, in, w);
            break;
        case 8:
            for (int x = 0; x < w >> 1; x++, in += 2) out[x] = (unsigned char)((in[0] << 4 & 0xf0) | (in[1] & 0xf));
            break;
        default: return (int)0x80004005;
        }
        dst += pitch; src += stride;
    }
    if (kind == 7 || kind == 8) {
        GA pal = A8020b680(dol_addr(0x80415ce0));
        GA old = *(w3d_u32 *)(s + 0x14);
        *(w3d_u32 *)(s + 0x14) = pal;
        if (pal) ((void (*)(GA))g2h(vtable_of(pal)[3]))(pal);
        if (old) ((void (*)(GA))g2h(vtable_of(old)[4]))(old);
        char *p = (char *)g2h(pal);
        int bits = kind == 8 ? 4 : 8;
        p[0x21] = (char)bits;
        *(int *)(p + 0x14) = 1;
        unsigned n = 1u << bits;
        unsigned char *out = lock_array(pal + 0x1c, n * 4, 1, 1);
        const unsigned char *in = (const unsigned char *)g2h(img->cmap);
        bool rgba = img->depth == 32;
        for (unsigned i = 0; i < n; i++, out += 4, in += rgba ? 4 : 3) { out[0] = in[2]; out[1] = in[1]; out[2] = in[0]; out[3] = rgba ? in[3] : 0xff; }
    }
    A801dad70(h2g(img));
    return 0;
}
// Lector de un flotante del archivo. Como los demás lectores de XOM, en PPC invierte los bytes: el disco es little-endian.
int A80201630(GA self, GA out) {
    GA stream = *(w3d_u32 *)((char *)g2h(self) + 20);
    return ((Transfer)g2h(vtable_of(stream)[5]))(stream, out, 4, 0);
}
// Escritura de palabras: PPC las invierte, escribe y las deja como estaban.
int A802047e0(GA self, GA buffer, unsigned bytes);
void A8035bd50(GA self, GA buffer, unsigned count) { A802047e0(self, buffer, count * 4); }
// Destructor de la cadena que se pasa por valor en f7a_scheme_message: el sufijo de la clase es la dirección de su constructor.
void A8020c5c4(GA text);
void A80341588(GA text);
void w3d_f7a_text_destroy(void *text) { A8020c5c4(h2g(text)); A80341588(h2g(text)); }
// Número de bundle de una entrada de recurso. En PPC es el primer byte de la palabra en +0x18; esa palabra se guarda
// como entero del anfitrión, así que el byte está en +0x1b.
GA A8019048c(GA self) { return self + 0x1b; }
// Búsqueda por nombre del servicio: pide el destino al objeto interno (+20) y le pasa el nombre. La fuente admitida
// no declara el nombre porque en PPC sigue vivo en r4; en arm64 hay que pasarlo.
GA A80211f40(GA self, GA name) {
    GA inner = self + 20;
    GA target = ((GA (*)(GA, GA))g2h(vtable_of(inner)[6]))(inner, name);
    return ((GA (*)(GA, GA))g2h(vtable_of(target)[22]))(target, name);
}
// Las tres leen enteros de 64 bits de un archivo little-endian. El original invierte bytes y palabras;
// en un anfitrión little-endian el valor ya está bien.
int A80201cd4(GA self, GA buffer, unsigned count) { return read_u64s(self, buffer, count); }
int A80201dbc(GA self, GA buffer, unsigned count) { return read_u64s(self, buffer, count); }
int A80201f5c(GA self, GA buffer, unsigned count) { return read_u64s(self, buffer, count); }
}

// setjmp y longjmp de newlib, usados por Lua para sus errores. El búfer del juego mide 256 B y el de arm64 192. Solo se
// pasa la dirección a 64 bit y se salta a la versión del sistema: un salto final conserva el LR y el SP del llamador.
#if defined(__aarch64__)
__asm__(
    ".text\n.p2align 2\n"
    ".globl _A802efe74\n_A802efe74:\n"
    "  mov w0, w0\n  orr x0, x0, #0x100000000\n  add x0, x0, #15\n  and x0, x0, #-16\n  b __setjmp\n"
    ".globl _A802eff30\n_A802eff30:\n"
    "  mov w0, w0\n  orr x0, x0, #0x100000000\n  add x0, x0, #15\n  and x0, x0, #-16\n  b __longjmp\n");
#else
__asm__(".text\n.p2align 2\n.globl A802efe74\nA802efe74:\n  b setjmp\n.globl A802eff30\nA802eff30:\n  b longjmp\n");
#endif
