// flags: -fvtable-thunks
struct K5bIface { void **vtable; };
struct K5bTypeInfo { int id; };
class K5bSource;
typedef K5bIface *(K5bSource::*K5bGetter)();
struct K5bObjectBinding {
    K5bTypeInfo *type;
    char pad4[8];
    K5bGetter getter;
};
extern char lbl_8040c970[];
extern "C" int w3d_k5b_binding_write_object_801ed47c(K5bObjectBinding *self, K5bIface *writer, K5bSource *source)
{
    K5bIface *held;
    K5bIface *value = (source->*(self->getter))();
    int result;
    K5bIface **out = &held;
    held = 0;
    if (value != 0)
        ((void (*)(K5bIface *, char *, K5bIface **))value->vtable[2])(value, lbl_8040c970, out);
    result = ((int (*)(K5bIface *, K5bIface *, int))writer->vtable[8])(writer, held, self->type->id);
    if (held != 0)
        ((void (*)(K5bIface *))held->vtable[4])(held);
    return result;
}
// desc: w3d_k5b_binding_write_object_801ed47c: Appears to read an object through the member-function getter, query it for interface 0x8040c970, write it with the writer's virtual slot 8 and release the queried reference.
