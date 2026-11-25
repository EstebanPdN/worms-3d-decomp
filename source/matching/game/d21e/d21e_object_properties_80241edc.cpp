// Object property registration (Worms 3D GameCube PAL, 0x80241edc).
//
// In call order: resets the Name string binding (0x801ed24c) to the shared
// empty string; registers Active (0x801eb674); creates the Position vector
// binding (0x801f0210) reset to 0.0f; creates the Orientation vector binding
// (0x801f0210) reset to 0.0f; creates the GraphicalOrientation vector
// binding (0x801f0210) reset to 0.0f; creates the Scale vector binding
// (0x801f0210) reset to 0.0f; creates the Velocity vector binding
// (0x801f0210) reset to 0.0f; creates the LastCollisionNormal vector binding
// (0x801f0210) reset to 0.0f; registers LogicAnimState (0x801ebf38);
// registers SlopeAngle (0x801ec52c); registers WeaponIndex (0x801ece2c);
// registers WeaponAngle (0x801ec52c); registers WeaponFuse (0x801ebf38);
// registers WeaponIsBounceMax (0x801eb674); registers WeaponHerd
// (0x801ebf38); registers TeamIndex (0x801eb834); registers Energy
// (0x801ebbb8); registers Vital (0x801eb674); registers CPUFixedWeapon
// (0x801eb834); registers CPUActionRadius (0x801ebbb8); registers
// ArtillaryMode (0x801eb674); registers PoisonRate (0x801ebf38); registers
// PendingPoison (0x801ebf38); registers PlaceWormAtPosition (0x801eb674);
// registers DamagePending (0x801ec0f8); registers InitialEnergy
// (0x801ec0f8); registers CurrentEnergy (0x801ec0f8); resets the SfxBankName
// string binding (0x801ed24c) to the shared empty string; resets the Spawn
// string binding (0x801ed24c) to the shared empty string; registers
// IsAfterTouching (0x801eb674); creates the AfterTouchVector vector binding
// (0x801f0210) reset to 0.0f; registers IsParachuteSpawn (0x801eb674);
// registers IsAllowedToTakeTurn (0x801eb674); registers IsHatWearer
// (0x801eb674); registers GunWobblePitch (0x801ec52c); registers
// GunWobbleYaw (0x801ec52c); registers IsQuickWalking (0x801eb674);
// registers AllowBazooka (0x801eb9f8); registers AllowGrenade (0x801eb9f8);
// registers AllowClusterGrenade (0x801eb9f8); registers AllowAirstrike
// (0x801eb9f8); registers AllowDynamite (0x801eb9f8); registers
// AllowHolyHandGrenade (0x801eb9f8); registers AllowBananaBomb (0x801eb9f8);
// registers AllowLandmine (0x801eb9f8); registers AllowShotgun (0x801eb9f8);
// registers AllowUzi (0x801eb9f8); registers AllowBaseballBat (0x801eb9f8);
// registers AllowProd (0x801eb9f8); registers AllowVikingAxe (0x801eb9f8);
// registers AllowFirePunch (0x801eb9f8); registers AllowHomingMissile
// (0x801eb9f8); registers AllowMortar (0x801eb9f8); registers
// AllowHomingPidgeon (0x801eb9f8); registers AllowEarthquake (0x801eb9f8);
// registers AllowBlowpipe (0x801eb9f8); registers AllowSheep (0x801eb9f8);
// registers AllowMineStrike (0x801eb9f8); registers AllowPetrolBomb
// (0x801eb9f8); registers AllowGasCanister (0x801eb9f8); registers
// AllowSheepStrike (0x801eb9f8); registers AllowMadCow (0x801eb9f8);
// registers AllowOldWoman (0x801eb9f8); registers AllowConcreteDonkey
// (0x801eb9f8); registers AllowNuclearBomb (0x801eb9f8); registers
// AllowArmageddon (0x801eb9f8); registers AllowMagicBullet (0x801eb9f8);
// registers AllowSuperSheep (0x801eb9f8); registers AllowGirder
// (0x801eb9f8); registers AllowBridgeKit (0x801eb9f8); registers
// AllowNinjaRope (0x801eb9f8); registers AllowParachute (0x801eb9f8);
// registers AllowScalesOfJustice (0x801eb9f8); registers AllowLowGravity
// (0x801eb9f8); registers AllowQuickWalk (0x801eb9f8); registers
// AllowLaserSight (0x801eb9f8); registers AllowTeleport (0x801eb9f8);
// registers AllowJetpack (0x801eb9f8); registers AllowSkipGo (0x801eb9f8);
// registers AllowSurrender (0x801eb9f8); registers AllowChangeWorm
// (0x801eb9f8); registers AllowFreeze (0x801eb9f8); registers
// AllowLotteryStrike (0x801eb9f8); registers AllowDoctorsStrike
// (0x801eb9f8); registers AllowMegaMine (0x801eb9f8); registers
// AllowStickyBomb (0x801eb9f8); registers AllowBinoculars (0x801eb9f8);
// registers AllowRedbull (0x801eb9f8); registers TeleportIn (0x801eb674);
// registers IsEmotional (0x801eb674); registers HasDrunkRedbull
// (0x801eb674); then calls the refresh routine 0x801e8d9c and returns 0.
// Names are read from the descriptors' name pointers in the original data.
// Vector resets use the constant 0x803be7b8 (0.0f).
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
extern "C" void * fn_801eb9f8(void *, const void *);
extern "C" void * fn_801ebbb8(void *, const void *);
extern "C" void * fn_801ebf38(void *, const void *);
extern "C" void * fn_801ec0f8(void *, const void *);
extern "C" void * fn_801ece2c(void *, const void *);
extern const unsigned char desc_803bd42c[];  // Name
extern const unsigned char desc_803bd458[];  // Active
extern const unsigned char desc_803bd48c[];  // Position
extern const unsigned char desc_803bd4bc[];  // Orientation
extern const unsigned char desc_803bd4f8[];  // GraphicalOrientation
extern const unsigned char desc_803bd524[];  // Scale
extern const unsigned char desc_803bd554[];  // Velocity
extern const unsigned char desc_803bd58c[];  // LastCollisionNormal
extern const unsigned char desc_803bd5c0[];  // LogicAnimState
extern const unsigned char desc_803bd5f4[];  // SlopeAngle
extern const unsigned char desc_803bd628[];  // WeaponIndex
extern const unsigned char desc_803bd65c[];  // WeaponAngle
extern const unsigned char desc_803bd690[];  // WeaponFuse
extern const unsigned char desc_803bd6cc[];  // WeaponIsBounceMax
extern const unsigned char desc_803bd700[];  // WeaponHerd
extern const unsigned char desc_803bd734[];  // TeamIndex
extern const unsigned char desc_803bd764[];  // Energy
extern const unsigned char desc_803bd794[];  // Vital
extern const unsigned char desc_803bd7cc[];  // CPUFixedWeapon
extern const unsigned char desc_803bd804[];  // CPUActionRadius
extern const unsigned char desc_803bd83c[];  // ArtillaryMode
extern const unsigned char desc_803bd870[];  // PoisonRate
extern const unsigned char desc_803bd8a8[];  // PendingPoison
extern const unsigned char desc_803bd8e4[];  // PlaceWormAtPosition
extern const unsigned char desc_803bd91c[];  // DamagePending
extern const unsigned char desc_803bd954[];  // InitialEnergy
extern const unsigned char desc_803bd98c[];  // CurrentEnergy
extern const unsigned char desc_803bd9c0[];  // SfxBankName
extern const unsigned char desc_803bd9ec[];  // Spawn
extern const unsigned char desc_803bda20[];  // IsAfterTouching
extern const unsigned char desc_803bda5c[];  // AfterTouchVector
extern const unsigned char desc_803bda94[];  // IsParachuteSpawn
extern const unsigned char desc_803bdad0[];  // IsAllowedToTakeTurn
extern const unsigned char desc_803bdb04[];  // IsHatWearer
extern const unsigned char desc_803bdb3c[];  // GunWobblePitch
extern const unsigned char desc_803bdb74[];  // GunWobbleYaw
extern const unsigned char desc_803bdbac[];  // IsQuickWalking
extern const unsigned char desc_803bdbe4[];  // AllowBazooka
extern const unsigned char desc_803bdc1c[];  // AllowGrenade
extern const unsigned char desc_803bdc58[];  // AllowClusterGrenade
extern const unsigned char desc_803bdc90[];  // AllowAirstrike
extern const unsigned char desc_803bdcc8[];  // AllowDynamite
extern const unsigned char desc_803bdd08[];  // AllowHolyHandGrenade
extern const unsigned char desc_803bdd40[];  // AllowBananaBomb
extern const unsigned char desc_803bdd78[];  // AllowLandmine
extern const unsigned char desc_803bddb0[];  // AllowShotgun
extern const unsigned char desc_803bdde4[];  // AllowUzi
extern const unsigned char desc_803bde20[];  // AllowBaseballBat
extern const unsigned char desc_803bde54[];  // AllowProd
extern const unsigned char desc_803bde8c[];  // AllowVikingAxe
extern const unsigned char desc_803bdec4[];  // AllowFirePunch
extern const unsigned char desc_803bdf00[];  // AllowHomingMissile
extern const unsigned char desc_803bdf34[];  // AllowMortar
extern const unsigned char desc_803bdf70[];  // AllowHomingPidgeon
extern const unsigned char desc_803bdfa8[];  // AllowEarthquake
extern const unsigned char desc_803bdfe0[];  // AllowBlowpipe
extern const unsigned char desc_803be014[];  // AllowSheep
extern const unsigned char desc_803be04c[];  // AllowMineStrike
extern const unsigned char desc_803be084[];  // AllowPetrolBomb
extern const unsigned char desc_803be0c0[];  // AllowGasCanister
extern const unsigned char desc_803be0fc[];  // AllowSheepStrike
extern const unsigned char desc_803be130[];  // AllowMadCow
extern const unsigned char desc_803be168[];  // AllowOldWoman
extern const unsigned char desc_803be1a4[];  // AllowConcreteDonkey
extern const unsigned char desc_803be1e0[];  // AllowNuclearBomb
extern const unsigned char desc_803be218[];  // AllowArmageddon
extern const unsigned char desc_803be254[];  // AllowMagicBullet
extern const unsigned char desc_803be28c[];  // AllowSuperSheep
extern const unsigned char desc_803be2c0[];  // AllowGirder
extern const unsigned char desc_803be2f8[];  // AllowBridgeKit
extern const unsigned char desc_803be330[];  // AllowNinjaRope
extern const unsigned char desc_803be368[];  // AllowParachute
extern const unsigned char desc_803be3a8[];  // AllowScalesOfJustice
extern const unsigned char desc_803be3e0[];  // AllowLowGravity
extern const unsigned char desc_803be418[];  // AllowQuickWalk
extern const unsigned char desc_803be450[];  // AllowLaserSight
extern const unsigned char desc_803be488[];  // AllowTeleport
extern const unsigned char desc_803be4c0[];  // AllowJetpack
extern const unsigned char desc_803be4f4[];  // AllowSkipGo
extern const unsigned char desc_803be52c[];  // AllowSurrender
extern const unsigned char desc_803be564[];  // AllowChangeWorm
extern const unsigned char desc_803be598[];  // AllowFreeze
extern const unsigned char desc_803be5d4[];  // AllowLotteryStrike
extern const unsigned char desc_803be610[];  // AllowDoctorsStrike
extern const unsigned char desc_803be648[];  // AllowMegaMine
extern const unsigned char desc_803be680[];  // AllowStickyBomb
extern const unsigned char desc_803be6b8[];  // AllowBinoculars
extern const unsigned char desc_803be6f0[];  // AllowRedbull
extern const unsigned char desc_803be724[];  // TeleportIn
extern const unsigned char desc_803be758[];  // IsEmotional
extern const unsigned char desc_803be790[];  // HasDrunkRedbull
extern float constant_803be7b8[];
extern "C" int w3d_d21e_register_object_properties_80241edc(void *owner) {
    fn_801ed24c(owner, desc_803bd42c)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801eb674(owner, desc_803bd458);
    VectorBinding *v1 = fn_801f0210(owner, desc_803bd48c);
    float zero = constant_803be7b8[0];
    Vec3 t1;
    Vec3 *p1 = &t1;
    p1->x = zero;
    p1->y = zero;
    p1->z = zero;
    v1->set(t1);
    VectorBinding *v2 = fn_801f0210(owner, desc_803bd4bc);
    Vec3 t2;
    Vec3 *p2 = &t2;
    p2->x = zero;
    p2->y = zero;
    p2->z = zero;
    v2->set(t2);
    VectorBinding *v3 = fn_801f0210(owner, desc_803bd4f8);
    Vec3 t3;
    Vec3 *p3 = &t3;
    p3->x = zero;
    p3->y = zero;
    p3->z = zero;
    v3->set(t3);
    VectorBinding *v4 = fn_801f0210(owner, desc_803bd524);
    Vec3 t4;
    Vec3 *p4 = &t4;
    p4->x = zero;
    p4->y = zero;
    p4->z = zero;
    v4->set(t4);
    VectorBinding *v5 = fn_801f0210(owner, desc_803bd554);
    Vec3 t5;
    Vec3 *p5 = &t5;
    p5->x = zero;
    p5->y = zero;
    p5->z = zero;
    v5->set(t5);
    VectorBinding *v6 = fn_801f0210(owner, desc_803bd58c);
    Vec3 t6;
    Vec3 *p6 = &t6;
    p6->x = zero;
    p6->y = zero;
    p6->z = zero;
    v6->set(t6);
    fn_801ebf38(owner, desc_803bd5c0);
    fn_801ec52c(owner, desc_803bd5f4);
    fn_801ece2c(owner, desc_803bd628);
    fn_801ec52c(owner, desc_803bd65c);
    fn_801ebf38(owner, desc_803bd690);
    fn_801eb674(owner, desc_803bd6cc);
    fn_801ebf38(owner, desc_803bd700);
    fn_801eb834(owner, desc_803bd734);
    fn_801ebbb8(owner, desc_803bd764);
    fn_801eb674(owner, desc_803bd794);
    fn_801eb834(owner, desc_803bd7cc);
    fn_801ebbb8(owner, desc_803bd804);
    fn_801eb674(owner, desc_803bd83c);
    fn_801ebf38(owner, desc_803bd870);
    fn_801ebf38(owner, desc_803bd8a8);
    fn_801eb674(owner, desc_803bd8e4);
    fn_801ec0f8(owner, desc_803bd91c);
    fn_801ec0f8(owner, desc_803bd954);
    fn_801ec0f8(owner, desc_803bd98c);
    fn_801ed24c(owner, desc_803bd9c0)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803bd9ec)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801eb674(owner, desc_803bda20);
    VectorBinding *v7 = fn_801f0210(owner, desc_803bda5c);
    Vec3 t7;
    Vec3 *p7 = &t7;
    p7->x = zero;
    p7->y = zero;
    p7->z = zero;
    v7->set(t7);
    fn_801eb674(owner, desc_803bda94);
    fn_801eb674(owner, desc_803bdad0);
    fn_801eb674(owner, desc_803bdb04);
    fn_801ec52c(owner, desc_803bdb3c);
    fn_801ec52c(owner, desc_803bdb74);
    fn_801eb674(owner, desc_803bdbac);
    fn_801eb9f8(owner, desc_803bdbe4);
    fn_801eb9f8(owner, desc_803bdc1c);
    fn_801eb9f8(owner, desc_803bdc58);
    fn_801eb9f8(owner, desc_803bdc90);
    fn_801eb9f8(owner, desc_803bdcc8);
    fn_801eb9f8(owner, desc_803bdd08);
    fn_801eb9f8(owner, desc_803bdd40);
    fn_801eb9f8(owner, desc_803bdd78);
    fn_801eb9f8(owner, desc_803bddb0);
    fn_801eb9f8(owner, desc_803bdde4);
    fn_801eb9f8(owner, desc_803bde20);
    fn_801eb9f8(owner, desc_803bde54);
    fn_801eb9f8(owner, desc_803bde8c);
    fn_801eb9f8(owner, desc_803bdec4);
    fn_801eb9f8(owner, desc_803bdf00);
    fn_801eb9f8(owner, desc_803bdf34);
    fn_801eb9f8(owner, desc_803bdf70);
    fn_801eb9f8(owner, desc_803bdfa8);
    fn_801eb9f8(owner, desc_803bdfe0);
    fn_801eb9f8(owner, desc_803be014);
    fn_801eb9f8(owner, desc_803be04c);
    fn_801eb9f8(owner, desc_803be084);
    fn_801eb9f8(owner, desc_803be0c0);
    fn_801eb9f8(owner, desc_803be0fc);
    fn_801eb9f8(owner, desc_803be130);
    fn_801eb9f8(owner, desc_803be168);
    fn_801eb9f8(owner, desc_803be1a4);
    fn_801eb9f8(owner, desc_803be1e0);
    fn_801eb9f8(owner, desc_803be218);
    fn_801eb9f8(owner, desc_803be254);
    fn_801eb9f8(owner, desc_803be28c);
    fn_801eb9f8(owner, desc_803be2c0);
    fn_801eb9f8(owner, desc_803be2f8);
    fn_801eb9f8(owner, desc_803be330);
    fn_801eb9f8(owner, desc_803be368);
    fn_801eb9f8(owner, desc_803be3a8);
    fn_801eb9f8(owner, desc_803be3e0);
    fn_801eb9f8(owner, desc_803be418);
    fn_801eb9f8(owner, desc_803be450);
    fn_801eb9f8(owner, desc_803be488);
    fn_801eb9f8(owner, desc_803be4c0);
    fn_801eb9f8(owner, desc_803be4f4);
    fn_801eb9f8(owner, desc_803be52c);
    fn_801eb9f8(owner, desc_803be564);
    fn_801eb9f8(owner, desc_803be598);
    fn_801eb9f8(owner, desc_803be5d4);
    fn_801eb9f8(owner, desc_803be610);
    fn_801eb9f8(owner, desc_803be648);
    fn_801eb9f8(owner, desc_803be680);
    fn_801eb9f8(owner, desc_803be6b8);
    fn_801eb9f8(owner, desc_803be6f0);
    fn_801eb674(owner, desc_803be724);
    fn_801eb674(owner, desc_803be758);
    fn_801eb674(owner, desc_803be790);
    fn_801e8d9c(owner);
    return 0;
}
