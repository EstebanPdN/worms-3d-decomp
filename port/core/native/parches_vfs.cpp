// Archivos que los VFS de Mac y 3DS sirven parcheados (formas en parches_vfs.h).
//   Forma 1, entero en memoria: Language/NGC/<idioma>.xom (textos_es.cpp: frases de ahogo de la v25, teclado QWERTY y
//     nombre del francotirador).
//   Forma 2, por tramos: Bundles/bundle04.xom con la animación de ahogo de Ultimate Mayhem (v26, anim_ahogo_um.cpp) y
//     las tres del francotirador. Por tramos solo queda en memoria lo nuevo (los cuerpos de los clips van en el .inc).
//   Francotirador de UM (francotirador.cpp): forma 1 con un número por archivo, porque w3d_parche_aplica con
//     in == nullptr no recibe la ruta: 4 WeapTwk.xom, 5 Scripts/stdvs.lua. El 3 no se usa (en la build separada era
//     English.xom, que aquí ya va con los demás idiomas en el 1).
//   6, por tramos: Bundles/Bundle00.xom con el cielo del título en esfera, con dos pantallas (titulo_cielo.cpp).
#include "parches_vfs.h"

extern "C" int w3d_textos_quiere(const char *path);
extern "C" int w3d_textos_parchea(const unsigned char *in, unsigned size, const unsigned char **out, unsigned *out_size);
extern "C" int w3d_anim_um_quiere(const char *path);
extern "C" int w3d_anim_um_tramos(W3dLeer leer, void *ctx, unsigned size, const W3dTramo **tramos, int *n);
extern "C" int w3d_franco_weaptwk_quiere(const char *path);
extern "C" int w3d_franco_weaptwk_parchea(const unsigned char *in, unsigned size, const unsigned char **out, unsigned *out_size);
extern "C" int w3d_franco_lua_quiere(const char *path);
extern "C" int w3d_franco_lua_parchea(const unsigned char *in, unsigned size, const unsigned char **out, unsigned *out_size);
extern "C" int w3d_cielo_quiere(const char *path);
extern "C" int w3d_cielo_tramos(W3dLeer leer, void *ctx, unsigned size, const W3dTramo **tramos, int *n);

extern "C" int w3d_parche_quiere(const char *path) {
    if (w3d_textos_quiere(path)) return 1;
    if (w3d_anim_um_quiere(path)) return 2;
    if (w3d_franco_weaptwk_quiere(path)) return 4;
    if (w3d_franco_lua_quiere(path)) return 5;
    if (w3d_cielo_quiere(path)) return 6;
    return 0;
}

extern "C" int w3d_parche_aplica(int k, const unsigned char *in, unsigned size, const unsigned char **out, unsigned *out_size) {
    switch (k) {
    case 1: return w3d_textos_parchea(in, size, out, out_size);
    case 4: return w3d_franco_weaptwk_parchea(in, size, out, out_size);
    case 5: return w3d_franco_lua_parchea(in, size, out, out_size);
    }
    return 0;
}

extern "C" int w3d_parche_tramos(int k, W3dLeer leer, void *ctx, unsigned size, const W3dTramo **tramos, int *n) {
    return k == 2 ? w3d_anim_um_tramos(leer, ctx, size, tramos, n) : k == 6 ? w3d_cielo_tramos(leer, ctx, size, tramos, n) : 0;
}

extern "C" int w3d_parche_es_tramos(int k) { return k == 2 || k == 6; }
