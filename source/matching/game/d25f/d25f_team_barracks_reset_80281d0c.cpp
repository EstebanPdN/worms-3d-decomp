// GWMP8P rev0 0x80281d0c. Looks up DATA.TeamBarracks, converts it with the
// tagged descriptor at 0x80178474 and clears the +64 word of every listed
// entry. The descriptor has two real words: the original writes tag 58280 at
// +4. String and handle classes here are one word. The early return is
// written as an if over a do-while(0): the loop-end note before the join
// stops CSE path following, which gives the fresh zero load and the reloads.
// Only the instruction effect supports that form, as a macro would; it is
// listed under caveats.
struct Object;
struct ObjectTable { void *s0[3]; void (*retain)(Object *); void (*release)(Object *); };
struct D25fEntry { char pad[64]; int score; };
struct D25fList { char pad[24]; unsigned count; char pad28[4]; D25fEntry *entries[1]; };
struct Object { ObjectTable *vtable; char pad[20]; D25fList *list; };
struct Descriptor_80178474 {
    void *value;
    unsigned tag;
    Descriptor_80178474() : value(0), tag(58280) {}
    ~Descriptor_80178474();
};
struct Handle {
    Object *value;
    Handle() : value(0) {}
    Handle(const Handle &);
    ~Handle() { if (value) value->vtable->release(value); }
};
struct Held {
    Object *value;
    Held() : value(0) {}
    Held(Object *next) : value(next) { if (value) value->vtable->retain(value); }
    Held(const Held &);
    ~Held() { if (value) value->vtable->release(value); }
    void assign(Object *next) {
        if (next) {
            next->vtable->retain(next);
            if (value) value->vtable->release(value);
            value = next;
        }
    }
};
struct PropertyKey { const char *name; PropertyKey(const char *n) : name(n) {} };
extern "C" int w3d_resource_property_800fc1b0(const PropertyKey &, Object **);
extern "C" void *w3d_identity_80341584(Object *);
extern "C" Object *w3d_as_team_80179598(void *, Descriptor_80178474 *);
extern char w3d_string_803ceaa0[];
extern "C" void d25f_team_barracks_reset_80281d0c() {
    Descriptor_80178474 descriptor;
    Descriptor_80178474 *d = &descriptor;
    Handle handle;
    if (w3d_resource_property_800fc1b0(PropertyKey(w3d_string_803ceaa0), &handle.value) < 0) do { return; } while (0);
    Held team;
    {
        Held acquired(w3d_as_team_80179598(w3d_identity_80341584(handle.value), d));
        team.assign(acquired.value);
    }
    D25fList *list = team.value->list;
    unsigned count = list->count;
    D25fEntry **entries = list->entries;
    for (unsigned i = 0; i < count; i++)
        entries[i]->score = 0;
}
