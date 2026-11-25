// Land property registration (Worms 3D GameCube PAL, 0x8024e1fc).
//
// Resets the Name string binding (0x801ed24c) to the shared empty string
// 0x804b06a0; creates the Position, Orientation, Scale, FloorTexXVec,
// FloorTexYVec, WallTexXVec and WallTexYVec vector bindings (0x801f0210),
// the FloorTexOffset and WallTexOffset 2D bindings (0x801f00f0) and the
// CentreOffset vector binding, all reset to the constant 0x803c5524 (0.0f);
// registers EdgeOffset1/EdgeOffset2 (0x801f25b0), XSize/YSize/ZSize
// (0x801eb834), HeightMap (0x801efec4), EdgeCrinkle, EdgeFalloff,
// PeturbCliffs, Visible, SmoothShading, resets the Tint colour binding
// (0x801f15e0) to 0, registers Voxels (0x801efdfc) and Details
// (0x801eff8c); calls the refresh routine 0x801e8d9c and returns 0. Names
// are read from the descriptors' name pointers in the original data.
//
// Each property descriptor is a function-local static initialized from a
// GNU statement expression over a memset-zeroed local (the shape solved for
// 0x801c4930, d20e_box_properties_801c4930). In the HeightMap block the
// element type (20) and the memset size are one value in the original: the
// descriptor size kept in a local and reused for the element type gives the
// original register assignment (a literal 20 swaps registers, 9 words).
// The guards and static objects are zero-initialized statics of this
// function (not file-backed). Built with -mps-float (one saved FPR in a
// non-leaf function).
extern "C" void *memset(...);
struct SharedString;
extern "C" void d20e_string_init_8020c5c0(SharedString *);
extern "C" unsigned short *d20e_string_header_80341884(SharedString *);
extern "C" void d20e_string_finish_8020c5c4(SharedString *);
extern "C" void d20e_string_release_80341588(SharedString *);
extern "C" void d20e_release_header_8020bb2c(unsigned short *);

struct SharedString {
    char *text;

    // Copy constructor: initializes the shared string and takes a
    // reference on the source text (16-bit header counter).
    SharedString(const SharedString &other) {
        d20e_string_init_8020c5c0(this);
        text = other.text;
        ++*d20e_string_header_80341884(this);
    }

    ~SharedString() {
        d20e_string_finish_8020c5c4(this);
        d20e_string_release_80341588(this);
    }

    SharedString &operator=(const SharedString &other) {
        // The original allocation header begins six bytes before the text;
        // its reference counter is unsigned sixteen-bit, including wrapping.
        ++reinterpret_cast<unsigned short *>(other.text)[-3];
        unsigned short *header = reinterpret_cast<unsigned short *>(text) - 3;
        if (--*header == 0) {
            d20e_release_header_8020bb2c(header);
        }
        text = other.text;
        return *this;
    }
};

struct StringBinding {
    unsigned header[2];
    SharedString value;
};

extern SharedString d20e_empty_804b06a0[];
struct Vec3 { float x, y, z; };
struct VectorBinding {
    unsigned header[2];
    Vec3 value;
    void set(const Vec3 &v) { value = v; }
};
struct Vec2 { float x, y; };
struct Vec2Binding {
    unsigned header[2];
    Vec2 value;
    void set(const Vec2 &v) { value = v; }
};
struct Colour {
    unsigned char r, g, b, a;
    Colour(unsigned char r_, unsigned char g_, unsigned char b_, unsigned char a_) : r(r_), g(g_), b(b_), a(a_) {}
};
struct ColourBinding {
    unsigned header[2];
    Colour value;
};
// 20-byte property descriptor registered by the property helpers.
struct PropertyInfo {
    const char *name;
    unsigned short size;
    unsigned char elementType;
    unsigned char type;
    void *typeObject;
    const void *member;
    int unknown16;
    void clear() { memset(this, 0, sizeof(*this)); }
};
extern "C" {
StringBinding *fn_801ed24c(void *, const void *);
VectorBinding *fn_801f0210(void *, const void *);
Vec2Binding *fn_801f00f0(void *, const void *);
ColourBinding *fn_801f15e0(void *, const void *);
void * fn_801eb834(void *, const void *);
void * fn_801eb674(void *, const void *);
void * fn_801ec52c(void *, const void *);
void * fn_801f25b0(void *, PropertyInfo *);
void * fn_801efec4(void *, PropertyInfo *);
void * fn_801efdfc(void *, PropertyInfo *);
void * fn_801eff8c(void *, PropertyInfo *);
void fn_801e8d9c(void *);
}
extern const unsigned char desc_803c5224[];
extern const unsigned char desc_803c5248[];
extern const unsigned char desc_803c526c[];
extern const unsigned char desc_803c5290[];
extern const unsigned char desc_803c52b4[];
extern const unsigned char desc_803c52d8[];
extern const unsigned char desc_803c52fc[];
extern const unsigned char desc_803c5320[];
extern const unsigned char desc_803c5344[];
extern const unsigned char desc_803c5368[];
extern const unsigned char desc_803c538c[];
extern const unsigned char desc_803c53b0[];
extern const unsigned char desc_803c53d8[];
extern const unsigned char desc_803c5400[];
extern const unsigned char desc_803c5428[];
extern const unsigned char desc_803c5450[];
extern const unsigned char desc_803c5478[];
extern const unsigned char desc_803c54a0[];
extern const unsigned char desc_803c54c8[];
extern const unsigned char desc_803c54f0[];
extern char lbl_803c48a8[], lbl_803c48b4[], lbl_803c48c0[], lbl_803c5514[], lbl_803c551c[];
extern char lbl_8045e47c[], lbl_8045ed7c[], lbl_8045ed4c[], lbl_8045e004[];
extern const char lbl_80401054[];
extern float constant_803c5524[];
extern "C" int w3d_d21e_register_land_properties_8024e1fc(void *owner) {
    fn_801ed24c(owner, desc_803c5224)->value = SharedString(d20e_empty_804b06a0[0]);
    VectorBinding *v1 = fn_801f0210(owner, desc_803c5248);
    float zero = constant_803c5524[0];
    Vec3 t1;
    Vec3 *p1 = &t1;
    p1->x = zero;
    p1->y = zero;
    p1->z = zero;
    v1->set(t1);
    VectorBinding *v2 = fn_801f0210(owner, desc_803c526c);
    Vec3 t2;
    Vec3 *p2 = &t2;
    p2->x = zero;
    p2->y = zero;
    p2->z = zero;
    v2->set(t2);
    VectorBinding *v3 = fn_801f0210(owner, desc_803c5290);
    Vec3 t3;
    Vec3 *p3 = &t3;
    p3->x = zero;
    p3->y = zero;
    p3->z = zero;
    v3->set(t3);
    VectorBinding *v4 = fn_801f0210(owner, desc_803c52b4);
    Vec3 t4;
    Vec3 *p4 = &t4;
    p4->x = zero;
    p4->y = zero;
    p4->z = zero;
    v4->set(t4);
    VectorBinding *v5 = fn_801f0210(owner, desc_803c52d8);
    Vec3 t5;
    Vec3 *p5 = &t5;
    p5->x = zero;
    p5->y = zero;
    p5->z = zero;
    v5->set(t5);
    VectorBinding *v6 = fn_801f0210(owner, desc_803c52fc);
    Vec3 t6;
    Vec3 *p6 = &t6;
    p6->x = zero;
    p6->y = zero;
    p6->z = zero;
    v6->set(t6);
    VectorBinding *v7 = fn_801f0210(owner, desc_803c5320);
    Vec3 t7;
    Vec3 *p7 = &t7;
    p7->x = zero;
    p7->y = zero;
    p7->z = zero;
    v7->set(t7);
    Vec2Binding *w1 = fn_801f00f0(owner, desc_803c5344);
    Vec2 u1;
    u1.x = zero;
    u1.y = zero;
    w1->set(u1);
    Vec2Binding *w2 = fn_801f00f0(owner, desc_803c5368);
    Vec2 u2;
    u2.x = zero;
    u2.y = zero;
    w2->set(u2);
    VectorBinding *v8 = fn_801f0210(owner, desc_803c538c);
    Vec3 t8;
    Vec3 *p8 = &t8;
    p8->x = zero;
    p8->y = zero;
    p8->z = zero;
    v8->set(t8);
    static PropertyInfo edgeOffset1 = ({
        PropertyInfo t;
        memset(&t, 0, sizeof(t));
        t.name = lbl_803c48a8;
        t.size = 148;
        t.elementType = 15;
        t.type = 9;
        t.typeObject = lbl_8045e47c;
        t;
    });
    fn_801f25b0(owner, &edgeOffset1);
    static PropertyInfo edgeOffset2 = ({
        PropertyInfo t;
        memset(&t, 0, sizeof(t));
        t.name = lbl_803c48b4;
        t.size = 144;
        t.elementType = 16;
        t.type = 9;
        t.typeObject = lbl_8045e47c;
        t;
    });
    fn_801f25b0(owner, &edgeOffset2);
    fn_801eb834(owner, desc_803c53b0);
    fn_801eb834(owner, desc_803c53d8);
    fn_801eb834(owner, desc_803c5400);
    static PropertyInfo heightMap = ({
        PropertyInfo t;
        unsigned n = sizeof(t);
        memset(&t, 0, n);
        t.name = lbl_803c48c0;
        t.size = 184;
        t.elementType = n;
        t.type = 9;
        t.typeObject = lbl_8045ed7c;
        t;
    });
    fn_801efec4(owner, &heightMap);
    fn_801eb674(owner, desc_803c5428);
    fn_801eb674(owner, desc_803c5450);
    fn_801ec52c(owner, desc_803c5478);
    fn_801eb674(owner, desc_803c54a0);
    fn_801eb674(owner, desc_803c54c8);
    fn_801f15e0(owner, desc_803c54f0)->value = Colour(0, 0, 0, 0);
    static PropertyInfo voxels = ({
        PropertyInfo t;
        memset(&t, 0, sizeof(t));
        t.name = lbl_803c5514;
        t.size = 172;
        t.elementType = 27;
        t.type = 9;
        t.typeObject = lbl_8045ed4c;
        t;
    });
    fn_801efdfc(owner, &voxels);
    static PropertyInfo details = ({
        PropertyInfo t;
        memset(&t, 0, sizeof(t));
        t.name = lbl_803c551c;
        t.size = 168;
        t.elementType = 28;
        t.type = 9;
        t.typeObject = lbl_8045e004;
        t.member = lbl_80401054;
        t;
    });
    fn_801eff8c(owner, &details);
    fn_801e8d9c(owner);
    return 0;
}
