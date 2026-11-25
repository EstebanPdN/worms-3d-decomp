#include "w3d_ptr.h"
#line 1 "d24b_landmine_spawn_8008bc78.cpp"
/* Landmine spawn (0x8008bc78): reads kWeaponLandmine into a handle, creates the
 * mine object (0x8020b680, type 0x8040fd78) and retains it, passes the handle by
 * value to 0x800eb65c and the position to 0x800eb8d0, sets +308 when setting +284
 * is zero and +92 with the probability +268, sets the fuse +32 to a random value
 * between settings +272 and +276, registers the object (0x80164514), stores the
 * returned id in setting +280 and appends it to the array at +332. Field and type
 * names are inferred from the original instructions. Strings and globals are
 * external views of original data. */
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
    template <class W3dU> Handle(Ptr32<W3dU> w3d_p) : Handle((Object *)w3d_p.get()) {}
 Handle(Object *o) { value = o; if (value) value->vtable->retain(value); }
    ~Handle() { if (value) value->vtable->release(value); }
private:
    Handle(const Handle &);
};
/* Reference passed by value; the callee releases it. */
struct ValueRef {
    Ptr32<Object> value;
    template <class W3dU> ValueRef(Ptr32<W3dU> w3d_p) : ValueRef((Object *)w3d_p.get()) {}
 ValueRef(Object *o) { value = o; if (value) value->vtable->retain(value); }
    ValueRef(const ValueRef &);
};
struct PropertyKey { Ptr32<const char> name; };
struct Mine : Object {
    char unknown04[28] __attribute__((aligned(__alignof__(Object))));
    int fuse;       /* +32 */
    char unknown36[56];
    int triggered;  /* +92 */
    char unknown96[212];
    int silent;     /* +308 */
};
extern "C" Ptr32<char> w3d_allocate_80212fd4(unsigned);
extern "C" void w3d_release_802134fc(Ptr32<void>);
extern "C" Ptr32<void> w3d_copy_802eee50(...);
template <class T> inline const T &maximum(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &minimum(const T &a, const T &b) { return b < a ? b : a; }
struct IntArray {
    Ptr32<int> begin; Ptr32<int> end; Ptr32<int> capacity;
    void push(const int &value) {
        if (end == capacity) {
            unsigned old = (Ptr32<char>)end - (Ptr32<char>)begin;
            int one = old + 1, grow = old + (old >> 1);
            unsigned bytes = maximum(one, grow) << 2;
            Ptr32<char> p = w3d_allocate_80212fd4(bytes);
            if (begin) {
                w3d_copy_802eee50(w3d::VA(p), w3d::VA(begin), minimum(bytes, old));
                w3d_release_802134fc(begin);
            }
            begin = (Ptr32<int>)p;
            end = (Ptr32<int>)(p + old);
            capacity = (Ptr32<int>)(p + bytes);
        }
        *end = value;
        end++;
    }
};
struct Spawner {
    char unknown00[20];
    int id;              /* +20 */
    char unknown24[244];
    Ptr32<Object> probability; /* +268 */
    Ptr32<Object> fuseMin;     /* +272 */
    Ptr32<Object> fuseMax;     /* +276 */
    Ptr32<Object> lastId;      /* +280 */
    Ptr32<Object> silent;      /* +284 */
    char unknown288[44];
    IntArray mines;      /* +332 */
};
extern "C" int w3d_resource_property_800fc1b0(Ptr32<PropertyKey>, Ptr32<Ptr32<Object>>);
extern "C" Ptr32<Mine> w3d_service_forward_8020b680(Ptr32<void>);
extern "C" Ptr32<void> w3d_identity_80341584(Ptr32<Object>);
extern "C" Ptr32<void> w3d_as_weapon_801797b4(Ptr32<void>);
extern "C" void w3d_assign_interface_800eb65c(Ptr32<Mine>, ValueRef);
extern "C" void w3d_copy12_800eb8d0(Ptr32<Mine>, Ptr32<void>);
extern "C" Ptr32<Object> w3d_identity_80342a78(Ptr32<Object>);
extern "C" Ptr32<Object> w3d_identity_80342a74(Ptr32<Object>);
extern "C" int w3d_int_value_80178d1c(Ptr32<Object>);
extern "C" float w3d_float_value_80178df0(Ptr32<Object>);
extern "C" int w3d_set_value_80178d28(Ptr32<Object>, Ptr32<int>);
extern "C" float w3d_random_80162bc8();
extern "C" int w3d_register_80164514(Ptr32<void>, Ptr32<Mine>, int);
extern Ptr32<void> w3d_manager_804b178c;
extern unsigned char w3d_type_8040fd78[];
extern "C" char w3d_string_8037d1d4[]; /* "kWeaponLandmine" */

extern "C" void w3d_d24b_landmine_spawn_8008bc78(Ptr32<Spawner> self, Ptr32<void> position)
{
    Handle handle;
    PropertyKey key;
    key.name = w3d_string_8037d1d4;
    handle.value = 0;
    w3d_resource_property_800fc1b0(&key, &handle.value);
    Handle mine(w3d_service_forward_8020b680(w3d_type_8040fd78));
    w3d_as_weapon_801797b4(w3d_identity_80341584(handle.value));
    w3d_assign_interface_800eb65c((Ptr32<Mine>)mine.value, ValueRef(handle.value));
    w3d_copy12_800eb8d0((Ptr32<Mine>)mine.value, position);
    bool armed = w3d_int_value_80178d1c(w3d_identity_80342a78(self->silent)) != 0;
    ((Ptr32<Mine>)mine.value)->silent = !armed;
    float roll = w3d_random_80162bc8();
    if (roll < w3d_float_value_80178df0(w3d_identity_80342a74(self->probability)))
        ((Ptr32<Mine>)mine.value)->triggered = 1;
    roll = w3d_random_80162bc8();
    int low = w3d_int_value_80178d1c(w3d_identity_80342a78(self->fuseMin));
    unsigned range = w3d_int_value_80178d1c(w3d_identity_80342a78(self->fuseMax)) - low;
    ((Ptr32<Mine>)mine.value)->fuse = low + (int)(roll * (float)range);
    int id = w3d_register_80164514(w3d_manager_804b178c, (Ptr32<Mine>)mine.value, self->id);
    w3d_set_value_80178d28(w3d_identity_80342a78(self->lastId), &id);
    self->mines.push(id);
}


