// Inferred static initialization body. Constants/objects remain externally owned.
inline void *operator new(unsigned int, void *address) { return address; }
struct Vec3 {
    float x, y, z;
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
};
extern Vec3 lbl_80453030[10];
extern float lbl_803a0490[], lbl_803a0494[], lbl_803a0498[], lbl_803a049c[], lbl_803a04a0[];
extern unsigned char *lbl_804ab3c8;
extern unsigned char *lbl_804afa48, *lbl_804afa4c, *lbl_804afa50, *lbl_804afa54, *lbl_804afa58;
extern unsigned char *lbl_804afa5c, *lbl_804afa60, *lbl_804afa64, *lbl_804afa68;
extern "C" void sol35c3_vectors_init_80141b14(int initialize, int priority)
{
    if (priority != 65535) return;
    if (!initialize) return;
    new (&lbl_80453030[0]) Vec3(lbl_803a0490[0], lbl_803a0494[0], lbl_803a0490[0]);
    new (&lbl_80453030[1]) Vec3(lbl_803a0490[0], lbl_803a0498[0], lbl_803a049c[0]);
    new (&lbl_80453030[2]) Vec3(lbl_803a0490[0], lbl_803a0498[0], lbl_803a04a0[0]);
    new (&lbl_80453030[3]) Vec3(lbl_803a049c[0], lbl_803a0498[0], lbl_803a0490[0]);
    new (&lbl_80453030[4]) Vec3(lbl_803a04a0[0], lbl_803a0498[0], lbl_803a0490[0]);
    new (&lbl_80453030[5]) Vec3(lbl_803a0490[0], lbl_803a0490[0], lbl_803a0490[0]);
    new (&lbl_80453030[6]) Vec3(lbl_803a049c[0], lbl_803a0490[0], lbl_803a0490[0]);
    new (&lbl_80453030[7]) Vec3(lbl_803a04a0[0], lbl_803a0490[0], lbl_803a0490[0]);
    new (&lbl_80453030[8]) Vec3(lbl_803a0490[0], lbl_803a0490[0], lbl_803a049c[0]);
    new (&lbl_80453030[9]) Vec3(lbl_803a0490[0], lbl_803a0490[0], lbl_803a04a0[0]);
    lbl_804afa48 = lbl_804ab3c8 + 16384;
    lbl_804afa4c = lbl_804ab3c8;
    lbl_804afa50 = lbl_804ab3c8 + 736;
    lbl_804afa54 = lbl_804ab3c8 + 12400;
    lbl_804afa58 = lbl_804ab3c8;
    lbl_804afa5c = lbl_804ab3c8 + 16368;
    lbl_804afa60 = lbl_804ab3c8 + 16304;
    lbl_804afa64 = lbl_804ab3c8 + 16176;
    lbl_804afa68 = lbl_804ab3c8;
}
