#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s15_hand_8011ad90.c"
/* Inferred effect update shapes and property getters. */
typedef struct S15EffectOwner {char unknown0[28];int effect;char unknown32[36];int first,second;} S15EffectOwner;
extern Ptr32<void> fn_80343580(int);
extern int fn_8018c5b0(Ptr32<void>,int);
extern int fn_8018d35c(Ptr32<void>,Ptr32<int>);
extern int fn_8018d434(Ptr32<void>,Ptr32<int>);
extern int fn_8011bc28(Ptr32<S15EffectOwner>);
void s15_update_saved_effect_8011ad90(Ptr32<S15EffectOwner> self,int value)
{
    if(self->effect) {
        Ptr32<void> effect=fn_80343580(self->effect);
        fn_8018c5b0(effect,value);
        fn_8018d35c(effect,&self->first);
        fn_8018d434(effect,&self->second);
        fn_8011bc28(self);
    }
}

}
