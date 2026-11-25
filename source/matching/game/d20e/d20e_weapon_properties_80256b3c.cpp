// Weapon property registration and reset (Worms 3D GameCube PAL, 0x80256b3c).
//
// Registers the flag bindings IsAimedWeapon, DamageIsPercentage and
// WormIsWeapon (0x801eb674), RetreatTimeOverride (0x801ebf38) and the typed
// bindings Radius, MinAimAngle and MaxAimAngle (0x801ec52c); resets the
// string properties DischargeFX, DischargeSoundFX, WormCollisionFX and
// LandCollisionFX (0x801ed24c) to the shared empty string 0x804b06a0 through
// a temporary copy; sets the LogicalPositionOffset and ImpulseDirection
// vectors (0x801f0210) to the constant 0x803c90b4 (0.0f); registers
// LogicalLaunchYOffset, the worm/land damage magnitudes, ImpulseMagnitude
// and the three damage/impulse radii (0x801ec52c); calls the refresh
// routine 0x801e8d9c and returns 0. Names are read from the descriptors'
// name pointers in the original data; descriptor layouts stay external.
//
// Same shapes as d20e_timer_widget_reset_80223a78 (string temp-copy
// assignment; both vectors filled through a pointer and copied with an
// inline set(const Vec3 &)). Built with -mps-float (one saved FPR in a
// non-leaf function).
struct SharedString;
extern "C" void d20e_string_init_8020c5c0(SharedString *);
extern "C" unsigned short *d20e_string_header_80341884(SharedString *);
extern "C" void d20e_string_finish_8020c5c4(SharedString *);
extern "C" void d20e_string_release_80341588(SharedString *);
extern "C" void d20e_release_header_8020bb2c(unsigned short *);

struct SharedString {
    char *text;

    // A real external C++ constructor preserves the observed call lifetime.

    SharedString(const SharedString &other) {
        d20e_string_init_8020c5c0(this);
        text = other.text;
        ++*d20e_string_header_80341884(this);
    }

    ~SharedString() {
        d20e_string_finish_8020c5c4(this);
        d20e_string_release_80341588(this);
    }

    SharedString &operator=(const SharedString &other) {
        // The original allocation header begins six bytes before the text;
        // its reference counter is unsigned sixteen-bit, including wrapping.
        ++reinterpret_cast<unsigned short *>(other.text)[-3];
        unsigned short *header = reinterpret_cast<unsigned short *>(text) - 3;
        if (--*header == 0) {
            d20e_release_header_8020bb2c(header);
        }
        text = other.text;
        return *this;
    }
};

struct StringBinding {
    unsigned header[2];
    SharedString value;
};

extern SharedString d20e_empty_804b06a0[];
struct Vec3 { float x, y, z; };
struct VectorBinding {
    unsigned header[2];
    Vec3 value;
    void set(const Vec3 &v) { value = v; }
};
extern "C" {
StringBinding *fn_801ed24c(void *, const void *);
VectorBinding *fn_801f0210(void *, const void *);
void *fn_801eb674(void *, const void *);
void *fn_801ebf38(void *, const void *);
void *fn_801ec52c(void *, const void *);
void fn_801e8d9c(void *);
}
extern const unsigned char desc_803c8d9c[];   // IsAimedWeapon
extern const unsigned char desc_803c8dc4[];   // DamageIsPercentage
extern const unsigned char desc_803c8dfc[];   // WormIsWeapon
extern const unsigned char desc_803c8e24[];   // RetreatTimeOverride
extern const unsigned char desc_803c8e4c[];   // Radius
extern const unsigned char desc_803c8e74[];   // MinAimAngle
extern const unsigned char desc_803c8e9c[];   // MaxAimAngle
extern const unsigned char desc_803c8ec4[];   // DischargeFX
extern const unsigned char desc_803c8ee8[];   // DischargeSoundFX
extern const unsigned char desc_803c8f0c[];   // WormCollisionFX
extern const unsigned char desc_803c8f30[];   // LandCollisionFX
extern const unsigned char desc_803c8f54[];   // LogicalPositionOffset
extern const unsigned char desc_803c8f78[];   // ImpulseDirection
extern const unsigned char desc_803c8f9c[];   // LogicalLaunchYOffset
extern const unsigned char desc_803c8fc4[];   // WormDamageMagnitude
extern const unsigned char desc_803c8fec[];   // LandDamageMagnitude
extern const unsigned char desc_803c9014[];   // ImpulseMagnitude
extern const unsigned char desc_803c903c[];   // WormDamageRadius
extern const unsigned char desc_803c9064[];   // LandDamageRadius
extern const unsigned char desc_803c908c[];   // ImpulseRadius
extern float constant_803c90b4[];
extern "C" int w3d_d20e_register_weapon_properties_80256b3c(void *owner) {
    fn_801eb674(owner, desc_803c8d9c);
    fn_801eb674(owner, desc_803c8dc4);
    fn_801eb674(owner, desc_803c8dfc);
    fn_801ebf38(owner, desc_803c8e24);
    fn_801ec52c(owner, desc_803c8e4c);
    fn_801ec52c(owner, desc_803c8e74);
    fn_801ec52c(owner, desc_803c8e9c);
    fn_801ed24c(owner, desc_803c8ec4)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c8ee8)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c8f0c)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c8f30)->value = SharedString(d20e_empty_804b06a0[0]);
    VectorBinding *first = fn_801f0210(owner, desc_803c8f54);
    float zero = constant_803c90b4[0];
    Vec3 a;
    Vec3 *p = &a;
    p->x = zero;
    p->y = zero;
    p->z = zero;
    first->set(a);
    VectorBinding *second = fn_801f0210(owner, desc_803c8f78);
    Vec3 b;
    Vec3 *q = &b;
    q->x = zero;
    q->y = zero;
    q->z = zero;
    second->set(b);
    fn_801ec52c(owner, desc_803c8f9c);
    fn_801ec52c(owner, desc_803c8fc4);
    fn_801ec52c(owner, desc_803c8fec);
    fn_801ec52c(owner, desc_803c9014);
    fn_801ec52c(owner, desc_803c903c);
    fn_801ec52c(owner, desc_803c9064);
    fn_801ec52c(owner, desc_803c908c);
    fn_801e8d9c(owner);
    return 0;
}
