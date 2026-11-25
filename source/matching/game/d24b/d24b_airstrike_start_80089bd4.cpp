/* Airstrike start (0x80089bd4): copies the team list 0x8043bb64, finds the worm
 * named by Airstrike.TargetEntity, publishes its position, the
 * direction vector built from Airstrike.Direction.Radians (cos, 0, sin) and the
 * up vector (0, 1, 0), reads the weapon name, creates the strike object
 * (0x8020b680, type 0x8040e4a8), loads the weapon resource by name (0x800fc1b0),
 * passes it by value to 0x8002f6dc and registers the object (0x80164514). Field
 * and type names are inferred from the original instructions. Strings and globals
 * are external views of original data; the unit owns its two float literals at
 * 0x8037d928. */
extern "C" char *w3d_allocate_80212fd4(unsigned);
extern "C" void w3d_release_802134fc(void *);
extern "C" void *w3d_copy_802eee50(...);
extern "C" int w3d_strcmp_802ef234(const char *, const char *);
extern "C" float w3d_cosf_802e86d4(float);
extern "C" float w3d_sinf_802e88ac(float);
struct String {
    char *text;
    String(const char *text);
    String(const String &);
    ~String();
};
extern "C" void w3d_string_finish_8020c5c4(String *);
extern "C" void w3d_string_release_80341588(String *);
inline String::~String() {
    w3d_string_finish_8020c5c4(this);
    w3d_string_release_80341588(this);
}
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
struct ValueRef {
    Object *value;
    ValueRef(Object *o) { value = o; if (value) value->vtable->retain(value); }
    ValueRef(const ValueRef &);
};
struct PropertyKey {
    const char *name;
    PropertyKey() {}
    PropertyKey(const char *n) { name = n; }
};
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) { x = ax; y = ay; z = az; }
    Vec3(const Vec3 &o) { float ax = o.x, ay = o.y, az = o.z; x = ax; y = ay; z = az; }
};
struct Worm { char unknown00[4]; Vec3 position; char unknown16[44]; const char *name; };
template <class T>
struct List {
    T *begin, *end, *capacity;
    List() {}
    ~List() { if (begin) w3d_release_802134fc(begin); }
    unsigned size() const { return end - begin; }
    T &operator[](unsigned i) { return begin[i]; }
};
struct Team { char unknown00[20]; List<Worm *> worms; };
extern List<Team *> w3d_teams_8043bb64;
struct Airstrike { char unknown00[20]; int id; /* +20 */ };
extern "C" int w3d_vector_write_800fc5dc(PropertyKey *, const Vec3 *);
extern "C" int w3d_float_read_800fc270(PropertyKey *, float *);
extern "C" int w3d_string_read_800fc2b0(PropertyKey *, PropertyKey *);
extern "C" int w3d_resource_property_800fc1b0(PropertyKey *, Object **);
extern "C" Object *w3d_service_forward_8020b680(void *);
extern "C" void w3d_assign_interface_8002f6dc(Object *, ValueRef);
extern "C" int w3d_register_80164514(void *, Object *, int);
extern void *w3d_manager_804b178c;
extern unsigned char w3d_type_8040e4a8[];
inline Object *CreateStrike(void *type) { return w3d_service_forward_8020b680(type); }
extern "C" char w3d_string_8037d898[]; /* "Airstrike.TargetEntity" */
extern "C" char w3d_string_8037d8b0[]; /* "Airstrike.TargetPoint" */
extern "C" char w3d_string_8037d8c8[]; /* "Airstrike.Direction.Radians" */
extern "C" char w3d_string_8037d8e4[]; /* "Airstrike.Direction" */
extern "C" char w3d_string_8037d8f8[]; /* "Airstrike.UpVector" */
extern "C" char w3d_string_8037d90c[]; /* "Airstrike.WeaponProperties" */

extern "C" void w3d_d24b_airstrike_start_80089bd4(Airstrike *self)
{
    List<Team *> teams;
    {
        unsigned n = (char *)w3d_teams_8043bb64.end - (char *)w3d_teams_8043bb64.begin;
        Team **p = (Team **)w3d_allocate_80212fd4(n);
        Team **e = (Team **)((char *)p + n);
        teams.begin = p;
        teams.end = e;
        teams.capacity = e;
        w3d_copy_802eee50(p, w3d_teams_8043bb64.begin, n);
    }
    PropertyKey wormKey;
    wormKey.name = w3d_string_8037d898;
    PropertyKey wormName;
    w3d_string_read_800fc2b0(&wormKey, &wormName);
    for (unsigned i = 0; i < teams.size(); i++) {
        List<Worm *> &worms = teams[i]->worms;
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
