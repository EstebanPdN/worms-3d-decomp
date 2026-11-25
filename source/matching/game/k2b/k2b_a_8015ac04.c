extern int w3d_test_ray_800b0788(const float *origin, const float *ray);
int w3d_k2b_ray_misses_8015ac04(void *self, const float *from, const float *to)
{
    float ray[7];
    float dx = to[0] - from[0];
    float dy = to[1] - from[1];
    float dz = to[2] - from[2];
    ray[4] = dx;
    ray[0] = dx;
    ray[5] = dy;
    ray[1] = dy;
    ray[6] = dz;
    ray[2] = dz;
    return w3d_test_ray_800b0788(from, ray) ^ 1;
}
// desc: Appears to build a direction vector between two points and return whether a ray test from the first point fails.
