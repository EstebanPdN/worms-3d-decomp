#include "w3d_ptr.h"
#line 1 "d20a_bomber_position_8002f098.cpp"
/* Bomber start position (0x8002f098): reads the gravity, gravity multiplier,
 * extra height, landing maximum height and ground speed properties through
 * the float property reader 0x800fc270, then places the bomber at the
 * destination height and, unless the owner's mode flag (+480) is set, backs
 * it off along the normalized direction by the distance covered at ground
 * speed during the fall time. Field and type names are inferred from the
 * original instructions. The property names live in the .rodata of the
 * original translation unit (0x80372e34..0x80372e87, and the shared
 * "Bomber.GroundSpeed" at 0x80372d2c); they are external views here because
 * the translation unit's earlier .rodata owners are not recovered. The
 * 0.0f, 1.0f and int-to-float constants (0x80372e88..0x80372e97) are this
 * function's own pool. Built with -mps-float. */
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec3 operator*(float f) const { Vec3 r; r.x = x * f; r.y = y * f; r.z = z * f; return r; }
    Vec3 operator-(const Vec3 &o) const { Vec3 r; r.x = x - o.x; r.y = y - o.y; r.z = z - o.z; return r; }
    float Length() const;
    void Normalize();
};
extern "C" float w3d_sqrt_802e82c0(float);
inline float Vec3::Length() const { return w3d_sqrt_802e82c0(x * x + y * y + z * z); }
inline void Vec3::Normalize() { float f = 1.0f / Length(); x *= f; y *= f; z *= f; }

struct BomberOwner {
    char unknown000[480];
    int fixed_position;
    char unknown1e4[32];
    int slow_gravity;
};

/* Property names (original .rodata). */
extern "C" char w3d_string_80372e34[]; /* "Gravity.Slow" */
extern "C" char w3d_string_80372e44[]; /* "Gravity" */
extern "C" char w3d_string_80372e4c[]; /* "Low.Gravity.Multiplier" */
extern "C" char w3d_string_80372e64[]; /* "Bomber.ExtraHeight" */
extern "C" char w3d_string_80372e78[]; /* "Land.MaxHeight" */
extern "C" char w3d_string_80372d2c[]; /* "Bomber.GroundSpeed" */

/* Reads the float property named by *name into *value; returns a status. */
extern "C" int w3d_float_property_800fc270(Ptr32<Ptr32<const char>> name, Ptr32<float> value);

extern "C" Vec3 w3d_d20a_bomber_position_8002f098(Ptr32<BomberOwner> owner, Ptr32<const Vec3> position, Ptr32<const Vec3> direction)
{
    float gravity;
    if (owner->slow_gravity) {
        Ptr32<const char> name = w3d_string_80372e34;
        w3d_float_property_800fc270(&name, &gravity);
    } else {
        Ptr32<const char> name = w3d_string_80372e44;
        w3d_float_property_800fc270(&name, &gravity);
    }
    Ptr32<const char> multiplierName = w3d_string_80372e4c;
    float multiplier = 0.0f;
    w3d_float_property_800fc270(&multiplierName, &multiplier);
    float offset = 0.0f;
    gravity *= multiplier;
    Ptr32<const char> extraName = w3d_string_80372e64;
    float extraHeight;
    w3d_float_property_800fc270(&extraName, &extraHeight);
    Ptr32<const char> heightName = w3d_string_80372e78;
    float maxHeight;
    w3d_float_property_800fc270(&heightName, &maxHeight);
    float destinationHeight = maxHeight + extraHeight;
    Vec3 normal(*direction);
    normal.Normalize();
    Ptr32<const char> speedName = w3d_string_80372d2c;
    float groundSpeed;
    w3d_float_property_800fc270(&speedName, &groundSpeed);
    if (!owner->fixed_position) {
        float drop = destinationHeight - position->y;
        int ticks = (int)w3d_sqrt_802e82c0((drop + drop) / -gravity);
        offset = groundSpeed * (float)ticks + offset;
    }
    Vec3 result = *position - normal * offset;
    result.y = destinationHeight;
    return result;
}


