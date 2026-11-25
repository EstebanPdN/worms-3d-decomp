/* Weapon selection set-up (0x8001a7f8): stores the weapon index (0x8001a758)
 * and the eye/target vectors (0x8001a770), looks the weapon record up by
 * the weapon's type name (table 0x803eb63c, e.g. "kWeaponBazooka") and
 * keeps it in the weapon state, publishes two derived record values
 * (+188 plus +184, and +188), then builds the aiming offset: a gravity term
 * read from "Gravity.Slow" or "Gravity" and scaled by
 * "Low.Gravity.Multiplier" when the record's gravity flag (+528) is 1, plus
 * the wind vector (0x8001a9a0) when the wind flag (+480) is 1. The camera
 * object 0x8041e780 then gets the eye vector and the offset. Field and type
 * names are inferred from the original instructions. Strings, the 0.0f
 * constant and all globals are external views of original data; the unit
 * owns no data.
 *
 * The weapon index/record pair 0x804aa778/0x804aa77c is one structure: as a
 * structure-member store the record pointer store stays before the record
 * field loads, as in the original. The property keys are explicit locals
 * declared before each call so that their stack slots precede those of the
 * address-taken floats. */
struct String {
    char *text;
    String(const char *);
    ~String();
};
extern "C" void w3d_string_base_finish_8020c5c4(String *);
extern "C" void w3d_string_release_80341588(String *);
inline String::~String() {
    w3d_string_base_finish_8020c5c4(this);
    w3d_string_release_80341588(this);
}
struct Vector3 {
    float x, y, z;
    Vector3() {}
    void Set(float a, float b, float c) { x = a; y = b; z = c; }
};
struct PropertyKey { const char *name; };
struct WeaponRecord {
    char unknown000[184];
    float value184;
    float value188;
    char unknown0c0[480 - 192];
    int windAffected;      /* +480 */
    char unknown1e4[516 - 484];
    int slowGravity;       /* +516 */
    char unknown208[528 - 520];
    int gravityAffected;   /* +528 */
};
struct WeaponRange { float sum; float last; };
struct Camera;

extern "C" void w3d_set_weapon_index_8001a758(int);
extern "C" void w3d_set_eye_vector_8001a770(Vector3 *, Vector3 *);
extern "C" int w3d_weapon_lookup_800fc330(PropertyKey *, WeaponRecord **);
extern "C" int w3d_float_property_800fc270(PropertyKey *, float *);
extern "C" Vector3 w3d_wind_vector_8001a9a0(void);
extern "C" void w3d_camera_set_eye_80118230(Camera *, Vector3 *);
extern "C" void w3d_camera_set_target_80118288(Camera *, Vector3 *);
struct WeaponState { int index; WeaponRecord *record; };
extern WeaponState w3d_weapon_state_804aa778;
extern WeaponRange w3d_weapon_range_804b1770;
extern const char *w3d_weapon_names_803eb63c[];
extern Camera w3d_camera_8041e780;
extern Vector3 w3d_eye_vector_8041e844;
extern float w3d_zero_8036af94[];
extern "C" char w3d_string_8036af64[]; /* "Gravity.Slow" */
extern "C" char w3d_string_8036af74[]; /* "Gravity" */
extern "C" char w3d_string_8036af7c[]; /* "Low.Gravity.Multiplier" */

extern "C" void w3d_d22a_weapon_select_8001a7f8(int weapon, Vector3 *eye, Vector3 *target)
{
    w3d_set_weapon_index_8001a758(weapon);
    w3d_set_eye_vector_8001a770(eye, target);
    String name(w3d_weapon_names_803eb63c[w3d_weapon_state_804aa778.index]);
    PropertyKey key;
    key.name = name.text;
    WeaponRecord *record;
    w3d_weapon_lookup_800fc330(&key, &record);
    WeaponRecord *weaponRecord = record;
    w3d_weapon_state_804aa778.record = weaponRecord;
    w3d_weapon_range_804b1770.sum = weaponRecord->value188 + weaponRecord->value184;
    w3d_weapon_range_804b1770.last = weaponRecord->value188;
    float gravity = w3d_zero_8036af94[0];
    if (weaponRecord->gravityAffected == 1) {
        if (weaponRecord->slowGravity == 1) {
            PropertyKey slowKey;
            slowKey.name = w3d_string_8036af64;
            w3d_float_property_800fc270(&slowKey, &gravity);
        } else {
            PropertyKey gravityKey;
            gravityKey.name = w3d_string_8036af74;
            w3d_float_property_800fc270(&gravityKey, &gravity);
        }
        float multiplier = w3d_zero_8036af94[0];
        PropertyKey multiplierKey;
        multiplierKey.name = w3d_string_8036af7c;
        w3d_float_property_800fc270(&multiplierKey, &multiplier);
        gravity *= multiplier;
    }
    Vector3 offset;
    Vector3 *p = &offset;
    p->Set(w3d_zero_8036af94[0], w3d_zero_8036af94[0], w3d_zero_8036af94[0]);
    if (w3d_weapon_state_804aa778.record->windAffected == 1)
        offset = w3d_wind_vector_8001a9a0();
    offset.y += gravity;
    w3d_camera_set_eye_80118230(&w3d_camera_8041e780, &w3d_eye_vector_8041e844);
    w3d_camera_set_target_80118288(&w3d_camera_8041e780, &offset);
}
