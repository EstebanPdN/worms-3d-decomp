// GWMP8P rev0 0x80266234. Round button hit test of the radius family (see
// s11radius units): hidden returns 0, an override dispatches to the panel
// test, otherwise the distance from the button origin is compared to half
// the scaled width. Names are inferred from use. Built with -mps-float:
// frame gap only without it; no padding local.
struct Vec3 {
 float x, y, z;
 Vec3() {}
 Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
 Vec3(const Vec3 &v) { float a = v.x, b = v.y, c = v.z; x = a; y = b; z = c; }
 Vec3 operator*(const Vec3 &v) const { Vec3 result(x * v.x, y * v.y, z * v.z); return result; }
 float distance_squared(const Vec3 &v) const { float a = x - v.x, b = y - v.y, c = z - v.z; return c * c + (a * a + b * b); }
};
struct ScaleObject;
struct ScaleTable { void (*unused[27])(); const Vec3 *(*get_scale)(ScaleObject *); };
struct ScaleObject { ScaleTable *vtable; };
struct Config { char u[20]; Vec3 scale; };
struct Owner { char u[40]; Config *config; char u44[68]; ScaleObject *graphic; char u116[24]; int visible; char u144[288]; int override_hit; };
extern "C" int fn_802b15e0(void *, float, float);
extern "C" void fn_802b22e4(Vec3 *, void *);
extern "C" float fn_802e82c0(float);
extern float lbl_803cb5c4[], lbl_803cb5c8[];
extern "C" int lbl_804abb4c;
extern "C" int w3d_d30k_button_radius_test_80266234(Owner *owner, float x, float y) {
 if (!owner->visible) return 0;
 if (owner->override_hit == 1) return fn_802b15e0((char *)owner + 28, x, y);
 if (lbl_804abb4c == 1) return 0;
 Vec3 origin;
 fn_802b22e4(&origin, (char *)owner + 28);
 Vec3 scale(*owner->graphic->vtable->get_scale(owner->graphic));
 Vec3 extent(owner->config->scale);
 extent = extent * scale;
 Vec3 point(x, y, origin.z);
 extent.x *= lbl_803cb5c4[0];
 float distance = fn_802e82c0(point.distance_squared(origin));
 if (distance < lbl_803cb5c8[0]) distance = -distance;
 if (extent.x < lbl_803cb5c8[0]) extent.x = -extent.x;
 return distance <= extent.x;
}
