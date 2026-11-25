#include "w3d_ptr.h"
#line 1 "handle_set_name.cpp"
/* Reconstructed manager wrapper8015adf4..8015ae3c; names/types inferred. */
extern "C" {
struct EngineString;
struct ResourceRef;
struct HandleNameManager;
struct HandleNameMethods {
    unsigned char unobserved_00[0x88];
    Ptr32<void (Ptr32<HandleNameManager>, Ptr32<EngineString>, Ptr32<ResourceRef>, unsigned int)> set_name;
};
struct HandleNameManager { Ptr32<HandleNameMethods> methods; };
struct HandleNameContext {
    unsigned char unobserved_00[0x74];
    Ptr32<HandleNameManager> manager;
};
extern Ptr32<HandleNameContext> w3d_handle_name_context;

/* Native r3 is preserved from the virtual call. Its semantic return type is
 * unknown; the observed handle caller ignores it. This void interface is the
 * caller's contract and does not claim the virtual method returns void. */
void w3d_handle_set_name(Ptr32<EngineString> name, Ptr32<ResourceRef> resource, unsigned int flags)
{
    Ptr32<HandleNameManager> manager = w3d_handle_name_context->manager;
    manager->methods->set_name(manager, name, resource, flags);
}
}


