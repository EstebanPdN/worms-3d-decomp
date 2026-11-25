#include "w3d_ptr.h"
#line 1 "k5b_a_801ecf54.cpp"
// flags: -fvtable-thunks
struct K5bSource { Ptr32<Ptr32<void>> vtable; };
struct K5bContext { char pad[8]; int scope; };
struct K5bHost { char pad[8]; Ptr32<K5bSource> source; Ptr32<K5bContext> context; };
class K5bTarget;
typedef w3d::Pmf<K5bTarget, void(int)> K5bSetter;
struct K5bBinding {
    Ptr32<K5bHost> host;
    char pad4[16];
    K5bSetter setter;
};
extern "C" int w3d_k5b_binding_fetch_apply_int_801ecf54(Ptr32<K5bBinding> self, int key, Ptr32<K5bTarget> object)
{
    int fetched;
    Ptr32<K5bSource> source = self->host->source;
    int result = ((Ptr32<int (Ptr32<K5bSource>, Ptr32<int>, int, int)>)source->vtable[18])(source, &fetched, key,
        self->host->context->scope);
    if (result >= 0)
        ((self->setter))(object, fetched);
    return result;
}
// desc: w3d_k5b_binding_fetch_apply_int_801ecf54: Appears to fetch an integer through virtual slot 18 of the host source within the host context scope and, on success, pass it to the bound member-function setter.


