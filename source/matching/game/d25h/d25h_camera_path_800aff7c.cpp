// Camera path constructor (Worms 3D GameCube PAL, 0x800aff7c, 388 bytes).
//
// Field names are inferred. The node local starts at zero and copies into the
// tail local, which keeps the original's separate zero load after the calls.

struct Obj;
struct ObjVt { void *u[3]; void (*addref)(Obj *); void (*release)(Obj *); };
struct Obj { ObjVt *vt; };
struct Ref {
    Obj *p;
    Ref() { p = 0; }
    ~Ref() { if (p) p->vt->release(p); }
    void operator=(Obj *o) { if (o) o->vt->addref(o); if (p) p->vt->release(p); p = o; }
};
struct Handle {
    Obj *p;
    Handle() { p = 0; }
    Handle(const Handle &);
    ~Handle() { if (p) p->vt->release(p); }
};
extern "C" int fn_800fc1b0(const char *const *, Handle *);
extern "C" Obj *fn_80343744(Obj *);
extern "C" Obj *fn_80342a78(Obj *);
extern "C" char *fn_802efd7c(char *, const char *);
struct Node { unsigned char u0[20]; Node *prev; Node *next; };
struct CameraPath;
extern "C" Node *fn_800b0474(CameraPath *, int, char *, Node **);
extern const char *lbl_804aacb8;
extern const char lbl_80382320[];
struct CameraPath {
    unsigned char u0[4];
    Node *head;   // +4
    Node *cur;    // +8
    Node *tail;   // +12
    float t;      // +16
    float speed;  // +20
    Ref a;        // +24
    Ref b;        // +28
    CameraPath(char *list, const char *key, int loop, float rate);
};
CameraPath::CameraPath(char *list, const char *key, int loop, float rate) {
    Handle h;
    const char *name = lbl_80382320;
    fn_800fc1b0(&name, &h);
    a = fn_80343744(h.p);
    fn_800fc1b0(&key, &h);
    b = fn_80342a78(h.p);
    char *tok = fn_802efd7c(list, lbl_804aacb8);
    Node *n = 0;
    Node *last = n;
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
