/* Homing projectile steering (0x8009f4dc): takes the direction from the position (+36) to
 * the target (+308) and, unless zero, accelerates the velocity (+48) along it by the
 * weapon's acceleration (+560 of the description cast from +192) times the frame time
 * 0x804b1944, then limits the speed to the weapon's maximum (+564). Field and type names
 * are inferred from the original instructions. Owns its literals at 0x80380778. */
extern "C" void *w3d_identity_80341584(void *);
extern "C" char *w3d_as_weapon_801797b4(void *);
extern "C" float w3d_sqrtf_802e82c0(float);
template <class T> inline const T &minimum(const T &a, const T &b) { return b < a ? b : a; }
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3 &o) { float ax = o.x, ay = o.y, az = o.z; x = ax; y = ay; z = az; }
    Vec3 operator-(const Vec3 &o) const {
        Vec3 r;
        r.x = x - o.x;
        r.y = y - o.y;
        r.z = z - o.z;
        return r;
    }
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
    float Length() const { return w3d_sqrtf_802e82c0(x * x + y * y + z * z); }
    void Normalize() {
        float k = 1.0f / Length();
        x *= k;
        y *= k;
        z *= k;
    }
};
struct Weapon { char unknown00[560]; float acceleration; float maxSpeed; };
struct Homing {
    char unknown00[36];
    Vec3 position;   /* +36 */
    Vec3 velocity;   /* +48 */
    char unknown60[132];
    void *owner;     /* +192 */
    char unknown196[112];
    Vec3 target;     /* +308 */
};
extern unsigned w3d_frame_time_804b1944;
extern "C" void w3d_d24b_homing_steer_8009f4dc(Homing *self)
{
    Weapon *weapon = (Weapon *)w3d_as_weapon_801797b4(w3d_identity_80341584(self->owner));
    Vec3 direction = self->target - self->position;
    if (direction.Length() != 0.0f) {
        direction.Normalize();
        Vec3 accel = direction * weapon->acceleration;
        self->velocity = self->velocity + accel * (float)w3d_frame_time_804b1944;
        float speed = self->velocity.Length();
        const float *from = &weapon->maxSpeed;
        float limit = *from;
        speed = minimum(speed, limit);
        Vec3 unit(self->velocity);
        unit.Normalize();
        self->velocity = unit * speed;
    }
}
