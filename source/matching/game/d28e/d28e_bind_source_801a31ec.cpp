// (Worms 3D GameCube PAL, 0x801a31ec).
//
// Store the source object and argument, keep the result of the source's
// table slot at +20, resize the parallel pointer vectors at +36 and +60 to
// the global table size, copy the global item list into the first vector and
// resize the second pair through 0x801a2d68.

extern "C" void *alloc_80212fd4(unsigned);
extern "C" void free_802134fc(void *);
extern "C" void *memcpy_802eee50(void *, const void *, unsigned, ...);
extern "C" void *memmove_802eeef4(void *, const void *, unsigned);
inline const int &v_max(const int &a, const int &b) { return a < b ? b : a; }
inline const unsigned &v_min(const unsigned &a, const unsigned &b) { return b < a ? b : a; }
template<class T> struct Slots {
    char *begin, *end, *cap;
    unsigned size() const { return (T *)end - (T *)begin; }
    T &operator[](unsigned i) { return ((T *)begin)[i]; }
    void erase(char *first, char *last) {
        unsigned gone = last - first;
        memcpy_802eee50(first, last, end - last);
        end -= gone;
    }
    void insert(char *pos, unsigned n, const T &x) {
        unsigned at = (T *)pos - (T *)begin;
        if (pos + n * sizeof(T) > cap) {
            unsigned used = end - begin;
            unsigned c = cap - begin;
            unsigned bytes = v_max((int)(c + (n - ((T *)cap - (T *)pos))), (int)(c + (c >> 1))) << 2;
            char *data = (char *)alloc_80212fd4(bytes);
            if (begin) { memcpy_802eee50(data, begin, v_min(bytes, used)); free_802134fc(begin); }
            begin = data; end = data + used; cap = data + bytes;
            pos = begin + at * sizeof(T);
        }
        if (pos == end) {
            for (unsigned i = 0; i < n; i++) *(T *)(end + i * sizeof(T)) = x;
            end += n * sizeof(T);
        } else {
            T y = x;
            memmove_802eeef4(pos + n * sizeof(T), pos, end - pos);
            end += n * sizeof(T);
            for (unsigned i = 0; i < n; i++) *(T *)pos = y;
        }
    }
    void resize(unsigned n, const T &x = T()) {
        if (n < size()) erase(begin + n * sizeof(T), end);
        else insert(end, n - size(), x);
    }
};
struct Item;
struct ItemTable { char u[20]; void *(*get)(Item *); };
struct Item { ItemTable *table; };
struct Src { char u[20]; Slots<void *> items; };
extern unsigned lbl_804b18d8;
extern Src *lbl_804ab74c;
struct Self { char u[20]; Item *item; void *arg; void *got; char u32[4]; Slots<void *> a; char u1[12]; Slots<void *> b; };
extern "C" void fn_801a2d68(Self *, unsigned);
extern "C" void w3d_d28e_bind_source_801a31ec(Self *self, void *arg, Item *item)
{
    self->arg = arg;
    self->item = item;
    self->got = item->table->get(item);
    self->b.resize(lbl_804b18d8);
    self->a.resize(lbl_804b18d8);
    for (unsigned i = 0; i < lbl_804b18d8; i++) self->a[i] = lbl_804ab74c->items[i];
    fn_801a2d68(self, 1);
}
