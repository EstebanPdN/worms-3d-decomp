struct K5bVec3 {
    float x, y, z;
    K5bVec3(float ax, float ay, float az)
    {
        x = ax;
        y = ay;
        z = az;
    }
};
inline void *operator new(unsigned int, void *place) { return place; }
extern K5bVec3 lbl_8045e788;
extern K5bVec3 lbl_8045e794;
extern K5bVec3 lbl_8045e7a0;
extern K5bVec3 lbl_8045e7ac;
extern "C" void w3d_k5b_axis_vectors_sinit_801f7a58(int initialize, int priority)
{
    if (priority == 0xffff && initialize != 0) {
        new (&lbl_8045e788) K5bVec3(0.0f, 0.0f, 0.0f);
        new (&lbl_8045e794) K5bVec3(1.0f, 0.0f, 0.0f);
        new (&lbl_8045e7a0) K5bVec3(0.0f, 1.0f, 0.0f);
        new (&lbl_8045e7ac) K5bVec3(0.0f, 0.0f, 1.0f);
    }
}
// desc: w3d_k5b_axis_vectors_sinit_801f7a58: Appears to be a static initializer constructing the zero vector and the X, Y and Z unit vectors at 0x8045e788..0x8045e7ac.
