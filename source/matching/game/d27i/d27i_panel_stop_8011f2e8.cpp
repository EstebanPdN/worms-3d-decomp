// GWMP8P rev0 0x8011f2e8. Stop handler of a fading panel. Reference members
// are cleared through a smart pointer assignment that adds the new value,
// releases the old one and stores it; assigning null folds the add away and
// splits the zero registers exactly as in the original.
struct Obj;
struct ObjVt { char u0[12]; void (*add)(Obj *); void (*release)(Obj *); char u20[16]; int (*a36)(Obj *); char u40[16]; int (*a56)(Obj *); int (*a60)(Obj *); int (*a64)(Obj *); };
struct Obj { ObjVt *vt; };
struct Ref { Obj *p; Ref &operator=(Obj *q) { if (q) q->vt->add(q); if (p) p->vt->release(p); p = q; return *this; } };
struct Stage;
struct StageVt { char u0[40]; void (*b40)(Stage *, int); void (*b44)(Stage *, int); void (*b48)(Stage *, int); void (*b52)(Stage *, int); };
struct Stage { StageVt *vt; };
struct Game { char u0[48]; Stage *stage; };
struct Log;
struct LogVt { char u0[196]; void (*write)(Log *, const char *, int); };
struct Log { LogVt *vt; };
struct Sys { char u0[116]; Log *log; };
struct Self { char u0[28]; Ref o28; Ref o32; Ref o36; Ref o40; char u44[12]; Ref o56; Ref o60; Ref o64; Ref o68; char u72[8]; Ref o80; Ref o84; Ref o88; Ref o92; };
extern Game *game_804b1788;
extern Sys *sys_804b17ec;
extern const char text_8039b40c[];
extern "C" int format_803442b4(char *, const char *, ...);
extern "C" void d27i_panel_stop_8011f2e8(Self *self) {
    if (self->o56.p) {
        { Stage *st = game_804b1788->stage; StageVt *t = st->vt; t->b40(st, self->o56.p->vt->a36(self->o56.p)); }
        { Stage *st = game_804b1788->stage; StageVt *t = st->vt; t->b44(st, self->o56.p->vt->a56(self->o56.p)); }
        { Stage *st = game_804b1788->stage; StageVt *t = st->vt; t->b48(st, self->o56.p->vt->a60(self->o56.p)); }
        { Stage *st = game_804b1788->stage; StageVt *t = st->vt; t->b52(st, self->o56.p->vt->a64(self->o56.p)); }
    }
    self->o56 = (Obj *)0;
    self->o60 = (Obj *)0;
    self->o64 = (Obj *)0;
    self->o68 = (Obj *)0;
    self->o28 = (Obj *)0;
    self->o32 = (Obj *)0;
    self->o36 = (Obj *)0;
    self->o40 = (Obj *)0;
    {
        char buf[32];
        Log *log = sys_804b17ec->log;
        LogVt *t = log->vt;
        format_803442b4(buf, text_8039b40c);
        t->write(log, buf, 4);
    }
    self->o80 = (Obj *)0;
    self->o84 = (Obj *)0;
    self->o88 = (Obj *)0;
    self->o92 = (Obj *)0;
}
