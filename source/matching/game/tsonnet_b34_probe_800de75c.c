/* Fills two three-float stack vectors from two global float constants (the
   first vector is constant, constant-two, constant; the second is all
   constant), calls the unrecovered query 0x800b0824 with the object, both
   vectors, 999 and 1, then reads the small-data result word 0x804b1764. When
   it is at most 998 the object's words at 176 and 180 are set from the
   small-data pair 0x804b17a8/0x804b17ac and 1 is returned, else 0. The
   vectors are reached through named pointers, except the first word of each,
   and the second vector's two later words are written in the order y, z: that
   is what reproduces the original register use and store order. Offsets are
   observed; field names and meanings are inferred. */
typedef struct { char p0[176]; int w0; int w1; } Obj;
typedef struct { float x, y, z; } V3;
extern int fn_800b0824(Obj *, V3 *, V3 *, int, int);
extern float lbl_80389bfc[];
extern float lbl_80389c00[];
extern unsigned lbl_804b1764;
extern int lbl_804b17a8, lbl_804b17ac;
int tsonnet_b34_probe_800de75c(Obj *o) {
    V3 a, b;
    V3 *pa = &a, *pb = &b;
    a.x = lbl_80389bfc[0]; pa->y = lbl_80389c00[0]; pa->z = lbl_80389bfc[0];
    b.x = lbl_80389bfc[0]; pb->y = lbl_80389bfc[0]; pb->z = lbl_80389bfc[0];
    fn_800b0824(o, pa, pb, 999, 1);
    if (lbl_804b1764 > 998) return 0;
    o->w0 = lbl_804b17a8;
    o->w1 = lbl_804b17ac;
    return 1;
}
