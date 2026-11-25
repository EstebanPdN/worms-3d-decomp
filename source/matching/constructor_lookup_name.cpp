/* Reconstructed from original Worms3D GameCube instructions.
 * Names, semantic return type, and prefix types are inferred, not recovered
 * original identifiers. Only accessed offsets are represented. */
extern "C" {
struct ConstructorOwned;
struct LookupManager;
struct LookupMethods {
    unsigned char unobserved_00[0x7c];
    unsigned int (*lookup)(LookupManager *, const void *, void *);
};
struct LookupManager { LookupMethods *methods; };
struct LookupContext {
    unsigned char unobserved_00[0x64];
    LookupManager *manager;
};
extern LookupContext *w3d_constructor_lookup_context;

unsigned int w3d_constructor_lookup_name(const void *name, void *output)
{
    LookupManager *manager = w3d_constructor_lookup_context->manager;
    return manager->methods->lookup(manager, name, output);
}

}
