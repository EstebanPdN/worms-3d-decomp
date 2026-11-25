// Node set from a 2D frame, GWMP8P rev0 0x80173988. Transforms the unit x and
// y axes by the frame with its translation cleared, takes the z rotation from
// the first axis (atan 0x802e83ec with quadrant fixes, literal pi/2, -pi/2,
// pi), and applies rotation (virtual slot +144), the frame's translation
// (+140) and scale (+152). The scale's y is negated when the frame mirrors. A
// null first axis only clears the scale and returns 0. Stored literals are the
// pool words 0x803a6708..0x803a6718 in first-use order. -mps-float: the frame
// has the 8-byte gap below the FPR save area.

extern "C" float sqrt_802e82c0(float);
extern "C" float atan_802e83ec(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    float len() const { return sqrt_802e82c0(x * x + y * y + z * z); }
};
struct Pos { float x, y, z; Pos(); };
struct Row { float x, y, z; };
struct Axes { Row row[3]; };
struct Mat {
    Axes a;
    Pos t;
    Mat(const Mat &o) { a = o.a; t = o.t; }
    const Row &R(int i) const { return a.row[i]; }
    const Pos &P() const { return t; }
    void zero(float v) { t.x = v; t.y = v; t.z = v; }
    void xform(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x + P().x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y + P().y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z + P().z;
    }
};
struct Node {
    virtual void s8(); virtual void s12(); virtual void s16(); virtual void s20(); virtual void s24(); virtual void s28();
    virtual void s32(); virtual void s36(); virtual void s40(); virtual void s44(); virtual void s48(); virtual void s52();
    virtual void s56(); virtual void s60(); virtual void s64(); virtual void s68(); virtual void s72(); virtual void s76();
    virtual void s80(); virtual void s84(); virtual void s88(); virtual void s92(); virtual void s96(); virtual void s100();
    virtual void s104(); virtual void s108(); virtual void s112(); virtual void s116(); virtual void s120(); virtual void s124();
    virtual void s128(); virtual void s132(); virtual void s136();
    virtual int setTranslation(const Pos &);
    virtual int setRotation(const Vec &);
    virtual void s148();
    virtual int setScale(const Vec &);
};
// Decompose a 2D frame into rotation about z, translation and x/y scale.
extern "C" int d26j_set_from_frame_80173988(Node *self, const Mat *m)
{
    Vec ex(1.0f, 0.0f, 0.0f);
    Vec ey(0.0f, 1.0f, 0.0f);
    Vec u, v;
    Mat r(*m);
    r.zero(0.0f);
    r.xform(u, ex);
    r.xform(v, ey);
    float det = u.x * v.y - u.y * v.x;
    float angle;
    if (u.x == 0.0f) {
        if (u.y == 0.0f) {
            Vec s(0.0f, 0.0f, 0.0f);
            self->setScale(s);
            return 0;
        }
        if (u.y > 0.0f) angle = 1.5707964f;
        else angle = -1.5707964f;
    } else {
        angle = atan_802e83ec(u.y / u.x);
        if (u.x < 0.0f) angle += 3.1415927f;
    }
    Vec rot(0.0f, 0.0f, -angle);
    int res = self->setRotation(rot);
    if (res < 0) return res;
    res = self->setTranslation(m->t);
    if (res < 0) return res;
    Vec s = det > 0.0f ? Vec(u.len(), v.len(), 0.0f) : Vec(u.len(), -v.len(), 0.0f);
    return self->setScale(s);
}
