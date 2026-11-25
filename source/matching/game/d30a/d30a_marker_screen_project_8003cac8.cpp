// GWMP8P rev0 0x8003cac8. Projects a world point to screen coordinates for
// an on-screen marker, clamped to the 960-wide frame: visible points get an
// unrotated icon and an upward offset, off-screen points get the icon
// rotated toward them, and points behind the camera are pushed to the
// nearest screen edge. Returns the screen position. Names are inferred from
// the original instructions.
extern "C" float atan2_802e7e5c(float, float);
inline float Abs(float v) { return __builtin_fabsf(v); }
inline float Limit(float v) { return 480.0f - __builtin_fabsf(v); }
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Iface;
typedef void (*SetV)(Iface *, const Vec *, int);
struct Table { char pad[80]; SetV set; };
struct Iface { Table *t; };
struct Marker { char pad[28]; Iface *icon; };
extern "C" void w3d_auto_8003ce84(Marker *);
extern "C" int s19_handle_is_one_8003cf8c(Marker *);
extern "C" int w3d_k10a_camera_near_8003cfcc(Marker *);
extern "C" int w3d_auto_8003cfbc(Marker *);
extern "C" void w3d_auto_8003cef0(Marker *);
extern "C" Vec w3d_d30a_marker_screen_project_8003cac8(Marker *self, const Vec *p)
{
    Vec s;
    int vis = 1;
    int behind = 0;
    if (p->z > 0.0f) {
        s.x = p->x * 500.0f / p->z;
        s.y = p->y * 500.0f / p->z;
        s.z = 500.0f;
    } else if (p->z < 0.0f) {
        vis = 0;
        behind = 1;
        float z = -p->z;
        s.x = p->x * 500.0f / z;
        s.y = p->y * 500.0f / z;
        s.z = 500.0f;
    }
    if (s.x < -480.0f) { s.x = -480.0f; vis = 0; } else if (s.x > 480.0f) { s.x = 480.0f; vis = 0; }
    if (s.y < -480.0f) { s.y = -480.0f; vis = 0; } else if (s.y > 480.0f) { s.y = 480.0f; vis = 0; }
    if (vis) {
        Vec zero(0.0f, 0.0f, 0.0f);
        self->icon->t->set(self->icon, &zero, 0);
        s.y += 30.0f;
        if (p->z < 190.0f && p->z != 0.0f) s.y += 19000.0f / p->z;
    } else {
        atan2_802e7e5c(s.x - p->x, s.y - p->y);
        float a = atan2_802e7e5c(-p->x, -p->y);
        Vec rot(0.0f, 0.0f, -a);
        self->icon->t->set(self->icon, &rot, 0);
    }
    if (behind) {
        float hi = 480.0f;
        float dx = hi - Abs(s.x), dy = hi - Abs(s.y);
        if (dx != 0.0f && dy != 0.0f) {
            if (dy < dx) { if (s.y > 0.0f) s.y = hi; else s.y = -480.0f; }
            else { if (s.x > 0.0f) s.x = hi; else s.x = -480.0f; }
        }
    }
    if (vis) {
        w3d_auto_8003ce84(self);
    } else if (!s19_handle_is_one_8003cf8c(self) && !w3d_k10a_camera_near_8003cfcc(self) && !w3d_auto_8003cfbc(self)) {
        w3d_auto_8003cef0(self);
    }
    return s;
}
