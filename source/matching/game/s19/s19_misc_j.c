extern int FUN_80009b04(void *, void *, void *, float);
extern int FUN_80009f08(void *, void *, void *, float);

int s19_try_two_checks_80009a94(void *p, int a, int b, float f) {
    if (FUN_80009b04(p, a, b, f))
        return 1;
    if (FUN_80009f08(p, a, b, f))
        return 1;
    return 0;
}

struct S19G { char pad0[60]; float f60; };
struct S19P { char pad0[36]; int f36; };
extern struct S19G *lbl_804aa6d8;
extern float FUN_8001b660(int *);
extern void FUN_8000affc(struct S19P *, float, int);

void s19_apply_scaled_length_8000d004(struct S19P *p) {
    float s = lbl_804aa6d8->f60;
    int n = (int)FUN_8001b660(&p->f36);
    FUN_8000affc(p, s, n);
}
