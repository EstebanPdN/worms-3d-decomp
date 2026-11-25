/* End-of-turn inventory tick (0x8008a8b4): decrements BuffaloRoundsActive
 * when non-zero, then walks the 59 weapon counters of the
 * Inventory.Weapons object (read 0x8025c3a8, write 0x8025c71c), decrementing each
 * non-zero one, and posts two cached messages when a counter reached zero. Field
 * and type names are inferred from the original instructions. Strings and globals
 * are external views of original data; the unit owns no data. */
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
 * keeps the two references 8 bytes apart at sp+24 and sp+32, the same layout as the
 * admitted family member f12c_rename_resource_80264698. */
struct Held {
 Held(const Held &);
    Object *value;
    Held() : value(0) {}
    Held(Object *next) : value(next) { if (value) value->vtable->retain(value); }
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
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Message { unsigned short id; unsigned short unknown02; void *vtable; };
extern "C" int w3d_int_read_800fc230(PropertyKey *, int *);
extern "C" int w3d_int_write_800fc43c(PropertyKey *, int);
extern "C" unsigned char w3d_weapon_count_8025c3a8(Object *, unsigned);
extern "C" void w3d_weapon_count_set_8025c71c(Object *, unsigned, unsigned char);
extern "C" void *w3d_arena_alloc_801613f0(void *, int);
extern "C" int w3d_cached_message_id_8015f5a0(MessageCache *, int);
extern "C" int w3d_message_post_8016239c(void *);
extern void *w3d_message_arena_804b1754;
extern MessageCache w3d_message_804add9c, w3d_message_804adcf4;
extern unsigned char w3d_vtable_8040db38[];
extern "C" char w3d_string_8037dbc0[]; /* "BuffaloRoundsActive" */
extern "C" char w3d_string_8037dbd4[]; /* "Inventory.WeaponDelays" */

extern "C" void w3d_d24b_inventory_tick_8008a8b4()
{
    int rounds = 0;
    {
        PropertyKey key;
        key.name = w3d_string_8037dbc0;
        w3d_int_read_800fc230(&key, &rounds);
    }
    if (rounds) {
        rounds--;
        PropertyKey key;
        key.name = w3d_string_8037dbc0;
        w3d_int_write_800fc43c(&key, rounds);
    }
    Descriptor_80178474 descriptor;
    Handle handle;
    handle.value = 0;
    {
        PropertyKey key;
        key.name = w3d_string_8037dbd4;
        w3d_resource_property_800fc1b0(&key, &handle.value);
    }
    Held current;
    {
        Held acquired(w3d_as_inventory_80179598(w3d_identity_80341584(handle.value), &descriptor));
        current.assign(acquired.value);
    }
    int emptied = 0;
    for (unsigned i = 0; i <= 58; i++) {
        unsigned char count = w3d_weapon_count_8025c3a8(current.value, i);
        if (count) {
            w3d_weapon_count_set_8025c71c(current.value, i, count - 1);
            if (count == 1) emptied = 1;
        }
    }
    if (emptied) {
        Message *first = (Message *)w3d_arena_alloc_801613f0(w3d_message_arena_804b1754, 8);
        first->id = w3d_cached_message_id_8015f5a0(&w3d_message_804add9c, 1);
        first->vtable = w3d_vtable_8040db38;
        w3d_message_post_8016239c(first);
        Message *second = (Message *)w3d_arena_alloc_801613f0(w3d_message_arena_804b1754, 8);
        second->id = w3d_cached_message_id_8015f5a0(&w3d_message_804adcf4, 1);
        second->vtable = w3d_vtable_8040db38;
        w3d_message_post_8016239c(second);
    }
}
