#include "w3d_ptr.h"
#line 1 "d24e_free_interface_tables_801fc7b0.cpp"
// Empties and frees thirteen pointer vectors (Worms 3D GameCube PAL, 0x801fc7b0).
//
// For each 12-byte vector in the table at 0x8045e890: erases all elements
// (a zero-length memcpy and an end pointer update), then swaps with an empty
// temporary whose destructor frees the old storage through 0x802134fc. Returns 0.
extern "C" Ptr32<void> memcpy(...);
extern "C" void fn_802134fc(Ptr32<void>);
template<class T> inline void g_swap(T &a, T &b) { T t = a; a = b; b = t; }
struct d24e_PointerVector {
    Ptr32<Ptr32<void>> b; Ptr32<Ptr32<void>> e; Ptr32<Ptr32<void>> c;
    d24e_PointerVector() { b = e = c = 0; }
    ~d24e_PointerVector() { if (b) fn_802134fc(b); }
    void erase(Ptr32<Ptr32<void>> first, Ptr32<Ptr32<void>> last) {
        int k = (Ptr32<char>)last - (Ptr32<char>)first;
        memcpy(w3d::VA(first), w3d::VA(last), (Ptr32<char>)e - (Ptr32<char>)last);
        e = (Ptr32<Ptr32<void>>)((Ptr32<char>)e - k);
    }
    void swap(d24e_PointerVector &o) { g_swap(b, o.b); g_swap(e, o.e); g_swap(c, o.c); }
    void release() { d24e_PointerVector t; erase(b, e); t.swap(*this); }
};
extern d24e_PointerVector table_8045e890[];
extern "C" int w3d_d24e_free_interface_tables_801fc7b0() {
    for (unsigned i = 0; i < 13; ++i) table_8045e890[i].release();
    return 0;
}


