// GWMP8P rev0 0x8003d4b4. Rebuilds a lit mesh's vertex stream with a
// rotating matrix.
extern "C" float w3d_sqrtf_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float Dot(const Vec &o) const { return x * o.x + y * o.y + z * o.z; }
    float Normalize() {
        Vec *p = this;
        float len = w3d_sqrtf_802e82c0(x * x + y * y + z * z);
        float inv = 1.0f / len;
        x *= inv; p->y *= inv; p->z *= inv;
        return len;
    }
};
struct Point { float x, y, z; Point(); };
struct Row { float x, y, z; };
struct Rows { Row r[3]; };
struct Mat {
    Rows r; Point p;
    Mat() {}
    Mat(const Mat &o) { r = o.r; p = o.p; }
    const Row &R(int i) const { return r.r[i]; }
    const Point &P() const { return p; }
    void Transform(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x + P().x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y + P().y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z + P().z;
    }
};
extern "C" void w3d_s21_construct_801f757c(Mat *, const Vec *, float);
extern "C" void w3d_auto_801f7794(Mat *, float, float, float);
extern "C" void w3d_auto_801f77f4(Mat *, float, float, float);
struct Mesh;
struct Node;
extern "C" Mesh *w3d_empty_8034380c(Node *);
extern "C" unsigned char *s9_property_data_80189704(Mesh *);
extern "C" Vec *s9_property_data_80189518(Mesh *);
extern "C" unsigned *tsonnet_b37_open_80189760(Mesh *);
extern "C" unsigned char *s9_property_data_80189828(Mesh *);
struct UV { float u, v; };
extern "C" UV *tsonnet_b37_open_8018963c(Mesh *);
struct Items { Vec *start; Vec *finish; Vec *end; const Vec &operator[](unsigned i) const { return start[i]; } };
extern Items g_items_804273d4[];
extern Items g_normals_804273e0[];
extern float g_angle_804aa93c;
struct Colour { unsigned char r, g, b, a; };
struct Self { char unknown00[28]; Node *mesh; Colour colours[256]; };
struct Row4 { float x, y, z, w; };
struct M44 {
    Row4 r[4];
    M44(const Mat &s) {
        r[0].x = s.r.r[0].x; r[0].y = s.r.r[0].y; r[0].z = s.r.r[0].z; r[0].w = 0.0f;
        r[1].x = s.r.r[1].x; r[1].y = s.r.r[1].y; r[1].z = s.r.r[1].z; r[1].w = 0.0f;
        r[2].x = s.r.r[2].x; r[2].y = s.r.r[2].y; r[2].z = s.r.r[2].z; r[2].w = 0.0f;
        r[3].x = s.P().x; r[3].y = s.P().y; r[3].z = s.P().z; r[3].w = 1.0f;
    }
    const Row4 &R(int i) const { return r[i]; }
    void Rotate(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z;
    }
};
extern "C" int w3d_d46a_mesh_light_colours_8003d4b4(Self *self)
{
    unsigned n = g_items_804273d4->finish - g_items_804273d4->start;
    Mesh *mesh = w3d_empty_8034380c(self->mesh);
    s9_property_data_80189704(mesh);
    Vec *pos = s9_property_data_80189518(mesh);
    unsigned *col = tsonnet_b37_open_80189760(mesh);
    unsigned char *tag = s9_property_data_80189828(mesh);
    unsigned char *flag = s9_property_data_80189704(mesh);
    UV *uv = tsonnet_b37_open_8018963c(mesh);
    const float scale = 40.0f;
    Vec d;
    Vec *pd = &d;
    d.x = 0.0f; pd->y = 0.6f; pd->z = -1.0f;
    d.Normalize();
    Mat m;
    Vec axis;
    Vec *pa = &axis;
    axis.x = 0.0f; pa->y = 1.0f; pa->z = 0.0f;
    w3d_s21_construct_801f757c(&m, pa, g_angle_804aa93c);
    Mat w(m);
    w3d_auto_801f7794(&w, scale, scale, scale);
    w3d_auto_801f77f4(&w, 100.0f, 1500.0f, -2000.0f);
    g_angle_804aa93c += 0.01f;
    for (unsigned i = 0; i < n; i++) {
        Vec b, a;
        M44 t(m);
        t.Rotate(a, (*g_normals_804273e0)[i]);
        w.Transform(b, (*g_items_804273d4)[i]);
        pos[i] = b;
        b.Normalize();
        flag[i] = 1;
        uv[i].u = 120.0f; uv[i].v = 120.0f;
        float dl = a.Dot(d);
        float dv = __builtin_fabsf(b.Dot(a));
        int idx = (int)(dl * 127.0f + 128.0f);
        int alpha = (int)(dv * 63.0f + 192.0f);
        idx = *(int *)&self->colours[idx] | (alpha << 24); col[i] = idx;
        tag[i] = i & 15;
    }
    return 0;
}
