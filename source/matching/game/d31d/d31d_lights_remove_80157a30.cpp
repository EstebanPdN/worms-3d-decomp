// GWMP8P rev0 0x80157a30. Removes the sixteen numbered worm lights and weapon
// lights by name from the engine's light manager, then finishes the world's
// manager. Names are read from the strings in the original; virtual slots are
// reference-ABI observations.
#pragma interface
struct Lights {
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual int remove(char *, int);
};
struct Engine { char u0[116]; Lights *lights; };
struct Mgr;
struct MgrVt { char u0[88]; void (*finish)(Mgr *, int); };
struct Mgr { MgrVt *vt; };
struct World { char u0[68]; Mgr *mgr; };
extern Engine *engine_804b17ec;
extern World *world_804b1788;
extern "C" int format_803442b4(char *, const char *, ...);
struct Name { char s[32]; char *c_str() { return s; } char *Fmt(const char *f, unsigned i) { format_803442b4(s, f, i); return s; } };
extern "C" void w3d_d31d_lights_remove_80157a30() {
    Name buf;
    for (unsigned i = 0; i <= 15; i++) {
        engine_804b17ec->lights->remove((format_803442b4(buf.s, "WormLight.%d", i), buf.c_str()), 4);
        engine_804b17ec->lights->remove(buf.Fmt("WeaponLight.%d", i), 4);
    }
    world_804b1788->mgr->vt->finish(world_804b1788->mgr, 4);
}
