// (Worms 3D GameCube PAL, 0x801a2754).
//
// Register an item in two parallel pointer vectors at +36 and +60. When the
// object's kind field is 3 both vectors are resized to the global table size
// at 0x804b18d8, the item is stored at its index in the first and zero in
// the second; the special object at 0x80365094 instead calls 0x801a2d68 with
// one entry.

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
struct Item { char u[20]; unsigned short index; };
struct Kind { char u[32]; unsigned : 12; unsigned kind : 4; unsigned : 16; int Type() const { return kind; } };
extern unsigned lbl_804b18d8;
extern Kind lbl_80365094[];
struct Self { char u[36]; Slots<Item *> a; char u1[12]; Slots<Item *> b; };
extern "C" void fn_801a2d68(Self *, unsigned);
extern "C" void w3d_d28e_register_item_801a2754(Self *self, Kind *k, Item *item)
{
    if (k->Type() == 3) {
        self->b.resize(lbl_804b18d8);
        self->a.resize(lbl_804b18d8);
        self->a[item->index] = item;
        self->b[item->index] = 0;
    } else if (k == lbl_80365094) fn_801a2d68(self, 1);
}
