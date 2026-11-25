// GWMP8P rev0 0x802847cc. Looks up DATA.TeamBarracks, converts it with the
// tagged descriptor at 0x80178474 and clears the word at +64 of every listed
// entry. The early return is an if over a do-while(0): the loop-end note
// before the join stops CSE path following (d28f). The count is read
// directly through the embedded list holder and the items through its inline
// member, so CSE keeps a second load that the post-reload pass turns into a
// register copy.
struct Object;
struct ObjectTable { void *s0[3]; void (*retain)(Object *); void (*release)(Object *); };
struct D25fEntry { char pad[64]; int score; };
struct D25fList { char pad[24]; unsigned count; char pad28[4]; D25fEntry *entries[1]; };
struct D25fSub { int a; D25fList *list; D25fEntry **Entries() { return list->entries; } };
struct Object { ObjectTable *vtable; char pad[16]; D25fSub sub; };
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
struct LR { D25fList *l; D25fEntry **E() const { return l->entries; } unsigned N() const { return l->count; } };
struct Items { D25fEntry **p; D25fEntry **Get() const { return p; } };
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
extern "C" void d30f_clear_barracks_scores_802847cc() {
    Descriptor_80178474 descriptor;
    Descriptor_80178474 *d = &descriptor;
    Handle handle;
    if (w3d_resource_property_800fc1b0(PropertyKey(w3d_string_803ceaa0), &handle.value) < 0) do { return; } while (0);
    Held team;
    {
        Held acquired(w3d_as_team_80179598(w3d_identity_80341584(handle.value), d));
        team.assign(acquired.value);
    }
    unsigned i = 0;
    unsigned count = team.value->sub.list->count;
    D25fEntry **items = team.value->sub.Entries();
    for (; i < count; i++)
        items[i]->score = 0;
}
