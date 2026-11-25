extern void w3d_auto_800fc270(const char **, float *);

float s19_hop_test_height_8001e2dc(void) {
    const char *name = "Worm.HopTest.Height";
    float v;
    w3d_auto_800fc270(&name, &v);
    v = v * 0.5f;
    return v;
}
