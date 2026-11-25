/* Small helpers: held-object release, cleared constructor, vector reset and normalize. */
typedef struct S20V3 { int x; int y; int z; } S20V3;
typedef void (*S20Call4)(char *, int, S20V3 *, S20V3 *, int);
extern void fn_800ddd14();
extern void fn_800dc6a8();
extern float lbl_8038af94[];

typedef struct S20I3 { int x; int y; int z; } S20I3;
typedef struct S20Obj { void **vtable; } S20Obj;
typedef void (*S20Call0)(S20Obj *);
extern void fn_8015af24(unsigned char);
extern int fn_8015fef0();
extern float fn_802e82c0(float);
extern char lbl_804102e8[];
extern float lbl_8038b5cc[];

void w3d_s20_release_held_pair_800f339c(char *self) {
    S20Obj *first = *(S20Obj **)(self + 28);
    S20Obj *second;
    *(int *)(self + 3168) = 0;
    if (first != 0)
        ((S20Call0)first->vtable[4])(first);
    second = *(S20Obj **)(self + 36);
    *(S20Obj **)(self + 28) = 0;
    if (second != 0)
        ((S20Call0)second->vtable[4])(second);
    *(S20Obj **)(self + 36) = 0;
    *(int *)(self + 80) = 0;
    if (*(int *)(self + 3192) >= 0) {
        fn_8015af24(*(unsigned char *)(self + 3195));
        *(int *)(self + 3192) = -1;
    }
}

char *w3d_s20_construct_cleared_800efe34(char *self) {
    fn_8015fef0();
    *(char **)self = lbl_804102e8;
    *(int *)(self + 28) = 0;
    *(int *)(self + 44) = 0;
    *(int *)(self + 48) = 0;
    *(int *)(self + 52) = 0;
    *(int *)(self + 56) = 0;
    *(int *)(self + 60) = 0;
    *(int *)(self + 88) = 0;
    *(int *)(self + 92) = 0;
    *(int *)(self + 96) = 0;
    *(int *)(self + 100) = 0;
    *(int *)(self + 104) = 0;
    *(int *)(self + 108) = 0;
    *(int *)(self + 112) = 0;
    *(int *)(self + 116) = 0;
    *(int *)(self + 72) = 0;
    *(int *)(self + 68) = 0;
    *(int *)(self + 80) = 0;
    *(int *)(self + 76) = 0;
    *(unsigned char *)(self + 84) = 0;
    return self;
}

void w3d_s20_set_normalized_direction_800ecfe0(char *self, float *vector) {
    float *dir = (float *)(self + 72);
    float scale;
    *(S20I3 *)dir = *(S20I3 *)vector;
    scale = lbl_8038b5cc[0] / fn_802e82c0(dir[0] * dir[0] + dir[1] * dir[1] + dir[2] * dir[2]);
    dir[0] = dir[0] * scale;
    dir[1] = dir[1] * scale;
    dir[2] = dir[2] * scale;
}

void w3d_s20_forward_position_800e705c(char *self, int index, S20V3 *out, int flag) {
    S20V3 position;
    fn_800ddd14();
    if (*(int *)(self + 164) != 0) {
        ((S20Call4)(*(void ***)(self + 112))[17])(self, index, &position, out, flag);
        *out = position;
    }
}

void w3d_s20_reset_vectors_800e67d0(char *self) {
    float *first;
    float *second;
    float zero;
    fn_800dc6a8();
    zero = lbl_8038af94[0];
    *(int *)(self + 168) = *(int *)(self + 100);
    first = (float *)(self + 140);
    *(int *)(self + 164) = 0;
    second = (float *)(self + 152);
    first[0] = zero;
    first[1] = zero;
    first[2] = zero;
    second[0] = zero;
    second[1] = zero;
    second[2] = zero;
}
