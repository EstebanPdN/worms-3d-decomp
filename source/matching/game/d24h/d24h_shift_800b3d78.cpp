// Pose shift (Worms 3D GameCube PAL, 0x800b3d78, 168 bytes). Names are inferred.

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) { x = a; y = b; z = c; }
    
    void operator+=(const Vec3 &o) { x += o.x; y += o.y; z += o.z; }
};
struct Pose {
    Vec3 pos; float w;
    Pose() {}
    Pose(float ax, float ay, float az, float aw) { pos.x = ax; pos.y = ay; pos.z = az; w = aw; }
};
struct Body { unsigned char unknown00[20]; Pose pose; };
struct Owner { unsigned char unknown00[4]; Body *body; };
struct Scene { unsigned char unknown00[104]; Vec3 offset; };
extern Scene *lbl_804b17e0;   // Small-data scene pointer.
inline void Put(Pose &to, const Pose &from) { to = from; }
extern "C" void w3d_d24h_shift_800b3d78(Owner *self) {
    Body *body = self->body;
    Pose &pose = body->pose;
    Vec3 v(pose.pos.x, pose.pos.y, pose.pos.z);
    v += lbl_804b17e0->offset;
    Put(pose, Pose(v.x, v.y, v.z, pose.w));
}
