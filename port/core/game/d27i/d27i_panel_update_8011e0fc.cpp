#include "w3d_ptr.h"
#line 1 "d27i_panel_update_8011e0fc.cpp"
// GWMP8P rev0 0x8011e0fc. Per-frame update of a fading panel: runs the panel
// state machine, blinks a widget at 750 unit intervals, drives the colour
// fade, and on activation forwards settings through a held service.
struct Color { unsigned char r, g, b; signed char a; };
struct Widget;
struct WidgetVt { char u0[76]; Ptr32<void (Ptr32<Widget>, const struct Vec2 &, int)> place; char u80[8]; Ptr32<void (Ptr32<Widget>, int)> show; };
struct Widget { Ptr32<WidgetVt> vt; };
struct Vec2 { float v[4]; };
struct Service;
struct ServiceVt { char u0[12]; Ptr32<void (Ptr32<Service>)> add; Ptr32<void (Ptr32<Service>)> release; char u20[4]; Ptr32<void (Ptr32<Service>, int)> setb; char u28[20]; Ptr32<void (Ptr32<Service>, int)> seta; };
struct Service { Ptr32<ServiceVt> vt; };
struct Ref {
    Ptr32<Service> p;
    template <class W3dU> Ref(Ptr32<W3dU> w3d_p) : Ref((Service *)w3d_p.get()) {}
 Ref(Service *q) { p = q; if (p) p->vt->add(p); }
    Ref(const Ref &o);
    ~Ref() { if (p) p->vt->release(p); }
};
struct Stage;
struct StageVt { char u0[68]; Ptr32<void (Ptr32<Stage>, int, int, int)> start; };
struct Stage { Ptr32<StageVt> vt; };
struct Game { char u0[48]; Ptr32<Stage> stage; };
struct Message { unsigned short id; Ptr32<void> vt; };
struct Self {
    char u0[28]; Ptr32<Widget> a; Ptr32<Widget> b; Ptr32<Widget> c; Ptr32<Widget> panel;
    char u44[4]; int ra; int rb;
    char u56[4]; int w60; int w64; int w68; unsigned state;
    char u76[8]; Ptr32<Widget> other; Ptr32<Widget> d; Ptr32<Widget> e;
    char u96[4]; unsigned blink; unsigned next; int u108; char u112[4]; unsigned char fade; char u117[3]; unsigned due;
};
struct Context { char u0[52]; unsigned now; };
extern Ptr32<Game> game_804b1788;
extern Ptr32<void> arena_804b1754;
extern char vt_8040db38[];
extern char svc_804140d0[];
extern int name_804af47c;
extern "C" int ready_80181ccc(Ptr32<Widget>, int);
extern "C" void vec_8011f2c8(Ptr32<Self>, Vec2 &);
extern "C" Ptr32<void> alloc_801613f0(Ptr32<void>, int);
extern "C" unsigned short msgid_8015f5a0(Ptr32<int>, int);
extern "C" int post_8016239c(Ptr32<Message>);
extern "C" Ptr32<Color> color_80189760(Ptr32<Widget>);
extern "C" Ptr32<Context> ctx_80165254();
extern "C" Ptr32<Service> svc_8020b680(Ptr32<void>);
extern "C" int w3d_fe_title_hide_press(void);   // core/native/fe_bridge.cpp (v28): en 3DS el "Press START" va abajo
extern "C" int d27i_panel_update_8011e0fc(Ptr32<Self> self, unsigned now) {
    int done = 0;
    switch (self->state) {
    case 0:
        done = 1;
        if (ready_80181ccc(self->a, self->ra)) {
            Vec2 v;
            vec_8011f2c8(self, v);
            self->other->vt->place(self->other, v, 0);
            self->state = done;
        }
        break;
    case 1:
        if (now > self->next && ready_80181ccc(self->c, self->rb)) {
            self->blink ^= 1;
            self->other->vt->show(self->other, w3d_fe_title_hide_press() ? 0 : self->blink);
            self->next = now + 750;
        }
        break;
    case 2:
        self->state = 3;
        done = 1;
        break;
    case 3:
        if (self->fade == 0) {
            self->state = 4;
            Ptr32<Message> m = (Ptr32<Message>)alloc_801613f0(arena_804b1754, 8);
            m->id = msgid_8015f5a0(&name_804af47c, 1);
            m->vt = vt_8040db38;
            post_8016239c(m);
        }
        break;
    }
    switch (self->fade) {
    case 0:
        break;
    case 1:
        if (now >= self->due) {
            unsigned char z = 0;
            Ptr32<Color> k = color_80189760(self->panel);
            k->r = z; k->g = z; k->b = z; k->a = z;
            self->panel->vt->show(self->panel, 0);
            self->fade = z;
        } else {
            unsigned char al = (unsigned char)((float)(self->due - now) / 4000.0f * 255.0f);
            Ptr32<Color> k = color_80189760(self->panel);
            k->r = 0; k->g = 0; k->b = 0; k->a = al;
        }
        break;
    case 2:
        if (now > self->due) {
            self->fade = 3;
            self->due = ctx_80165254()->now + 2000;
            self->panel->vt->show(self->panel, 1);
        }
        break;
    case 3:
        if (now >= self->due) {
            Ptr32<Color> k = color_80189760(self->panel);
            k->a = -1; k->g = 0; k->b = 0; k->r = 0;
            self->fade = 0;
            self->a->vt->show(self->a, 0);
            self->b->vt->show(self->b, 0);
            self->c->vt->show(self->c, 0);
            self->d->vt->show(self->d, 0);
            self->e->vt->show(self->e, 0);
        } else {
            unsigned char al = (unsigned char)((1.0f - (float)(self->due - now) / 2000.0f) * 255.0f);
            Ptr32<Color> k = color_80189760(self->panel);
            k->r = 0; k->g = 0; k->b = 0; k->a = al;
        }
        break;
    }
    if (done) {
        Ref s(svc_8020b680(svc_804140d0));
        s.p->vt->seta(s.p, self->w68);
        s.p->vt->setb(s.p, self->w64);
        game_804b1788->stage->vt->start(game_804b1788->stage, self->w60, self->w64, self->w68);
    }
    return 0;
}


