struct S19Camera { char pad0[72]; void *vt; char pad76[132]; int f208; };
extern void * FUN_800d2dec(struct S19Camera *, void *, const char *, void *);
extern void w3d_auto_800d31d8(struct S19Camera *, const char *);
extern unsigned char lbl_8040eb90[];

struct S19Camera *s19_camera_ctor_800520f4(struct S19Camera *p, void *a, void *b) {
    FUN_800d2dec(p, a, "Shoulder", b);
    p->vt = (void *)lbl_8040eb90;
    p->f208 = 0;
    w3d_auto_800d31d8(p, "ShoulderCamera");
    return p;
}
