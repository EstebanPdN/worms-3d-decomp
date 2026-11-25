#include "w3d_ptr.h"
#line 1 "k5b_a_801ed47c.cpp"
// flags: -fvtable-thunks
struct K5bIface { Ptr32<Ptr32<void>> vtable; };
struct K5bTypeInfo { int id; };
class K5bSource;
typedef w3d::Pmf<K5bSource, Ptr32<K5bIface>()> K5bGetter;
struct K5bObjectBinding {
    Ptr32<K5bTypeInfo> type;
    char pad4[8];
    K5bGetter getter;
};
extern char lbl_8040c970[];
extern "C" int w3d_k5b_binding_write_object_801ed47c(Ptr32<K5bObjectBinding> self, Ptr32<K5bIface> writer, Ptr32<K5bSource> source)
{
    Ptr32<K5bIface> held;
    Ptr32<K5bIface> value = ((self->getter))(source);
    int result;
    Ptr32<Ptr32<K5bIface>> out = &held;
    held = 0;
    if (value != 0)
        ((Ptr32<void (Ptr32<K5bIface>, Ptr32<char>, Ptr32<Ptr32<K5bIface>>)>)value->vtable[2])(value, lbl_8040c970, out);
    result = ((Ptr32<int (Ptr32<K5bIface>, Ptr32<K5bIface>, int)>)writer->vtable[8])(writer, held, self->type->id);
    if (held != 0)
        ((Ptr32<void (Ptr32<K5bIface>)>)held->vtable[4])(held);
    return result;
}
// desc: w3d_k5b_binding_write_object_801ed47c: Appears to read an object through the member-function getter, query it for interface 0x8040c970, write it with the writer's virtual slot 8 and release the queried reference.


