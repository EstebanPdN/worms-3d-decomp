// Inferred vector/matrix views from the original scalar access offsets.
// Local vector stride in the frame does not establish the original sizeof.
struct cc44a_Vec3 {
    float x,y,z;
    float dot(const cc44a_Vec3 &b) const { return x*b.x+y*b.y+z*b.z; }
};
struct cc44a_Vec4 {
    float x,y,z,w;
    void set(float a,float b,float c,float d) { x=a; y=b; z=c; w=d; }
};
struct cc44a_View { void *vtable; cc44a_Vec3 position; };
struct cc44a_Matrix { cc44a_Vec4 rows[4]; };
// 8015a6f0 writes three 3-float output vectors and has no defined scalar result.
extern "C" void cc44a_basis_8015a6f0(cc44a_View *, cc44a_Vec3 *, cc44a_Vec3 *, cc44a_Vec3 *);
extern "C" void cc44a_view_matrix_8015aa04(cc44a_View *self, cc44a_Matrix *out) {
    cc44a_Vec3 right, up, back;
    cc44a_basis_8015a6f0(self,&right,&up,&back);
    out->rows[0].set(right.x,up.x,back.x,0.0f);
    out->rows[1].set(right.y,up.y,back.y,0.0f);
    out->rows[2].set(right.z,up.z,back.z,0.0f);
    cc44a_Vec4 &translation = out->rows[3];
    translation.x = -self->position.dot(right);
    translation.y = -self->position.dot(up);
    translation.z = -self->position.dot(back);
    translation.w = 1.0f;
}
