// (Worms 3D GameCube PAL, 0x801a92c8).
//
// Selects a rendering mode on an object: when the mode differs from +160,
// creates an instance of class record 0x80363b54 (mode 0) or 0x80363ba4
// (otherwise) through 0x8020fcb4 and assigns it to the reference at +176
// (add new, release old, store). Stores the mode and returns 0. Names are
// inferred.

struct Obj { virtual void v0(); virtual void AddRef(); virtual void Release(); };
struct ClassInfo;
extern ClassInfo k_80363b54[], k_80363ba4[];
extern "C" Obj *w3d_r24b_invoke_ready_callback_8020fcb4(const ClassInfo *);
struct Ref {
    Obj *p;
    Ref &operator=(Obj *q) {
        if (q) q->AddRef();
        if (p) p->Release();
        p = q;
        return *this;
    }
};
struct Self { char pad[160]; int mode; char pad2[12]; Ref ref; };
extern "C" int w3d_d31e_select_mode_801a92c8(Self *self, int mode)
{
    if (mode != self->mode) {
        if (mode == 0) self->ref = w3d_r24b_invoke_ready_callback_8020fcb4(k_80363b54);
        else self->ref = w3d_r24b_invoke_ready_callback_8020fcb4(k_80363ba4);
    }
    self->mode = mode;
    return 0;
}
