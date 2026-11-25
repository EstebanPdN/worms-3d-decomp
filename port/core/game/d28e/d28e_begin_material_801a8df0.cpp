#include "w3d_ptr.h"
#line 1 "d28e_begin_material_801a8df0.cpp"
// (Worms 3D GameCube PAL, 0x801a8df0).
//
// Start a material for a source: copies +168 to +164, clears counters, reads
// the source's count and matrix through its table, updates the frustum at
// +64 through 0x801a9f78, takes the pair count through 0x801f5da0, then
// finds the matrix among the elements at +252 by a 64-byte compare. A new
// matrix takes an element from the 32-per-chunk pool at +204 and is
// appended. The index goes to +264. Returns 0.

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
    void reserve(unsigned want) {
        unsigned c = cap - begin;
        unsigned have = (Ptr32<T>)cap - (Ptr32<T>)begin;
        if (want > have) {
            unsigned used = end - begin;
            unsigned bytes = v_max((int)(c + (want - have)), (int)(c + (c >> 1))) * sizeof(T);
            Ptr32<char> data = (Ptr32<char>)alloc_80212fd4(bytes);
            if (begin) { memcpy_802eee50(data, begin, v_min(bytes, used)); free_802134fc(begin); }
            begin = data; end = data + used; cap = data + bytes;
        }
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

extern "C" int memcmp_802eedc0(Ptr32<const void>, Ptr32<const void>, unsigned);
extern "C" Ptr32<void> w3d_handle_storage_fallback_803413d8(unsigned);
extern "C" Ptr32<void> w3d_heap_allocate_801fe1d8(unsigned);
struct Matrix { int w[16]; };
struct Elt;
struct Type { char u[32]; unsigned int rest:22; unsigned int index:10; };
extern Type lbl_80363c44[];
extern "C" int w3d_ctor_801bdfe4(Ptr32<Elt>, unsigned);
struct Elt {
    char u[20]; Matrix m;
    Elt() { w3d_ctor_801bdfe4(this, lbl_80363c44->index); }
    static void *operator new[](__SIZE_TYPE__ n) { return w3d_heap_allocate_801fe1d8(n); }
};
inline Ptr32<void> v_copy_trivial(Ptr32<const void> first, Ptr32<const void> last, Ptr32<void> result) {
    if (last != first) {
        unsigned n = (Ptr32<const char>)last - (Ptr32<const char>)first;
        return (Ptr32<char>)memmove_802eeef4(result, first, n) + n;
    }
    return result;
}
template<class T> inline const T &s_max(const T &a, const T &b) { return a < b ? b : a; }
template<class T> inline Ptr32<T> v_fill_n(T *out, unsigned n, const T &value) {
    for (; n > 0; --n, ++out) *out = value;
    return out;
}
struct VTrue { char w3d_empty; };
template<class T> struct SVec {
    Ptr32<T> start; Ptr32<T> finish; int alloc; Ptr32<T> limit;
    unsigned size() const { return finish - start; }
    void set(Ptr32<T> s, Ptr32<T> f, Ptr32<T> e) { start = s; finish = f; limit = e; }
    static Ptr32<void> allocate_bytes(unsigned n) {
        Ptr32<void> p = alloc_80212fd4(n);
        if (p == 0) p = w3d_handle_storage_fallback_803413d8(n);
        return p;
    }
    void insert_overflow(Ptr32<T> pos, const T &x, const VTrue &, unsigned fill_len, bool atend) {
        const unsigned old_size = size();
        const unsigned len = old_size + s_max(old_size, fill_len);
        Ptr32<T> new_start = len ? (Ptr32<T>)allocate_bytes(len * sizeof(T)) : 0;
        Ptr32<T> new_finish = (Ptr32<T>)v_copy_trivial(start, pos, new_start);
        new_finish = v_fill_n(w3d::R(new_finish), fill_len, x);
        if (start) free_802134fc(start);
        set(new_start, new_finish, new_start + len);
    }
    void push_back(const T &x) {
        if (finish != limit) { if (finish) *finish = x; ++finish; }
        else insert_overflow(finish, x, VTrue(), 1, true);
    }
};
struct Pool {
    SVec <Ptr32<Elt> > chunks; Ptr32<Ptr32<Elt>> cur; int pos;
    Ptr32<Elt> acquire(const Matrix &m) {
        if (pos == 32) {
            ++cur;
            if (cur == chunks.finish) {
                chunks.push_back(w3d::new_array<Elt>(32));
                cur = chunks.finish - 1;
            }
            pos = 0;
        }
        Ptr32<Elt> r = *cur + pos++;
        r->m = m;
        return r;
    }
};
struct Source;
struct SourceTable { char u24[24]; Ptr32<int (Ptr32<Source>)> count; char u28[4]; Ptr32<Ptr32<const Matrix> (Ptr32<Source>)> matrix; Ptr32<Ptr32<void> (Ptr32<Source>)> extra; };
struct Source { Ptr32<SourceTable> table; };
extern "C" int w3d_k5b_pairs_cancel_801f5da0(Ptr32<void>);
extern "C" void f8c_frustum_801a9f78(Ptr32<struct Self>, Ptr32<const Matrix>, Ptr32<void>);
struct Self {
    char u[44]; int a44; int a48; int a52; int count56; int pairs60; char box64[100]; int a164; int a168; Ptr32<Source> source;
    char u176[28]; Pool pool; char u228[24]; Slots <Ptr32<Elt> > elts; int current; char u268[56]; int a324;
};
extern "C" int w3d_d28e_begin_material_801a8df0(Ptr32<Self> self)
{
    Ptr32<Source> s = self->source;
    self->a164 = self->a168;
    self->a324 = 0;
    self->count56 = 0;
    self->count56 = s->table->count(s);
    self->a48 = 0;
    self->a44 = -1;
    self->a52 = -1;
    Ptr32<const Matrix> m = s->table->matrix(s);
    f8c_frustum_801a9f78(self, m, self->box64);
    self->pairs60 = w3d_k5b_pairs_cancel_801f5da0(s->table->extra(s));
    int idx = 0;
    bool found = false;
    Ptr32<Ptr32<Elt>> last = (Ptr32<Ptr32<Elt>>)self->elts.end;
    for (Ptr32<Ptr32<Elt>> it = (Ptr32<Ptr32<Elt>>)self->elts.begin; it != last; ++it, ++idx) {
        if (memcmp_802eedc0(m, &(*it)->m, 64) == 0) { found = true; break; }
    }
    if (!found) {
        Ptr32<Elt> e = self->pool.acquire(*m);
        idx = self->elts.size();
        self->elts.push_back(e);
    }
    self->current = idx;
    return 0;
}


