#include "w3d_ptr.h"
#line 1 "d28a_weapon_plans_flight_8000d5e4.cpp"
// GWMP8P rev0 0x8000d5e4. Advances a weapon plan's height by a random step,
// then clones it into follow-up plans for weapons 9, 8 and 30 when
// available. Class names and field meanings are inferred from the original
// instructions.
inline void *operator new(__SIZE_TYPE__, void *place) { return place; }
struct Vec { float x, y, z; };
struct Counted { char unknown00[44]; int refs; };
struct Handle {
    int kind;
    Ptr32<Counted> object;
    Handle() : object(0) {}
};
struct CostBase {
    int unknown0;
    float distance;
    int state;
    void w3d_r_dispatch() __asm__(W3D_SYM("_ZN8CostBase8dispatchEv"));
    CostBase();
 __attribute__((always_inline)) inline void dispatch() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_CostBase, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_CostBase; };
struct WeaponPlan : CostBase {
    int index __attribute__((aligned(__alignof__(CostBase))));            /* +16 */
    int weapon;           /* +20 */
    Vec position;         /* +24 */
    char unknown24[28];   /* +36 */
    unsigned char done;   /* +64 */
    int aim;              /* +68 */
    Handle first;         /* +72 */
    Handle second;        /* +80 */
    char unknown58[16];   /* +88 */
    void w3d_r_dispatch() __asm__(W3D_SYM("_ZN10WeaponPlan8dispatchEv"));
    bool Done() const { return done != 0; }
    WeaponPlan(const WeaponPlan &o)
    { W3D_SET_VPTR(this->CostBase::w3d_vptr_CostBase, w3d_vt___vt_10WeaponPlan, "__vt_10WeaponPlan"); 
        *this = o;
        distance = -1e20f;
        const Handle &a = o.first; const Handle &b = o.second;
        if (a.object) { first.object = a.object; first.object->refs++; }
        if (b.object) { second.object = b.object; second.object->refs++; }
    }
 __attribute__((always_inline)) inline void dispatch() { this->CostBase::dispatch(); } };
extern int w3d_flag_804aa594;
extern "C" int w3d_ai_weapon_available(int);
extern "C" Ptr32<void> w3d_auto_8001523c(unsigned int);
extern "C" void w3d_ai_push_plan_b(Ptr32<CostBase>);
struct Weapon9 : WeaponPlan { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN7Weapon98dispatchEv")); Weapon9(const WeaponPlan &o) : WeaponPlan(o) { W3D_SET_VPTR(this->WeaponPlan::w3d_vptr_CostBase, w3d_vt___vt_7Weapon9, "__vt_7Weapon9");  weapon = 9; aim = 4935; }  __attribute__((always_inline)) inline void dispatch() { this->WeaponPlan::dispatch(); } };
struct Aim4423 : WeaponPlan { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN7Aim44238dispatchEv")); Aim4423(const WeaponPlan &o) : WeaponPlan(o) { W3D_SET_VPTR(this->WeaponPlan::w3d_vptr_CostBase, w3d_vt___vt_7Aim4423, "__vt_7Aim4423");  aim = 4423; }  __attribute__((always_inline)) inline void dispatch() { this->WeaponPlan::dispatch(); } };
struct Weapon8 : Aim4423 { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN7Weapon88dispatchEv")); Weapon8(const WeaponPlan &o) : Aim4423(o) { W3D_SET_VPTR(this->Aim4423::w3d_vptr_CostBase, w3d_vt___vt_7Weapon8, "__vt_7Weapon8");  weapon = 8; }  __attribute__((always_inline)) inline void dispatch() { this->Aim4423::dispatch(); } };
struct Weapon30 : Aim4423 { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN8Weapon308dispatchEv")); Weapon30(const WeaponPlan &o) : Aim4423(o) { W3D_SET_VPTR(this->Aim4423::w3d_vptr_CostBase, w3d_vt___vt_8Weapon30, "__vt_8Weapon30");  weapon = 30; }  __attribute__((always_inline)) inline void dispatch() { this->Aim4423::dispatch(); } };
extern "C" float w3d_auto_80015794();

// Port (francotirador de UM): CAIPlanAttackSniperRifle de UM (0x49d030, vtable 0x823978). Es el plan de la escopeta
// con otro número de arma, su Clone (0x4a3b40) y su nombre (0x49b7a0); lo demás, igual
// (mods/armas-um/decomp/francotirador/ficha.md §6). Aquí: un Weapon8 (escopeta, banderas 0x1147) con arma 28 y una copia
// nativa de su tabla 0x8040d268 con tres huecos cambiados:
//   9  Clone: el de la escopeta (0x80013488 pone 8 y su tabla) y después otra vez 28 y esta tabla;
//   10 GetName: "CAIPlanAttackSniperRifle";
//   13 disparo: el de la escopeta (0x8000dcbc, error de puntería AiTwk+0x34 ShotErrorDirectNonStrafe, el mismo campo
//      que comparten escopeta y francotirador en UM, 0x4a0d90), con una línea en el registro.
// La puntuación (hueco 5, 0x8000da8c) lee el contenedor por número de arma (0x80341710 -> kWeaponMagicBullet) y la
// preferencia por 0x8021d100 (28 -> AiTwk+0x180 PrefMagicBullet).
extern "C" int w3d_francotirador_on(void);
extern "C" void w3d_dbg(const char *, ...);
extern "C" Ptr32<void> w3d_ai_weapon_names_803eb63c[];
extern "C" Ptr32<void> w3d_weapon_lookup_800fc330(Ptr32<Ptr32<void>>, Ptr32<Ptr32<void>>);
namespace {
const int kFrancoArma = 28;                          // kWeaponMagicBullet
const int kFrancoHuecos = 14;                        // 0x8040d268: 2 de cabecera y 12 funciones (la siguiente tabla en +0x40)
const char kFrancoNombre[] = "CAIPlanAttackSniperRifle";
w3d_u32 g_franco_vt[16] __attribute__((aligned(8)));
w3d_u32 g_franco_clonar_escopeta, g_franco_disparo_escopeta;
int g_franco_planes;
void franco_marca(Ptr32<WeaponPlan> plan)
{
    plan->weapon = kFrancoArma;
    plan->w3d_vptr_CostBase = (void *)g_franco_vt;
}
}
extern "C" Ptr32<WeaponPlan> w3d_franco_ia_clonar(Ptr32<WeaponPlan> self)
{
    Ptr32<WeaponPlan> copia = ((Ptr32<WeaponPlan> (*)(Ptr32<WeaponPlan>))w3d::g2h(g_franco_clonar_escopeta))(self);
    if (copia) franco_marca(copia);
    return copia;
}
extern "C" w3d_u32 w3d_franco_ia_nombre(void)
{
    return w3d::h2g(kFrancoNombre);
}
extern "C" void w3d_franco_ia_disparo(Ptr32<WeaponPlan> self)
{
    w3d_dbg("[francotirador] IA: dispara con CAIPlanAttackSniperRifle (arma 28), blanco %d, puntuación %.3f\n",
            self->index, (double)self->distance);
    ((void (*)(Ptr32<WeaponPlan>))w3d::g2h(g_franco_disparo_escopeta))(self);
}
// La tabla se copia la primera vez de la que acaba de poner el constructor de la escopeta.
static void franco_tabla(Ptr32<WeaponPlan> escopeta)
{
    if (g_franco_vt[2]) return;
    const w3d_u32 *vt = (const w3d_u32 *)escopeta->w3d_vptr_CostBase.get();
    for (int i = 0; i < kFrancoHuecos; i++) g_franco_vt[i] = vt[i];
    g_franco_clonar_escopeta = vt[9];
    g_franco_disparo_escopeta = vt[13];
    g_franco_vt[9] = w3d::h2g((const void *)&w3d_franco_ia_clonar);
    g_franco_vt[10] = w3d::h2g((const void *)&w3d_franco_ia_nombre);
    g_franco_vt[13] = w3d::h2g((const void *)&w3d_franco_ia_disparo);
}
// Como AI_CanUseWeapon (0x493500) de UM: munición o arma forzada (0x80007ccc). Además, que exista el contenedor
// kWeaponMagicBullet (WeapTwk parcheado): sin él la puntuación leería un contenedor nulo.
static bool franco_puede(void)
{
    static int llamadas;
    if (++llamadas <= 5 || !(llamadas % 200))
        w3d_dbg("[francotirador] IA: generador de planes directos (%d), escopeta %d, francotirador %d\n", llamadas,
                w3d_ai_weapon_available(8), w3d_ai_weapon_available(kFrancoArma));
    if (!w3d_francotirador_on() || !w3d_ai_weapon_available(kFrancoArma)) return false;
    Ptr32<void> nombre = w3d_ai_weapon_names_803eb63c[kFrancoArma];
    Ptr32<void> contenedor = 0;
    w3d_weapon_lookup_800fc330(&nombre, &contenedor);
    return contenedor.get() != 0;
}

extern "C" int w3d_d28a_weapon_plans_flight_8000d5e4(Ptr32<WeaponPlan> self)
{
    int any = 0;
    if (!self->Done()) self->position.y += w3d_auto_80015794() * 0.5f;
    if (w3d_ai_weapon_available(9)) {
        Ptr32<Weapon9> plan = new (w3d_auto_8001523c(104)) Weapon9(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(8)) {
        Ptr32<Weapon8> plan = new (w3d_auto_8001523c(104)) Weapon8(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    // Port (francotirador de UM): tras la escopeta, como CAIPlanAttackDirect::vf02 de UM (0x4a0840).
    if (franco_puede()) {
        Ptr32<Weapon8> plan = new (w3d_auto_8001523c(104)) Weapon8(*self);
        franco_tabla(plan);
        franco_marca(plan);
        w3d_ai_push_plan_b(plan);
        any = 1;
        if (++g_franco_planes <= 3 || !(g_franco_planes % 500))
            w3d_dbg("[francotirador] IA: plan CAIPlanAttackSniperRifle generado (%d), blanco %d\n", g_franco_planes, plan->index);
    }
    if (w3d_ai_weapon_available(30)) {
        Ptr32<Weapon30> plan = new (w3d_auto_8001523c(104)) Weapon30(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    w3d_flag_804aa594 = 1;
    return any;
}


