#include "w3d_ptr.h"
#line 1 "k5b_a_801ec964.cpp"
// flags: -fvtable-thunks
struct K5bValue { int words[2]; };
class K5bSource;
class K5bTarget;
typedef w3d::Pmf<K5bSource, K5bValue(...)> K5bGetter;
typedef w3d::Pmf<K5bTarget, void(K5bValue)> K5bSetter;
struct K5bGetterDesc {
    char pad[16];
    K5bGetter getter;
};
struct K5bBinding {
    char pad[24];
    K5bSetter setter;
};
extern "C" void w3d_k5b_binding_copy_wide_member_801ec964(Ptr32<K5bBinding> self, Ptr32<K5bTarget> target, Ptr32<K5bSource> source,
    Ptr32<K5bGetterDesc> desc)
{
    ((self->setter))(target, ((desc->getter))(source));
}
// desc: w3d_k5b_binding_copy_wide_member_801ec964: Appears to read a value through the member-function getter at +16 of the descriptor and pass it to the binding's member-function setter at +24 on the target.


