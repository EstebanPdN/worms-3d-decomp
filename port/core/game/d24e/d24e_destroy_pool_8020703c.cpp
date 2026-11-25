#include "w3d_ptr.h"
#line 1 "d24e_destroy_pool_8020703c.cpp"
// Destructor of an indexed object pool (Worms 3D GameCube PAL, 0x8020703c).
//
// Sets the vtable pointer, unlinks the free list threaded through the
// item slots (head at +48), destroys each live item through 0x802074c4, erases
// the vector, clears the counter at 0x804b18f0 and frees the storage. Then
// destroys the member at +20 (0x80210abc) and, with the base vtable set, the base
// part at +4 (0x80210990). Bit 0 of flags deletes self through 0x801fe1f8.
// Vtables are referenced as external objects, and stay unowned.
extern "C" Ptr32<void> memcpy(...);
extern "C" void fn_802134fc(Ptr32<void>);
extern "C" void fn_802074c4(Ptr32<void>);
extern "C" void fn_80210abc(Ptr32<void>, int);
extern "C" void fn_80210990(Ptr32<void>, int);
extern "C" void fn_801fe1f8(Ptr32<void>);
extern char vt_804191c0[], vt_80419200[];
extern int count_804b18f0;
struct d24e_ItemVector {
    void destroyAll() { for (Ptr32<void> *p = b,*last = e; p != last; ++p) { if (*p) fn_802074c4(*p); } }
    Ptr32<Ptr32<void>> b; Ptr32<Ptr32<void>> e; Ptr32<Ptr32<void>> c;
    void erase(Ptr32<Ptr32<void>> first, Ptr32<Ptr32<void>> last) {
        int k = (Ptr32<char>)last - (Ptr32<char>)first;
        memcpy(w3d::VA(first), w3d::VA(last), (Ptr32<char>)e - (Ptr32<char>)last);
        e = (Ptr32<Ptr32<void>>)((Ptr32<char>)e - k);
    }
};
struct d24e_Pool {
    Ptr32<char> vtable;
    char u04[16];
    char u14[16];
    d24e_ItemVector items;
    int freeHead;
};
extern "C" void w3d_d24e_destroy_pool_8020703c(Ptr32<d24e_Pool> self, unsigned flags) {
    self->vtable = vt_804191c0;
    for (int i = self->freeHead; i != 0; ) {
        int n = (int)w3d::H(self->items.b[i]);
        self->items.b[i] = 0;
        i = n;
    }
    self->items.destroyAll();
    d24e_ItemVector &v = self->items;
    v.erase(self->items.b, v.e);
    count_804b18f0 = 0;
    if (self->items.b) fn_802134fc(self->items.b);
    fn_80210abc(self->u14, 2);
    self->vtable = vt_80419200;
    fn_80210990(self->u04, 0);
    if (flags & 1) fn_801fe1f8(self);
}


