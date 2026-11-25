/* Inventory defaults reset (0x8008c954): loads the worm, team and alliance default
 * inventories and the default and live weapon delay tables through one handle
 * (0x800fc1b0, 0x80341584, 0x80179598) keeping them retained, clears them
 * (0x8025ca78, 0x8025c2d8), and propagates the default tags to the live delays, the
 * sixteen worm inventories (0x800fca64), four team inventories (0x800fcc9c) and four
 * alliance inventories (0x800fcdb8) (0x801ea4c8). Field and type names are inferred
 * from the original instructions. Strings and globals are external views of original
 * data; the unit owns no data. */
struct Object;
struct ObjectVtable {
    void *unknown00[3];
    void (*retain)(Object *);   /* +12 */
    void (*release)(Object *);  /* +16 */
};
struct Object { ObjectVtable *vtable; };
struct Handle {
    Object *value;
    Handle() {}
    ~Handle() { if (value) value->vtable->release(value); }
private:
    Handle(const Handle &);
};
/* Owned type descriptor released through 0x80178474. */
struct Descriptor_80178474 {
    void *value;
    unsigned tag;
    Descriptor_80178474() : value(0), tag(58280) {}
    ~Descriptor_80178474();
};
/* Retained reference. It has a user copy constructor: the original
 * keeps the references 8 bytes apart, the same layout as the admitted family member
 * f12c_rename_resource_80264698. */
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
struct PropertyKey { const char *name; };
extern "C" int w3d_resource_property_800fc1b0(PropertyKey *, Object **);
extern "C" void *w3d_identity_80341584(Object *);
extern "C" Object *w3d_as_inventory_80179598(void *, Descriptor_80178474 *);
extern "C" void w3d_clear_flags_8025ca78(Object *);
extern "C" void w3d_clear_flags_8025c2d8(Object *);
extern "C" int w3d_unsigned_read_800fc330(PropertyKey *, unsigned *);
extern "C" void w3d_propagate_tag_801ea4c8(Object *, void *);
extern "C" Object *w3d_worm_inventory_800fca64(unsigned, Descriptor_80178474 *);
extern "C" Object *w3d_team_inventory_800fcc9c(unsigned, Descriptor_80178474 *);
extern "C" Object *w3d_alliance_inventory_800fcdb8(unsigned, Descriptor_80178474 *);
extern "C" char w3d_string_8037e0cc[]; /* "Inventory.Worm.Default" */
extern "C" char w3d_string_8037e0e4[]; /* "Inventory.Team.Default" */
extern "C" char w3d_string_8037e0fc[]; /* "Inventory.Alliance.Default" */
extern "C" char w3d_string_8037e118[]; /* "Inventory.WeaponDelays.Default" */
extern "C" char w3d_string_8037dbd4[]; /* "Inventory.WeaponDelays" */

inline unsigned ReadTag(const char *name)
{
    PropertyKey key;
    key.name = name;
    unsigned tag;
    w3d_unsigned_read_800fc330(&key, &tag);
    return tag;
}

extern "C" void w3d_d24b_inventory_defaults_reset_8008c954()
{
    Descriptor_80178474 descriptor;
    Handle handle;
    handle.value = 0;
    {
        PropertyKey key;
        key.name = w3d_string_8037e0cc;
        w3d_resource_property_800fc1b0(&key, &handle.value);
    }
    Held worm;
    {
        Held acquired(w3d_as_inventory_80179598(w3d_identity_80341584(handle.value), &descriptor));
        worm.assign(acquired.value);
    }
    w3d_clear_flags_8025ca78(worm.value);
    {
        PropertyKey key;
        key.name = w3d_string_8037e0e4;
        w3d_resource_property_800fc1b0(&key, &handle.value);
    }
    Held team;
    {
        Held acquired(w3d_as_inventory_80179598(w3d_identity_80341584(handle.value), &descriptor));
        team.assign(acquired.value);
    }
    w3d_clear_flags_8025ca78(team.value);
    {
        PropertyKey key;
        key.name = w3d_string_8037e0fc;
        w3d_resource_property_800fc1b0(&key, &handle.value);
    }
    Held alliance;
    {
        Held acquired(w3d_as_inventory_80179598(w3d_identity_80341584(handle.value), &descriptor));
        alliance.assign(acquired.value);
    }
    w3d_clear_flags_8025ca78(alliance.value);
    {
        PropertyKey key;
        key.name = w3d_string_8037e118;
        w3d_resource_property_800fc1b0(&key, &handle.value);
    }
    Held defaults;
    {
        Held acquired(w3d_as_inventory_80179598(w3d_identity_80341584(handle.value), &descriptor));
        defaults.assign(acquired.value);
    }
    w3d_clear_flags_8025c2d8(defaults.value);
    {
        PropertyKey key;
        key.name = w3d_string_8037dbd4;
        w3d_resource_property_800fc1b0(&key, &handle.value);
    }
    Held delays;
    {
        Held acquired(w3d_as_inventory_80179598(w3d_identity_80341584(handle.value), &descriptor));
        delays.assign(acquired.value);
    }
    {
        PropertyKey key;
        key.name = w3d_string_8037e118;
        unsigned tag;
        w3d_unsigned_read_800fc330(&key, &tag);
        w3d_propagate_tag_801ea4c8(delays.value, (void *)tag);
    }
    {
        unsigned tag = ReadTag(w3d_string_8037e0cc);
        for (unsigned i = 0; i <= 15; i++) {
            Descriptor_80178474 slot;
            w3d_propagate_tag_801ea4c8(w3d_worm_inventory_800fca64(i, &slot), (void *)tag);
        }
    }
    {
        unsigned tag = ReadTag(w3d_string_8037e0e4);
        for (unsigned i = 0; i <= 3; i++) {
            Descriptor_80178474 slot;
            w3d_propagate_tag_801ea4c8(w3d_team_inventory_800fcc9c(i, &slot), (void *)tag);
        }
    }
    {
        unsigned tag = ReadTag(w3d_string_8037e0fc);
        for (unsigned i = 0; i <= 3; i++) {
            Descriptor_80178474 slot;
            w3d_propagate_tag_801ea4c8(w3d_alliance_inventory_800fcdb8(i, &slot), (void *)tag);
        }
    }
}
