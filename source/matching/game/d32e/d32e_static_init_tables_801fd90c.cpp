// (Worms 3D GameCube PAL, 0x801fd90c).
//
// Static initializer of this file: clears five small globals and constructs
// the two interface tables at 0x8045e944 and 0x8045e970 (three interface
// slots, three word pairs, two interface slots each).

inline void *operator new(unsigned int, void *place) { return place; }
struct Obj { virtual void v0(); virtual void AddRef(); virtual int Release(); };
// A released-on-assignment interface pointer.
struct Ref {
    Obj *p;
    Ref() { p = 0; }
    Ref &operator=(Obj *q) {
        if (p) p->Release();
        p = q;
        return *this;
    }
};
struct Slot2 { int w[2]; };
// Three interface slots, three word pairs, two more interface slots.
struct Table {
    Ref a[3];
    Slot2 s[3];
    Ref b[2];
    Table() {
        unsigned i;
        for (i = 0; i < 3; i++) {
            a[i] = 0;
            for (unsigned j = 0; j < 2; j++) s[i].w[j] = 0;
        }
        for (i = 0; i < 2; i++) b[i] = 0;
    }
};
struct Word { int v; Word() { v = 0; } };
extern Word lbl_804b05f0, lbl_804b05e4, lbl_804b05e8, lbl_804b05ec;
extern int lbl_804b05e0;
extern char lbl_8045e944[], lbl_8045e970[];
extern "C" void w3d_d32e_static_init_tables_801fd90c(int init, int prio)
{
    if (prio == 0xffff && init) {
        lbl_804b05e0 = 0;
        new (&lbl_804b05e4) Word;
        new (&lbl_804b05e8) Word;
        new (&lbl_804b05ec) Word;
        new (&lbl_804b05f0) Word;
        new (lbl_8045e944) Table;
        new (lbl_8045e970) Table;
    }
}
