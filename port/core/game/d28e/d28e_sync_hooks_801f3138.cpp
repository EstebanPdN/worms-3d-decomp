#include "w3d_ptr.h"
#line 1 "d28e_sync_hooks_801f3138.cpp"
// (Worms 3D GameCube PAL, 0x801f3138).
//
// Build the hook and state tables of a shader-like node. With a source, the
// hook vector is copied from it and each state byte takes the low two bits
// of the source's state plus 64; with the override flag set, both tables are
// sized to the global type table and filled with the default hook 0x801e716c
// and state 128; otherwise the source is taken from the owner, reference
// counted, and the function repeats. It finishes through 0x801f3850 or
// 0x801f39a0.

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
typedef Ptr32<void (void)> Hook;
extern "C" int fn_801e716c();
struct Source;
struct SourceTable { char u12[12]; Ptr32<void (Ptr32<Source>)> add_ref; Ptr32<void (Ptr32<Source>)> release; char u20[20]; Ptr32<Ptr32<void> (Ptr32<Source>)> prepare; };
struct Source { Ptr32<SourceTable> table; char u4[16]; Slots<Hook> hooks; char u32[20]; Slots<unsigned char> states; Ptr32<Source> next; };
struct Owner;
struct OwnerTable { char u20[20]; Ptr32<Ptr32<Owner> (Ptr32<Owner>)> get; };
struct Owner { Ptr32<OwnerTable> table; char u4[44]; Ptr32<Source> source; };
extern Slots <Ptr32<void> > lbl_8045e080;
struct Self { char u[20]; Slots<Hook> hooks; unsigned flags; Ptr32<Source> source; char u40[12]; Slots<unsigned char> states; Ptr32<char> holder; };
extern "C" void fn_801f3850(Ptr32<Self>);
extern "C" void w3d_auto_801f39a0(Ptr32<Self>);
extern "C" Ptr32<void> w3d_d28e_sync_hooks_801f3138(Ptr32<Self> self)
{
    Ptr32<void> result;
top:
    {
        if (self->source) {
            result = self->source->table->prepare(self->source);
            unsigned flags = self->flags;
            if (!(flags & 0x40000000)) { if (flags & 0x20000000) goto done; }
            Ptr32<Source> src = self->source;
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
            v_fill(w3d::R(self->hooks.first()), w3d::R(self->hooks.last()), (Hook)fn_801e716c);
            v_fill(w3d::R(self->states.first()), w3d::R(self->states.last()), 128);
            }
last:
            result = self->hooks.begin;
            goto done;
        }
        Ptr32<Owner> owner = self->holder ? w3d::R((Ptr32<Owner>)(self->holder - 4)) : 0;
        Ptr32<Source> s = owner->table->get(owner)->source;
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


