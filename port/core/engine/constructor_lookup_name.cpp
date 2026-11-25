#include "w3d_ptr.h"
#line 1 "constructor_lookup_name.cpp"
/* Reconstructed from original Worms3D GameCube instructions.
 * Names, semantic return type, and prefix types are inferred, not recovered
 * original identifiers. Only accessed offsets are represented. */
extern "C" {
struct ConstructorOwned;
struct LookupManager;
struct LookupMethods {
    unsigned char unobserved_00[0x7c];
    Ptr32<unsigned int (Ptr32<LookupManager>, Ptr32<const void>, Ptr32<void>)> lookup;
};
struct LookupManager { Ptr32<LookupMethods> methods; };
struct LookupContext {
    unsigned char unobserved_00[0x64];
    Ptr32<LookupManager> manager;
};
extern Ptr32<LookupContext> w3d_constructor_lookup_context;

unsigned int w3d_constructor_lookup_name(Ptr32<const void> name, Ptr32<void> output)
{
    Ptr32<LookupManager> manager = w3d_constructor_lookup_context->manager;
    return manager->methods->lookup(manager, name, output);
}

}


