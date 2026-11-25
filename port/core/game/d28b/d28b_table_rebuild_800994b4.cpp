#include "w3d_ptr.h"
#line 1 "d28b_table_rebuild_800994b4.cpp"
/* Table list rebuild (0x800994b4): zeroes and empties the item vector at +64, resizes it to the
 * entry count of the service (0x8015ae74) and fills it through the service iterator (0x8015aea8),
 * dropping entries whose count is zero when +56 is set, whose byte differs from +60 unless -1, or
 * whose kind differs from +76 unless 7, then resizes it to the kept count. The inlined vector
 * resize keeps the original behaviour: the capacity is computed from a byte difference, growth is
 * capacity times 1.5 or the needed amount, and the non-append fill stores to one element only.
 * Item is a partial view of the original virtual table with 4-byte entries; names are inferred
 * from the original instructions. The unit owns no data. */
extern "C" Ptr32<void> w3d_copy_802eee50(Ptr32<void>, Ptr32<const void>, ...);
extern "C" Ptr32<void> w3d_move_802eeef4(Ptr32<void>, Ptr32<const void>, unsigned);
extern "C" Ptr32<void> w3d_alloc_80212fd4(unsigned);
extern "C" void w3d_free_802134fc(Ptr32<void>);
extern "C" unsigned w3d_service_query_8015ae74();
struct Item {
    void w3d_r_v0() __asm__(W3D_SYM("_ZN4Item2v0Ev")); void w3d_r_v1() __asm__(W3D_SYM("_ZN4Item2v1Ev")); void w3d_r_v2() __asm__(W3D_SYM("_ZN4Item2v2Ev")); void w3d_r_v3() __asm__(W3D_SYM("_ZN4Item2v3Ev"));
    void w3d_r_v4() __asm__(W3D_SYM("_ZN4Item2v4Ev")); void w3d_r_v5() __asm__(W3D_SYM("_ZN4Item2v5Ev")); void w3d_r_v6() __asm__(W3D_SYM("_ZN4Item2v6Ev"));
    int w3d_r_Kind() __asm__(W3D_SYM("_ZN4Item4KindEv"));
    void w3d_r_v8() __asm__(W3D_SYM("_ZN4Item2v8Ev")); void w3d_r_v9() __asm__(W3D_SYM("_ZN4Item2v9Ev")); void w3d_r_v10() __asm__(W3D_SYM("_ZN4Item3v10Ev")); void w3d_r_v11() __asm__(W3D_SYM("_ZN4Item3v11Ev")); void w3d_r_v12() __asm__(W3D_SYM("_ZN4Item3v12Ev")); void w3d_r_v13() __asm__(W3D_SYM("_ZN4Item3v13Ev"));
    void w3d_r_v14() __asm__(W3D_SYM("_ZN4Item3v14Ev")); void w3d_r_v15() __asm__(W3D_SYM("_ZN4Item3v15Ev"));
    Ptr32<unsigned char> w3d_r_Bytes() __asm__(W3D_SYM("_ZN4Item5BytesEv"));
    void w3d_r_v17() __asm__(W3D_SYM("_ZN4Item3v17Ev"));
    int w3d_r_Count() __asm__(W3D_SYM("_ZN4Item5CountEv"));
 __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int Kind() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v15() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<unsigned char> Bytes() { return ((Ptr32<unsigned char> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v17() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int Count() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 20))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Item; };
extern "C" Ptr32<Ptr32<Item>> w3d_service_pair_8015aea8(Ptr32<int>, Ptr32<Ptr32<Item>>);
template <class T> static inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> static inline const T &Min(const T &a, const T &b) { return b < a ? b : a; }
struct Vec {
    Ptr32<Ptr32<Item>> start; Ptr32<Ptr32<Item>> finish; Ptr32<Ptr32<Item>> limit;
    Ptr32<Item> & operator[](unsigned i) { return start[i]; }
    void erase(Ptr32<Ptr32<Item>> first, Ptr32<Ptr32<Item>> last) {
        int n = (Ptr32<char>)last - (Ptr32<char>)first;
        w3d_copy_802eee50(first, last, (Ptr32<char>)finish - (Ptr32<char>)last);
        finish = (Ptr32<Ptr32<Item>>)((Ptr32<char>)finish - n);
    }
    unsigned capacity() const { return (Ptr32<char>)limit - (Ptr32<char>)start; }
    void wipe() { for (Ptr32<Ptr32<Item>> p = start; p != finish; p++) *p = 0; }
    void clear() { erase(start, finish); }
    void resize(unsigned n, Ptr32<Item> const &v) {
        unsigned s = finish - start;
        if (n < s) { erase(start + n, finish); return; }
        Ptr32<Ptr32<Item>> pos = finish;
        unsigned extra = n - s;
        if (pos + extra > limit) {
            int a, b;
            unsigned bytes, used;
            used = (Ptr32<char>)finish - (Ptr32<char>)start;
            a = capacity() + (extra - (limit - pos));
            b = capacity() + (capacity() >> 1);
            bytes = Max(a, b) << 2;
            Ptr32<Ptr32<Item>> fresh = (Ptr32<Ptr32<Item>>)w3d_alloc_80212fd4(bytes);
            if (start) {
                w3d_copy_802eee50(fresh, start, Min(bytes, used));
                w3d_free_802134fc(start);
            }
            start = fresh;
            pos = fresh + s;
            finish = (Ptr32<Ptr32<Item>>)((Ptr32<char>)fresh + used);
            limit = (Ptr32<Ptr32<Item>>)((Ptr32<char>)fresh + bytes);
        }
        if (pos == finish) {
            for (unsigned i = 0; i < extra; i++) finish[i] = v;
            finish += extra;
        } else {
            Ptr32<Item> c = v;
            w3d_move_802eeef4(pos + extra, pos, (Ptr32<char>)finish - (Ptr32<char>)pos);
            finish += extra;
            for (unsigned i = 0; i < extra; i++) *pos = c;
        }
    }
};
struct Menu { char unknown00[56]; int withCount; int byteFilter; Vec items; int kindFilter; };
extern "C" void w3d_d28b_table_rebuild_800994b4(Ptr32<Menu> self) {
    self->items.wipe();
    self->items.clear();
    self->items.resize(w3d_service_query_8015ae74(), (Ptr32<Item>)0);
    int iter = 0;
    unsigned kept = 0;
    Ptr32<Item> zero = 0;
    while (w3d_service_pair_8015aea8(&iter, &self->items[kept])) {
        int drop = 0;
        if (self->withCount != 0) drop = self->items[kept]->Count() == 0;
        if (self->byteFilter != -1 && *self->items[kept]->Bytes() != self->byteFilter) drop = 1;
        if (self->kindFilter != 7 && self->items[kept]->Kind() != self->kindFilter) drop = 1;
        if (drop) self->items[kept] = zero;
        else kept++;
    }
    self->items.resize(kept, (Ptr32<Item>)0);
}


