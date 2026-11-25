// GWMP8P rev0 0x80130fb8. Lays out the wind gauge's nodes and mesh for a
// given scale.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec &operator*=(float f) { x *= f; y *= f; z *= f; return *this; }
};
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
struct UV { float u, v; void set(const Vec &o) { float a = o.x, b = o.y; u = a; v = b; } };
struct Prop;
extern "C" float w3d_prop_float_80178df0(Prop *);
extern "C" const Vec *w3d_prop_vec_80178ec4(Prop *);
struct Mesh;
extern "C" Mesh *w3d_mesh_8034380c(void *);
extern "C" Vec *w3d_vertices_80189518(Mesh *);
extern "C" UV *w3d_uvs_8018963c(Mesh *);
struct Node {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void setPos(const Vec &, int); virtual void v18(); virtual void setDir(const Vec &, int);
};
struct Gauge {
    char u0[28]; Node *needle; char u32[4]; Node *back; void *mesh; char u44[16]; Vec origin; char u72[48];
    Prop *dir; Prop *size; Prop *grow; char u132[4]; Prop *top; char u140[8]; Prop *quad; Prop *uv;
};
inline Vec readVec(Prop *p) {
    float x = w3d_prop_float_80178df0(p);
    float y = w3d_prop_float_80178df0(p);
    float z = w3d_prop_float_80178df0(p);
    return Vec(x, y, z);
}
extern "C" void d26i_wind_gauge_layout_80130fb8(Gauge *self, float s) {
    float x1 = w3d_prop_float_80178df0(self->size); float y1 = w3d_prop_float_80178df0(self->size);
    Vec a(x1, y1, w3d_prop_float_80178df0(self->size));
    float x2 = w3d_prop_float_80178df0(self->dir); float y2 = w3d_prop_float_80178df0(self->dir);
    Vec b(x2, y2, w3d_prop_float_80178df0(self->dir));
    Vec c(*w3d_prop_vec_80178ec4(self->top));
    Vec d(*w3d_prop_vec_80178ec4(self->uv));
    Vec e(*w3d_prop_vec_80178ec4(self->quad));
    a *= s; b *= s; c *= s; d *= s; e *= s;
    self->needle->setPos(self->origin, 0);
    self->needle->setDir(a, 0);
    self->back->setPos(self->origin + c, 0);
    self->back->setDir(b, 0);
    Mesh *mesh = w3d_mesh_8034380c(self->mesh);
    w3d_vertices_80189518(mesh)[0] = self->origin + e;
    e.x += w3d_prop_float_80178df0(self->grow) * s;
    w3d_vertices_80189518(mesh)[1] = self->origin + e;
    w3d_uvs_8018963c(mesh)[0].set(d);
    w3d_uvs_8018963c(mesh)[1].set(d);
}
