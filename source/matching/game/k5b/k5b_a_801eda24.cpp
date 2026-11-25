// flags: -fvtable-thunks
class K5bTarget;
typedef void (K5bTarget::*K5bSetter)(unsigned int);
struct K5bBinding {
    char pad[20];
    K5bSetter setter;
};
extern "C" void w3d_k5b_binding_store_unsigned_801eda24(K5bBinding *self, K5bTarget *object, void *context,
    const float *value)
{
    (object->*(self->setter))((unsigned int)*value);
}
// desc: w3d_k5b_binding_store_unsigned_801eda24: Appears to convert a float value to an unsigned integer and pass it to the binding's member-function setter at +20 on the object.
