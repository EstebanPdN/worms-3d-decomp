// flags: -fvtable-thunks
struct K5bValue { int word; };
class K5bSource;
class K5bTarget;
typedef K5bValue (K5bSource::*K5bGetter)(...);
typedef void (K5bTarget::*K5bSetter)(K5bValue);
struct K5bGetterDesc {
    char pad[12];
    K5bGetter getter;
};
struct K5bBinding {
    char pad[20];
    K5bSetter setter;
};
extern "C" void w3d_k5b_binding_copy_member_801ec81c(K5bBinding *self, K5bTarget *target, K5bSource *source,
    K5bGetterDesc *desc)
{
    (target->*(self->setter))((source->*(desc->getter))());
}
// desc: w3d_k5b_binding_copy_member_801ec81c: Appears to read a value through the member-function getter at +12 of the descriptor and pass it to the binding's member-function setter at +20 on the target.
