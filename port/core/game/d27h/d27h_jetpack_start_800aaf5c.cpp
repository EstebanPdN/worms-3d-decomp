#include "w3d_ptr.h"
#line 1 "d27h_jetpack_start_800aaf5c.cpp"
// GWMP8P rev0 0x800aaf5c. Jetpack start-up. Names are inferred. Subscribes
// eleven cached messages, creates the HUD element and shows it hidden with
// colour 200,200,200,255, posts the created message, reads the fuel settings
// and binds the retained jetpack settings.
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<Object>)> retain;       // +12
    Ptr32<void (Ptr32<Object>)> release;      // +16
};
struct Object { Ptr32<ObjectVtable> vtable; };
struct Key { Ptr32<const char> name; };
struct Ref {
    Ptr32<Object> value;
    Ref() { value = 0; }
    Ref(const Ref &);
    ~Ref() { if (value) value->vtable->release(value); }
};
extern "C" int read_setting_800fc1b0(Ptr32<Key>, Ptr32<void>);
extern "C" int read_int_800fc1f0(Ptr32<Key>, Ptr32<void>);
static inline void assign(Ptr32<Object> &slot, Ptr32<Object> value) {
    if (value) value->vtable->retain(value);
    if (slot) slot->vtable->release(slot);
    slot = value;
}
extern "C" Ptr32<Object> cast_80342a74(Ptr32<Object>);
static inline void load(Ptr32<Object> &slot, Ptr32<const char> name) {
    Key key;
    key.name = name;
    Ref found;
    read_setting_800fc1b0(&key, &found);
    assign(slot, cast_80342a74(found.value));
}
struct MessageId { unsigned short value; };
extern "C" unsigned short cached_id_8015f5a0(Ptr32<void>, int);
struct Colour {
    unsigned char r, g, b, a;
    Colour(unsigned char cr, unsigned char cg, unsigned char cb, unsigned char ca) { r = cr; g = cg; b = cb; a = ca; }
};
struct Hud;
extern "C" Ptr32<Hud> create_hud_8020b680(Ptr32<void>);
extern "C" void hud_properties_8011adf8(Ptr32<Hud>, Ptr32<Colour>, Ptr32<void>);
extern "C" void hud_set_visible_8011afac(Ptr32<Hud>, int);
extern "C" int submit_80164514(Ptr32<void>, Ptr32<Hud>, int);
struct Message;
extern "C" Ptr32<Message> arena_alloc_801613f0(Ptr32<void>, int);
extern "C" Ptr32<Message> message_init_800c1620(Ptr32<Message>, Ptr32<int>);
extern "C" int message_post_8016239c(Ptr32<Message>);
extern Ptr32<void> g_arena_804b1754;
extern Ptr32<void> g_804b178c;
extern char g_804af3b4;
extern unsigned char type_80410a10[];
struct Jetpack;
extern "C" int subscribe_80162024(Ptr32<Jetpack>, Ptr32<MessageId>, Ptr32<void>);
extern "C" void set_fuel_800ac11c(Ptr32<Jetpack>, int);
struct Jetpack {
    unsigned char unknown00[20];
    int id;  // +20
    unsigned char unknown24[4];
    int sub28;  // +28
    int sub32;  // +32
    int sub36;  // +36
    int sub40;  // +40
    int sub44;  // +44
    int sub48;  // +48
    int sub52;  // +52
    int sub56;  // +56
    int sub60;  // +60
    int sub64;  // +64
    int sub68;  // +68
    unsigned char unknown72[48];
    Ptr32<Hud> hud;  // +120
    int maxAltitude;  // +124
    Ptr32<Object> fuel;  // +128
    unsigned char unknown132[44];
    Ptr32<Object> waterLevel;  // +176
    int activeWormIndex;  // +180
    Ptr32<Object> f184;  // +184 Jetpack.FwdThrustRotation
    Ptr32<Object> f188;  // +188 Jetpack.TurnRotationSpeed
    Ptr32<Object> f192;  // +192 Jetpack.ThrustScale
    Ptr32<Object> f196;  // +196 Jetpack.AnimSmoothLR
    Ptr32<Object> f200;  // +200 Jetpack.AnimSmoothFB
    Ptr32<Object> f204;  // +204 Jetpack.OverCeilingThrustMod
    Ptr32<Object> f208;  // +208 Jetpack.SuperThrustMod
    Ptr32<Object> f212;  // +212 Jetpack.SuperThrustAccel
    Ptr32<Object> f216;  // +216 Jetpack.SuperThrustReduct
    Ptr32<Object> f220;  // +220 Jetpack.SuperThrustShutOff
    Ptr32<Object> f224;  // +224 Jetpack.MaxGfxXOrient
    Ptr32<Object> f228;  // +228 Jetpack.XZWindResThrust
    Ptr32<Object> f232;  // +232 Jetpack.XZWindResNoThrust
    Ptr32<Object> f236;  // +236 Jetpack.SuperThrustMax
};
extern char cache_804ae328;
extern char cache_804ae330;
extern char cache_804ae338;
extern char cache_804ae340;
extern char cache_804ae348;
extern char cache_804ae350;
extern char cache_804ae358;
extern char cache_804ae360;
extern char cache_804ae368;
extern char cache_804ae378;
extern char cache_804ae370;
extern const char n_80381a90[];  // "Water.Level"
extern const char n_80381a9c[];  // "Jetpack.FwdThrustRotation"
extern const char n_80381ab8[];  // "Jetpack.TurnRotationSpeed"
extern const char n_80381ad4[];  // "Jetpack.ThrustScale"
extern const char n_80381ae8[];  // "Jetpack.AnimSmoothLR"
extern const char n_80381b00[];  // "Jetpack.AnimSmoothFB"
extern const char n_80381b18[];  // "Jetpack.OverCeilingThrustMod"
extern const char n_80381b38[];  // "Jetpack.SuperThrustMod"
extern const char n_80381b50[];  // "Jetpack.SuperThrustAccel"
extern const char n_80381b6c[];  // "Jetpack.SuperThrustReduct"
extern const char n_80381b88[];  // "Jetpack.SuperThrustShutOff"
extern const char n_80381ba4[];  // "Jetpack.MaxGfxXOrient"
extern const char n_80381bbc[];  // "Jetpack.XZWindResThrust"
extern const char n_80381bd4[];  // "Jetpack.XZWindResNoThrust"
extern const char n_80381bf0[];  // "Jetpack.SuperThrustMax"
extern const char n_80381a48[];  // "ActiveWormIndex"
extern const char n_80381a58[];  // "Jetpack.MaxAltitude"
extern const char n_80381a6c[];  // "Jetpack.InitFuel"
extern const char n_80381a80[];  // "Jetpack.Fuel"
extern "C" void d27h_jetpack_start_800aaf5c(Ptr32<Jetpack> self) {
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804ae328, 1); subscribe_80162024(self, &id, &self->sub28); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804ae330, 1); subscribe_80162024(self, &id, &self->sub32); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804ae338, 1); subscribe_80162024(self, &id, &self->sub36); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804ae340, 1); subscribe_80162024(self, &id, &self->sub56); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804ae348, 1); subscribe_80162024(self, &id, &self->sub60); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804ae350, 1); subscribe_80162024(self, &id, &self->sub40); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804ae358, 1); subscribe_80162024(self, &id, &self->sub44); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804ae360, 1); subscribe_80162024(self, &id, &self->sub48); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804ae368, 1); subscribe_80162024(self, &id, &self->sub52); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804ae378, 1); subscribe_80162024(self, &id, &self->sub68); }
    { MessageId id; id.value = cached_id_8015f5a0(&cache_804ae370, 1); subscribe_80162024(self, &id, &self->sub64); }
    self->hud = create_hud_8020b680(type_80410a10);
    submit_80164514(g_804b178c, self->hud, self->id);
    { Colour c(200, 200, 200, 255); hud_properties_8011adf8(self->hud, &c, &g_804af3b4); }
    hud_set_visible_8011afac(self->hud, 0);
    { Ptr32<Message> m = arena_alloc_801613f0(g_arena_804b1754, 12); int id = self->id; message_post_8016239c(message_init_800c1620(m, &id)); }
    { Key key; key.name = n_80381a48; read_int_800fc1f0(&key, &self->activeWormIndex); }
    { Key key; key.name = n_80381a58; read_setting_800fc1b0(&key, &self->maxAltitude); }
    int initFuel;
    { Key key; key.name = n_80381a6c; read_int_800fc1f0(&key, &initFuel); }
    { Key key; key.name = n_80381a80; read_setting_800fc1b0(&key, &self->fuel); }
    set_fuel_800ac11c(self, initFuel);
    load(self->waterLevel, n_80381a90);
    load(self->f184, n_80381a9c);
    load(self->f188, n_80381ab8);
    load(self->f192, n_80381ad4);
    load(self->f196, n_80381ae8);
    load(self->f200, n_80381b00);
    load(self->f204, n_80381b18);
    load(self->f208, n_80381b38);
    load(self->f212, n_80381b50);
    load(self->f216, n_80381b6c);
    load(self->f220, n_80381b88);
    load(self->f224, n_80381ba4);
    load(self->f228, n_80381bbc);
    load(self->f232, n_80381bd4);
    load(self->f236, n_80381bf0);
}


