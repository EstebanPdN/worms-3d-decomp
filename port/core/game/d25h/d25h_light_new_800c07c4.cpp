#include "w3d_ptr.h"
#line 1 "d25h_light_new_800c07c4.cpp"
// Light allocation (Worms 3D GameCube PAL, 0x800c07c4, 2112 bytes).
//
// Lights are 60-byte records in an STLport-shaped vector (model:
// d24h_pool_erase_800c56b8; the non-trivial element type goes through the full
// uninitialized_copy and _Destroy layers). Field names are inferred. The bank's
// add call returns a value; a void prototype changes the argument move order.

extern "C" Ptr32<void> fn_80212fd4(unsigned);
extern "C" Ptr32<void> fn_803413d8(unsigned);
extern "C" void fn_802134fc(Ptr32<void>);
extern "C" Ptr32<void> fn_802eee50(Ptr32<void>, Ptr32<const void>, unsigned, ...);
inline void *operator new(__SIZE_TYPE__, void *place) throw() { return place; }
template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &Min(const T &a, const T &b) { return b < a ? b : a; }
template <class T> struct Array {
    Ptr32<T> start; Ptr32<T> finish; Ptr32<T> capacity;
    Ptr32<T> begin() { return start; }
    Ptr32<T> end() { return finish; }
    T &operator[](unsigned i) { return start[i]; }
    void Grow(Ptr32<T> f) {
        unsigned size = (Ptr32<char>)f - (Ptr32<char>)start;
        unsigned used = (Ptr32<char>)f - (Ptr32<char>)start;
        int want = used + 1;
        int more = used + used / 2;
        unsigned bytes = Max(want, more) * sizeof(T);
        Ptr32<T> fresh = (Ptr32<T>)fn_80212fd4(bytes);
        if (start) {
            fn_802eee50(fresh, start, Min(bytes, size));
            fn_802134fc(start);
        }
        start = fresh;
        finish = (Ptr32<T>)((Ptr32<char>)fresh + size);
        capacity = (Ptr32<T>)((Ptr32<char>)fresh + bytes);
    }
    void Add(const T &x) {
        Ptr32<T> f = finish;
        if (f == capacity) Grow(f);
        *finish = x;
        finish++;
    }
};
struct Ids : Array<unsigned short> { int alloc __attribute__((aligned(__alignof__(Array<unsigned short>)))); };
struct Obj;
struct ObjVt { Ptr32<void> u[3]; Ptr32<void (Ptr32<Obj>)> addref; Ptr32<void (Ptr32<Obj>)> release; };
struct Obj { Ptr32<ObjVt> vt; };
struct Ref {
    Ptr32<Obj> p;
    Ref() { p = 0; }
    Ref(const Ref &o) { p = o.p; if (p) p->vt->addref(p); }
    ~Ref() { if (p) p->vt->release(p); }
    int &Active() { return *(Ptr32<int>)((Ptr32<char>)p + 144); }
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Obj *)w3d_p.get()); }
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
template <class T> inline Ptr32<T> UCopy(T *first, T *last, T *out) {
    Ptr32<T> cur = out;
    for (; first != last; ++first, ++cur) Construct(w3d::R(cur), *first);
    return cur;
}
template <class T> inline Ptr32<T> UFill(T *out, unsigned n, const T &x) {
    Ptr32<T> cur = out;
    for (; n > 0; --n, ++cur) Construct(w3d::R(cur), x);
    return cur;
}
struct VFalse { char w3d_empty; };
template <class T> inline void DestroyOne(T *p) { p->~T(); }
template <class T> inline void DestroyAux(T *first, T *last) { for (; first != last; ++first) DestroyOne(w3d::R(first)); }
template <class T> inline void Destroy(T *first, T *last) { DestroyAux(w3d::R(first), w3d::R(last)); }
template <class T> struct VAlloc {
    static Ptr32<void> allocate_bytes(unsigned n) {
        Ptr32<void> p = fn_80212fd4(n);
        if (p == 0) p = fn_803413d8(n);
        return p;
    }
    Ptr32<T> allocate(unsigned n) { return n ? (Ptr32<T>)allocate_bytes(n * sizeof(T)) : 0; }
    void deallocate(Ptr32<T> p, unsigned) { if (p) fn_802134fc(p); }
 char w3d_empty; };
template <class T> struct VEnd : VAlloc<T> { Ptr32<T> data __attribute__((aligned(__alignof__(VAlloc<T>)))); };
template <class T> struct Vector {
    Ptr32<T> start;
    Ptr32<T> finish;
    VEnd<T> end_of_storage;
    unsigned size() const { return finish - start; }
    void clear_all() {
        Destroy(w3d::R(start), w3d::R(finish));
        end_of_storage.deallocate(start, end_of_storage.data - start);
    }
    void set(Ptr32<T> s, Ptr32<T> f, Ptr32<T> e) { start = s; finish = f; end_of_storage.data = e; }
    void insert_overflow(Ptr32<T> pos, const T &x, const VFalse &, unsigned fill_len, bool atend) {
        const unsigned old_size = size();
        const unsigned len = old_size + Max(old_size, fill_len);
        Ptr32<T> new_start = end_of_storage.allocate(len);
        Ptr32<T> new_finish = new_start;
        new_finish = UCopy(w3d::R(start), w3d::R(pos), w3d::R(new_start));
        if (fill_len == 1) { Construct(w3d::R(new_finish), x); ++new_finish; }
        else new_finish = UFill(w3d::R(new_finish), fill_len, x);
        if (!atend) new_finish = UCopy(w3d::R(pos), w3d::R(finish), w3d::R(new_finish));
        clear_all();
        set(new_start, new_finish, new_start + len);
    }
    void push_back(const T &x) {
        if (finish != end_of_storage.data) { Construct(w3d::R(finish), x); ++finish; }
        else insert_overflow(finish, x, VFalse(), 1, true);
    }
    T &operator[](unsigned i) { return start[i]; }
};
extern Vector<Light> lbl_8043c384;
extern Ids lbl_8043c394;
extern Ids lbl_8043c3a0;
extern int lbl_804aada8;
extern char lbl_80414a90[];
extern "C" Ptr32<Obj> fn_8020b680(Ptr32<const char>);
struct Bank;
struct BankVt { Ptr32<void> u[48]; Ptr32<int (Ptr32<Bank>, Ptr32<const char>, int, int, Ptr32<Obj>)> add; };
struct Bank { Ptr32<BankVt> vt; };
struct Sound { unsigned char u[116]; Ptr32<Bank> bank; };
extern Ptr32<Sound> lbl_804b17ec;
struct Mgr;
struct MgrVt { Ptr32<void> u[22]; Ptr32<void (Ptr32<Mgr>, int)> f88; };
struct Mgr { Ptr32<MgrVt> vt; };
struct Services { unsigned char u[68]; Ptr32<Mgr> mgr; };
extern Ptr32<Services> lbl_804b1788;
extern const char lbl_80382f88[];
extern "C" int fn_803442b4(Ptr32<char>, Ptr32<const char>, ...);
extern "C" unsigned short w3d_d25h_light_new_800c07c4(int type) {
    if (lbl_804aada8 == 0) return 0;
    unsigned short id;
    unsigned n = ((Ptr32<char>)lbl_8043c394.finish - (Ptr32<char>)lbl_8043c394.start) >> 1;
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
        Ptr32<Bank> bank = lbl_804b17ec->bank;
        Ptr32<BankVt> vt = bank->vt;
        fn_803442b4(name, lbl_80382f88, id);
        Ptr32<const char> p = name;
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


