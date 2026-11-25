// (Worms 3D GameCube PAL, 0x801a2d68).
//
// Resize two parallel pointer vectors at +48 and +72 to n entries, then fill
// the first with the value read from the global at 0x804ab74c through
// 0x801a2420. The vector is byte addressed with memcpy growth to the larger
// of need and 1.5 times capacity; a fill insert writes at the insert point
// without advancing.

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
struct Obj;
extern Obj *lbl_804ab74c;
extern "C" Obj *w3d_get_801a2420(Obj *);
struct Self { char u[48]; Slots<Obj *> a; char u1[12]; Slots<Obj *> b; };
extern "C" void w3d_d28e_resize_slots_801a2d68(Self *self, unsigned n)
{
    self->a.resize(n);
    self->b.resize(n);
    for (unsigned i = 0; i < n; i++) self->a[i] = w3d_get_801a2420(lbl_804ab74c);
}
