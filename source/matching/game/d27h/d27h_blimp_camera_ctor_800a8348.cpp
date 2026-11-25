// GWMP8P rev0 0x800a8348. Blimp camera constructor. Names are inferred. Runs
// the base camera constructor, sets the table pointer, clears the setting
// references +120..+180 and binds each to its named setting. The reference
// held from the start of the body is witnessed by the saved register holding
// self+128.
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
extern "C" int write_setting_800fc43c(Key *, int);
static inline void assign(Object *&slot, Object *value) {
    if (value) value->vtable->retain(value);
    if (slot) slot->vtable->release(slot);
    slot = value;
}
extern "C" Object *cast_80342a74(Object *);
static inline void load_80342a74(Object *&slot, const char *name) {
    Key key;
    key.name = name;
    Ref found;
    read_setting_800fc1b0(&key, &found);
    assign(slot, cast_80342a74(found.value));
}
extern "C" Object *cast_80342fa4(Object *);
static inline void load_80342fa4(Object *&slot, const char *name) {
    Key key;
    key.name = name;
    Ref found;
    read_setting_800fc1b0(&key, &found);
    assign(slot, cast_80342fa4(found.value));
}
struct Camera {
    unsigned char unknown00[72];
    void *vtable;  // +72
    unsigned char unknown76[44];
    Object *f120;  // +120 Land.MaxHeight
    Object *f124;  // +124 Camera.Blimp.HeightAboveLand
    Object *f128;  // +128 Camera.Blimp.UpdateSpeed
    Object *f132;  // +132 Camera.Blimp.MoveSpeed
    Object *f136;  // +136 Camera.Blimp.MouseXSpeed
    Object *f140;  // +140 Camera.Blimp.MouseYSpeed
    Object *f144;  // +144 Camera.Blimp.MouseWheelSpeed
    Object *f148;  // +148 
    Object *f152;  // +152 
    Object *f156;  // +156 Camera.Blimp.RotateSpeed
    Object *f160;  // +160 Camera.Blimp.StickLength
    Object *f164;  // +164 Camera.Blimp.PitchSpeed
    Object *f168;  // +168 Camera.Blimp.DefaultPitch
    Object *f172;  // +172 Camera.Blimp.MousePitchSpeed
    Object *f176;  // +176 Camera.Blimp.MouseYawSpeed
    Object *f180;  // +180 Land.Center
};
extern unsigned char vtable_8040f658[];
extern "C" int base_8015a0d4(Camera *, const char *, int);
extern const char n_803816d0[];  // "Land.MaxHeight"
extern const char n_803816e0[];  // "Camera.Blimp.DefaultPitch"
extern const char n_803816fc[];  // "Camera.Blimp.HeightAboveLand"
extern const char n_8038171c[];  // "Camera.Blimp.UpdateSpeed"
extern const char n_80381738[];  // "Camera.Blimp.RotateSpeed"
extern const char n_80381754[];  // "Camera.Blimp.MoveSpeed"
extern const char n_8038176c[];  // "Camera.Blimp.MouseXSpeed"
extern const char n_80381788[];  // "Camera.Blimp.MouseYSpeed"
extern const char n_803817a4[];  // "Camera.Blimp.MouseWheelSpeed"
extern const char n_803817c4[];  // "Camera.Blimp.MousePitchSpeed"
extern const char n_803817e4[];  // "Camera.Blimp.MouseYawSpeed"
extern const char n_80381800[];  // "Camera.Blimp.StickLength"
extern const char n_8038181c[];  // "Camera.Blimp.PitchSpeed"
extern const char n_80381834[];  // "Land.Center"
extern const char n_80381840[];  // "AIStrike.SeekTarget"
extern "C" Camera *d27h_blimp_camera_ctor_800a8348(Camera *self, const char *name, int kind) {
    base_8015a0d4(self, name, kind);
    Object *&up = self->f128;
    self->vtable = vtable_8040f658;
    self->f120 = 0;
    self->f124 = 0;
    self->f128 = 0;
    self->f132 = 0;
    self->f136 = 0;
    self->f140 = 0;
    self->f144 = 0;
    self->f148 = 0;
    self->f152 = 0;
    self->f156 = 0;
    self->f160 = 0;
    self->f164 = 0;
    self->f168 = 0;
    self->f172 = 0;
    self->f176 = 0;
    self->f180 = 0;
    load_80342a74(self->f120, n_803816d0);
    load_80342a74(self->f168, n_803816e0);
    load_80342a74(self->f124, n_803816fc);
    load_80342a74(up, n_8038171c);
    load_80342a74(self->f156, n_80381738);
    load_80342a74(self->f132, n_80381754);
    load_80342a74(self->f136, n_8038176c);
    load_80342a74(self->f140, n_80381788);
    load_80342a74(self->f144, n_803817a4);
    load_80342a74(self->f172, n_803817c4);
    load_80342a74(self->f176, n_803817e4);
    load_80342a74(self->f160, n_80381800);
    load_80342a74(self->f164, n_8038181c);
    load_80342fa4(self->f180, n_80381834);
    { Key key; key.name = n_80381840; write_setting_800fc43c(&key, 0); }
    return self;
}
