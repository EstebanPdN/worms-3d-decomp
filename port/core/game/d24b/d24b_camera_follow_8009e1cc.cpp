#include "w3d_ptr.h"
#line 1 "d24b_camera_follow_8009e1cc.cpp"
/* Camera follow step (0x8009e1cc): for an active worm (index setting +56, at most 16,
 * flag +220 of 0x800fc6dc) whose height exceeds setting +64 minus +84: copies its position
 * (+80) to +4, adds setting +76, computes the look direction from pitch (+68 +4, +144) and
 * yaw (+116, +148), blends the current direction +100 and the eye +16 by setting +80,
 * rebuilds the side vector and blends the up vector +28. Field and type names are inferred
 * from the original instructions. Owns its float literals at 0x803805ac. */
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) { x = ax; y = ay; z = az; }
    Vec3(const Vec3 &o) { float ax = o.x, ay = o.y, az = o.z; x = ax; y = ay; z = az; }
    Vec3 operator+(const Vec3 &o) const {
        Vec3 r;
        r.x = x + o.x;
        r.y = y + o.y;
        r.z = z + o.z;
        return r;
    }
    Vec3 operator*(float k) const {
        Vec3 r;
        r.x = x * k;
        r.y = y * k;
        r.z = z * k;
        return r;
    }
    void Cross(const Vec3 &o, Vec3 &r) const {
        r.x = y * o.z - z * o.y;
        r.y = z * o.x - x * o.z;
        r.z = x * o.y - y * o.x;
    }
    float Dot() const { return x * x + y * y + z * z; }
};
extern "C" float w3d_sqrtf_802e82c0(float);
extern "C" float w3d_sinf_802e88ac(float);
extern "C" float w3d_cosf_802e86d4(float);
extern "C" int w3d_int_value_80178c48(Ptr32<void>);
extern "C" float w3d_float_value_80178df0(Ptr32<void>);
extern "C" Ptr32<char> w3d_index_query_800fc6dc(int);
inline float SelfDot(const Vec3 &v) { return v.Dot(); }
struct Follow {
    char unknown00[4];
    Vec3 position;   /* +4 */
    Vec3 eye;        /* +16 */
    Vec3 up;         /* +28 */
    char unknown40[16];
    Ptr32<void> index;     /* +56 */
    char unknown60[4];
    Ptr32<void> height;    /* +64 */
    char unknown68[8];
    Ptr32<void> lift;      /* +76 */
    Ptr32<void> blend;     /* +80 */
    Ptr32<void> margin;    /* +84 */
    Vec3 forward;    /* +88 */
    Vec3 direction;  /* +100 */
};
struct Target { char unknown00[68]; Vec3 angles; Vec3 position; };
extern "C" void w3d_franco_headcam_tick(void);   // Port (francotirador de UM): zoom de UM HeadCam::Update 0x528d70
extern "C" void w3d_d24b_camera_follow_8009e1cc(Ptr32<Follow> self)
{
    w3d_franco_headcam_tick();
    unsigned index = w3d_int_value_80178c48(self->index);
    if (index > 16) return;
    if (*(Ptr32<int>)(w3d_index_query_800fc6dc(index) + 220) == 0) return;
    Ptr32<Target> target = (Ptr32<Target>)w3d_index_query_800fc6dc(index);
    Ptr32<Vec3> position = &target->position;
    float limit = w3d_float_value_80178df0(self->height);
    limit -= w3d_float_value_80178df0(self->margin);
    if (position->y <= limit) return;
    Ptr32<Vec3> angles = (Ptr32<Vec3>)(w3d_index_query_800fc6dc(index) + 68);
    float pitchOffset = *(Ptr32<float>)(w3d_index_query_800fc6dc(index) + 144);
    float yawOffset = *(Ptr32<float>)(w3d_index_query_800fc6dc(index) + 148);
    self->position = target->position;
    self->position.y += w3d_float_value_80178df0(self->lift);
    float pitch = angles->y + pitchOffset + 3.1415927410125732f;
    float yaw = *(Ptr32<float>)(w3d_index_query_800fc6dc(w3d_int_value_80178c48(self->index)) + 116) + yawOffset;
    float sy = w3d_sinf_802e88ac(yaw);
    float cy = w3d_cosf_802e86d4(yaw);
    float sp = w3d_sinf_802e88ac(pitch);
    float cp = w3d_cosf_802e86d4(pitch);
    self->forward.y = sy;
    float ncy = -cy;
    self->forward.x = ncy * sp;
    self->forward.z = ncy * cp;
    float t = w3d_float_value_80178df0(self->blend);
    float one = 1.0f;
    float inverse = one - t;
    float nsp = -sp;
    {
        Vec3 blended = self->direction * inverse + self->forward * t;
        self->direction = blended;
    }
    {
        Vec3 eye = self->position + self->direction;
        self->eye = eye;
    }
    Vec3 cross;
    Ptr32<Vec3> pc = &cross;
    Vec3 side(cp, 0.0f, nsp);
    side.Cross(self->forward, cross);
    float k = one / w3d_sqrtf_802e82c0(cross.x * cross.x + pc->y * pc->y + pc->z * pc->z);
    cross.x *= k;
    pc->y *= k;
    pc->z *= k;
    Vec3 blended2 = self->up * inverse + cross * t;
    self->up = blended2;
}


