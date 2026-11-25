#include "w3d_ptr.h"
#line 1 "d26j_transform_setters_80185ba4.cpp"
// Transform setters of a scene node with no owned space, GWMP8P rev0
// 0x80185ba4, 0x80185f10, 0x80186254. Same template as the setters at
// 0x8017a2b0 without the validity test, the space pointer (0x801a3eb0 receives
// null) and the per-target source objects: an unchanged value returns 0 unless
// forced; otherwise the value is stored and a node that is not local and has
// no targets ends in a plain virtual setter. Else the world frame is built
// from rotation, scale and translation and passed to virtual slot +148, a
// frame for the targets is rebuilt from the components the flags byte selects
// unless it is 7, and every target gets the frame and a change notification.
// The unread Vec3 copies in the translation and scale setters are witnessed by
// the original, which writes all three floats to sp+8 and never reads them.
// The zero literals are the pool words 0x803a7aa4, 0x803a7aa8 and 0x803a7aac.

struct Vec3 {
    float x, y, z;
    Vec3();
    Vec3(const Vec3 &o) { x = o.x; y = o.y; z = o.z; }
    bool operator==(const Vec3 &o) const
    {
        return *(Ptr32<const int>)&x == *(Ptr32<const int>)&o.x
            && *(Ptr32<const int>)&y == *(Ptr32<const int>)&o.y
            && *(Ptr32<const int>)&z == *(Ptr32<const int>)&o.z;
    }
};

struct Frame {
    float r[9];
    Vec3 t;
    void set(const Vec3 &v) { t = v; }
    void zero(float v) { t.x = v; t.y = v; t.z = v; }
};

extern "C" void fn_801a3eb0(Ptr32<const Vec3> rotation, int space, Ptr32<Frame> out);
extern "C" void fn_801f6448(Ptr32<Frame> frame, float x, float y, float z);
extern "C" void fn_801f6034(Ptr32<Frame> frame);
extern "C" void fn_801f740c(Ptr32<Frame> out, Ptr32<const Frame> a, Ptr32<const Frame> b);
extern float float_803a7aa4[];
extern float float_803a7aa8[];
extern float float_803a7aac[];

struct World;

struct Target {
    void w3d_r_slot_8() __asm__(W3D_SYM("_ZN6Target6slot_8Ev"));
    void w3d_r_slot_12() __asm__(W3D_SYM("_ZN6Target7slot_12Ev"));
    void w3d_r_slot_16() __asm__(W3D_SYM("_ZN6Target7slot_16Ev"));
    void w3d_r_slot_20() __asm__(W3D_SYM("_ZN6Target7slot_20Ev"));
    void w3d_r_slot_24() __asm__(W3D_SYM("_ZN6Target7slot_24Ev"));
    void w3d_r_slot_28() __asm__(W3D_SYM("_ZN6Target7slot_28Ev"));
    void w3d_r_slot_32() __asm__(W3D_SYM("_ZN6Target7slot_32Ev"));
    void w3d_r_slot_36() __asm__(W3D_SYM("_ZN6Target7slot_36Ev"));
    void w3d_r_slot_40() __asm__(W3D_SYM("_ZN6Target7slot_40Ev"));
    void w3d_r_slot_44() __asm__(W3D_SYM("_ZN6Target7slot_44Ev"));
    void w3d_r_slot_48() __asm__(W3D_SYM("_ZN6Target7slot_48Ev"));
    void w3d_r_slot_52() __asm__(W3D_SYM("_ZN6Target7slot_52Ev"));
    void w3d_r_slot_56() __asm__(W3D_SYM("_ZN6Target7slot_56Ev"));
    void w3d_r_slot_60() __asm__(W3D_SYM("_ZN6Target7slot_60Ev"));
    void w3d_r_slot_64() __asm__(W3D_SYM("_ZN6Target7slot_64Ev"));
    void w3d_r_slot_68() __asm__(W3D_SYM("_ZN6Target7slot_68Ev"));
    void w3d_r_slot_72() __asm__(W3D_SYM("_ZN6Target7slot_72Ev"));
    void w3d_r_changed_translation(int a, int b) __asm__(W3D_SYM("_ZN6Target19changed_translationEii"));
    void w3d_r_changed_rotation(int a, int b) __asm__(W3D_SYM("_ZN6Target16changed_rotationEii"));
    void w3d_r_changed_scale(int a, int b) __asm__(W3D_SYM("_ZN6Target13changed_scaleEii"));
    void w3d_r_slot_88() __asm__(W3D_SYM("_ZN6Target7slot_88Ev"));
    void w3d_r_slot_92() __asm__(W3D_SYM("_ZN6Target7slot_92Ev"));
    void w3d_r_slot_96() __asm__(W3D_SYM("_ZN6Target7slot_96Ev"));
    int w3d_r_translation_key() __asm__(W3D_SYM("_ZN6Target15translation_keyEv"));
    int w3d_r_rotation_key() __asm__(W3D_SYM("_ZN6Target12rotation_keyEv"));
    int w3d_r_scale_key() __asm__(W3D_SYM("_ZN6Target9scale_keyEv"));
    void w3d_r_slot_112() __asm__(W3D_SYM("_ZN6Target8slot_112Ev"));
    void w3d_r_slot_116() __asm__(W3D_SYM("_ZN6Target8slot_116Ev"));
    void w3d_r_slot_120() __asm__(W3D_SYM("_ZN6Target8slot_120Ev"));
    void w3d_r_slot_124() __asm__(W3D_SYM("_ZN6Target8slot_124Ev"));
    void w3d_r_update(Ptr32<const void> m) __asm__(W3D_SYM("_ZN6Target6updateEPKv"));
 __attribute__((always_inline)) inline void slot_8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_32() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_36() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_40() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_44() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_48() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_52() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_56() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_60() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_64() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_68() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_72() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void changed_translation(int w3d_a0, int w3d_a1) { ((void (*)(w3d_u32, int, int))w3d::vfn(this->w3d_vptr_Target, 19))(w3d::h2g(this), w3d_a0, w3d_a1); }  __attribute__((always_inline)) inline void changed_rotation(int w3d_a0, int w3d_a1) { ((void (*)(w3d_u32, int, int))w3d::vfn(this->w3d_vptr_Target, 20))(w3d::h2g(this), w3d_a0, w3d_a1); }  __attribute__((always_inline)) inline void changed_scale(int w3d_a0, int w3d_a1) { ((void (*)(w3d_u32, int, int))w3d::vfn(this->w3d_vptr_Target, 21))(w3d::h2g(this), w3d_a0, w3d_a1); }  __attribute__((always_inline)) inline void slot_88() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 22))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_92() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 23))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_96() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 24))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int translation_key() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 25))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int rotation_key() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 26))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int scale_key() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 27))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_112() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 28))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_116() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 29))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_120() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 30))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_124() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 31))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void update(Ptr32<const void> w3d_a0) { ((void (*)(w3d_u32, Ptr32<const void>))w3d::vfn(this->w3d_vptr_Target, 32))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_Target; };

struct Maker {
    void w3d_r_slot_8() __asm__(W3D_SYM("_ZN5Maker6slot_8Ev"));
    void w3d_r_slot_12() __asm__(W3D_SYM("_ZN5Maker7slot_12Ev"));
    void w3d_r_slot_16() __asm__(W3D_SYM("_ZN5Maker7slot_16Ev"));
    void w3d_r_slot_20() __asm__(W3D_SYM("_ZN5Maker7slot_20Ev"));
    void w3d_r_slot_24() __asm__(W3D_SYM("_ZN5Maker7slot_24Ev"));
    void w3d_r_slot_28() __asm__(W3D_SYM("_ZN5Maker7slot_28Ev"));
    void w3d_r_slot_32() __asm__(W3D_SYM("_ZN5Maker7slot_32Ev"));
    void w3d_r_slot_36() __asm__(W3D_SYM("_ZN5Maker7slot_36Ev"));
    void w3d_r_slot_40() __asm__(W3D_SYM("_ZN5Maker7slot_40Ev"));
    void w3d_r_slot_44() __asm__(W3D_SYM("_ZN5Maker7slot_44Ev"));
    void w3d_r_slot_48() __asm__(W3D_SYM("_ZN5Maker7slot_48Ev"));
    void w3d_r_slot_52() __asm__(W3D_SYM("_ZN5Maker7slot_52Ev"));
    void w3d_r_slot_56() __asm__(W3D_SYM("_ZN5Maker7slot_56Ev"));
    void w3d_r_slot_60() __asm__(W3D_SYM("_ZN5Maker7slot_60Ev"));
    void w3d_r_slot_64() __asm__(W3D_SYM("_ZN5Maker7slot_64Ev"));
    void w3d_r_slot_68() __asm__(W3D_SYM("_ZN5Maker7slot_68Ev"));
    void w3d_r_slot_72() __asm__(W3D_SYM("_ZN5Maker7slot_72Ev"));
    void w3d_r_make(Ptr32<void> a, Ptr32<World> w, Ptr32<Ptr32<void>> out) __asm__(W3D_SYM("_ZN5Maker4makeEPvP5WorldPS0_"));
 __attribute__((always_inline)) inline void slot_8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_32() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_36() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_40() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_44() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_48() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_52() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_56() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_60() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_64() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_68() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_72() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void make(Ptr32<void> w3d_a0, Ptr32<World> w3d_a1, Ptr32<Ptr32<void>> w3d_a2) { ((void (*)(w3d_u32, Ptr32<void>, Ptr32<World>, Ptr32<Ptr32<void>>))w3d::vfn(this->w3d_vptr_Maker, 19))(w3d::h2g(this), w3d_a0, w3d_a1, w3d_a2); }  Ptr32<void> w3d_vptr_Maker; };

struct Inner { char u[108]; Ptr32<void> space; };
struct World { char u[48]; Ptr32<Inner> inner; };

struct Targets {
    Ptr32<Ptr32<Target>> start; Ptr32<Ptr32<Target>> finish; Ptr32<Ptr32<Target>> cap;
    unsigned size() const { return finish - start; }
    Ptr32<Ptr32<Target>> end() { return finish; }
};

struct Makers { int a, b; Ptr32<Ptr32<Maker>> data; };
struct Sources { int a, b; Ptr32<Ptr32<void>> data; };

struct NodeBase {
    void w3d_r_slot_8() __asm__(W3D_SYM("_ZN8NodeBase6slot_8Ev"));
    void w3d_r_slot_12() __asm__(W3D_SYM("_ZN8NodeBase7slot_12Ev"));
    void w3d_r_slot_16() __asm__(W3D_SYM("_ZN8NodeBase7slot_16Ev"));
    void w3d_r_slot_20() __asm__(W3D_SYM("_ZN8NodeBase7slot_20Ev"));
    void w3d_r_slot_24() __asm__(W3D_SYM("_ZN8NodeBase7slot_24Ev"));
    int w3d_r_is_local() __asm__(W3D_SYM("_ZN8NodeBase8is_localEv"));
    void w3d_r_slot_32() __asm__(W3D_SYM("_ZN8NodeBase7slot_32Ev"));
    void w3d_r_slot_36() __asm__(W3D_SYM("_ZN8NodeBase7slot_36Ev"));
    void w3d_r_slot_40() __asm__(W3D_SYM("_ZN8NodeBase7slot_40Ev"));
    void w3d_r_slot_44() __asm__(W3D_SYM("_ZN8NodeBase7slot_44Ev"));
    void w3d_r_slot_48() __asm__(W3D_SYM("_ZN8NodeBase7slot_48Ev"));
    void w3d_r_slot_52() __asm__(W3D_SYM("_ZN8NodeBase7slot_52Ev"));
    void w3d_r_slot_56() __asm__(W3D_SYM("_ZN8NodeBase7slot_56Ev"));
    void w3d_r_slot_60() __asm__(W3D_SYM("_ZN8NodeBase7slot_60Ev"));
    void w3d_r_slot_64() __asm__(W3D_SYM("_ZN8NodeBase7slot_64Ev"));
    void w3d_r_slot_68() __asm__(W3D_SYM("_ZN8NodeBase7slot_68Ev"));
    void w3d_r_slot_72() __asm__(W3D_SYM("_ZN8NodeBase7slot_72Ev"));
    void w3d_r_slot_76() __asm__(W3D_SYM("_ZN8NodeBase7slot_76Ev"));
    void w3d_r_slot_80() __asm__(W3D_SYM("_ZN8NodeBase7slot_80Ev"));
    void w3d_r_slot_84() __asm__(W3D_SYM("_ZN8NodeBase7slot_84Ev"));
    void w3d_r_slot_88() __asm__(W3D_SYM("_ZN8NodeBase7slot_88Ev"));
    void w3d_r_slot_92() __asm__(W3D_SYM("_ZN8NodeBase7slot_92Ev"));
    void w3d_r_slot_96() __asm__(W3D_SYM("_ZN8NodeBase7slot_96Ev"));
    void w3d_r_slot_100() __asm__(W3D_SYM("_ZN8NodeBase8slot_100Ev"));
    void w3d_r_slot_104() __asm__(W3D_SYM("_ZN8NodeBase8slot_104Ev"));
    void w3d_r_slot_108() __asm__(W3D_SYM("_ZN8NodeBase8slot_108Ev"));
    void w3d_r_slot_112() __asm__(W3D_SYM("_ZN8NodeBase8slot_112Ev"));
    void w3d_r_slot_116() __asm__(W3D_SYM("_ZN8NodeBase8slot_116Ev"));
    void w3d_r_slot_120() __asm__(W3D_SYM("_ZN8NodeBase8slot_120Ev"));
    void w3d_r_slot_124() __asm__(W3D_SYM("_ZN8NodeBase8slot_124Ev"));
    void w3d_r_slot_128() __asm__(W3D_SYM("_ZN8NodeBase8slot_128Ev"));
    void w3d_r_slot_132() __asm__(W3D_SYM("_ZN8NodeBase8slot_132Ev"));
    void w3d_r_slot_136() __asm__(W3D_SYM("_ZN8NodeBase8slot_136Ev"));
    int w3d_r_plain_translation(Ptr32<const Vec3>) __asm__(W3D_SYM("_ZN8NodeBase17plain_translationEPK4Vec3"));
    int w3d_r_plain_rotation(Ptr32<const Vec3>) __asm__(W3D_SYM("_ZN8NodeBase14plain_rotationEPK4Vec3"));
    int w3d_r_world_frame(Ptr32<const Frame>) __asm__(W3D_SYM("_ZN8NodeBase11world_frameEPK5Frame"));
    int w3d_r_plain_scale(Ptr32<const Vec3>) __asm__(W3D_SYM("_ZN8NodeBase11plain_scaleEPK4Vec3"));
 __attribute__((always_inline)) inline void slot_8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeBase, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeBase, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeBase, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeBase, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeBase, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int is_local() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeBase, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_32() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeBase, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_36() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeBase, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_40() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeBase, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_44() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeBase, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_48() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeBase, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_52() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeBase, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_56() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeBase, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_60() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeBase, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_64() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeBase, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_68() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeBase, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_72() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeBase, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_76() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeBase, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_80() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeBase, 20))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_84() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeBase, 21))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_88() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeBase, 22))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_92() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeBase, 23))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_96() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeBase, 24))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_100() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeBase, 25))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_104() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeBase, 26))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_108() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeBase, 27))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_112() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeBase, 28))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_116() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeBase, 29))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_120() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeBase, 30))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_124() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeBase, 31))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_128() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeBase, 32))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_132() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeBase, 33))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_136() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeBase, 34))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int plain_translation(Ptr32<const Vec3> w3d_a0) { return ((int (*)(w3d_u32, Ptr32<const Vec3>))w3d::vfn(this->w3d_vptr_NodeBase, 35))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline int plain_rotation(Ptr32<const Vec3> w3d_a0) { return ((int (*)(w3d_u32, Ptr32<const Vec3>))w3d::vfn(this->w3d_vptr_NodeBase, 36))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline int world_frame(Ptr32<const Frame> w3d_a0) { return ((int (*)(w3d_u32, Ptr32<const Frame>))w3d::vfn(this->w3d_vptr_NodeBase, 37))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline int plain_scale(Ptr32<const Vec3> w3d_a0) { return ((int (*)(w3d_u32, Ptr32<const Vec3>))w3d::vfn(this->w3d_vptr_NodeBase, 38))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_NodeBase; };

struct Node : NodeBase {
    char u4[8] __attribute__((aligned(__alignof__(NodeBase))));
    Vec3 translation;
    Vec3 rotation;
    Vec3 scale;
    char u48[4];
    unsigned char flags;
    char u53[3];
    Frame local_frame;
    Targets kids;
    char u116[4];
    Ptr32<World> world;
    char u124[4];
    Makers makers;
    Sources sources;
    char u152[12];
    int valid;
};

extern "C" int d26j_set_translation_80185ba4(Ptr32<Node> self, Ptr32<const Vec3> k, int force)
{
    if (!force && self->translation == *k) return 0;
    self->translation = *k;
    Ptr32<Targets> kids = &self->kids;
    if (!self->is_local() && kids->size() == 0)
        return self->plain_translation(&self->translation);
    Vec3 old(self->translation);
    Frame b;
    Frame a;
    Ptr32<Frame> pa = &a;
    fn_801a3eb0(&self->rotation, 0, pa);
    fn_801f6448(pa, self->scale.x, self->scale.y, self->scale.z);
    a.set(self->translation);
    int result;
    if (self->is_local()) {
        fn_801f740c(&b, &a, &self->local_frame);
        result = self->world_frame(&b);
    } else {
        b = a;
        result = self->world_frame(&a);
    }
    if (self->flags != 7) {
        if (self->flags & 2) fn_801a3eb0(&self->rotation, 0, pa);
        else fn_801f6034(pa);
        if (self->flags & 4) fn_801f6448(pa, self->scale.x, self->scale.y, self->scale.z);
        if ((self->flags ^ 1) & 1) {
            float zero = float_803a7aa4[0];
            Ptr32<Frame> q = &a;
            q->zero(zero);
        }
        if (self->is_local()) fn_801f740c(&b, &a, &self->local_frame);
        else b = a;
    }
    Ptr32<Ptr32<Target>> it = self->kids.start;
    Ptr32<Ptr32<Target>> end = kids->end();
    for (; it != end; ++it) {
        (*it)->update(&b);
        Ptr32<Target> t = *it;
        t->changed_translation(t->translation_key(), 1);
    }
    return result;
}

extern "C" int d26j_set_rotation_80185f10(Ptr32<Node> self, Ptr32<const Vec3> k, int force)
{
    if (!force && self->rotation == *k) return 0;
    self->rotation = *k;
    Ptr32<Targets> kids = &self->kids;
    if (!self->is_local() && kids->size() == 0)
        return self->plain_rotation(&self->rotation);
    Frame b;
    Frame a;
    Ptr32<Frame> pa = &a;
    fn_801a3eb0(&self->rotation, 0, pa);
    fn_801f6448(pa, self->scale.x, self->scale.y, self->scale.z);
    a.set(self->translation);
    int result;
    if (self->is_local()) {
        fn_801f740c(&b, &a, &self->local_frame);
        result = self->world_frame(&b);
    } else {
        b = a;
        result = self->world_frame(&a);
    }
    if (self->flags != 7) {
        if (self->flags & 2) fn_801a3eb0(&self->rotation, 0, pa);
        else fn_801f6034(pa);
        if (self->flags & 4) fn_801f6448(pa, self->scale.x, self->scale.y, self->scale.z);
        if ((self->flags ^ 1) & 1) {
            float zero = float_803a7aa8[0];
            Ptr32<Frame> q = &a;
            q->zero(zero);
        }
        if (self->is_local()) fn_801f740c(&b, &a, &self->local_frame);
        else b = a;
    }
    Ptr32<Ptr32<Target>> it = self->kids.start;
    Ptr32<Ptr32<Target>> end = kids->end();
    for (; it != end; ++it) {
        (*it)->update(&b);
        Ptr32<Target> t = *it;
        t->changed_rotation(t->rotation_key(), 1);
    }
    return result;
}

extern "C" int d26j_set_scale_80186254(Ptr32<Node> self, Ptr32<const Vec3> k, int force)
{
    if (!force && self->scale == *k) return 0;
    self->scale = *k;
    Ptr32<Targets> kids = &self->kids;
    if (!self->is_local() && kids->size() == 0)
        return self->plain_scale(&self->scale);
    Vec3 old(self->scale);
    Frame b;
    Frame a;
    Ptr32<Frame> pa = &a;
    fn_801a3eb0(&self->rotation, 0, pa);
    fn_801f6448(pa, self->scale.x, self->scale.y, self->scale.z);
    a.set(self->translation);
    int result;
    if (self->is_local()) {
        fn_801f740c(&b, &a, &self->local_frame);
        result = self->world_frame(&b);
    } else {
        b = a;
        result = self->world_frame(&a);
    }
    if (self->flags != 7) {
        if (self->flags & 2) fn_801a3eb0(&self->rotation, 0, pa);
        else fn_801f6034(pa);
        if (self->flags & 4) fn_801f6448(pa, self->scale.x, self->scale.y, self->scale.z);
        if ((self->flags ^ 1) & 1) {
            float zero = float_803a7aac[0];
            Ptr32<Frame> q = &a;
            q->zero(zero);
        }
        if (self->is_local()) fn_801f740c(&b, &a, &self->local_frame);
        else b = a;
    }
    Ptr32<Ptr32<Target>> it = self->kids.start;
    Ptr32<Ptr32<Target>> end = kids->end();
    for (; it != end; ++it) {
        (*it)->update(&b);
        Ptr32<Target> t = *it;
        t->changed_scale(t->scale_key(), 1);
    }
    return result;
}


