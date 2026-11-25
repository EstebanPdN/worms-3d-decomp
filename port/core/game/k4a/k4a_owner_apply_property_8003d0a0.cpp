#include "w3d_ptr.h"
#line 1 "k4a_owner_apply_property_8003d0a0.cpp"
struct K4aPropValue { int value; };
struct K4aOwner { char pad0[36]; Ptr32<void> holder_ref; unsigned int index_source; };
extern "C" unsigned int w3d_auto_80178c48(Ptr32<void>);
extern "C" Ptr32<void> w3d_empty_8034357c(Ptr32<void>);
extern "C" Ptr32<K4aPropValue> FUN_800fd388(Ptr32<K4aPropValue>, unsigned);
extern "C" int FUN_80173df0(Ptr32<void> holder, Ptr32<K4aPropValue> value);

extern "C" void k4a_owner_apply_property_8003d0a0(Ptr32<K4aOwner> self)
{
    unsigned int index = w3d_auto_80178c48((Ptr32<void>)w3d::G(self->index_source));
    if (index <= 15) {
        Ptr32<void> holder = w3d_empty_8034357c(self->holder_ref);
        K4aPropValue value; FUN_800fd388(&value, index);
        FUN_80173df0(holder, &value);
    }
}


