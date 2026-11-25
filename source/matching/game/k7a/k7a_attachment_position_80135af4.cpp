struct K7aVec
{
    float x, y, z;
    K7aVec() {}
    K7aVec(const K7aVec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
extern "C" void w3d_empty_80343740(K7aVec *vector);
struct K7aMatrix
{
    K7aVec axis_x, axis_y, axis_z, translation;
    K7aMatrix() { w3d_empty_80343740(&translation); }
};
struct K7aMesh;
struct K7aMeshState { char pad0[56]; K7aVec position; };
struct K7aAttached { char pad0[28]; K7aMesh *mesh; char pad32[20]; K7aVec position; char pad64[100]; K7aMesh *attachment; char pad168[516]; int mode; };
extern "C" int w3d_obj_804ab324;
extern "C" int w3d_obj_804ab328;
extern "C" K7aMesh *w3d_empty_80343584(K7aMesh *mesh);
extern "C" int FUN_80181e3c(K7aMesh *mesh, int clip, K7aMatrix *out);
extern "C" K7aMeshState *w3d_mesh_instance_unbind(K7aMesh *mesh);

extern "C" K7aVec w3d_k7a_attachment_position_80135af4(K7aAttached *self)
{
    if (self->mode == 47)
        return self->position;
    if (self->attachment)
    {
        K7aMatrix transform;
        K7aMesh *mesh = w3d_empty_80343584(self->attachment);
        if (FUN_80181e3c(mesh, w3d_obj_804ab324, &transform) >= 0)
        {
            K7aVec result;
            result = transform.translation;
            return result;
        }
        K7aVec result;
        result = w3d_mesh_instance_unbind(mesh)->position;
        return result;
    }
    K7aMatrix transform;
    FUN_80181e3c(w3d_empty_80343584(self->mesh), w3d_obj_804ab328, &transform);
    K7aVec result;
    result = transform.translation;
    return result;
}
