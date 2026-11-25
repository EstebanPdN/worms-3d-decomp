#include "w3d_ptr.h"
#line 1 "k7a_blend_effect_construct_80062c24.cpp"
struct K7aEngineContext { char pad0[184]; float blend; };

struct K7aBlendEffect
{
    Ptr32<const void> vtable;     // +0
    char pad4[24];
    int link_28;
    char pad32[8];
    int field_40;
    int field_44;
    int field_48;
    int field_52;
    char pad56[8];
    float low;              // +64
    float high;             // +68
    float high_floor;       // +72
};

extern "C" Ptr32<const void> w3d_vtable_8040ed80[];
extern "C" Ptr32<K7aEngineContext> w3d_engine_context_804b1788;
extern "C" const float w3d_f32_80379b00[];
extern "C" const float w3d_f32_80379b04[];
extern "C" const float w3d_f32_80379b08[];
extern "C" const float w3d_f32_80379b0c[];
extern "C" const float w3d_f32_80379b10[];
extern "C" int w3d_ctor_8015fef0(Ptr32<void> object);

extern "C" Ptr32<K7aBlendEffect> w3d_k7a_blend_effect_construct_80062c24(Ptr32<K7aBlendEffect> self)
{
    w3d_ctor_8015fef0(self);
    self->vtable = w3d_vtable_8040ed80;
    self->link_28 = 0;
    self->field_40 = 0;
    self->field_44 = 0;
    self->field_48 = 0;
    self->field_52 = 0;
    float blend = w3d_engine_context_804b1788->blend;
    float rest = w3d_f32_80379b00[0] - blend;
    float low = blend * w3d_f32_80379b04[0] + rest * w3d_f32_80379b08[0];
    float high = blend * w3d_f32_80379b0c[0] + rest * w3d_f32_80379b10[0];
    self->high = high;
    self->low = low;
    self->high_floor = high - w3d_f32_80379b10[0];
    return self;
}


