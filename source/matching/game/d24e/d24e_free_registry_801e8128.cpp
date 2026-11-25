// Empties and frees one pointer vector (Worms 3D GameCube PAL, 0x801e8128).
//
// Erases all elements of the vector at 0x80365770, then swaps with an empty
// temporary whose destructor frees the old storage through 0x802134fc. Returns 0.
// Same vector shape as d24e_free_interface_tables_801fc7b0, with the temporary
// built after the erase.
extern "C" void *memcpy(...);
extern "C" void fn_802134fc(void *);
template<class T> inline void g_swap(T &a, T &b) { T t = a; a = b; b = t; }
struct d24e_PointerVector {
    void **b, **e, **c;
    d24e_PointerVector() { b = e = c = 0; }
    ~d24e_PointerVector() { if (b) fn_802134fc(b); }
    void erase(void **first, void **last) {
        int k = (char *)last - (char *)first;
        memcpy(first, last, (char *)e - (char *)last);
        e = (void **)((char *)e - k);
    }
    void swap(d24e_PointerVector &o) { g_swap(b, o.b); g_swap(e, o.e); g_swap(c, o.c); }
    void release() { erase(b, e); d24e_PointerVector t; t.swap(*this); }
};
extern d24e_PointerVector table_80365770;
extern "C" int w3d_d24e_free_registry_801e8128() {
    table_80365770.release();
    return 0;
}
