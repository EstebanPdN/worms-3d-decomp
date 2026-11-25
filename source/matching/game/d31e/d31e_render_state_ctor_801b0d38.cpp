// (Worms 3D GameCube PAL, 0x801b0d38).
//
// Constructs a render state holder: base table 0x804136c0 with tag at +4,
// final table 0x80414220. Takes the shared state store through 0x8020b648
// slot 21 (class record 0x804143e0), creates a rasterizer state (values 6
// and 7), a material-like state at +60 (1, 0.5, 4) and a depth state at +52
// (0), each deduplicated through the store's share slot, and a further
// service object at +56. Names are inferred.

#pragma interface
struct Tag { char u[7]; unsigned char flags; int w[3]; void Mark() { flags |= 2; } };
struct FullTag { int w[9]; FullTag(); };
struct ObjV { virtual void v0(); virtual void AddRef(); virtual void Release(); };
struct Obj : ObjV {
    Tag tag;
    int a;
    int b;
    int c;
    void SetA(int v) { a = v; tag.Mark(); }
    void SetB(int v) { b = v; tag.Mark(); }
    void SetC(int v) { c = v; tag.Mark(); }
    void SetAf(float v) { *(float *)&a = v; tag.Mark(); }
};
struct Ref {
    Obj *p;
    Ref() : p(0) { }
    Ref(Obj *o) { p = o; if (p) p->AddRef(); }
    Ref(const Ref &);
    ~Ref() { if (p) p->Release(); }
    Ref &operator=(Obj *q) {
        if (q) q->AddRef();
        if (p) p->Release();
        p = q;
        return *this;
    }
    Obj *operator->() const { return p; }
};
struct Store {
    virtual void a0(),a1(),a2(),a3(),a4(),a5(),a6(),a7(),a8();
    virtual Obj *Share(Obj *);
    virtual void b0(),b1(),b2(),b3(),b4(),b5(),b6(),b7(),b8(),b9(),b10();
    virtual Store *Get(void *);
};
struct StoreObj : ObjV { };
struct StoreRef {
    Store *p;
    StoreRef(Store *o) { p = o; if (p) ((ObjV *)p)->AddRef(); }
    StoreRef(const StoreRef &);
    ~StoreRef() { if (p) ((ObjV *)p)->Release(); }
};
struct ClassRecord;
extern ClassRecord k_804143e0[], k_80415cb0[], k_80415bb0[], k_80415c00[], k_804166b0[];
extern float f_803aa838[];
extern "C" Store *w3d_auto_8020b648();
extern "C" Obj *w3d_s10_service_forward_8020b680(ClassRecord *);
struct Iface { virtual void x0() = 0; };
struct Base : Iface { FullTag tag; Base() { } };
struct Render : Base {
    int x40;
    int x44;
    Ref rs;
    Ref ds;
    Ref bs;
    Ref ms;
    virtual void x0();
    Render();
};
Render::Render() : x40(0)
{
    ClassRecord *k = k_804143e0;
    StoreRef store(w3d_auto_8020b648()->Get(k));
    rs = w3d_s10_service_forward_8020b680(k_80415cb0);
    rs->SetB(6);
    rs->SetA(7);
    rs = store.p->Share(rs.p);
    ms = w3d_s10_service_forward_8020b680(k_80415bb0);
    ms->SetC(1);
    ms->SetAf(0.5f);
    ms->SetB(4);
    ms = store.p->Share(ms.p);
    ds = w3d_s10_service_forward_8020b680(k_80415c00);
    ds->SetA(0);
    ds = store.p->Share(ds.p);
    bs = w3d_s10_service_forward_8020b680(k_804166b0);
}
