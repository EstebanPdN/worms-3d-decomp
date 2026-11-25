struct K4aRefVtable;
struct K4aRef { const K4aRefVtable *vtable; char pad0[64]; int a_value; int b_value; };
struct K4aRefVtable { void (*unknown_00[3])(void); void (*retain)(K4aRef *self); void (*release)(K4aRef *self); };
struct K4aHeld {
    K4aRef *ref;
    int unused;
    K4aHeld(K4aRef *r) : ref(r) { if (ref) ref->vtable->retain(ref); }
    ~K4aHeld() { if (ref) ref->vtable->release(ref); }
};
struct K4aTeamRecord { char pad0[260]; int field_260; };
struct K4aChooser { char pad0[20]; unsigned int owner; };
extern "C" char w3d_str_8037d874[];
extern "C" char w3d_str_8037d7d0[];
extern "C" char w3d_service_80410f70[];
extern "C" int w3d_auto_800fc230(const char **name, int *value);
extern "C" int w3d_auto_800fc1f0(const char **name, int *value);
extern "C" K4aTeamRecord *s8_index_query_800fc6dc(int index);
extern "C" K4aRef *w3d_s10_service_forward_8020b680(void *);
extern "C" int FUN_80164514(void *context, K4aRef *ref, unsigned int owner);
extern "C" void *w3d_context_804b178c;

extern "C" void k4a_chooser_reset_8008991c(K4aChooser *self)
{
    const char *enabled_key;
    int enabled;
    enabled_key = w3d_str_8037d874;
    w3d_auto_800fc230(&enabled_key, &enabled);
    if (enabled == 0) {
        const char *index_key;
        int index = 0;
        int value;
        index_key = w3d_str_8037d7d0;
        w3d_auto_800fc1f0(&index_key, &index);
        value = s8_index_query_800fc6dc(index)->field_260;
        if (value == 0) {
            K4aHeld held(w3d_s10_service_forward_8020b680(w3d_service_80410f70));
            FUN_80164514(w3d_context_804b178c, held.ref, self->owner);
            held.ref->a_value = value;
            held.ref->b_value = 1;
        }
    }
}
