#include "w3d_ptr.h"
#line 1 "d28e_add_draw_block_801aa15c.cpp"
// (Worms 3D GameCube PAL, 0x801aa15c).
//
// Append a draw block to list index: skips kind 3 lists. When the current
// material differs from the entry at the mark it stores the source matrix
// into the material and pushes it; a changed transform takes a 512-per-chunk
// pool element, copies the matrix and pushes it. Then it takes a 16-byte
// block from the arena at +232, sets its depth from kind (zero, or the
// matrix's z), packs the transform index, current and mark into the word at
// +12, stores key and link, and pushes the block on the list.

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
struct Matrix { int w[14]; float z; int w15; };
struct Type { char u[32]; unsigned int rest:22; unsigned int index:10; };
extern Type lbl_80363bf4[];
struct Elt2;
extern "C" int w3d_ctor_801bddf0(Ptr32<Elt2>, unsigned);
struct Elt2 {
    char u[20]; Matrix m;
    Elt2() { w3d_ctor_801bddf0(this, lbl_80363bf4->index); }
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
    void set(Ptr32<T> s, Ptr32<T> f, Ptr32<T> e) { start = s; finish = f; limit = e; }
    static Ptr32<void> allocate_bytes(unsigned n) {
        Ptr32<void> p = alloc_80212fd4(n);
        if (p == 0) p = w3d_handle_storage_fallback_803413d8(n);
        return p;
    }
    void insert_overflow(Ptr32<T> pos, const T &x, const VTrue &, unsigned fill_len, bool atend) {
        const unsigned old_size = finish - start;
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
template<class E, int N> struct Pool {
    SVec <Ptr32<E> > chunks; Ptr32<Ptr32<E>> cur; int pos;
    Ptr32<E> acquire() {
        if (pos == N) {
            ++cur;
            if (cur == chunks.finish) {
                chunks.push_back(w3d::new_array<E>(N));
                cur = chunks.finish - 1;
            }
            pos = 0;
        }
        return *cur + pos++;
    }
};
struct Block { Ptr32<void> next; Ptr32<void> key; float z; unsigned int current:7; unsigned int mark:9; unsigned int n:16; };
struct List { Slots <Ptr32<Block> > items; int kind; };
struct Elt;
struct Source;
struct SourceTable { char u24[24]; Ptr32<Ptr32<const Matrix> (Ptr32<Source>)> matrix; };
struct Source { Ptr32<SourceTable> table; };
extern "C" Ptr32<Block> w3d_cx10b_arena_allocate_existing_80209d50(Ptr32<void>, unsigned);
struct Elt { char u[20]; Matrix m; };
struct Self {
    char u48[48]; int a48; int a52; Ptr32<const Matrix> m56; char u60[104]; Ptr32<Elt> a164; Ptr32<Elt> a168; Ptr32<Source> source;
    char u176[4]; Pool<Elt2, 512> pool; char u204[24]; Ptr32<void> a228; char arena[8];
    Slots <Ptr32<Elt2> > c; char u252[12]; int current; Slots <Ptr32<Elt> > e; unsigned short mark; char u282[6]; Ptr32<List> lists;
};
extern "C" void w3d_d28e_add_draw_block_801aa15c(Ptr32<Self> self, int index, Ptr32<void> key)
{
    Ptr32<List> list = &self->lists[index];
    if (list->kind == 3) return;
    if (self->e[self->mark] != self->a164) {
        if (self->a164 != self->a168) {
            self->a164->m = *self->source->table->matrix(self->source);
            self->e.push_back(self->a164);
            self->mark = self->e.size() - 1;
        } else self->mark = 0;
    }
    if (self->a48 != self->a52) {
        Ptr32<Elt2> e = self->pool.acquire();
        e->m = *self->m56;
        self->c.push_back(e);
        self->a52 = self->a48;
    }
    int n = self->c.size() - 1;
    Ptr32<Block> b = w3d_cx10b_arena_allocate_existing_80209d50(self->arena, 16);
    switch (list->kind) {
    case 1: case 2:
        b->z = self->m56->z;
        break;
    case 0:
        b->z = 0.0f;
        break;
    }
    b->n = n;
    b->current = self->current;
    b->mark = self->mark;
    b->key = key;
    { unsigned k = self->a228.v; b->next.v = k << 16 | k >> 16; } /* clave de orden: dos u16 en +228 y +230, la primera en la mitad alta en PPC */
    list->items.push_back(b);
}


