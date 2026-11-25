#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "tsonnet_b27_ring_8015d018.c"
/* Rolling sample window: replaces the entry at the cursor with the new
   elapsed time and value, keeping running sums. Field meanings are inferred. */
typedef struct { int time; float value; } Entry;
typedef struct { Ptr32<Entry> entries; int count; int total; float sum; int index; int previous; } Ring;
void tsonnet_b27_ring_8015d018(Ptr32<Ring> p, int now, float value) {
    if (p->entries) {
        int elapsed;
        if (p->previous == -1) elapsed = 0; else elapsed = now - p->previous;
        p->sum = (p->sum - p->entries[p->index].value) + value;
        p->total = (p->total - p->entries[p->index].time) + elapsed;
        p->entries[p->index].value = value;
        p->entries[p->index].time = elapsed;
        p->index++;
        if (p->index >= p->count) p->index = 0;
        p->previous = now;
    }
}

}
