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
inline void *operator new(unsigned, void *place) { return place; }

struct W3dCostBase_80006360 {
    int unknown0;
    float distance;
    int state;
    virtual void dispatch(); // structural declaration; original slot external
    W3dCostBase_80006360();
};

struct W3dPathPlan : W3dCostBase_80006360 {
    int selected;       // +16, initial -1
    float x, y, z;      // +20..31, position observed in related methods
    void *path;         // +32, released by the intermediate destructor
    int active;         // +36, initial 1; meaning inferred
    int flag;           // +40, initial 0; meaning inferred
    virtual void dispatch();
    W3dPathPlan() : selected(-1), path(0), active(1), flag(0) {}
};

struct W3dCollectCrate : W3dPathPlan {
    void *crate;        // +44, related scoring code inspects this object
    float weight;       // +48, used as a score multiplier
    virtual void dispatch();
    W3dCollectCrate(const W3dCollectCrate &other) { *this = other; }
};

typedef char CostBaseFootprint[(sizeof(W3dCostBase_80006360) == 16) ? 1 : -1];
typedef char PathPlanFootprint[(sizeof(W3dPathPlan) == 44) ? 1 : -1];
typedef char CollectCrateFootprint[(sizeof(W3dCollectCrate) == 52) ? 1 : -1];

extern "C" W3dCollectCrate *w3d_collect_crate_copy_80017e28(
    void *storage, const W3dCollectCrate *other)
{
    return new (storage) W3dCollectCrate(*other);
}
