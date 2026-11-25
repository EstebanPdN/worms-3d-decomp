// (Worms 3D GameCube PAL, 0x80204950).
//
// Serialize to a stream: resets, runs the collection pass through the table
// slot at +32, assigns running offsets to the sized map at +44, numbers the
// objects of the map at +60 per type and lists them, writes the header,
// types, guids, tables and body through the section writers, then writes
// each listed object through its table. Returns 0.

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

template<class T> struct Array : Slots<T> {
    Array(unsigned n) {
        cap = 0; end = 0; begin = 0;
        grow(n);
        end += n * sizeof(T);
    }
    struct Init { T v; Init() : v(0) { } const T &get() const { return v; } };
    void zero_fill(T *f, T *l, const Init &x) { for (; f != l; ++f) *f = x.get(); }
    void assign() { zero_fill(first(), last(), Init()); }
    Array(const Array &o) {
        unsigned bytes = o.end - o.begin;
        begin = (char *)alloc_80212fd4(bytes);
        cap = end = begin + bytes;
        memcpy_802eee50(begin, o.begin, bytes);
    }
    ~Array() { if (begin) free_802134fc(begin); }
    void grow(unsigned n) {
        unsigned used = end - begin;
        unsigned c = cap - begin;
        unsigned bytes = v_max((int)(c + n), (int)(c + (c >> 1))) * sizeof(T);
        char *data = (char *)alloc_80212fd4(bytes);
        if (begin) { memcpy_802eee50(data, begin, v_min(bytes, used)); free_802134fc(begin); }
        begin = data; end = data + used; cap = data + bytes;
    }
};
template<class T, class V> inline void v_fill_(T *, T *, const V &);

extern "C" void *w3d_rb_increment_80351ef8(void *);
template<class V> struct TreeNode { int color; TreeNode *parent; TreeNode *left; TreeNode *right; V value; };
template<class V> struct TreeIter {
    TreeNode<V> *node;
    TreeIter(TreeNode<V> *n) : node(n) { }
    TreeIter(const TreeIter &o) : node(o.node) { }
    bool operator!=(const TreeIter &o) const { return node != o.node; }
    V &operator*() const { return node->value; }
    TreeIter &operator++() { node = (TreeNode<V> *)w3d_rb_increment_80351ef8(node); return *this; }
};
template<class V> struct Tree {
    int alloc; TreeNode<V> *header; unsigned count; int cmp;
    unsigned size() const { return count; }
    TreeIter<V> begin() { return TreeIter<V>(header->left); }
    TreeIter<V> end() { return TreeIter<V>(header); }
};
struct Stream;
struct Sized { void *key; int size; int off0; int off1; };
struct SizedPair { unsigned k; Sized second; };
struct Item { virtual void v8(); virtual void v12(); virtual void v16(); virtual unsigned id(); virtual void write(struct Writer *); };
struct Value16 { char u[12]; int next; };
struct Slotted { Item *item; int slot; };
struct Self;
extern "C" void fn_80204850(Self *);
extern "C" int w3d_auto_801ffea8(void *);
extern "C" Value16 *fn_80205654(Self *, unsigned);
extern "C" void f7c_header_80204c18(Self *);
extern "C" int f7c_types_80204d88(Self *);
extern "C" int f7c_guids_80204f08(Self *);
extern "C" int fn_80204ffc(Self *);
extern "C" int fn_80205258(Self *);
extern "C" int w3d_auto_80205648(Self *);
struct Writer { virtual void v8(); virtual void v12(); virtual void v16(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void begin_stream(Stream *, int); };
struct Self : Writer {
    char u4[20]; int state; char u28[16];
    Tree<SizedPair> sized; Tree<Slotted> slotted; char u76[72]; Stream *stream;
};
extern "C" int w3d_d28e_write_file_80204950(Self *self, Stream *s)
{
    self->stream = s;
    fn_80204850(self);
    self->state = 1;
    self->begin_stream(s, 0);
    self->state = 2;
    int offset = 1;
    for (TreeIter<SizedPair> it = self->sized.begin(); it != self->sized.end(); ++it) {
        Sized &e = (*it).second;
        w3d_auto_801ffea8(e.key);
        e.off0 = offset;
        e.off1 = offset;
        offset += e.size;
    }
    int count = self->slotted.size();
    Array<Item *> list(count + 1);
    for (TreeIter<Slotted> j = self->slotted.begin(); j != self->slotted.end(); ++j) {
        Item *o = (*j).item;
        Value16 *v = fn_80205654(self, o->id());
        (*j).slot = v->next++;
        list[(*j).slot] = o;
    }
    f7c_header_80204c18(self);
    f7c_types_80204d88(self);
    f7c_guids_80204f08(self);
    fn_80204ffc(self);
    fn_80205258(self);
    w3d_auto_80205648(self);
    for (int i = 1; i <= count; i++) {
        Item *o = list[i];
        fn_80205654(self, o->id());
        o->write((Writer *)self);
    }
    self->state = 0;
    return 0;
}
