#include "w3d_ptr.h"
#line 1 "d25b_inventory_reset_8008b80c.cpp"
/* Inventory weapon slots reset (0x8008b80c): formats sixteen and then four
 * resource names into a string (0x8020c510, formats 0x8037de84 and 0x8037de98),
 * loads each inventory object through one handle (0x800fc1b0, 0x80341584,
 * 0x80179598) and clears its counters at +20 and +24 to +64. Field and type names
 * are inferred from the original instructions. Strings and globals are external
 * views of original data; the unit owns no data. */
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
/* Retained reference, one word. */
struct Held {
    Ptr32<Object> value;
    Held() : value(0) {}
    template <class W3dU> Held(Ptr32<W3dU> w3d_p) : Held((Object *)w3d_p.get()) {}
 Held(Object *next) : value(next) { if (value) value->vtable->retain(value); }
    Held(const Held &);
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
struct String {
    Ptr32<char> text;
    String();
    String(const String &);
    ~String();
};
extern "C" void w3d_string_finish_8020c5c4(Ptr32<String>);
extern "C" void w3d_string_release_80341588(Ptr32<String>);
inline String::~String() {
    w3d_string_finish_8020c5c4(this);
    w3d_string_release_80341588(this);
}
/* Declared void as in the admitted callers of 0x8020c510: its body leaves r3 from a final call, and the receiver-before-format move order needs void. */
extern "C" void w3d_string_format_8020c510(Ptr32<String>, Ptr32<const char>, ...);
struct InventoryView : Object {
    char unknown04[16] __attribute__((aligned(__alignof__(Object))));
    int count;       /* +20 */
    int slots[11];   /* +24 */
};
extern "C" char w3d_string_8037de84[];
extern "C" char w3d_string_8037de98[];

inline void Acquire(Held &current, Ptr32<Object> object)
{
    Held acquired(object);
    current.assign(acquired.value);
}

extern "C" void w3d_d25b_inventory_reset_8008b80c()
{
    Descriptor_80178474 descriptor;
    Handle handle;
    handle.value = 0;
    String text;
    for (unsigned i = 0; i <= 15; i++) {
        w3d_string_format_8020c510(&text, w3d_string_8037de84, i);
        PropertyKey key;
        key.name = text.text;
        w3d_resource_property_800fc1b0(&key, &handle.value);
        Held current;
        Acquire(current, w3d_as_inventory_80179598(w3d_identity_80341584(handle.value), &descriptor));
        Ptr32<InventoryView> view = (Ptr32<InventoryView>)current.value;
        view->slots[10] = 0;
        view->slots[9] = 0;
        view->slots[8] = 0;
        view->slots[7] = 0;
        view->slots[6] = 0;
        view->slots[5] = 0;
        view->slots[4] = 0;
        view->slots[3] = 0;
        view->slots[2] = 0;
        view->slots[1] = 0;
        view->slots[0] = 0;
        view->count = 0;
    }
    for (unsigned i = 0; i <= 3; i++) {
        w3d_string_format_8020c510(&text, w3d_string_8037de98, i);
        PropertyKey key;
        key.name = text.text;
        w3d_resource_property_800fc1b0(&key, &handle.value);
        Held current;
        Acquire(current, w3d_as_inventory_80179598(w3d_identity_80341584(handle.value), &descriptor));
        Ptr32<InventoryView> view = (Ptr32<InventoryView>)current.value;
        view->slots[10] = 0;
        view->slots[9] = 0;
        view->slots[8] = 0;
        view->slots[7] = 0;
        view->slots[6] = 0;
        view->slots[5] = 0;
        view->slots[4] = 0;
        view->slots[3] = 0;
        view->slots[2] = 0;
        view->slots[1] = 0;
        view->slots[0] = 0;
        view->count = 0;
    }
}


