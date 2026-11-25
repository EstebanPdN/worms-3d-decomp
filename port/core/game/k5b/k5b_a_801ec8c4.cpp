#include "w3d_ptr.h"
#line 1 "k5b_a_801ec8c4.cpp"
// flags: -fvtable-thunks
struct K5bValue { int word; };
struct K5bSource { Ptr32<Ptr32<void>> vtable; };
struct K5bHost { char pad[8]; Ptr32<K5bSource> source; };
class K5bTarget;
typedef w3d::Pmf<K5bTarget, void(K5bValue)> K5bSetter;
struct K5bBinding {
    Ptr32<K5bHost> host;
    char pad4[16];
    K5bSetter setter;
};
extern "C" int w3d_k5b_binding_fetch_apply_801ec8c4(Ptr32<K5bBinding> self, int key, Ptr32<K5bTarget> object)
{
    K5bValue fetched;
    Ptr32<K5bSource> source = self->host->source;
    int result = ((Ptr32<int (Ptr32<K5bSource>, Ptr32<K5bValue>, int, int)>)source->vtable[18])(source, &fetched, key, 0);
    if (result >= 0)
        ((self->setter))(object, fetched);
    return result;
}
// desc: w3d_k5b_binding_fetch_apply_801ec8c4: Appears to fetch a value through virtual slot 18 of the host source and, on success, pass it by value to the bound member-function setter on the object.


