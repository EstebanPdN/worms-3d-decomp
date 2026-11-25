/* Corner rotation (0x80090f84): copies the two matrices into +320 and +272, runs 0x80090dac, sets the
 * translation of +320 from the vector at +104 of the object 0x804b17e0 (0x801f77f4), then rotates the eight
 * vectors at 0x80433700 by the rows of +320 (0x80343bb4) into the eight vectors at 0x804336a0. Returns 0.
 * Names are inferred from the original instructions; the unit owns no data. */
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Mat48 { unsigned v[12]; };
extern "C" const Vec *w3d_record12_at_80343bb4(const Mat48 *, int);
extern "C" void w3d_set_pos_801f77f4(Mat48 *, float, float, float);
struct Scene { char unknown00[104]; Vec eye; };
extern Scene *lbl_804b17e0;
struct Box;
extern "C" int w3d_box_update_80090dac(Box *);
struct Box {
    char unknown00[272]; Mat48 m272; Mat48 m320;
};
extern Vec lbl_804336a0, lbl_804336ac, lbl_804336b8, lbl_804336c4, lbl_804336d0, lbl_804336dc, lbl_804336e8, lbl_804336f4;
extern const Vec lbl_80433700, lbl_8043370c, lbl_80433718, lbl_80433724, lbl_80433730, lbl_8043373c, lbl_80433748, lbl_80433754;
static inline float DotX(const Mat48 *m, const Vec &s) {
    const Vec *a = w3d_record12_at_80343bb4(m, 0);
    const Vec *b = w3d_record12_at_80343bb4(m, 1);
    const Vec *c = w3d_record12_at_80343bb4(m, 2);
    return s.x * a->x + s.y * b->x + s.z * c->x;
}
static inline float DotY(const Mat48 *m, const Vec &s) {
    const Vec *a = w3d_record12_at_80343bb4(m, 0);
    const Vec *b = w3d_record12_at_80343bb4(m, 1);
    const Vec *c = w3d_record12_at_80343bb4(m, 2);
    return s.x * a->y + s.y * b->y + s.z * c->y;
}
static inline float DotZ(const Mat48 *m, const Vec &s) {
    const Vec *a = w3d_record12_at_80343bb4(m, 0);
    const Vec *b = w3d_record12_at_80343bb4(m, 1);
    const Vec *c = w3d_record12_at_80343bb4(m, 2);
    return s.x * a->z + s.y * b->z + s.z * c->z;
}
static inline void Rotate(const Mat48 *m, Vec &d, const Vec &s) {
    d.x = DotX(m, s);
    d.y = DotY(m, s);
    d.z = DotZ(m, s);
}
extern "C" int w3d_d29b_box_set_80090f84(Box *self, const Mat48 *a, const Mat48 *b) {
    self->m320 = *a;
    self->m272 = *b;
    w3d_box_update_80090dac(self);
    Vec t = lbl_804b17e0->eye;
    w3d_set_pos_801f77f4(&self->m320, t.x, t.y, t.z);
    Rotate(&self->m320, lbl_804336a0, lbl_80433700);
    Rotate(&self->m320, lbl_804336ac, lbl_8043370c);
    Rotate(&self->m320, lbl_804336b8, lbl_80433718);
    Rotate(&self->m320, lbl_804336c4, lbl_80433724);
    Rotate(&self->m320, lbl_804336d0, lbl_80433730);
    Rotate(&self->m320, lbl_804336dc, lbl_8043373c);
    Rotate(&self->m320, lbl_804336e8, lbl_80433748);
    Rotate(&self->m320, lbl_804336f4, lbl_80433754);
    return 0;
}
