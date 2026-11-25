// GWMP8P rev0 0x800c9e14. Builds the land water render graph: three texture
// stages, a material with static default colours, two water surfaces with
// layers fed by the settings Land.WaterDetailResource, Land.WaterResource
// and Land.WaterOffsetResource, shared grid buffers of 81 vertices and 420
// indices, two passes grouped and forwarded to the owner, and stores the
// surfaces in the scene object. Class layouts are partial views; names are
// inferred.
struct Object;
struct ObjectVtable { void *unknown00[3]; void (*retain)(Object *); void (*release)(Object *); };
struct Object { ObjectVtable *vtable; };
struct Ref {
    Object *p;
    Ref(Object *o) { p = o; if (p) p->vtable->retain(p); }
    Ref(const Ref &);
    ~Ref() { if (p) p->vtable->release(p); }
};
struct Field {
    Object *p;
    void Set(Object *q) {
        Object *old = p;
        p = q;
        if (q) q->vtable->retain(q);
        if (old) old->vtable->release(old);
    }
    void Assign(const Ref &q) {
        if (q.p) q.p->vtable->retain(q.p);
        if (p) p->vtable->release(p);
        p = q.p;
    }
};
struct Flags { char unknown0[7]; unsigned char bits; void Mark(unsigned char m) { bits |= m; } };
struct Color { float r, g, b, a; void Set(float x, float y, float z, float w) { r = x; g = y; b = z; a = w; } };
inline void *Slot(Object *o, int off) { return *(void **)((char *)o->vtable + off); }
struct Header { char unknown0[4]; unsigned short kind; char unknown6[18]; int count; unsigned short locks; };
extern "C" void *reserve_801ef048(void *, int, int, int);
struct ArrayRef {
    Header *header;
    void Lock(int n, int size, int flag) {
        Header *h = header;
        if (h->kind == 1 && h->count == n) ++h->locks;
        else reserve_801ef048(this, n, size, flag);
    }
};
struct Stage : Object { Flags flags; char unknown12[12]; int mode; int arg; void SetMode(int v) { mode = v; flags.Mark(2); } void SetArg(int v) { arg = v; flags.Mark(2); } };
struct Material : Object { Flags flags; char unknown12[12]; Color c24, c40, c56, c72; float k88; void Set24(const Color &c) { c24 = c; flags.Mark(2); } void Set40(const Color &c) { c40 = c; flags.Mark(2); } void Set56(const Color &c) { c56 = c; flags.Mark(2); } void Set72(const Color &c) { c72 = c; flags.Mark(2); } void SetK(float k) { k88 = k; flags.Mark(2); } void Enable() { flags.Mark(1); } };
struct Water : Object { void SetColor(const Color &c) { color = c; } char unknown4[16]; Color color; char unknown36[4]; int mode; char unknown44[4]; Field child48; Field child52; };
struct Layer : Object { char unknown4[24]; float k28; float k32; char unknown36[20]; Field f56; char unknown60[8]; Field f68; int a72; int b76; };
struct Comb : Object { char unknown4[64]; Field f68; Field f72; char unknown76[4]; Field f80; int n84; char unknown88[4]; Field f92; };
struct Buffer20 : Object { char unknown4[16]; ArrayRef array; };
struct Buffer24 : Object { char unknown4[20]; ArrayRef array; };
struct Pass : Object { char unknown4[16]; Field source; unsigned char a; unsigned char b; };
struct Scene { char unknown0[60]; Field a; Field b; };
extern Scene *scene_804b1794;
extern "C" Object *create_8020b680(void *);
extern "C" void append_801ef174(Object *, int, int, Object *);
extern "C" Object *service_8020b648();
struct Key { const char *name; };
struct String { String(const String &); char *text; String(const char *t); ~String(); };
extern "C" void string_finish_8020c5c4(String *);
extern "C" void string_release_80341588(String *);
inline String::~String() { string_finish_8020c5c4(this); string_release_80341588(this); }
extern "C" int setting_800fc2b0(Key *, const char **);
extern "C" int load_8015adf4(const String *, Object **, unsigned char);
extern "C" Object *cast_8034357c(Object *);
extern "C" Object *lookup_80174074(Object *);
extern "C" Object *value_80174050(Object *);
extern "C" int forward_801750f4(void *, Object *);
extern char k80415c30[], k80415c00[], k80415ba0[], k80415cb0[], k80414518[], k80415b30[], k804143e0[], k80413db0[], k80414780[], k80414830[], k80414870[], k804146e0[], k804148d0[], k804149f0[], k804144f8[];
extern int guard_804ae800, guard_804ae804, guard_804ae808;
extern Color color_8043ed74, color_8043ed84, color_8043ed94;
extern Object *h_8043eda4[], *h_8043eda8[], *h_8043edb0[];
extern int token_804b1930;
typedef void (*IntFn)(Object *, int);
typedef int (*IntFn2)(Object *, int);
typedef void (*ObjFn)(Object *, Object *);
typedef void (*TokenFn)(Object *, int *, int);
typedef void (*StrFn)(Object *, void *);
#define S(x) ((Stage *)(x).p)

extern "C" int d32h_water_setup_800c9e14(void *self) {
    Ref s0(create_8020b680(k80415c30));
    int off = 0, on = 1;
    void *kS = k80415c00;
    S(s0)->SetMode(off);
    Ref s1(create_8020b680(kS));
    S(s1)->SetMode(on);
    Ref s2(create_8020b680(kS));
    S(s2)->SetMode(off);
    Ref mat(create_8020b680(k80415ba0));
    if (!guard_804ae800) { guard_804ae800 = on; color_8043ed74.Set(1.0f, 1.0f, 1.0f, 1.0f); }
    if (!guard_804ae804) { guard_804ae804 = on; color_8043ed84.Set(0.0f, 0.0f, 0.0f, 0.0f); }
    if (!guard_804ae808) { color_8043ed94.Set(0.75f, 0.75f, 0.75f, 0.0f); guard_804ae808 = on; }
    #define M ((Material *)mat.p)
    int yes = 1;
    M->Set56(color_8043ed74);
    M->Set72(color_8043ed74);
    M->Set24(color_8043ed94);
    M->Set40(color_8043ed84);
    M->SetK(20.0f);
    M->Enable();
    Ref st(create_8020b680(k80415cb0));
    S(st)->SetArg(6);
    S(st)->SetMode(7);
    void *kW = k80414518;
    Ref w0(create_8020b680(kW));
    void *kL = k80415b30;
    Ref l0(create_8020b680(kL));
    Ref w1(create_8020b680(kW));
    Ref l1(create_8020b680(kL));
    ((Water *)w0.p)->child52.Set(l0.p);
    int no = 0;
    ((Layer *)l0.p)->a72 = yes;
    ((Layer *)l0.p)->b76 = no;
    append_801ef174(l0.p, 48, 7, s0.p);
    append_801ef174(l0.p, 48, 7, st.p);
    append_801ef174(l0.p, 48, 7, mat.p);
    append_801ef174(l0.p, 48, 7, s1.p);
    ((Water *)w1.p)->child52.Set(l1.p);
    ((Layer *)l1.p)->a72 = no;
    ((Layer *)l1.p)->b76 = yes;
    append_801ef174(l1.p, 48, 7, s0.p);
    append_801ef174(l1.p, 48, 7, st.p);
    append_801ef174(l1.p, 48, 7, mat.p);
    append_801ef174(l1.p, 48, 7, s1.p);
    ((Layer *)l1.p)->k32 = 2.5f;
    ((Layer *)l1.p)->k28 = 1.0f;
    void *kT = k804143e0;
    Object *svc = service_8020b648();
    ((ObjFn)Slot(svc, 92))(svc, (Object *)kT);
    const char *text;
    Key k1; k1.name = "Land.WaterDetailResource";
    setting_800fc2b0(&k1, &text);
    { String n(text); load_8015adf4(&n, h_8043eda4, 255); }
    const char *text2;
    Key k2; k2.name = "Land.WaterResource";
    setting_800fc2b0(&k2, &text2);
    { String n(text2); load_8015adf4(&n, h_8043eda8, 255); }
    Key k3; k3.name = "Land.WaterOffsetResource";
    setting_800fc2b0(&k3, &text2);
    { String n(text2); load_8015adf4(&n, h_8043edb0, 255); }
    Object *res, *o;
    res = cast_8034357c(h_8043eda8[0]);
    o = lookup_80174074(res);
    ((Layer *)l0.p)->f68.Set(o);
    ((IntFn2)Slot(res, 88))(res, 0);
    res = cast_8034357c(h_8043eda4[0]);
    o = lookup_80174074(res);
    ((Layer *)l1.p)->f68.Set(o);
    ((IntFn2)Slot(res, 88))(res, 0);
    res = cast_8034357c(h_8043edb0[0]);
    o = lookup_80174074(res);
    Object *v = value_80174050(res);
    ((IntFn2)Slot(res, 88))(res, 0);
    Ref tex(create_8020b680(k80413db0));
    ((IntFn)Slot(tex.p, 56))(tex.p, 4);
    ((IntFn)Slot(tex.p, 144))(tex.p, 0);
    ((IntFn)Slot(tex.p, 64))(tex.p, 1);
    ((TokenFn)Slot(tex.p, 80))(tex.p, &token_804b1930, 1);
    ((ObjFn)Slot(tex.p, 24))(tex.p, v);
    ((Layer *)l0.p)->f56.Set(o);
    ((Layer *)l1.p)->f56.Set(o);
    Ref b0(create_8020b680(k80414780));
    void *kB = k80414830;
    Ref b1(create_8020b680(kB));
    Ref b2(create_8020b680(kB));
    Ref b3(create_8020b680(k80414870));
    void *kC = k804146e0;
    Ref c0(create_8020b680(kC));
    Ref c1(create_8020b680(kC));
    Ref b4(create_8020b680(k804148d0));
    ((Buffer20 *)b0.p)->array.Lock(81, 12, 1);
    ((Buffer20 *)b1.p)->array.Lock(81, 4, 1);
    ((Buffer20 *)b2.p)->array.Lock(81, 4, 1);
    ((Buffer20 *)b3.p)->array.Lock(81, 8, 1);
    ((Buffer24 *)b4.p)->array.Lock(420, 2, 1);
    ((Water *)w0.p)->child48.Set(c0.p);
    ((Comb *)c0.p)->f80.Set(b0.p);
    ((Comb *)c0.p)->f72.Set(b1.p);
    ((Comb *)c0.p)->f68.Set(b3.p);
    ((Comb *)c0.p)->f92.Set(b4.p);
    ((Comb *)c0.p)->n84 = 140;
    ((Water *)w1.p)->child48.Set(c1.p);
    ((Comb *)c1.p)->f80.Set(b0.p);
    ((Comb *)c1.p)->f72.Set(b2.p);
    ((Comb *)c1.p)->f68.Set(b3.p);
    ((Comb *)c1.p)->f92.Set(b4.p);
    ((Comb *)c1.p)->n84 = 140;
    Color col;
    Color *pc = &col;
    pc->r = 0.0f; pc->g = 0.0f; pc->b = 0.0f; col.a = 2.0f;
    ((Water *)w0.p)->mode = 0;
    ((Water *)w0.p)->SetColor(col);
    void *kP = k804149f0;
    Ref p0(create_8020b680(kP));
    Ref p1(create_8020b680(kP));
    ((Pass *)p0.p)->source.Set(w0.p);
    ((Pass *)p0.p)->b = 22; ((Pass *)p0.p)->a = 22;
    ((Pass *)p1.p)->source.Set(w1.p);
    ((Pass *)p1.p)->b = 23; ((Pass *)p1.p)->a = 23;
    Ref group(create_8020b680(k804144f8));
    append_801ef174(group.p, 44, 3, p0.p);
    append_801ef174(group.p, 44, 3, p1.p);
    forward_801750f4(self, group.p);
    scene_804b1794->a.Assign(w0);
    scene_804b1794->b.Assign(w1);
    return 0;
}
