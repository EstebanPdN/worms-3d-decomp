#include "w3d_ptr.h"
#line 1 "d24b_airstrike_start_80089bd4.cpp"
/* Airstrike start (0x80089bd4): copies the team list 0x8043bb64, finds the worm
 * named by Airstrike.TargetEntity, publishes its position, the
 * direction vector built from Airstrike.Direction.Radians (cos, 0, sin) and the
 * up vector (0, 1, 0), reads the weapon name, creates the strike object
 * (0x8020b680, type 0x8040e4a8), loads the weapon resource by name (0x800fc1b0),
 * passes it by value to 0x8002f6dc and registers the object (0x80164514). Field
 * and type names are inferred from the original instructions. Strings and globals
 * are external views of original data; the unit owns its two float literals at
 * 0x8037d928. */
extern "C" Ptr32<char> w3d_allocate_80212fd4(unsigned);
extern "C" void w3d_release_802134fc(Ptr32<void>);
extern "C" Ptr32<void> w3d_copy_802eee50(...);
extern "C" int w3d_strcmp_802ef234(Ptr32<const char>, Ptr32<const char>);
extern "C" float w3d_cosf_802e86d4(float);
extern "C" float w3d_sinf_802e88ac(float);
struct String {
    Ptr32<char> text;
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *text);
    String(const String &);
    ~String();
};
extern "C" void w3d_string_finish_8020c5c4(Ptr32<String>);
extern "C" void w3d_string_release_80341588(Ptr32<String>);
inline String::~String() {
    w3d_string_finish_8020c5c4(this);
    w3d_string_release_80341588(this);
}
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
struct ValueRef {
    Ptr32<Object> value;
    template <class W3dU> ValueRef(Ptr32<W3dU> w3d_p) : ValueRef((Object *)w3d_p.get()) {}
 ValueRef(Object *o) { value = o; if (value) value->vtable->retain(value); }
    ValueRef(const ValueRef &);
};
struct PropertyKey {
    Ptr32<const char> name;
    PropertyKey() {}
    template <class W3dU> PropertyKey(Ptr32<W3dU> w3d_p) : PropertyKey((const char *)w3d_p.get()) {}
 PropertyKey(const char *n) { name = n; }
};
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) { x = ax; y = ay; z = az; }
    Vec3(const Vec3 &o) { float ax = o.x, ay = o.y, az = o.z; x = ax; y = ay; z = az; }
};
struct Worm { char unknown00[4]; Vec3 position; char unknown16[44]; Ptr32<const char> name; };
template <class T>
struct List {
    Ptr32<T> begin; Ptr32<T> end; Ptr32<T> capacity;
    List() {}
    ~List() { if (begin) w3d_release_802134fc(begin); }
    unsigned size() const { return end - begin; }
    T &operator[](unsigned i) { return begin[i]; }
};
struct Team { char unknown00[20]; List <Ptr32<Worm> > worms; };
extern List <Ptr32<Team> > w3d_teams_8043bb64;
struct Airstrike { char unknown00[20]; int id; /* +20 */ };
extern "C" int w3d_vector_write_800fc5dc(Ptr32<PropertyKey>, Ptr32<const Vec3>);
extern "C" int w3d_float_read_800fc270(Ptr32<PropertyKey>, Ptr32<float>);
extern "C" int w3d_string_read_800fc2b0(Ptr32<PropertyKey>, Ptr32<PropertyKey>);
extern "C" int w3d_resource_property_800fc1b0(Ptr32<PropertyKey>, Ptr32<Ptr32<Object>>);
extern "C" Ptr32<Object> w3d_service_forward_8020b680(Ptr32<void>);
extern "C" void w3d_assign_interface_8002f6dc(Ptr32<Object>, ValueRef);
extern "C" int w3d_register_80164514(Ptr32<void>, Ptr32<Object>, int);
extern Ptr32<void> w3d_manager_804b178c;
extern unsigned char w3d_type_8040e4a8[];
inline Ptr32<Object> CreateStrike(Ptr32<void> type) { return w3d_service_forward_8020b680(type); }
extern "C" char w3d_string_8037d898[]; /* "Airstrike.TargetEntity" */
extern "C" char w3d_string_8037d8b0[]; /* "Airstrike.TargetPoint" */
extern "C" char w3d_string_8037d8c8[]; /* "Airstrike.Direction.Radians" */
extern "C" char w3d_string_8037d8e4[]; /* "Airstrike.Direction" */
extern "C" char w3d_string_8037d8f8[]; /* "Airstrike.UpVector" */
extern "C" char w3d_string_8037d90c[]; /* "Airstrike.WeaponProperties" */

extern "C" void w3d_d24b_airstrike_start_80089bd4(Ptr32<Airstrike> self)
{
    List <Ptr32<Team> > teams;
    {
        unsigned n = (Ptr32<char>)w3d_teams_8043bb64.end - (Ptr32<char>)w3d_teams_8043bb64.begin;
        Ptr32<Ptr32<Team>> p = (Ptr32<Ptr32<Team>>)w3d_allocate_80212fd4(n);
        Ptr32<Ptr32<Team>> e = (Ptr32<Ptr32<Team>>)((Ptr32<char>)p + n);
        teams.begin = p;
        teams.end = e;
        teams.capacity = e;
        w3d_copy_802eee50(w3d::VA(p), w3d::VA(w3d_teams_8043bb64.begin), n);
    }
    PropertyKey wormKey;
    wormKey.name = w3d_string_8037d898;
    PropertyKey wormName;
    w3d_string_read_800fc2b0(&wormKey, &wormName);
    for (unsigned i = 0; i < teams.size(); i++) {
        List <Ptr32<Worm> > &worms = teams[i]->worms;
        for (unsigned j = 0; j < worms.size(); j++) {
            String name(worms[j]->name);
            bool same = w3d_strcmp_802ef234(name.text, wormName.name) == 0;
            if (same) {
                Vec3 position(worms[j]->position);
                {
                    PropertyKey key;
                    key.name = w3d_string_8037d8b0;
                    w3d_vector_write_800fc5dc(&key, &position);
                }
                float angle;
                {
                    PropertyKey key;
                    key.name = w3d_string_8037d8c8;
                    w3d_float_read_800fc270(&key, &angle);
                }
                Vec3 direction;
                direction.x = w3d_cosf_802e86d4(angle);
                direction.y = 0.0f;
                direction.z = w3d_sinf_802e88ac(angle);
                {
                    PropertyKey key;
                    key.name = w3d_string_8037d8e4;
                    w3d_vector_write_800fc5dc(&key, &direction);
                }
                Vec3 up(0.0f, 1.0f, 0.0f);
                {
                    PropertyKey key;
                    key.name = w3d_string_8037d8f8;
                    w3d_vector_write_800fc5dc(&key, &up);
                }
                PropertyKey weapon;
                {
                    PropertyKey key;
                    key.name = w3d_string_8037d90c;
                    w3d_string_read_800fc2b0(&key, &weapon);
                }
                Handle strike(CreateStrike(w3d_type_8040e4a8));
                Handle resource;
                resource.value = 0;
                w3d_resource_property_800fc1b0(&weapon, &resource.value);
                w3d_assign_interface_8002f6dc(strike.value, ValueRef(resource.value));
                w3d_register_80164514(w3d_manager_804b178c, strike.value, self->id);
                return;
            }
        }
    }
}


