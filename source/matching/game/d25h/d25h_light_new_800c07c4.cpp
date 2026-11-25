// Light allocation (Worms 3D GameCube PAL, 0x800c07c4, 2112 bytes).
//
// Lights are 60-byte records in an STLport-shaped vector (model:
// d24h_pool_erase_800c56b8; the non-trivial element type goes through the full
// uninitialized_copy and _Destroy layers). Field names are inferred. The bank's
// add call returns a value; a void prototype changes the argument move order.

extern "C" void *fn_80212fd4(unsigned);
extern "C" void *fn_803413d8(unsigned);
extern "C" void fn_802134fc(void *);
extern "C" void *fn_802eee50(void *, const void *, unsigned, ...);
inline void *operator new(unsigned int, void *place) throw() { return place; }
template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &Min(const T &a, const T &b) { return b < a ? b : a; }
template <class T> struct Array {
    T *start, *finish, *capacity;
    T *begin() { return start; }
    T *end() { return finish; }
    T &operator[](unsigned i) { return start[i]; }
    void Grow(T *f) {
        unsigned size = (char *)f - (char *)start;
        unsigned used = (char *)f - (char *)start;
        int want = used + 1;
        int more = used + used / 2;
        unsigned bytes = Max(want, more) * sizeof(T);
        T *fresh = (T *)fn_80212fd4(bytes);
        if (start) {
            fn_802eee50(fresh, start, Min(bytes, size));
            fn_802134fc(start);
        }
        start = fresh;
        finish = (T *)((char *)fresh + size);
        capacity = (T *)((char *)fresh + bytes);
    }
    void Add(const T &x) {
        T *f = finish;
        if (f == capacity) Grow(f);
        *finish = x;
        finish++;
    }
};
struct Ids : Array<unsigned short> { int alloc; };
struct Obj;
struct ObjVt { void *u[3]; void (*addref)(Obj *); void (*release)(Obj *); };
struct Obj { ObjVt *vt; };
struct Ref {
    Obj *p;
    Ref() { p = 0; }
    Ref(const Ref &o) { p = o.p; if (p) p->vt->addref(p); }
    ~Ref() { if (p) p->vt->release(p); }
    int &Active() { return *(int *)((char *)p + 144); }
    void operator=(Obj *o) { if (o) o->vt->addref(o); if (p) p->vt->release(p); p = o; }
};
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Plain { int a, b, c; };
struct Light {
    Vec3 pos;
    Ref a;
    Ref b;
    float f20;
    int kind;
    unsigned char state;
    float f32, f36, f40, f44;
    Plain v48;
    Light();
};
extern Vec3 lbl_8045e788;
inline Light::Light() {
    pos = lbl_8045e788;
    b = 0;
    f20 = 0.0f;
    kind = 62;
    state = 0;
    f32 = 0.0f;
}
template <class T> inline void Construct(T *p, const T &x) { new (p) T(x); }
template <class T> inline T *UCopy(T *first, T *last, T *out) {
    T *cur = out;
    for (; first != last; ++first, ++cur) Construct(cur, *first);
    return cur;
}
template <class T> inline T *UFill(T *out, unsigned n, const T &x) {
    T *cur = out;
    for (; n > 0; --n, ++cur) Construct(cur, x);
    return cur;
}
struct VFalse {};
template <class T> inline void DestroyOne(T *p) { p->~T(); }
template <class T> inline void DestroyAux(T *first, T *last) { for (; first != last; ++first) DestroyOne(first); }
template <class T> inline void Destroy(T *first, T *last) { DestroyAux(first, last); }
template <class T> struct VAlloc {
    static void *allocate_bytes(unsigned n) {
        void *p = fn_80212fd4(n);
        if (p == 0) p = fn_803413d8(n);
        return p;
    }
    T *allocate(unsigned n) { return n ? (T *)allocate_bytes(n * sizeof(T)) : 0; }
    void deallocate(T *p, unsigned) { if (p) fn_802134fc(p); }
};
template <class T> struct VEnd : VAlloc<T> { T *data; };
template <class T> struct Vector {
    T *start;
    T *finish;
    VEnd<T> end_of_storage;
    unsigned size() const { return finish - start; }
    void clear_all() {
        Destroy(start, finish);
        end_of_storage.deallocate(start, end_of_storage.data - start);
    }
    void set(T *s, T *f, T *e) { start = s; finish = f; end_of_storage.data = e; }
    void insert_overflow(T *pos, const T &x, const VFalse &, unsigned fill_len, bool atend) {
        const unsigned old_size = size();
        const unsigned len = old_size + Max(old_size, fill_len);
        T *new_start = end_of_storage.allocate(len);
        T *new_finish = new_start;
        new_finish = UCopy(start, pos, new_start);
        if (fill_len == 1) { Construct(new_finish, x); ++new_finish; }
        else new_finish = UFill(new_finish, fill_len, x);
        if (!atend) new_finish = UCopy(pos, finish, new_finish);
        clear_all();
        set(new_start, new_finish, new_start + len);
    }
    void push_back(const T &x) {
        if (finish != end_of_storage.data) { Construct(finish, x); ++finish; }
        else insert_overflow(finish, x, VFalse(), 1, true);
    }
    T &operator[](unsigned i) { return start[i]; }
};
extern Vector<Light> lbl_8043c384;
extern Ids lbl_8043c394;
extern Ids lbl_8043c3a0;
extern int lbl_804aada8;
extern char lbl_80414a90[];
extern "C" Obj *fn_8020b680(const char *);
struct Bank;
struct BankVt { void *u[48]; int (*add)(Bank *, const char *, int, int, Obj *); };
struct Bank { BankVt *vt; };
struct Sound { unsigned char u[116]; Bank *bank; };
extern Sound *lbl_804b17ec;
struct Mgr;
struct MgrVt { void *u[22]; void (*f88)(Mgr *, int); };
struct Mgr { MgrVt *vt; };
struct Services { unsigned char u[68]; Mgr *mgr; };
extern Services *lbl_804b1788;
extern const char lbl_80382f88[];
extern "C" int fn_803442b4(char *, const char *, ...);
extern "C" unsigned short w3d_d25h_light_new_800c07c4(int type) {
    if (lbl_804aada8 == 0) return 0;
    unsigned short id;
    unsigned n = ((char *)lbl_8043c394.finish - (char *)lbl_8043c394.start) >> 1;
    if (n) {
        id = lbl_8043c394[n - 1];
        lbl_8043c394.finish--;
    } else {
        Light tmp;
        lbl_8043c384.push_back(tmp);
        id = lbl_8043c384.size() - 1;
    }
    lbl_8043c384[id].a = fn_8020b680(lbl_80414a90);
    lbl_8043c384[id].a.Active() = 1;
    {
        char name[32];
        Bank *bank = lbl_804b17ec->bank;
        BankVt *vt = bank->vt;
        fn_803442b4(name, lbl_80382f88, id);
        const char *p = name;
        vt->add(bank, p, (unsigned char)type, 0, lbl_8043c384[id].a.p);
    }
    lbl_804b1788->mgr->vt->f88(lbl_804b1788->mgr, type);
    Light &m = lbl_8043c384[id];
    m.pos.x = 0.0f; m.pos.y = 0.0f; m.pos.z = 0.0f;
    lbl_8043c384[id].state = 2;
    lbl_8043c384[id].kind = type;
    lbl_8043c384[id].b = 0;
    lbl_8043c384[id].f20 = 1.0f;
    lbl_8043c384[id].f36 = 1.0f;
    lbl_8043c384[id].f40 = 1.0f;
    lbl_8043c384[id].f44 = 1.0f;
    lbl_8043c3a0.Add(id);
    return id;
}
