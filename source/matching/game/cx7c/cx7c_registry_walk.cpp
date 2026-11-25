/* Inferred registry walk, original 0x80355690.
 * A global registry yields opaque entries; each is refreshed before obtaining
 * its successor. Entry and registry layouts are not exposed by this wrapper.
 */
struct Cx7cRegistry;
struct Cx7cRegistryEntry;
extern "C" {
extern unsigned char cx7c_registry_80362444[];
Cx7cRegistryEntry *cx7c_registry_first_8020fe00(Cx7cRegistry *);
Cx7cRegistryEntry *cx7c_registry_next_8020fe18(Cx7cRegistry *, Cx7cRegistryEntry *);
void cx7c_entry_refresh_801a7ed8(Cx7cRegistryEntry *);
void w3d_cx7c_registry_refresh_80355690()
{
    Cx7cRegistryEntry *entry = cx7c_registry_first_8020fe00((Cx7cRegistry *)cx7c_registry_80362444);
    while (entry) {
        cx7c_entry_refresh_801a7ed8(entry);
        entry = cx7c_registry_next_8020fe18((Cx7cRegistry *)cx7c_registry_80362444, entry);
    }
}
}
