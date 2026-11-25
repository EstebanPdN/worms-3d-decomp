// GWMP8P rev0 0x8013de54. Pick the worm walk clip: rotate the record
// direction (+44 of the index entry) by the matrix built from the negated
// yaw (+68), reset two mesh channels, play the idle clip, then play one of
// four directional clips chosen by the larger of |x| and |z| and its sign,
// all as named clips through 0x801359ec. Names are inferred.
struct Vec {
    float x, y, z;
    Vec() {}
};
struct Pos { float x, y, z; Pos(); };
struct Axis { float x, y, z; };
struct Transform { Axis axis[3]; Pos position; };
struct Row { float x, y, z, w; };
struct Matrix {
    Row row[4];
    const Row &R(int i) const { return row[i]; }
    Matrix(const Axis *axis, const Pos &p) {
        row[0].x = axis[0].x; row[0].y = axis[0].y; row[0].z = axis[0].z; row[0].w = 0.0f;
        row[1].x = axis[1].x; row[1].y = axis[1].y; row[1].z = axis[1].z; row[1].w = 0.0f;
        row[2].x = axis[2].x; row[2].y = axis[2].y; row[2].z = axis[2].z; row[2].w = 0.0f;
        row[3].x = p.x; row[3].y = p.y; row[3].z = p.z; row[3].w = 1.0f;
    }
    void rotate(Vec &o, const Axis &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z;
    }
};
struct Info { unsigned char u0[44]; Axis dir; };
struct Mesh;
struct Worm {
    unsigned char u0[68]; float yaw;
    unsigned char u72[40]; int index;
    unsigned char u116[356]; char strafe[20]; char idle[4];
};
extern "C" void construct_801f7538(Transform *, float, float, float, float);
extern "C" Info *index_query_800fc6dc(int);
extern "C" int control_801817e0(Mesh *, int);
extern "C" int play_801359ec(Worm *, Mesh *, int, void *, float, float, float);
extern int idle_804ab100, back_804ab3a0, front_804ab3a4, right_804ab3a8, left_804ab3ac;
extern "C" void d25d_worm_strafe_clip_8013de54(Worm *self, Mesh *mesh) {
    Transform t;
    const Pos &pos = t.position;
    Axis *axis = t.axis;
    construct_801f7538(&t, 0.0f, 1.0f, 0.0f, -self->yaw);
    Info *w = index_query_800fc6dc(self->index);
    Vec o;
    Matrix m(axis, pos);
    m.rotate(o, w->dir);
    control_801817e0(mesh, -1);
    control_801817e0(mesh, -2);
    play_801359ec(self, mesh, idle_804ab100, self->idle, 1.0f, 0.0f, 0.0f);
    if (__builtin_fabsf(o.z) > __builtin_fabsf(o.x)) {
        if (o.z < 0.0f) play_801359ec(self, mesh, back_804ab3a0, self->strafe, 1.0f, -1.0f, 0.0f);
        else play_801359ec(self, mesh, front_804ab3a4, self->strafe, 1.0f, -1.0f, 0.0f);
    } else {
        if (o.x > 0.0f) play_801359ec(self, mesh, left_804ab3ac, self->strafe, 1.0f, -1.0f, 0.0f);
        else play_801359ec(self, mesh, right_804ab3a8, self->strafe, 1.0f, -1.0f, 0.0f);
    }
}
