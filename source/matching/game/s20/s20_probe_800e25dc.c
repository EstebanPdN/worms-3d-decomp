typedef struct S20V3 { int x; int y; int z; } S20V3;
typedef struct S20Obj { void **vtable; } S20Obj;
typedef int (*S20Call1)(S20Obj *, char *);
typedef void (*S20Call4)(char *, int, S20V3 *, S20V3 *, int);
extern void fn_80343740(S20V3 *);
extern void fn_800ddd14();
extern void fn_800dc6a8();
extern float lbl_8038af94[];

int w3d_s20_query_position_800e25dc(char *self, S20V3 *out) {
    struct { S20V3 scratch[3]; S20V3 position; } local;
    S20Obj *sub;
    int result;
    S20V3 *scratch = local.scratch;
    S20V3 *position = &local.position;
    fn_80343740(position);
    sub = *(S20Obj **)(self + 300);
    if (sub == 0)
        return 0x80004005;
    result = ((S20Call1)sub->vtable[31])(sub, (char *)scratch);
    *out = *position;
    return result;
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
    fn_800dc6a8();
    *(int *)(self + 168) = *(int *)(self + 100);
    first = (float *)(self + 140);
    *(int *)(self + 164) = 0;
    second = (float *)(self + 152);
    first[0] = lbl_8038af94[0];
    first[2] = lbl_8038af94[0];
    first[1] = lbl_8038af94[0];
    second[0] = lbl_8038af94[0];
    second[2] = lbl_8038af94[0];
    second[1] = lbl_8038af94[0];
}
