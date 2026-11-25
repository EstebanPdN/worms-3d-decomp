/* Scaled vector length. */
typedef struct S20Vec4 { float x; float y; float z; float w; } S20Vec4;
extern int fn_80341584(int);
extern char *fn_801797b4(int);
extern float fn_802e82c0(float);
extern float lbl_8038b5c8[];

void w3d_s20_set_scaled_length_800ecf54(char *self, float *vector) {
    char *resolved = fn_801797b4(fn_80341584(*(int *)(self + 192)));
    S20Vec4 value;
    volatile float *words = (volatile float *)&value;
    float x;
    float y;
    float z;
    words[0] = vector[0];
    words[1] = vector[1];
    words[2] = vector[2];
    value.w = lbl_8038b5c8[0];
    x = words[0];
    y = words[1];
    z = words[2];
    *(float *)(self + 104) = fn_802e82c0(x * x + y * y + z * z) * *(float *)(resolved + 272);
}
