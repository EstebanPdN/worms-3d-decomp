#include "w3d_ptr.h"
#line 1 "d31d_worm_message_80143794.cpp"
// GWMP8P rev0 0x80143794. Worm logic entity message handler. Names are read from
// the log strings where the original has them, others are inferred from use.
// Virtual slots are reference-ABI observations.
struct Triple { int a, b, c; };
struct Vec { float x, y, z; };
struct TypeDesc {
    char pad[20];
    Ptr32<TypeDesc> parent;
    bool is_a(Ptr32<TypeDesc> target) {
        Ptr32<TypeDesc> t = this;
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
struct ObjVt { char u0[16]; Ptr32<void (Ptr32<Obj>)> release; };
struct Obj { Ptr32<ObjVt> vt; };
struct Ref { Ptr32<Obj> p; };
struct Plain { short id; Ptr32<void> vt; };
struct Handle { int value; unsigned key; Handle(int v) { value = v; key = 58280; } ~Handle(); };
struct Msg { unsigned short id; char u2[6]; int f8; int f12; Vec v16; float f28; int f32; unsigned short Id() const { return id; } };
struct Info { char u0[213]; unsigned char team; };
struct Team { char u0[44]; int f44; char u30[4]; int f52; };
struct Item { char u0[136]; int f136; char u8c[24]; int f164; char ua8[2]; unsigned short hp; };
struct Engine { char u0[52]; int now; };
struct Base {
    int w3d_r_query_interface() __asm__(W3D_SYM("_ZN4Base15query_interfaceEv"));
    void w3d_r_retain() __asm__(W3D_SYM("_ZN4Base6retainEv"));
    void w3d_r_release() __asm__(W3D_SYM("_ZN4Base7releaseEv"));
    Ptr32<TypeDesc> w3d_r_type() __asm__(W3D_SYM("_ZN4Base4typeEv"));
 __attribute__((always_inline)) inline int query_interface() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Base, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void retain() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Base, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Base, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<TypeDesc> type() { return ((Ptr32<TypeDesc> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Base, 5))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Base; };
struct Worm : Base {
     char u4[16] __attribute__((aligned(__alignof__(Base)))); int f20; char u24[284]; int f308; char u312[272]; int f584; float f588; float f592; int f596; int f600; char u604[8]; int f612; int f616; int f620; int f624; int f628; int f632; int f636; int f640; char u644[4]; int f648; int f652; int f656; char u660[4]; int f664; char u668[4]; int f672; Triple f676; char u688[28]; int f716; char u720[16]; int f736; int f740; char u744[4]; int f748; char u752[8]; int f760; char u764[8]; Triple f772; char u784[12]; int f796; Ref f800; int f804; char u808[4]; Ref f812; char u816[308]; Ptr32<Obj> f1124;
};
extern "C" {
int equals_8015f65c(unsigned short, Ptr32<int>);
int base_8015fb34(Ptr32<Worm>, Ptr32<Msg>);
void setup_80146fb8(Ptr32<Worm>);
void shutdown_80142d3c(Ptr32<Worm>);
Ptr32<void> get_803426b4(Ptr32<Obj>);
int active_80178c48(Ptr32<void>);
void damage_step_8014d1cc(Ptr32<Worm>);
void step_8014cd48(Ptr32<Worm>);
void message_8014860c(Ptr32<Worm>, Ptr32<Msg>);
int pair_query_8014de20(Ptr32<Worm>);
void take_damage_80148ef0(Ptr32<Worm>);
int command_801431fc(Ptr32<Worm>, Ptr32<Msg>);
void apply_impulse_80148c14(Ptr32<Worm>, Ptr32<Vec>, float);
void post_owner_80153c74(Ptr32<Worm>);
Ptr32<Item> item_800fc710(int, const Handle &);
void damage_80148a40(Ptr32<Worm>, int);
int owner_8014c488(Ptr32<Worm>);
void punch_8014d65c(Ptr32<Worm>);
int get_int_800fc1f0(Ptr32<Ptr32<const char>>, Ptr32<int>);
int get_int2_800fc230(Ptr32<Ptr32<const char>>, Ptr32<int>);
int log_80022e20(Ptr32<const char>, Ptr32<const char>, int, Ptr32<void>);
void command_reset_801529d8(Ptr32<Worm>, int);
void dying_8015115c(Ptr32<Worm>, Ptr32<Msg>);
void hit_remove_801534e0(Ptr32<Worm>, Ptr32<Msg>);
void bounce_801535cc(Ptr32<Worm>, Ptr32<Msg>);
void post_team_8014f860(Ptr32<Worm>);
void set_state_801492ec(Ptr32<Worm>, int);
void other_8014e774(Ptr32<Worm>, int);
Ptr32<void> alloc_801613f0(Ptr32<void>, int);
short message_id_8015f5a0(Ptr32<int>, int);
int post_8016239c(Ptr32<void>);
void reset_801496f0(Ptr32<Worm>);
Ptr32<Engine> engine_80165254();
void send_8015fc58(Ptr32<Worm>, Ptr32<void>);
void clear_links_8014df84(Ptr32<Worm>, int);
void reset_words_8015286c(Ptr32<Worm>);
void planner_reset_80021234(Ptr32<void>);
int mode_80153f38(Ptr32<Worm>);
Ptr32<Triple> vec_value_80126034(Ptr32<Msg>);
void command_8015fd1c(Ptr32<Worm>);
float range_low_80069a28(Ptr32<Msg>);
void pair_800a8334(Ptr32<Msg>, Ptr32<int>, Ptr32<int>);
void lock_8014f728(Ptr32<Worm>, Ptr32<Msg>);
void unlock_8014f7d8(Ptr32<Worm>, Ptr32<Msg>);
void step_8014f8c0(Ptr32<Worm>);
void slide_start_8014e550(Ptr32<Worm>);
Ptr32<Info> query_800fc6dc(int);
Ptr32<Team> team_800fc7f8(int);
void hit_8014e960(Ptr32<Worm>);
void choose_fall_8014e80c(Ptr32<Worm>);
int value_800a830c(Ptr32<Msg>);
void launch_80150828(Ptr32<Worm>);
void clear_active_8014ffa4(Ptr32<Worm>);
Ptr32<void> int_message_800a82f0(Ptr32<void>, unsigned short, int);
int link_query_8014dc60(Ptr32<Worm>);
int combined_8014b3b4(Ptr32<Worm>);
void start_jump_8014fd38(Ptr32<Worm>);
void step_8014fedc(Ptr32<Worm>);
}
extern Ptr32<void> heap_804b1754;
extern Ptr32<void> planner_804b1760;
extern unsigned char vt_8040db38[];
extern const char str_803a0e0c[];
extern const char str_803a0e1c[];
extern const char str_803a0e2c[];
extern const char str_803a0e40[];
extern const char str_803a0e9c[];
extern const char str_803a0ea8[];
extern const char str_803a0ebc[];
extern int cache_804af764;
extern int cache_804af76c;
extern int cache_804afa98;
extern int cache_804afaa0;
extern int cache_804afaa8;
extern int cache_804afab0;
extern int cache_804afab8;
extern int cache_804afac0;
extern int cache_804afac8;
extern int cache_804afad0;
extern int cache_804afad8;
extern int cache_804afae0;
extern int cache_804afaf0;
extern int cache_804afaf8;
extern int cache_804afb00;
extern int cache_804afb08;
extern int cache_804afb10;
extern int cache_804afb18;
extern int cache_804afb28;
extern int cache_804afb30;
extern int cache_804afb38;
extern int cache_804afb48;
extern int cache_804afb58;
extern int cache_804afb60;
extern int cache_804afb78;
extern int cache_804afb80;
extern int cache_804afb88;
extern int cache_804afb90;
extern int cache_804afbb8;
extern int cache_804afbc0;
extern int cache_804afbc8;
extern int cache_804afbd8;
extern int cache_804afbe0;
extern int cache_804afbe8;
extern int cache_804afbf0;
extern int cache_804afbf8;
extern int cache_804afc00;
extern int cache_804afc08;
extern int cache_804afc18;
extern int cache_804afc38;
extern int cache_804afc48;
extern int cache_804afc78;
extern int cache_804afc80;
extern int cache_804afc88;
extern int cache_804afc98;
extern int cache_804afca0;
extern int cache_804afca8;
extern int cache_804afcb0;
extern int cache_804afcc0;
extern int cache_804afcd0;
extern int cache_804afcf8;
extern int cache_804afd00;
extern int cache_804afd28;
extern int cache_804afd40;
extern int cache_804afd78;
extern int cache_804afd80;
extern int cache_804afd88;
extern int cache_804afd90;
extern int cache_804afd98;
extern int cache_804afda0;
extern int cache_804afda8;
extern int cache_804afdb0;
extern int cache_804afdb8;
extern int cache_804afdd0;
inline void impulse(Ptr32<Worm> w, const Vec &o, float k) { float a = o.x, b = o.y, c = o.z; Vec v; v.x = a; v.y = b; v.z = c; apply_impulse_80148c14(w, &v, k); }
extern "C" int w3d_d31d_worm_message_80143794(Ptr32<Worm> self, Ptr32<Msg> m) {
    unsigned short id = m->Id();
    switch (m->Id()) {
    case 64:
        if (base_8015fb34(self, m) >= 0) { setup_80146fb8(self); goto end; }
        return 0x80004005;
    case 66:
        shutdown_80142d3c(self);
        goto base;
    }
    int active;
    active = active_80178c48(get_803426b4(self->f1124));

    if (equals_8015f65c(id, &cache_804af764)) { damage_step_8014d1cc(self); goto end; }
    if (equals_8015f65c(id, &cache_804af76c)) { step_8014cd48(self); goto end; }
    if (equals_8015f65c(id, &cache_804afb28)) { message_8014860c(self, m); goto end; }
    if (equals_8015f65c(id, &cache_804afbe8)) { if (pair_query_8014de20(self)) { self->f716 = 0; goto post; } }
    if (equals_8015f65c(id, &cache_804afb78)) { take_damage_80148ef0(self); goto end; }
    if (equals_8015f65c(id, &cache_804afb18)) { if (active == self->f584) command_801431fc(self, m); goto end; }
    if (equals_8015f65c(id, &cache_804afb30)) {
        if (m->f8 != self->f20) goto end;
        impulse(self, m->v16, m->f28);
        post_owner_80153c74(self);
        if (m->f12 < 0 || m->f32 == 1) {
            Handle h(0);
            Ptr32<Item> it = item_800fc710(self->f584, h);
            it->f164 += m->f12;
            take_damage_80148ef0(self);
            goto end;
        }
        damage_80148a40(self, m->f12);
        goto end;
    }
    if (equals_8015f65c(id, &cache_804afbb8)) { if (owner_8014c488(self)) { punch_8014d65c(self); goto post; } }
    if (equals_8015f65c(id, &cache_804afcd0)) {
        Ptr32<const char> n = str_803a0e0c;
        int index;
        get_int_800fc1f0(&n, &index);
        if (index == self->f584 && !self->f800.p) {
            if (self->type()->is_a(type_80361860) || self->type()->is_a(type_803618f0)) log_80022e20(str_803a0e1c, str_803a0e2c, 637, &self->f800);
            command_reset_801529d8(self, 0);
        }
        if (index == self->f584) goto post;
        if (!self->f800.p) goto base;
        {
            Ptr32<Obj> none = 0;
            self->f800.p->vt->release(self->f800.p);
            self->f800.p = none;
        }
        goto post;
    }
    if (equals_8015f65c(id, &cache_804afcf8)) { dying_8015115c(self, m); goto post; }
    if (equals_8015f65c(id, &cache_804afb60)) { hit_remove_801534e0(self, m); goto post; }
    if (equals_8015f65c(id, &cache_804afd40)) { bounce_801535cc(self, m); goto post; }
    if (equals_8015f65c(id, &cache_804afb38)) {
        if (active == self->f584) {
            if (self->f652) post_team_8014f860(self); else set_state_801492ec(self, 0);
            if (self->f800.p) { Ptr32<Obj> none = 0; self->f800.p->vt->release(self->f800.p); self->f800.p = none; }
            if (self->type()->is_a(type_80361860) || self->type()->is_a(type_803618f0)) log_80022e20(str_803a0e40, str_803a0e2c, 673, &self->f800);
            command_reset_801529d8(self, 1);
        } else other_8014e774(self, active);
        goto post;
    }
    if (equals_8015f65c(id, &cache_804afbc8)) {
        if (active != self->f584) goto post;
        set_state_801492ec(self, 0);
        self->f760 = 0;
        Ptr32<Plain> p = (Ptr32<Plain>)alloc_801613f0(heap_804b1754, 8); p->id = message_id_8015f5a0(&cache_804afb80, 1); p->vt = vt_8040db38;
        post_8016239c(p);
        reset_801496f0(self);
        goto post;
    }
    if (equals_8015f65c(id, &cache_804afb88)) { if (owner_8014c488(self)) { reset_801496f0(self); engine_80165254(); goto post; } }
    if (equals_8015f65c(id, &cache_804afb80)) {
        if (owner_8014c488(self)) {
            self->f796 = 0;
            Ptr32<Plain> p = (Ptr32<Plain>)alloc_801613f0(heap_804b1754, 8); p->id = message_id_8015f5a0(&cache_804afb90, 1); p->vt = vt_8040db38;
            send_8015fc58(self, p);
            goto post;
        }
    }
    if (equals_8015f65c(id, &cache_804afb48)) {
        self->f624 = 0; self->f620 = 0; self->f616 = 0; self->f612 = 0; self->f640 = 0; self->f636 = 0; self->f632 = 0; self->f656 = 0; self->f736 = 0; self->f664 = 0; self->f628 = 0;
        if (active == self->f584) {
            if (self->f800.p) self->f800.p->vt->release(self->f800.p);
            self->f800.p = 0;
            clear_links_8014df84(self, 1);
        }
        if (owner_8014c488(self) && self->f308 != 15) {
            reset_words_8015286c(self);
            planner_reset_80021234(planner_804b1760);
        }
        goto post;
    }
    if (equals_8015f65c(id, &cache_804afbc0)) {
        if (owner_8014c488(self)) {
            if (!mode_80153f38(self)) {
                if (self->type()->is_a(type_80361860) || self->type()->is_a(type_803618f0)) log_80022e20(str_803a0e9c, str_803a0e2c, 731, &self->f804);
                int now = engine_80165254()->now;
                self->f760 = 14;
                self->f672 = now;
            }
            self->f772 = *vec_value_80126034(m);
            goto post;
        }
    }
    if (equals_8015f65c(id, &cache_804afb58)) {
        self->f624 = 0; self->f620 = 0; self->f616 = 0; self->f612 = 0; self->f640 = 0; self->f636 = 0; self->f632 = 0;
        command_8015fd1c(self);
        goto post;
    }
    if (equals_8015f65c(id, &cache_804afbd8)) { self->f588 = range_low_80069a28(m); goto post; }
    if (equals_8015f65c(id, &cache_804afbe0)) { self->f592 = range_low_80069a28(m); goto post; }
    if (equals_8015f65c(id, &cache_804afb10)) {
        if (owner_8014c488(self)) {
            int a, b;
            pair_800a8334(m, &a, &b);
            self->f596 += a;
            self->f600 += b;
            goto post;
        }
    }
    if (equals_8015f65c(id, &cache_804afca0)) { lock_8014f728(self, m); goto post; }
    if (equals_8015f65c(id, &cache_804afca8)) { unlock_8014f7d8(self, m); goto post; }
    if (equals_8015f65c(id, &cache_804afcb0)) { if (owner_8014c488(self)) step_8014f8c0(self); goto post; }
    if (equals_8015f65c(id, &cache_804afc00)) {
        if (!owner_8014c488(self)) goto post;
        self->f716 = 0;
        self->f760 = 7;
        self->f676 = *vec_value_80126034(m);
        set_state_801492ec(self, 16);
        goto post;
    }
    if (equals_8015f65c(id, &cache_804afc38)) { slide_start_8014e550(self); goto post; }
    if (equals_8015f65c(id, &cache_804afc48)) {
        if (team_800fc7f8(query_800fc6dc(self->f584)->team)->f44) goto post;
        goto fall;
    }
    if (equals_8015f65c(id, &cache_804afd90) || equals_8015f65c(id, &cache_804afda0) || equals_8015f65c(id, &cache_804afdb0)) {
        if (!team_800fc7f8(query_800fc6dc(self->f584)->team)->f52) goto fall;
        goto hit;
    }
    if (equals_8015f65c(id, &cache_804afd98) || equals_8015f65c(id, &cache_804afda8) || equals_8015f65c(id, &cache_804afdb8)) {
        if (team_800fc7f8(query_800fc6dc(self->f584)->team)->f52) goto fall;
    hit:
        hit_8014e960(self);
        goto post;
    fall:
        choose_fall_8014e80c(self);
        goto post;
    }
    if (equals_8015f65c(id, &cache_804afd00)) { value_800a830c(m); goto post; }
    if (equals_8015f65c(id, &cache_804afd28)) { if (value_800a830c(m) == self->f584) launch_80150828(self); goto post; }
    if (equals_8015f65c(id, &cache_804afc08)) {
        if (!owner_8014c488(self)) goto base;
        Ptr32<Plain> p = (Ptr32<Plain>)alloc_801613f0(heap_804b1754, 8); p->id = message_id_8015f5a0(&cache_804afb80, 1); p->vt = vt_8040db38;
        post_8016239c(p);
        goto base;
    }
    if (equals_8015f65c(id, &cache_804afbf0)) { clear_links_8014df84(self, 0); return base_8015fb34(self, m); }
    if (equals_8015f65c(id, &cache_804afbf8)) { clear_links_8014df84(self, 0); self->f628 = 0; goto base; }
    if (equals_8015f65c(id, &cache_804afc18)) {
        if (value_800a830c(m) == self->f584) { self->f796 = 0; clear_links_8014df84(self, 0); }
        return base_8015fb34(self, m);
    }
    if (equals_8015f65c(id, &cache_804afdd0)) { clear_links_8014df84(self, 1); goto base; }
    if (equals_8015f65c(id, &cache_804afcc0)) { if (value_800a830c(m) == self->f584) clear_active_8014ffa4(self); goto post; }
    if (equals_8015f65c(id, &cache_804afc78)) {
        int v = value_800a830c(m);
        if (v != self->f584) goto post;
        Handle h(0);
        Ptr32<Item> it = item_800fc710(v, h);
        if (!it->f136 && !self->f652) {
            Ptr32<const char> n = str_803a0ea8;
            int x;
            get_int2_800fc230(&n, &x);
            Ptr32<int> slot = &it->f136; *slot = x;
            Ptr32<void> q = alloc_801613f0(heap_804b1754, 12);
            post_8016239c(int_message_800a82f0(q, message_id_8015f5a0(&cache_804afd80, 1), self->f584));
        }
        goto post;
    }
    if (equals_8015f65c(id, &cache_804afc80)) {
        int v = value_800a830c(m);
        if (v != self->f584) goto post;
        if (self->f652) goto post;
        Handle h(0);
        item_800fc710(v, h)->f136 = 0;
        goto post;
    }
    if (equals_8015f65c(id, &cache_804afc88)) {
        Handle h(0);
        Ptr32<Item> it = item_800fc710(self->f584, h);
        int hp = it->hp;
        int d = it->f136;
        if (hp <= d && !self->f648) { it->f136 = 0; d = hp - 1; }
        d += it->f164;
        it->f164 = d;
        take_damage_80148ef0(self);
        Ptr32<void> q = alloc_801613f0(heap_804b1754, 12);
        post_8016239c(int_message_800a82f0(q, message_id_8015f5a0(&cache_804afb60, 1), self->f584));
        goto post;
    }
    if (equals_8015f65c(id, &cache_804afd78)) {
        if (self->f812.p) self->f812.p->vt->release(self->f812.p);
        self->f812.p = 0;
        goto post;
    }
    if (equals_8015f65c(id, &cache_804afd88)) { if (owner_8014c488(self)) self->f664 = 1; }
post:
    if (!self->f800.p) goto base;
    if (link_query_8014dc60(self)) goto base;
    if (equals_8015f65c(id, &cache_804afa98)) { self->f620 = 1; goto base; }
    if (equals_8015f65c(id, &cache_804afaa0)) { self->f620 = 0; goto base; }
    if (equals_8015f65c(id, &cache_804afaa8)) { self->f624 = 1; goto base; }
    if (equals_8015f65c(id, &cache_804afab0)) { self->f624 = 0; goto base; }
    if (equals_8015f65c(id, &cache_804afab8)) { self->f612 = 1; goto base; }
    if (equals_8015f65c(id, &cache_804afac0)) { self->f612 = 0; goto base; }
    if (equals_8015f65c(id, &cache_804afac8)) { self->f616 = 1; goto base; }
    if (equals_8015f65c(id, &cache_804afad0)) { self->f616 = 0; goto base; }
    if (equals_8015f65c(id, &cache_804afc98)) {
        Ptr32<const char> n = str_803a0ebc;
        int x;
        get_int2_800fc230(&n, &x);
        self->f628 = x == 1 || x == 3;
        goto base;
    }
    if (active != self->f584) goto base;
    if (equals_8015f65c(id, &cache_804afaf0)) {
        if (!self->f632) {
            self->f632 = 1;
            int now = engine_80165254()->now;
            self->f740 = now;
            self->f748 = now;
        }
        goto base;
    }
    if (equals_8015f65c(id, &cache_804afaf8)) { self->f632 = 0; goto stamp; }
    if (equals_8015f65c(id, &cache_804afb00)) {
        if (self->f636) goto end;
        self->f636 = 1;
        int now = engine_80165254()->now;
        self->f740 = now;
        self->f748 = now;
        goto end;
    }
    if (equals_8015f65c(id, &cache_804afb08)) {
        self->f636 = 0;
    stamp:
        self->f740 = engine_80165254()->now;
        goto end;
    }
    if (equals_8015f65c(id, &cache_804afad8)) { if (!combined_8014b3b4(self)) { start_jump_8014fd38(self); goto end; } }
    if (equals_8015f65c(id, &cache_804afae0)) { step_8014fedc(self); goto end; }
base:
    return base_8015fb34(self, m);
end:
    return 0;
}


