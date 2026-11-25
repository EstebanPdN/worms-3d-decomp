#include "w3d_ptr.h"
#line 1 "d27i_panel_stop_8011f2e8.cpp"
// GWMP8P rev0 0x8011f2e8. Stop handler of a fading panel. Reference members
// are cleared through a smart pointer assignment that adds the new value,
// releases the old one and stores it; assigning null folds the add away and
// splits the zero registers exactly as in the original.
struct Obj;
struct ObjVt { char u0[12]; Ptr32<void (Ptr32<Obj>)> add; Ptr32<void (Ptr32<Obj>)> release; char u20[16]; Ptr32<int (Ptr32<Obj>)> a36; char u40[16]; Ptr32<int (Ptr32<Obj>)> a56; Ptr32<int (Ptr32<Obj>)> a60; Ptr32<int (Ptr32<Obj>)> a64; };
struct Obj { Ptr32<ObjVt> vt; };
struct Ref { Ptr32<Obj> p; template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Obj *)w3d_p.get()); }
 Ref &operator=(Obj *q) { if (q) q->vt->add(q); if (p) p->vt->release(p); p = q; return *this; } };
struct Stage;
struct StageVt { char u0[40]; Ptr32<void (Ptr32<Stage>, int)> b40; Ptr32<void (Ptr32<Stage>, int)> b44; Ptr32<void (Ptr32<Stage>, int)> b48; Ptr32<void (Ptr32<Stage>, int)> b52; };
struct Stage { Ptr32<StageVt> vt; };
struct Game { char u0[48]; Ptr32<Stage> stage; };
struct Log;
struct LogVt { char u0[196]; Ptr32<void (Ptr32<Log>, Ptr32<const char>, int)> write; };
struct Log { Ptr32<LogVt> vt; };
struct Sys { char u0[116]; Ptr32<Log> log; };
struct Self { char u0[28]; Ref o28; Ref o32; Ref o36; Ref o40; char u44[12]; Ref o56; Ref o60; Ref o64; Ref o68; char u72[8]; Ref o80; Ref o84; Ref o88; Ref o92; };
extern Ptr32<Game> game_804b1788;
extern Ptr32<Sys> sys_804b17ec;
extern const char text_8039b40c[];
extern "C" int format_803442b4(Ptr32<char>, Ptr32<const char>, ...);
extern "C" void d27i_panel_stop_8011f2e8(Ptr32<Self> self) {
    if (self->o56.p) {
        { Ptr32<Stage> st = game_804b1788->stage; Ptr32<StageVt> t = st->vt; t->b40(st, self->o56.p->vt->a36(self->o56.p)); }
        { Ptr32<Stage> st = game_804b1788->stage; Ptr32<StageVt> t = st->vt; t->b44(st, self->o56.p->vt->a56(self->o56.p)); }
        { Ptr32<Stage> st = game_804b1788->stage; Ptr32<StageVt> t = st->vt; t->b48(st, self->o56.p->vt->a60(self->o56.p)); }
        { Ptr32<Stage> st = game_804b1788->stage; Ptr32<StageVt> t = st->vt; t->b52(st, self->o56.p->vt->a64(self->o56.p)); }
    }
    self->o56 = (Ptr32<Obj>)0;
    self->o60 = (Ptr32<Obj>)0;
    self->o64 = (Ptr32<Obj>)0;
    self->o68 = (Ptr32<Obj>)0;
    self->o28 = (Ptr32<Obj>)0;
    self->o32 = (Ptr32<Obj>)0;
    self->o36 = (Ptr32<Obj>)0;
    self->o40 = (Ptr32<Obj>)0;
    {
        char buf[32];
        Ptr32<Log> log = sys_804b17ec->log;
        Ptr32<LogVt> t = log->vt;
        format_803442b4(buf, text_8039b40c);
        t->write(log, buf, 4);
    }
    self->o80 = (Ptr32<Obj>)0;
    self->o84 = (Ptr32<Obj>)0;
    self->o88 = (Ptr32<Obj>)0;
    self->o92 = (Ptr32<Obj>)0;
}


