#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k7b_a_8017b64c.c"
struct K7bEntry;
struct K7bEntryVector { Ptr32<Ptr32<struct K7bEntry>> begin; Ptr32<Ptr32<struct K7bEntry>> end; };
struct K7bRefresher;
struct K7bRefresherVtable { Ptr32<void> slots[37]; Ptr32<int (Ptr32<struct K7bRefresher>, Ptr32<void>)> refresh; };
struct K7bRefresher { Ptr32<struct K7bRefresherVtable> vtable; char pad04[100]; struct K7bEntryVector entries; char pad70[52]; int dirty; };
extern void fn_8017a07c(Ptr32<struct K7bRefresher> self, unsigned index);
static inline unsigned k7b_entry_count(Ptr32<struct K7bEntryVector> v) { return v->end - v->begin; }
/* El segundo argumento (r4 en PowerPC) pasa sin tocar a refresh, que lo usa: llamado por la ranura +168
   (set_transform, d25g_hands_transform_800697ac) es la matriz, y refresh es set_inner_matrix 0x8017b0b8.
   Sin pasarlo, en 3DS refresh recibía en r1 su propia dirección y copiaba su código como matriz: manos y
   huesos de primera persona con valores de 1e25 (R para apuntar). En Mac funcionaba porque x1 seguía intacto. */
int w3d_k7b_refresher_update_8017b64c(Ptr32<struct K7bRefresher> self, Ptr32<void> arg)
{
    unsigned i;
    int result;
    self->dirty = 0;
    result = self->vtable->refresh(self, arg);
    for (i = 0; i < k7b_entry_count(&self->entries); i++)
        fn_8017a07c(self, i);
    return result;
}

}
