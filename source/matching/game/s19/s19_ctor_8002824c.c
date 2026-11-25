struct S19Obj { void *vt; char pad4[24]; int w28, w32, w36, w40, w44, w48, w52, w56, w60, w64, w68; float f72; int w76, f80, f84, f88, f92, f96, f100, f104, f108, f112, f116; };
extern unsigned char lbl_8040e208[];
extern int w3d_ctor_8015fef0(struct S19Obj *);
struct S19Obj *s19_ctor_8002824c(struct S19Obj *p) {
    w3d_ctor_8015fef0(p);
    p->w40 = 0;
    p->w44 = 0;
    p->w60 = 0;
    p->w64 = 0;
    p->f80 = 0;
    p->f88 = 0;
    p->f92 = 0;
    p->f96 = 0;
    p->f100 = 0;
    p->f104 = 0;
    p->f108 = 0;
    p->f112 = 0;
    p->f116 = 0;
    p->w32 = 0;
    p->w28 = 0;
    p->w68 = 0;
    p->vt = (void *)lbl_8040e208;
    p->w36 = 0;
    p->f72 = 0.0f;
    p->f84 = 1;
    return p;
}
