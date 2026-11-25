#include "w3d_ptr.h"
#line 1 "d28d_worm_take_damage_80148ef0.cpp"
// GWMP8P rev0 0x80148ef0. Worm pending damage. Names are inferred from use
// and the log strings. Virtual slots are reference-ABI observations.
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
struct Object {
    int w3d_r_query_interface() __asm__(W3D_SYM("_ZN6Object15query_interfaceEv"));
    void w3d_r_retain() __asm__(W3D_SYM("_ZN6Object6retainEv"));
    void w3d_r_release() __asm__(W3D_SYM("_ZN6Object7releaseEv"));
    Ptr32<TypeDesc> w3d_r_type() __asm__(W3D_SYM("_ZN6Object4typeEv"));
 __attribute__((always_inline)) inline int query_interface() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Object, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void retain() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Object, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Object, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<TypeDesc> type() { return ((Ptr32<TypeDesc> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Object, 5))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Object; };
struct Worm : Object {
    char u4[16] __attribute__((aligned(__alignof__(Object)))); int id; char u18[560]; int index; char u24c[60]; int dying; char u28c[8]; int f660; char u298[52]; int moving; char u2d0[88]; int slotA; int slotB; char u32c[8]; int flags; char u33c[284];
    Ptr32<void> barA; Ptr32<void> barB; char u460[132]; Ptr32<void> anim;
};
struct Info { char u0[164]; int alive; char u168[45]; unsigned char team; char ud6[6]; int active; };
struct Item { char u0[80]; Vec v; char u5c[72]; int pending; char ua8[2]; unsigned short hp; };
struct Anim { char u0[60]; int mode; };
struct Handle { int value; unsigned key; Handle(int v) { value = v; key = 58280; } ~Handle(); };
struct Message;
struct Plain { short id; Ptr32<void> vt; };
extern "C" Ptr32<Info> query_800fc6dc(int);
extern "C" Ptr32<Anim> anim_801797b4(Ptr32<void>);
extern "C" Ptr32<Item> item_800fc710(int, const Handle &);
extern "C" int log_80022e20(Ptr32<const char>, Ptr32<const char>, int, Ptr32<int>);
extern const char logic_entity_803a0e2c[];
extern const char active_worm_803a0e0c[];
extern "C" Ptr32<void> alloc_801613f0(Ptr32<void>, int);
extern "C" short msg_id_8015f5a0(Ptr32<void>, int);
extern "C" Ptr32<void> target_message_801190b4(Ptr32<void>, unsigned short, int);
extern "C" Ptr32<void> int_message_800a82f0(Ptr32<void>, unsigned short, int);
extern "C" int post_8016239c(Ptr32<void>);
extern "C" int setting_800fc1f0(Ptr32<Ptr32<const char>>, Ptr32<int>);
extern "C" void set_state_801492ec(Ptr32<Worm>, int);
extern "C" Ptr32<void> get_803426b4(Ptr32<void>);
extern "C" Ptr32<void> get_80342fa4(Ptr32<void>);
extern "C" int update_80178c54(Ptr32<void>, Ptr32<const int>);
extern "C" int set_vector_80178fa4(Ptr32<void>, Ptr32<const Vec>);
struct Engine { char u0[52]; int now; };
extern "C" Ptr32<Engine> engine_80165254();
extern "C" int pool_add_800c53a0(Ptr32<void>, int);
extern "C" void check_801506f8(Ptr32<Worm>);
extern Ptr32<void> heap_804b1754;
extern int cacheA_804afcf0, cacheB_804afd10, cacheC_804afba0, cacheD_804afd78;
extern unsigned char vt_8040db38[];
extern "C" void d28d_worm_take_damage_80148ef0(Ptr32<Worm> self) {
    int zero = 0;
    self->f660 = zero;
    Ptr32<Info> info = query_800fc6dc(self->index);
    if (!info->active) return;
    if (!info->alive) return;
    if (anim_801797b4(self->anim)->mode == 1) return;
    Handle h(zero);
    Ptr32<Item> it = item_800fc710(self->index, h);
    int hp = it->hp;
    int dmg = it->pending;
    if (dmg >= hp) {
        it->hp = zero;
        self->dying = 1;
        if (self->type()->is_a(type_80361860) || self->type()->is_a(type_803618f0)) log_80022e20("Worm Waiting To Die", logic_entity_803a0e2c, 2610, &self->slotA);
        post_8016239c(target_message_801190b4(alloc_801613f0(heap_804b1754, 12), msg_id_8015f5a0(&cacheA_804afcf0, 1), self->id));
    } else {
        if (dmg > 0) {
            Ptr32<const char> name = active_worm_803a0e0c;
            int active = zero;
            setting_800fc1f0(&name, &active);
            int team = query_800fc6dc(active)->team;
            if (team == query_800fc6dc(self->index)->team)
                post_8016239c(int_message_800a82f0(alloc_801613f0(heap_804b1754, 12), msg_id_8015f5a0(&cacheB_804afd10, 1), -dmg));
            else
                post_8016239c(int_message_800a82f0(alloc_801613f0(heap_804b1754, 12), msg_id_8015f5a0(&cacheB_804afd10, 1), dmg));
        }
        it->hp = hp - (unsigned short)dmg;
        if (dmg > 0 && (self->moving || self->flags < 0)) set_state_801492ec(self, 11);
    }
    it->pending = 0;
    update_80178c54(get_803426b4(self->barA), &dmg);
    set_vector_80178fa4(get_80342fa4(self->barB), &it->v);
    Ptr32<Plain> m = (Ptr32<Plain>)alloc_801613f0(heap_804b1754, 8);
    m->id = msg_id_8015f5a0(&cacheC_804afba0, 1);
    m->vt = vt_8040db38;
    post_8016239c(m);
    Ptr32<Plain> n = (Ptr32<Plain>)alloc_801613f0(heap_804b1754, 8);
    n->id = msg_id_8015f5a0(&cacheD_804afd78, 1);
    n->vt = vt_8040db38;
    pool_add_800c53a0(n, engine_80165254()->now + 2500);
    if (self->type()->is_a(type_80361860) || self->type()->is_a(type_803618f0)) log_80022e20("Worm Taking Damage", logic_entity_803a0e2c, 2655, &self->slotB);
    check_801506f8(self);
}


