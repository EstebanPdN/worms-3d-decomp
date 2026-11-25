/* Reconstructed manager wrapper8015adf4..8015ae3c; names/types inferred. */
extern "C" {
struct EngineString;
struct ResourceRef;
struct HandleNameManager;
struct HandleNameMethods {
    unsigned char unobserved_00[0x88];
    void (*set_name)(HandleNameManager *, EngineString *, ResourceRef *, unsigned int);
};
struct HandleNameManager { HandleNameMethods *methods; };
struct HandleNameContext {
    unsigned char unobserved_00[0x74];
    HandleNameManager *manager;
};
extern HandleNameContext *w3d_handle_name_context;

/* Native r3 is preserved from the virtual call. Its semantic return type is
 * unknown; the observed handle caller ignores it. This void interface is the
 * caller's contract and does not claim the virtual method returns void. */
void w3d_handle_set_name(EngineString *name, ResourceRef *resource, unsigned int flags)
{
    HandleNameManager *manager = w3d_handle_name_context->manager;
    manager->methods->set_name(manager, name, resource, flags);
}
}
