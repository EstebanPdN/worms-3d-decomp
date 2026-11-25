// GWMP8P rev0 0x8015776c. Creates the sixteen numbered light slots.
struct Vec { float x, y, z; void init(float a, float b, float c) { x = a; y = b; z = c; } };
struct Light { char u0[120]; Vec v120; Vec v132; int on; char u94[8]; Vec v156; };
struct Mgr;
struct MgrVt { char u0[192]; int (*add)(Mgr *, char *, int, int, Light *); };
struct Mgr { MgrVt *vt; };
struct Svc;
struct SvcVt { char u0[88]; void (*set)(Svc *, int); };
struct Svc { SvcVt *vt; };
struct Engine { char u0[116]; Mgr *mgr; };
struct World { char u0[68]; Svc *svc; };
extern "C" {
float sqrt_802e82c0(float);
Light *create_8020b680(void *);
int sprintf_803442b4(char *, const char *, ...);
}
struct EngineRef { Engine *e; };
extern EngineRef engine_804b17ec;
extern World *world_804b1788;
extern int guardA_804afe10, guardB_804afe14, guardC_804afe18, flag_804ab3b0;
extern Vec a_804540f4[], b_80454100[], c_8045410c[];
extern char desc_80414a90[];
extern const char fmtA_803a2c04[], fmtB_803a2c14[];
extern "C" void d29d_lights_init_8015776c() {
    if (!guardA_804afe10) { a_804540f4->init(0.5f, 0.5f, 0.6f); guardA_804afe10 = 1; }
    if (!guardB_804afe14) { b_80454100->init(0.7f, 0.7f, 0.6f); guardB_804afe14 = 1; }
    if (!guardC_804afe18) { c_8045410c->init(-0.57f, -0.57f, -0.57f); guardC_804afe18 = 1; }
    unsigned i = 0;
    Vec &c = *c_8045410c;
    float k = 1.0f / sqrt_802e82c0(c.x * c.x + c.y * c.y + c.z * c.z);
    c.x *= k; c.y *= k; c.z *= k;
    char buf[32];
    char *desc = desc_80414a90;
    for (i = 0; i < 16; i++) {
        Light *l = create_8020b680(desc);
        l->on = 1;
        l->v132 = *a_804540f4;
        l->v120 = *b_80454100;
        l->v156 = *c_8045410c;
        Mgr *m = engine_804b17ec.e->mgr;
        MgrVt *vt = m->vt;
        char *name;
        sprintf_803442b4(buf, fmtA_803a2c04, i);
        name = buf;
        vt->add(m, name, 4, 0, l);
        Light *l2 = create_8020b680(desc);
        l2->on = 1;
        l2->v132 = *a_804540f4;
        l2->v120 = *b_80454100;
        l2->v156 = *c_8045410c;
        Mgr *m2 = engine_804b17ec.e->mgr;
        MgrVt *vt2 = m2->vt;
        sprintf_803442b4(name, fmtB_803a2c14, i);
        vt2->add(m2, name, 4, 0, l2);
    }
    world_804b1788->svc->vt->set(world_804b1788->svc, 4);
    flag_804ab3b0 = 0;
}
