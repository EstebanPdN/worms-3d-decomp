// (Worms 3D GameCube PAL, 0x801db478).
//
// Builds a sound object's stream chain. With a source at +104, creates the
// object of class 0x80416cb8, initializes it, keeps its output in the
// reference at +172 and appends it to the list at +48, returning any error.
// If +116 is set and the mode at +108 is 0 or 1, creates the player of class
// 0x80416e78, initializes it, connects the output through 0x801e344c, and
// appends it. Otherwise sets +176. Returns the last result. Names are
// inferred.

struct Obj;
struct ObjV { virtual void v0(); virtual void AddRef(); virtual void Release(); virtual int Init(); };
struct Obj : ObjV { char u4[16]; Obj *output; };
struct Ref {
    Obj *p;
    Ref() : p(0) { }
    Ref(const Ref &);
    ~Ref() { if (p) p->Release(); }
    Ref &operator=(Obj *q) {
        if (q) q->AddRef();
        if (p) p->Release();
        p = q;
        return *this;
    }
    Ref &operator=(const Ref &r) {
        if (r.p) r.p->AddRef();
        if (p) p->Release();
        p = r.p;
        return *this;
    }
};
extern "C" void w3d_cx11b_compact_vector_grow_80210d54(void *, int);
struct RefVec {
    int n;
    int cap;
    Ref *d;
    void push(Obj *o) {
        w3d_cx11b_compact_vector_grow_80210d54(this, n + 1);
        *(Ref *)(n * 4 + (int)d) = o;
        n++;
    }
};
struct ClassRecord;
extern ClassRecord k_80416cb8[], k_80416e78[];
extern "C" Obj *w3d_s10_service_forward_8020b680(ClassRecord *);
extern "C" void w3d_stream_player_set_output_801e344c(Obj *, Obj *);
struct Self {
    char u0[48];
    RefVec list;
    char u60[44];
    int x104;
    int mode;
    char u112[4];
    int x116;
    char u120[52];
    Ref output;
    int done;
};
extern "C" int w3d_d31e_setup_stream_chain_801db478(Self *self)
{
    int hr = 0;
    Ref a;
    Ref b;
    self->mode = 1;
    self->x116 = 1;
    if (self->x104) {
        a = w3d_s10_service_forward_8020b680(k_80416cb8);
        b = a;
        hr = a.p->Init();
        if (self->output.p) self->output.p->Release();
        self->output.p = 0;
        self->output = a.p->output;
        if (!hr) self->list.push(a.p);
        else return hr;
    }
    if (self->x116) {
        if (self->mode <= 1) {
            if (self->mode >= 0) {
                a = w3d_s10_service_forward_8020b680(k_80416e78);
                hr = a.p->Init();
                if (self->output.p) w3d_stream_player_set_output_801e344c(a.p, self->output.p);
            }
        }
        if (!hr) self->list.push(a.p);
        return hr;
    }
    self->done = 1;
    return hr;
}
