#include "w3d_ptr.h"
#line 1 "k5b_a_801eda24.cpp"
// flags: -fvtable-thunks
class K5bTarget;
typedef w3d::Pmf<K5bTarget, void(unsigned int)> K5bSetter;
struct K5bBinding {
    char pad[20];
    K5bSetter setter;
};
extern "C" void w3d_k5b_binding_store_unsigned_801eda24(Ptr32<K5bBinding> self, Ptr32<K5bTarget> object, Ptr32<void> context,
    Ptr32<const float> value)
{
    ((self->setter))(object, (unsigned int)*value);
}
// desc: w3d_k5b_binding_store_unsigned_801eda24: Appears to convert a float value to an unsigned integer and pass it to the binding's member-function setter at +20 on the object.


