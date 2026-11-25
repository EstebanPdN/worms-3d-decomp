// GWMP8P rev0 0x8024bc08. Constructor of a node holding a registry base at
// +0 (its type word passes straight through in r4), five transforms copied
// from the identity table at 0x8045e748, nine zero vectors, reference-
// counted handles initialised from the default object in lbl_804b05a8, two
// zero 2D vectors, a colour, and twelve cleared flags. The class and field
// names are inferred; 0x80343740 is the empty position constructor.
struct D43kObject;
struct D43kObjectVt { void *unknown[3]; int (*retain)(D43kObject *); };
struct D43kObject { D43kObjectVt *vt; };
struct D43kRef {
    D43kObject *pointer;
    D43kRef(D43kObject *o) : pointer(o) { if (o) o->vt->retain(o); }
};
struct D43kPos { float x, y, z; D43kPos(); };
struct D43kRot { float m[9]; };
struct D43kMat {
    D43kRot rot;
    D43kPos pos;
    D43kMat(const D43kMat &o);
};
extern D43kMat lbl_8045e748[];
inline D43kMat::D43kMat(const D43kMat &o) { rot = o.rot; pos = o.pos; }
struct D43kVec { float x, y, z; D43kVec(float a, float b, float c) { x = a; y = b; z = c; } };
struct D43kVec2 { float x, y; D43kVec2(float a, float b) { x = a; y = b; } };
struct D43kColor { char r, g, b, a; D43kColor(char x, char y, char z, char w) { r = x; g = y; b = z; a = w; } };
extern D43kObject *lbl_804b05a8;
extern void *lbl_8041b8c0[];
extern "C" void *fn_801b4e94(void *, unsigned);
struct D43kHead {
    void *vt;
    char unknown[44];
    D43kHead(unsigned type) { fn_801b4e94(this, type); vt = lbl_8041b8c0; }
};
struct D43kTransformNode {
    D43kHead head;
    D43kMat m0, m1, m2, m3, m4;
    D43kVec v288, v300, v312, v324, v336, v348, v360, v372, v384;
    D43kRef a, b;
    D43kVec2 p404, p412;
    float f420;
    D43kColor color;
    D43kRef d, e, f, g;
    float f444;
    char ba, bb, bc, bd, be, bf, bg, bh, bi, bj, bk, bl;
    D43kRef h;
    D43kTransformNode(unsigned type);
};
D43kTransformNode::D43kTransformNode(unsigned type)
    : head(type), m0(lbl_8045e748[0]), m1(lbl_8045e748[0]), m2(lbl_8045e748[0]), m3(lbl_8045e748[0]), m4(lbl_8045e748[0]),
      v288(0.0f, 0.0f, 0.0f), v300(0.0f, 0.0f, 0.0f), v312(0.0f, 0.0f, 0.0f), v324(0.0f, 0.0f, 0.0f), v336(0.0f, 0.0f, 0.0f),
      v348(0.0f, 0.0f, 0.0f), v360(0.0f, 0.0f, 0.0f), v372(0.0f, 0.0f, 0.0f), v384(0.0f, 0.0f, 0.0f),
      a(lbl_804b05a8), b(lbl_804b05a8), p404(0.0f, 0.0f), p412(0.0f, 0.0f), f420(0.0f), color(0, 0, 0, 0),
      d(lbl_804b05a8), e(lbl_804b05a8), f(lbl_804b05a8), g(lbl_804b05a8), f444(0.0f),
      ba(0), bb(0), bc(0), bd(0), be(0), bf(0), bg(0), bh(0), bi(0), bj(0), bk(0), bl(0), h(lbl_804b05a8) {}
