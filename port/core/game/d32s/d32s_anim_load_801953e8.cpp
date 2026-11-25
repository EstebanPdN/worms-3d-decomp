#include "w3d_ptr.h"
#line 1 "d32s_anim_load_801953e8.cpp"
/* GWMP8P rev0 0x801953e8. Creates the file's property reader once, then resolves every prototype slot through it
 * from the name before '|' and then the whole name (trace text: AnimInstanceImpl.cpp (236)), sizing the real
 * STLport 4.5.3 binding and weight vectors first. Each failure returns 0x80004005 after dropping a name copy;
 * its trace call is compiled out. Names and field meanings are inferred. */
#include "compat/stlport_sn_oom.h"
#include "compat/module_allocator.h"
#include <vector>
extern "C" void w3d_string_base_init(Ptr32<void>);
extern "C" void w3d_string_base_finish(Ptr32<void>);
extern "C" Ptr32<unsigned short> w3d_string_header(Ptr32<void>);
extern "C" void w3d_string_release(Ptr32<void>);
struct D32sAnimString {
    Ptr32<char> text;
    unsigned len() const { return ((Ptr32<unsigned short>)text)[-2]; }
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
struct D32sAnimReader { void w3d_r_s0() __asm__(W3D_SYM("_ZN14D32sAnimReader2s0Ev")); void w3d_r_retain() __asm__(W3D_SYM("_ZN14D32sAnimReader6retainEv")); void w3d_r_release() __asm__(W3D_SYM("_ZN14D32sAnimReader7releaseEv")); void w3d_r_s3() __asm__(W3D_SYM("_ZN14D32sAnimReader2s3Ev")); void w3d_r_set_object(Ptr32<D32sAnimObj>) __asm__(W3D_SYM("_ZN14D32sAnimReader10set_objectEP11D32sAnimObj")); void w3d_r_s5() __asm__(W3D_SYM("_ZN14D32sAnimReader2s5Ev")); void w3d_r_s6() __asm__(W3D_SYM("_ZN14D32sAnimReader2s6Ev")); void w3d_r_s7() __asm__(W3D_SYM("_ZN14D32sAnimReader2s7Ev")); void w3d_r_s8() __asm__(W3D_SYM("_ZN14D32sAnimReader2s8Ev")); void w3d_r_s9() __asm__(W3D_SYM("_ZN14D32sAnimReader2s9Ev")); void w3d_r_select(Ptr32<const char>) __asm__(W3D_SYM("_ZN14D32sAnimReader6selectEPKc")); Ptr32<D32sAnimObj> w3d_r_get() __asm__(W3D_SYM("_ZN14D32sAnimReader3getEv"));  __attribute__((always_inline)) inline void s0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D32sAnimReader, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void retain() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D32sAnimReader, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D32sAnimReader, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D32sAnimReader, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void set_object(Ptr32<D32sAnimObj> w3d_a0) { ((void (*)(w3d_u32, Ptr32<D32sAnimObj>))w3d::vfn(this->w3d_vptr_D32sAnimReader, 6))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void s5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D32sAnimReader, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D32sAnimReader, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D32sAnimReader, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D32sAnimReader, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D32sAnimReader, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void select(Ptr32<const char> w3d_a0) { ((void (*)(w3d_u32, Ptr32<const char>))w3d::vfn(this->w3d_vptr_D32sAnimReader, 12))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline Ptr32<D32sAnimObj> get() { return ((Ptr32<D32sAnimObj> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D32sAnimReader, 13))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_D32sAnimReader; };
struct D32sAnimReaderRef { Ptr32<D32sAnimReader> p; template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((D32sAnimReader *)w3d_p.get()); }
 D32sAnimReaderRef &operator=(D32sAnimReader *q) { if (q) q->retain(); if (p) p->release(); p = q; return *this; } };
extern "C" Ptr32<D32sAnimReader> w3d_s10_service_forward_8020b680(Ptr32<void>);
extern char lbl_804164c0[];
extern char lbl_804b0640;
extern char lbl_803a834c[];
extern "C" void w3d_trace_stub_80347324(Ptr32<void>, Ptr32<const char>, ...);
extern "C" void w3d_cx11b_string_truncate_8020c3a0(Ptr32<void>, unsigned);
struct D32sAnimTag { short a, b; unsigned int kind:8; unsigned int value:24; };
struct D32sAnim {
    char u0[24]; D32sAnimWeights weights; char u40[16 - sizeof(D32sAnimWeights) + 16]; D32sAnimBindings bindings; Ptr32<D32sAnimProto> proto; D32sAnimReaderRef reader; char u80[44]; D32sAnimHandle owner;
    int load(Ptr32<D32sAnimObj> obj);
};
int D32sAnim::load(Ptr32<D32sAnimObj> obj) {
    if (!reader.p) reader = w3d_s10_service_forward_8020b680(lbl_804164c0);
    if (!proto) return 0x80004005;
    Ptr32<D32sAnimSlot> s = proto->first;
    Ptr32<D32sAnimSlot> end = proto->last;
    unsigned n = end - s;
    bindings.resize(n);
    weights.resize(n);
    Ptr32<D32sAnimBinding> b = bindings.begin();
    for (; s != end; s++, b++) {
        D32sAnimString key(s->name);
        unsigned pos = 0;
        while (pos < key.len() && key.text[pos] != '|') pos++;
        w3d_cx11b_string_truncate_8020c3a0(&key, pos);
        reader.p->select(key.text);
        reader.p->set_object(obj);
        Ptr32<D32sAnimObj> t = reader.p->get();
        if (!t) {
            D32sAnimString name(s->name);
            return 0x80004005;
        }
        reader.p->select(s->name.text);
        reader.p->set_object(t);
        t = reader.p->get();
        if (!t) {
            D32sAnimString name(s->name);
            return 0x80004005;
        }
        if (s->flags & 1) t = t->base;
        else if (s->flags & 2) t = t->base->outer;
        Ptr32<D32sAnimProp> prop = w3d_s21_vector_get_801e9db8(t->list(), s->index);
        if (!prop) {
            w3d_trace_stub_80347324(&lbl_804b0640, lbl_803a834c, s->index, w3d::VA(s->name.text));
            return 0x80004005;
        }
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
        Ptr32<D32sAnimTag> tag = (Ptr32<D32sAnimTag>)((Ptr32<char>)t + 4);
        tag->kind = (tag->kind | 8) & ~1;
    }
    owner = obj;
    return 0;
}


