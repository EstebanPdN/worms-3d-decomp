typedef struct S20Vec4 { float x; float y; float z; float w; } S20Vec4;
extern char *fn_801f0624(char *, char *);
extern void fn_801e8d9c(char *);
extern char lbl_803ab490[];
extern float lbl_803ab4b4[];

int w3d_s20reg4_801b9400(char *self) {
    char *property = fn_801f0624(self, lbl_803ab490);
    S20Vec4 value;
    volatile float *words = (volatile float *)&value;
    words[0] = lbl_803ab4b4[0];
    words[3] = lbl_803ab4b4[0];
    words[1] = lbl_803ab4b4[0];
    words[2] = lbl_803ab4b4[0];
    *(S20Vec4 *)(property + 8) = value;
    fn_801e8d9c(self);
    return 0;
}
