/* Measures the surface below an object relative to the water level. The
 * object's position vector sits at +40 and the three-float result at +260
 * (observed offsets). The water level setting is read through 0x800fc270
 * with the key string at 0x80376eb0 ("Water.Level", shared with 0x8004a040).
 * The probe direction points straight down with a length of
 * |position.y - world water base| / 1000; 0x800b0824 traces it with range
 * 1000, leaving the hit point at 0x8043ae20 and the hit distance at
 * 0x804b1764. The result is (position.x, hit.y or the water level when the
 * trace ran past its range, position.z). The literals 0.0f and 1000.0f are
 * pooled at 0x8037747c/0x80377478. Names are inferred. */

struct D17aVec3 {
    float x, y, z;
    D17aVec3() {}
    D17aVec3(const D17aVec3 &v) { float a = v.x, b = v.y, c = v.z; x = a; y = b; z = c; }
    D17aVec3 &operator=(const D17aVec3 &v)
    {
        float a = v.x, b = v.y, c = v.z;
        x = a; y = b; z = c;
        return *this;
    }
};

struct D17aSettingKey {
    const char *name;
    D17aSettingKey(const char *n) : name(n) {}
};

struct D17aWorld { unsigned char unknown0000[12552]; float water_base; };
struct D17aWaterProbe {
    unsigned char unknown00[40];
    D17aVec3 position;
    unsigned char unknown34[208];
    float result[3];
};

extern char d17a_water_level_key_80376eb0[];
extern "C" int d17a_read_float_setting_800fc270(const D17aSettingKey &key, float *value);
extern "C" void d17a_trace_800b0824(D17aVec3 *from, D17aVec3 *direction, D17aVec3 *offset,
                                    unsigned int range, int flag);
extern D17aWorld *d17a_world_804b17e0;
extern unsigned int d17a_trace_distance_804b1764;
extern D17aVec3 d17a_trace_hit_8043ae20;

static inline float d17a_absf(float v)
{
    *(unsigned int *)&v &= 0x7fffffff;
    return v;
}

extern "C" void w3d_d17a_water_level_probe_8004d23c(D17aWaterProbe *self)
{
    D17aVec3 position, direction, offset;
    D17aVec3 *p = &position;
    *p = self->position;
    float level;
    d17a_read_float_setting_800fc270(D17aSettingKey(d17a_water_level_key_80376eb0), &level);
    float depth = position.y - d17a_world_804b17e0->water_base;
    float step = -d17a_absf(depth) / 1000.0f;
    D17aVec3 *d = &direction;
    d->x = 0.0f;
    direction.y = step;
    d->z = 0.0f;
    D17aVec3 *o = &offset;
    o->x = 0.0f;
    o->y = 0.0f;
    o->z = 0.0f;
    d17a_trace_800b0824(p, d, o, 1000, 1);
    D17aVec3 hit = d17a_trace_hit_8043ae20;
    unsigned int distance = d17a_trace_distance_804b1764;
    self->result[0] = position.x;
    if (distance <= 1000)
        self->result[1] = hit.y;
    else
        self->result[1] = level;
    self->result[2] = position.z;
}

typedef char d17a_vec3_size[sizeof(D17aVec3) == 12 ? 1 : -1];
typedef char d17a_probe_result[sizeof(D17aWaterProbe) == 272 ? 1 : -1];
