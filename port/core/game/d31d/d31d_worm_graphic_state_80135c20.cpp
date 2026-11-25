#include "w3d_ptr.h"
#line 1 "d31d_worm_graphic_state_80135c20.cpp"
// GWMP8P rev0 0x80135c20. Worm graphic state change: leaves the old animation
// state and enters the new one, then runs the per-frame blends. Names are read
// from the strings in the original or inferred; virtual slots are reference-ABI
// observations.
struct Vec { float x, y, z; void init(float a, float b, float c) { x = a; y = b; z = c; } Vec() {} Vec(float a, float b, float c) { x = a; y = b; z = c; } Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; } };
struct Effect;
struct EffectVt { char u0[12]; Ptr32<void (Ptr32<Effect>)> retain; Ptr32<void (Ptr32<Effect>)> release; Ptr32<void (Ptr32<Effect>)> start; Ptr32<void (Ptr32<Effect>)> off; char u1c[8]; Ptr32<int (Ptr32<Effect>)> ready; char u28[12]; Ptr32<void (Ptr32<Effect>, int, float)> rate; Ptr32<void (Ptr32<Effect>, int, Ptr32<Vec>)> place; char u3c[4]; Ptr32<void (Ptr32<Effect>, int, Ptr32<float>)> get; char u44[20]; Ptr32<void (Ptr32<Effect>, int)> stop; };
struct Effect { Ptr32<EffectVt> vt; };
struct ERef { Ptr32<Effect> p; void drop() { if (p) p->vt->release(p); p = 0; } };
struct Mesh;
struct Obj;
struct MeshVt { char u0[80]; Ptr32<void (Ptr32<Mesh>, Ptr32<Vec>, int)> rotate; char u54[8]; Ptr32<int (Ptr32<Mesh>, Ptr32<Effect>, Ptr32<const char>)> locate; };
struct Mesh { Ptr32<MeshVt> vt; };
struct Mgr;
struct MgrVt { char u0[92]; Ptr32<void (Ptr32<Mgr>, Ptr32<const char>, Ptr32<ERef>)> find; Ptr32<void (Ptr32<Mgr>, Ptr32<const char>, Ptr32<Vec>)> place_at; };
struct Mgr { Ptr32<MgrVt> vt; };
struct World { char u0[108]; Ptr32<Mgr> f108; };
struct Info { char u0[44]; Vec v44; char u38[72]; int f128; };
struct Engine { char u0[52]; int now; };
struct Plain { short id; Ptr32<void> vt; };
extern "C" { struct String; void string_finish_8020c5c4(Ptr32<String>); void string_release_80341588(Ptr32<String>); }
struct String { Ptr32<void> rep; template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *); String(const String &); ~String() { string_finish_8020c5c4(this); string_release_80341588(this); } };
struct Ref { Ptr32<Effect> p; Ref() { p = 0; } Ref(const Ref &); ~Ref() { if (p) p->vt->release(p); } };
struct Worm {
    Ptr32<void> vt;
     char u4[24]; Ptr32<Obj> f28; char u32[20]; Vec f52; char u64[4]; float f68; char u72[28]; Ptr32<Obj> f100; Ptr32<Obj> f104; char u108[4]; int f112; char u116[48]; Ptr32<Effect> f164; Ptr32<Obj> f168; char u172[300]; int f472; int f476; int f480; int f484; int f488; int f492; int f496; float f500; char u504[4]; float f508; char u512[12]; Ptr32<Effect> f524; ERef f528; ERef f532; Ptr32<Effect> f536; ERef f540; ERef f544; int f548; int f552; char u556[44]; int f600; char u604[16]; float f620; char u624[12]; int f636; int f640; int f644; int f648; char u652[32]; int f684; int f688; int f692; int f696; char u700[32]; int f732; int f736; char u740[4]; int f744;
};
extern "C" {
Ptr32<Info> query_800fc6dc(int);
Ptr32<Mesh> cast_80343584(Ptr32<Obj>);
Ptr32<Obj> cast_80342a74(Ptr32<Obj>);
float look_801381f0(Ptr32<Worm>);
int fade_80181884(Ptr32<Mesh>, int, float, float);
int fade_named_80181814(Ptr32<Mesh>, Ptr32<const char>, float, float);
int control_801817e0(Ptr32<Mesh>, int);
int play_801359ec(Ptr32<Worm>, Ptr32<Mesh>, Ptr32<const char>, Ptr32<int>, float, float, float);
int playing_80181ccc(Ptr32<Mesh>, int);
void stop_800e5bb8(int);
void auto_8013f57c(Ptr32<Worm>, int);
Ptr32<void> alloc_801613f0(Ptr32<void>, int);
short message_id_8015f5a0(Ptr32<int>, int);
int post_8016239c(Ptr32<void>);
void camera_8013f260(Ptr32<Worm>, int);
void unfreeze_8013dcb8(Ptr32<Worm>, Ptr32<Mesh>);
void update_8013c890(Ptr32<Worm>, int);
void auto_80139454(Ptr32<Worm>, Ptr32<Mesh>);
void auto_8013f50c(Ptr32<Worm>, Ptr32<Mesh>);
float value_80178df0(Ptr32<Obj>);
float sqrt_802e82c0(float);
float atan2_802e7e5c(float, float);
void choose_turn_8013a8b0(Ptr32<Worm>, Ptr32<Mesh>, Ptr32<int>);
void pick_aim_8013c5f0(Ptr32<Worm>, Ptr32<Mesh>);
void speak_8013bd0c(Ptr32<Worm>, Ptr32<const char>);
void auto_8013e0a0(Ptr32<Worm>, Ptr32<Mesh>);
float prediction_80137d6c(Ptr32<Worm>, Ptr32<Vec>);
float clip_length_80181d30(Ptr32<Mesh>, Ptr32<const char>);
int set_name_8015adf4(String &, Ptr32<void>, int);
int set_resource_80182410(Ptr32<Effect>, int);
void auto_8013ddfc(Ptr32<Worm>);
void strafe_8013de54(Ptr32<Worm>, Ptr32<Mesh>);
int effect_800e5cf0(Ptr32<Mesh>, Ptr32<const char>, Ptr32<const char>, int, int);
void idle_80138dac(Ptr32<Worm>, int);
void jump_8013bec4(Ptr32<Worm>, Ptr32<Mesh>);
void auto_8013c54c(Ptr32<Worm>, Ptr32<Mesh>);
void fidget_8013a158(Ptr32<Worm>, Ptr32<Mesh>, int);
void auto_8013f8e8(Ptr32<Worm>, Ptr32<Mesh>);
void idle_think_8013aa58(Ptr32<Worm>, Ptr32<Mesh>);
int auto_8013f4dc(Ptr32<Worm>);
void surrender_8013f348(Ptr32<Worm>, Ptr32<Mesh>);
void armed_think_8013ae80(Ptr32<Worm>, Ptr32<Mesh>);
void freeze_8013db60(Ptr32<Worm>, Ptr32<Mesh>);
void auto_8013eab8(Ptr32<Worm>, Ptr32<Mesh>);
void auto_8013c938(Ptr32<Worm>);
int state_in_8013d88c(Ptr32<Worm>);
int get_8013caf0(Ptr32<Worm>);
void idle_8013caf8(Ptr32<Worm>, Ptr32<Mesh>);
Ptr32<Engine> engine_80165254();
void transition_8013c9ac(Ptr32<Worm>);
void aim_clips_80139234(Ptr32<Worm>, Ptr32<Mesh>, int);
void movement_80139f1c(Ptr32<Worm>, Ptr32<Mesh>);
void apply_8013a048(Ptr32<Worm>, Ptr32<Mesh>);
void blend_8013a0d4(Ptr32<Worm>, Ptr32<Mesh>);
unsigned rand_80162c20();
void aim_blend_8013e130(Ptr32<Worm>, Ptr32<Mesh>);
// v25 (core/native/ahogo.cpp): velocidad de la animación SinkWater (0,35 = 65 % más lenta).
float w3d_hundir_velocidad(void);
// v26 (core/native/anim_ahogo_um.cpp): postura de ahogo de Ultimate Mayhem en el estado gráfico 33.
int w3d_anim_um_entra(int);
int w3d_anim_um_activo(int);
int w3d_anim_um_sale(int);
float w3d_anim_um_peso(int);
float w3d_anim_um_tiempo(float);
const char *w3d_anim_um_clip(int);
}
inline float fabs(float x) { return __builtin_fabsf(x); }
extern Ptr32<World> const world_804b1788;
extern Ptr32<void> heap_804b1754;
extern unsigned char vt_8040db38[];
extern int cache_804af838;
extern const char str_8039f1c4[];
extern const char str_8039f3ac[];
extern const char str_8039f3b8[];
extern const char str_8039f3dc[];
extern const char str_8039f404[];
extern const char str_8039f40c[];
extern const char str_8039f414[];
extern const char str_8039f424[];
extern const char str_8039f438[];
extern const char str_8039f448[];
extern const char str_8039f454[];
extern const char str_8039f460[];
extern const char str_8039f470[];
extern const char str_8039f480[];
extern const char str_8039f490[];
extern const char str_8039f498[];
extern const char str_8039f4ac[];
extern const char str_8039f4b8[];
extern const char str_8039f4c4[];
extern const char str_8039f4cc[];
extern const char str_8039f4d8[];
extern const char str_8039f4e8[];
extern const char str_8039f4f4[];
extern Ptr32<const char> sda_804ab100;
extern Ptr32<const char> sda_804ab104;
extern Ptr32<const char> sda_804ab108;
extern Ptr32<const char> sda_804ab10c;
extern Ptr32<const char> sda_804ab110;
extern Ptr32<const char> sda_804ab118;
extern Ptr32<const char> sda_804ab120;
extern Ptr32<const char> sda_804ab128;
extern Ptr32<const char> sda_804ab12c;
extern Ptr32<const char> sda_804ab134;
extern Ptr32<const char> sda_804ab138;
extern Ptr32<const char> sda_804ab13c;
extern Ptr32<const char> sda_804ab140;
extern Ptr32<const char> sda_804ab144;
extern Ptr32<const char> sda_804ab148;
extern Ptr32<const char> sda_804ab14c;
extern Ptr32<const char> sda_804ab150;
extern Ptr32<const char> sda_804ab154;
extern Ptr32<const char> sda_804ab158;
extern Ptr32<const char> sda_804ab16c;
extern Ptr32<const char> sda_804ab170;
extern Ptr32<const char> sda_804ab174;
extern Ptr32<const char> sda_804ab17c;
extern Ptr32<const char> sda_804ab180;
extern Ptr32<const char> sda_804ab184;
extern Ptr32<const char> sda_804ab194;
extern Ptr32<const char> sda_804ab198;
extern Ptr32<const char> sda_804ab1b0;
extern Ptr32<const char> sda_804ab1b4;
extern Ptr32<const char> sda_804ab1b8;
extern Ptr32<const char> sda_804ab1bc;
extern Ptr32<const char> sda_804ab1c0;
extern Ptr32<const char> sda_804ab1d0;
extern Ptr32<const char> sda_804ab244;
extern Ptr32<const char> sda_804ab328;
extern Ptr32<const char> sda_804ab32c;
extern Ptr32<const char> sda_804ab330;
extern "C" void w3d_dbg(const char *, ...);
extern "C" int w3d_ahogo_log_tilt(void);
// Ahogo de UM (pedido del dueño, 2026-11-06): un worm que cae al agua rodando (estado gráfico 8, girado hacia donde
// va) se quedaba flotando con ese giro, boca abajo o de punta. UM, en su estado gráfico de ahogo (0x5A06B0), lleva sus
// dos ángulos de inclinación (+0x158, +0x15c) a 0 cada cuadro con 0x47A1A0: a = (0 + 10·a) / 11, sin cambiar más de
// 0,05236 rad (3°) por cuadro. Aquí lo mismo con la inclinación del estado 8 (x, y z; el rumbo y se conserva).
namespace {
struct DrownTilt { const void *who; float x, z; };
DrownTilt g_tilt[16];
DrownTilt &tilt_of(const void *who) {
    for (DrownTilt &t : g_tilt) if (t.who == who) return t;
    for (DrownTilt &t : g_tilt) if (!t.who) { t.who = who; t.x = t.z = 0.0f; return t; }
    g_tilt[0].who = who; g_tilt[0].x = g_tilt[0].z = 0.0f; return g_tilt[0];
}
float settle_um(float a) {   // 0x47A1A0 con objetivo 0, factor 10 y paso máximo 0,05236
    const float to = (0.0f + 10.0f * a) / (10.0f + 1.0f), step = 0.05236f;
    if (step < to - a) return a + step;
    if (step < a - to) return a - step;
    return to;
}
}
inline void assign_164(Ptr32<Worm> w, Ptr32<Mesh> m) {
    Ptr32<Effect> q = (Ptr32<Effect>)m;
    if (q) q->vt->retain(q);
    if (w->f164) w->f164->vt->release(w->f164);
    w->f164 = q;
}
inline void helper_ref(Ptr32<String> n, Ptr32<Worm> self) {
    Ref t;
    set_name_8015adf4(*n, &t, 255);
    assign_164(self, cast_80343584((Ptr32<Obj>)t.p));
}
extern "C" void w3d_d31d_worm_graphic_state_80135c20(Ptr32<Worm> self) {
    int entered = 0;
    int state = 0;
    int old = self->f496;
    int next = query_800fc6dc(self->f112)->f128;
    Ptr32<Mesh> mesh = cast_80343584(self->f28);
    switch (self->f496) {
    case 1: case 3: case 4: case 5: case 7: case 8: case 18: case 21: case 22:
    case 24: case 25: case 26: case 27: case 34: case 38: case 43:
        entered = 1;
        break;
    }
float look = look_801381f0(self);
    fade_80181884(mesh, self->f640, look, 1.0f);
int d = next - 27;
if (d) {
        if (self->f552) { stop_800e5bb8(self->f552); self->f552 = 0; }
        if (self->f540.p) self->f540.p->vt->off(self->f540.p);
    }
    auto_8013f57c(self, next);
    if (next == self->f496 && !entered) goto out;
    switch (self->f496) {
    case 10:
        if (next == 42) break;
        if (self->f648) fade_80181884(mesh, self->f644, 0.0f, 0.0f);
        control_801817e0(mesh, -2);
        control_801817e0(mesh, -1);
        play_801359ec(self, mesh, sda_804ab100, &self->f492, 1.0f, 0.0f, 0.0f);
        {
            Ptr32<Plain> p = (Ptr32<Plain>)alloc_801613f0(heap_804b1754, 8);
            p->id = message_id_8015f5a0(&cache_804af838, 1);
            p->vt = vt_8040db38;
            post_8016239c(p);
        }
        if (self->f684 == 16 && self->f168) {
            Ptr32<Mesh> m = cast_80343584(self->f168);
            fade_named_80181814(m, str_8039f3ac, 0.0f, 0.0f);
            play_801359ec(self, m, str_8039f3b8, &self->f484, 1.0f, -1.0f, 0.0f);
        }
        camera_8013f260(self, 1);
        break;
    case 14:
        fade_named_80181814(mesh, sda_804ab180, 0.0f, 0.0f);
        fade_named_80181814(mesh, sda_804ab17c, 0.0f, 0.0f);
        break;
    case 19:
        fade_named_80181814(mesh, sda_804ab198, 0.0f, 0.0f);
        break;
    case 28:
        unfreeze_8013dcb8(self, mesh);
        break;
    case 37:
        self->f732 = 0;
        update_8013c890(self, 0);
        break;
    }
    state = next;
    self->f496 = state;
    switch (state) {
    case 0:
        if (!playing_80181ccc(mesh, self->f492)) goto out;
        if (self->f472 != -1 && !playing_80181ccc(mesh, self->f472)) goto out;
        play_801359ec(self, mesh, sda_804ab100, &self->f492, 1.0f, -1.0f, 0.0f);
        goto out;
    case 1:
        if (old != 1 && old != 18) {
            if (self->f536) self->f536->vt->off(self->f536);
            auto_80139454(self, mesh);
            control_801817e0(mesh, -2);
            control_801817e0(mesh, -1);
            control_801817e0(mesh, self->f472);
            play_801359ec(self, mesh, sda_804ab100, &self->f492, 1.0f, 0.0f, 0.0f);
            auto_8013f50c(self, mesh);
        } else {
            if (self->f164) self->f164->vt->stop(self->f164, 0);
        }
        {
            Vec v(query_800fc6dc(self->f112)->v44);
            Ptr32<Vec> vp = &v;
            if ((self->f472 == -1 || playing_80181ccc(mesh, self->f472)) && playing_80181ccc(mesh, self->f492)
                && (self->f52.x != self->f500 || self->f52.z != self->f508)) {
                float k = value_80178df0(cast_80342a74(self->f100));
                float rate = 0.5f;
                float len = sqrt_802e82c0(v.x * v.x + vp->y * vp->y + vp->z * vp->z);
                if (len > 0.0f) rate = 1.0f / (k * len);
                play_801359ec(self, mesh, sda_804ab104, &self->f472, rate, -1.0f, 0.0f);
                if (self->f168) { play_801359ec(self, cast_80343584(self->f168), sda_804ab104, &self->f484, rate, 0.0f, 0.0f); }
                self->f528.drop();
                world_804b1788->f108->vt->find(world_804b1788->f108, str_8039f3dc, &self->f528);
                self->f528.p->vt->start(self->f528.p);
                
                self->f528.p->vt->place(self->f528.p, 3, &self->f52);
            }
        }
        if (!playing_80181ccc(mesh, self->f492)) goto out;
        if ((old == 1 || old == 18) && fabs(self->f620) > 0.6283185482025146f) choose_turn_8013a8b0(self, mesh, &self->f480);
        pick_aim_8013c5f0(self, mesh);
        goto out;
    case 18:
        if (old != 18 && old != 1) {
            if (self->f536) self->f536->vt->off(self->f536);
            auto_80139454(self, mesh);
            control_801817e0(mesh, -2);
            control_801817e0(mesh, -1);
            control_801817e0(mesh, self->f472);
            play_801359ec(self, mesh, sda_804ab100, &self->f492, 1.0f, 0.0f, 0.0f);
            auto_8013f50c(self, mesh);
        } else {
            if (self->f164) self->f164->vt->stop(self->f164, 0);
        }
        {
            Vec v(query_800fc6dc(self->f112)->v44);
            Ptr32<Vec> vp = &v;
            if ((self->f472 == -1 || playing_80181ccc(mesh, self->f472)) && playing_80181ccc(mesh, self->f492)
                && (self->f52.x != self->f500 || self->f52.z != self->f508)) {
                float k = value_80178df0(cast_80342a74(self->f104));
                float rate = 0.6f;
                float len = sqrt_802e82c0(v.x * v.x + vp->y * vp->y + vp->z * vp->z);
                if (len > 0.0f) rate = 1.0f / (k * len);
                play_801359ec(self, mesh, sda_804ab108, &self->f472, rate, -1.0f, 0.0f);
                if (self->f168) { play_801359ec(self, cast_80343584(self->f168), sda_804ab108, &self->f484, rate, 0.0f, 0.0f); }
                self->f528.drop();
                world_804b1788->f108->vt->find(world_804b1788->f108, str_8039f3dc, &self->f528);
                self->f528.p->vt->start(self->f528.p);
                self->f528.p->vt->rate(self->f528.p, 1, 0.5f);
                self->f528.p->vt->place(self->f528.p, 3, &self->f52);
            }
        }
        if (!playing_80181ccc(mesh, self->f492)) goto out;
        if ((old == 18 || old == 1) && fabs(self->f620) > 0.6283185482025146f) choose_turn_8013a8b0(self, mesh, &self->f480);
        pick_aim_8013c5f0(self, mesh);
        goto out;
    case 2:
        if (self->f536) self->f536->vt->off(self->f536);
        control_801817e0(mesh, -2);
        control_801817e0(mesh, -1);
        play_801359ec(self, mesh, sda_804ab100, &self->f492, 1.0f, -1.0f, 0.0f);
        play_801359ec(self, mesh, sda_804ab10c, &self->f472, 1.0f, -1.0f, 0.0f);
        if (self->f168) { play_801359ec(self, cast_80343584(self->f168), sda_804ab10c, &self->f484, 1.0f, -1.0f, 0.0f); }
        speak_8013bd0c(self, str_8039f404);
        goto out;
    case 3:
        if (self->f164) self->f164->vt->stop(self->f164, 0);
        if (old == 3) goto same;
        play_801359ec(self, mesh, sda_804ab110, &self->f472, 1.0f, 0.0f, 0.0f);
        if (self->f168) { play_801359ec(self, cast_80343584(self->f168), sda_804ab110, &self->f484, 1.0f, 0.0f, 0.0f); }
        speak_8013bd0c(self, str_8039f40c);
        goto out;
    case 5:
        if (self->f164) self->f164->vt->stop(self->f164, 0);
        if (old == 5) goto same;
        play_801359ec(self, mesh, sda_804ab118, &self->f472, 1.0f, 0.0f, 0.0f);
        if (self->f168) { play_801359ec(self, cast_80343584(self->f168), sda_804ab118, &self->f484, 1.0f, 0.0f, 0.0f); }
        speak_8013bd0c(self, str_8039f40c);
        goto out;
    case 6:
        {
            Vec out;
            float x = prediction_80137d6c(self, &out);
            if (self->f164) self->f164->vt->stop(self->f164, 0);
            if (clip_length_80181d30(mesh, sda_804ab120) < x) play_801359ec(self, mesh, sda_804ab120, &self->f472, 1.0f, 0.0f, 0.0f);
            else play_801359ec(self, mesh, sda_804ab118, &self->f472, 1.0f, 0.0f, 0.0f);
            if (self->f168) { play_801359ec(self, cast_80343584(self->f168), sda_804ab120, &self->f484, 1.0f, 0.0f, 0.0f); }
            self->f544.drop();
        world_804b1788->f108->vt->find(world_804b1788->f108, str_8039f414, &self->f544);
        self->f544.p->vt->place(self->f544.p, 3, &self->f52);
        self->f544.p->vt->start(self->f544.p);
        }
        goto out;
    case 36:
        {
            Vec out;
            float x = prediction_80137d6c(self, &out);
            if (self->f164) self->f164->vt->stop(self->f164, 0);
            if (clip_length_80181d30(mesh, sda_804ab128) < x) play_801359ec(self, mesh, sda_804ab128, &self->f472, 1.0f, 0.0f, 0.0f);
            else play_801359ec(self, mesh, sda_804ab110, &self->f472, 1.0f, 0.0f, 0.0f);
            if (self->f168) { play_801359ec(self, cast_80343584(self->f168), sda_804ab120, &self->f484, 1.0f, 0.0f, 0.0f); }
            self->f544.drop();
        world_804b1788->f108->vt->find(world_804b1788->f108, str_8039f414, &self->f544);
        self->f544.p->vt->place(self->f544.p, 3, &self->f52);
        self->f544.p->vt->start(self->f544.p);
        }
        goto out;
    case 4:
        if (self->f164) self->f164->vt->stop(self->f164, 0);
        if (old == 4) goto same;
        play_801359ec(self, mesh, sda_804ab12c, &self->f472, 1.0f, 0.0f, 0.0f);
        if (self->f168) { play_801359ec(self, cast_80343584(self->f168), sda_804ab12c, &self->f484, 1.0f, 0.0f, 0.0f); }
        speak_8013bd0c(self, str_8039f40c);
        goto out;
    same:
        auto_8013e0a0(self, mesh);
        goto out;
    case 32:
        control_801817e0(mesh, -1);
        play_801359ec(self, mesh, sda_804ab100, &self->f492, 1.0f, 0.0f, 0.0f);
        play_801359ec(self, mesh, sda_804ab12c, &self->f472, 1.0f, -1.0f, 0.0f);
        goto out;
    case 42:
        if (old == 42 || old == 10) goto out;
        control_801817e0(mesh, -1);
        play_801359ec(self, mesh, sda_804ab100, &self->f492, 1.0f, 0.0f, 0.0f);
        play_801359ec(self, mesh, str_8039f424, &self->f472, 1.0f, -1.0f, 0.0f);
        play_801359ec(self, mesh, str_8039f438, &self->f472, 1.0f, -1.0f, 0.0f);
        goto out;
    case 7:
        if (self->f164) self->f164->vt->stop(self->f164, 0);
        if (old != 7 && old != 31) {
            self->f732 = 0;
            update_8013c890(self, 0);
            control_801817e0(mesh, self->f472);
            play_801359ec(self, mesh, sda_804ab100, &self->f492, 1.0f, 0.0f, 0.0f);
        }
        if (!playing_80181ccc(mesh, self->f472)) goto out;
        play_801359ec(self, mesh, sda_804ab138, &self->f472, 1.0f, -1.0f, 0.0f);
        goto out;
    case 37:
        self->f732 = 1;
        update_8013c890(self, 1);
        goto out;
    case 8:
        if (old != 8) {
            self->f732 = 0;
            update_8013c890(self, 0);
            control_801817e0(mesh, -1);
            play_801359ec(self, mesh, sda_804ab100, &self->f492, 1.0f, 0.0f, 0.0f);
            play_801359ec(self, mesh, sda_804ab134, &self->f472, 1.0f, -1.0f, 0.0f);
            speak_8013bd0c(self, str_8039f1c4);
            goto out;
        }
        if (!playing_80181ccc(mesh, self->f472)) goto out;
        play_801359ec(self, mesh, sda_804ab134, &self->f472, 1.0f, 0.0f, 0.0f);
        goto out;
    case 9:
        control_801817e0(mesh, -1);
        play_801359ec(self, mesh, sda_804ab13c, &self->f472, 1.0f, 0.0f, 0.0f);
        self->f544.drop();
        world_804b1788->f108->vt->find(world_804b1788->f108, str_8039f448, &self->f544);
        self->f544.p->vt->place(self->f544.p, 3, &self->f52);
        self->f544.p->vt->start(self->f544.p);
        goto out;
    case 35:
        control_801817e0(mesh, -1);
        play_801359ec(self, mesh, sda_804ab140, &self->f472, 1.0f, 0.0f, 0.0f);
        play_801359ec(self, mesh, sda_804ab100, &self->f472, 1.0f, -1.0f, 0.0f);
        goto out;
    case 12:
        {
            String name(str_8039f454);
            Ptr32<String> n = &name;
            helper_ref(n, self);
        }
        mesh->vt->locate(mesh, self->f164, str_8039f460);
        set_resource_80182410(self->f164, self->f600);
        play_801359ec(self, cast_80343584((Ptr32<Obj>)self->f164), sda_804ab144, &self->f488, 1.0f, 0.0f, 0.0f);
        play_801359ec(self, mesh, sda_804ab144, &self->f472, 1.0f, 0.0f, 0.0f);
        auto_8013ddfc(self);
        goto out;
    case 29:
        play_801359ec(self, mesh, sda_804ab148, &self->f472, 1.0f, 0.0f, 0.0f);
        auto_8013ddfc(self);
        goto out;
    case 30:
        play_801359ec(self, mesh, sda_804ab14c, &self->f472, 1.0f, 0.0f, 0.0f);
        auto_8013ddfc(self);
        goto out;
    case 39:
        play_801359ec(self, mesh, sda_804ab150, &self->f472, 1.0f, 0.0f, 0.0f);
        auto_8013ddfc(self);
        goto out;
    case 40:
        {
            String name(str_8039f470);
            Ptr32<String> n = &name;
            Ref t;
            set_name_8015adf4(*n, &t, 255);
            assign_164(self, cast_80343584((Ptr32<Obj>)t.p));
        }
        set_resource_80182410(self->f164, self->f600);
        mesh->vt->locate(mesh, self->f164, sda_804ab328);
        play_801359ec(self, mesh, sda_804ab154, &self->f472, 1.0f, 0.0f, 0.0f);
        auto_8013ddfc(self);
        goto out;
    case 41:
        play_801359ec(self, mesh, sda_804ab158, &self->f472, 1.0f, 0.0f, 0.0f);
        auto_8013ddfc(self);
        goto out;
    case 31:
        self->f732 = 0;
        update_8013c890(self, 0);
        strafe_8013de54(self, mesh);
        goto out;
    case 13:
        control_801817e0(mesh, -1);
        play_801359ec(self, mesh, sda_804ab170, &self->f472, w3d_hundir_velocidad(), 0.0f, 0.0f);   // SinkWater (v25: más lenta)
        self->f548 = effect_800e5cf0(mesh, sda_804ab330, str_8039f480, -1, 0);
        world_804b1788->f108->vt->place_at(world_804b1788->f108, str_8039f490, &self->f52);
        goto out;
    case 33:
        control_801817e0(mesh, -1);
        // v26: con el ahogo de UM, su postura FallDrown (cada cuadro, más abajo); si no, Drown_Shallow.
        if (!w3d_anim_um_entra(self->f112)) play_801359ec(self, mesh, sda_804ab1c0, &self->f472, 1.0f, 0.0f, 0.0f);
        world_804b1788->f108->vt->place_at(world_804b1788->f108, str_8039f490, &self->f52);
        goto out;
    case 10:
        if (self->f552) {
            stop_800e5bb8(self->f552);
            self->f552 = 0;
            if (self->f540.p) self->f540.p->vt->off(self->f540.p);
        }
        if (self->f164) self->f164->vt->stop(self->f164, self->f744);
        idle_80138dac(self, 1);
        camera_8013f260(self, 0);
        goto out;
    case 26:
        if (old != 26) { jump_8013bec4(self, mesh); auto_8013c54c(self, mesh); }
        auto_8013e0a0(self, mesh);
        goto stop164;
    case 38:
        if (old != 26) { jump_8013bec4(self, mesh); auto_8013c54c(self, mesh); }
        if (playing_80181ccc(mesh, self->f472)) play_801359ec(self, mesh, sda_804ab138, &self->f472, 1.0f, 0.0f, 0.0f);
    stop164:
        if (self->f164) self->f164->vt->stop(self->f164, 0);
        goto out;
    case 17:
        if (playing_80181ccc(mesh, self->f472)) fidget_8013a158(self, mesh, 1);
        goto out;
    case 11:
        play_801359ec(self, mesh, sda_804ab100, &self->f492, 1.0f, -1.0f, 0.0f);
        auto_8013f8e8(self, mesh);
        goto out;
    case 14:
        control_801817e0(mesh, -1);
        play_801359ec(self, mesh, sda_804ab100, &self->f492, 1.0f, 0.0f, 0.0f);
        play_801359ec(self, mesh, sda_804ab174, &self->f472, 1.0f, -1.0f, 0.0f);
        goto out;
    case 15:
        control_801817e0(mesh, -1);
        fade_80181884(mesh, self->f644, 1.0f, 1.0f);
        play_801359ec(self, mesh, sda_804ab100, &self->f492, 1.0f, -1.0f, 0.0f);
        play_801359ec(self, mesh, str_8039f498, &self->f492, 1.0f, -1.0f, 0.0f);
        play_801359ec(self, mesh, sda_804ab184, &self->f472, 1.0f, -1.0f, 0.0f);
        goto out;
    case 19:
        control_801817e0(mesh, -1);
        play_801359ec(self, mesh, sda_804ab100, &self->f492, 1.0f, 0.0f, 0.0f);
        play_801359ec(self, mesh, sda_804ab194, &self->f472, 1.0f, -1.0f, 0.0f);
        goto out;
    case 21:
        if (self->f472 != -1 && !playing_80181ccc(mesh, self->f472)) goto out;
        idle_think_8013aa58(self, mesh);
        goto out;
    case 22:
        if (old != 22 && auto_8013f4dc(self)) surrender_8013f348(self, mesh);
        if (self->f472 != -1 && !playing_80181ccc(mesh, self->f472)) goto out;
        armed_think_8013ae80(self, mesh);
        goto out;
    case 24:
        if (old != 24) {
            control_801817e0(mesh, -1);
            play_801359ec(self, mesh, sda_804ab100, &self->f492, 1.0f, 0.0f, 0.0f);
            play_801359ec(self, mesh, sda_804ab1bc, &self->f472, 1.0f, -1.0f, 0.0f);
            
            goto out;
        }
        if (!playing_80181ccc(mesh, self->f472)) goto out;
        play_801359ec(self, mesh, sda_804ab1b8, &self->f472, 1.0f, 0.0f, 0.0f);
        
        goto out;
    case 25:
        if (old != 25) {
            control_801817e0(mesh, -1);
            play_801359ec(self, mesh, sda_804ab100, &self->f492, 1.0f, 0.0f, 0.0f);
            play_801359ec(self, mesh, sda_804ab1b4, &self->f472, 1.0f, -1.0f, 0.0f);
            
            goto out;
        }
        if (!playing_80181ccc(mesh, self->f472)) goto out;
        play_801359ec(self, mesh, sda_804ab1b0, &self->f472, 1.0f, 0.0f, 0.0f);
        world_804b1788->f108->vt->find(world_804b1788->f108, str_8039f4ac, &self->f532);
            self->f532.p->vt->place(self->f532.p, 3, &self->f52);
            self->f532.p->vt->start(self->f532.p);
        goto out;
    case 43:
        if (old != 43) {
            control_801817e0(mesh, -1);
            play_801359ec(self, mesh, sda_804ab100, &self->f492, 1.0f, 0.0f, 0.0f);
            play_801359ec(self, mesh, str_8039f4b8, &self->f472, 1.0f, -1.0f, 0.0f);
            speak_8013bd0c(self, str_8039f4c4);
            goto out;
        }
        if (!playing_80181ccc(mesh, self->f472)) goto out;
        play_801359ec(self, mesh, str_8039f4cc, &self->f472, 1.0f, 0.0f, 0.0f);
        
        goto out;
    case 27:
        if (old != 27) {
            control_801817e0(mesh, -1);
            play_801359ec(self, mesh, sda_804ab100, &self->f492, 1.0f, 0.0f, 0.0f);
            play_801359ec(self, mesh, sda_804ab1d0, &self->f472, 1.0f, -1.0f, 0.0f);
            if (!self->f552) self->f552 = effect_800e5cf0(mesh, sda_804ab32c, str_8039f4d8, -1, 0);
            if (world_804b1788->f108) {
                world_804b1788->f108->vt->find(world_804b1788->f108, str_8039f4e8, &self->f540);
                self->f540.p->vt->place(self->f540.p, 3, &self->f52);
                self->f540.p->vt->start(self->f540.p);
            }
            goto out;
        }
        if (!playing_80181ccc(mesh, self->f472)) goto out;
        play_801359ec(self, mesh, sda_804ab1d0, &self->f472, 1.0f, -1.0f, 0.0f);
        goto out;
    case 28:
        play_801359ec(self, mesh, sda_804ab100, &self->f492, 1.0f, -1.0f, 0.0f);
        freeze_8013db60(self, mesh);
        goto out;
    case 34:
        auto_8013eab8(self, mesh);
    }
out:
    // v26: al salir del estado 33 con la postura de UM, sus dos clips vuelven a peso 0.
    if (old == 33 && self->f496 != 33 && w3d_anim_um_sale(self->f112)) {
        fade_named_80181814(mesh, w3d_anim_um_clip(1), 0.0f, 0.0f);
        fade_named_80181814(mesh, w3d_anim_um_clip(0), 0.0f, 0.0f);
    }
    auto_8013c938(self);
    if (old != self->f496 && w3d_ahogo_log_tilt()) w3d_dbg("[tilt] estado gráfico %d -> %d (UM %d)\n", old, self->f496, w3d_anim_um_activo(self->f112));
    if (self->f496 == 10) {
        if (playing_80181ccc(mesh, self->f472)) {
            if (state_in_8013d88c(self) && get_8013caf0(self)) {
                idle_8013caf8(self, mesh);
                self->f688 = 0;
                self->f696 = engine_80165254()->now + 9000;
            } else if (self->f692) {
                transition_8013c9ac(self);
            } else {
                aim_clips_80139234(self, mesh, 0);
                if (self->f648) choose_turn_8013a8b0(self, mesh, &self->f480);
            }
            self->f620 = 0.0f;
        }
    } else if (self->f496 != 25) {
        transition_8013c9ac(self);
    }
    // The tumble's tilt (state 8) is kept while the worm is still in the air (falling, jumping) so a drowning that
    // follows can ease it to 0; standing or any other state clears it.
    if (self->f496 != 8 && self->f496 != 7 && self->f496 != 38 && self->f496 != 34 && self->f496 != 33) {
        DrownTilt &t = tilt_of(self.get()); t.x = t.z = 0.0f;
    }
    if (self->f496 == 8) {
        float zero = 0.0f;
        Vec a;
        a.init(zero, zero, zero);
        Vec &d = query_800fc6dc(self->f112)->v44;
        float dx = d.x, dy = d.y, dz = d.z;
        Vec v; v.x = dx; v.y = dy; v.z = dz;
        Vec h; h.x = dx; h.z = dz; h.y = zero;
        a.x = atan2_802e7e5c(sqrt_802e82c0(dx * dx + zero + dz * dz), v.y);
        a.y = atan2_802e7e5c(v.x, v.z);
        float len2 = h.x * h.x + h.y * h.y + h.z * h.z;
        if (len2 != zero) {
            float inv = 1.0f / sqrt_802e82c0(len2);
            h.x *= inv; h.y *= inv; h.z *= inv;
            Vec up;
            Ptr32<Vec> u = &up;
            u->init(zero, zero, 1.0f);
        }
        self->f68 = a.y;
        { DrownTilt &t = tilt_of(self.get()); t.x = a.x; t.z = a.z; }
        mesh->vt->rotate(mesh, &a, 0);
    } else if (self->f496 == 15) {
        movement_80139f1c(self, mesh);
    } else if (self->f496 == 14) {
        apply_8013a048(self, mesh);
    } else if (self->f496 == 19) {
        blend_8013a0d4(self, mesh);
    } else if (self->f496 == 33 && w3d_anim_um_activo(self->f112)) {
        // La inclinación con la que llegó (solo si venía rodando) vuelve a 0 poco a poco, como en UM.
        DrownTilt &tilt = tilt_of(self.get());
        if (tilt.x != 0.0f || tilt.z != 0.0f) {   // only a worm that arrived tumbling (other drownings are untouched)
            if (old != 33 && w3d_ahogo_log_tilt()) w3d_dbg("[tilt] entra al ahogo desde el estado %d con %.3f / %.3f rad\n", old, tilt.x, tilt.z);
            tilt.x = settle_um(tilt.x); tilt.z = settle_um(tilt.z);
            if (w3d_ahogo_log_tilt()) w3d_dbg("[tilt] %.3f %.3f\n", tilt.x, tilt.z);
            Vec a; a.init(tilt.x, self->f68, tilt.z);
            mesh->vt->rotate(mesh, &a, 0);
        }
        // v26: como 0x5A06B0 de UM, FallDrown en t = 1 + clamp(10 · v.y, -1, 1) con peso w, y la base con 1 - w.
        float w = w3d_anim_um_peso(self->f112);
        float t = w3d_anim_um_tiempo(query_800fc6dc(self->f112)->v44.y);
        if (w > 0.0f) fade_named_80181814(mesh, w3d_anim_um_clip(1), t, w);
        fade_named_80181814(mesh, w3d_anim_um_clip(0), 0.0f, 1.0f - w);
    }
    if ((self->f496 == 0 || self->f496 == 10 || self->f496 == 11)
        && playing_80181ccc(mesh, self->f472) && playing_80181ccc(mesh, self->f492)) {
        if (self->f476 != -1 && !playing_80181ccc(mesh, self->f476)) goto light;
        if (self->f496 == 10) goto plain;
        if (auto_8013f4dc(self)) {
            play_801359ec(self, mesh, str_8039f4f4, &self->f472, 1.0f, 0.0f, 0.0f);
            if (self->f164) { play_801359ec(self, (Ptr32<Mesh>)self->f164, str_8039f4f4, &self->f488, 1.0f, 0.0f, 0.0f); }
            goto tail;
        }
        if ((rand_80162c20() & 1) && self->f736) goto special;
    plain:
        play_801359ec(self, mesh, sda_804ab16c, &self->f476, 1.0f, 0.0f, 0.0f);
        goto tail;
    special:
        play_801359ec(self, mesh, sda_804ab244, &self->f476, 1.0f, 0.0f, 0.0f);
    tail:
        if (self->f168 && self->f684 == 16) {
            Ptr32<Mesh> m = cast_80343584(self->f168);
            if (playing_80181ccc(m, self->f484)) { play_801359ec(self, m, sda_804ab16c, &self->f484, 1.0f, 0.0f, 0.0f); }
        }
    } else if (self->f496 != 15) {
        auto_80139454(self, mesh);
    }
light:
    if (self->f524 && self->f524->vt->ready(self->f524)) {
        self->f524->vt->place(self->f524, 3, &self->f52);
        float val = 0.0f;
        self->f524->vt->get(self->f524, 24, &val);
        fade_80181884(mesh, self->f636, val, 1.0f);
    } else {
        fade_80181884(mesh, self->f636, 0.0f, 0.0f);
    }
    aim_blend_8013e130(self, mesh);
}


