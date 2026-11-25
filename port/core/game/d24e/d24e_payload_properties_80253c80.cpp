#include "w3d_ptr.h"
#line 1 "d24e_payload_properties_80253c80.cpp"
// Weapon payload property registration (Worms 3D GameCube PAL, 0x80253c80).
//
// In call order: registers IsAimedWeapon (0x801eb674); registers
// IsPoweredWeapon (0x801eb674); registers IsTargetingWeapon (0x801eb674);
// registers IsBomberWeapon (0x801eb674); registers IsDirectionalWeapon
// (0x801eb674); registers IsHoming (0x801eb674); registers IsLowGravity
// (0x801eb674); registers IsLaunchedFromWorm (0x801eb674); registers
// HasAdjustableFuse (0x801eb674); registers HasAdjustableBounce
// (0x801eb674); registers HasAdjustableHerd (0x801eb674); registers
// IsAffectedByGravity (0x801eb674); registers IsAffectedByWind (0x801eb674);
// registers ColliderFlags (0x801ebf38); registers CameraId (0x801efff0) with
// a guarded function-local static descriptor built once from a zero-filled
// temporary; resets the PayloadGraphicsResourceID string binding
// (0x801ed24c) to the shared empty string; registers Scale (0x801ec52c);
// registers Radius (0x801ec52c); resets the AnimTravel string binding
// (0x801ed24c) to the shared empty string; resets the AnimSmallJump string
// binding (0x801ed24c) to the shared empty string; resets the AnimBigJump
// string binding (0x801ed24c) to the shared empty string; resets the AnimArm
// string binding (0x801ed24c) to the shared empty string; resets the
// AnimSplashdown string binding (0x801ed24c) to the shared empty string;
// resets the AnimSink string binding (0x801ed24c) to the shared empty
// string; registers DirectionBlend (0x801ec52c); registers BasePower
// (0x801ec52c); registers MaxPower (0x801ec52c); registers
// MinTerminalVelocity (0x801ec52c); registers MaxTerminalVelocity
// (0x801ec52c); registers LogicalLaunchZOffset (0x801ec52c); registers
// OrientationOption (0x801ebf38); registers SpinSpeed (0x801ec52c);
// registers InterPayloadDelay (0x801ebf38); registers DetonatesOnLandImpact
// (0x801eb674); registers DetonatesOnExpiry (0x801eb674); registers
// DetonatesOnObjectImpact (0x801eb674); registers DetonatesOnWormImpact
// (0x801eb674); registers DetonatesAtRest (0x801eb674); registers
// DetonatesOnFirePress (0x801eb674); registers DetonatesWhenCantJump
// (0x801eb674); registers WormDamageMagnitude (0x801ec52c); registers
// ImpulseMagnitude (0x801ec52c); registers WormDamageRadius (0x801ec52c);
// registers LandDamageRadius (0x801ec52c); registers ImpulseRadius
// (0x801ec52c); registers ImpulseOffset (0x801ec52c); registers Mass
// (0x801ec52c); registers MaxPowerUp (0x801ebf38); registers
// TangentialMinBounceDamping (0x801ec52c); registers
// ParallelMinBounceDamping (0x801ec52c); registers
// TangentialMaxBounceDamping (0x801ec52c); registers
// ParallelMaxBounceDamping (0x801ec52c); registers SkimsOnWater
// (0x801eb674); registers MinSpeedForSkim (0x801ec52c); registers
// MaxAngleForSkim (0x801ec52c); creates the SkimDamping vector binding
// (0x801f0210) reset to 0.0f; registers SinkDepth (0x801ec52c); registers
// NumBomblets (0x801ebf38); registers BombletMaxConeAngle (0x801ec52c);
// registers BombletMaxSpeed (0x801ec52c); registers BombletMinSpeed
// (0x801ec52c); resets the BombletWeaponName string binding (0x801ed24c) to
// the shared empty string; resets the FxLocator string binding (0x801ed24c)
// to the shared empty string; resets the ArielFx string binding (0x801ed24c)
// to the shared empty string; resets the DetonationFx string binding
// (0x801ed24c) to the shared empty string; resets the DetonationSfx string
// binding (0x801ed24c) to the shared empty string; resets the ExpiryFx
// string binding (0x801ed24c) to the shared empty string; resets the
// SplashFx string binding (0x801ed24c) to the shared empty string; resets
// the SplishFx string binding (0x801ed24c) to the shared empty string;
// resets the SinkingFx string binding (0x801ed24c) to the shared empty
// string; resets the BounceFx string binding (0x801ed24c) to the shared
// empty string; registers StopFxAtRest (0x801eb674); resets the BounceSfx
// string binding (0x801ed24c) to the shared empty string; resets the
// PreDetonationSfx string binding (0x801ed24c) to the shared empty string;
// resets the ArmSfx1Shot string binding (0x801ed24c) to the shared empty
// string; resets the ArmSfxLoop string binding (0x801ed24c) to the shared
// empty string; resets the LaunchSfx string binding (0x801ed24c) to the
// shared empty string; resets the LoopSfx string binding (0x801ed24c) to the
// shared empty string; resets the BigJumpSfx string binding (0x801ed24c) to
// the shared empty string; resets the WalkSfx string binding (0x801ed24c) to
// the shared empty string; resets the TrailBitmap string binding
// (0x801ed24c) to the shared empty string; resets the TrailLocator1 string
// binding (0x801ed24c) to the shared empty string; resets the TrailLocator2
// string binding (0x801ed24c) to the shared empty string; registers
// TrailLength (0x801ebf38); resets the AttachedMesh string binding
// (0x801ed24c) to the shared empty string; registers AttachedMeshScale
// (0x801ec52c); registers StartsArmed (0x801eb674); registers
// RetreatTimeOverride (0x801ebf38); registers ArmingCourtesyTime
// (0x801ebf38); registers PreDetonationTime (0x801ebf38); registers
// ArmingRadius (0x801ec52c); registers LifeTime (0x801ec0f8); registers
// IsFuseDisplayed (0x801eb674); then calls the refresh routine 0x801e8d9c
// and returns 0. Names are read from the descriptors' name pointers in the
// original data. Vector resets use the constant 0x803c7af8 (0.0f).
//
// String resets assign a temporary copy of the shared empty string
// 0x804b06a0 (copy constructor, shared-header assignment, destructor), as in
// d20e_timer_widget_reset_80223a78. Property descriptors are function-local
// statics initialized from a GNU statement expression over a memset-zeroed
// local (d20e_box_properties_801c4930); guards and objects are zero-
// initialized statics of this function, not file-backed. Vectors are filled
// through a pointer and copied with an inline set(const Vec3 &) (d18e
// recipe).  No saved FPR, no extra compiler options.
extern "C" Ptr32<void> memset(...);
struct SharedString;
extern "C" void d20e_string_init_8020c5c0(Ptr32<SharedString>);
extern "C" Ptr32<unsigned short> d20e_string_header_80341884(Ptr32<SharedString>);
extern "C" void d20e_string_finish_8020c5c4(Ptr32<SharedString>);
extern "C" void d20e_string_release_80341588(Ptr32<SharedString>);
extern "C" void d20e_release_header_8020bb2c(Ptr32<unsigned short>);

struct SharedString {
    Ptr32<char> text;

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
        ++reinterpret_cast<unsigned short *>(w3d::R(other.text))[-3];
        Ptr32<unsigned short> header = reinterpret_cast<unsigned short *>(w3d::R(text)) - 3;
        if (--*header == 0) {
            d20e_release_header_8020bb2c(header);
        }
        text = other.text;
        return *this;
    }

    // Takes its value by copy, so the temporary is built at the call.
    void set(SharedString v) { *this = v; }
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
    Ptr32<const char> name;
    unsigned short size;
    unsigned char elementType;
    unsigned char type;
    Ptr32<void> typeObject;
    Ptr32<const void> member;
    int unknown16;
    void clear() { memset(w3d::VA(this), 0, sizeof(*this)); }
};
extern "C" {
Ptr32<StringBinding> fn_801ed24c(Ptr32<void>, Ptr32<const void>);
Ptr32<VectorBinding> fn_801f0210(Ptr32<void>, Ptr32<const void>);
Ptr32<Vec2Binding> fn_801f00f0(Ptr32<void>, Ptr32<const void>);
Ptr32<ColourBinding> fn_801f15e0(Ptr32<void>, Ptr32<const void>);
void fn_801eb834(Ptr32<void>, Ptr32<const void>);
Ptr32<void> fn_801eb674(Ptr32<void>, Ptr32<const void>);
Ptr32<void> fn_801ec52c(Ptr32<void>, Ptr32<const void>);
void fn_801f25b0(Ptr32<void>, Ptr32<PropertyInfo>);
void fn_801efec4(Ptr32<void>, Ptr32<PropertyInfo>);
void fn_801efdfc(Ptr32<void>, Ptr32<PropertyInfo>);
void fn_801eff8c(Ptr32<void>, Ptr32<PropertyInfo>);
void fn_801e8d9c(Ptr32<void>);
}
extern "C" Ptr32<void> fn_801ebf38(Ptr32<void>, Ptr32<const void>);
extern "C" Ptr32<void> fn_801ec0f8(Ptr32<void>, Ptr32<const void>);
extern "C" Ptr32<void> fn_801efff0(Ptr32<void>, Ptr32<PropertyInfo>);
extern const unsigned char desc_803c6728[];  // IsAimedWeapon
extern const unsigned char desc_803c6760[];  // IsPoweredWeapon
extern const unsigned char desc_803c679c[];  // IsTargetingWeapon
extern const unsigned char desc_803c67d4[];  // IsBomberWeapon
extern const unsigned char desc_803c6810[];  // IsDirectionalWeapon
extern const unsigned char desc_803c6844[];  // IsHoming
extern const unsigned char desc_803c687c[];  // IsLowGravity
extern const unsigned char desc_803c68b8[];  // IsLaunchedFromWorm
extern const unsigned char desc_803c68f4[];  // HasAdjustableFuse
extern const unsigned char desc_803c6930[];  // HasAdjustableBounce
extern const unsigned char desc_803c696c[];  // HasAdjustableHerd
extern const unsigned char desc_803c69a8[];  // IsAffectedByGravity
extern const unsigned char desc_803c69e4[];  // IsAffectedByWind
extern const unsigned char desc_803c6a1c[];  // ColliderFlags
extern const unsigned char desc_803c6a6c[];  // PayloadGraphicsResourceID
extern const unsigned char desc_803c6a98[];  // Scale
extern const unsigned char desc_803c6ac8[];  // Radius
extern const unsigned char desc_803c6afc[];  // AnimTravel
extern const unsigned char desc_803c6b30[];  // AnimSmallJump
extern const unsigned char desc_803c6b60[];  // AnimBigJump
extern const unsigned char desc_803c6b8c[];  // AnimArm
extern const unsigned char desc_803c6bc0[];  // AnimSplashdown
extern const unsigned char desc_803c6bf0[];  // AnimSink
extern const unsigned char desc_803c6c24[];  // DirectionBlend
extern const unsigned char desc_803c6c58[];  // BasePower
extern const unsigned char desc_803c6c8c[];  // MaxPower
extern const unsigned char desc_803c6cc8[];  // MinTerminalVelocity
extern const unsigned char desc_803c6d04[];  // MaxTerminalVelocity
extern const unsigned char desc_803c6d44[];  // LogicalLaunchZOffset
extern const unsigned char desc_803c6d80[];  // OrientationOption
extern const unsigned char desc_803c6db4[];  // SpinSpeed
extern const unsigned char desc_803c6df0[];  // InterPayloadDelay
extern const unsigned char desc_803c6e30[];  // DetonatesOnLandImpact
extern const unsigned char desc_803c6e6c[];  // DetonatesOnExpiry
extern const unsigned char desc_803c6eac[];  // DetonatesOnObjectImpact
extern const unsigned char desc_803c6eec[];  // DetonatesOnWormImpact
extern const unsigned char desc_803c6f24[];  // DetonatesAtRest
extern const unsigned char desc_803c6f64[];  // DetonatesOnFirePress
extern const unsigned char desc_803c6fa4[];  // DetonatesWhenCantJump
extern const unsigned char desc_803c6fe0[];  // WormDamageMagnitude
extern const unsigned char desc_803c701c[];  // ImpulseMagnitude
extern const unsigned char desc_803c7058[];  // WormDamageRadius
extern const unsigned char desc_803c7094[];  // LandDamageRadius
extern const unsigned char desc_803c70cc[];  // ImpulseRadius
extern const unsigned char desc_803c7104[];  // ImpulseOffset
extern const unsigned char desc_803c7134[];  // Mass
extern const unsigned char desc_803c7168[];  // MaxPowerUp
extern const unsigned char desc_803c71ac[];  // TangentialMinBounceDamping
extern const unsigned char desc_803c71f0[];  // ParallelMinBounceDamping
extern const unsigned char desc_803c7234[];  // TangentialMaxBounceDamping
extern const unsigned char desc_803c7278[];  // ParallelMaxBounceDamping
extern const unsigned char desc_803c72b0[];  // SkimsOnWater
extern const unsigned char desc_803c72e8[];  // MinSpeedForSkim
extern const unsigned char desc_803c7320[];  // MaxAngleForSkim
extern const unsigned char desc_803c7354[];  // SkimDamping
extern const unsigned char desc_803c7384[];  // SinkDepth
extern const unsigned char desc_803c73b8[];  // NumBomblets
extern const unsigned char desc_803c73f4[];  // BombletMaxConeAngle
extern const unsigned char desc_803c742c[];  // BombletMaxSpeed
extern const unsigned char desc_803c7464[];  // BombletMinSpeed
extern const unsigned char desc_803c74a0[];  // BombletWeaponName
extern const unsigned char desc_803c74d0[];  // FxLocator
extern const unsigned char desc_803c74fc[];  // ArielFx
extern const unsigned char desc_803c7530[];  // DetonationFx
extern const unsigned char desc_803c7564[];  // DetonationSfx
extern const unsigned char desc_803c7594[];  // ExpiryFx
extern const unsigned char desc_803c75c4[];  // SplashFx
extern const unsigned char desc_803c75f4[];  // SplishFx
extern const unsigned char desc_803c7624[];  // SinkingFx
extern const unsigned char desc_803c7654[];  // BounceFx
extern const unsigned char desc_803c7688[];  // StopFxAtRest
extern const unsigned char desc_803c76bc[];  // BounceSfx
extern const unsigned char desc_803c76f4[];  // PreDetonationSfx
extern const unsigned char desc_803c7724[];  // ArmSfx1Shot
extern const unsigned char desc_803c7754[];  // ArmSfxLoop
extern const unsigned char desc_803c7784[];  // LaunchSfx
extern const unsigned char desc_803c77b0[];  // LoopSfx
extern const unsigned char desc_803c77e0[];  // BigJumpSfx
extern const unsigned char desc_803c780c[];  // WalkSfx
extern const unsigned char desc_803c783c[];  // TrailBitmap
extern const unsigned char desc_803c7870[];  // TrailLocator1
extern const unsigned char desc_803c78a4[];  // TrailLocator2
extern const unsigned char desc_803c78d4[];  // TrailLength
extern const unsigned char desc_803c790c[];  // AttachedMesh
extern const unsigned char desc_803c7944[];  // AttachedMeshScale
extern const unsigned char desc_803c7978[];  // StartsArmed
extern const unsigned char desc_803c79b4[];  // RetreatTimeOverride
extern const unsigned char desc_803c79f0[];  // ArmingCourtesyTime
extern const unsigned char desc_803c7a2c[];  // PreDetonationTime
extern const unsigned char desc_803c7a64[];  // ArmingRadius
extern const unsigned char desc_803c7a98[];  // LifeTime
extern const unsigned char desc_803c7ad0[];  // IsFuseDisplayed
extern char lbl_803c6a44[];
extern char lbl_8045ed94[];
extern float constant_803c7af8[];
extern "C" int w3d_d24e_register_payload_properties_80253c80(Ptr32<void> owner) {
    fn_801eb674(owner, desc_803c6728);
    fn_801eb674(owner, desc_803c6760);
    fn_801eb674(owner, desc_803c679c);
    fn_801eb674(owner, desc_803c67d4);
    fn_801eb674(owner, desc_803c6810);
    fn_801eb674(owner, desc_803c6844);
    fn_801eb674(owner, desc_803c687c);
    fn_801eb674(owner, desc_803c68b8);
    fn_801eb674(owner, desc_803c68f4);
    fn_801eb674(owner, desc_803c6930);
    fn_801eb674(owner, desc_803c696c);
    fn_801eb674(owner, desc_803c69a8);
    fn_801eb674(owner, desc_803c69e4);
    fn_801ebf38(owner, desc_803c6a1c);
    static PropertyInfo info14 = ({
        PropertyInfo t;
        t.clear();
        t.name = lbl_803c6a44;  // "CameraId"
        t.size = 232;
        t.elementType = 47;
        t.type = 9;
        t.typeObject = lbl_8045ed94;
        t;
    });
    fn_801efff0(owner, &info14);
    fn_801ed24c(owner, desc_803c6a6c)->value.set(d20e_empty_804b06a0[0]);
    fn_801ec52c(owner, desc_803c6a98);
    fn_801ec52c(owner, desc_803c6ac8);
    fn_801ed24c(owner, desc_803c6afc)->value.set(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c6b30)->value.set(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c6b60)->value.set(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c6b8c)->value.set(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c6bc0)->value.set(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c6bf0)->value.set(d20e_empty_804b06a0[0]);
    fn_801ec52c(owner, desc_803c6c24);
    fn_801ec52c(owner, desc_803c6c58);
    fn_801ec52c(owner, desc_803c6c8c);
    fn_801ec52c(owner, desc_803c6cc8);
    fn_801ec52c(owner, desc_803c6d04);
    fn_801ec52c(owner, desc_803c6d44);
    fn_801ebf38(owner, desc_803c6d80);
    fn_801ec52c(owner, desc_803c6db4);
    fn_801ebf38(owner, desc_803c6df0);
    fn_801eb674(owner, desc_803c6e30);
    fn_801eb674(owner, desc_803c6e6c);
    fn_801eb674(owner, desc_803c6eac);
    fn_801eb674(owner, desc_803c6eec);
    fn_801eb674(owner, desc_803c6f24);
    fn_801eb674(owner, desc_803c6f64);
    fn_801eb674(owner, desc_803c6fa4);
    fn_801ec52c(owner, desc_803c6fe0);
    fn_801ec52c(owner, desc_803c701c);
    fn_801ec52c(owner, desc_803c7058);
    fn_801ec52c(owner, desc_803c7094);
    fn_801ec52c(owner, desc_803c70cc);
    fn_801ec52c(owner, desc_803c7104);
    fn_801ec52c(owner, desc_803c7134);
    fn_801ebf38(owner, desc_803c7168);
    fn_801ec52c(owner, desc_803c71ac);
    fn_801ec52c(owner, desc_803c71f0);
    fn_801ec52c(owner, desc_803c7234);
    fn_801ec52c(owner, desc_803c7278);
    fn_801eb674(owner, desc_803c72b0);
    fn_801ec52c(owner, desc_803c72e8);
    fn_801ec52c(owner, desc_803c7320);
    Ptr32<VectorBinding> v1 = fn_801f0210(owner, desc_803c7354);
    float zero = constant_803c7af8[0];
    Vec3 t1;
    Ptr32<Vec3> p1 = &t1;
    p1->x = zero;
    p1->y = zero;
    p1->z = zero;
    v1->set(t1);
    fn_801ec52c(owner, desc_803c7384);
    fn_801ebf38(owner, desc_803c73b8);
    fn_801ec52c(owner, desc_803c73f4);
    fn_801ec52c(owner, desc_803c742c);
    fn_801ec52c(owner, desc_803c7464);
    fn_801ed24c(owner, desc_803c74a0)->value.set(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c74d0)->value.set(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c74fc)->value.set(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c7530)->value.set(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c7564)->value.set(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c7594)->value.set(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c75c4)->value.set(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c75f4)->value.set(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c7624)->value.set(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c7654)->value.set(d20e_empty_804b06a0[0]);
    fn_801eb674(owner, desc_803c7688);
    fn_801ed24c(owner, desc_803c76bc)->value.set(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c76f4)->value.set(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c7724)->value.set(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c7754)->value.set(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c7784)->value.set(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c77b0)->value.set(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c77e0)->value.set(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c780c)->value.set(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c783c)->value.set(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c7870)->value.set(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803c78a4)->value.set(d20e_empty_804b06a0[0]);
    fn_801ebf38(owner, desc_803c78d4);
    fn_801ed24c(owner, desc_803c790c)->value.set(d20e_empty_804b06a0[0]);
    fn_801ec52c(owner, desc_803c7944);
    fn_801eb674(owner, desc_803c7978);
    fn_801ebf38(owner, desc_803c79b4);
    fn_801ebf38(owner, desc_803c79f0);
    fn_801ebf38(owner, desc_803c7a2c);
    fn_801ec52c(owner, desc_803c7a64);
    fn_801ec0f8(owner, desc_803c7a98);
    fn_801eb674(owner, desc_803c7ad0);
    fn_801e8d9c(owner);
    return 0;
}


