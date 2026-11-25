/* Table list rebuild (0x800994b4): zeroes and empties the item vector at +64, resizes it to the
 * entry count of the service (0x8015ae74) and fills it through the service iterator (0x8015aea8),
 * dropping entries whose count is zero when +56 is set, whose byte differs from +60 unless -1, or
 * whose kind differs from +76 unless 7, then resizes it to the kept count. The inlined vector
 * resize keeps the original behaviour: the capacity is computed from a byte difference, growth is
 * capacity times 1.5 or the needed amount, and the non-append fill stores to one element only.
 * Item is a partial view of the original virtual table with 4-byte entries; names are inferred
 * from the original instructions. The unit owns no data. */
extern "C" void *w3d_copy_802eee50(void *, const void *, ...);
extern "C" void *w3d_move_802eeef4(void *, const void *, unsigned);
extern "C" void *w3d_alloc_80212fd4(unsigned);
extern "C" void w3d_free_802134fc(void *);
extern "C" unsigned w3d_service_query_8015ae74();
struct Item {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual int Kind();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15();
    virtual unsigned char *Bytes();
    virtual void v17();
    virtual int Count();
};
extern "C" Item **w3d_service_pair_8015aea8(int *, Item **);
template <class T> static inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> static inline const T &Min(const T &a, const T &b) { return b < a ? b : a; }
struct Vec {
    Item **start; Item **finish; Item **limit;
    Item *&operator[](unsigned i) { return start[i]; }
    void erase(Item **first, Item **last) {
        int n = (char *)last - (char *)first;
        w3d_copy_802eee50(first, last, (char *)finish - (char *)last);
        finish = (Item **)((char *)finish - n);
    }
    unsigned capacity() const { return (char *)limit - (char *)start; }
    void wipe() { for (Item **p = start; p != finish; p++) *p = 0; }
    void clear() { erase(start, finish); }
    void resize(unsigned n, Item *const &v) {
        unsigned s = finish - start;
        if (n < s) { erase(start + n, finish); return; }
        Item **pos = finish;
        unsigned extra = n - s;
        if (pos + extra > limit) {
            int a, b;
            unsigned bytes, used;
            used = (char *)finish - (char *)start;
            a = capacity() + (extra - (limit - pos));
            b = capacity() + (capacity() >> 1);
            bytes = Max(a, b) << 2;
            Item **fresh = (Item **)w3d_alloc_80212fd4(bytes);
            if (start) {
                w3d_copy_802eee50(fresh, start, Min(bytes, used));
                w3d_free_802134fc(start);
            }
            start = fresh;
            pos = fresh + s;
            finish = (Item **)((char *)fresh + used);
            limit = (Item **)((char *)fresh + bytes);
        }
        if (pos == finish) {
            for (unsigned i = 0; i < extra; i++) finish[i] = v;
            finish += extra;
        } else {
            Item *c = v;
            w3d_move_802eeef4(pos + extra, pos, (char *)finish - (char *)pos);
            finish += extra;
            for (unsigned i = 0; i < extra; i++) *pos = c;
        }
    }
};
struct Menu { char unknown00[56]; int withCount; int byteFilter; Vec items; int kindFilter; };
extern "C" void w3d_d28b_table_rebuild_800994b4(Menu *self) {
    self->items.wipe();
    self->items.clear();
    self->items.resize(w3d_service_query_8015ae74(), (Item *)0);
    int iter = 0;
    unsigned kept = 0;
    Item *zero = 0;
    while (w3d_service_pair_8015aea8(&iter, &self->items[kept])) {
        int drop = 0;
        if (self->withCount != 0) drop = self->items[kept]->Count() == 0;
        if (self->byteFilter != -1 && *self->items[kept]->Bytes() != self->byteFilter) drop = 1;
        if (self->kindFilter != 7 && self->items[kept]->Kind() != self->kindFilter) drop = 1;
        if (drop) self->items[kept] = zero;
        else kept++;
    }
    self->items.resize(kept, (Item *)0);
}
