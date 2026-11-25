// Cuatro frases de ahogo del comentarista en español, cambiadas (v25, pedido del dueño el 2026-11-05).
// Lista completa de frases en docs/textos-comentarios.md.
//
// Al abrir Language/NGC/Spanish.xom, los VFS de 3DS y de Mac (platform/3ds/vfs_3ds.cpp, platform/common/vfs.cpp) leen
// el archivo entero y lo sirven parcheado desde memoria. El archivo es un XOM: cabecera, tabla de tipos de 64 B por
// tipo, "GUID" y "SCHM" (16 B cada uno), y la tabla "STRS": u32 cuenta, u32 bytes de texto, un u32 de desplazamiento
// por texto y los textos con su cero. Los objetos van detrás, sin direcciones absolutas.
// El parche añade los textos nuevos al final de STRS y cambia solo el desplazamiento de las cuatro frases. Si una frase
// no está tal cual (otro archivo, o un mod que ya la cambió), esa se deja como esté.
// W3D_TEXTOS_ORIGINALES=1 en debug.ini lo apaga.
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

extern "C" void w3d_dbg(const char *, ...);

namespace {
struct Cambio { const char *clave, *antes, *ahora; };
const Cambio kCambios[] = {
    {"Comment.WaterDeath.2", "Se ha roto el hilo de la vida de %s", "\xc2\xa1%s ya no pasar\xc3\xa1 sed!"},
    {"Comment.WaterDeath.8", "%s tomo un salto", "%s se ech\xc3\xb3 un clavado"},
    {"Comment.WaterDeath.10", "%s nad\xc3\xb3 como un ladrillo.", "%s nada igualito a un ladrillo."},
    {"Comment.WaterDeath.11", "V\xc3\xad" "a de agua fatal para %s", "%s descansa en pez"},
    // Teclado en pantalla en QWERTY (dueño, 2026-11-06): las letras del teclado del juego (30 teclas, filas de 10) en
    // orden QWERTY, en todos los idiomas. Mismos caracteres, otro orden.
    {"FE teclado minúsculas", "abcdefghijklmnopqrstuvwxyz,.?!", "qwertyuiopasdfghjkl,zxcvbnm.?!"},
    {"FE teclado mayúsculas", "ABCDEFGHIJKLMNOPQRSTUVWXYZ,.?!", "QWERTYUIOPASDFGHJKL,ZXCVBNM.?!"},
    // Francotirador de UM (francotirador.cpp): el arma 28 (kWeaponMagicBullet) se llama Text.kWeaponMagicBullet en el
    // panel, y esa clave no existe. Se reutiliza la de Text.kWeaponSheepStrike, que nada usa (el Ataque de oveja no tiene
    // contenedor en WeapTwk). En los seis idiomas su clave y su valor solo los usa ese objeto, así que basta cambiar sus
    // dos textos en STRS. El valor de cada idioma solo está en su archivo; el nuevo es el nombre de UM.
    {"(clave del francotirador)", "Text.kWeaponSheepStrike", "Text.kWeaponMagicBullet"},
    {"Text.kWeaponMagicBullet", "Ataque de oveja", "Fusil francotirador"},
    {"Text.kWeaponMagicBullet", "Sheep Strike", "Sniper Rifle"},   // English y American
    {"Text.kWeaponMagicBullet", "Pluie de mouton", "Fusil de sniper"},
    {"Text.kWeaponMagicBullet", "Schafschuss", "Scharfsch\xc3\xbctzengewehr"},
    {"Text.kWeaponMagicBullet", "Pioggia di pecore", "Fucile cecchino"},
};
const int kN = sizeof kCambios / sizeof kCambios[0];

uint32_t rd(const unsigned char *p) { return (uint32_t)p[0] | (uint32_t)p[1] << 8 | (uint32_t)p[2] << 16 | (uint32_t)p[3] << 24; }
void wr(unsigned char *p, uint32_t v) { p[0] = (unsigned char)v; p[1] = (unsigned char)(v >> 8); p[2] = (unsigned char)(v >> 16); p[3] = (unsigned char)(v >> 24); }
bool ends_with(const char *s, const char *suffix) {
    size_t a = strlen(s), b = strlen(suffix);
    if (a < b) return false;
    s += a - b;
    for (size_t i = 0; i < b; i++) {
        char c = s[i];
        if (c >= 'A' && c <= 'Z') c += 32;
        if (c == '\\') c = '/';
        if (c != suffix[i]) return false;
    }
    return a == b || s[-1] == '/' || s[-1] == '\\';
}
// Un archivo parcheado por idioma (se reconocen por su tamaño original).
struct Hecho { unsigned in_size; const unsigned char *data; unsigned size; };
Hecho g_hechos[8]; int g_n;
}

extern "C" {
int w3d_textos_quiere(const char *path) {
    if (getenv("W3D_TEXTOS_ORIGINALES")) return 0;
    if (!path) return 0;
    static const char *const k[] = {"language/ngc/spanish.xom", "language/ngc/english.xom", "language/ngc/american.xom",
        "language/ngc/french.xom", "language/ngc/german.xom", "language/ngc/italian.xom"};
    for (const char *e : k) if (ends_with(path, e)) return 1;
    return 0;
}
// Parchea el archivo. Devuelve 1 con el archivo nuevo (memoria propia, que se guarda para las siguientes aperturas) si
// cambió alguna frase; 0 si no hay nada que cambiar o el archivo no es el esperado.
int w3d_textos_parchea(const unsigned char *in, unsigned size, const unsigned char **out, unsigned *out_size) {
    for (int i = 0; i < g_n; i++) if (g_hechos[i].in_size == size) { *out = g_hechos[i].data; *out_size = g_hechos[i].size; return g_hechos[i].data ? 1 : 0; }
    if (!in || size < 64 || memcmp(in, "MOIK", 4)) return 0;
    uint64_t so = 64 + 64ull * rd(in + 24) + 32;
    if (so + 12 > size || memcmp(in + so, "STRS", 4)) return 0;
    uint32_t n = rd(in + so + 4), len = rd(in + so + 8);
    uint64_t offs = so + 12, data = offs + 4ull * n, end = data + len;
    if (end > size) return 0;
    int idx[kN];
    size_t extra = 0;
    for (int c = 0; c < kN; c++) {
        idx[c] = -1;
        size_t la = strlen(kCambios[c].antes) + 1;
        for (uint32_t i = 0; i < n; i++) {
            uint32_t o = rd(in + offs + 4ull * i);
            if ((uint64_t)o + la > len || memcmp(in + data + o, kCambios[c].antes, la)) continue;
            idx[c] = (int)i;
            extra += strlen(kCambios[c].ahora) + 1;
            break;
        }
        (void)0;   // las frases de ahogo solo están en Spanish.xom
    }
    if (!extra) { if (g_n < 8) g_hechos[g_n++] = {size, nullptr, 0}; return 0; }
    unsigned total = size + (unsigned)extra;
    unsigned char *buf = (unsigned char *)malloc(total);
    if (!buf) return 0;
    memcpy(buf, in, (size_t)end);
    uint64_t pos = end;
    for (int c = 0; c < kN; c++) {
        if (idx[c] < 0) continue;
        size_t l = strlen(kCambios[c].ahora) + 1;
        wr(buf + offs + 4ull * idx[c], (uint32_t)(pos - data));
        memcpy(buf + pos, kCambios[c].ahora, l);
        pos += l;
    }
    memcpy(buf + pos, in + end, size - (size_t)end);
    wr(buf + so + 8, len + (uint32_t)extra);
    if (g_n < 8) g_hechos[g_n++] = {size, buf, total};
    w3d_dbg("[textos] idioma parcheado: %u bytes de texto nuevos (teclado QWERTY, frases de ahogo y francotirador)\n", (unsigned)extra);
    *out = buf;
    *out_size = total;
    return 1;
}
}
