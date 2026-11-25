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
    void *unknown00[3];
    void (*retain)(Object *);   /* +12 */
    void (*release)(Object *);  /* +16 */
};
struct Object { ObjectVtable *vtable; };
struct Handle {
    Object *value;
    Handle() {}
    Handle(Object *o) { value = o; if (value) value->vtable->retain(value); }
    ~Handle() { if (value) value->vtable->release(value); }
private:
    Handle(const Handle &);
};
/* Reference passed by value; the callee releases it. */
struct ValueRef {
    Object *value;
    ValueRef(Object *o) { value = o; if (value) value->vtable->retain(value); }
    ValueRef(const ValueRef &);
};
struct PropertyKey { const char *name; };
struct Mine : Object {
    char unknown04[28];
    int fuse;       /* +32 */
    char unknown36[56];
    int triggered;  /* +92 */
    char unknown96[212];
    int silent;     /* +308 */
};
extern "C" char *w3d_allocate_80212fd4(unsigned);
extern "C" void w3d_release_802134fc(void *);
extern "C" void *w3d_copy_802eee50(...);
template <class T> inline const T &maximum(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &minimum(const T &a, const T &b) { return b < a ? b : a; }
struct IntArray {
    int *begin, *end, *capacity;
    void push(const int &value) {
        if (end == capacity) {
            unsigned old = (char *)end - (char *)begin;
            int one = old + 1, grow = old + (old >> 1);
            unsigned bytes = maximum(one, grow) << 2;
            char *p = w3d_allocate_80212fd4(bytes);
            if (begin) {
                w3d_copy_802eee50(p, begin, minimum(bytes, old));
                w3d_release_802134fc(begin);
            }
            begin = (int *)p;
            end = (int *)(p + old);
            capacity = (int *)(p + bytes);
        }
        *end = value;
        end++;
    }
};
struct Spawner {
    char unknown00[20];
    int id;              /* +20 */
    char unknown24[244];
    Object *probability; /* +268 */
    Object *fuseMin;     /* +272 */
    Object *fuseMax;     /* +276 */
    Object *lastId;      /* +280 */
    Object *silent;      /* +284 */
    char unknown288[44];
    IntArray mines;      /* +332 */
};
extern "C" int w3d_resource_property_800fc1b0(PropertyKey *, Object **);
extern "C" Mine *w3d_service_forward_8020b680(void *);
extern "C" void *w3d_identity_80341584(Object *);
extern "C" void *w3d_as_weapon_801797b4(void *);
extern "C" void w3d_assign_interface_800eb65c(Mine *, ValueRef);
extern "C" void w3d_copy12_800eb8d0(Mine *, void *);
extern "C" Object *w3d_identity_80342a78(Object *);
extern "C" Object *w3d_identity_80342a74(Object *);
extern "C" int w3d_int_value_80178d1c(Object *);
extern "C" float w3d_float_value_80178df0(Object *);
extern "C" int w3d_set_value_80178d28(Object *, int *);
extern "C" float w3d_random_80162bc8();
extern "C" int w3d_register_80164514(void *, Mine *, int);
extern void *w3d_manager_804b178c;
extern unsigned char w3d_type_8040fd78[];
extern "C" char w3d_string_8037d1d4[]; /* "kWeaponLandmine" */

extern "C" void w3d_d24b_landmine_spawn_8008bc78(Spawner *self, void *position)
{
    Handle handle;
    PropertyKey key;
    key.name = w3d_string_8037d1d4;
    handle.value = 0;
    w3d_resource_property_800fc1b0(&key, &handle.value);
    Handle mine(w3d_service_forward_8020b680(w3d_type_8040fd78));
    w3d_as_weapon_801797b4(w3d_identity_80341584(handle.value));
    w3d_assign_interface_800eb65c((Mine *)mine.value, ValueRef(handle.value));
    w3d_copy12_800eb8d0((Mine *)mine.value, position);
    bool armed = w3d_int_value_80178d1c(w3d_identity_80342a78(self->silent)) != 0;
    ((Mine *)mine.value)->silent = !armed;
    float roll = w3d_random_80162bc8();
    if (roll < w3d_float_value_80178df0(w3d_identity_80342a74(self->probability)))
        ((Mine *)mine.value)->triggered = 1;
    roll = w3d_random_80162bc8();
    int low = w3d_int_value_80178d1c(w3d_identity_80342a78(self->fuseMin));
    unsigned range = w3d_int_value_80178d1c(w3d_identity_80342a78(self->fuseMax)) - low;
    ((Mine *)mine.value)->fuse = low + (int)(roll * (float)range);
    int id = w3d_register_80164514(w3d_manager_804b178c, (Mine *)mine.value, self->id);
    w3d_set_value_80178d28(w3d_identity_80342a78(self->lastId), &id);
    self->mines.push(id);
}
