// GWMP8P rev0 0x800bcdec. Mesh tree cull into a visibility bit mask: nodes
// are walked in order, a box test with an enlarged limit rejects a subtree
// (the skip count advances the node pointer and the mask by the subtree's
// leaves), then a band test against the view plane or a cone test against
// the view axis. Mesh, Node and the four camera vectors are partial views.
// The 30.0 limit sits just before this function's pool at 0x80382ce4, so it
// is declared extern.
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    bool NonZero() const { bool r = true; if (x == 0.0f && y == 0.0f) r = z != 0.0f; return r; }
    float Dot(const Vec &o) const { return x * o.x + y * o.y + z * o.z; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
};
struct Node { Vec min; Vec max; float radius; unsigned short skip; unsigned short leaves; };
struct Mesh { char unknown0[116]; Node *first; Node *last; char unknown124[4]; unsigned bits[1]; };
extern Vec lbl_8043add8[];
extern Vec lbl_8043ade4[];
extern Vec lbl_8043adf0[];
extern Vec lbl_8043adfc[];
extern float lbl_804b181c;
extern float lbl_80382ce4[];
#define NEXT() mask <<= 1; if (mask == 0) { self->bits[word] = cur; mask = 1; word++; cur = 0; }
#define SKIP() { for (i = 0; i < n->leaves; i++) { NEXT() } n += n->skip; }
#define INBOX() Sub(d, n->min, c); Sub(e, c, n->max); \
    if (d.x < limit && d.y < limit && d.z < limit && e.x < limit && e.y < limit && e.z < limit)
inline void Add(Vec &o, const Vec &a, const Vec &b) { o.x = a.x + b.x; o.y = a.y + b.y; o.z = a.z + b.z; }
inline void ScaleSub(Vec &o, float k, const Vec &b) { o.x = o.x * k - b.x; o.y = o.y * k - b.y; o.z = o.z * k - b.z; }
inline void Sub(Vec &o, const Vec &a, const Vec &b) { o.x = a.x - b.x; o.y = a.y - b.y; o.z = a.z - b.z; }
extern "C" void d32h_mesh_tree_cull_800bcdec(Mesh *self, float r) {
    Vec c = lbl_8043add8[0];
    Node *end = self->last;
    Node *n = self->first;
    Vec a = lbl_8043ade4[0];
    Vec b = lbl_8043adf0[0];
    unsigned short i;
    Vec na = a;
    if (a.x == 0.0f && a.y == 0.0f && a.z == 0.0f) na = b;
    float inv = 1.0f / na.len();
    Vec w = lbl_8043adfc[0];
    Vec m, d, e;
    na.x *= inv; na.y *= inv; na.z *= inv;
    float s; float limit = lbl_804b181c + r;
    bool has = w.NonZero();
    unsigned cur = 0, mask = 1;
    int word = 0;
    if (has) {
        if (limit > lbl_80382ce4[0]) {
            while (n != end) {
                INBOX() {
                                        Add(m, n->min, n->max);
                    ScaleSub(m, 0.5f, c);
                    float dot = m.Dot(w);
                    s = n->radius + r;
                    if (dot > -s && dot < s) {
                        if (n->skip == 1) { cur |= mask; NEXT() }
                        n++;
                    } else SKIP()
                } else SKIP()
            }
        } else {
            while (n != end) {
                INBOX() {
                    if (n->skip == 1) { cur |= mask; NEXT() }
                    n++;
                } else SKIP()
            }
        }
    } else {
        while (n != end) {
            INBOX() {
                                    Add(m, n->min, n->max);
                    ScaleSub(m, 0.5f, c);
                float len2 = m.lenSq();
                float dot = m.Dot(na);
                s = n->radius + r;
                if (len2 < s * s + dot * dot) {
                    if (n->skip == 1) { cur |= mask; NEXT() }
                    n++;
                } else SKIP()
            } else SKIP()
        }
    }
    self->bits[word] = cur;
}
