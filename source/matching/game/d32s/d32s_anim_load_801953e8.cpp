/* GWMP8P rev0 0x801953e8. Creates the file's property reader once, then resolves every prototype slot through it
 * from the name before '|' and then the whole name (trace text: AnimInstanceImpl.cpp (236)), sizing the real
 * STLport 4.5.3 binding and weight vectors first. Each failure returns 0x80004005 after dropping a name copy;
 * its trace call is compiled out. Names and field meanings are inferred. */
#include "compat/stlport_sn_oom.h"
#include "compat/module_allocator.h"
#include <vector>
extern "C" void w3d_string_base_init(void *);
extern "C" void w3d_string_base_finish(void *);
extern "C" unsigned short *w3d_string_header(void *);
extern "C" void w3d_string_release(void *);
struct D32sAnimString {
    char *text;
    unsigned len() const { return ((unsigned short *)text)[-2]; }
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
struct D32sAnimReader { virtual void s0(); virtual void retain(); virtual void release(); virtual void s3(); virtual void set_object(D32sAnimObj *); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void select(const char *); virtual D32sAnimObj *get(); };
struct D32sAnimReaderRef { D32sAnimReader *p; D32sAnimReaderRef &operator=(D32sAnimReader *q) { if (q) q->retain(); if (p) p->release(); p = q; return *this; } };
extern "C" D32sAnimReader *w3d_s10_service_forward_8020b680(void *);
extern char lbl_804164c0[];
extern char lbl_804b0640;
extern char lbl_803a834c[];
extern "C" void w3d_trace_stub_80347324(void *, const char *, ...);
extern "C" void w3d_cx11b_string_truncate_8020c3a0(void *, unsigned);
struct D32sAnimTag { short a, b; unsigned value : 24; unsigned kind : 8; };
struct D32sAnim {
    char u0[24]; D32sAnimWeights weights; char u40[16 - sizeof(D32sAnimWeights) + 16]; D32sAnimBindings bindings; D32sAnimProto *proto; D32sAnimReaderRef reader; char u80[44]; D32sAnimHandle owner;
    int load(D32sAnimObj *obj);
};
int D32sAnim::load(D32sAnimObj *obj) {
    if (!reader.p) reader = w3d_s10_service_forward_8020b680(lbl_804164c0);
    if (!proto) return 0x80004005;
    D32sAnimSlot *s = proto->first;
    D32sAnimSlot *end = proto->last;
    unsigned n = end - s;
    bindings.resize(n);
    weights.resize(n);
    D32sAnimBinding *b = bindings.begin();
    for (; s != end; s++, b++) {
        D32sAnimString key(s->name);
        unsigned pos = 0;
        while (pos < key.len() && key.text[pos] != '|') pos++;
        w3d_cx11b_string_truncate_8020c3a0(&key, pos);
        reader.p->select(key.text);
        reader.p->set_object(obj);
        D32sAnimObj *t = reader.p->get();
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
        D32sAnimProp *prop = w3d_s21_vector_get_801e9db8(t->list(), s->index);
        if (!prop) {
            w3d_trace_stub_80347324(&lbl_804b0640, lbl_803a834c, s->index, s->name.text);
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
        D32sAnimTag *tag = (D32sAnimTag *)((char *)t + 4);
        tag->kind = (tag->kind | 8) & ~1;
    }
    owner = obj;
    return 0;
}
