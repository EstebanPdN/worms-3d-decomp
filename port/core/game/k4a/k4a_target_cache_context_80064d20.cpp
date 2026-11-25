#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4a_target_cache_context_80064d20.c"
typedef struct K4aPropPair { int first; int second; } K4aPropPair;
typedef struct K4aContext { char pad0[52]; int value; } K4aContext;
typedef struct K4aTarget { char pad0[36]; Ptr32<void> holder_ref; char pad1[8]; int key; char pad2[48]; int cached; } K4aTarget;
extern void FUN_80064384(Ptr32<void> target, int key);
extern Ptr32<void> w3d_empty_80343580(Ptr32<void>);
extern Ptr32<void> s8_indexed_property_800fd3e4(Ptr32<K4aPropPair> pair, int key, ...);
extern int FUN_8018d35c(Ptr32<void> holder, Ptr32<K4aPropPair> pair);
extern Ptr32<K4aContext> w3d_engine_get_context(void);

void k4a_target_cache_context_80064d20(Ptr32<K4aTarget> self)
{
    K4aPropPair pair;
    FUN_80064384(self, self->key);
    {
        Ptr32<void> holder = w3d_empty_80343580(self->holder_ref);
        s8_indexed_property_800fd3e4(&pair, self->key);
        FUN_8018d35c(holder, &pair);
    }
    self->cached = w3d_engine_get_context()->value;
}

}
