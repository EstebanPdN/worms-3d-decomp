/* Property registration helpers that set a default value and finish through a shared routine. */
typedef struct S20Color { unsigned char r; unsigned char g; unsigned char b; unsigned char a; } S20Color;
typedef struct S20Vec { float x; float y; float z; } S20Vec;
extern char *fn_801f15e0(char *, char *);
extern char *fn_801f0210(char *, char *);
extern void fn_801e8d9c(char *);
extern char lbl_803a80c4[];
extern char lbl_803a8078[];
extern float lbl_803a809c[];

int w3d_s20_register_color_property_8018efe0(char *self) {
    char *property = fn_801f15e0(self, lbl_803a80c4);
    S20Color color;
    volatile unsigned char *bytes = (volatile unsigned char *)&color;
    bytes[0] = 0;
    bytes[3] = 0;
    bytes[1] = 0;
    bytes[2] = 0;
    *(int *)(property + 8) = *(int *)&color;
    fn_801e8d9c(self);
    return 0;
}

int w3d_s20_register_vector_property_8018ec60(char *self) {
    char *property = fn_801f0210(self, lbl_803a8078);
    S20Vec value;
    volatile float *words = (volatile float *)&value;
    words[0] = lbl_803a809c[0];
    words[2] = lbl_803a809c[0];
    words[1] = lbl_803a809c[0];
    *(S20Vec *)(property + 8) = value;
    fn_801e8d9c(self);
    return 0;
}
