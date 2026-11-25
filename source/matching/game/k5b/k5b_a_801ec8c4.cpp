// flags: -fvtable-thunks
struct K5bValue { int word; };
struct K5bSource { void **vtable; };
struct K5bHost { char pad[8]; K5bSource *source; };
class K5bTarget;
typedef void (K5bTarget::*K5bSetter)(K5bValue);
struct K5bBinding {
    K5bHost *host;
    char pad4[16];
    K5bSetter setter;
};
extern "C" int w3d_k5b_binding_fetch_apply_801ec8c4(K5bBinding *self, int key, K5bTarget *object)
{
    K5bValue fetched;
    K5bSource *source = self->host->source;
    int result = ((int (*)(K5bSource *, K5bValue *, int, int))source->vtable[18])(source, &fetched, key, 0);
    if (result >= 0)
        (object->*(self->setter))(fetched);
    return result;
}
// desc: w3d_k5b_binding_fetch_apply_801ec8c4: Appears to fetch a value through virtual slot 18 of the host source and, on success, pass it by value to the bound member-function setter on the object.
