// Inferred view-matrix update. Only observed GC32 fields are represented.
struct Vec3 { float x, y, z; };
struct MatrixRow { Vec3 xyz; float untouched; };
struct ViewOwner {
    unsigned char unknown0[20];
    MatrixRow matrix[4];
    unsigned char unknown84[92];
    Vec3 position;
};
extern "C" void fn_801a0cf4(ViewOwner *, Vec3 *, Vec3 *, Vec3 *);
inline float dot(const Vec3 &a, const Vec3 &b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
extern "C" void sol35c3_view_matrix_801a1008(ViewOwner *self)
{
    Vec3 right, up, forward;
    fn_801a0cf4(self, &right, &up, &forward);
    self->matrix[0].xyz.x = right.x;
    self->matrix[0].xyz.y = up.x;
    self->matrix[0].xyz.z = forward.x;
    self->matrix[1].xyz.x = right.y;
    self->matrix[1].xyz.z = forward.y;
    self->matrix[1].xyz.y = up.y;
    self->matrix[2].xyz.x = right.z;
    self->matrix[2].xyz.z = forward.z;
    self->matrix[2].xyz.y = up.z;
    self->matrix[3].xyz.x = -dot(self->position, right);
    self->matrix[3].xyz.y = -dot(self->position, up);
    self->matrix[3].xyz.z = -dot(self->position, forward);
}
