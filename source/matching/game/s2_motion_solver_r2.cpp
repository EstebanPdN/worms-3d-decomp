/* Motion target updates and vertical trajectory intersection. */
extern "C" {
struct S2Vector { float x, y, z; };
struct S2Motion { S2Vector position, velocity, acceleration; unsigned char pad24[4]; unsigned char dirty; unsigned char pad29[3]; S2Vector target; };
float w3d_sqrt_802e82c0(float);
void w3d_fn_800d75f0(S2Motion *, S2Vector *, float);
int w3d_motion_height_time_80118aac(S2Motion *, float *, int, float);
extern const float w3d_f32_8039a9d0[];


void w3d_motion_set_target_801182c0(S2Motion *self, const S2Vector *target)
{
    self->target = *target;
    self->dirty |= 8;
}


int w3d_motion_at_height_80118a5c(S2Motion *self, S2Vector *out, int farRoot, float height)
{
    float local;
    int found = w3d_motion_height_time_80118aac(self, &local, farRoot, height);
    if (found) w3d_fn_800d75f0(self, out, local);
    return found;
}


#if 0 /* 4 attempts; acceleration and velocity floating-point registers are exchanged */
int w3d_motion_height_time_80118aac(S2Motion *self, float *time, int farRoot, float height)
{
    struct { float a[6]; } scratch;
    float velocity = self->velocity.y;
    register float acceleration = self->acceleration.y;
    float zero = w3d_f32_8039a9d0[0];
    float distance = self->position.y - height;
    if (acceleration == zero) {
        *time = -distance / velocity;
    } else {
        float discriminant = velocity * velocity - ((acceleration + acceleration) * distance);
        if (discriminant < zero) return 0;
        float root = w3d_sqrt_802e82c0(discriminant);
        float smaller = (-velocity + root) / acceleration;
        float larger = (-velocity - root) / acceleration;
        if (larger < smaller) { float temp = smaller; smaller = larger; larger = temp; }
        if (!farRoot && smaller > zero) *time = smaller;
        else *time = larger;
    }
    if (*time < w3d_f32_8039a9d0[0]) return 0;
    return 1;
}
#endif

}
