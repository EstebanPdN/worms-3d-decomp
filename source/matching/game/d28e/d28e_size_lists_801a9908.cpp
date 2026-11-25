// (Worms 3D GameCube PAL, 0x801a9908).
//
// Resize the list of word vectors at +288 to n default elements (erase
// destroys the tail, growth goes through the fill insert 0x80354f08) and
// reserve 16 words in each element. Returns 0.

extern "C" void *w3d_d24k_heap_resize_80213750(void *, unsigned);
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
    Slots &operator=(const Slots &o) {
        unsigned n = o.end - o.begin;
        begin = (char *)w3d_d24k_heap_resize_80213750(begin, n);
        cap = end = begin + n;
        memcpy_802eee50(begin, o.begin, n);
        return *this;
    }
    T *first() { return (T *)begin; }
    T *last() { return (T *)end; }
    void push_back(const T &x) {
        if (end == cap) {
            unsigned used = end - begin;
            unsigned bytes = v_max((int)(used + 1), (int)(used + (used >> 1))) * sizeof(T);
            char *data = (char *)alloc_80212fd4(bytes);
            if (begin) { memcpy_802eee50(data, begin, v_min(bytes, used)); free_802134fc(begin); }
            begin = data; end = data + used; cap = data + bytes;
        }
        *(T *)end = x;
        end += sizeof(T);
    }
    void reserve(unsigned want) {
        unsigned c = cap - begin;
        unsigned have = (T *)cap - (T *)begin;
        if (want > have) {
            unsigned used = end - begin;
            unsigned bytes = v_max((int)(c + (want - have)), (int)(c + (c >> 1))) * sizeof(T);
            char *data = (char *)alloc_80212fd4(bytes);
            if (begin) { memcpy_802eee50(data, begin, v_min(bytes, used)); free_802134fc(begin); }
            begin = data; end = data + used; cap = data + bytes;
        }
    }
    void clear() { erase(begin, end); }
    void erase(char *first, char *last) {
        unsigned gone = last - first;
        memcpy_802eee50(first, last, end - last);
        end -= gone;
    }
    void insert(char *pos, unsigned n, const T &x) {
        unsigned at = (T *)pos - (T *)begin;
        if (pos + n * sizeof(T) > cap) {
            unsigned used = end - begin;
            unsigned left = (T *)cap - (T *)pos; unsigned c = cap - begin;
            unsigned bytes = v_max((int)(c + (n - left)), (int)(c + (c >> 1))) * sizeof(T);
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
template<class T, class V> inline void v_fill(T *first, T *last, const V &value) {
    for (; first != last; ++first) *first = value;
}

struct List {
    Slots<int> items; int extra;

    List() { items.cap = 0; items.end = 0; items.begin = 0; extra = 0; }
    ~List() { if (items.begin) free_802134fc(items.begin); }
};
struct Lists;
template<class T> inline void v_dist(T *first, T *last, int &n) { n += last - first; }
template<class T> inline T *v_copy(T *first, T *last, T *out) {
    int n = 0;
    v_dist(first, last, n);
    for (; n > 0; --n) { *out = *first; ++first; ++out; }
    return out;
}
extern "C" void sol35f4r_nested_buffer_insert_80354f08(Lists *, List *, unsigned, const List *);
struct Lists {
    List *start, *finish, *limit;
    unsigned size() const { return finish - start; }
    List &operator[](unsigned i) { return start[i]; }
    void erase(List *first, List *last) {
        List *e = v_copy(last, finish, first);
        { List *l = finish; for (List *p = e; p != l; ++p) p->~List(); }
        finish = e;
    }
    void resize(unsigned n, const List &x = List()) {
        if (n < size()) erase(start + n, finish);
        else sol35f4r_nested_buffer_insert_80354f08(this, finish, n - size(), &x);
    }
};
struct Self { char u[288]; Lists lists; };
extern "C" int w3d_d28e_size_lists_801a9908(Self *self, unsigned n)
{
    self->lists.resize(n);
    for (unsigned i = 0; i < n; i++) self->lists[i].items.reserve(16);
    return 0;
}
