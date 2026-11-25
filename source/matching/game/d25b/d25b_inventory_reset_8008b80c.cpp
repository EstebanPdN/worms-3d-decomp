/* Inventory weapon slots reset (0x8008b80c): formats sixteen and then four
 * resource names into a string (0x8020c510, formats 0x8037de84 and 0x8037de98),
 * loads each inventory object through one handle (0x800fc1b0, 0x80341584,
 * 0x80179598) and clears its counters at +20 and +24 to +64. Field and type names
 * are inferred from the original instructions. Strings and globals are external
 * views of original data; the unit owns no data. */
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
/* Retained reference, one word. */
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
struct String {
    char *text;
    String();
    String(const String &);
    ~String();
};
extern "C" void w3d_string_finish_8020c5c4(String *);
extern "C" void w3d_string_release_80341588(String *);
inline String::~String() {
    w3d_string_finish_8020c5c4(this);
    w3d_string_release_80341588(this);
}
/* Declared void as in the admitted callers of 0x8020c510: its body leaves r3 from a final call, and the receiver-before-format move order needs void. */
extern "C" void w3d_string_format_8020c510(String *, const char *, ...);
struct InventoryView : Object {
    char unknown04[16];
    int count;       /* +20 */
    int slots[11];   /* +24 */
};
extern "C" char w3d_string_8037de84[];
extern "C" char w3d_string_8037de98[];

inline void Acquire(Held &current, Object *object)
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
        InventoryView *view = (InventoryView *)current.value;
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
        InventoryView *view = (InventoryView *)current.value;
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
