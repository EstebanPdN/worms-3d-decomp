#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "d19c_motion_time_to_height_80118aac.c"
/* d19c: 0x80118aac (244 bytes). Time for a body moving with constant
 * acceleration (+28) and velocity (+16) from height +4 to reach a target
 * height: linear when the acceleration is zero, otherwise the roots of
 * a t^2 / 2 + v t + d = 0 (no solution: return 0). The earlier positive root
 * is used unless the caller asks for the later one. Returns whether the time
 * is not negative. Meanings are inferred (cx13a/s9 analysis).
 * Built with -mps-float: three FPRs are saved and the unflagged build
 * differed only by the frame reservation (cx13a's "twenty-four reserved
 * frame bytes"). The result is an explicit branch pair, as in the original. */
typedef struct d19c_Motion {
    float unknown00;
    float height;                        /* +4 */
    unsigned char unknown08[8];
    float velocity;                      /* +16 */
    unsigned char unknown14[8];
    float acceleration;                  /* +28 */
} d19c_Motion;
extern float d19c_sqrtf_802e82c0(float);

int d19c_motion_time_to_height_80118aac(Ptr32<d19c_Motion> self, Ptr32<float> time, int later, float target)
{
    float distance = self->height - target;
    float acceleration = self->acceleration;
    float velocity = self->velocity;
    if (acceleration == 0.0f) {
        *time = -distance / velocity;
    } else {
        float discriminant = velocity * velocity - 2.0f * acceleration * distance;
        float root;
        float first;
        float second;
        if (discriminant < 0.0f)
            return 0;
        root = d19c_sqrtf_802e82c0(discriminant);
        first = (-velocity + root) / acceleration;
        second = (-velocity - root) / acceleration;
        if (second < first) {
            float swap = first;
            first = second;
            second = swap;
        }
        if (!later && first > 0.0f)
            *time = first;
        else
            *time = second;
    }
    if (*time < 0.0f)
        return 0;
    return 1;
}

}
