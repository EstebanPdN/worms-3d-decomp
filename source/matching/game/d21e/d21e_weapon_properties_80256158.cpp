// Weapon property registration (Worms 3D GameCube PAL, 0x80256158).
//
// In call order: registers IsAimedWeapon (0x801eb674); registers
// IsAffectedByGravity (0x801eb674); registers IsAffectedByWind (0x801eb674);
// registers bCanDamageLand (0x801eb674); registers bCanMoveBetweenShots
// (0x801eb674); registers ImpulseIsNormal (0x801eb674); registers
// DamageIsPercentage (0x801eb674); registers LaserEffect (0x801eb674);
// registers RetreatTimeOverride (0x801ebf38); registers NumberOfBullets
// (0x801ebf38); registers DischargeTime (0x801ebf38); registers Range
// (0x801ebf38); registers WaitForSoundDelay (0x801ebf38); registers Accuracy
// (0x801ec52c); registers WormDamageMagnitude (0x801ec52c); registers
// WormPoisonMagnitude (0x801ec52c); registers LandDamageMagnitude
// (0x801ec52c); registers ImpulseMagnitude (0x801ec52c); registers
// BulletRadius (0x801ec52c); registers MinAimAngle (0x801ec52c); registers
// MaxAimAngle (0x801ec52c); registers WormDamageRadius (0x801ec52c);
// registers LandDamageRadius (0x801ec52c); registers ImpulseRadius
// (0x801ec52c); registers LogicalLaunchYOffset (0x801ec52c); resets the
// DischargeFX string binding (0x801ed24c) to the shared empty string; resets
// the DischargeEndFX string binding (0x801ed24c) to the shared empty string;
// resets the SecondaryDischargeFX string binding (0x801ed24c) to the shared
// empty string; resets the SecondaryDischargeFXLocator string binding
// (0x801ed24c) to the shared empty string; resets the DischargeSoundFX
// string binding (0x801ed24c) to the shared empty string; resets the
// DischargeEndSoundFX string binding (0x801ed24c) to the shared empty
// string; resets the WormCollisionFX string binding (0x801ed24c) to the
// shared empty string; resets the LandCollisionFX string binding
// (0x801ed24c) to the shared empty string; resets the WaterCollisionFX
// string binding (0x801ed24c) to the shared empty string; creates the
// LogicalPositionOffset vector binding (0x801f0210) reset to 0.0f; creates
// the ImpulseDirection vector binding (0x801f0210) reset to 0.0f; registers
// DischargeFXZOffset (0x801ec52c); registers KickSize (0x801ec52c);
// registers KickFrequency (0x801ebf38); then calls the refresh routine
// 0x801e8d9c and returns 0. Names are read from the descriptors' name
// pointers in the original data. Vector resets use the constant 0x803c8d74
// (0.0f).
//
// String resets assign a temporary copy of the shared empty string
// 0x804b06a0 (copy constructor, shared-header assignment, destructor), as in
// d20e_timer_widget_reset_80223a78. Vectors are filled through a pointer and
// copied with an inline set(const Vec3 &) (d18e recipe).  Built with -mps-
// float (one saved FPR in a non-leaf function).
extern "C" void *memset(...);
struct SharedString;
extern "C" void d20e_string_init_8020c5c0(SharedString *);
extern "C" unsigned short *d20e_string_header_80341884(SharedString *);
extern "C" void d20e_string_finish_8020c5c4(SharedString *);
extern "C" void d20e_string_release_80341588(SharedString *);
extern "C" void d20e_release_header_8020bb2c(unsigned short *);

struct SharedString {
    char *text;

    // Copy constructor: initializes the shared string and takes a
    // reference on the source text (16-bit header counter).
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
struct Vec2 { float x, y; };
struct Vec2Binding {
    unsigned header[2];
    Vec2 value;
    void set(const Vec2 &v) { value = v; }
};
struct Colour {
    unsigned char r, g, b, a;
    Colour(unsigned char r_, unsigned char g_, unsigned char b_, unsigned char a_) : r(r_), g(g_), b(b_), a(a_) {}
};
struct ColourBinding {
    unsigned header[2];
    Colour value;
};
struct PropertyInfo {
    const char *name;
    unsigned short size;
    unsigned char elementType;
    unsigned char type;
    void *typeObject;
    const void *member;
    int unknown16;
    void clear() { memset(this, 0, sizeof(*this)); }
};
extern "C" {
StringBinding *fn_801ed24c(void *, const void *);
VectorBinding *fn_801f0210(void *, const void *);
Vec2Binding *fn_801f00f0(void *, const void *);
ColourBinding *fn_801f15e0(void *, const void *);
void fn_801eb834(void *, const void *);
void * fn_801ebf38(void *, const void *);
void * fn_801eb674(void *, const void *);
void * fn_801ec52c(void *, const void *);
void fn_801f25b0(void *, PropertyInfo *);
void fn_801efec4(void *, PropertyInfo *);
void fn_801efdfc(void *, PropertyInfo *);
void fn_801eff8c(void *, PropertyInfo *);
void fn_801e8d9c(void *);
}
extern "C" void * fn_801ebf38(void *, const void *);
extern const unsigned char desc_803c8578[];  // IsAimedWeapon
extern const unsigned char desc_803c85a0[];  // IsAffectedByGravity
extern const unsigned char desc_803c85c8[];  // IsAffectedByWind
extern const unsigned char desc_803c8600[];  // bCanDamageLand
extern const unsigned char desc_803c8640[];  // bCanMoveBetweenShots
extern const unsigned char desc_803c8678[];  // ImpulseIsNormal
extern const unsigned char desc_803c86b4[];  // DamageIsPercentage
extern const unsigned char desc_803c86e8[];  // LaserEffect
extern const unsigned char desc_803c8710[];  // RetreatTimeOverride
extern const unsigned char desc_803c8748[];  // NumberOfBullets
extern const unsigned char desc_803c8780[];  // DischargeTime
extern const unsigned char desc_803c87b0[];  // Range
extern const unsigned char desc_803c87ec[];  // WaitForSoundDelay
extern const unsigned char desc_803c8820[];  // Accuracy
extern const unsigned char desc_803c8848[];  // WormDamageMagnitude
extern const unsigned char desc_803c8884[];  // WormPoisonMagnitude
extern const unsigned char desc_803c88c0[];  // LandDamageMagnitude
extern const unsigned char desc_803c88e8[];  // ImpulseMagnitude
extern const unsigned char desc_803c8920[];  // BulletRadius
extern const unsigned char desc_803c8954[];  // MinAimAngle
extern const unsigned char desc_803c8988[];  // MaxAimAngle
extern const unsigned char desc_803c89b0[];  // WormDamageRadius
extern const unsigned char desc_803c89d8[];  // LandDamageRadius
extern const unsigned char desc_803c8a00[];  // ImpulseRadius
extern const unsigned char desc_803c8a40[];  // LogicalLaunchYOffset
extern const unsigned char desc_803c8a74[];  // DischargeFX
extern const unsigned char desc_803c8aa8[];  // DischargeEndFX
extern const unsigned char desc_803c8ae4[];  // SecondaryDischargeFX
extern const unsigned char desc_803c8b24[];  // SecondaryDischargeFXLocator
extern const unsigned char desc_803c8b5c[];  // DischargeSoundFX
extern const unsigned char desc_803c8b94[];  // DischargeEndSoundFX
extern const unsigned char desc_803c8bc8[];  // WormCollisionFX
extern const unsigned char desc_803c8bfc[];  // LandCollisionFX
extern const unsigned char desc_803c8c34[];  // WaterCollisionFX
extern const unsigned char desc_803c8c70[];  // LogicalPositionOffset
extern const unsigned char desc_803c8ca8[];  // ImpulseDirection
extern const unsigned char desc_803c8ce0[];  // DischargeFXZOffset
extern const unsigned char desc_803c8d14[];  // KickSize
extern const unsigned char desc_803c8d4c[];  // KickFrequency
extern float constant_803c8d74[];
extern "C" int w3d_d21e_register_weapon_properties_80256158(void *owner) {
    fn_801eb674(owner, desc_803c8578);
    fn_801eb674(owner, desc_803c85a0);
    fn_801eb674(owner, desc_803c85c8);
    fn_801eb674(owner, desc_803c8600);
    fn_801eb674(owner, desc_803c8640);
    fn_801eb674(owner, desc_803c8678);
    fn_801eb674(owner, desc_803c86b4);
    fn_801eb674(owner, desc_803c86e8);
    fn_801ebf38(owner, desc_803c8710);
    fn_801ebf38(owner, desc_803c8748);
    fn_801ebf38(owner, desc_803c8780);
    fn_801ebf38(owner, desc_803c87b0);
    fn_801ebf38(owner, desc_803c87ec);
    fn_801ec52c(owner, desc_803c8820);
    fn_801ec52c(owner, desc_803c8848);
    fn_801ec52c(owner, desc_803c8884);
    fn_801ec52c(owner, desc_803c88c0);
    fn_801ec52c(owner, desc_803c88e8);
    fn_801ec52c(owner, desc_803c8920);
    fn_801ec52c(owner, desc_803c8954);
    fn_801ec52c(owner, desc_803c8988);
    fn_801ec52c(owner, desc_803c89b0);
    fn_801ec52c(owner, desc_803c89d8);
    fn_801ec52c(owner, desc_803c8a00);
    fn_801ec52c(owner, desc_803c8a40);
    fn_801ed24c(owner, desc_803c8a74)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c8aa8)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c8ae4)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c8b24)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c8b5c)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c8b94)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c8bc8)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c8bfc)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c8c34)->value = SharedString(d20e_empty_804b06a0[0]);
    VectorBinding *v1 = fn_801f0210(owner, desc_803c8c70);
    float zero = constant_803c8d74[0];
    Vec3 t1;
    Vec3 *p1 = &t1;
    p1->x = zero;
    p1->y = zero;
    p1->z = zero;
    v1->set(t1);
    VectorBinding *v2 = fn_801f0210(owner, desc_803c8ca8);
    Vec3 t2;
    Vec3 *p2 = &t2;
    p2->x = zero;
    p2->y = zero;
    p2->z = zero;
    v2->set(t2);
    fn_801ec52c(owner, desc_803c8ce0);
    fn_801ec52c(owner, desc_803c8d14);
    fn_801ebf38(owner, desc_803c8d4c);
    fn_801e8d9c(owner);
    return 0;
}
