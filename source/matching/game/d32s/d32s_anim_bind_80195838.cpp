/* GWMP8P rev0 0x80195838. Binds an animation instance to an object: sizes the real STLport 4.5.3 binding
 * and weight vectors to the prototype's slot count, resolves each slot's
 * property on the object or its parents, and keeps the object in a retained handle. Fails with
 * 0x80004005 on a null argument or a property with flag bit 0; the failure path copies the slot's name into
 * a string that is dropped (its trace call is compiled out). Names and field meanings are inferred. */
#include "compat/stlport_sn_oom.h"
#include "compat/module_allocator.h"
#include <vector>
extern "C" void w3d_string_base_init(void *);
extern "C" void w3d_string_base_finish(void *);
extern "C" unsigned short *w3d_string_header(void *);
extern "C" void w3d_string_release(void *);
struct D32sAnimString {
    char *text;
    D32sAnimString(const D32sAnimString &o) { w3d_string_base_init(this); text = o.text; ++*w3d_string_header(this); }
    ~D32sAnimString() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct D32sAnimProp { struct Info { char u[7]; unsigned char flags; } *info; };
struct D32sAnimList;
extern "C" D32sAnimProp *w3d_s21_vector_get_801e9db8(D32sAnimList *, unsigned);
extern "C" int w3d_s21_apply_unless_two_801eb240(D32sAnimProp *);
struct D32sAnimObjApi { virtual void s0(); virtual void retain(); virtual void release(); virtual D32sAnimList *list(); };
struct D32sAnimObj : D32sAnimObjApi { char u4[44]; D32sAnimObj *base; char u52[20]; D32sAnimObj *outer; };
struct D32sAnimHandle {
    D32sAnimObj *p;
    D32sAnimHandle() : p(0) {}
    D32sAnimHandle(const D32sAnimHandle &o) : p(o.p) { if (p) p->retain(); }
    ~D32sAnimHandle() { if (p) p->release(); }
    D32sAnimHandle &operator=(D32sAnimObj *q) { if (q) q->retain(); if (p) p->release(); p = q; return *this; }
    D32sAnimHandle &operator=(const D32sAnimHandle &o);
};
struct D32sAnimBinding { D32sAnimHandle handle; unsigned char bound, index, extra, pad; D32sAnimProp *prop; int u12; };
typedef _STL::vector<D32sAnimBinding, ModuleAllocator<D32sAnimBinding> > D32sAnimBindings;
typedef _STL::vector<float, ModuleAllocator<float> > D32sAnimWeights;
template <> void D32sAnimBindings::_M_fill_insert(D32sAnimBinding *, unsigned, const D32sAnimBinding &);
template <> void D32sAnimWeights::_M_fill_insert(float *, unsigned, const float &);
struct D32sAnimSlot { D32sAnimString name; unsigned char index, extra; unsigned short flags; };
struct D32sAnimProto { char u[20]; D32sAnimSlot *first, *last; };
struct D32sAnim {
    char u0[24]; D32sAnimWeights weights; char u40[16 - sizeof(D32sAnimWeights) + 16]; D32sAnimBindings bindings; D32sAnimProto *proto; char u76[48]; D32sAnimHandle owner;
    int bind(D32sAnimObj *obj);
};
int D32sAnim::bind(D32sAnimObj *obj) {
    if (!obj || !proto) return 0x80004005;
    D32sAnimSlot *s = proto->first;
    D32sAnimSlot *end = proto->last;
    unsigned n = end - s;
    bindings.resize(n);
    weights.resize(n);
    D32sAnimBinding *b = bindings.begin();
    for (; s != end; s++, b++) {
        D32sAnimObj *t;
        if (s->flags & 1) t = obj->base;
        else if (s->flags & 2) t = obj->base->outer;
        else t = obj;
        D32sAnimProp *prop = w3d_s21_vector_get_801e9db8(t->list(), s->index);
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
