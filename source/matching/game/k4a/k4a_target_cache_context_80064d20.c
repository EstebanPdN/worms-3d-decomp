typedef struct K4aPropPair { int first; int second; } K4aPropPair;
typedef struct K4aContext { char pad0[52]; int value; } K4aContext;
typedef struct K4aTarget { char pad0[36]; void *holder_ref; char pad1[8]; int key; char pad2[48]; int cached; } K4aTarget;
extern void FUN_80064384(void *target, int key);
extern void *w3d_empty_80343580(void *);
extern void * s8_indexed_property_800fd3e4(K4aPropPair *pair, int key, ...);
extern int FUN_8018d35c(void *holder, K4aPropPair *pair);
extern K4aContext *w3d_engine_get_context(void);

void k4a_target_cache_context_80064d20(K4aTarget *self)
{
    K4aPropPair pair;
    FUN_80064384(self, self->key);
    {
        void *holder = w3d_empty_80343580(self->holder_ref);
        s8_indexed_property_800fd3e4(&pair, self->key);
        FUN_8018d35c(holder, &pair);
    }
    self->cached = w3d_engine_get_context()->value;
}
