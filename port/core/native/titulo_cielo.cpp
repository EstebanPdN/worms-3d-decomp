// Parche 6, por tramos (parches_vfs.cpp): Bundles/Bundle00.xom con el cielo del título en esfera.
// El dueño, 2026-11-07: «que el fondo de arriba se expanda para la de abajo también… extiéndelo más». Con dos pantallas
// la escena del título sigue en la de abajo, y la cúpula del cielo (SkyBox, la nebulosa skynailed2_FrontSky_02) acababa en
// el horizonte: por debajo quedaba negro. tools/build3ds/ui/cielo_esfera.py le añade su reflejo, con la misma textura, y
// deja aquí los tramos: el bundle original con cuatro contenedores de la cúpula y dos campos de su tira cambiados.
// Solo con dos pantallas (con una, la vista del título no llega por debajo del horizonte), y solo si el bundle es el
// esperado: mismo tamaño y los bytes originales de cada tramo cambiado.
#include <string.h>
#include "parches_vfs.h"
#ifdef W3D_PUBLIC
extern "C" int w3d_cielo_quiere(const char *) { return 0; }
extern "C" int w3d_cielo_tramos(W3dLeer, void *, unsigned, const W3dTramo **, int *) { return 0; }
#else
#include "titulo_cielo.inc"

extern "C" int w3d_fe_native_layout(void);
extern "C" void w3d_dbg(const char *, ...);

static bool ends_with_ci(const char *s, const char *tail) {
    const size_t n = strlen(s), m = strlen(tail);
    if (n < m) return false;
    for (size_t i = 0; i < m; i++) {
        char c = s[n - m + i];
        if (c >= 'A' && c <= 'Z') c += 32;
        if (c == '\\') c = '/';
        if (c != tail[i]) return false;
    }
    return n == m || s[n - m - 1] == '/' || s[n - m - 1] == '\\';
}

extern "C" int w3d_cielo_quiere(const char *path) {
    return path && ends_with_ci(path, "bundles/bundle00.xom") && w3d_fe_native_layout();
}

extern "C" int w3d_cielo_tramos(W3dLeer leer, void *ctx, unsigned size, const W3dTramo **tramos, int *n) {
    static int said;
    if (size != W3D_CIELO_BUNDLE_BYTES) {
        if (!said++) w3d_dbg("[cielo] Bundle00.xom de %u bytes, no el esperado: cielo del título sin cambiar\n", size);
        return 0;
    }
    for (const CieloCheck &c : kCieloChecks) {
        unsigned char b[16];
        if (!leer(ctx, c.desde, b, c.n) || memcmp(b, c.bytes, c.n)) {
            if (!said++) w3d_dbg("[cielo] Bundle00.xom no es el esperado (%u): cielo del título sin cambiar\n", c.desde);
            return 0;
        }
    }
    if (!said++) w3d_dbg("[cielo] cielo del título en esfera (Bundle00.xom por tramos)\n");
    *tramos = kCieloTramos;
    *n = (int)(sizeof kCieloTramos / sizeof kCieloTramos[0]);
    return 1;
}

#endif
