// (Worms 3D GameCube PAL, 0x801a8df0).
//
// Start a material for a source: copies +168 to +164, clears counters, reads
// the source's count and matrix through its table, updates the frustum at
// +64 through 0x801a9f78, takes the pair count through 0x801f5da0, then
// finds the matrix among the elements at +252 by a 64-byte compare. A new
// matrix takes an element from the 32-per-chunk pool at +204 and is
// appended. The index goes to +264. Returns 0.

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
struct Matrix { int w[16]; };
struct Elt;
struct Type { char u[32]; unsigned index : 10; unsigned rest : 22; };
extern Type lbl_80363c44[];
extern "C" int w3d_ctor_801bdfe4(Elt *, unsigned);
struct Elt {
    char u[20]; Matrix m;
    Elt() { w3d_ctor_801bdfe4(this, lbl_80363c44->index); }
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
    unsigned size() const { return finish - start; }
    void set(T *s, T *f, T *e) { start = s; finish = f; limit = e; }
    static void *allocate_bytes(unsigned n) {
        void *p = alloc_80212fd4(n);
        if (p == 0) p = w3d_handle_storage_fallback_803413d8(n);
        return p;
    }
    void insert_overflow(T *pos, const T &x, const VTrue &, unsigned fill_len, bool atend) {
        const unsigned old_size = size();
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
struct Pool {
    SVec<Elt *> chunks; Elt **cur; int pos;
    Elt *acquire(const Matrix &m) {
        if (pos == 32) {
            ++cur;
            if (cur == chunks.finish) {
                chunks.push_back(new Elt[32]);
                cur = chunks.finish - 1;
            }
            pos = 0;
        }
        Elt *r = *cur + pos++;
        r->m = m;
        return r;
    }
};
struct Source;
struct SourceTable { char u24[24]; int (*count)(Source *); char u28[4]; const Matrix *(*matrix)(Source *); void *(*extra)(Source *); };
struct Source { SourceTable *table; };
extern "C" int w3d_k5b_pairs_cancel_801f5da0(void *);
extern "C" void f8c_frustum_801a9f78(struct Self *, const Matrix *, void *);
struct Self {
    char u[44]; int a44; int a48; int a52; int count56; int pairs60; char box64[100]; int a164; int a168; Source *source;
    char u176[28]; Pool pool; char u228[24]; Slots<Elt *> elts; int current; char u268[56]; int a324;
};
extern "C" int w3d_d28e_begin_material_801a8df0(Self *self)
{
    Source *s = self->source;
    self->a164 = self->a168;
    self->a324 = 0;
    self->count56 = 0;
    self->count56 = s->table->count(s);
    self->a48 = 0;
    self->a44 = -1;
    self->a52 = -1;
    const Matrix *m = s->table->matrix(s);
    f8c_frustum_801a9f78(self, m, self->box64);
    self->pairs60 = w3d_k5b_pairs_cancel_801f5da0(s->table->extra(s));
    int idx = 0;
    bool found = false;
    Elt **last = (Elt **)self->elts.end;
    for (Elt **it = (Elt **)self->elts.begin; it != last; ++it, ++idx) {
        if (memcmp_802eedc0(m, &(*it)->m, 64) == 0) { found = true; break; }
    }
    if (!found) {
        Elt *e = self->pool.acquire(*m);
        idx = self->elts.size();
        self->elts.push_back(e);
    }
    self->current = idx;
    return 0;
}
