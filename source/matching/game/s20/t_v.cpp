struct S20Vec3 {
    float x; float y; float z;
    inline S20Vec3(float k) { x = k; y = k; z = k; }
};
extern "C" char *fn_801f0210(char *, char *);
extern "C" void fn_801e8d9c(char *);
extern "C" char lbl_803ac5f0[];
extern "C" char lbl_803ac620[];
extern "C" float lbl_803ac644[];

extern "C" int w3d_s20pair_801c16ec(char *self) {
    char *property;
    float constant;
    property = fn_801f0210(self, lbl_803ac5f0);
    constant = lbl_803ac644[0];
    {
        S20Vec3 first(constant);
        *(S20Vec3 *)(property + 8) = first;
    }
    property = fn_801f0210(self, lbl_803ac620);
    {
        S20Vec3 second(constant);
        *(S20Vec3 *)(property + 8) = second;
    }
    fn_801e8d9c(self);
    return 0;
}
