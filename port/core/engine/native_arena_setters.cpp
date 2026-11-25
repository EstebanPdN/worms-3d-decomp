#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "native_arena_setters.c"
/* Complete reconstructed native functions. Analyst-assigned names/types.
 * Original entries: high 0x802fa678, low 0x802fa680 (8 bytes each).
 * Only external declarations: original state ownership remains unproven. */
extern Ptr32<void> w3d_heap_arena_low_value;
extern Ptr32<void> w3d_heap_arena_high_value;
void w3d_arena_set_high(Ptr32<void> value) { w3d_heap_arena_high_value = value; }
void w3d_arena_set_low(Ptr32<void> value) { w3d_heap_arena_low_value = value; }

}
