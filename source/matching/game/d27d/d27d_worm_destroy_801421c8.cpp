// GWMP8P rev0 0x801421c8. Destructor body of the worm object: set the worm
// vtable at 0x80410f00, then destroy its members in reverse order: 99 held
// interfaces released through virtual slot 16, one handle storage, one probe
// handle, one tracer owner and two method members, then chain to the actor
// base destructor with the flags. Member names are inferred; the padding
// spans fields this destructor does not touch.
#define VCALL(p, T, o) ((T)(*(void **)(*(char **)(p) + (o))))
extern const void *vtable_80410f00[];
extern "C" void storage_release_802134fc(void *);
extern "C" void handle_destroy_80126230(void *, int);
extern "C" void optional_delete_8014127c(void *, int);
extern "C" void method_destroy_80118200(void *, int);
extern "C" void actor_destroy_80161050(void *, int);
struct Held {
    void *held;
    ~Held() { if (held) VCALL(held, void (*)(void *), 16)(held); }
};
struct Storage {
    void *block;
    ~Storage() { if (block) storage_release_802134fc(block); }
};
struct Handle {
    void *word;
    ~Handle() { handle_destroy_80126230(this, 2); }
};
struct Optional {
    void *word;
    ~Optional() { optional_delete_8014127c(this, 2); }
};
struct Method {
    void *word;
    ~Method() { method_destroy_80118200(this, 2); }
};
struct Worm {
    const void *vtable;
    char pad4[24];
    Method method28;
    char pad32[212];
    Held held244;
    char pad248[104];
    Method method352;
    char pad356[180];
    Held held536;
    Held held540;
    Held held544;
    Held held548;
    Held held552;
    Held held556;
    char pad560[240];
    Held held800;
    Held held804;
    Held held808;
    Held held812;
    char pad816[32];
    Held held848;
    Held held852;
    Held held856;
    Held held860;
    Held held864;
    Held held868;
    Held held872;
    Held held876;
    Held held880;
    Held held884;
    Held held888;
    Held held892;
    Held held896;
    Held held900;
    Held held904;
    Held held908;
    Held held912;
    Held held916;
    Held held920;
    Held held924;
    Held held928;
    Held held932;
    Held held936;
    Held held940;
    Held held944;
    Held held948;
    Held held952;
    Held held956;
    Held held960;
    Held held964;
    Held held968;
    Held held972;
    Held held976;
    Held held980;
    Held held984;
    Held held988;
    Held held992;
    Held held996;
    Held held1000;
    Held held1004;
    Held held1008;
    Held held1012;
    Held held1016;
    Held held1020;
    Held held1024;
    Held held1028;
    Held held1032;
    Held held1036;
    Held held1040;
    Held held1044;
    Held held1048;
    Held held1052;
    Held held1056;
    Held held1060;
    Held held1064;
    Held held1068;
    Held held1072;
    Held held1076;
    Held held1080;
    Held held1084;
    Held held1088;
    Held held1092;
    Held held1096;
    Held held1100;
    Held held1104;
    Held held1108;
    Held held1112;
    Held held1116;
    Held held1120;
    Held held1124;
    Held held1128;
    Held held1132;
    Held held1136;
    Held held1140;
    Handle handle1144;
    char pad1148[4];
    Optional optional1152;
    char pad1156[36];
    Held held1192;
    Held held1196;
    Held held1200;
    char pad1204[12];
    Held held1216;
    Held held1220;
    Held held1224;
    Held held1228;
    Held held1232;
    Held held1236;
    Held held1240;
    Held held1244;
    Held held1248;
    Held held1252;
    char pad1256[88];
    Storage storage1344;
    char pad1348[8];
    Held held1356;
    Held held1360;
    ~Worm() {}
};
extern "C" void d27d_worm_destroy_801421c8(void *self, int flags) {
    Worm *o = (Worm *)self;
    o->vtable = vtable_80410f00;
    o->~Worm();
    actor_destroy_80161050(self, flags);
}
