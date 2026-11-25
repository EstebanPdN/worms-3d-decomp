#include "w3d_ptr.h"
#line 1 "d32e_purge_unused_801b37cc.cpp"
// (Worms 3D GameCube PAL, 0x801b37cc).
//
// Garbage collects a cache: optionally releases the lists first, then
// repeatedly scans the three object lists and removes every object whose
// reference count is one (probed with AddRef and Release), together with its
// parallel name where it has one, until a full pass removes nothing. Returns
// 0.

extern "C" Ptr32<void> memmove(Ptr32<void>, Ptr32<const void>, unsigned);
struct Obj { void w3d_r_v0() __asm__(W3D_SYM("_ZN3Obj2v0Ev")); void w3d_r_AddRef() __asm__(W3D_SYM("_ZN3Obj6AddRefEv")); int w3d_r_Release() __asm__(W3D_SYM("_ZN3Obj7ReleaseEv"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void AddRef() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int Release() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Obj; };
extern "C" void w3d_string_release_header(Ptr32<void>);
struct Str;
extern "C" void w3d_string_base_finish(Ptr32<Str>);
extern "C" void w3d_string_release(Ptr32<Str>);
struct Str {
    Ptr32<char> p;
    ~Str() { w3d_string_base_finish(this); w3d_string_release(this); }
    Str &operator=(const Str &o) {
        ++*(Ptr32<unsigned short>)(o.p - 6);
        Ptr32<unsigned short> h = (Ptr32<unsigned short>)(p - 6);
        if (--*h == 0) w3d_string_release_header(h);
        p = o.p;
        return *this;
    }
};
static inline Ptr32<Str> Copy(Ptr32<Str> f, Ptr32<Str> l, Ptr32<Str> d) {
    for (int n = l - f; n > 0; --n) { *d = *f; ++f; ++d; }
    return d;
}
struct Names {
    Ptr32<Str> first; Ptr32<Str> last;
    void erase(Ptr32<Str> pos) {
        if (pos + 1 != last) Copy(pos + 1, last, pos);
        --last;
        last->~Str();
    }
};
struct Objs {
    Ptr32<Ptr32<Obj>> first; Ptr32<Ptr32<Obj>> last;
    Ptr32<Ptr32<Obj>> end() { return last; }
    void erase(Ptr32<Ptr32<Obj>> pos) {
        Ptr32<Ptr32<Obj>> n = pos + 1;
        if (n != last) {
            if (last != n) memmove(pos, n, (Ptr32<char>)last - (Ptr32<char>)n);
        }
        --last;
    }
};
struct Arr;
extern "C" void f4c_erase_80210dd8(Ptr32<Arr>, Ptr32<Ptr32<Obj>>, Ptr32<Ptr32<Obj>>);
struct Arr { int count; int u4; Ptr32<Ptr32<Obj>> data; Ptr32<Ptr32<Obj>> begin() { return data; } void Erase(Ptr32<Ptr32<Obj>> p) { f4c_erase_80210dd8(this, p, p + 1); } };
struct Mgr;
extern "C" void w3d_d25e_release_lists_801b4140(Ptr32<Mgr>);
struct Mgr {
    char u0[28];
    Names n1; char u36[8];
    Objs a; char u52[8];
    Arr c;
    Names n2; char u80[8];
    Objs b;
};
extern "C" int w3d_d32e_purge_unused_801b37cc(Ptr32<Mgr> self, int purge)
{
    if (purge) w3d_d25e_release_lists_801b4140(self);
    bool changed;
    bool again;
    do {
        changed = false;
        do {
            again = false;
            Ptr32<Ptr32<Obj>> it = self->a.first;
            Ptr32<Ptr32<Obj>> e = self->a.end();
            for (; it != e; it++) {
                (*it)->AddRef();
                if ((*it)->Release() == 1) {
                    self->n1.erase(self->n1.first + (it - self->a.first));
                    (*it)->Release();
                    self->a.erase(it);
                    again = true;
                    changed = true;
                    break;
                }
            }
        } while (again);
        do {
            again = false;
            Ptr32<Ptr32<Obj>> it = self->b.first;
            Ptr32<Ptr32<Obj>> e = self->b.end();
            for (; it != e; it++) {
                (*it)->AddRef();
                if ((*it)->Release() == 1) {
                    (*it)->Release();
                    self->b.erase(it);
                    again = true;
                    changed = true;
                    break;
                }
            }
        } while (again);
        do {
            again = false;
            Ptr32<Ptr32<Obj>> it = self->c.begin();
            Ptr32<Ptr32<Obj>> e = self->c.begin() + self->c.count;
            for (; it != e; it++) {
                (*it)->AddRef();
                if ((*it)->Release() == 1) {
                    self->c.Erase(it);
                    self->n2.erase(self->n2.first + (it - self->c.begin()));
                    again = true;
                    changed = true;
                    break;
                }
            }
        } while (again);
    } while (changed);
    return 0;
}


