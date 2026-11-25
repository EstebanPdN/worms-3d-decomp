// d41d: 0x80144904. Per-frame simulation update of a worm: state machine over
// f760, physics hand-off to the simulation entry, animation selection, and the
// reschedule. Class fields are partial views of what this function touches.
// The repeated `self->f752 = now; break;` and zero-vector arms are written out
// in each case and merge only by cross-jumping after reload, as does the
// if/else store of f760 in the landing arm.
extern "C" float sqrtf_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec operator*(float k) const { Vec r; r.x = x * k; r.y = y * k; r.z = z * k; return r; }
    bool operator==(const Vec &o) const { return *(const int *)&x == *(const int *)&o.x && *(const int *)&y == *(const int *)&o.y && *(const int *)&z == *(const int *)&o.z; }
    void clear() { x = 0.0f; y = 0.0f; z = 0.0f; }
    float len() const { return sqrtf_802e82c0(x * x + y * y + z * z); }
    void scale(float k) { x *= k; y *= k; z *= k; }
};
struct Obj;
struct ObjVt { char u0[12]; void (*retain)(Obj *); void (*release)(Obj *); };
struct Obj { ObjVt *vt; };
struct Ref {
    Obj *p;
    void reset(Obj *q) { if (p) p->vt->release(p); p = q; }
    void drop() { if (p) { Obj *q = 0; p->vt->release(p); p = q; } }
};
struct Coll { int a; };
struct TypeDesc {
    char u0[20]; TypeDesc *parent;
    bool is_a(TypeDesc *t) { TypeDesc *c = this; while (c != t) { if (c == c->parent) return false; c = c->parent; } return true; }
};
struct Descriptor_80178474 { int value; unsigned key; Descriptor_80178474(int v) { value = v; key = 58280; } ~Descriptor_80178474(); };
struct Plain { short id; void *vt; };
struct Item { char u0[20]; Vec f20; Vec f32; Vec f44; char u38[12]; Vec f68; Vec f80; char u5c[32]; float f124; char u80[4]; int f132; char u88[44]; int f180; char ub8[16]; int f200; char ucc[16]; int f220; char ue0[24]; int f248; };
struct Team { char u0[152]; unsigned char a, b; };
struct Worm;
struct WormVt { char u0[20]; TypeDesc *(*type)(Worm *); };
struct Engine { char u0[52]; unsigned now; };
struct Worm {
    WormVt *vt;
    char u4[296];
    int f300;
    char u304[240];
    Obj *f544;
    Obj *f548;
    Obj *f552;
    char u556[4];
    Vec f560;
    Vec f572;
    int f584;
    float f588;
    char u592[36];
    int f628;
    int f632;
    int f636;
    char u640[8];
    int f648;
    int f652;
    int f656;
    int f660;
    int f664;
    unsigned f668;
    unsigned f672;
    Vec f676;
    char u688[4];
    float f692;
    char u696[20];
    int f716;
    int f720;
    Vec f724;
    char u736[8];
    int f744;
    char u748[4];
    unsigned f752;
    int f756;
    int f760;
    int f764;
    float f768;
    Vec f772;
    int f784;
    int f788;
    int f792;
    int f796;
    Ref f800;
    Ref f804;
    char u808[16];
    int f824;
    char u828[16];
    int f844;
    char u848[260];
    Obj *f1108;
    char u1112[40];
    Coll f1152;
    char u1156[48];
    Vec f1204;
    char u1216[12];
    Obj *f1228;
    Obj *f1232;
};
extern "C" {
int scene_8006e71c();
void *alloc_801613f0(void *, int);
short message_id_8015f5a0(int *, int);
int send_to_8015fc58(Worm *, void *);
int post_8016239c(void *);
void *msg_init_800a82f0(void *, unsigned short, int);
Item *query_800fc6dc(int);
Item *item_800fc710(int, const Descriptor_80178474 &);
float value_80178df0(Obj *);
Obj *cast_80342a74(Obj *);
Obj *cast_80342a78(Obj *);
int update_80178d28(Obj *, int *);
void behaviour_801515a4(Worm *);
void target_8015324c(Worm *);
void air_move_80146190(Worm *);
void drown_80149f18(Worm *);
int coll_8014c7fc(const Vec *);
int ok_8014c488(Worm *);
void empty_8014fd34(Worm *);
void turn_8014b6b0(Worm *);
int b3b4_8014b3b4(Worm *);
void yaw_8015139c(Worm *);
int has_motion_8014c3f4(Worm *);
void f34_80146f34(Worm *);
int spot_8014a9f8(Worm *, Vec *);
int linkb_8014decc(Worm *);
void air_step_8014e9ec(Worm *);
int jump_8014ae84(Worm *, Vec *);
void rot_8014fb40(Worm *);
int near_8014d59c(Worm *);
void walk_8014a510(Worm *);
void land_8014b498(Worm *);
Vec dir_80146f10(Worm *);
int b84_80146b84(Worm *);
int contact_801418c4(Coll *);
void b40c_8014b40c(Worm *);
int df28_8014df28(Worm *);
void e3d4_8014e3d4(Worm *);
void e44c_8014e44c(Worm *);
int trace_80022e20(const char *, const char *, int, Ref *);
int dc60_8014dc60(Worm *);
void air_8014f8cc(Worm *);
int h_801510c4(Worm *);
void bob_8014e170(Worm *);
void step_801502f0(Worm *);
void stop_80150018(Worm *);
void set_801492ec(Worm *, int);
Engine *engine_80165254();
int db4_80153db4(Worm *);
int read_800fc330(const char **, Team **);
int fwd_800fdd80(unsigned char, unsigned char, const Vec *, int, int);
void notify_800fdf24(const Vec *);
int fwd_800e5ca4(const Vec *, const char *, int, float);
void notify_800fde64(int);
void r_8015286c(Worm *);
void g_80020b20(void *);
void fd1c_8015fd1c(Worm *);
void death_8014cb88(Worm *);
int de70_8014de70(Worm *);
void jet_8014d7c8(Worm *);
void track_8014da00(Worm *);
int follow_8014dd18(Worm *);
int dc04_8014dc04(Worm *);
void e104_8014e104(Worm *, unsigned);
int dcbc_8014dcbc(Worm *);
void mode_8012f964(int);
}
extern void *heap_804b1754;
extern unsigned char vt_8040db38[];
extern Vec zero_8045e788[];
extern TypeDesc type_80361860[], type_803618f0[];
extern int cache_804afb70, cache_804afb80, cache_804afd48, cache_804afd50, cache_804afd08;
extern int global_804b1760;
extern float limit_804aafac;
extern int last_804ab3e4;
extern char file_803a0e2c[], s_803a0ed0[], s_803a0ef8[], s_803a0f14[], s_803a0f28[], s_803a0f50[], s_803a0f68[], s_803a0f40[], s_803a089c[];
extern float m025_803a0f90[], c001_803a0f94[], c100_803a0f98[];
inline void post_plain(int *cache) {
    Plain *p = (Plain *)alloc_801613f0(heap_804b1754, 8);
    p->id = message_id_8015f5a0(cache, 1);
    p->vt = vt_8040db38;
    post_8016239c(p);
}
inline void post_to(Worm *self, int *cache) {
    Plain *p = (Plain *)alloc_801613f0(heap_804b1754, 8);
    p->id = message_id_8015f5a0(cache, 1);
    p->vt = vt_8040db38;
    send_to_8015fc58(self, p);
}
#define post_id(cache, id) post_8016239c(msg_init_800a82f0(alloc_801613f0(heap_804b1754, 12), message_id_8015f5a0(cache, 1), id))
#define trace(self, name, line) if ((self)->vt->type(self)->is_a(type_80361860) || (self)->vt->type(self)->is_a(type_803618f0)) trace_80022e20(name, file_803a0e2c, line, &(self)->f804)
extern "C" int w3d_d41d_worm_sim_update_80144904(Worm *self, unsigned ms) {
    int r = scene_8006e71c();
    if (r) { post_to(self, &cache_804afb70); return 20; }
    Item *it = query_800fc6dc(self->f584);
    if (it->f220 == 0) return 20;
    self->f560 = it->f80;
    self->f572 = it->f68;
    {
        float a = value_80178df0(self->f544);
        self->f692 = a * value_80178df0(self->f548);
    }
    if (self->f300) behaviour_801515a4(self);
    target_8015324c(self);
    self->f764 = self->f760;
    air_move_80146190(self);
    drown_80149f18(self);
    if (self->f760 != 9) self->f844 = r;
    int zero = 0;
    self->f720 = zero;
    switch (self->f760) {
    case 0:
        self->f804.reset((Obj *)zero);
        self->f744 = zero;
        if ((self->f716 || self->f824 < 0) && coll_8014c7fc(&self->f1204)) goto c0;
        self->f760 = 7;
        trace(self, s_803a0ed0, 1075);
        break;
    c0:
        self->f572.x = 0.0f;
        if (!ok_8014c488(self)) { self->f676 = *zero_8045e788; break; }
        empty_8014fd34(self);
        if ((self->f632 || self->f636 || (self->f588 != 0.0f && self->f628 == 1)) && self->f800.p && !self->f648) { turn_8014b6b0(self); break; }
        if (b3b4_8014b3b4(self)) { yaw_8015139c(self); break; }
        if (has_motion_8014c3f4(self)) {
            f34_80146f34(self);
            if (!spot_8014a9f8(self, &self->f676)) self->f760 = 1;
            else self->f676 = *zero_8045e788;
        }
        break;
    case 1:
        if (linkb_8014decc(self)) { self->f760 = 7; break; }
        if (self->f716 || self->f824 < 0) {
            f34_80146f34(self);
            if (ok_8014c488(self) && has_motion_8014c3f4(self)) {
                if (!spot_8014a9f8(self, &self->f676)) { air_step_8014e9ec(self); break; }
                if (jump_8014ae84(self, &self->f676)) { rot_8014fb40(self); break; }
                self->f760 = zero;
                self->f676 = *zero_8045e788;
                break;
            }
            self->f760 = 0;
            self->f676 = *zero_8045e788;
            break;
        }
        if (!near_8014d59c(self)) self->f760 = 7;
        break;
    case 2: case 3: case 4: case 5:
        walk_8014a510(self);
        break;
    case 6: case 7: case 8:
        if (self->f716 || self->f824 < 0) {
            land_8014b498(self);
            self->f572.x = 0.0f;
            self->f724 = *zero_8045e788;
            self->f744 = zero;
            Vec d = dir_80146f10(self);
            if ((self->f824 < 0 && b84_80146b84(self)) || (contact_801418c4(&self->f1152) && coll_8014c7fc(&d))) {
int v = self->f660;
if (v) self->f760 = 25; else self->f760 = v;
self->f676 = *zero_8045e788;
                self->f572.x = 6.2831855f;
                self->f572.z = 0.0f;
                const Vec &q = it->f68;
                self->f572.y = q.y;
                break;
            }
            Vec *mv = &self->f676;
            bool same = *(int *)&zero_8045e788->x == *(int *)&mv->x && *(int *)&zero_8045e788->y == *(int *)&mv->y && *(int *)&zero_8045e788->z == *(int *)&mv->z;
            if (same) {
                float k = value_80178df0(cast_80342a74(self->f552));
                self->f676 = dir_80146f10(self) * k * 10.0f;
            }
            b40c_8014b40c(self);
            if (df28_8014df28(self)) {
                self->f676.scale(0.6f);
            } else self->f760 = 9;
            break;
        }
        e3d4_8014e3d4(self);
        e44c_8014e44c(self);
        if (self->f760 == 8) self->f572.x += 0.1f;
        if (!self->f804.p) trace(self, s_803a0ed0, 1204);
        if (!dc60_8014dc60(self) && self->f760 != 8) air_8014f8cc(self);
        if (!h_801510c4(self) && self->f676.y < m025_803a0f90[0]) {
            self->f760 = 8;
            self->f724 = *zero_8045e788;
            if (query_800fc6dc(self->f584)->f132 == 13) post_plain(&cache_804afb80);
        }
        break;
    case 21:
        bob_8014e170(self);
        break;
    case 9: case 26:
        if (self->f716 || self->f824 < 0) { land_8014b498(self); step_801502f0(self); }
        break;
    case 11:
        if (self->f716 || self->f824 < 0) { land_8014b498(self); stop_80150018(self); }
        break;
    case 12:
        set_801492ec(self, 9);
        self->f676.clear();
        if (!self->f752) { self->f752 = engine_80165254()->now; break; }
        if (engine_80165254()->now > self->f752 + 2500) { self->f760 = zero; self->f752 = zero; self->f804.reset((Obj *)zero); self->f800.reset((Obj *)zero); }
        break;
    case 10:
        set_801492ec(self, 35);
        self->f676 = *zero_8045e788;
        if (!self->f752) { self->f752 = engine_80165254()->now; break; }
        if (engine_80165254()->now <= self->f752 + 10) break;
        self->f760 = zero;
        if (!ok_8014c488(self) && db4_80153db4(self)) set_801492ec(self, 11);
        self->f752 = 0;
        self->f804.reset(0);
        break;
    case 25:
        self->f676 = *zero_8045e788;
        if (!self->f752) {
            self->f752 = engine_80165254()->now;
            break;
        }
        if (engine_80165254()->now <= self->f752 + 3000) break;
        self->f760 = zero;
        self->f752 = zero;
        self->f804.reset((Obj *)zero);
        self->f800.reset((Obj *)zero);
        break;
    case 14:
        self->f676.clear();
        if (engine_80165254()->now > self->f672 + 1000) {
            self->f672 = engine_80165254()->now;
            self->f760 = 15;
            const char *key;
            Team *team;
            trace(self, s_803a0ef8, 1313);
            key = s_803a089c;
            read_800fc330(&key, &team);
            fwd_800fdd80(team->b, team->a, &self->f560, 200, 0);
        }
        break;
    case 15:
        if (engine_80165254()->now > self->f672 + 1000) {
            self->f560 = self->f772;
            self->f760 = 16;
            self->f672 = engine_80165254()->now;
            notify_800fdf24(&self->f560);
            trace(self, s_803a0f14, 1331);
        }
        break;
    case 16:
        if (engine_80165254()->now > self->f672 + 1000) {
            self->f760 = 17;
            self->f672 = engine_80165254()->now;
            trace(self, s_803a0f28, 1338);
            fwd_800e5ca4(&self->f772, s_803a0f40, 0, 0.0f);
        }
        break;
    case 17:
        if (engine_80165254()->now > self->f672 + 1000) {
            self->f760 = 18;
            self->f672 = engine_80165254()->now;
            trace(self, s_803a0f50, 1347);
        }
        break;
    case 18:
        self->f676.clear();
        if (engine_80165254()->now > self->f672 + 1050) {
            self->f716 = zero;
            self->f824 &= 0x7fffffff;
            self->f760 = 7;
            notify_800fde64(200);
            trace(self, s_803a0f68, 1359);
        }
        break;
    case 27:
        self->f676 = *zero_8045e788;
        {
            float a = value_80178df0(self->f1232);
            a -= value_80178df0(self->f1228);
            if (self->f560.y > a) self->f560.y = a;
        }
    case 19: case 20:
        if (self->f648 && self->f668 <= engine_80165254()->now) {
            self->f668 = 1000;
            if (self->f300 && ok_8014c488(self)) { r_8015286c(self); g_80020b20((void *)global_804b1760); }
            {
                Descriptor_80178474 h(0);
                item_800fc710(self->f584, h)->f220 = 0;
            }
            update_80178d28(cast_80342a78(self->f1108), &self->f584);
            if (self->f760 == 20) post_id(&cache_804afd48, self->f584);
            else post_id(&cache_804afd50, self->f584);
            post_id(&cache_804afd08, self->f584);
            self->f800.drop();
            self->f804.drop();
            fd1c_8015fd1c(self);
            if (self->f760 == 20 || self->f760 == 27) death_8014cb88(self);
            return -1;
        }
        break;
    case 22: case 23: case 24:
        if (self->f716 || self->f824 < 0) {
            self->f676 = *zero_8045e788;
        }
        break;
    case 13:
        break;
    }
    if (de70_8014de70(self)) jet_8014d7c8(self);
    track_8014da00(self);
    {
        int fol = follow_8014dd18(self);
        if (!self->f648) {
            if (self->f652) set_801492ec(self, 28);
            else if (self->f784 != -1 && !self->f716 && self->f824 >= 0 && df28_8014df28(self)) set_801492ec(self, 14);
            else if (self->f788 != -1 && fol) set_801492ec(self, 15);
            else if (self->f792 != -1 && dc04_8014dc04(self)) set_801492ec(self, 19);
            else switch (self->f760) {
            case 0:
                if (ok_8014c488(self)) {
                    if (!self->f764 && self->f800.p && self->f796) { set_801492ec(self, 10); self->f756 = ms + 1000; }
                    else { set_801492ec(self, 0); e104_8014e104(self, ms); }
                }
                break;
            case 1:
                if (self->f676.len() > c001_803a0f94[0]) set_801492ec(self, 1);
                else set_801492ec(self, 18);
                break;
            case 9: set_801492ec(self, 7); break;
            case 11: set_801492ec(self, 8); break;
            case 22: set_801492ec(self, 24); break;
            case 23: set_801492ec(self, 25); break;
            case 24: set_801492ec(self, 43); break;
            case 7: if (!self->f784) set_801492ec(self, 26); break;
            case 8: set_801492ec(self, 38); break;
            case 25: set_801492ec(self, 27); break;
            case 26: set_801492ec(self, 31); break;
            case 15: case 16: case 17: set_801492ec(self, 37); break;
            case 10: set_801492ec(self, 35); break;
            }
        }
    }
    if (ok_8014c488(self)) {
        if ((unsigned)self->f760 <= 1 && !dcbc_8014dcbc(self)) mode_8012f964(0);
        else if (self->f760 == 13 || de70_8014de70(self) || dc04_8014dc04(self) || dcbc_8014dcbc(self)) mode_8012f964(2);
        else mode_8012f964(1);
    }
    {
        Descriptor_80178474 h(0);
        Item *out = item_800fc710(self->f584, h);
        float over = self->f560.y;
        if (over > limit_804aafac && self->f676.y > 0.0f) {
            over -= limit_804aafac;
            if (over > c100_803a0f98[0]) self->f676.y = 0.0f;
            else self->f676.y = self->f676.y * (c100_803a0f98[0] - over) / c100_803a0f98[0];
        }
        out->f80 = self->f560;
        while (self->f572.y < 0.0f) self->f572.y += 6.2831855f;
        while (self->f572.y > 6.2831855f) self->f572.y -= 6.2831855f;
        out->f68 = self->f572;
        out->f44 = self->f676;
        out->f124 = self->f768;
        out->f32 = self->f1204;
        out->f200 = self->f720;
        out->f20 = self->f724;
        out->f180 = self->f656;
        out->f248 = self->f664;
    }
    if (ok_8014c488(self)) last_804ab3e4 = self->f760;
    post_to(self, &cache_804afb70);
    unsigned m = ms % 20;
    return 20 - m;
}

