extern unsigned char lbl_8041e780[];
extern void w3d_auto_80118268(void *, void *);
extern int FUN_80118aac(void *, float, float *, int);
extern int FUN_8001b830(void *, float);

int s19_probe_value_8001b8f0(void *p, float t) {
    struct { float v; int extra[2]; } k;
    w3d_auto_80118268(lbl_8041e780, p);
    if (FUN_80118aac(lbl_8041e780, t, &k.v, 0) == 0)
        return 0;
    return FUN_8001b830(p, k.v);
}
