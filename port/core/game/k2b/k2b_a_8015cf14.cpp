#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k2b_a_8015cf14.c"
struct K2bSlot { int id; float weight; };
struct K2bSlotTable { Ptr32<struct K2bSlot> slots; int count; int head; float total; int cursor; int last; };
extern void w3d_task_array_release(Ptr32<void> slots);
extern Ptr32<struct K2bSlot> w3d_heap_allocate_entry_b(int bytes);
extern void w3d_slot_table_reset_8015cfa0(Ptr32<struct K2bSlotTable> t);
void w3d_k2b_slot_table_resize_8015cf14(Ptr32<struct K2bSlotTable> t, int count)
{
    Ptr32<struct K2bSlot> slots;
    Ptr32<struct K2bSlot> p;
    int n;
    if (t->slots != 0)
        w3d_task_array_release(t->slots);
    slots = w3d_heap_allocate_entry_b(count * 8);
    p = slots;
    n = count - 1;
    if (n != -1) {
        do {
            p->id = 0;
            p->weight = 0.0f;
            p++;
        } while (n-- != 0);
    }
    t->count = count;
    t->slots = slots;
    w3d_slot_table_reset_8015cfa0(t);
}
// desc: Appears to replace a slot table's storage with a freshly allocated zeroed array of the given length and reset it.

}
