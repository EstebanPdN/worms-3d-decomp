#include "w3d_ptr.h"
#line 1 "d24e_free_registry_801e8128.cpp"
// Empties and frees one pointer vector (Worms 3D GameCube PAL, 0x801e8128).
//
// Erases all elements of the vector at 0x80365770, then swaps with an empty
// temporary whose destructor frees the old storage through 0x802134fc. Returns 0.
// Same vector shape as d24e_free_interface_tables_801fc7b0, with the temporary
// built after the erase.
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
    void release() { erase(b, e); d24e_PointerVector t; t.swap(*this); }
};
extern d24e_PointerVector table_80365770;
extern "C" int w3d_d24e_free_registry_801e8128() {
    table_80365770.release();
    return 0;
}


