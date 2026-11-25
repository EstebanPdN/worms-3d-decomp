/* Random valid land point search (0x8008dd54): sets up a collision probe (0x80126184)
 * of the given radius at the output position, then up to 100 times picks a random point
 * inside the land bounds (0x804b17e0 +12548, +12560), drops it to the ground
 * (0x800b0788) and, when the ground is above Water.Level, tests the probe at the point
 * plus the offset (0x80126334, 0x801264fc). Returns 1 when a point passes. Field and
 * type names are inferred from the original instructions. Owns its float literal at
 * 0x8037e15c. */
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3 &o) { float ax = o.x, ay = o.y, az = o.z; x = ax; y = ay; z = az; }
};
struct PropertyKey { const char *name; };
struct Probe {
    char storage[8];
    Probe();
    ~Probe();
};
struct Land { char unknown00[12548]; Vec3 lower; Vec3 upper; };
extern Land *w3d_land_804b17e0;
extern Vec3 w3d_ground_8043ae20;
extern "C" void w3d_probe_set_group_8012632c(Probe *, int);
extern "C" void w3d_probe_set_mask_801262e4(Probe *, int);
extern "C" void w3d_probe_set_radius_8012629c(Probe *, float);
extern "C" void w3d_probe_set_position_801262c0(Probe *, const Vec3 *);
extern "C" void w3d_probe_run_80126334(Probe *);
extern "C" int w3d_probe_result_801264fc(Probe *);
extern "C" void w3d_probe_reset_80126524(Probe *);
extern "C" int w3d_float_read_800fc270(PropertyKey *, float *);
extern "C" float w3d_random_80162bc8();
extern "C" int w3d_ground_query_800b0788(Vec3 *, Vec3 *);
extern "C" char w3d_string_8037e150[]; /* "Water.Level" */

extern "C" int w3d_d24b_land_point_search_8008dd54(void *self, Vec3 *position, const Vec3 *offset, float radius)
{
    Probe probe;
    int hit = 0;
    w3d_probe_set_group_8012632c(&probe, -1);
    int clear = 0;
    w3d_probe_set_mask_801262e4(&probe, 0);
    unsigned tries = 0;
    w3d_probe_set_radius_8012629c(&probe, radius);
    w3d_probe_set_position_801262c0(&probe, position);
    Vec3 lower(w3d_land_804b17e0->lower);
    Vec3 upper(w3d_land_804b17e0->upper);
    Vec3 down;
    Vec3 *pdown = &down;
    Vec3 test;
    PropertyKey key;
    key.name = w3d_string_8037e150;
    float water;
    w3d_float_read_800fc270(&key, &water);
    float zero = 0.0f;
    while ((!hit || !clear) && tries <= 99) {
        position->y = upper.y;
        position->x = (upper.x - lower.x) * w3d_random_80162bc8() + lower.x;
        position->z = (upper.z - lower.z) * w3d_random_80162bc8() + lower.z;
        down.x = zero;
        down.y = -(upper.y - lower.y);
        pdown->z = zero;
        hit = w3d_ground_query_800b0788(position, pdown);
        if (hit && w3d_ground_8043ae20.y > water) {
            test.x = w3d_ground_8043ae20.x + offset->x;
            test.y = w3d_ground_8043ae20.y + offset->y;
            test.z = w3d_ground_8043ae20.z + offset->z;
            w3d_probe_set_position_801262c0(&probe, &test);
            w3d_probe_run_80126334(&probe);
            clear = (w3d_probe_result_801264fc(&probe) ^ 0xffff) == 0;
            w3d_probe_reset_80126524(&probe);
        }
        tries++;
    }
    int found = 0;
    if (hit && clear) found = 1;
    return found;
}
