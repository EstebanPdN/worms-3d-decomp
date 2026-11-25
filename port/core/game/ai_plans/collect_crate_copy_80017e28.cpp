#include "w3d_ptr.h"
#line 1 "collect_crate_copy_80017e28.cpp"
// Native CollectCrate plan copy at 0x80017e28. The name is supported by the
// related name getter; field meanings remain inferred where noted.
//
// Original 0x803428dc delegates destruction to the intermediate path owner at
// 0x80017304, which installs table 0x8040d990 and releases the pointer at +32.
// The final type uses table 0x8040d958. This is a real intermediate base, not
// a synthetic owner introduced to force store order. Its constructor inlines
// before the derived vptr installation. The reference compiler merges the
// overwritten intermediate table store and preserves the original vptr around
// the generated memberwise assignment.
//
// These are GC32 external lifetime/layout views. Actual virtual slots and
// destructors are defined elsewhere; this unit recovers only construction.
inline void *operator new(__SIZE_TYPE__, void *place) { return place; }

struct W3dCostBase_80006360 {
    int unknown0;
    float distance;
    int state;
    void w3d_r_dispatch() __asm__(W3D_SYM("_ZN20W3dCostBase_800063608dispatchEv")); // structural declaration; original slot external
    W3dCostBase_80006360();
 __attribute__((always_inline)) inline void dispatch() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_W3dCostBase_80006360, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_W3dCostBase_80006360; };

struct W3dPathPlan : W3dCostBase_80006360 {
    int selected __attribute__((aligned(__alignof__(W3dCostBase_80006360))));       // +16, initial -1
    float x, y, z;      // +20..31, position observed in related methods
    Ptr32<void> path;         // +32, released by the intermediate destructor
    int active;         // +36, initial 1; meaning inferred
    int flag;           // +40, initial 0; meaning inferred
    void w3d_r_dispatch() __asm__(W3D_SYM("_ZN11W3dPathPlan8dispatchEv"));
    W3dPathPlan() : selected(-1), path(0), active(1), flag(0) { W3D_SET_VPTR(this->W3dCostBase_80006360::w3d_vptr_W3dCostBase_80006360, w3d_vt___vt_11W3dPathPlan, "__vt_11W3dPathPlan"); }
 __attribute__((always_inline)) inline void dispatch() { this->W3dCostBase_80006360::dispatch(); } };

struct W3dCollectCrate : W3dPathPlan {
    Ptr32<void> crate __attribute__((aligned(__alignof__(W3dPathPlan))));        // +44, related scoring code inspects this object
    float weight;       // +48, used as a score multiplier
    void w3d_r_dispatch() __asm__(W3D_SYM("_ZN15W3dCollectCrate8dispatchEv"));
    W3dCollectCrate(const W3dCollectCrate &other) { W3D_SET_VPTR(this->W3dPathPlan::w3d_vptr_W3dCostBase_80006360, w3d_vt___vt_15W3dCollectCrate, "__vt_15W3dCollectCrate");  *this = other; }
 __attribute__((always_inline)) inline void dispatch() { this->W3dPathPlan::dispatch(); } };

typedef char CostBaseFootprint[(sizeof(W3dCostBase_80006360) == 16) ? 1 : -1];
typedef char PathPlanFootprint[(sizeof(W3dPathPlan) == 44) ? 1 : -1];
typedef char CollectCrateFootprint[(sizeof(W3dCollectCrate) == 52) ? 1 : -1];

extern "C" Ptr32<W3dCollectCrate> w3d_collect_crate_copy_80017e28(
    Ptr32<void> storage, Ptr32<const W3dCollectCrate> other)
{
    return new (storage) W3dCollectCrate(*other);
}


