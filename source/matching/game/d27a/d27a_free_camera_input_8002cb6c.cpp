// GWMP8P rev0 0x8002cb6c. Moves a free camera from pad input. Names are
// inferred from the original instructions.
extern "C" float w3d_auto_80178df0(void *);
extern "C" float w3d_cx9c_cosf_802e86d4(float);
extern "C" float w3d_cx9c_sinf_802e88ac(float);
extern "C" int s19_active_team_value_80020834(void *);
extern void *g_team_804b1760;
struct Input {
    unsigned buttons;  /* +0 */
    int unknown04;
    int strafe;        /* +8 */
    int forward;       /* +12 */
    int turn;          /* +16 */
};
struct Camera {
    char unknown00[80];
    float yaw;         /* +80 */
    float pitch;       /* +84 */
    float ax;          /* +88 */
    float height;      /* +92 */
    float az;          /* +96 */
    float bx;          /* +100 */
    float unknown68;
    float bz;          /* +108 */
    char unknown70[12];
    int k_min;         /* +124 */
    int k_extra;       /* +128 */
    char unknown84[12];
    int k_pitch;       /* +144 */
    int unknown94;
    int k_walk;        /* +152 */
    int k_fwd;         /* +156 */
    int k_side;        /* +160 */
    int k_turn;        /* +164 */
    int k_lift;        /* +168 */
};
extern "C" void w3d_camera_8002c840(Camera *, float);
inline const float &Max(const float &a, const float &b) { return a < b ? b : a; }
extern "C" void w3d_d27a_free_camera_input_8002cb6c(Camera *self, float dt, const Input *in)
{
    if (g_team_804b1760 && s19_active_team_value_80020834(g_team_804b1760)) {
        w3d_camera_8002c840(self, dt);
        return;
    }
    if (in->buttons & 0x08000000) self->pitch += w3d_auto_80178df0((void *)self->k_pitch) * dt;
    if (in->buttons & 0x04000000) self->pitch -= w3d_auto_80178df0((void *)self->k_pitch) * dt;
    if (in->turn) self->pitch += (float)in->turn * w3d_auto_80178df0((void *)self->k_turn);
    float step = w3d_auto_80178df0((void *)self->k_walk) * dt;
    float yaw = self->yaw;
    float dx = 0.0f, dz = 0.0f;
    float s = w3d_cx9c_sinf_802e88ac(yaw) * step;
    float c = w3d_cx9c_cosf_802e86d4(yaw) * step;
    if (in->buttons & 0x80000000) { dx += s; dz -= c; }
    if (in->buttons & 0x40000000) { dx -= s; dz += c; }
    if (in->buttons & 0x20000000) { dx -= c; dz -= s; }
    if (in->buttons & 0x10000000) { dx += c; dz += s; }
    float fw = (float)in->strafe * w3d_auto_80178df0((void *)self->k_fwd);
    float sd = (float)in->forward * w3d_auto_80178df0((void *)self->k_side);
    dx += -c * sd - s * fw;
    dz += -s * sd + c * fw;
    self->ax += dx;
    self->az += dz;
    self->bx += dx;
    self->bz += dz;
    float dy = 0.0f;
    float lift = w3d_auto_80178df0((void *)self->k_lift) * dt;
    if (in->buttons & 0x02000000) dy += lift;
    if (in->buttons & 0x01000000) dy -= lift;
    self->height += dy;
    self->height = Max(self->height, w3d_auto_80178df0((void *)self->k_min) + w3d_auto_80178df0((void *)self->k_extra));
}
