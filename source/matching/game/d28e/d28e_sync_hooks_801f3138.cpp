// (Worms 3D GameCube PAL, 0x801f3138).
//
// Build the hook and state tables of a shader-like node. With a source, the
// hook vector is copied from it and each state byte takes the low two bits
// of the source's state plus 64; with the override flag set, both tables are
// sized to the global type table and filled with the default hook 0x801e716c
// and state 128; otherwise the source is taken from the owner, reference
// counted, and the function repeats. It finishes through 0x801f3850 or
// 0x801f39a0.

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
typedef void (*Hook)();
extern "C" int fn_801e716c();
struct Source;
struct SourceTable { char u12[12]; void (*add_ref)(Source *); void (*release)(Source *); char u20[20]; void *(*prepare)(Source *); };
struct Source { SourceTable *table; char u4[16]; Slots<Hook> hooks; char u32[20]; Slots<unsigned char> states; Source *next; };
struct Owner;
struct OwnerTable { char u20[20]; Owner *(*get)(Owner *); };
struct Owner { OwnerTable *table; char u4[44]; Source *source; };
extern Slots<void *> lbl_8045e080;
struct Self { char u[20]; Slots<Hook> hooks; unsigned flags; Source *source; char u40[12]; Slots<unsigned char> states; char *holder; };
extern "C" void fn_801f3850(Self *);
extern "C" void w3d_auto_801f39a0(Self *);
extern "C" void *w3d_d28e_sync_hooks_801f3138(Self *self)
{
    void *result;
top:
    {
        if (self->source) {
            result = self->source->table->prepare(self->source);
            unsigned flags = self->flags;
            if (!(flags & 0x40000000)) { if (flags & 0x20000000) goto done; }
            Source *src = self->source;
            self->hooks = src->hooks;
            unsigned count = self->hooks.size();
            self->states.resize(count);
            for (unsigned i = 0; i < count; i++) self->states[i] = (self->source->states[i] & 3) | 64;
            goto last;
        }
        if (self->flags & 0x40000000) {
            {
            unsigned count = lbl_8045e080.size();
            self->hooks.resize(count, (Hook)fn_801e716c);
            self->states.resize(count);
            v_fill(self->hooks.first(), self->hooks.last(), (Hook)fn_801e716c);
            v_fill(self->states.first(), self->states.last(), 128);
            }
last:
            result = self->hooks.begin;
            goto done;
        }
        Owner *owner = self->holder ? (Owner *)(self->holder - 4) : 0;
        Source *s = owner->table->get(owner)->source;
        if (s) s->table->add_ref(s);
        if (self->source) self->source->table->release(self->source);
        self->source = s;
        goto top;
    }
done:
    if (self->flags & 0x40000000) fn_801f3850(self);
    else w3d_auto_801f39a0(self);
    return result;
}
