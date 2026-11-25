/* d19c: 0x800dcbe0 (616 bytes). Randomise a particle velocity (+12): each
 * component is base + spread * (2r - 1) for a unit random r, taken from the
 * shared generator (0x80162bc8) when +108 is set, otherwise from the local
 * linear congruential seed (x * 1103515245 + 12345, scaled by 2^-32). With
 * normalize, the vector is made unit length and scaled by base.x + spread.x;
 * a non-zero scale multiplies it again. Meanings are inferred (from m2c).
 * Built with -mps-float: the scale stays in f31 across calls and the
 * unflagged build differed only by the 8-byte frame gap below the register
 * save area. The float parameter comes before the int flag in the prototype
 * (same registers; it reproduces the original order of the parameter copies). */
typedef struct d19c_Vec3 { float x, y, z; } d19c_Vec3;
typedef struct d19c_Particle {
    unsigned char unknown00[12];
    d19c_Vec3 velocity;                  /* +12 */
    unsigned char unknown24[84];
    int shared_random;                   /* +108 */
} d19c_Particle;
extern float d19c_random_unit_80162bc8(void);
extern float d19c_sqrtf_802e82c0(float);
extern unsigned d19c_local_seed_804aec54;

static inline float d19c_particle_random(d19c_Particle *self)
{
    if (self->shared_random)
        return d19c_random_unit_80162bc8();
    d19c_local_seed_804aec54 = d19c_local_seed_804aec54 * 1103515245 + 12345;
    return (float)d19c_local_seed_804aec54 * 2.3283064e-10f;
}

void d19c_particle_random_velocity_800dcbe0(d19c_Particle *self, const d19c_Vec3 *base, const d19c_Vec3 *spread, float scale, int normalize)
{
    float r;
    r = d19c_particle_random(self);
    self->velocity.x = 2.0f * (r - 0.5f) * spread->x + base->x;
    r = d19c_particle_random(self);
    self->velocity.y = 2.0f * (r - 0.5f) * spread->y + base->y;
    r = d19c_particle_random(self);
    self->velocity.z = 2.0f * (r - 0.5f) * spread->z + base->z;
    if (normalize) {
        d19c_Vec3 *v = &self->velocity;
        float y = v->y;
        float x = self->velocity.x;
        float z = v->z;
        float factor = 1.0f / d19c_sqrtf_802e82c0(z * z + (x * x + y * y));
        float size;
        self->velocity.x *= factor;
        v->y *= factor;
        v->z *= factor;
        size = base->x + spread->x;
        self->velocity.x *= size;
        v->y *= size;
        v->z *= size;
    }
    if (scale != 0.0f) {
        d19c_Vec3 *v = &self->velocity;
        self->velocity.x *= scale;
        v->y *= scale;
        v->z *= scale;
    }
}
