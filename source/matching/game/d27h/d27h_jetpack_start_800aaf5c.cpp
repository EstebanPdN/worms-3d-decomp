// GWMP8P rev0 0x800aaf5c. Jetpack start-up. Names are inferred. Subscribes
// eleven cached messages, creates the HUD element and shows it hidden with
// colour 200,200,200,255, posts the created message, reads the fuel settings
// and binds the retained jetpack settings.
struct Object;
struct ObjectVtable {
    void *unknown00[3];
    void (*retain)(Object *);       // +12
    void (*release)(Object *);      // +16
};
struct Object { ObjectVtable *vtable; };
struct Key { const char *name; };
struct Ref {
    Object *value;
    Ref() { value = 0; }
    Ref(const Ref &);
    ~Ref() { if (value) value->vtable->release(value); }
};
extern "C" int read_setting_800fc1b0(Key *, void *);
extern "C" int read_int_800fc1f0(Key *, void *);
static inline void assign(Object *&slot, Object *value) {
    if (value) value->vtable->retain(value);
    if (slot) slot->vtable->release(slot);
    slot = value;
}
extern "C" Object *cast_80342a74(Object *);
static inline void load(Object *&slot, const char *name) {
    Key key;
    key.name = name;
    Ref found;
    read_setting_800fc1b0(&key, &found);
    assign(slot, cast_80342a74(found.value));
}
struct MessageId { unsigned short value; };
extern "C" unsigned short cached_id_8015f5a0(void *, int);
struct Colour {
    unsigned char r, g, b, a;
    Colour(unsigned char cr, unsigned char cg, unsigned char cb, unsigned char ca) { r = cr; g = cg; b = cb; a = ca; }
};
struct Hud;
extern "C" Hud *create_hud_8020b680(void *);
extern "C" void hud_properties_8011adf8(Hud *, Colour *, void *);
extern "C" void hud_set_visible_8011afac(Hud *, int);
extern "C" int submit_80164514(void *, Hud *, int);
struct Message;
extern "C" Message *arena_alloc_801613f0(void *, int);
extern "C" Message *message_init_800c1620(Message *, int *);
extern "C" int message_post_8016239c(Message *);
extern void *g_arena_804b1754;
extern void *g_804b178c;
extern char g_804af3b4;
extern unsigned char type_80410a10[];
struct Jetpack;
extern "C" int subscribe_80162024(Jetpack *, MessageId *, void *);
extern "C" void set_fuel_800ac11c(Jetpack *, int);
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
    Hud *hud;  // +120
    int maxAltitude;  // +124
    Object *fuel;  // +128
    unsigned char unknown132[44];
    Object *waterLevel;  // +176
    int activeWormIndex;  // +180
    Object *f184;  // +184 Jetpack.FwdThrustRotation
    Object *f188;  // +188 Jetpack.TurnRotationSpeed
    Object *f192;  // +192 Jetpack.ThrustScale
    Object *f196;  // +196 Jetpack.AnimSmoothLR
    Object *f200;  // +200 Jetpack.AnimSmoothFB
    Object *f204;  // +204 Jetpack.OverCeilingThrustMod
    Object *f208;  // +208 Jetpack.SuperThrustMod
    Object *f212;  // +212 Jetpack.SuperThrustAccel
    Object *f216;  // +216 Jetpack.SuperThrustReduct
    Object *f220;  // +220 Jetpack.SuperThrustShutOff
    Object *f224;  // +224 Jetpack.MaxGfxXOrient
    Object *f228;  // +228 Jetpack.XZWindResThrust
    Object *f232;  // +232 Jetpack.XZWindResNoThrust
    Object *f236;  // +236 Jetpack.SuperThrustMax
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
extern "C" void d27h_jetpack_start_800aaf5c(Jetpack *self) {
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
    { Message *m = arena_alloc_801613f0(g_arena_804b1754, 12); int id = self->id; message_post_8016239c(message_init_800c1620(m, &id)); }
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
