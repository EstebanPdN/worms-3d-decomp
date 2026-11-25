#include "w3d_ptr.h"
#line 1 "d25b_girder_input_80094a84.cpp"
/* Girder placement input (0x80094a84): while the placed count at +744 is below the limit
 * at +740, clears the velocity and rate fields and reads the keys at +292 and the
 * previous keys at +296: 2048 toggles the size at +688 and rescales the handle at +764
 * (0x8012629c); up and down set the height velocity and target; the 512, 1024, 64 and 128
 * edges rotate the angles at +312 and +332 unless 4096 is held; the four direction keys
 * move the target along the axes at +256 and +268. Field and type names are inferred from
 * the original instructions. Owns its float literals at 0x8037ea70. */
struct Vec3 {
    float x, y, z;
    void Set(float v) { x = v; Ptr32<Vec3> p = this; p->y = v; p->z = v; }
};
struct Handle;
struct Girder {
    char unknown00[184];
    Vec3 position;    /* +184 */
    char unknown196[12];
    Vec3 target;      /* +208 */
    char unknown220[12];
    Vec3 velocity;    /* +232 */
    char unknown244[12];
    float forwardX;   /* +256 */
    float unknown260;
    float forwardZ;   /* +264 */
    float sideX;      /* +268 */
    float unknown272;
    float sideZ;      /* +276 */
    char unknown280[12];
    unsigned keys;    /* +292 */
    unsigned previous; /* +296 */
    char unknown300[4];
    float pitch;      /* +304 */
    char unknown308[4];
    float pitchTarget; /* +312 */
    char unknown316[4];
    float pitchRate;  /* +320 */
    float yaw;        /* +324 */
    char unknown328[4];
    float yawTarget;  /* +332 */
    char unknown336[4];
    float yawRate;    /* +340 */
    char unknown344[344];
    int large;        /* +688 */
    char unknown692[48];
    unsigned limit;   /* +740 */
    unsigned count;   /* +744 */
    char unknown748[16];
    Ptr32<Handle> handle;   /* +764 */
};
extern "C" void w3d_handle_member_query_8012629c(Ptr32<Handle>, float);

extern "C" void w3d_d25b_girder_input_80094a84(Ptr32<Girder> self)
{
    if (self->count >= self->limit) return;
    float zero = 0.0f;
    self->velocity.Set(zero);
    self->pitchRate = zero;
    self->yawRate = zero;
    self->yawTarget = self->yaw;
    self->pitchTarget = self->pitch;
    self->target = self->position;
    if ((self->keys & 2048) && !(self->previous & 2048)) {
        self->large++;
        if (self->large > 1) self->large = 0;
        switch (self->large) {
        case 0:
            w3d_handle_member_query_8012629c(self->handle, 25.0f);
            break;
        case 1:
            w3d_handle_member_query_8012629c(self->handle, 50.0f);
            break;
        }
    }
    if ((self->keys & 32) || (self->keys & 4160) == 4160) {
        float v = 0.3f;
        self->velocity.y = v;
        self->target.y = self->position.y + v * 20.0f;
    }
    if ((self->keys & 16) || (self->keys & 4224) == 4224) {
        float v = -0.3f;
        self->velocity.y = v;
        self->target.y = self->position.y + v * 20.0f;
    }
    if (!(self->keys & 4096)) {
        if ((self->keys & 512) && !(self->previous & 512)) {
            self->pitchTarget = self->pitch - 0.3926991f;
            self->pitchRate = 0.3926991f;
        }
        if ((self->keys & 1024) && !(self->previous & 1024)) {
            self->pitchTarget = self->pitch + 0.3926991f;
            self->pitchRate = 0.3926991f;
        }
        if ((self->keys & 64) && !(self->previous & 64)) {
            self->yawTarget = self->yaw + 0.3926991f;
            self->yawRate = 0.3926991f;
        }
        if ((self->keys & 128) && !(self->previous & 128)) {
            self->yawTarget = self->yaw - 0.3926991f;
            self->yawRate = 0.3926991f;
        }
    }
    if (self->keys & 1) {
        float vx = self->forwardX * 0.3f;
        float vz = self->forwardZ * 0.3f;
        self->velocity.x = vx;
        self->target.x = self->position.x + vx * 20.0f;
        self->velocity.z = vz;
        self->target.z = self->position.z + vz * 20.0f;
    }
    if (self->keys & 2) {
        float vx = -self->forwardX * 0.3f;
        float vz = -self->forwardZ * 0.3f;
        self->velocity.x = vx;
        self->target.x = self->position.x + vx * 20.0f;
        self->velocity.z = vz;
        self->target.z = self->position.z + vz * 20.0f;
    }
    if ((self->keys & 4) || (self->keys & 4608) == 4608) {
        float vx = -self->sideX * 0.3f;
        float vz = -self->sideZ * 0.3f;
        self->velocity.x = vx;
        self->target.x = self->position.x + vx * 20.0f;
        self->velocity.z = vz;
        self->target.z = self->position.z + vz * 20.0f;
    }
    if ((self->keys & 8) || (self->keys & 5120) == 5120) {
        float vx = self->sideX * 0.3f;
        float vz = self->sideZ * 0.3f;
        self->velocity.x = vx;
        self->target.x = self->position.x + vx * 20.0f;
        self->velocity.z = vz;
        self->target.z = self->position.z + vz * 20.0f;
    }
}


