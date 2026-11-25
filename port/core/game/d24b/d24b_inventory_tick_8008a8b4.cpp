#include "w3d_ptr.h"
#line 1 "d24b_inventory_tick_8008a8b4.cpp"
/* End-of-turn inventory tick (0x8008a8b4): decrements BuffaloRoundsActive
 * when non-zero, then walks the 59 weapon counters of the
 * Inventory.Weapons object (read 0x8025c3a8, write 0x8025c71c), decrementing each
 * non-zero one, and posts two cached messages when a counter reached zero. Field
 * and type names are inferred from the original instructions. Strings and globals
 * are external views of original data; the unit owns no data. */
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<Object>)> retain;   /* +12 */
    Ptr32<void (Ptr32<Object>)> release;  /* +16 */
};
struct Object { Ptr32<ObjectVtable> vtable; };
struct Handle {
    Ptr32<Object> value;
    Handle() {}
    ~Handle() { if (value) value->vtable->release(value); }
private:
    Handle(const Handle &);
};
/* Owned type descriptor released through 0x80178474. */
struct Descriptor_80178474 {
    Ptr32<void> value;
    unsigned tag;
    Descriptor_80178474() : value(0), tag(58280) {}
    ~Descriptor_80178474();
};
/* Retained reference. It has a user copy constructor: the original
 * keeps the two references 8 bytes apart at sp+24 and sp+32, the same layout as the
 * admitted family member f12c_rename_resource_80264698. */
struct Held {
 Held(const Held &);
    Ptr32<Object> value;
    Held() : value(0) {}
    template <class W3dU> Held(Ptr32<W3dU> w3d_p) : Held((Object *)w3d_p.get()) {}
 Held(Object *next) : value(next) { if (value) value->vtable->retain(value); }
    ~Held() { if (value) value->vtable->release(value); }
    void assign(Ptr32<Object> next) {
        if (next) {
            next->vtable->retain(next);
            if (value) value->vtable->release(value);
            value = next;
        }
    }
};
struct PropertyKey { Ptr32<const char> name; };
extern "C" int w3d_resource_property_800fc1b0(Ptr32<PropertyKey>, Ptr32<Ptr32<Object>>);
extern "C" Ptr32<void> w3d_identity_80341584(Ptr32<Object>);
extern "C" Ptr32<Object> w3d_as_inventory_80179598(Ptr32<void>, Ptr32<Descriptor_80178474>);
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Message { unsigned short id; unsigned short unknown02; Ptr32<void> vtable; };
extern "C" int w3d_int_read_800fc230(Ptr32<PropertyKey>, Ptr32<int>);
extern "C" int w3d_int_write_800fc43c(Ptr32<PropertyKey>, int);
extern "C" unsigned char w3d_weapon_count_8025c3a8(Ptr32<Object>, unsigned);
extern "C" void w3d_weapon_count_set_8025c71c(Ptr32<Object>, unsigned, unsigned char);
extern "C" Ptr32<void> w3d_arena_alloc_801613f0(Ptr32<void>, int);
extern "C" int w3d_cached_message_id_8015f5a0(Ptr32<MessageCache>, int);
extern "C" int w3d_message_post_8016239c(Ptr32<void>);
extern Ptr32<void> w3d_message_arena_804b1754;
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
        Ptr32<Message> first = (Ptr32<Message>)w3d_arena_alloc_801613f0(w3d_message_arena_804b1754, 8);
        first->id = w3d_cached_message_id_8015f5a0(&w3d_message_804add9c, 1);
        first->vtable = w3d_vtable_8040db38;
        w3d_message_post_8016239c(first);
        Ptr32<Message> second = (Ptr32<Message>)w3d_arena_alloc_801613f0(w3d_message_arena_804b1754, 8);
        second->id = w3d_cached_message_id_8015f5a0(&w3d_message_804adcf4, 1);
        second->vtable = w3d_vtable_8040db38;
        w3d_message_post_8016239c(second);
    }
}


