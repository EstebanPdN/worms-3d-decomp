#include "w3d_ptr.h"
#line 1 "d25h_camera_path_800aff7c.cpp"
// Camera path constructor (Worms 3D GameCube PAL, 0x800aff7c, 388 bytes).
//
// Field names are inferred. The node local starts at zero and copies into the
// tail local, which keeps the original's separate zero load after the calls.

struct Obj;
struct ObjVt { Ptr32<void> u[3]; Ptr32<void (Ptr32<Obj>)> addref; Ptr32<void (Ptr32<Obj>)> release; };
struct Obj { Ptr32<ObjVt> vt; };
struct Ref {
    Ptr32<Obj> p;
    Ref() { p = 0; }
    ~Ref() { if (p) p->vt->release(p); }
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Obj *)w3d_p.get()); }
 void operator=(Obj *o) { if (o) o->vt->addref(o); if (p) p->vt->release(p); p = o; }
};
struct Handle {
    Ptr32<Obj> p;
    Handle() { p = 0; }
    Handle(const Handle &);
    ~Handle() { if (p) p->vt->release(p); }
};
extern "C" int fn_800fc1b0(Ptr32<Ptr32<const char> const>, Ptr32<Handle>);
extern "C" Ptr32<Obj> fn_80343744(Ptr32<Obj>);
extern "C" Ptr32<Obj> fn_80342a78(Ptr32<Obj>);
extern "C" Ptr32<char> fn_802efd7c(Ptr32<char>, Ptr32<const char>);
struct Node { unsigned char u0[20]; Ptr32<Node> prev; Ptr32<Node> next; };
struct CameraPath;
extern "C" Ptr32<Node> fn_800b0474(Ptr32<CameraPath>, int, Ptr32<char>, Ptr32<Ptr32<Node>>);
extern Ptr32<const char> lbl_804aacb8;
extern const char lbl_80382320[];
struct CameraPath {
    unsigned char u0[4];
    Ptr32<Node> head;   // +4
    Ptr32<Node> cur;    // +8
    Ptr32<Node> tail;   // +12
    float t;      // +16
    float speed;  // +20
    Ref a;        // +24
    Ref b;        // +28
    CameraPath(Ptr32<char> list, Ptr32<const char> key, int loop, float rate);
};
CameraPath::CameraPath(Ptr32<char> list, Ptr32<const char> key, int loop, float rate) {
    Handle h;
    Ptr32<const char> name = lbl_80382320;
    fn_800fc1b0(&name, &h);
    a = fn_80343744(h.p);
    fn_800fc1b0(&key, &h);
    b = fn_80342a78(h.p);
    Ptr32<char> tok = fn_802efd7c(list, lbl_804aacb8);
    Ptr32<Node> n = 0;
    Ptr32<Node> last = n;
    n = fn_800b0474(this, 0, tok, &last);
    if (loop) {
        n->prev = last;
        last->next = n;
    }
    cur = n;
    head = n;
    tail = last;
    speed = rate;
    t = 0.0f;
}


