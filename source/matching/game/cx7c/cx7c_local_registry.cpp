/* Inferred lazy registry accessor. Guard at 0x804b060c and object at
 * 0x8045e9c8 remain original external data. The recorded cleanup is registered
 * once, after construction, matching this runtime's non-thread-safe guard.
 */
struct Cx7cLocalRegistry;
extern "C" {
extern int cx7c_guard_804b060c;
extern unsigned char cx7c_storage_8045e9c8[];
void cx7c_registry_construct_8016df70(Cx7cLocalRegistry *);
void cx7c_registry_cleanup_801fdb6c();
int cx7c_register_exit_802ed7e0(void (*)());
}
extern "C" Cx7cLocalRegistry *w3d_cx7c_local_registry_8035a3a8()
{
    if (!cx7c_guard_804b060c) {
        cx7c_registry_construct_8016df70((Cx7cLocalRegistry *)cx7c_storage_8045e9c8);
        cx7c_guard_804b060c=1;
        cx7c_register_exit_802ed7e0(cx7c_registry_cleanup_801fdb6c);
    }
    return (Cx7cLocalRegistry *)cx7c_storage_8045e9c8;
}
