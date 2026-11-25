// GWMP8P rev0 0x8011ddb0. Message handler of a fading panel: activation
// starts it, a timer message advances its show and hide states, rescaling
// the remaining fade time and playing the sound once.
struct Message { unsigned short id; };
struct Context { char u0[52]; unsigned now; };
struct Sound;
struct SoundVt { char u0[100]; void (*play)(Sound *, void *, int); };
struct Sound { SoundVt *vt; };
struct Game { char u0[108]; Sound *sound; };
struct Widget;
struct WidgetVt { char u0[88]; void (*show)(Widget *, int); };
struct Widget { WidgetVt *vt; };
struct Self {
    char u0[40]; Widget *panel;
    char u44[28]; unsigned state;
    char u76[8]; Widget *other;
    char u88[12]; int count;
    char u104[4]; int soundId; int playing; unsigned char fade; char u117[3]; unsigned due;
};
extern Game *game_804b1788;
extern int msg_804af474;
extern "C" int base_8015fb34(Self *, Message *);
extern "C" void start_8011e4fc(Self *);
extern "C" void stop_8011f2e8(Self *);
extern "C" int same_8015f65c(unsigned, int *);
extern "C" Context *ctx_80165254();
extern "C" int d27i_panel_fade_message_8011ddb0(Self *self, Message *m) {
    switch (m->id) {
    case 64:
        if (base_8015fb34(self, m) >= 0) {
            start_8011e4fc(self);
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
                Sound *s = game_804b1788->sound;
                if (s) {
                    int *id = &self->soundId;
                    if (*id && !self->playing) {
                        s->vt->play(s, id, 200);
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
                Sound *s = game_804b1788->sound;
                if (s) {
                    int *id = &self->soundId;
                    if (*id && !self->playing) {
                        s->vt->play(s, id, 4500);
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
