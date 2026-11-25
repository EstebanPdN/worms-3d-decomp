// GWMP8P rev0 0x80027d2c. Creates three render states through the service
// lookup, sets their fields, queries an interface from the object, creates a
// pass and adds each state with that interface, then releases all
// references. Names are inferred from the original instructions.
struct Iface;
typedef void (*Plain)(Iface *);
typedef void (*Arg)(Iface *, void *);
typedef int (*Get)(Iface *, const void *, int, void *);
struct Table { char pad[12]; Plain add; Plain release; char pad2[4]; Arg put; char pad3[20]; Arg set; char pad4[4]; Get query; };
struct Part { char pad[7]; unsigned char flags; void Dirty() { flags |= 2; } };
struct Iface { Table *t; Part part; char pad[12]; int f24, f28, f32, f36;
    void Set24(int v) { f24 = v; part.Dirty(); }
    void Set28(int v) { f28 = v; part.Dirty(); }
    void Set32(int v) { f32 = v; part.Dirty(); }
    void Set36(int v) { f36 = v; part.Dirty(); }
};
struct Ref {
    Iface *p;
    Ref(Iface *q) { p = q; if (p) p->t->add(p); }
    Ref() {}
    Ref(const Ref &o);
    ~Ref() { if (p) p->t->release(p); }
};
extern "C" Iface *w3d_s10_service_forward_8020b680(const void *);
extern char g_a_80415c00[], g_b_80415cb0[], g_c_80415c10[], g_d_80416560[], g_e_8040e078[];
extern "C" int w3d_d30a_effect_state_setup_80027d2c(Iface *self)
{
    Ref a(w3d_s10_service_forward_8020b680(g_c_80415c10));
    a.p->Set36(1);
    a.p->Set32(4);
    Ref b(w3d_s10_service_forward_8020b680(g_a_80415c00));
    b.p->Set24(0);
    Ref c(w3d_s10_service_forward_8020b680(g_b_80415cb0));
    c.p->Set24(7);
    c.p->Set28(6);
    Ref d;
    d.p = 0;
    self->t->query(self, g_e_8040e078, 0, &d);
    Iface *dp = d.p;
    Ref e(w3d_s10_service_forward_8020b680(g_d_80416560));
    e.p->t->set(e.p, a.p);
    e.p->t->put(e.p, dp);
    e.p->t->set(e.p, b.p);
    e.p->t->put(e.p, dp);
    e.p->t->set(e.p, c.p);
    e.p->t->put(e.p, dp);
    return 0;
}
