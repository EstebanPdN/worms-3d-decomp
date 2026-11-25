// (Worms 3D GameCube PAL, 0x801e925c).
//
// Renumbers the class registry at 0x8045e080. Each registered class with a
// wanted index keeps it, the rest take free slots searched with 0x80356934.
// If any index moved, the table is rebuilt in the new order, moved classes
// are told their index (0x801e9090), the hook list of 0x801ea954 runs under
// its lock, and 0x801e80f0 is called. The allocator 0x80212fd4 is declared by
// its C name malloc: the compiler treats its result as unaliased, which is why
// the zero fill of a new array hoists its load past the stores.

extern "C" void *w3d_d24k_heap_resize_80213750(void *, unsigned);
extern "C" void *malloc(unsigned);
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
            char *data = (char *)malloc(bytes);
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
            char *data = (char *)malloc(bytes);
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
            char *data = (char *)malloc(bytes);
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
    Array() { }
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
        begin = (char *)malloc(bytes);
        cap = end = begin + bytes;
        memcpy_802eee50(begin, o.begin, bytes);
    }
    ~Array() { if (begin) free_802134fc(begin); }
    void grow(unsigned n) {
        unsigned used = end - begin;
        unsigned c = cap - begin;
        unsigned bytes = v_max((int)(c + n), (int)(c + (c >> 1))) * sizeof(T);
        char *data = (char *)malloc(bytes);
        if (begin) { memcpy_802eee50(data, begin, v_min(bytes, used)); free_802134fc(begin); }
        begin = data; end = data + used; cap = data + bytes;
    }
};
template<class T, class V> inline void v_fill_(T *, T *, const V &);
template<class A> inline void v_swap(A &a, A &b) { A t(a); a = b; b = t; }
struct Obj { char u[32]; unsigned index : 10; unsigned rest : 22; };
struct Info { char u[4]; unsigned wanted; char pad[0]; };
struct Info2 { char u[6]; unsigned short id; };

struct Lockable { virtual void v8(); virtual void retain(); virtual void release(); };
struct Hooked { virtual void v8(); virtual void call(); };
struct ListNode { ListNode *next; ListNode *prev; Hooked *obj; };
struct ListIter {
    ListNode *node;
    ListIter(ListNode *n) : node(n) { }
    ListIter(const ListIter &o) : node(o.node) { }
    bool operator!=(const ListIter &o) const { return node != o.node; }
};
struct CIter { ListNode *node; CIter(const ListIter &i) : node(i.node) { } bool operator!=(CIter o) const { return node != o.node; } Hooked *get() const { return node->obj; } ListNode *next() const { return node->next; } void set(ListNode *n) { node = n; } };
struct HookList { char u[4]; ListNode *head; ListIter begin() { return ListIter(head->next); } ListIter end() { return ListIter(head); } };
struct Registry : Lockable { HookList hooks; };
struct Lock { Lockable *p; Lock(Lockable *q) : p(q) { p->retain(); } Lock(const Lock &o) : p(o.p) { } ~Lock() { p->release(); } };
extern Array<Obj *> lbl_8045e080;
extern "C" void *f5c_search_801e8ff8(Obj *);
extern "C" int *w3d_find_80356934(int *, int *, const int *);
extern "C" void w3d_s21_set_class_801e9090(Obj *, int);
extern "C" Registry *w3d_local_static_801ea954();
extern "C" void w3d_auto_801e80f0(int);
inline void call_hooks(CIter first, CIter last) {
    while (first != last) {
        ListNode *next = first.next();
        first.get()->call();
        first.set(next);
    }
}
extern "C" void w3d_d40e_renumber_classes_801e925c()
{
    unsigned n = lbl_8045e080.size();
    unsigned n0 = n;
    Array<unsigned short> map(n);
    Array<int> used(n);
    used.assign();
    int idx = 0;
    int changed = 0;
    for (Obj **it = lbl_8045e080.first(), **e = lbl_8045e080.last(); it != e; ++it, ++idx) {
        int none = -1;
        if (*it != 0) {
            char *info = (char *)f5c_search_801e8ff8(*it);
            if (info != 0) {
                map[idx] = ((Info2 *)info)->id;
                unsigned v = ((Info *)info)->wanted;
                if (v >= n) {
                    n = v + 1;
                    used.resize(n);
                }
                used[((Info *)info)->wanted] = 1;
                if (idx != ((Info *)info)->wanted) changed = 1;
            } else map[idx] = none;
        } else map[idx] = none;
    }
    lbl_8045e080.resize(n);
    int i = n0 - 1;
    if (i >= 0) { int one = 1; do {
        if (map[i] == 0xffff) {
            if (used[i] == 0) {
                used[i] = one;
                map[i] = i;
            } else {
                int none = 0;
                changed = 1;
                int *p = w3d_find_80356934(used.first(), used.last(), &none);
                *p = one;
                map[i] = p - used.first();
            }
        }
    } while (--i >= 0); }
    if (changed) {
        Array<Obj *> old(n);
        old.assign();
        for (int j = 0; j < (int)n0; j++) old[map[j]] = lbl_8045e080[j];
        v_swap(old, lbl_8045e080);
        for (int k = 0; k < (int)n; k++) {
            Obj *o = lbl_8045e080[k];
            if (old[k] != o && o) w3d_s21_set_class_801e9090(o, k);
        }
        {
            Registry *r = w3d_local_static_801ea954();
            Lock lock(r);
            HookList &hooks = r->hooks;
            CIter it = hooks.begin();
            CIter stop = hooks.end();
            while (it != stop) {
                ListNode *next = it.next();
                it.get()->call();
                it.set(next);
            }
        }
        w3d_auto_801e80f0(0);
    }
}
