#include "w3d_ptr.h"
#line 1 "d24e_shutdown_objects_801e89c0.cpp"
// Shutdown of the registered objects (Worms 3D GameCube PAL, 0x801e89c0).
//
// Calls 0x801e8ccc on each node of the list at 0x804b18e0 (link at +76), erases
// the vector at 0x8045e080 and swaps it with an empty temporary, calls 0x801ea954
// and 0x801ea9a4, then the temporary's destructor frees the old storage through
// 0x802134fc. Returns 0.
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
};
struct Node { char u[76]; Ptr32<Node> next; };
extern Ptr32<Node> first_804b18e0;
extern d24e_PointerVector table_8045e080;
extern "C" void fn_801e8ccc(Ptr32<Node>);
extern "C" int fn_801ea954();
extern "C" void fn_801ea9a4(Ptr32<void>);
extern "C" int w3d_d24e_shutdown_objects_801e89c0() {
    for (Ptr32<Node> n = first_804b18e0; n; n = n->next) fn_801e8ccc(n);
    table_8045e080.erase(table_8045e080.b, table_8045e080.e);
    d24e_PointerVector t;
    t.swap(table_8045e080);fn_801ea9a4((Ptr32<void>)w3d::G(fn_801ea954()));
    return 0;
}


