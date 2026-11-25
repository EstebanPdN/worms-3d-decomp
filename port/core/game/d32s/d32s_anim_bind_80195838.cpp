#include "w3d_ptr.h"
#line 1 "d32s_anim_bind_80195838.cpp"
/* GWMP8P rev0 0x80195838. Binds an animation instance to an object: sizes the real STLport 4.5.3 binding
 * and weight vectors to the prototype's slot count, resolves each slot's
 * property on the object or its parents, and keeps the object in a retained handle. Fails with
 * 0x80004005 on a null argument or a property with flag bit 0; the failure path copies the slot's name into
 * a string that is dropped (its trace call is compiled out). Names and field meanings are inferred. */
#include "compat/stlport_sn_oom.h"
#include "compat/module_allocator.h"
#include <vector>
extern "C" void w3d_string_base_init(Ptr32<void>);
extern "C" void w3d_string_base_finish(Ptr32<void>);
extern "C" Ptr32<unsigned short> w3d_string_header(Ptr32<void>);
extern "C" void w3d_string_release(Ptr32<void>);
struct D32sAnimString {
    Ptr32<char> text;
    D32sAnimString(const D32sAnimString &o) { w3d_string_base_init(this); text = o.text; ++*w3d_string_header(this); }
    ~D32sAnimString() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct D32sAnimProp { struct Info { char u[6]; char w3d_kind; unsigned char flags; }; Ptr32<struct Info> info; };
struct D32sAnimList;
extern "C" Ptr32<D32sAnimProp> w3d_s21_vector_get_801e9db8(Ptr32<D32sAnimList>, unsigned);
extern "C" int w3d_s21_apply_unless_two_801eb240(Ptr32<D32sAnimProp>);
struct D32sAnimObjApi { void w3d_r_s0() __asm__(W3D_SYM("_ZN14D32sAnimObjApi2s0Ev")); void w3d_r_retain() __asm__(W3D_SYM("_ZN14D32sAnimObjApi6retainEv")); void w3d_r_release() __asm__(W3D_SYM("_ZN14D32sAnimObjApi7releaseEv")); Ptr32<D32sAnimList> w3d_r_list() __asm__(W3D_SYM("_ZN14D32sAnimObjApi4listEv"));  __attribute__((always_inline)) inline void s0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D32sAnimObjApi, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void retain() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D32sAnimObjApi, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D32sAnimObjApi, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<D32sAnimList> list() { return ((Ptr32<D32sAnimList> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D32sAnimObjApi, 5))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_D32sAnimObjApi; };
struct D32sAnimObj : D32sAnimObjApi { char u4[44] __attribute__((aligned(__alignof__(D32sAnimObjApi)))); Ptr32<D32sAnimObj> base; char u52[20]; Ptr32<D32sAnimObj> outer; };
struct D32sAnimHandle {
    Ptr32<D32sAnimObj> p;
    D32sAnimHandle() : p(0) {}
    D32sAnimHandle(const D32sAnimHandle &o) : p(o.p) { if (p) p->retain(); }
    ~D32sAnimHandle() { if (p) p->release(); }
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((D32sAnimObj *)w3d_p.get()); }
 D32sAnimHandle &operator=(D32sAnimObj *q) { if (q) q->retain(); if (p) p->release(); p = q; return *this; }
    D32sAnimHandle &operator=(const D32sAnimHandle &o);
};
struct D32sAnimBinding { D32sAnimHandle handle; unsigned char bound, index, extra, pad; Ptr32<D32sAnimProp> prop; int u12; };
typedef _STL::vector<D32sAnimBinding, ModuleAllocator<D32sAnimBinding> > D32sAnimBindings;
typedef _STL::vector<float, ModuleAllocator<float> > D32sAnimWeights;
template <> void D32sAnimBindings::_M_fill_insert(Ptr32<D32sAnimBinding>, unsigned, const D32sAnimBinding &);
template <> void D32sAnimWeights::_M_fill_insert(Ptr32<float>, unsigned, const float &);
struct D32sAnimSlot { D32sAnimString name; unsigned char index, extra; unsigned short flags; };
struct D32sAnimProto { char u[20]; Ptr32<D32sAnimSlot> first; Ptr32<D32sAnimSlot> last; };
struct D32sAnim {
    char u0[24]; D32sAnimWeights weights; char u40[16 - sizeof(D32sAnimWeights) + 16]; D32sAnimBindings bindings; Ptr32<D32sAnimProto> proto; char u76[48]; D32sAnimHandle owner;
    int bind(Ptr32<D32sAnimObj> obj);
};
int D32sAnim::bind(Ptr32<D32sAnimObj> obj) {
    if (!obj || !proto) return 0x80004005;
    Ptr32<D32sAnimSlot> s = proto->first;
    Ptr32<D32sAnimSlot> end = proto->last;
    unsigned n = end - s;
    bindings.resize(n);
    weights.resize(n);
    Ptr32<D32sAnimBinding> b = bindings.begin();
    for (; s != end; s++, b++) {
        Ptr32<D32sAnimObj> t;
        if (s->flags & 1) t = obj->base;
        else if (s->flags & 2) t = obj->base->outer;
        else t = obj;
        Ptr32<D32sAnimProp> prop = w3d_s21_vector_get_801e9db8(t->list(), s->index);
        int bound = prop->info->flags & 1;
        if (bound) {
            D32sAnimString name(s->name);
            return 0x80004005;
        }
        w3d_s21_apply_unless_two_801eb240(prop);
        b->handle = t;
        b->bound = bound;
        b->index = s->index;
        b->extra = s->extra;
        b->prop = prop;
    }
    owner = obj;
    return 0;
}


