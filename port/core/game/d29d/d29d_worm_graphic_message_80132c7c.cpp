#include "w3d_ptr.h"
#line 1 "d29d_worm_graphic_message_80132c7c.cpp"
// GWMP8P rev0 0x80132c7c. Worm graphic entity message handler: animations and
// speech per message. Names are inferred from use and the strings in the original.
struct Vec { float x, y, z; };
struct Obj;
struct Mesh;
struct Ready;
struct ReadyVt { char u0[36]; Ptr32<int (Ptr32<Ready>)> ready; };
struct Ready { Ptr32<ReadyVt> vt; };
struct Msg { unsigned short id; unsigned short Id() const { return id; } };
struct Engine { char u0[52]; int now; };
struct Worm {
    Ptr32<void> vt;
     char u4[16]; int f20; char u24[4]; Ptr32<Obj> f28; char u32[60]; Ptr32<Obj> f92; char u96[16]; int f112; char u116[24]; int f140; int f144; int f148; int f152; char u156[8]; int f164; char u168[8]; float f176; char u180[292]; int f472; char u476[16]; int f492; int f496; char u500[24]; Ptr32<Ready> f524; char u528[112]; int f640; int f644; char u648[4]; int f652;
};
extern "C" {
int equals_8015f65c(unsigned short, Ptr32<int>);
int base_8015fb34(Ptr32<Worm>, Ptr32<Msg>);
void setup_80134644(Ptr32<Worm>);
void release_effects_8013919c(Ptr32<Worm>);
int get_int_800fc230(Ptr32<Ptr32<const char>>, Ptr32<int>);
void interfaces_8013c890(Ptr32<Worm>, int);
void camera_8013f260(Ptr32<Worm>, int);
void transition_8013c9ac(Ptr32<Worm>);
int current_80139158(Ptr32<Worm>);
void clear_8013e3d4(Ptr32<Worm>);
void restore_80139084(Ptr32<Worm>, int);
void release_inner_8013e458(Ptr32<Worm>);
void refresh_801385a4(Ptr32<Worm>);
void attach_weapon_801394ac(Ptr32<Worm>);
void auto_80139994(Ptr32<Worm>);
void fdec_8013fdec(Ptr32<Worm>, Ptr32<Msg>);
void reaction_8013ff58(Ptr32<Worm>, Ptr32<Msg>);
void random_8014009c(Ptr32<Worm>, Ptr32<Msg>);
void blink_801401d8(Ptr32<Worm>, Ptr32<Msg>);
int get_801190d0(Ptr32<Msg>);
void attach_80139900(Ptr32<Worm>, int);
void attach_80139858(Ptr32<Worm>, int);
void attach_801397b0(Ptr32<Worm>, int);
void auto_801399b4(Ptr32<Worm>, int);
int matches_8013f168(Ptr32<Worm>, Ptr32<Msg>);
Ptr32<Mesh> cast_80343584(Ptr32<Obj>);
int fade_80181884(Ptr32<Mesh>, int, float, float);
int control_801817e0(Ptr32<Mesh>, int);
int play_801359ec(Ptr32<Worm>, Ptr32<Mesh>, Ptr32<const char>, Ptr32<int>, float, float, float);
Ptr32<Engine> engine_80165254();
void time_80133d74(Ptr32<Worm>, int);
Ptr32<void> attachment_80135af4(Ptr32<Vec>, Ptr32<Worm>);
Ptr32<void> get_80342fa4(Ptr32<Obj>);
int set_vector_80178fa4(Ptr32<void>, Ptr32<Vec>);
void state_release_8013f1c0(Ptr32<Worm>);
void fire_80138a18(Ptr32<Worm>);
void auto_801388cc(Ptr32<Worm>);
void type_80138d24(Ptr32<Worm>);
void voice_8013bbc8(Ptr32<Worm>);
void speak_8013bd0c(Ptr32<Worm>, Ptr32<const char>);
void celebrate_8013faf0(Ptr32<Worm>);
int value_800a830c(Ptr32<Msg>);
unsigned rand_80162c20();
int auto_8013fecc(Ptr32<Worm>);
float look_801381f0(Ptr32<Worm>);
void taunt_8013e790(Ptr32<Worm>, Ptr32<Msg>);
void auto_8013e744(Ptr32<Worm>, Ptr32<Msg>);
void state_8013ea30(Ptr32<Worm>, Ptr32<Msg>);
void pick_8013f0cc(Ptr32<Worm>);
int playing_80181ccc(Ptr32<Mesh>, int);
int owner_8013fa8c(Ptr32<Worm>);
void double_8013e4b0(Ptr32<Worm>);
void script_8013e530(Ptr32<Worm>);
void finish_8013e65c(Ptr32<Worm>);
void auto_8013e600(Ptr32<Worm>);
void speech_8013e6f0(Ptr32<Worm>);
void empty_8013c840(Ptr32<Worm>, Ptr32<Msg>);
int property_write_800fc43c(Ptr32<Ptr32<const char>>, int);
void auto_8013bb70(Ptr32<Worm>);
void tail_8013f038(Ptr32<Worm>);
void release_effect_80140240(Ptr32<Worm>);
}
extern int flag_804ab3bc;
extern Ptr32<const char> sda_804ab100;
extern Ptr32<const char> sda_804ab2e8;
extern Ptr32<const char> sda_804ab2f4;
extern Ptr32<const char> sda_804ab2fc;
extern const char str_8039eea4[];
extern const char str_8039f0c4[];
extern const char str_8039f0ec[];
extern const char str_8039f100[];
extern const char str_8039f114[];
extern const char str_8039f11c[];
extern const char str_8039f124[];
extern const char str_8039f130[];
extern const char str_8039f138[];
extern const char str_8039f144[];
extern const char str_8039f14c[];
extern const char str_8039f154[];
extern const char str_8039f15c[];
extern const char str_8039f164[];
extern const char str_8039f16c[];
extern const char str_8039f174[];
extern const char str_8039f17c[];
extern const char str_8039f184[];
extern const char str_8039f190[];
extern const char str_8039f198[];
extern const char str_8039f1a0[];
extern const char str_8039f1ac[];
extern const char str_8039f1b4[];
extern const char str_8039f1bc[];
extern const char str_8039f1c4[];
extern const char str_8039f1c8[];
extern int cache_804af7f8;
extern int cache_804af800;
extern int cache_804af808;
extern int cache_804af818;
extern int cache_804af820;
extern int cache_804af828;
extern int cache_804af858;
extern int cache_804af870;
extern int cache_804af878;
extern int cache_804af880;
extern int cache_804af888;
extern int cache_804af890;
extern int cache_804af898;
extern int cache_804af8a0;
extern int cache_804af8a8;
extern int cache_804af8b0;
extern int cache_804af8b8;
extern int cache_804af8c0;
extern int cache_804af8c8;
extern int cache_804af8d0;
extern int cache_804af8d8;
extern int cache_804af8e0;
extern int cache_804af8e8;
extern int cache_804af8f0;
extern int cache_804af8f8;
extern int cache_804af900;
extern int cache_804af908;
extern int cache_804af910;
extern int cache_804af918;
extern int cache_804af920;
extern int cache_804af928;
extern int cache_804af930;
extern int cache_804af938;
extern int cache_804af940;
extern int cache_804af948;
extern int cache_804af950;
extern int cache_804af958;
extern int cache_804af960;
extern int cache_804af968;
extern int cache_804af970;
extern int cache_804af978;
extern int cache_804af980;
extern int cache_804af988;
extern int cache_804af990;
extern int cache_804af998;
extern int cache_804af9a0;
extern int cache_804af9a8;
extern int cache_804af9b0;
extern int cache_804af9c0;
extern int cache_804af9c8;
extern int cache_804af9d0;
extern int cache_804af9d8;
extern int cache_804af9e0;
extern int cache_804af9e8;
extern int cache_804af9f0;
extern int cache_804af9f8;
extern int cache_804afa00;
extern int cache_804afa08;
extern int cache_804afa10;
extern int cache_804afa18;
extern int cache_804afa20;
extern int cache_804afa28;
extern int cache_804afa30;
extern int cache_804afa38;
extern int cache_804afa40;
extern "C" void w3d_hat_sync(Ptr32<Worm>, int);  // Ropa de prueba: gorros del menú Ropa (d28d_worm_attach_weapon_mesh_801394ac.cpp).
extern "C" int d29d_worm_graphic_message_80132c7c(Ptr32<Worm> self, Ptr32<Msg> m) {
    unsigned short id = m->Id();
    if (id != 64) w3d_hat_sync(self, id == 66);
    switch (m->Id()) {
    case 64:
        if (base_8015fb34(self, m) >= 0) { setup_80134644(self); goto zero; }
        return 0x80004005;
    case 66:
        release_effects_8013919c(self);
        goto base;
    }
    if (equals_8015f65c(id, &cache_804af958)) {
        Ptr32<const char> n = str_8039f0c4;
        int mode;
        get_int_800fc230(&n, &mode);
        interfaces_8013c890(self, mode == 1);
        camera_8013f260(self, mode == 1);
        transition_8013c9ac(self);
    } else if (equals_8015f65c(id, &cache_804af800)) {
        interfaces_8013c890(self, 1);
    } else if (equals_8015f65c(id, &cache_804af818) || equals_8015f65c(id, &cache_804af808)) {
        interfaces_8013c890(self, 0);
    }
    if (equals_8015f65c(id, &cache_804af8b0) && current_80139158(self)) { clear_8013e3d4(self); if (self->f164) restore_80139084(self, 1); release_inner_8013e458(self); self->f652 = 0; refresh_801385a4(self); attach_weapon_801394ac(self); goto zero; }
    if (equals_8015f65c(id, &cache_804af8a8) && current_80139158(self)) { release_inner_8013e458(self); clear_8013e3d4(self); restore_80139084(self, 1); auto_80139994(self); goto zero; }
    if (equals_8015f65c(id, &cache_804af9e0)) { if (self->f524 && self->f524->vt->ready(self->f524)) flag_804ab3bc = 1; goto zero; }
    if (equals_8015f65c(id, &cache_804af9f0)) { fdec_8013fdec(self, m); goto zero; }
    if (equals_8015f65c(id, &cache_804afa00)) { reaction_8013ff58(self, m); goto zero; }
    if (equals_8015f65c(id, &cache_804afa08)) { random_8014009c(self, m); goto zero; }
    if (equals_8015f65c(id, &cache_804afa10)) { blink_801401d8(self, m); goto zero; }
    if (equals_8015f65c(id, &cache_804af870) && current_80139158(self)) { int x = get_801190d0(m); self->f140 = x; attach_80139900(self, x); goto zero; }
    if (equals_8015f65c(id, &cache_804afa28) && current_80139158(self)) {
        Ptr32<Mesh> mesh = cast_80343584(self->f28);
        fade_80181884(mesh, self->f644, 1.0f, 1.0f);
        control_801817e0(mesh, -1);
        play_801359ec(self, mesh, sda_804ab100, &self->f492, 1.0f, -1.0f, 0.0f);
        switch (self->f496) {
        case 3: case 4: case 5: case 6: case 26: case 35: case 36: case 38:
            play_801359ec(self, mesh, str_8039f0ec, &self->f492, 1.0f, -1.0f, 0.0f);
            break;
        case 2:
        default:
            play_801359ec(self, mesh, str_8039f100, &self->f492, 1.0f, -1.0f, 0.0f);
            break;
        }
        goto zero;
    }
    if (equals_8015f65c(id, &cache_804af878) && current_80139158(self)) { int x = get_801190d0(m); self->f144 = x; attach_80139858(self, x); goto zero; }
    if (equals_8015f65c(id, &cache_804af880) && matches_8013f168(self, m)) { int x = get_801190d0(m); self->f148 = x; attach_801397b0(self, x); goto zero; }
    if (equals_8015f65c(id, &cache_804afa30) && current_80139158(self)) { auto_801399b4(self, get_801190d0(m)); goto zero; }
    if (equals_8015f65c(id, &cache_804af888) && current_80139158(self)) return 0;
    if (equals_8015f65c(id, &cache_804afa40)) { time_80133d74(self, engine_80165254()->now); goto zero; }
    if (equals_8015f65c(id, &cache_804af7f8)) { if (!current_80139158(self)) goto zero; Vec v; attachment_80135af4(&v, self); set_vector_80178fa4(get_80342fa4(self->f92), &v); goto zero; }
    if (equals_8015f65c(id, &cache_804afa20) && current_80139158(self)) { state_release_8013f1c0(self); goto zero; }
    if (equals_8015f65c(id, &cache_804af820)) { if (!current_80139158(self)) goto zero; fire_80138a18(self); goto zero; }
    if (equals_8015f65c(id, &cache_804af8b8)) { if (!current_80139158(self)) goto zero; auto_801388cc(self); goto zero; }
    if (equals_8015f65c(id, &cache_804af8c0)) { if (!current_80139158(self)) goto zero; type_80138d24(self); goto zero; }
    if (equals_8015f65c(id, &cache_804af828) && current_80139158(self)) { voice_8013bbc8(self); goto zero; }
    if (equals_8015f65c(id, &cache_804af8d0) && current_80139158(self)) { speak_8013bd0c(self, str_8039f114); goto zero; }
    if (equals_8015f65c(id, &cache_804af8c8) && current_80139158(self)) { speak_8013bd0c(self, str_8039f11c); goto zero; }
    if (equals_8015f65c(id, &cache_804af9e8)) { celebrate_8013faf0(self); goto zero; }
    if (equals_8015f65c(id, &cache_804af8d8) && current_80139158(self)) { speak_8013bd0c(self, str_8039f124); goto zero; }
    if (equals_8015f65c(id, &cache_804af8e0)) { if (value_800a830c(m) != self->f112) goto zero; speak_8013bd0c(self, str_8039f130); goto zero; }
    if (equals_8015f65c(id, &cache_804af8e8)) { if (value_800a830c(m) != self->f112) goto zero; speak_8013bd0c(self, str_8039f138); goto zero; }
    if (equals_8015f65c(id, &cache_804af9f8)) { if (value_800a830c(m) != self->f112) goto zero; speak_8013bd0c(self, str_8039f144); goto zero; }
    if (equals_8015f65c(id, &cache_804af928)) { if (value_800a830c(m) != self->f112) goto zero; if ((rand_80162c20() & 1) == 0) goto s1; goto s2; goto zero; }
    if (equals_8015f65c(id, &cache_804af930)) {
        if (value_800a830c(m) != self->f112) goto zero;
        if (!auto_8013fecc(self)) goto zero;
        if ((rand_80162c20() & 1) == 0) speak_8013bd0c(self, str_8039f15c); else speak_8013bd0c(self, str_8039f164);
        Ptr32<Mesh> mesh = cast_80343584(self->f28);
        control_801817e0(mesh, -2);
        play_801359ec(self, mesh, sda_804ab100, &self->f492, 1.0f, -1.0f, 0.0f);
        int clip = self->f640;
        fade_80181884(mesh, clip, look_801381f0(self), 1.0f);
        play_801359ec(self, mesh, sda_804ab2e8, &self->f472, 1.0f, -1.0f, 0.0f);
        goto zero;
    }
    if (equals_8015f65c(id, &cache_804af8f0)) {
        if (!current_80139158(self)) goto zero;
        if (rand_80162c20() & 1) goto s1;
    s2:
        speak_8013bd0c(self, str_8039f154);
        goto zero;
    s1:
        speak_8013bd0c(self, str_8039f14c);
        goto zero;
    }
    if (equals_8015f65c(id, &cache_804af938)) { if (!current_80139158(self)) goto zero; speak_8013bd0c(self, str_8039f16c); goto zero; }
    if (equals_8015f65c(id, &cache_804af9c0)) { taunt_8013e790(self, m); goto zero; }
    if (equals_8015f65c(id, &cache_804af9c8)) { auto_8013e744(self, m); goto zero; }
    if (equals_8015f65c(id, &cache_804af9d0)) { state_8013ea30(self, m); goto zero; }
    if (equals_8015f65c(id, &cache_804af8f8)) { if (value_800a830c(m) != self->f112) goto zero; pick_8013f0cc(self); goto zero; }
    if (equals_8015f65c(id, &cache_804af900)) {
        if (value_800a830c(m) != self->f112) goto zero;
        if (!auto_8013fecc(self)) goto zero;
        if (current_80139158(self)) goto zero;
        Ptr32<Mesh> mesh = cast_80343584(self->f28);
        if (!playing_80181ccc(mesh, self->f472)) goto zero;
        if (!playing_80181ccc(mesh, self->f492)) goto zero;
        if ((rand_80162c20() & 1) == 0) {
            speak_8013bd0c(self, str_8039f174);
            play_801359ec(self, mesh, sda_804ab100, &self->f492, 1.0f, 0.0f, 0.0f);
            play_801359ec(self, mesh, sda_804ab2fc, &self->f472, 1.0f, -1.0f, 0.0f);
        } else {
            speak_8013bd0c(self, str_8039eea4);
            play_801359ec(self, mesh, sda_804ab100, &self->f492, 1.0f, 0.0f, 0.0f);
            play_801359ec(self, mesh, sda_804ab2f4, &self->f472, 1.0f, -1.0f, 0.0f);
        }
        goto zero;
    }
    if (equals_8015f65c(id, &cache_804af908)) { if (value_800a830c(m) != self->f112) goto zero; if ((rand_80162c20() & 1) == 0) speak_8013bd0c(self, str_8039f17c); else speak_8013bd0c(self, str_8039f184); goto zero; }
    if (equals_8015f65c(id, &cache_804af910)) { if (!current_80139158(self)) goto zero; speak_8013bd0c(self, str_8039f190); goto zero; }
    if (equals_8015f65c(id, &cache_804af918)) {
        if (value_800a830c(m) != self->f112) goto zero;
        unsigned r;
        if (owner_8013fa8c(self)) r = rand_80162c20() % 5; else r = rand_80162c20() & 3;
        switch ((int)r) {
        case 0: speak_8013bd0c(self, str_8039f198); break;
        case 1: speak_8013bd0c(self, str_8039f1a0); break;
        case 2: speak_8013bd0c(self, str_8039f1ac); break;
        case 3: speak_8013bd0c(self, str_8039f1b4); break;
        case 4: speak_8013bd0c(self, str_8039f1bc); break;
        }
        goto zero;
    }
    if (equals_8015f65c(id, &cache_804af920)) { if (value_800a830c(m) != self->f112) goto zero; speak_8013bd0c(self, str_8039f1c4); goto zero; }
    if (equals_8015f65c(id, &cache_804af990)) { if (!current_80139158(self)) goto zero; double_8013e4b0(self); goto zero; }
    if (equals_8015f65c(id, &cache_804af998)) { if (value_800a830c(m) != self->f112) goto zero; script_8013e530(self); goto zero; }
    if (equals_8015f65c(id, &cache_804af9a8)) { if (value_800a830c(m) != self->f112) goto zero; finish_8013e65c(self); goto zero; }
    if (equals_8015f65c(id, &cache_804af9a0)) { if (value_800a830c(m) != self->f112) goto zero; auto_8013e600(self); goto zero; }
    if (equals_8015f65c(id, &cache_804af9b0)) { if (value_800a830c(m) != self->f112) goto zero; speech_8013e6f0(self); goto zero; }
    if (equals_8015f65c(id, &cache_804af940)) { empty_8013c840(self, m); goto zero; }
    if (equals_8015f65c(id, &cache_804af858)) { self->f144 = -1; clear_8013e3d4(self); goto zero; }
    if (equals_8015f65c(id, &cache_804af898)) { if (value_800a830c(m) != self->f112) goto zero; self->f148 = -1; clear_8013e3d4(self); goto zero; }
    if (equals_8015f65c(id, &cache_804af8a0)) { self->f140 = -1; self->f652 = 1; goto zero; }
    if (equals_8015f65c(id, &cache_804af948)) { if (value_800a830c(m) != self->f112) goto zero; if (self->f152 != -1) goto zero; self->f176 = 1.0f; goto zero; }
    if (equals_8015f65c(id, &cache_804af950)) { if (value_800a830c(m) != self->f112) goto zero; self->f176 = 0.0f; goto zero; }
    if (equals_8015f65c(id, &cache_804af9d8)) { Ptr32<const char> n = str_8039f1c8; property_write_800fc43c(&n, self->f20); goto zero; }
    if (equals_8015f65c(id, &cache_804afa18)) { if (value_800a830c(m) != self->f112) goto zero; auto_8013bb70(self); goto zero; }
    if (self->f496 == 10 && (equals_8015f65c(id, &cache_804af968) || equals_8015f65c(id, &cache_804af970) || equals_8015f65c(id, &cache_804af978) || equals_8015f65c(id, &cache_804af980) || equals_8015f65c(id, &cache_804af960) || equals_8015f65c(id, &cache_804af988))) { transition_8013c9ac(self); goto zero; }
    if (equals_8015f65c(id, &cache_804afa38) && current_80139158(self)) { tail_8013f038(self); goto zero; }
    if (equals_8015f65c(id, &cache_804af890) && current_80139158(self)) { release_effect_80140240(self); goto zero; }
base:
    return base_8015fb34(self, m);
zero:
    return 0;
}


