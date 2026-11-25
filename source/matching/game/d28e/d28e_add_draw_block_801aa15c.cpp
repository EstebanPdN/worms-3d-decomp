// (Worms 3D GameCube PAL, 0x801aa15c).
//
// Append a draw block to list index: skips kind 3 lists. When the current
// material differs from the entry at the mark it stores the source matrix
// into the material and pushes it; a changed transform takes a 512-per-chunk
// pool element, copies the matrix and pushes it. Then it takes a 16-byte
// block from the arena at +232, sets its depth from kind (zero, or the
// matrix's z), packs the transform index, current and mark into the word at
// +12, stores key and link, and pushes the block on the list.

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

extern "C" int memcmp_802eedc0(const void *, const void *, unsigned);
extern "C" void *w3d_handle_storage_fallback_803413d8(unsigned);
extern "C" void *w3d_heap_allocate_801fe1d8(unsigned);
struct Matrix { int w[14]; float z; int w15; };
struct Type { char u[32]; unsigned index : 10; unsigned rest : 22; };
extern Type lbl_80363bf4[];
struct Elt2;
extern "C" int w3d_ctor_801bddf0(Elt2 *, unsigned);
struct Elt2 {
    char u[20]; Matrix m;
    Elt2() { w3d_ctor_801bddf0(this, lbl_80363bf4->index); }
    static void *operator new[](unsigned n) { return w3d_heap_allocate_801fe1d8(n); }
};
inline void *v_copy_trivial(const void *first, const void *last, void *result) {
    if (last != first) {
        unsigned n = (const char *)last - (const char *)first;
        return (char *)memmove_802eeef4(result, first, n) + n;
    }
    return result;
}
template<class T> inline const T &s_max(const T &a, const T &b) { return a < b ? b : a; }
template<class T> inline T *v_fill_n(T *out, unsigned n, const T &value) {
    for (; n > 0; --n, ++out) *out = value;
    return out;
}
struct VTrue {};
template<class T> struct SVec {
    T *start; T *finish; int alloc; T *limit;
    void set(T *s, T *f, T *e) { start = s; finish = f; limit = e; }
    static void *allocate_bytes(unsigned n) {
        void *p = alloc_80212fd4(n);
        if (p == 0) p = w3d_handle_storage_fallback_803413d8(n);
        return p;
    }
    void insert_overflow(T *pos, const T &x, const VTrue &, unsigned fill_len, bool atend) {
        const unsigned old_size = finish - start;
        const unsigned len = old_size + s_max(old_size, fill_len);
        T *new_start = len ? (T *)allocate_bytes(len * sizeof(T)) : 0;
        T *new_finish = (T *)v_copy_trivial(start, pos, new_start);
        new_finish = v_fill_n(new_finish, fill_len, x);
        if (start) free_802134fc(start);
        set(new_start, new_finish, new_start + len);
    }
    void push_back(const T &x) {
        if (finish != limit) { if (finish) *finish = x; ++finish; }
        else insert_overflow(finish, x, VTrue(), 1, true);
    }
};
template<class E, int N> struct Pool {
    SVec<E *> chunks; E **cur; int pos;
    E *acquire() {
        if (pos == N) {
            ++cur;
            if (cur == chunks.finish) {
                chunks.push_back(new E[N]);
                cur = chunks.finish - 1;
            }
            pos = 0;
        }
        return *cur + pos++;
    }
};
struct Block { void *next; void *key; float z; unsigned n : 16; unsigned mark : 9; unsigned current : 7; };
struct List { Slots<Block *> items; int kind; };
struct Elt;
struct Source;
struct SourceTable { char u24[24]; const Matrix *(*matrix)(Source *); };
struct Source { SourceTable *table; };
extern "C" Block *w3d_cx10b_arena_allocate_existing_80209d50(void *, unsigned);
struct Elt { char u[20]; Matrix m; };
struct Self {
    char u48[48]; int a48; int a52; const Matrix *m56; char u60[104]; Elt *a164; Elt *a168; Source *source;
    char u176[4]; Pool<Elt2, 512> pool; char u204[24]; void *a228; char arena[8];
    Slots<Elt2 *> c; char u252[12]; int current; Slots<Elt *> e; unsigned short mark; char u282[6]; List *lists;
};
extern "C" void w3d_d28e_add_draw_block_801aa15c(Self *self, int index, void *key)
{
    List *list = &self->lists[index];
    if (list->kind == 3) return;
    if (self->e[self->mark] != self->a164) {
        if (self->a164 != self->a168) {
            self->a164->m = *self->source->table->matrix(self->source);
            self->e.push_back(self->a164);
            self->mark = self->e.size() - 1;
        } else self->mark = 0;
    }
    if (self->a48 != self->a52) {
        Elt2 *e = self->pool.acquire();
        e->m = *self->m56;
        self->c.push_back(e);
        self->a52 = self->a48;
    }
    int n = self->c.size() - 1;
    Block *b = w3d_cx10b_arena_allocate_existing_80209d50(self->arena, 16);
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
    b->next = self->a228;
    list->items.push_back(b);
}
