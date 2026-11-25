// Weapon animation property registration (Worms 3D GameCube PAL, 0x802525c4).
//
// In call order: resets the DisplayName string binding (0x801ed24c) to the
// shared empty string; resets the AnimDraw string binding (0x801ed24c) to
// the shared empty string; resets the AnimAim string binding (0x801ed24c) to
// the shared empty string; resets the AnimFire string binding (0x801ed24c)
// to the shared empty string; resets the AnimHolding string binding
// (0x801ed24c) to the shared empty string; resets the AnimEndFire string
// binding (0x801ed24c) to the shared empty string; resets the
// WeaponGraphicsResourceID string binding (0x801ed24c) to the shared empty
// string; registers WeaponType (0x801ece2c); registers DefaultPreference
// (0x801ec52c); registers CurrentPreference (0x801ec52c); registers
// LaunchDelay (0x801ebf38); registers PostLaunchDelay (0x801ebf38); creates
// the FirstPersonOffset vector binding (0x801f0210) reset to 0.0f; creates
// the FirstPersonScale vector binding (0x801f0210) reset to 0.0f; resets the
// FirstPersonFiringParticleEffect string binding (0x801ed24c) to the shared
// empty string; resets the FirstPersonDrawAnim string binding (0x801ed24c)
// to the shared empty string; resets the FirstPersonWindUpAnim string
// binding (0x801ed24c) to the shared empty string; resets the
// FirstPersonFireAnim string binding (0x801ed24c) to the shared empty
// string; resets the FirstPersonWindDownAnim string binding (0x801ed24c) to
// the shared empty string; resets the FirstPersonReloadAnim string binding
// (0x801ed24c) to the shared empty string; resets the FirstPersonHideAnim
// string binding (0x801ed24c) to the shared empty string; resets the
// FirstPersonIdleAnim string binding (0x801ed24c) to the shared empty
// string; resets the FirstPersonHandDrawAnim string binding (0x801ed24c) to
// the shared empty string; resets the FirstPersonHandWindUpAnim string
// binding (0x801ed24c) to the shared empty string; resets the
// FirstPersonHandFireAnim string binding (0x801ed24c) to the shared empty
// string; resets the FirstPersonHandWindDownAnim string binding (0x801ed24c)
// to the shared empty string; resets the FirstPersonHandReloadAnim string
// binding (0x801ed24c) to the shared empty string; resets the
// FirstPersonHandHideAnim string binding (0x801ed24c) to the shared empty
// string; resets the FirstPersonHandIdleAnim string binding (0x801ed24c) to
// the shared empty string; registers DisplayInFirstPerson (0x801eb674);
// registers CanBeFiredWhenWormMoving (0x801eb674); registers RumbleLight
// (0x801eb834); registers RumbleHeavy (0x801eb834); then calls the refresh
// routine 0x801e8d9c and returns 0. Names are read from the descriptors'
// name pointers in the original data. Vector resets use the constant
// 0x803c66ec (0.0f).
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
void * fn_801eb834(void *, const void *);
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
extern "C" void * fn_801ece2c(void *, const void *);
extern const unsigned char desc_803c5fa0[];  // DisplayName
extern const unsigned char desc_803c5fd0[];  // AnimDraw
extern const unsigned char desc_803c5ffc[];  // AnimAim
extern const unsigned char desc_803c602c[];  // AnimFire
extern const unsigned char desc_803c605c[];  // AnimHolding
extern const unsigned char desc_803c608c[];  // AnimEndFire
extern const unsigned char desc_803c60cc[];  // WeaponGraphicsResourceID
extern const unsigned char desc_803c60fc[];  // WeaponType
extern const unsigned char desc_803c6138[];  // DefaultPreference
extern const unsigned char desc_803c6174[];  // CurrentPreference
extern const unsigned char desc_803c61a8[];  // LaunchDelay
extern const unsigned char desc_803c61e0[];  // PostLaunchDelay
extern const unsigned char desc_803c621c[];  // FirstPersonOffset
extern const unsigned char desc_803c6254[];  // FirstPersonScale
extern const unsigned char desc_803c6298[];  // FirstPersonFiringParticleEffect
extern const unsigned char desc_803c62d0[];  // FirstPersonDrawAnim
extern const unsigned char desc_803c630c[];  // FirstPersonWindUpAnim
extern const unsigned char desc_803c6344[];  // FirstPersonFireAnim
extern const unsigned char desc_803c6380[];  // FirstPersonWindDownAnim
extern const unsigned char desc_803c63bc[];  // FirstPersonReloadAnim
extern const unsigned char desc_803c63f4[];  // FirstPersonHideAnim
extern const unsigned char desc_803c642c[];  // FirstPersonIdleAnim
extern const unsigned char desc_803c6468[];  // FirstPersonHandDrawAnim
extern const unsigned char desc_803c64a8[];  // FirstPersonHandWindUpAnim
extern const unsigned char desc_803c64e4[];  // FirstPersonHandFireAnim
extern const unsigned char desc_803c6524[];  // FirstPersonHandWindDownAnim
extern const unsigned char desc_803c6564[];  // FirstPersonHandReloadAnim
extern const unsigned char desc_803c65a0[];  // FirstPersonHandHideAnim
extern const unsigned char desc_803c65dc[];  // FirstPersonHandIdleAnim
extern const unsigned char desc_803c6618[];  // DisplayInFirstPerson
extern const unsigned char desc_803c665c[];  // CanBeFiredWhenWormMoving
extern const unsigned char desc_803c6690[];  // RumbleLight
extern const unsigned char desc_803c66c4[];  // RumbleHeavy
extern float constant_803c66ec[];
extern "C" int w3d_d21e_register_weapon_animation_properties_802525c4(void *owner) {
    fn_801ed24c(owner, desc_803c5fa0)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c5fd0)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c5ffc)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c602c)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c605c)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c608c)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c60cc)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ece2c(owner, desc_803c60fc);
    fn_801ec52c(owner, desc_803c6138);
    fn_801ec52c(owner, desc_803c6174);
    fn_801ebf38(owner, desc_803c61a8);
    fn_801ebf38(owner, desc_803c61e0);
    VectorBinding *v1 = fn_801f0210(owner, desc_803c621c);
    float zero = constant_803c66ec[0];
    Vec3 t1;
    Vec3 *p1 = &t1;
    p1->x = zero;
    p1->y = zero;
    p1->z = zero;
    v1->set(t1);
    VectorBinding *v2 = fn_801f0210(owner, desc_803c6254);
    Vec3 t2;
    Vec3 *p2 = &t2;
    p2->x = zero;
    p2->y = zero;
    p2->z = zero;
    v2->set(t2);
    fn_801ed24c(owner, desc_803c6298)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c62d0)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c630c)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c6344)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c6380)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c63bc)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c63f4)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c642c)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c6468)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c64a8)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c64e4)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c6524)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c6564)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c65a0)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c65dc)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801eb674(owner, desc_803c6618);
    fn_801eb674(owner, desc_803c665c);
    fn_801eb834(owner, desc_803c6690);
    fn_801eb834(owner, desc_803c66c4);
    fn_801e8d9c(owner);
    return 0;
}
