#include "w3d_ptr.h"
#line 1 "d27i_panel_fade_message_8011ddb0.cpp"
// GWMP8P rev0 0x8011ddb0. Message handler of a fading panel: activation
// starts it, a timer message advances its show and hide states, rescaling
// the remaining fade time and playing the sound once.
struct Message { unsigned short id; };
struct Context { char u0[52]; unsigned now; };
struct Sound;
struct SoundVt { char u0[100]; Ptr32<void (Ptr32<Sound>, Ptr32<void>, int)> play; };
struct Sound { Ptr32<SoundVt> vt; };
struct Game { char u0[108]; Ptr32<Sound> sound; };
struct Widget;
struct WidgetVt { char u0[88]; Ptr32<void (Ptr32<Widget>, int)> show; };
struct Widget { Ptr32<WidgetVt> vt; };
struct Self {
    char u0[40]; Ptr32<Widget> panel;
    char u44[28]; unsigned state;
    char u76[8]; Ptr32<Widget> other;
    char u88[12]; int count;
    char u104[4]; int soundId; int playing; unsigned char fade; char u117[3]; unsigned due;
};
extern Ptr32<Game> game_804b1788;
extern int msg_804af474;
extern "C" int base_8015fb34(Ptr32<Self>, Ptr32<Message>);
extern "C" void start_8011e4fc(Ptr32<Self>);
extern "C" void stop_8011f2e8(Ptr32<Self>);
extern "C" int same_8015f65c(unsigned, Ptr32<int>);
extern "C" Ptr32<Context> ctx_80165254();
// Port: en el título (modo 5) la música del panel no se funde al irse; pasa al menú (core/native/fe_bridge.cpp).
extern "C" int w3d_fe_title_keep(Ptr32<int> id);
// Port: con dos pantallas el panel negro del fundido llega hasta abajo del lienzo alto (fe_bridge.cpp); 0: como estaba.
extern "C" int w3d_fe_title_fade_h(void);
extern "C" Ptr32<float> size_8018963c(Ptr32<Widget>);
extern "C" int d27i_panel_fade_message_8011ddb0(Ptr32<Self> self, Ptr32<Message> m) {
    switch (m->id) {
    case 64:
        if (base_8015fb34(self, m) >= 0) {
            start_8011e4fc(self);
            if (int h = w3d_fe_title_fade_h()) if (self->panel) size_8018963c(self->panel)[1] = (float)h;
            return 0;
        }
        return 0x80004005;
    case 66:
        stop_8011f2e8(self);
        break;
    default:
        if (same_8015f65c(m->id, &msg_804af474)) {
            switch (self->state) {
            case 0: {
                Ptr32<Sound> s = game_804b1788->sound;
                if (s) {
                    Ptr32<int> id = &self->soundId;
                    if (*id && !self->playing) {
                        if (!w3d_fe_title_keep(id)) s->vt->play(s, id, 200);
                        self->playing = 1;
                    }
                }
            }
            case 2:
                if (self->fade != 3) {
                    if (self->fade == 1) {
                        float t = (float)(self->due - ctx_80165254()->now) / 4000.0f;
                        unsigned now = ctx_80165254()->now;
                        self->due = now + (unsigned)(t * 2000.0f);
                    } else {
                        self->due = ctx_80165254()->now + 2000;
                    }
                    self->fade = 3;
                }
                self->state = 3;
                self->panel->vt->show(self->panel, 1);
                break;
            case 1: {
                self->count = 0;
                self->other->vt->show(self->other, 0);
                self->state = 2;
                if (self->fade == 1) {
                    float t = (float)(self->due - ctx_80165254()->now) / 4000.0f;
                    unsigned now = ctx_80165254()->now;
                    self->due = now + (unsigned)((1.0f - t) * 2000.0f);
                } else {
                    self->due = ctx_80165254()->now + 2000;
                }
                self->panel->vt->show(self->panel, 1);
                self->fade = 3;
                Ptr32<Sound> s = game_804b1788->sound;
                if (s) {
                    Ptr32<int> id = &self->soundId;
                    if (*id && !self->playing) {
                        if (!w3d_fe_title_keep(id)) s->vt->play(s, id, 4500);
                        self->playing = 1;
                    }
                }
                break;
            }
            }
        }
    }
    return base_8015fb34(self, m);
}


