// Ropa de prueba (port, no está en el original): gorros de Worms Ultimate Mayhem convertidos a un solo bundle de
// Worms 3D por mods/gorra/tools/hacer_ropa.py.
// - v29: los 76 sombreros de UM en Mac y en 3DS (hat_ropa76_lista.inc; mods/gorra/tools/ropa_um.py). Los 11 primeros
//   son los de la v19 en el mismo orden, así W3D_GORRA=<k> sigue valiendo. Caben en la tabla de recursos porque
//   core/native/tabla_recursos.cpp la lleva de 1920 a 4096 huecos.
//
// - Mac: el archivo Bundles/Bundle89.xom (2,4 MB) va dentro del ejecutable (hat_ropa76_bundle.inc); el VFS lo sirve
//   si ningún paquete lo tiene (w3d_builtin_file).
// - 3DS: no va en el ejecutable, que ocupa el mismo montón que el juego (unos 83 MB, casi todo reservado al arrancar).
//   build3ds.sh lo mete en el paquete del romfs (romfs:/mapas-um.worms, tools/build3ds/ui/paquete_romfs.py) y
//   vfs_3ds.cpp lo lee de ahí a trozos, sin copiarlo al montón. Si falta, no se da de alta ningún gorro.
// - w3d_hat_register (al final de cx12a_register_catalogs_80127544) añade un recurso por gorro ("Hat.Militar",
//   "Hat.Camuflaje"...) con la misma forma que las filas de la tabla 0x803f5e60 (malla, tipo 4, flags 0x0028 como
//   BaseballCap) y el bundle 0x59, igual que el bucle del original hace con los bundles 0x00-0x58.
// - w3d_hat_mode: 0 sin gorro, k el gorro k-1 de kHats. Lo cambian Developer > Outfit (platform/ui/ui_pages.cpp), el
//   menú Ropa de la consola de diag.cpp o W3D_GORRA=<k> (1 = militar); un equipo puede llevar el suyo
//   (ropa_equipos.cpp). El gorro lo ponen y quitan d28d_worm_attach_weapon_mesh_801394ac.cpp y el manejador de mensajes
//   del worm (d29d).
#include "w3d_ptr.h"
#include <stdlib.h>
#include <string.h>

#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
#define VCALL(p,T,o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p)+(o))))

extern "C" { volatile int w3d_hat_mode; }

#if defined(__3DS__) || defined(W3D_PUBLIC)
#include "../../platform/platform.h"
extern "C" void w3d_dbg(const char *, ...);
#else
static const unsigned char kBundle[] = {
#include "hat_ropa76_bundle.inc"
};
#endif

extern "C" int w3d_mapa_um_file(const char *path, const unsigned char **data, unsigned *size);   // mapa_um.cpp (v26)
extern "C" int w3d_builtin_file(const char *path, const unsigned char **data, unsigned *size) {
    if (w3d_mapa_um_file(path, data, size)) return 1;
#if defined(__3DS__) || defined(W3D_PUBLIC)
    return 0;   // Bundle89.xom viene del paquete del romfs: vfs_3ds.cpp lo encuentra antes de llegar aquí.
#else
    const char *base = strrchr(path, '/'), *b2 = strrchr(path, '\\');
    if (b2 > base) base = b2;
    base = base ? base + 1 : path;
    static const char want[] = "bundle89.xom";
    for (int i = 0;; i++) {
        char c = base[i];
        if (c >= 'A' && c <= 'Z') c += 32;
        if (c != want[i]) return 0;
        if (!c) break;
    }
    *data = kBundle; *size = sizeof kBundle;
    return 1;
#endif
}

// Fila de recurso: nombre, bytes {bundle, tipo, 0, 0}, archivo, dos u16 (flags) y dos u16 más (0).
struct ResourceRow { Ptr32<const char> name; unsigned char bundle, type, pad[2]; Ptr32<const char> file; unsigned short flags, flags_lo, extra[2]; };
static_assert(sizeof(ResourceRow) == 20, "fila de 20 bytes como en 0x803f5e60");
// Mismo orden que los descriptores del bundle (mods/gorra/tools/hacer_ropa.py).
static const struct { const char *resource, *file, *label, *label_en; } kHats[] = {
#include "hat_ropa76_lista.inc"
};
static const int kHatCount = sizeof kHats / sizeof kHats[0];
static ResourceRow g_rows[kHatCount];
// Gorros dados de alta: todos, salvo en 3DS si el romfs no trae el bundle (w3d_hat_register).
static int g_hat_count = kHatCount;

extern "C" int w3d_hat_count(void) { return g_hat_count; }
extern "C" const char *w3d_hat_label(int k) { return k >= 1 && k <= g_hat_count ? kHats[k - 1].label : ""; }
// Nombre en inglés (el de UM) para la UI de dos pantallas en los idiomas que no son el español.
extern "C" const char *w3d_hat_label_en(int k) { return k >= 1 && k <= g_hat_count ? kHats[k - 1].label_en : ""; }
extern "C" const char *w3d_hat_resource(int k) { return k >= 1 && k <= g_hat_count ? kHats[k - 1].resource : nullptr; }

extern "C" Ptr32<void> A804b17ec;  // mismo global que service_804b17ec de cx12a
extern "C" void w3d_hat_register(void) {
#if defined(__3DS__) || defined(W3D_PUBLIC)
    // Sin el bundle en el romfs (build3ds.sh) no hay gorros: si no, la partida caería al ponerse uno.
    if (w3d::plat::File *f = w3d::plat::file_open("Bundles/Bundle89.xom")) w3d::plat::file_close(f);
    else { g_hat_count = 0; w3d_hat_mode = 0; w3d_dbg("[ropa] falta Bundles/Bundle89.xom: sin gorros\n"); return; }
#endif
    // debug.ini: W3D_GORRA=<k> arranca con el gorro k puesto (1 = militar), para las pruebas en Azahar.
    if (const char *e = getenv("W3D_GORRA")) { int k = atoi(e); w3d_hat_mode = k >= 1 && k <= kHatCount ? k : 1; }
    for (int i = 0; i < kHatCount; i++) {
        ResourceRow &r = g_rows[i];
        r.name = kHats[i].resource; r.bundle = 0x59; r.type = 4; r.file = kHats[i].file; r.flags = 0x0028;
    }
    Ptr32<void> svc = FIELD(A804b17ec, void *, 0x74);
    VCALL(svc, void (*)(void *, void *, unsigned), 0x28)(svc, g_rows, kHatCount);
    unsigned char index = 0x59;
    svc = FIELD(A804b17ec, void *, 0x74);
    VCALL(svc, void (*)(void *, unsigned char *, int), 0x48)(svc, &index, 0);
    svc = FIELD(A804b17ec, void *, 0x74);
    VCALL(svc, void (*)(void *, unsigned char *, int), 0x54)(svc, &index, 1);
}
