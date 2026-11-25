#include "w3d_ptr.h"
#line 1 "d31l_panel_message_802aff9c.cpp"
// GWMP8P rev0 0x802aff9c. Panel message handler: focus messages; when
// enabled, the four navigation messages post their config targets, select
// and release press the panel, and the pointer messages hit-test it; the
// click messages post the config action; finally a matching select string
// starts or stops the mode transition. Field names are inferred.
struct Str { Ptr32<char> p; unsigned length() const { return *(Ptr32<unsigned short>)(p - 4); } };
struct Msg { char u[8]; };
struct Message { unsigned short id; };
struct Note { unsigned short id; Ptr32<void> vt; };
struct Ent { char u[16]; int w16; };
struct Cfg { char u0[8]; unsigned char b11; char w3d_tag_rest[3]; char u12[60]; Str s72, s76, s80, s84, s88; };
struct Panel;
struct PanelVt { char u0[16]; Ptr32<void (Ptr32<Panel>)> back; char u20[20]; Ptr32<void (Ptr32<Panel>, int)> focus; char u44[4]; Ptr32<int (Ptr32<Panel>, float, float)> hit; Ptr32<void (Ptr32<Panel>, int)> press; Ptr32<void (Ptr32<Panel>)> click; };
struct Panel {
    char u0[12];
    Ptr32<Cfg> cfg;
    char u16[16];
    Ptr32<Ent> e32; Ptr32<Ent> e36;
    char u40[60];
    int w100;
    char u104[8];
    int w112;
    char u116[32];
    int w148, w152, w156;
    char u160[4];
    int w164;
    char u168[12];
    Ptr32<PanelVt> vt;
};
struct Flags { char u[96]; int w96; };
extern int busy_804abb48;
extern int input_804abc68;
extern Ptr32<Flags> flags_804aac54;
extern Ptr32<void> arena_804b1754;
extern Msg msg_804b0fb8, msg_804b0fc0, msg_804b0f80, msg_804b0f88, msg_804b0f90, msg_804b0f98, msg_804b0fa0, msg_804b0fb0, msg_804b0fd0, msg_804b0fc8, msg_804b0fd8, msg_804b0fe0, msg_804b0fe8, msg_804b0fa8;
extern char vt_8040db38[];
extern "C" {
int fn_802b264c(Ptr32<void>);
int fn_8015f65c(unsigned short, Ptr32<Msg>);
int fn_8015f5a0(Ptr32<Msg>, int);
Ptr32<void> fn_801613f0(Ptr32<void>, unsigned);
Ptr32<void> fn_8010a8e0(Ptr32<void>, unsigned short, Ptr32<const char>);
int fn_8016239c(Ptr32<void>);
void fn_80069a50(Ptr32<Message>, Ptr32<float>, Ptr32<float>);
void fn_802b22b0(Ptr32<Panel>);
void fn_802b11d8(Ptr32<Panel>, int);
Ptr32<const char> fn_8010a8fc(Ptr32<Message>);
int strcmp(Ptr32<const char>, Ptr32<const char>);
}
extern "C" void d31l_panel_message_802aff9c(Ptr32<Panel> self, Ptr32<Message> m) {
    int busy = busy_804abb48;
    if (!fn_802b264c(self) || self->w164) return;
    if (fn_8015f65c(m->id, &msg_804b0fb8))
        self->vt->focus(self, 1);
    else if (fn_8015f65c(m->id, &msg_804b0fc0))
        self->vt->focus(self, 0);
    if (busy) return;
    if (!self->w100) {
        int on = self->w152 == 1 ? self->w156 : self->w148;
        if (on) {
            if (fn_8015f65c(m->id, &msg_804b0f80)) {
                if (self->cfg->s84.length())
                    fn_8016239c(fn_8010a8e0(fn_801613f0(arena_804b1754, 12), fn_8015f5a0(&msg_804b0fc8, 1), self->cfg->s84.p));
            } else if (fn_8015f65c(m->id, &msg_804b0f88)) {
                if (self->cfg->s80.length())
                    fn_8016239c(fn_8010a8e0(fn_801613f0(arena_804b1754, 12), fn_8015f5a0(&msg_804b0fc8, 1), self->cfg->s80.p));
            } else if (fn_8015f65c(m->id, &msg_804b0f90)) {
                if (self->cfg->s76.length())
                    fn_8016239c(fn_8010a8e0(fn_801613f0(arena_804b1754, 12), fn_8015f5a0(&msg_804b0fc8, 1), self->cfg->s76.p));
            } else if (fn_8015f65c(m->id, &msg_804b0f98)) {
                if (self->cfg->s72.length())
                    fn_8016239c(fn_8010a8e0(fn_801613f0(arena_804b1754, 12), fn_8015f5a0(&msg_804b0fc8, 1), self->cfg->s72.p));
            } else if (fn_8015f65c(m->id, &msg_804b0fa0)) {
                self->vt->back(self);
                self->vt->press(self, 1);
            } else if (fn_8015f65c(m->id, &msg_804b0fb0))
                self->vt->press(self, 0);
            else if (fn_8015f65c(m->id, &msg_804b0fd0)) {
                float a, b;
                fn_80069a50(m, &a, &b);
                if (input_804abc68 == -1 && self->vt->hit(self, a, b))
                    self->vt->click(self);
            }
        } else if (fn_8015f65c(m->id, &msg_804b0fd0)) {
            float a, b;
            fn_80069a50(m, &a, &b);
            if (input_804abc68 == -1 && self->vt->hit(self, a, b))
                fn_8016239c(fn_8010a8e0(fn_801613f0(arena_804b1754, 12), fn_8015f5a0(&msg_804b0fc8, 1), self->cfg->s88.p));
        }
            if (fn_8015f65c(m->id, &msg_804b0fd8)) {
                float a, b;
                fn_80069a50(m, &a, &b);
                if (!(flags_804aac54->w96 & 0x1000000) && (self->cfg->b11 ^ 4) & 4 && self->vt->hit(self, a, b)) {
                if (self->w112) {
                    fn_8016239c(fn_8010a8e0(fn_801613f0(arena_804b1754, 12), fn_8015f5a0(&msg_804b0fc8, 1), self->cfg->s88.p));
                    Ptr32<Note> n = (Ptr32<Note>)fn_801613f0(arena_804b1754, 8);
                    n->id = fn_8015f5a0(&msg_804b0fa0, 1);
                    n->vt = vt_8040db38;
                    fn_8016239c(n);
                }
                else
                    fn_802b22b0(self);
                }
            }
            if (fn_8015f65c(m->id, &msg_804b0fe0)) {
                float a, b;
                fn_80069a50(m, &a, &b);
                if (!(flags_804aac54->w96 & 0x1000000) && (self->cfg->b11 ^ 4) & 4 && self->vt->hit(self, a, b)) {
                if (self->w112) {
                    fn_8016239c(fn_8010a8e0(fn_801613f0(arena_804b1754, 12), fn_8015f5a0(&msg_804b0fc8, 1), self->cfg->s88.p));
                    Ptr32<Note> n = (Ptr32<Note>)fn_801613f0(arena_804b1754, 8);
                    n->id = fn_8015f5a0(&msg_804b0fa8, 1);
                    n->vt = vt_8040db38;
                    fn_8016239c(n);
                }
                }
            }
            if (fn_8015f65c(m->id, &msg_804b0fe8)) {
                float a, b;
                fn_80069a50(m, &a, &b);
                if (!(flags_804aac54->w96 & 0x1000000) && (self->cfg->b11 ^ 4) & 4 && self->vt->hit(self, a, b)) {
                if (self->w112) {
                    fn_8016239c(fn_8010a8e0(fn_801613f0(arena_804b1754, 12), fn_8015f5a0(&msg_804b0fc8, 1), self->cfg->s88.p));
                    Ptr32<Note> n = (Ptr32<Note>)fn_801613f0(arena_804b1754, 8);
                    n->id = fn_8015f5a0(&msg_804b0fb0, 1);
                    n->vt = vt_8040db38;
                    fn_8016239c(n);
                }
                else
                    fn_802b22b0(self);
                }
            }
    }
    if (fn_8015f65c(m->id, &msg_804b0fc8)) {
        Ptr32<const char> t = fn_8010a8fc(m);
        if (strcmp(self->cfg->s88.p, t) == 0) {
            fn_802b11d8(self, 1);
            self->e32->w16 = 1;
            self->e36->w16 = 1;
        } else {
            self->e32->w16 = 0;
            self->e36->w16 = 0;
            fn_802b11d8(self, 0);
        }
    }
}


