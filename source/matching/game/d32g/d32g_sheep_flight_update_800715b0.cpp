// GWMP8P rev0 0x800715b0. Flying sheep steering: settle back to level when
// no key is held, otherwise pitch, yaw and roll rates with damping and
// clamps, then rebuild the orientation with a bank roll.
extern "C" float acos_802e79e0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    float dot(const Vec &o) const { return x * o.x + y * o.y + z * o.z; }
};
inline const float &fmin(const float &a, const float &b) { return b < a ? b : a; }
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
inline float fabs_(float v) { *(int *)&v &= 0x7fffffff; return v; }
struct Row { float x, y, z; };
struct Mat {
    Row r[3];
    const Row &R(int i) const { return r[i]; }
};
struct Mat3 { float m[9]; };
struct Handle;
struct Config {
    char u0[616]; int settleDelay; float settleRate; float settleMax; float bankFast; float bankSlow; float bankScale; float speed;
    float rollAccel, rollMax, yawAccel, yawMax, damp, pitchAccel, pitchMax;
};
struct Ctx { char u[52]; int now; };
struct Sheep {
    char u0[124]; Mat m; char u160[192 - 160]; Handle *a192; char u196[308 - 196]; int up, down, left, right, fwd, back; int a332; float pitch, roll, yaw, bank; int idle;
};
extern "C" {
Handle *w3d_empty_80341584(Handle *);
Config *w3d_auto_801797b4(Handle *);
Ctx *w3d_engine_get_context();
void w3d_d26e_euler_matrix_801a3eb0(Vec *, int, Mat *);
void w3d_s21_multiply3_801f606c(Mat *, Mat *, Mat *);
}
extern unsigned step_804b1944;
extern "C" void w3d_d32g_sheep_flight_update_800715b0(Sheep *self)
{
    Config *c = w3d_auto_801797b4(w3d_empty_80341584(self->a192));
    Vec rot(0.0f, 0.0f, 0.0f);
    Mat e;
    Mat r;
    {
    int now = w3d_engine_get_context()->now;
    Vec ax(1.0f, 0.0f, 0.0f);
    Vec ay(0.0f, 1.0f, 0.0f);
    Vec az(0.0f, 0.0f, 1.0f);
    Vec wx, wz;
    wx.x = ax.x * self->m.R(0).x + ax.y * self->m.R(1).x + ax.z * self->m.R(2).x;
    wx.y = ax.x * self->m.R(0).y + ax.y * self->m.R(1).y + ax.z * self->m.R(2).y;
    wx.z = ax.x * self->m.R(0).z + ax.y * self->m.R(1).z + ax.z * self->m.R(2).z;
    wz.x = az.x * self->m.R(0).x + az.y * self->m.R(1).x + az.z * self->m.R(2).x;
    wz.y = az.x * self->m.R(0).y + az.y * self->m.R(1).y + az.z * self->m.R(2).y;
    wz.z = az.x * self->m.R(0).z + az.y * self->m.R(1).z + az.z * self->m.R(2).z;
    bool still = !self->up && !self->down && !self->left && !self->right && !self->fwd && !self->back;
    int elapsed = now - self->idle - c->settleDelay;
    if (still && elapsed > 0) {
        const float &settle = c->settleRate;
        float rate = fmin((float)c->settleMax, settle * (float)elapsed);
        float angle = (float)step_804b1944 * rate;
        float ac = acos_802e79e0(wx.dot(ax)); angle = fmin(angle, ac);
        if (wx.y > 0.0f) rot.z = -angle;
        else rot.z = angle;
    } else {
        if (!self->up && !self->down) { float d = c->damp; self->pitch *= d; }
        else if (self->up) {
            if (self->pitch < 0.0f) self->pitch = 0.0f;
            self->pitch = self->pitch + c->pitchAccel * (float)step_804b1944;
            self->pitch = fmin((float)c->pitchMax, self->pitch);
        } else {
            if (self->pitch > 0.0f) self->pitch = 0.0f;
            self->pitch = self->pitch - c->pitchAccel * (float)step_804b1944;
            self->pitch = fmax(-c->pitchMax, self->pitch);
        }
        float dt = (float)step_804b1944;
        rot.x = self->pitch * dt;
        if (!self->left && !self->right) { float d = c->damp; self->yaw *= d; }
        else if (self->left) {
            if (self->yaw < 0.0f) self->yaw = 0.0f;
            self->yaw = self->yaw + c->yawAccel * dt;
            self->yaw = fmin((float)c->yawMax, self->yaw);
        } else {
            if (self->yaw > 0.0f) self->yaw = 0.0f;
            self->yaw = self->yaw - c->yawAccel * dt;
            self->yaw = fmax(-c->yawMax, self->yaw);
        }
        dt = (float)step_804b1944;
        rot.y = self->yaw * dt;
        if (!self->fwd && !self->back) { float d = c->damp; self->roll *= d; }
        else if (self->fwd) {
            if (self->roll < 0.0f) self->roll = 0.0f;
            self->roll = self->roll + c->rollAccel * dt;
            self->roll = fmin((float)c->rollMax, self->roll);
        } else {
            if (self->roll > 0.0f) self->roll = 0.0f;
            self->roll = self->roll - c->rollAccel * dt;
            self->roll = fmax(-c->rollMax, self->roll);
        }
        rot.z = -self->roll * (float)step_804b1944;
    }
    w3d_d26e_euler_matrix_801a3eb0(&rot, 2, &e);
    w3d_s21_multiply3_801f606c(&r, &e, &self->m);
    Mat e2;
    Vec b(0.0f, 0.0f, 0.0f);
    float k = fabs_(wx.y) < fabs_(self->bank) ? c->bankSlow : c->bankFast;
    self->bank = wx.y * k + self->bank * (1.0f - k);
    b.y = -self->bank * c->bankScale;
    w3d_d26e_euler_matrix_801a3eb0(&b, 2, &e2);
    w3d_s21_multiply3_801f606c(&self->m, &r, &e2);
    }
}
