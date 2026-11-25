#include "w3d_ptr.h"
#line 1 "d28e_reset_batches_801a966c.cpp"
// (Worms 3D GameCube PAL, 0x801a966c).
//
// Reset a batch collector: creates its service on first use through the
// named factory at 0x80414ae0 and flags it, rewinds the two cursors at +180
// and +204, clears the vectors at +240, +252 and +268, clears the block at
// +232, pushes the service as the first entry of the +268 vector, clears the
// mark at +280 and every element vector of the list at +288, and zeroes the
// two counters. Returns 0.

extern "C" Ptr32<void> w3d_d24k_heap_resize_80213750(Ptr32<void>, unsigned);
extern "C" Ptr32<void> alloc_80212fd4(unsigned);
extern "C" void free_802134fc(Ptr32<void>);
extern "C" Ptr32<void> memcpy_802eee50(Ptr32<void>, Ptr32<const void>, unsigned, ...);
extern "C" Ptr32<void> memmove_802eeef4(Ptr32<void>, Ptr32<const void>, unsigned);
inline const int &v_max(const int &a, const int &b) { return a < b ? b : a; }
inline const unsigned &v_min(const unsigned &a, const unsigned &b) { return b < a ? b : a; }
template<class T> struct Slots {
    Ptr32<char> begin; Ptr32<char> end; Ptr32<char> cap;
    unsigned size() const { return (Ptr32<T>)end - (Ptr32<T>)begin; }
    T &operator[](unsigned i) { return ((Ptr32<T>)begin)[i]; }
    Slots &operator=(const Slots &o) {
        unsigned n = o.end - o.begin;
        begin = (Ptr32<char>)w3d_d24k_heap_resize_80213750(begin, n);
        cap = end = begin + n;
        memcpy_802eee50(begin, o.begin, n);
        return *this;
    }
    Ptr32<T> first() { return (Ptr32<T>)begin; }
    Ptr32<T> last() { return (Ptr32<T>)end; }
    void push_back(const T &x) {
        if (end == cap) {
            unsigned used = end - begin;
            unsigned bytes = v_max((int)(used + 1), (int)(used + (used >> 1))) * sizeof(T);
            Ptr32<char> data = (Ptr32<char>)alloc_80212fd4(bytes);
            if (begin) { memcpy_802eee50(data, begin, v_min(bytes, used)); free_802134fc(begin); }
            begin = data; end = data + used; cap = data + bytes;
        }
        *(Ptr32<T>)end = x;
        end += sizeof(T);
    }
    void clear() { erase(begin, end); }
    void erase(Ptr32<char> first, Ptr32<char> last) {
        unsigned gone = last - first;
        memcpy_802eee50(first, last, end - last);
        end -= gone;
    }
    void insert(Ptr32<char> pos, unsigned n, const T &x) {
        unsigned at = (Ptr32<T>)pos - (Ptr32<T>)begin;
        if (pos + n * sizeof(T) > cap) {
            unsigned used = end - begin;
            unsigned left = (Ptr32<T>)cap - (Ptr32<T>)pos; unsigned c = cap - begin;
            unsigned bytes = v_max((int)(c + (n - left)), (int)(c + (c >> 1))) * sizeof(T);
            Ptr32<char> data = (Ptr32<char>)alloc_80212fd4(bytes);
            if (begin) { memcpy_802eee50(data, begin, v_min(bytes, used)); free_802134fc(begin); }
            begin = data; end = data + used; cap = data + bytes;
            pos = begin + at * sizeof(T);
        }
        if (pos == end) {
            for (unsigned i = 0; i < n; i++) *(Ptr32<T>)(end + i * sizeof(T)) = x;
            end += n * sizeof(T);
        } else {
            T y = x;
            memmove_802eeef4(pos + n * sizeof(T), pos, end - pos);
            end += n * sizeof(T);
            for (unsigned i = 0; i < n; i++) *(Ptr32<T>)pos = y;
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

struct Service;
struct ServiceTable { char u12[12]; Ptr32<void (Ptr32<Service>)> add_ref; Ptr32<void (Ptr32<Service>)> release; };
struct Sub { char u[4]; unsigned char flags; char w3d_tag_rest[3]; };
struct Service { Ptr32<ServiceTable> table; Sub sub; };
struct Cursor { Ptr32<void> base; char u4[12]; Ptr32<void> cur; int pos; void rewind() { cur = base; pos = 0; } };
struct List { Slots<int> items; int extra; };
extern char lbl_80414ae0[];
extern "C" Ptr32<Service> w3d_s10_service_forward_8020b680(Ptr32<char>);
extern "C" void w3d_auto_80209de4(Ptr32<void>);
struct Self {
    char u[168]; Ptr32<Service> service; char u172[8];
    Cursor a; Cursor b;
    int count228; char tail232[8]; Slots<int> c; Slots<int> d; char u264[4]; Slots <Ptr32<Service> > e;
    short mark; char u282[2]; int count284; Slots<List> lists;
};

extern "C" int w3d_d28e_reset_batches_801a966c(Ptr32<Self> self)
{
    if (self->service == 0) {
        Ptr32<Service> p = w3d_s10_service_forward_8020b680(lbl_80414ae0);
        if (p) p->table->add_ref(p);
        if (self->service) self->service->table->release(self->service);
        self->service = p;
        Ptr32<Sub> sub = &p->sub;
        sub->flags |= 8;
    }
    self->a.rewind();
    self->c.clear();
    self->b.rewind();
    self->d.clear();
    w3d_auto_80209de4(self->tail232);
    self->e.clear();
    Ptr32<Service> s = self->service; self->e.push_back(s);
    self->mark = 0;
    unsigned n = self->lists.size();
    for (unsigned i = 0; i < n; i++) self->lists[i].items.clear();
    self->count284 = 0;
    self->count228 = 0;
    return 0;
}


