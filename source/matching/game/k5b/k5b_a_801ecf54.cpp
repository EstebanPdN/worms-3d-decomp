// flags: -fvtable-thunks
struct K5bSource { void **vtable; };
struct K5bContext { char pad[8]; int scope; };
struct K5bHost { char pad[8]; K5bSource *source; K5bContext *context; };
class K5bTarget;
typedef void (K5bTarget::*K5bSetter)(int);
struct K5bBinding {
    K5bHost *host;
    char pad4[16];
    K5bSetter setter;
};
extern "C" int w3d_k5b_binding_fetch_apply_int_801ecf54(K5bBinding *self, int key, K5bTarget *object)
{
    int fetched;
    K5bSource *source = self->host->source;
    int result = ((int (*)(K5bSource *, int *, int, int))source->vtable[18])(source, &fetched, key,
        self->host->context->scope);
    if (result >= 0)
        (object->*(self->setter))(fetched);
    return result;
}
// desc: w3d_k5b_binding_fetch_apply_int_801ecf54: Appears to fetch an integer through virtual slot 18 of the host source within the host context scope and, on success, pass it to the bound member-function setter.
