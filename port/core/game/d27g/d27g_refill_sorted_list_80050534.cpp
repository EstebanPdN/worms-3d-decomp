#include "w3d_ptr.h"
#line 1 "d27g_refill_sorted_list_80050534.cpp"
/* Worms 3D GameCube PAL 0x80050534. Releases every object in the list at +44 and clears each slot, clears the list, resizes it to the service count, fills it from the service read handle through a stack slot until the reader returns zero, then sorts it with qsort and the comparator at 0x800504d0. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct Object;
struct Vt { Ptr32<void> u[4]; Ptr32<void (Ptr32<Object>)> release; };
struct Object { Ptr32<Vt> vt; };
struct List {
    int count; int cap; Ptr32<Ptr32<Object>> data;
    Ptr32<Ptr32<Object>> begin() { return data; }
    Ptr32<Ptr32<Object>> end() { return data + count; }
    Ptr32<Ptr32<Object>> raw() { return data; }
};
struct Owner { char u[44]; List list; };
struct Slot { Ptr32<Object> value; Slot() {} Slot(const Slot &); };
extern "C" {
void w3d_list_clear_80210afc(Ptr32<List>);
int w3d_count_800fc668();
void w3d_list_resize_80210b90(Ptr32<List>, int);
int w3d_next_800fc69c(Ptr32<Slot>, Ptr32<Ptr32<Object>>);
void qsort_802ede44(Ptr32<void>, int, int, Ptr32<int (Ptr32<const void>, Ptr32<const void>)>);
int w3d_cmp_800504d0(Ptr32<const void>, Ptr32<const void>);
}
extern "C" void w3d_d27g_refill_sorted_list_80050534(Ptr32<Owner> self)
{
    Slot s;
    Ptr32<Slot> sp = &s;
    for (Ptr32<Ptr32<Object>> p = self->list.begin(); p != self->list.end(); ++p) {
        if (*p) (*p)->vt->release(*p);
        *p = 0;
    }
    int off = -4;
    w3d_list_clear_80210afc(&self->list);
    w3d_list_resize_80210b90(&self->list, w3d_count_800fc668());
    s.value = 0;
    do {
        off += 4;
    } while (w3d_next_800fc69c(sp, (Ptr32<Ptr32<Object>>)w3d::G((off + (int)w3d::H(self->list.raw())))));
    qsort_802ede44(self->list.raw(), self->list.count, 4, w3d_cmp_800504d0);
}


