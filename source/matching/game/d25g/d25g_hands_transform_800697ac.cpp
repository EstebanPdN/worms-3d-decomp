/* Worms 3D GameCube PAL 0x800697ac. Builds the first-person mesh transform: rotates by pi about the Y axis, applies the +72 scale and the +60 translation, multiplies by the inverted camera view matrix, hands the result to the body mesh and, when present, the arms mesh through slot +168, then calls 0x800694f4. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct Vec3 {
    float x, y, z;
    Vec3();
    Vec3(float a, float b, float c) { x = a; y = b; z = c; }
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Matrix { float rows[9]; Vec3 origin; Matrix() {} };
struct Matrix44 { float m[16]; Matrix44() {} Matrix44(char *camera); };
struct Mesh { struct V { void *u[42]; void (*set_transform)(Mesh *, Matrix *); } *vtable; };
struct Self { char u0[60]; Vec3 position; Vec3 scale; char u84[12]; Mesh *body; Mesh *arms; };
extern char *camera_804aa8c8;
extern "C" void rotation_801f757c(Matrix *, const Vec3 *, float);
extern "C" void scale_801f7794(Matrix *, float, float, float);
extern "C" void translate_801f77f4(Matrix *, float, float, float);
extern "C" void view_8015aa04(char *, Matrix44 *);
extern "C" Matrix44 *inverse_801f6c2c(Matrix44 *, Matrix44 *);
extern "C" void multiply_801f68c8(Matrix44 *, Matrix *, Matrix44 *);
extern "C" void to_matrix_801f74d0(Matrix *, Matrix44 *);
extern "C" void update_800694f4(Self *);
inline Matrix44::Matrix44(char *camera) { view_8015aa04(camera + 328, this); }
extern "C" void w3d_d25g_hands_transform_800697ac(Self *self)
{
    Matrix m;
    Matrix *mp = &m;
    Vec3 axis(0.0f, 1.0f, 0.0f);
    rotation_801f757c(mp, &axis, 3.1415927f);
    Vec3 scale(self->scale);
    scale_801f7794(mp, scale.x, scale.y, scale.z);
    Vec3 position(self->position);
    translate_801f77f4(mp, position.x, position.y, position.z);
    Matrix44 view(camera_804aa8c8);
    inverse_801f6c2c(&view, &view);
    multiply_801f68c8(&view, mp, &view);
    to_matrix_801f74d0(mp, &view);
    self->body->vtable->set_transform(self->body, mp);
    if (self->arms) self->arms->vtable->set_transform(self->arms, mp);
    update_800694f4(self);
}
