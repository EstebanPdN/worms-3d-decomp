#include "w3d_ptr.h"
#line 1 "d31g_stage_cache_80078f48.cpp"
// GWMP8P rev0 0x80078f48. Finds or creates eight render stages: for four
// keys in the list at +120 and four in the list at +180, searches for an
// object whose first stage is the key and otherwise creates one, attaches
// the fixed objects, grows the parallel arrays, and records the indexes in
// six byte tables. Partial views inferred from the original instructions.
extern "C" Ptr32<void> memcpy_802eee50(Ptr32<void>, Ptr32<const void>, unsigned, ...);
extern "C" Ptr32<void> w3d_alloc_80212fd4(unsigned);
extern "C" void w3d_free_802134fc(Ptr32<void>);
struct Obj;
struct ObjVt { Ptr32<void> u0[3]; Ptr32<void (Ptr32<Obj>)> retain; Ptr32<void (Ptr32<Obj>)> release; };
struct Obj { Ptr32<ObjVt> vt; };
struct Ref {
    Ptr32<Obj> p;
    Ref() { p = 0; }
    Ref(const Ref &o);
    ~Ref() { if (p) p->vt->release(p); }
    Ref &operator=(const Ref &o) { if (o.p) o.p->vt->retain(o.p); if (p) p->vt->release(p); p = o.p; return *this; }
};
template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &Min(const T &a, const T &b) { return b < a ? b : a; }
template <class T> struct Vector {
    Ptr32<T> start; Ptr32<T> finish; Ptr32<T> end;
    int size() const { return finish - start; }
    bool full() const { return finish == end; }
    void grow() {
        unsigned size = (Ptr32<char>)finish - (Ptr32<char>)start;
        int a = size + 1, b = size + (size >> 1);
        unsigned bytes = Max(a, b) * sizeof(T);
        Ptr32<T> n = (Ptr32<T>)w3d_alloc_80212fd4(bytes);
        if (start) { memcpy_802eee50(n, start, Min(bytes, size)); w3d_free_802134fc(start); }
        start = n;
        finish = (Ptr32<T>)((Ptr32<char>)n + size);
        end = (Ptr32<T>)((Ptr32<char>)n + bytes);
    }
    void push_back(const T &v) {
        if (full()) grow();
        *finish = v;
        finish++;
    }
};
extern "C" void w3d_reserve_801f29d0(Ptr32<void>, int);
struct List {
    int count; unsigned short cap, u6; Ptr32<Ptr32<Obj>> data;
    int size() const { return count; }
    Ptr32<Obj> operator[](unsigned i) const { return data[i]; }
    void push(Ptr32<Obj> o) {
        w3d_reserve_801f29d0(this, count + 1);
        int k = count << 2; Ptr32<Ptr32<Obj>> d = data;
        if (o) o->vt->retain(o);
        Ptr32<Obj> old = *(Ptr32<Ptr32<Obj>>)w3d::G((k + (int)w3d::H(d)));
        if (old) old->vt->release(old);
        *(Ptr32<Ptr32<Obj>>)w3d::G((k + (int)w3d::H(d))) = o;
        count++;
    }
};
extern "C" Ptr32<Obj> w3d_create_8020b680(Ptr32<const void>);
extern "C" void w3d_append_801ef174(Ptr32<Obj>, int, int, Ptr32<Obj>);
extern "C" Ptr32<Ptr32<Obj>> w3d_stages_801d0858(Ptr32<Obj>, Ptr32<int>);
extern "C" void w3d_stage_set_801d0898(Ptr32<Obj>, Ptr32<Obj>, int);
extern "C" void w3d_stage_add_801d086c(Ptr32<Obj>, Ptr32<Obj>);
extern "C" Ptr32<void> w3d_heap_802098d8(Ptr32<void>, unsigned);
extern const char lbl_80415b00[];
extern int lbl_804adde4;
extern int lbl_804b17f4;
inline Ptr32<Obj> First(Ptr32<Obj> o) { int n; Ptr32<Ptr32<Obj>> s = w3d_stages_801d0858(o, &n); if (n) return *s; return 0; }
struct Self {
    char u0[60]; List l60; List l72; List l84; List l96; List l108; List l120; List l132; List l144; List l156; List l168; List l180;
    char u192[4]; Ptr32<Obj> o196; char u200[8]; Ptr32<Obj> o208; char u212[4]; Ref o216; char u220[4]; Ptr32<Obj> o224; Ptr32<Obj> o228; Ptr32<Obj> o232; Ptr32<Obj> o236;
    char u240[524]; int n764;
    signed char t768[256], t1024[256], t1280[256], t1536[256], t1792[256], t2048[256];
    Vector<int> v2304, v2316; char u2328[36]; Vector<short> v2364; Vector<int> v2376, v2388; char u2400[36]; Vector<short> v2436;
    Vector <Ptr32<void> > v2448; Vector<short> v2460;
};
extern "C" int w3d_d31g_stage_cache_80078f48(Ptr32<Self> self, Ptr32<Obj> a, Ptr32<Obj> b, Ptr32<Obj> c, Ptr32<Obj> tail, Ptr32<Obj> d) {
    Ptr32<Obj> oa = 0; Ptr32<Obj> ob = 0; Ptr32<Obj> oc = 0; Ptr32<Obj> od = 0; Ptr32<Obj> oe = 0; Ptr32<Obj> of = 0; Ptr32<Obj> og = 0; Ptr32<Obj> oh = 0;
    signed char ia = -1, ib = -1, ic = -1, id = -1, ie = -1, if_ = -1, ig = -1, ih = -1;
    unsigned i;
    for (i = 0; i < self->l120.count; i++) {
        Ptr32<Obj> v = First(self->l120[i]);
        if (v == a) { ia = i; oa = self->l120[i]; }
    }
    Ref h;
    h = self->o216;
    if (!oa) {
        oa = w3d_create_8020b680(lbl_80415b00);
        { int n; w3d_stages_801d0858(oa, &n);
        if (n) w3d_stage_set_801d0898(oa, a, 0); else w3d_stage_add_801d086c(oa, a); }
        w3d_append_801ef174(oa, 28, 3, self->o224);
        w3d_append_801ef174(oa, 28, 3, h.p);
        w3d_append_801ef174(oa, 28, 3, self->o208);
        ia = self->l120.size();
        self->v2304.push_back(0);
        self->v2316.push_back(0);
        self->v2364.push_back(0);
        self->l120.push(oa);
    }
    self->l60.push(oa);
    for (i = 0; i < self->l120.count; i++) {
        Ptr32<Obj> v = First(self->l120[i]);
        if (v == b) { ib = i; ob = self->l120[i]; }
    }
    if (!ob) {
        ob = w3d_create_8020b680(lbl_80415b00);
        { int n; w3d_stages_801d0858(ob, &n);
        if (n) w3d_stage_set_801d0898(ob, b, 0); else w3d_stage_add_801d086c(ob, b); }
        w3d_append_801ef174(ob, 28, 3, self->o224);
        w3d_append_801ef174(ob, 28, 3, h.p);
        w3d_append_801ef174(ob, 28, 3, self->o208);
        ib = self->l120.size();
        self->v2304.push_back(0);
        self->v2316.push_back(0);
        self->v2364.push_back(0);
        self->l120.push(ob);
    }
    self->l84.push(ob);
    for (i = 0; i < self->l120.count; i++) {
        Ptr32<Obj> v = First(self->l120[i]);
        if (v == c) { ic = i; oc = self->l120[i]; }
    }
    if (!oc) {
        oc = w3d_create_8020b680(lbl_80415b00);
        { int n; w3d_stages_801d0858(oc, &n);
        if (n) w3d_stage_set_801d0898(oc, c, 0); else w3d_stage_add_801d086c(oc, c); }
        w3d_append_801ef174(oc, 28, 3, self->o224);
        w3d_append_801ef174(oc, 28, 3, h.p);
        w3d_append_801ef174(oc, 28, 3, self->o208);
        ic = self->l120.size();
        self->v2304.push_back(0);
        self->v2316.push_back(0);
        self->v2364.push_back(0);
        self->l120.push(oc);
    }
    self->l96.push(oc);
    for (i = 0; i < self->l120.count; i++) {
        Ptr32<Obj> v = First(self->l120[i]);
        if (v == d) { id = i; od = self->l120[i]; }
    }
    if (!od) {
        od = w3d_create_8020b680(lbl_80415b00);
        { int n; w3d_stages_801d0858(od, &n);
        if (n) w3d_stage_set_801d0898(od, d, 0); else w3d_stage_add_801d086c(od, d); }
        w3d_append_801ef174(od, 28, 3, self->o224);
        w3d_append_801ef174(od, 28, 3, h.p);
        w3d_append_801ef174(od, 28, 3, self->o208);
        id = self->l120.size();
        self->v2304.push_back(0);
        self->v2316.push_back(0);
        self->v2364.push_back(0);
        self->l120.push(od);
    }
    self->l72.push(od);
    for (i = 0; i < self->l180.count; i++) {
        Ptr32<Obj> v = First(self->l180[i]);
        if (v == a) { ie = i; oe = self->l180[i]; }
    }
    if (!oe) {
        oe = w3d_create_8020b680(lbl_80415b00);
        w3d_append_801ef174(oe, 28, 3, self->o224);
        { int n; w3d_stages_801d0858(oe, &n);
        if (n) w3d_stage_set_801d0898(oe, a, 0); else w3d_stage_add_801d086c(oe, a); }
        w3d_append_801ef174(oe, 28, 3, h.p);
        w3d_append_801ef174(oe, 28, 3, self->o208);
        w3d_append_801ef174(oe, 28, 3, self->o196);
        ie = self->l180.size();
        self->v2376.push_back(0);
        self->v2388.push_back(0);
        self->v2436.push_back(0);
        self->l180.push(oe);
    }
    self->l132.push(oe);
    for (i = 0; i < self->l180.count; i++) {
        Ptr32<Obj> v = First(self->l180[i]);
        if (v == b) { if_ = i; of = self->l180[i]; }
    }
    if (!of) {
        of = w3d_create_8020b680(lbl_80415b00);
        w3d_append_801ef174(of, 28, 3, self->o224);
        { int n; w3d_stages_801d0858(of, &n);
        if (n) w3d_stage_set_801d0898(of, b, 0); else w3d_stage_add_801d086c(of, b); }
        w3d_append_801ef174(of, 28, 3, h.p);
        w3d_append_801ef174(of, 28, 3, self->o208);
        w3d_append_801ef174(of, 28, 3, self->o196);
        if_ = self->l180.size();
        self->v2376.push_back(0);
        self->v2388.push_back(0);
        self->v2436.push_back(0);
        self->l180.push(of);
    }
    self->l156.push(of);
    for (i = 0; i < self->l180.count; i++) {
        Ptr32<Obj> v = First(self->l180[i]);
        if (v == c) { ig = i; og = self->l180[i]; }
    }
    if (!og) {
        og = w3d_create_8020b680(lbl_80415b00);
        { int n; w3d_stages_801d0858(og, &n);
        if (n) w3d_stage_set_801d0898(og, c, 0); else w3d_stage_add_801d086c(og, c); }
        w3d_append_801ef174(og, 28, 3, self->o224);
        w3d_append_801ef174(og, 28, 3, h.p);
        w3d_append_801ef174(og, 28, 3, self->o208);
        w3d_append_801ef174(og, 28, 3, self->o196);
        ig = self->l180.size();
        self->v2376.push_back(0);
        self->v2388.push_back(0);
        self->v2436.push_back(0);
        self->l180.push(og);
    }
    self->l168.push(og);
    for (i = 0; i < self->l180.count; i++) {
        Ptr32<Obj> v = First(self->l180[i]);
        if (v == d) { ih = i; oh = self->l180[i]; }
    }
    if (!oh) {
        oh = w3d_create_8020b680(lbl_80415b00);
        w3d_append_801ef174(oh, 28, 3, self->o224);
        { int n; w3d_stages_801d0858(oh, &n);
        if (n) w3d_stage_set_801d0898(oh, d, 0); else w3d_stage_add_801d086c(oh, d); }
        w3d_append_801ef174(oh, 28, 3, h.p);
        w3d_append_801ef174(oh, 28, 3, self->o208);
        w3d_append_801ef174(oh, 28, 3, self->o196);
        ih = self->l180.size();
        self->v2376.push_back(0);
        self->v2388.push_back(0);
        self->v2436.push_back(0);
        self->l180.push(oh);
    }
    self->l144.push(oh);
    if (tail) {
        Ptr32<Obj> o = w3d_create_8020b680(lbl_80415b00);
        { int n; w3d_stages_801d0858(o, &n);
        if (n) w3d_stage_set_801d0898(o, tail, 0); else w3d_stage_add_801d086c(o, tail); }
        w3d_append_801ef174(o, 28, 3, self->o196);
        w3d_append_801ef174(o, 28, 3, self->o228);
        w3d_append_801ef174(o, 28, 3, self->o232);
        w3d_append_801ef174(o, 28, 3, self->o236);
        self->l108.push(o);
        self->v2448.push_back(w3d_heap_802098d8(&lbl_804adde4, 16464));
        self->v2460.push_back(0);
    } else {
        self->l108.push(tail);
        { Ptr32<void> p = tail; self->v2448.push_back(p); }
        self->v2460.push_back(0);
    }
    lbl_804b17f4 = self->v2460.size();
    self->t768[self->n764] = ia;
    self->t1024[self->n764] = ib;
    self->t1280[self->n764] = ic;
    self->t1536[self->n764] = ie;
    self->t1792[self->n764] = if_;
    self->t2048[self->n764] = ig;
    self->t768[self->n764 + 128] = id;
    self->t1024[self->n764 + 128] = ib;
    self->t1280[self->n764 + 128] = ic;
    self->t1536[self->n764 + 128] = ih;
    self->t1792[self->n764 + 128] = if_;
    self->t2048[self->n764 + 128] = ig;
    self->n764++;
    return 0;
}


