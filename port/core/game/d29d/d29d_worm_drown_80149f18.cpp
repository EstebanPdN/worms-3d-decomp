#include "w3d_ptr.h"
#line 1 "d29d_worm_drown_80149f18.cpp"
// GWMP8P rev0 0x80149f18. Worm drowning check: once below the water level by the
// drown height the worm loses all hit points, plays the splash, is given a new
// state and a replacement active worm is chosen. Names are inferred from use and
// the log strings; virtual slots are reference-ABI observations.
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
struct Plain { short id; Ptr32<void> vt; };
struct Handle { int value; unsigned key; Handle(int v) { value = v; key = 58280; } ~Handle(); };
struct Item { char u0[80]; Vec v80; char u5c[36]; int f128; char u84[32]; int f164; char ua8[2]; unsigned short hp; char uac[41]; unsigned char team; char ud6[6]; int f220; };
struct Engine { char u0[52]; int now; };
struct Base {
    int w3d_r_query_interface() __asm__(W3D_SYM("_ZN4Base15query_interfaceEv"));
    void w3d_r_retain() __asm__(W3D_SYM("_ZN4Base6retainEv"));
    void w3d_r_release() __asm__(W3D_SYM("_ZN4Base7releaseEv"));
    Ptr32<TypeDesc> w3d_r_type() __asm__(W3D_SYM("_ZN4Base4typeEv"));
 __attribute__((always_inline)) inline int query_interface() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Base, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void retain() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Base, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Base, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<TypeDesc> type() { return ((Ptr32<TypeDesc> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Base, 5))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Base; };
struct Worm : Base {
    char u4[556] __attribute__((aligned(__alignof__(Base)))); Vec f560; char u23c[12]; int f584; char u24c[60]; int f648; char u28c[16]; int f668; char u2a0[4]; Vec f676; Triple f688; char u2bc[16]; int f716; char u2d0[40]; int f760; char u2fc[40]; int f804; char u328[16]; unsigned f824; char u33c[296]; Ptr32<void> f1124; char u468[100]; Ptr32<void> f1228; Ptr32<void> f1232;
};
extern "C" {
float value_80178df0(Ptr32<void>);
Ptr32<Item> item_800fc710(int, const Handle &);
Ptr32<void> alloc_801613f0(Ptr32<void>, int);
short message_id_8015f5a0(Ptr32<int>, int);
Ptr32<void> int_message_800a82f0(Ptr32<void>, unsigned short, int);
int post_8016239c(Ptr32<void>);
int owner_8014c488(Ptr32<Worm>);
void clear_links_8014df84(Ptr32<Worm>, int);
int falling_8014fcac(Ptr32<Worm>);
void track_80150828(Ptr32<Worm>);
// v26 (core/native/ahogo.cpp): ahogo de Ultimate Mayhem y prueba de ahogo.
int w3d_ahogo_um_entrar(int, int, unsigned);
int w3d_prueba_ahogo_toca(int);
int w3d_prueba_ahogo_somero(void);
float w3d_prueba_ahogo_altura(void);
float w3d_prueba_ahogo_vx(void);
void w3d_prueba_ahogo_log(int, float, float, float, int);
void set_state_801492ec(Ptr32<Worm>, int);
Ptr32<Engine> engine_80165254();
int log_80022e20(Ptr32<const char>, Ptr32<const char>, int, Ptr32<int>);
int splash_800e5ca4(Ptr32<Vec>, Ptr32<const char>, int, float);
Ptr32<void> get_803426b4(Ptr32<void>);
int active_80178c48(Ptr32<void>);
int get_80158dc4(Ptr32<void>);
void set_80158dcc(Ptr32<void>, int);
Ptr32<Item> query_800fc6dc(int);
float sqrt_802e82c0(float);
}
extern Ptr32<void> heap_804b1754;
extern unsigned char vt_8040db38[];
extern Triple triple_8045e788[];
extern int cache_804afb60;
extern int cache_804afb68;
extern int cache_804afd30;
extern int cache_804afd38;
extern int cache_804afc58;
extern Ptr32<void> turns_804ab400;
extern const char str_803a1308[];
extern const char str_803a131c[];
extern const char str_803a1328[];
extern const char str_803a0e2c[];
inline void splash(Ptr32<Worm> self, const Vec &o) {
    float a = o.x, b = o.y, c = o.z;
    Vec v;
    v.x = a; v.y = b; v.z = c;
    float k = value_80178df0(self->f1232);
    int n = (int)(k * 16.0f);
    v.y = (float)(n | 1) * 0.0625f;
    splash_800e5ca4(&v, str_803a131c, 0, 0.0f);
}
inline void post_plain(Ptr32<int> cache) {
    Ptr32<Plain> p = (Ptr32<Plain>)alloc_801613f0(heap_804b1754, 8);
    p->id = message_id_8015f5a0(cache, 1);
    p->vt = vt_8040db38;
    post_8016239c(p);
}
// v25, prueba de ahogo (W3D_PRUEBA_AHOGO): busca alrededor del worm el punto más cercano con agua honda según la misma
// prueba del juego (8014fcac desde 8 bajo el agua, como al ahogarse), y deja al worm 60 por encima del agua, cayendo.
// Solo para las pruebas: sin la opción no se llama.
// v26: anillos de 20 en 20 unidades desde 60, y la caída debe estar libre: desde 92 sobre el agua, 8014fcac no toca
// nada en 100 unidades; en agua honda, tampoco a 50 unidades en 4 direcciones (antes caía a veces dentro de una
// construcción sobre el agua o pegado a una pared, y no se veía).
// W3D_PRUEBA_AHOGO_SOMERO=1: agua poco profunda, es decir, desde 8 bajo el agua 8014fcac toca suelo a menos de 100.
// W3D_PRUEBA_AHOGO_ALTURA=<h> (60) y W3D_PRUEBA_AHOGO_VX=<v> (0): altura y velocidad en x; con h < 0 queda de pie (kStatic).
// La cámara sigue al worm con la cámara de seguir worms del juego (0x80150828, la de un worm lanzado por una explosión).
inline void prueba_ahogo(Ptr32<Worm> self) {
    static const float kDir[16][2] = {
        {1.0f, 0.0f}, {0.92388f, 0.38268f}, {0.70711f, 0.70711f}, {0.38268f, 0.92388f},
        {0.0f, 1.0f}, {-0.38268f, 0.92388f}, {-0.70711f, 0.70711f}, {-0.92388f, 0.38268f},
        {-1.0f, 0.0f}, {-0.92388f, -0.38268f}, {-0.70711f, -0.70711f}, {-0.38268f, -0.92388f},
        {0.0f, -1.0f}, {0.38268f, -0.92388f}, {0.70711f, -0.70711f}, {0.92388f, -0.38268f}};
    float ox = self->f560.x, oy = self->f560.y, oz = self->f560.z;
    float water = value_80178df0(self->f1232);
    int somero = w3d_prueba_ahogo_somero();
    for (int r = 60; r <= 4000; r += 20) {
        for (int a = 0; a < 16; a++) {
            self->f560.x = ox + kDir[a][0] * (float)r;
            self->f560.y = water + 92.0f;
            self->f560.z = oz + kDir[a][1] * (float)r;
            if (!falling_8014fcac(self)) continue;
            // Agua honda abierta: tampoco hay nada sobre el agua a 50 unidades en las 4 direcciones (si no, una pared tapa al
            // worm). El agua poco profunda está junto a la orilla: ahí no se mira.
            float cx = self->f560.x, cz = self->f560.z;
            int libre = 1;
            for (int k = 0; k < 16 && libre && !somero; k += 4) {
                self->f560.x = cx + kDir[k][0] * 50.0f;
                self->f560.z = cz + kDir[k][1] * 50.0f;
                libre = falling_8014fcac(self);
            }
            self->f560.x = cx; self->f560.z = cz;
            if (!libre) continue;
            self->f560.y = water - 8.0f;
            if (falling_8014fcac(self) == somero) continue;
            float h = w3d_prueba_ahogo_altura();
            self->f560.y = water + h;
            self->f676.x = w3d_prueba_ahogo_vx(); self->f676.y = h < 0.0f ? 0.0f : -0.05f; self->f676.z = 0.0f;
            self->f716 = 0;
            self->f824 &= 0x7fffffffu;
            self->f760 = h < 0.0f ? 0 : 7;
            w3d_prueba_ahogo_log(self->f584, self->f560.x, self->f560.y, self->f560.z, 1);
            track_80150828(self);
            return;
        }
    }
    self->f560.x = ox; self->f560.y = oy; self->f560.z = oz;
    w3d_prueba_ahogo_log(self->f584, ox, oy, oz, 0);
}
// v26: entrada al agua de Ultimate Mayhem (CheckDrown 0x5AD640 de WormsMayhem.exe; docs/ahogo-ultimate-mayhem.md).
// Estado 27 con la animación 33, como el ahogo en agua poco profunda de W3D, pero lo mueve ahogo.cpp (d41d) y la muerte
// llega cuando ahogo.cpp lo dice: hasta entonces +668 no vence.
// - Velocidad: si caminaba o resbalaba (Ambulatory 0 y Sliding 3 en UM; kStatic 0, kWalk 1, kSlide 9 y kSlideRecovery
//   10 en W3D), v = (v.x·0,5, −0,03, v.z·0,5). Si no, la misma con la que cayó.
// - Salpicadura: UM pone WXP_WaterSplash en (x, superficie + 1, z); aquí Splash_Worm, la de W3D al caer un worm al agua.
//   La animación 33 añade la salpicadura Splash de W3D (d31d).
inline void entrada_um(Ptr32<Worm> self) {
    int prev = self->f760;
    self->f760 = 27;
    set_state_801492ec(self, 33);
    if (prev == 0 || prev == 1 || prev == 9 || prev == 10) {
        self->f676.x *= 0.5f;
        self->f676.y = -0.03f;
        self->f676.z *= 0.5f;
    }
    self->f668 = -1;
    {
        Vec v = self->f560;
        float level = value_80178df0(self->f1232);
        int n = (int)(level * 16.0f);
        v.y = (float)(n | 1) * 0.0625f + 1.0f;
        splash_800e5ca4(&v, str_803a131c, 0, 0.0f);
    }
    if (self->type()->is_a(type_80361860) || self->type()->is_a(type_803618f0)) log_80022e20(str_803a1308, str_803a0e2c, 3025, &self->f804);
}
extern "C" void d29d_worm_drown_80149f18(Ptr32<Worm> self) {
    if (self->f648 && (self->f760 == 19 || self->f760 == 27)) return;
    if (!self->f648 && owner_8014c488(self) && w3d_prueba_ahogo_toca(engine_80165254()->now)) prueba_ahogo(self);
    float level = value_80178df0(self->f1232);
    level -= value_80178df0(self->f1228);
    if (!(self->f560.y < level)) return;
    Handle h(0);
    Ptr32<Item> it = item_800fc710(self->f584, h);
    it->hp = 0;
    Ptr32<int> dead = &self->f648;
    *dead = 1;
    {
        Ptr32<void> m = alloc_801613f0(heap_804b1754, 12);
        post_8016239c(int_message_800a82f0(m, message_id_8015f5a0(&cache_804afb60, 1), self->f584));
    }
    if (owner_8014c488(self)) clear_links_8014df84(self, 1);
    // 8014fcac da 1 si no hay suelo a menos de 100 unidades bajo el worm: agua honda.
    int deep = falling_8014fcac(self);
    // v26-v27 (pedido del dueño): con el ahogo de UM activado (core/native/ahogo.cpp), la mitad de los ahogos flota y
    // explota como en UM (1) y la otra mitad se hunde (2), aunque haya suelo cerca.
    int um = w3d_ahogo_um_entrar(self->f584, deep, (unsigned)engine_80165254()->now);
    if (um == 1) {
        entrada_um(self);
    } else if (!deep && um != 2) {
        self->f760 = 27;
        set_state_801492ec(self, 33);
        *(Ptr32<Triple>)&self->f676 = *triple_8045e788;
        self->f668 = engine_80165254()->now + 4000;
        if (self->type()->is_a(type_80361860) || self->type()->is_a(type_803618f0)) log_80022e20(str_803a1308, str_803a0e2c, 3025, &self->f804);
    } else {
        self->f760 = 19;
        set_state_801492ec(self, 13);
        self->f668 = engine_80165254()->now + 1000;
        splash(self, self->f560);
        if (self->type()->is_a(type_80361860) || self->type()->is_a(type_803618f0)) log_80022e20(str_803a1328, str_803a0e2c, 3034, &self->f804);
    }
    if (owner_8014c488(self)) post_plain(&cache_804afb68);
    self->f688 = *triple_8045e788;
    if (um != 1) {
        self->f676.x *= 0.4f;
        self->f676.z *= 0.4f;
        self->f676.y *= 0.6f;
    }
    int active = active_80178c48(get_803426b4(self->f1124));
    if ((unsigned)active > 15) return;
    if (get_80158dc4(turns_804ab400)) {
        set_80158dcc(turns_804ab400, 0);
        if (!owner_8014c488(self)) {
            Ptr32<void> m = alloc_801613f0(heap_804b1754, 12);
            post_8016239c(int_message_800a82f0(m, message_id_8015f5a0(&cache_804afd30, 1), active));
        }
        goto tail;
    }
    {
    int team = it->team;
    float best = 1000000.0f;
    int found = -1;
    if (query_800fc6dc(active)->team != team) {
        post_plain(&cache_804afd38);
        return;
    }
    int i = 0;
    Vec &me = self->f560;
    for (; i <= 15; i++) {
        Ptr32<Item> q = query_800fc6dc(i);
        if (i == self->f584) continue;
        if (q->f220 != 1) continue;
        if (q->team != team) continue;
        int taken = q->f164;
        if (q->hp - taken <= 0) continue;
        int st = q->f128;
        if (st == 20) continue;
        if (st == 19) continue;
        if (st == 27) continue;
        Vec &o = q->v80;
        float dy = o.y - me.y;
        float dx = o.x - self->f560.x;
        float dz = o.z - me.z;
        float d = sqrt_802e82c0(dx * dx + dy * dy + dz * dz);
        if (d < best) { best = d; found = i; }
    }
    if (found != -1) {
        Ptr32<void> m = alloc_801613f0(heap_804b1754, 12);
        post_8016239c(int_message_800a82f0(m, message_id_8015f5a0(&cache_804afc58, 1), found));
    }
    }
tail:
    ;
}


