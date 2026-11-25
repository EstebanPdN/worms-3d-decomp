#include "w3d_ptr.h"
#line 1 "d31e_init_actor_hooks_801e7658.cpp"
// (Worms 3D GameCube PAL, 0x801e7658).
//
// Sets up an actor's per-class state: when the object owns itself, sizes the
// hook and state arrays to the global class list (filling hooks with
// 0x801e716c) and copies them otherwise from the owner, then for each
// interface of kind 5 matching its type walks the null-terminated 16-byte
// entry table, finds the class index with 0x801e8f64 and, when the entry's
// mask is enabled, registers the hook through 0x801e7270. Finally visits
// actor types to fill their values through each instance table. Names are
// inferred.

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
extern "C" int memcmp_802eedc0(Ptr32<const void>, Ptr32<const void>, unsigned);
struct Entry { Ptr32<void> guid; Ptr32<void> a; Ptr32<void> b; unsigned char mask; Ptr32<void> valid() const { return guid; } };
struct Item { char u[24]; Ptr32<Entry> entries; };
struct Iface { char u[12]; Ptr32<void> guid; };
struct Iter;
extern "C" Ptr32<Iter> w3d_d25e_find_interface_801fca00(Ptr32<Iter>, int, Ptr32<const void>);
struct Iter {
    Ptr32<Ptr32<Iface>> cur; Ptr32<Ptr32<Iface>> last; Ptr32<void> guid; int extra;
    Iter() {}
    Iter(int i, Ptr32<const void> k) { w3d_d25e_find_interface_801fca00(this, i, k); }
    Iter &ToEnd() { cur = last; return *this; }
    Ptr32<Iface> operator*() const { return *cur; }
    bool operator!=(const Iter &o) const { return cur != o.cur; }
    Iter &operator++() {
        if (cur != last) {
            do {
                Ptr32<Ptr32<Iface>> p = cur;
                cur = p + 1;
                if (cur == last) break;
            } while (memcmp_802eedc0(cur[0]->guid, guid, 16) != 0);
        }
        return *this;
    }
};
inline Iter end_of(Ptr32<const void> k) { Iter t(5, k); t.cur = t.last; return t; }
struct Self;
struct Inst;
struct InstTable { char u[40]; Ptr32<Ptr32<void> (Ptr32<Inst>)> get; };
struct Inst { Ptr32<InstTable> table; };
struct Node { char u[24]; Ptr32<void> value; Ptr32<Inst> inst; };
extern Slots <Ptr32<void> > lbl_8045e080;
struct Self { char u[20]; Ptr32<Self> owner; char u24[28]; Slots<Hook> hooks; Slots<unsigned char> states; };
extern unsigned lbl_804b18dc;
extern "C" Ptr32<void> w3d_auto_801fff3c(Ptr32<Self>);
extern "C" int w3d_s21_find_item_class_801e8f64(Ptr32<void>, Ptr32<unsigned int>);
extern "C" void fn_801e7270(Ptr32<Self>, unsigned, Ptr32<void>, int);
extern "C" Ptr32<char> w3d_actor_type_first_8020fe00(Ptr32<Self>);
extern "C" Ptr32<char> w3d_actor_type_next_8020fe18(Ptr32<Self>, Ptr32<char>);
extern "C" int w3d_d31e_init_actor_hooks_801e7658(Ptr32<Self> self)
{
    Ptr32<Self> owner = self->owner;
    if (owner == self) {
        unsigned count = lbl_8045e080.size();
        self->hooks.resize(count, (Hook)fn_801e716c);
        self->states.resize(count);
        v_fill(w3d::R(self->hooks.first()), w3d::R(self->hooks.last()), (Hook)fn_801e716c);
        v_fill(w3d::R(self->states.first()), w3d::R(self->states.last()), 0);
    } else {
        self->hooks = owner->hooks;
        unsigned n = owner->states.size();
        self->states.resize(n);
        for (unsigned i = 0; i < n; i++) {
            if (owner->states[i] == 2) self->states[i] = 2;
            else self->states[i] = 0;
        }
    }
    Iter it;
    w3d_d25e_find_interface_801fca00(&it, 5, w3d_auto_801fff3c(self));
    Iter last = end_of(w3d_auto_801fff3c(self));
    while (it != last) {
        Ptr32<Entry> e = ((Ptr32<Item>)*it)->entries;
        while (e->valid()) {
            unsigned index;
            if (w3d_s21_find_item_class_801e8f64(e->guid, &index) != 0) { e++; continue; }
            if ((e->mask & lbl_804b18dc) == e->mask)
                fn_801e7270(self, index, e->a, (int)w3d::H(e->b));
            e++;
        }
        ++it;
    }
    for (Ptr32<char> t = w3d_actor_type_first_8020fe00(self); t; t = w3d_actor_type_next_8020fe18(self, t)) {
        Ptr32<Node> node = t ? w3d::R((Ptr32<Node>)(t + 4)) : 0;
        node->value = node->inst->table->get(node->inst);
    }
    return 0;
}


