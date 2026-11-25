// GWMP8P rev0 0x80146fb8. Worm logic entity setup: binds its global and worm
// properties and subscribes to its messages, then places the worm. Names are
// read from the strings in the original; other names are inferred from use.
// Virtual slots are reference-ABI observations.
struct Vec { float x, y, z; };
struct Triple { int a, b, c; };
struct TypeDesc {
    char pad[20];
    TypeDesc *parent;
    bool is_a(TypeDesc *target) {
        TypeDesc *t = this;
        while (t != target) {
            if (t == t->parent) return false;
            t = t->parent;
        }
        return true;
    }
};
extern TypeDesc type_80361860[];
extern TypeDesc type_803618f0[];
struct Obj;
struct ObjVt { char u0[12]; void (*retain)(Obj *); void (*release)(Obj *); };
struct Obj { ObjVt *vt; };
struct Ref {
    Obj *p;
    Ref() { p = 0; }
    Ref(const Ref &);
    ~Ref() { if (p) p->vt->release(p); }
    void operator=(Obj *q) {
        if (q) q->vt->retain(q);
        if (p) p->vt->release(p);
        p = q;
    }
};
struct Event { unsigned short id; };
struct Plain { short id; void *vt; };
struct Handle { int value; unsigned key; Handle(int v) { value = v; key = 58280; } ~Handle(); };
struct Info { char u0[68]; Vec v68; Vec v80; char u5c[100]; int f192; char uc4[64]; int f260; };
struct Item { char u0[160]; int f160; char ua4[6]; unsigned short hp; };
struct Engine { char u0[52]; int now; };
struct Base {
    virtual int query_interface();
    virtual void retain();
    virtual void release();
    virtual TypeDesc *type();
};
struct Worm : Base {
     char u4[16]; int f20; char u24[276]; int f300; char u304[4]; int f308; char u312[232]; Ref f544; Ref f548; int f552; int f556; Vec f560; Vec f572; int f584; char u588[84]; int f672; char u676[84]; int f760; char u764[40]; int f804; char u808[20]; Triple f828; int f840; char u844[4]; int f848; int f852; int f856; int f860; int f864; int f868; int f872; int f876; int f880; char u884[4]; int f888; int f892; int f896; int f900; int f904; int f908; int f912; int f916; int f920; int f924; int f928; int f932; int f936; int f940; int f944; int f948; int f952; int f956; int f960; int f964; int f968; int f972; int f976; int f980; int f984; int f988; int f992; int f996; int f1000; int f1004; int f1008; int f1012; int f1016; int f1020; int f1024; int f1028; int f1032; int f1036; int f1040; int f1044; int f1048; int f1052; int f1056; int f1060; int f1064; int f1068; int f1072; int f1076; int f1080; int f1084; int f1088; int f1092; int f1096; int f1100; int f1104; int f1108; int f1112; int f1116; char u1120[4]; int f1124; char u1128[8]; int f1136; char u1140[4]; int f1144; char u1148[44]; int f1192; int f1196; int f1200; char u1204[12]; Ref f1216; Ref f1220; Ref f1224; Ref f1228; Ref f1232; Ref f1236; Ref f1240; Ref f1244; Ref f1248; Ref f1252; char u1256[24]; int f1280[16];
};
extern "C" {
int bind_800fc1b0(const char **, void *);
unsigned short message_id_8015f5a0(int *, int);
int subscribe_80162024(void *, unsigned short *, void *);
void *alloc_801613f0(void *, int);
void *init_800c1620(void *, int *);
int post_8016239c(void *);
void query_80126308(void *, int);
Info *query_800fc6dc(int);
void create_third_80150b6c(Worm *, int);
Engine *engine_80165254();
int log_80022e20(const char *, const char *, int, int *);
void set_state_801492ec(Worm *, int);
void target_position_8015324c(Worm *);
void compact_80153a58(Worm *);
Item *item_800fc710(int, const Handle &);
Obj *cast_80341584(Obj *);
Obj *cast_80342a74(Obj *);
Obj *cast_80342fa4(Obj *);
}
extern void *heap_804b1754;
extern unsigned char vt_8040db38[];
extern Triple triple_8045e788[];
extern int count_804ab3e0;
extern const char log_803a1270[];
extern const char logic_entity_803a0e2c[];
extern int cache_804afcb8;
extern const char str_803a0ff4[];
extern const char str_803a1000[];
extern const char str_803a100c[];
extern const char str_803a1024[];
extern const char str_803a0e0c[];
extern const char str_803a103c[];
extern const char str_803a1044[];
extern const char str_803a105c[];
extern const char str_803a1074[];
extern const char str_803a1084[];
extern const char str_803a109c[];
extern const char str_803a10b4[];
extern const char str_803a10d0[];
extern const char str_803a10e4[];
extern const char str_803a10fc[];
extern const char str_803a111c[];
extern const char str_803a1134[];
extern const char str_803a1150[];
extern const char str_803a1164[];
extern const char str_803a1178[];
extern const char str_803a118c[];
extern const char str_803a1194[];
extern const char str_803a11a8[];
extern const char str_803a11bc[];
extern const char str_803a11d0[];
extern const char str_803a11e4[];
extern const char str_803a11f8[];
extern const char str_803a1214[];
extern const char str_803a1230[];
extern const char str_803a1250[];
extern Ref ref_804afdd8;
extern Ref ref_804afddc;
extern Ref ref_804afde0;
extern Ref ref_804afde4;
extern Ref ref_804afde8;
extern Ref ref_804afdec;
extern Ref ref_804afdf0;
extern Ref ref_804afdf8;
extern Ref ref_804afdf4;
extern int cache_804afbd8;
extern int cache_804afbe0;
extern int cache_804afb10;
extern int cache_804afaf0;
extern int cache_804afaf8;
extern int cache_804afb00;
extern int cache_804afb08;
extern int cache_804afad8;
extern int cache_804afae0;
extern int cache_804afc98;
extern int cache_804afb28;
extern int cache_804af764;
extern int cache_804af76c;
extern int cache_804afb30;
extern int cache_804afb38;
extern int cache_804afb48;
extern int cache_804afb50;
extern int cache_804afb58;
extern int cache_804afb78;
extern int cache_804afb88;
extern int cache_804afb80;
extern int cache_804afae8;
extern int cache_804afbb8;
extern int cache_804afa98;
extern int cache_804afaa0;
extern int cache_804afaa8;
extern int cache_804afab0;
extern int cache_804afab8;
extern int cache_804afac0;
extern int cache_804afac8;
extern int cache_804afad0;
extern int cache_804afbc0;
extern int cache_804afb18;
extern int cache_804afb20;
extern int cache_804afbc8;
extern int cache_804afc00;
extern int cache_804afc38;
extern int cache_804afc48;
extern int cache_804afbe8;
extern int cache_804afc78;
extern int cache_804afc80;
extern int cache_804afc88;
extern int cache_804afc18;
extern int cache_804afca0;
extern int cache_804afca8;
extern int cache_804afcb0;
extern int cache_804afbf0;
extern int cache_804afbf8;
extern int cache_804afc08;
extern int cache_804afcc0;
extern int cache_804afcd0;
extern int cache_804afcf8;
extern int cache_804afd00;
extern int cache_804afd28;
extern int cache_804afb60;
extern int cache_804afd40;
extern int cache_804afd78;
extern int cache_804afd88;
extern int cache_804afd90;
extern int cache_804afd98;
extern int cache_804afda0;
extern int cache_804afda8;
extern int cache_804afdb0;
extern int cache_804afdb8;
extern int cache_804afdd0;
extern "C" void d29d_worm_setup_80146fb8(Worm *self) {
    const char *n0 = str_803a0ff4; bind_800fc1b0(&n0, &self->f1108);
    const char *n1 = str_803a1000; { Ref t; bind_800fc1b0(&n1, &t); self->f1232 = cast_80342a74(t.p); }
    const char *n2 = str_803a100c; bind_800fc1b0(&n2, &self->f1112);
    const char *n3 = str_803a1024; bind_800fc1b0(&n3, &self->f1116);
    const char *n4 = str_803a0e0c; bind_800fc1b0(&n4, &self->f1124);
    const char *n5 = str_803a103c; { Ref t; bind_800fc1b0(&n5, &t); self->f544 = cast_80342a74(t.p); }
    const char *n6 = str_803a1044; { Ref t; bind_800fc1b0(&n6, &t); self->f548 = cast_80342a74(t.p); }
    const char *n7 = str_803a105c; bind_800fc1b0(&n7, &self->f556);
    const char *n8 = str_803a1074; bind_800fc1b0(&n8, &self->f552);
    const char *n9 = str_803a1084; bind_800fc1b0(&n9, &self->f1192);
    const char *n10 = str_803a109c; bind_800fc1b0(&n10, &self->f1196);
    const char *n11 = str_803a10b4; bind_800fc1b0(&n11, &self->f1200);
    const char *n12 = str_803a10d0; { Ref t; bind_800fc1b0(&n12, &t); self->f1216 = cast_80342a74(t.p); }
    const char *n13 = str_803a10e4; { Ref t; bind_800fc1b0(&n13, &t); self->f1220 = cast_80342a74(t.p); }
    const char *n14 = str_803a10fc; { Ref t; bind_800fc1b0(&n14, &t); self->f1224 = cast_80342a74(t.p); }
    const char *n15 = str_803a111c; { Ref t; bind_800fc1b0(&n15, &t); self->f1228 = cast_80342a74(t.p); }
    const char *n16 = str_803a1134; { Ref t; bind_800fc1b0(&n16, &t); self->f1236 = cast_80342a74(t.p); }
    const char *n17 = str_803a1150; { Ref t; bind_800fc1b0(&n17, &t); self->f1240 = cast_80342a74(t.p); }
    const char *n18 = str_803a1164; { Ref t; bind_800fc1b0(&n18, &t); self->f1244 = cast_80342a74(t.p); }
    const char *n19 = str_803a1178; { Ref t; bind_800fc1b0(&n19, &t); self->f1248 = cast_80342a74(t.p); }
    const char *n20 = str_803a118c; { Ref t; bind_800fc1b0(&n20, &t); self->f1252 = cast_80341584(t.p); }
    if (++count_804ab3e0 == 1) {
        const char *n21 = str_803a1194; { Ref t; bind_800fc1b0(&n21, &t); ref_804afdd8 = cast_80342fa4(t.p); }
        const char *n22 = str_803a11a8; { Ref t; bind_800fc1b0(&n22, &t); ref_804afddc = cast_80342fa4(t.p); }
        const char *n23 = str_803a11bc; { Ref t; bind_800fc1b0(&n23, &t); ref_804afde0 = cast_80342fa4(t.p); }
        const char *n24 = str_803a11d0; { Ref t; bind_800fc1b0(&n24, &t); ref_804afde4 = cast_80342fa4(t.p); }
        const char *n25 = str_803a11e4; { Ref t; bind_800fc1b0(&n25, &t); ref_804afde8 = cast_80342fa4(t.p); }
        const char *n26 = str_803a11f8; { Ref t; bind_800fc1b0(&n26, &t); ref_804afdec = cast_80342a74(t.p); }
        const char *n27 = str_803a1214; { Ref t; bind_800fc1b0(&n27, &t); ref_804afdf0 = cast_80342a74(t.p); }
        const char *n28 = str_803a1230; { Ref t; bind_800fc1b0(&n28, &t); ref_804afdf8 = cast_80342a74(t.p); }
        const char *n29 = str_803a1250; { Ref t; bind_800fc1b0(&n29, &t); ref_804afdf4 = cast_80342a74(t.p); }
    }
    int zero = 0;
    self->f300 = zero;
    self->f308 = zero;
    Event e0; e0.id = message_id_8015f5a0(&cache_804afbd8, 1); subscribe_80162024(self, &e0.id, &self->f984);
    Event e1; e1.id = message_id_8015f5a0(&cache_804afbe0, 1); subscribe_80162024(self, &e1.id, &self->f988);
    Event e2; e2.id = message_id_8015f5a0(&cache_804afb10, 1); subscribe_80162024(self, &e2.id, &self->f992);
    Event e3; e3.id = message_id_8015f5a0(&cache_804afaf0, 1); subscribe_80162024(self, &e3.id, &self->f864);
    Event e4; e4.id = message_id_8015f5a0(&cache_804afaf8, 1); subscribe_80162024(self, &e4.id, &self->f868);
    Event e5; e5.id = message_id_8015f5a0(&cache_804afb00, 1); subscribe_80162024(self, &e5.id, &self->f872);
    Event e6; e6.id = message_id_8015f5a0(&cache_804afb08, 1); subscribe_80162024(self, &e6.id, &self->f876);
    Event e7; e7.id = message_id_8015f5a0(&cache_804afad8, 1); subscribe_80162024(self, &e7.id, &self->f880);
    Event e8; e8.id = message_id_8015f5a0(&cache_804afae0, 1); subscribe_80162024(self, &e8.id, &self->f1044);
    Event e9; e9.id = message_id_8015f5a0(&cache_804afc98, 1); subscribe_80162024(self, &e9.id, &self->f888);
    Event e10; e10.id = message_id_8015f5a0(&cache_804afb28, 1); subscribe_80162024(self, &e10.id, &self->f924);
    Event e11; e11.id = message_id_8015f5a0(&cache_804af764, 1); subscribe_80162024(self, &e11.id, &self->f928);
    Event e12; e12.id = message_id_8015f5a0(&cache_804af76c, 1); subscribe_80162024(self, &e12.id, &self->f932);
    Event e13; e13.id = message_id_8015f5a0(&cache_804afb30, 1); subscribe_80162024(self, &e13.id, &self->f936);
    Event e14; e14.id = message_id_8015f5a0(&cache_804afb38, 1); subscribe_80162024(self, &e14.id, &self->f940);
    Event e15; e15.id = message_id_8015f5a0(&cache_804afb48, 1); subscribe_80162024(self, &e15.id, &self->f944);
    Event e16; e16.id = message_id_8015f5a0(&cache_804afb50, 1); subscribe_80162024(self, &e16.id, &self->f964);
    Event e17; e17.id = message_id_8015f5a0(&cache_804afb58, 1); subscribe_80162024(self, &e17.id, &self->f968);
    Event e18; e18.id = message_id_8015f5a0(&cache_804afb78, 1); subscribe_80162024(self, &e18.id, &self->f960);
    Event e19; e19.id = message_id_8015f5a0(&cache_804afb88, 1); subscribe_80162024(self, &e19.id, &self->f848);
    Event e20; e20.id = message_id_8015f5a0(&cache_804afb80, 1); subscribe_80162024(self, &e20.id, &self->f852);
    Event e21; e21.id = message_id_8015f5a0(&cache_804afae8, 1); subscribe_80162024(self, &e21.id, &self->f972);
    Event e22; e22.id = message_id_8015f5a0(&cache_804afbb8, 1); subscribe_80162024(self, &e22.id, &self->f976);
    Event e23; e23.id = message_id_8015f5a0(&cache_804afa98, 1); subscribe_80162024(self, &e23.id, &self->f892);
    Event e24; e24.id = message_id_8015f5a0(&cache_804afaa0, 1); subscribe_80162024(self, &e24.id, &self->f896);
    Event e25; e25.id = message_id_8015f5a0(&cache_804afaa8, 1); subscribe_80162024(self, &e25.id, &self->f900);
    Event e26; e26.id = message_id_8015f5a0(&cache_804afab0, 1); subscribe_80162024(self, &e26.id, &self->f904);
    Event e27; e27.id = message_id_8015f5a0(&cache_804afab8, 1); subscribe_80162024(self, &e27.id, &self->f908);
    Event e28; e28.id = message_id_8015f5a0(&cache_804afac0, 1); subscribe_80162024(self, &e28.id, &self->f912);
    Event e29; e29.id = message_id_8015f5a0(&cache_804afac8, 1); subscribe_80162024(self, &e29.id, &self->f916);
    Event e30; e30.id = message_id_8015f5a0(&cache_804afad0, 1); subscribe_80162024(self, &e30.id, &self->f920);
    Event e31; e31.id = message_id_8015f5a0(&cache_804afbc0, 1); subscribe_80162024(self, &e31.id, &self->f980);
    Event e32; e32.id = message_id_8015f5a0(&cache_804afb18, 1); subscribe_80162024(self, &e32.id, &self->f856);
    Event e33; e33.id = message_id_8015f5a0(&cache_804afb20, 1); subscribe_80162024(self, &e33.id, &self->f860);
    Event e34; e34.id = message_id_8015f5a0(&cache_804afbc8, 1); subscribe_80162024(self, &e34.id, &self->f952);
    Event e35; e35.id = message_id_8015f5a0(&cache_804afc00, 1); subscribe_80162024(self, &e35.id, &self->f1000);
    Event e36; e36.id = message_id_8015f5a0(&cache_804afc38, 1); subscribe_80162024(self, &e36.id, &self->f1136);
    Event e37; e37.id = message_id_8015f5a0(&cache_804afc48, 1); subscribe_80162024(self, &e37.id, &self->f948);
    Event e38; e38.id = message_id_8015f5a0(&cache_804afbe8, 1); subscribe_80162024(self, &e38.id, &self->f996);
    Event e39; e39.id = message_id_8015f5a0(&cache_804afc78, 1); subscribe_80162024(self, &e39.id, &self->f1008);
    Event e40; e40.id = message_id_8015f5a0(&cache_804afc80, 1); subscribe_80162024(self, &e40.id, &self->f1004);
    Event e41; e41.id = message_id_8015f5a0(&cache_804afc88, 1); subscribe_80162024(self, &e41.id, &self->f1012);
    Event e42; e42.id = message_id_8015f5a0(&cache_804afc18, 1); subscribe_80162024(self, &e42.id, &self->f1016);
    Event e43; e43.id = message_id_8015f5a0(&cache_804afca0, 1); subscribe_80162024(self, &e43.id, &self->f1020);
    Event e44; e44.id = message_id_8015f5a0(&cache_804afca8, 1); subscribe_80162024(self, &e44.id, &self->f1024);
    Event e45; e45.id = message_id_8015f5a0(&cache_804afcb0, 1); subscribe_80162024(self, &e45.id, &self->f1028);
    Event e46; e46.id = message_id_8015f5a0(&cache_804afbf0, 1); subscribe_80162024(self, &e46.id, &self->f1032);
    Event e47; e47.id = message_id_8015f5a0(&cache_804afbf8, 1); subscribe_80162024(self, &e47.id, &self->f1036);
    Event e48; e48.id = message_id_8015f5a0(&cache_804afc08, 1); subscribe_80162024(self, &e48.id, &self->f1040);
    Event e49; e49.id = message_id_8015f5a0(&cache_804afcc0, 1); subscribe_80162024(self, &e49.id, &self->f1048);
    Event e50; e50.id = message_id_8015f5a0(&cache_804afcd0, 1); subscribe_80162024(self, &e50.id, &self->f956);
    Event e51; e51.id = message_id_8015f5a0(&cache_804afcf8, 1); subscribe_80162024(self, &e51.id, &self->f1052);
    Event e52; e52.id = message_id_8015f5a0(&cache_804afd00, 1); subscribe_80162024(self, &e52.id, &self->f1056);
    Event e53; e53.id = message_id_8015f5a0(&cache_804afd28, 1); subscribe_80162024(self, &e53.id, &self->f1060);
    Event e54; e54.id = message_id_8015f5a0(&cache_804afb60, 1); subscribe_80162024(self, &e54.id, &self->f1064);
    Event e55; e55.id = message_id_8015f5a0(&cache_804afd40, 1); subscribe_80162024(self, &e55.id, &self->f1068);
    Event e56; e56.id = message_id_8015f5a0(&cache_804afd78, 1); subscribe_80162024(self, &e56.id, &self->f1072);
    Event e57; e57.id = message_id_8015f5a0(&cache_804afd88, 1); subscribe_80162024(self, &e57.id, &self->f1076);
    Event e58; e58.id = message_id_8015f5a0(&cache_804afd90, 1); subscribe_80162024(self, &e58.id, &self->f1080);
    Event e59; e59.id = message_id_8015f5a0(&cache_804afd98, 1); subscribe_80162024(self, &e59.id, &self->f1084);
    Event e60; e60.id = message_id_8015f5a0(&cache_804afda0, 1); subscribe_80162024(self, &e60.id, &self->f1088);
    Event e61; e61.id = message_id_8015f5a0(&cache_804afda8, 1); subscribe_80162024(self, &e61.id, &self->f1092);
    Event e62; e62.id = message_id_8015f5a0(&cache_804afdb0, 1); subscribe_80162024(self, &e62.id, &self->f1096);
    Event e63; e63.id = message_id_8015f5a0(&cache_804afdb8, 1); subscribe_80162024(self, &e63.id, &self->f1100);
    Event e64; e64.id = message_id_8015f5a0(&cache_804afdd0, 1); subscribe_80162024(self, &e64.id, &self->f1104);
    int id_arg;
    void *mem = alloc_801613f0(heap_804b1754, 12);
    id_arg = self->f20;
    post_8016239c(init_800c1620(mem, &id_arg));
    query_80126308(&self->f1144, self->f20);
    self->f760 = zero;
    Info *info = query_800fc6dc(self->f584);
    if (info->f192) {
    create_third_80150b6c(self, 1);
    Plain *m = (Plain *)alloc_801613f0(heap_804b1754, 8);
    m->id = message_id_8015f5a0(&cache_804afcb8, 1);
    m->vt = vt_8040db38;
    post_8016239c(m);
    }
    self->f560 = info->v80;
    self->f572 = info->v68;
    if (info->f260) {
        self->f760 = 16;
        self->f672 = engine_80165254()->now - 1000;
        if (self->type()->is_a(type_80361860) || self->type()->is_a(type_803618f0)) log_80022e20(log_803a1270, logic_entity_803a0e2c, 2373, &self->f804);
        set_state_801492ec(self, 37);
    } else {
        target_position_8015324c(self);
    }
    self->f560 = info->v80;
    self->f572 = info->v68;
    self->f828 = *triple_8045e788;
    self->f840 = 0;
    compact_80153a58(self);
    for (int i = 15; i >= 0; i--) self->f1280[i] = -1;
    Handle h(0);
    Item *it = item_800fc710(self->f584, h);
    it->f160 = it->hp;
}
