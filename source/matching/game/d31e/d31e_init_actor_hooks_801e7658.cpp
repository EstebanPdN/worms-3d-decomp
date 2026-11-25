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
extern "C" int memcmp_802eedc0(const void *, const void *, unsigned);
struct Entry { void *guid; void *a; void *b; unsigned char mask; void *valid() const { return guid; } };
struct Item { char u[24]; Entry *entries; };
struct Iface { char u[12]; void *guid; };
struct Iter;
extern "C" Iter *w3d_d25e_find_interface_801fca00(Iter *, int, const void *);
struct Iter {
    Iface **cur; Iface **last; void *guid; int extra;
    Iter() {}
    Iter(int i, const void *k) { w3d_d25e_find_interface_801fca00(this, i, k); }
    Iter &ToEnd() { cur = last; return *this; }
    Iface *operator*() const { return *cur; }
    bool operator!=(const Iter &o) const { return cur != o.cur; }
    Iter &operator++() {
        if (cur != last) {
            do {
                Iface **p = cur;
                cur = p + 1;
                if (cur == last) break;
            } while (memcmp_802eedc0(cur[0]->guid, guid, 16) != 0);
        }
        return *this;
    }
};
inline Iter end_of(const void *k) { Iter t(5, k); t.cur = t.last; return t; }
struct Self;
struct Inst;
struct InstTable { char u[40]; void *(*get)(Inst *); };
struct Inst { InstTable *table; };
struct Node { char u[24]; void *value; Inst *inst; };
extern Slots<void *> lbl_8045e080;
struct Self { char u[20]; Self *owner; char u24[28]; Slots<Hook> hooks; Slots<unsigned char> states; };
extern unsigned lbl_804b18dc;
extern "C" void *w3d_auto_801fff3c(Self *);
extern "C" int w3d_s21_find_item_class_801e8f64(void *, unsigned *);
extern "C" void fn_801e7270(Self *, unsigned, void *, int);
extern "C" char *w3d_actor_type_first_8020fe00(Self *);
extern "C" char *w3d_actor_type_next_8020fe18(Self *, char *);
extern "C" int w3d_d31e_init_actor_hooks_801e7658(Self *self)
{
    Self *owner = self->owner;
    if (owner == self) {
        unsigned count = lbl_8045e080.size();
        self->hooks.resize(count, (Hook)fn_801e716c);
        self->states.resize(count);
        v_fill(self->hooks.first(), self->hooks.last(), (Hook)fn_801e716c);
        v_fill(self->states.first(), self->states.last(), 0);
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
        Entry *e = ((Item *)*it)->entries;
        while (e->valid()) {
            unsigned index;
            if (w3d_s21_find_item_class_801e8f64(e->guid, &index) != 0) { e++; continue; }
            if ((e->mask & lbl_804b18dc) == e->mask)
                fn_801e7270(self, index, e->a, (int)e->b);
            e++;
        }
        ++it;
    }
    for (char *t = w3d_actor_type_first_8020fe00(self); t; t = w3d_actor_type_next_8020fe18(self, t)) {
        Node *node = t ? (Node *)(t + 4) : 0;
        node->value = node->inst->table->get(node->inst);
    }
    return 0;
}
