#include "w3d_ptr.h"
#line 1 "d31e_apply_interface_entries_801f3850.cpp"
// (Worms 3D GameCube PAL, 0x801f3850).
//
// Walks the interfaces of kind 5 matching the type returned by 0x801fff3c
// for the object at +64 and, for each entry of an interface's null-
// terminated 16-byte table, finds the class index with 0x801e8f64; when
// found and the entry's mask is enabled in the global at 0x804b18dc, calls
// 0x801f3a00 with the index, the entry's second word and the code from the
// table at 0x803b0dbc. Names are inferred.

extern "C" int memcmp(Ptr32<const void>, Ptr32<const void>, unsigned);
struct Iface { char u[12]; Ptr32<void> guid; };
struct Iter;
extern "C" Ptr32<Iter> w3d_d25e_find_interface_801fca00(Ptr32<Iter>, int, Ptr32<const void>);
struct Iter {
    Ptr32<Ptr32<Iface>> cur; Ptr32<Ptr32<Iface>> last; Ptr32<void> guid; int extra;
    Iter() {}
    Iter(int i, Ptr32<const void> k) { w3d_d25e_find_interface_801fca00(this, i, k); }
    Ptr32<Iface> operator*() const { return *cur; }
    bool operator!=(const Iter &o) const { return cur != o.cur; }
    Iter &operator++() {
        if (cur != last) {
            do {
                Ptr32<Ptr32<Iface>> p = cur;
                cur = p + 1;
                if (cur == last) break;
            } while (memcmp(cur[0]->guid, guid, 16) != 0);
        }
        return *this;
    }
};
inline Iter end_of(Ptr32<const void> k) { Iter t(5, k); t.cur = t.last; return t; }
struct Entry { Ptr32<void> guid; int a; int b; unsigned char mask; Ptr32<Entry> next() { return this + 1; } };
struct Item { char u[24]; Ptr32<Entry> entries; };
struct Self { char pad[64]; Ptr32<void> type; };
extern "C" Ptr32<void> w3d_auto_801fff3c(Ptr32<void>);
extern "C" int w3d_s21_find_item_class_801e8f64(Ptr32<void>, Ptr32<unsigned int>);
extern "C" void fn_801f3a00(Ptr32<Self>, unsigned, int, int);
extern int lbl_804b18dc;
extern int lbl_803b0dbc[];
extern "C" void w3d_d31e_apply_interface_entries_801f3850(Ptr32<Self> self)
{
    Ptr32<void> k = w3d_auto_801fff3c(self->type);
    Iter it;
    w3d_d25e_find_interface_801fca00(&it, 5, k);
    Iter last = end_of(k);
    while (it != last) {
        Ptr32<Entry> e = ((Ptr32<Item>)*it)->entries;
        while (e->guid) {
            unsigned index;
            if (w3d_s21_find_item_class_801e8f64(e->guid, &index) != 0) { e++; continue; }
            if ((e->mask & lbl_804b18dc) == e->mask)
                fn_801f3a00(self, index, e->a, lbl_803b0dbc[e->b]);
            e++;
        }
        ++it;
    }
}


