/* Normalizes a vector after a virtual call. */
extern int fn_80341584(int);
extern char *fn_801797b4(void *);
extern float fn_802e82c0(float);
extern float lbl_8038b600[];
extern float lbl_8038b604[];

void w3d_s20_normalize_after_call_800ed38c(char *self, int arg, float *vector) {
    float length_squared;
    fn_801797b4(fn_80341584(*(int *)(self + 192)));
    ((void (*)(char *, int, float *))(*(void ***)self)[12])(self, arg, vector);
    length_squared = vector[0] * vector[0] + vector[1] * vector[1] + vector[2] * vector[2];
    if (length_squared > lbl_8038b600[0]) {
        float scale = lbl_8038b604[0] / fn_802e82c0(length_squared);
        vector[0] = vector[0] * scale;
        vector[1] = vector[1] * scale;
        vector[2] = vector[2] * scale;
    }
}
