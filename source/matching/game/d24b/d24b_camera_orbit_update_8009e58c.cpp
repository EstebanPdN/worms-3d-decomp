/* Camera orbit update (0x8009e58c): takes the target position and angle of the active
 * worm (index from +56, 0x80178c48, 0x800fc6dc; +80 position, +68 angles) or a zero
 * vector when none, keeps the height at least setting +64 minus +84, adds setting +76,
 * derives the view direction from the yaw (sin, cos) plus pi and places the eye at the
 * position plus the direction. Field and type names are inferred from the original
 * instructions. Owns its float literals at 0x803805b8. */
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) { x = ax; y = ay; z = az; }
    Vec3(const Vec3 &o) { float ax = o.x, ay = o.y, az = o.z; x = ax; y = ay; z = az; }
    void Set(float ax, float ay, float az) { x = ax; y = ay; z = az; }
    Vec3 operator+(const Vec3 &o) const {
        Vec3 r;
        r.x = x + o.x;
        r.y = y + o.y;
        r.z = z + o.z;
        return r;
    }
};
extern "C" float w3d_sinf_802e88ac(float);
extern "C" float w3d_cosf_802e86d4(float);
extern "C" int w3d_int_value_80178c48(void *);
extern "C" float w3d_float_value_80178df0(void *);
extern "C" char *w3d_index_query_800fc6dc(int);
struct Orbit {
    char unknown00[4];
    Vec3 position;   /* +4 */
    Vec3 eye;        /* +16 */
    Vec3 up;          /* +28 */
    char unknown40[16];
    void *index;      /* +56 */
    char unknown60[4];
    void *height;     /* +64 */
    char unknown68[8];
    void *lift;       /* +76 */
    char unknown80[4];
    void *margin;     /* +84 */
    Vec3 forward;    /* +88 */
    Vec3 direction;  /* +100 */
};
extern "C" void w3d_d24b_camera_orbit_update_8009e58c(Orbit *self)
{
    static Vec3 origin(0.0f, 0.0f, 0.0f);
    Vec3 *angles = &origin;
    Vec3 *source = &origin;
    int index = w3d_int_value_80178c48(self->index);
    if (index >= 0) {
        source = (Vec3 *)(w3d_index_query_800fc6dc(index) + 80);
        angles = (Vec3 *)(w3d_index_query_800fc6dc(index) + 68);
    }
    self->position = *source;
    float limit = w3d_float_value_80178df0(self->height);
    limit -= w3d_float_value_80178df0(self->margin);
    if (self->position.y < limit) self->position.y = limit;
    self->position.y += w3d_float_value_80178df0(self->lift);
    float yaw = angles->y + 3.1415927410125732f;
    self->forward.y = 0.0f;
    self->forward.x = -w3d_sinf_802e88ac(yaw);
    self->forward.z = -w3d_cosf_802e86d4(yaw);
    self->up.Set(0.0f, 1.0f, 0.0f);
    self->direction = self->forward;
    self->eye = self->position + self->direction;
}
