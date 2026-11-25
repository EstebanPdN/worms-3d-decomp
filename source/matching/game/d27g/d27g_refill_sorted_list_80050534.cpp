/* Worms 3D GameCube PAL 0x80050534. Releases every object in the list at +44 and clears each slot, clears the list, resizes it to the service count, fills it from the service read handle through a stack slot until the reader returns zero, then sorts it with qsort and the comparator at 0x800504d0. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct Object;
struct Vt { void *u[4]; void (*release)(Object *); };
struct Object { Vt *vt; };
struct List {
    int count; int cap; Object **data;
    Object **begin() { return data; }
    Object **end() { return data + count; }
    Object **raw() { return data; }
};
struct Owner { char u[44]; List list; };
struct Slot { Object *value; Slot() {} Slot(const Slot &); };
extern "C" {
void w3d_list_clear_80210afc(List *);
int w3d_count_800fc668();
void w3d_list_resize_80210b90(List *, int);
int w3d_next_800fc69c(Slot *, Object **);
void qsort_802ede44(void *, int, int, int (*)(const void *, const void *));
int w3d_cmp_800504d0(const void *, const void *);
}
extern "C" void w3d_d27g_refill_sorted_list_80050534(Owner *self)
{
    Slot s;
    Slot *sp = &s;
    for (Object **p = self->list.begin(); p != self->list.end(); ++p) {
        if (*p) (*p)->vt->release(*p);
        *p = 0;
    }
    int off = -4;
    w3d_list_clear_80210afc(&self->list);
    w3d_list_resize_80210b90(&self->list, w3d_count_800fc668());
    s.value = 0;
    do {
        off += 4;
    } while (w3d_next_800fc69c(sp, (Object **)(off + (int)self->list.raw())));
    qsort_802ede44(self->list.raw(), self->list.count, 4, w3d_cmp_800504d0);
}
