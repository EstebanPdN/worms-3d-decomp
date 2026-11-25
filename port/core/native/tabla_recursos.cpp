// Tabla de recursos del port (v29): 4096 huecos en vez de 1920.
//
// En el original, el gestor de recursos (SceneBins_804127a0, un solo objeto, lbl_804ab5fc) guarda sus recursos en
// una tabla hash de 1920 huecos con sondeo lineal que vive dentro del propio objeto (+24 .. +7704); detrás van la
// caché de nombres (+7704, 256 entradas de 8 bytes) y el contador (+9752). Con los 11 mapas de Ultimate Mayhem la
// tabla quedaba en 1872 de 1920 (docs/mapas-ultimate-mayhem.md) y los 76 sombreros de UM no cabían.
//
// Agrandar el objeto movería la caché y el contador para todas las funciones convertidas que los leen por su
// desplazamiento. Así que el objeto se queda igual (sus 1920 huecos sin uso, a cero) y las funciones que tocan los
// huecos usan esta tabla:
//   k1d_a_8017e1c4 (hash módulo la capacidad), d24j_find_named_item_8017e22c, d30j_insert_pool_item_8017c464,
//   d24j_apply_named_item_8017dd68, s20 lookup_slot_8017ded8 y clear_tables_8017ccdc, cc17b_pool_next_8017d6f4,
//   cc41a_refresh_group_8017d294, d29j_shut_down_pools_8017c26c, d30j_destroy_pool_manager_8017bf40,
//   d22d_count_categories_8017d60c, el constructor d41x_scene_bins_ctor_8017b9c8 y w3d_constant_8017ea1c.
// Los índices de hueco que guardan los recursos son de 16 bits, así que 4096 cabe.
#include "w3d_ptr.h"

namespace {
const unsigned kCap = 4096;
Ptr32<void> g_slots[kCap];
}

extern "C" Ptr32<void> *w3d_restab_slots(void) { return g_slots; }
extern "C" unsigned w3d_restab_cap(void) { return kCap; }
// Huecos ocupados (para el registro de pruebas).
extern "C" unsigned w3d_restab_used(void) {
    unsigned n = 0;
    for (unsigned i = 0; i < kCap; i++) n += g_slots[i] ? 1 : 0;
    return n;
}
