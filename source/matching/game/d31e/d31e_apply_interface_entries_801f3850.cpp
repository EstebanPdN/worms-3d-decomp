// (Worms 3D GameCube PAL, 0x801f3850).
//
// Walks the interfaces of kind 5 matching the type returned by 0x801fff3c
// for the object at +64 and, for each entry of an interface's null-
// terminated 16-byte table, finds the class index with 0x801e8f64; when
// found and the entry's mask is enabled in the global at 0x804b18dc, calls
// 0x801f3a00 with the index, the entry's second word and the code from the
// table at 0x803b0dbc. Names are inferred.

extern "C" int memcmp(const void *, const void *, unsigned);
struct Iface { char u[12]; void *guid; };
struct Iter;
extern "C" Iter *w3d_d25e_find_interface_801fca00(Iter *, int, const void *);
struct Iter {
    Iface **cur; Iface **last; void *guid; int extra;
    Iter() {}
    Iter(int i, const void *k) { w3d_d25e_find_interface_801fca00(this, i, k); }
    Iface *operator*() const { return *cur; }
    bool operator!=(const Iter &o) const { return cur != o.cur; }
    Iter &operator++() {
        if (cur != last) {
            do {
                Iface **p = cur;
                cur = p + 1;
                if (cur == last) break;
            } while (memcmp(cur[0]->guid, guid, 16) != 0);
        }
        return *this;
    }
};
inline Iter end_of(const void *k) { Iter t(5, k); t.cur = t.last; return t; }
struct Entry { void *guid; int a; int b; unsigned char mask; Entry *next() { return this + 1; } };
struct Item { char u[24]; Entry *entries; };
struct Self { char pad[64]; void *type; };
extern "C" void *w3d_auto_801fff3c(void *);
extern "C" int w3d_s21_find_item_class_801e8f64(void *, unsigned *);
extern "C" void fn_801f3a00(Self *, unsigned, int, int);
extern int lbl_804b18dc;
extern int lbl_803b0dbc[];
extern "C" void w3d_d31e_apply_interface_entries_801f3850(Self *self)
{
    void *k = w3d_auto_801fff3c(self->type);
    Iter it;
    w3d_d25e_find_interface_801fca00(&it, 5, k);
    Iter last = end_of(k);
    while (it != last) {
        Entry *e = ((Item *)*it)->entries;
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
