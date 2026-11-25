#include "w3d_ptr.h"
#line 1 "d27l_setup_frame_nodes_802b192c.cpp"
// GWMP8P rev0 0x802b192c. Panel transform setup: binds the base node, reads
// the position from the config, binds the frame node under the Frontend node
// name when any of four config strings is set and under the null name
// otherwise, then sets position, scale, rotation and attachment. Node method
// names are inferred from the argument vectors; the string address names
// come from the original data.
extern "C" void fn_8020c5c4(Ptr32<void>), fn_80341588(Ptr32<void>);
struct Str {
    Ptr32<char> p;
    template <class W3dU> Str(Ptr32<W3dU> w3d_p) : Str((const char *)w3d_p.get()) {}
 Str(const char *);
    Str(const Str &);
    ~Str() {
        fn_8020c5c4(this);
        fn_80341588(this);
    }
    unsigned len() const { return *(Ptr32<unsigned short>)(p - 4); }
};
struct Vec {
    float x, y, z;
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) {
        float a = o.x, b = o.y, c = o.z;
        x = a;
        y = b;
        z = c;
    }
};
struct Node;
struct NodeVt {
    char u0[76];
    Ptr32<void (Ptr32<Node>, const Vec &, int)> move;
    Ptr32<void (Ptr32<Node>, const Vec &, int)> turn;
    Ptr32<void (Ptr32<Node>, const Vec &, int)> scale;
    Ptr32<void> u88;
    Ptr32<void (Ptr32<Node>, Ptr32<Node>, Ptr32<const char>)> attach;
};
struct Node { Ptr32<NodeVt> vt; };
struct Cfg { char u0[32]; Vec pos; char u44[48]; Str s92, s96, s100, s104; };
struct Self {
    char u0[12];
    Ptr32<Cfg> cfg;
    char u16[68];
    Ptr32<Node> base;
    Ptr32<Node> frame;
};
extern const char null_803d7a6c[], front_803d7a74[], locator_803d7a84[];
extern "C" int fn_8015adf4(const Str &, Ptr32<Ptr32<Node>>, unsigned char);
extern "C" void d27l_setup_frame_nodes_802b192c(Ptr32<Self> self) {
    fn_8015adf4(Str(null_803d7a6c), &self->base, 255);
    Ptr32<Cfg> c = self->cfg;
    Vec pos = c->pos;
    Vec a(0.0f, 0.0f, 0.0f);
    Vec b(1.0f, 1.0f, 1.0f);
    Vec d(0.0f, 0.0f, 0.0f);
    if (c->s104.len() || c->s100.len() || c->s96.len() || c->s92.len()) {
        fn_8015adf4(Str(front_803d7a74), &self->frame, 255);
        self->frame->vt->move(self->frame, pos, 0);
        self->frame->vt->scale(self->frame, b, 0);
        self->frame->vt->turn(self->frame, a, 0);
        self->frame->vt->attach(self->frame, self->base, locator_803d7a84);
    } else {
        fn_8015adf4(Str(null_803d7a6c), &self->frame, 255);
        self->frame->vt->move(self->frame, pos, 0);
        self->frame->vt->scale(self->frame, b, 0);
        self->frame->vt->turn(self->frame, a, 0);
        self->frame->vt->attach(self->frame, self->base, 0);
    }
    self->base->vt->move(self->base, d, 1);
    self->base->vt->turn(self->base, d, 1);
    self->base->vt->scale(self->base, b, 0);
}


