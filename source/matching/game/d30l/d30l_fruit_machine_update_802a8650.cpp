// GWMP8P rev0 0x802a8650. Wormpot fruit-machine per-frame update: advances
// the breathe and slot clips, steps the three reels through their spin and
// nudge clips by the flag word at +1340, stops each reel at its target digit
// by forcing a nudge action, and stops the spin sound. Strings, literals and
// flag values are from the original; field names are inferred.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
};
struct Node;
struct NodeVt { char u[96]; void (*set)(Node *, const char *, const Vec &); };
struct Node { NodeVt *vt; };
struct Scene { char u[108]; Node *root; };
struct Sound;
struct SoundVt { char u[20]; void (*start)(Sound *); void (*stop)(Sound *); char u28[8]; int (*playing)(Sound *); char u40[16]; void (*param)(Sound *, int, const Vec &); };
struct Sound { SoundVt *vt; };
struct Slot {
    int type;
    char u4[32];
    const char *clip;
    const char *intro;
    char u44[4];
    int clip_handle;
    int intro_handle;
    char u56[16];
};
struct PanelVt { char u[56]; int (*update)(struct Sub *); };
struct Sub { char u0[180]; PanelVt *vt; };
struct Menu {
    char u0[28];
    Sub sub;
    char u212[32];
    void *model;
    void *reel[3];
    int breathe;
    int idle;
    Slot slots[11];
    int handle[3];
    int index;
    char u1076[240];
    int digit[3];
    int target[3];
    unsigned flags;
    unsigned next[3];
    Sound *sound;
    char u1360[16];
    int busy;
};
extern "C" {
int fn_802b0668(Sub *, unsigned);
int fn_80181d00(void *, int);
int fn_8018179c(void *, int, int);
int fn_80181640(void *, const char *, int *, float, float, float, int);
int fn_802aa8a4(Menu *, int);
void fn_802aaf5c(Menu *, int, int);
void fn_802ab24c(Menu *);
int fn_802a9058(Menu *, int, int);
void fn_802aaa8c(Menu *);
}
extern Scene *scene_804b1788;

extern "C" int d30l_fruit_machine_update_802a8650(Menu *self, unsigned now) {
    float zero = 0.0f, one = 1.0f;
    Vec v;
    Vec *pv = &v;
    pv->x = zero; pv->y = zero; pv->z = one;
    fn_802b0668(&self->sub, now);
    if (self->flags & 2) {
        int r = fn_80181d00(self->model, self->breathe);
        if (!r) {
            self->flags = r;
            fn_80181640(self->model, "Breathe", &self->idle, one, zero, zero, 0);
            fn_8018179c(self->model, self->idle, 1);
            fn_802aa8a4(self, 0);
        }
    }
    {
    unsigned fl = self->flags;
    if (fl & 4) {
        if (self->slots[self->index].intro) {
            if (!fn_80181d00(self->model, self->slots[self->index].intro_handle))
                self->flags &= ~4;
        } else
            self->flags = fl & ~4;
        if (!(self->flags & 4)) {
            if (self->slots[self->index].clip) {
                fn_80181640(self->model, self->slots[self->index].clip, &self->slots[self->index].clip_handle, 1.0f, 0.0f, 0.0f, 0);
                fn_8018179c(self->model, self->slots[self->index].clip_handle, 1);
            }
        }
    }
    }

    if (self->flags & 24) {
        if ((self->flags & 0x12000) == 0x2000) {
            if (!fn_80181d00(self->reel[0], self->handle[0])) {
                { int d = self->digit[0]; self->digit[0] = d == 0 ? 20 : d - 1; }
                fn_802aaf5c(self, 0, 0);
                if (now > self->next[0]) {
                    fn_80181640(self->reel[0], "Spin_Outro", &self->handle[0], 1.0f, 0.0f, 0.0f, 0);
                    fn_80181640(self->model, "Bounce", &self->breathe, 1.0f, 0.0f, 0.0f, 0);
                    
                    if (scene_804b1788->root) scene_804b1788->root->vt->set(scene_804b1788->root, "Wormpot.SpinStop", v);
                    self->flags = self->flags & ~24 | 32;
                } else
                    fn_80181640(self->reel[0], "Spin_Loop", &self->handle[0], 1.0f, 0.0f, 0.0f, 0);
            }
        } else if (!fn_80181d00(self->reel[0], self->handle[0])) {
            fn_802aaf5c(self, 0, 0);
            fn_80181640(self->reel[0], "NudgeUp_Outro", &self->handle[0], 1.0f, 0.0f, 0.0f, 0);
            self->flags = self->flags & ~24 | 32;
        }
    }
    if (self->flags & 32) {
        if (!fn_80181d00(self->reel[0], self->handle[0])) self->flags &= ~32;
    }

    if (self->flags & 192) {
        if ((self->flags & 0x22000) == 0x2000) {
            if (!fn_80181d00(self->reel[1], self->handle[1])) {
                { int d = self->digit[1]; self->digit[1] = d == 0 ? 20 : d - 1; }
                fn_802aaf5c(self, 1, 1);
                if (now > self->next[1]) {
                    fn_80181640(self->reel[1], "Spin_Outro", &self->handle[1], 1.0f, 0.0f, 0.0f, 0);
                    fn_80181640(self->model, "Bounce", &self->breathe, 1.0f, 0.0f, 0.0f, 0);
                    
                    if (scene_804b1788->root) scene_804b1788->root->vt->set(scene_804b1788->root, "Wormpot.SpinStop", v);
                    self->flags = self->flags & ~192 | 256;
                } else
                    fn_80181640(self->reel[1], "Spin_Loop", &self->handle[1], 1.0f, 0.0f, 0.0f, 0);
            }
        } else if (!fn_80181d00(self->reel[1], self->handle[1])) {
            fn_802aaf5c(self, 1, 1);
            fn_80181640(self->reel[1], "NudgeUp_Outro", &self->handle[1], 1.0f, 0.0f, 0.0f, 0);
            self->flags = self->flags & ~192 | 256;
        }
    }
    if (self->flags & 256) {
        if (!fn_80181d00(self->reel[1], self->handle[1])) self->flags &= ~256;
    }

    if (self->flags & 1536) {
        if ((self->flags & 0x42000) == 0x2000) {
            if (!fn_80181d00(self->reel[2], self->handle[2])) {
                { int d = self->digit[2]; self->digit[2] = d == 0 ? 15 : d - 1; }
                fn_802aaf5c(self, 2, 2);
                if (now > self->next[2]) {
                    fn_80181640(self->reel[2], "Spin_Outro", &self->handle[2], 1.0f, 0.0f, 0.0f, 0);
                    fn_80181640(self->model, "Bounce", &self->breathe, 1.0f, 0.0f, 0.0f, 0);
                    if (self->sound) self->sound->vt->stop(self->sound);
                    if (scene_804b1788->root) scene_804b1788->root->vt->set(scene_804b1788->root, "Wormpot.SpinStop", v);
                    self->flags = self->flags & ~1536 | 2048;
                } else
                    fn_80181640(self->reel[2], "Spin_Loop", &self->handle[2], 1.0f, 0.0f, 0.0f, 0);
            }
        } else if (!fn_80181d00(self->reel[2], self->handle[2])) {
            fn_802aaf5c(self, 2, 2);
            fn_80181640(self->reel[2], "NudgeUp_Outro", &self->handle[2], 1.0f, 0.0f, 0.0f, 0);
            self->flags = self->flags & ~1536 | 2048;
        }
    }
    if (self->flags & 2048) {
        if (!fn_80181d00(self->reel[2], self->handle[2])) self->flags &= ~2048;
    }

    if (self->flags & 4096) {
        if (!fn_80181d00(self->reel[0], self->handle[0])) {
            self->flags = self->flags & ~4096 | 9360;
            fn_80181640(self->reel[0], "Spin_Loop", &self->handle[0], 1.0f, 0.0f, 0.0f, 0);
            fn_80181640(self->reel[1], "Spin_Loop", &self->handle[1], 1.0f, 0.0f, 0.0f, 0);
            fn_80181640(self->reel[2], "Spin_Loop", &self->handle[2], 1.0f, 0.0f, 0.0f, 0);
            if (scene_804b1788->root) scene_804b1788->root->vt->set(scene_804b1788->root, "Wormpot.SpinStart", v);
            if (self->sound) {
                Vec p;
                Vec *q = &p;
                q->x = 0.0f; q->y = 0.0f; q->z = 1.0f;
                self->sound->vt->param(self->sound, 3, *q);
                self->sound->vt->start(self->sound);
            }
        }
    }
    if (self->flags & 8192) {
        self->sub.vt->update(&self->sub);
        if (!(self->flags & 4088)) {
            fn_802ab24c(self);
            self->flags = self->flags & ~8192 | 16384;
        }
    }
    {
    unsigned fl = self->flags;
    if (fl & 16384) self->flags = fl & ~16384;
    }

    {
    unsigned fl = self->flags;
    if (fl & 0x10000) {
        if (self->digit[0] == self->target[0]) {
            self->busy = 0;
            self->flags = fl & ~0x10000;
        } else {
            unsigned m = fl & 24;
            if (!m) {
                Slot *sl = self->slots;
                int k = self->index * 72;
                int old = *(int *)((char *)sl + k);
                *(int *)((char *)sl + k) = fn_802a9058(self, 0, 21) == 1 ? 2 : 3;
                self->flags = m;
                self->busy = 1;
                fn_802aaa8c(self);
                sl[self->index].type = old;
                self->flags |= fl;
            }
        }
    }
    }

    {
    unsigned fl = self->flags;
    if (fl & 0x20000) {
        if (self->digit[1] == self->target[1]) {
            self->busy = 0;
            self->flags = fl & ~0x20000;
        } else {
            unsigned m = fl & 192;
            if (!m) {
                Slot *sl = self->slots;
                int k = self->index * 72;
                int old = *(int *)((char *)sl + k);
                *(int *)((char *)sl + k) = fn_802a9058(self, 1, 21) == 1 ? 5 : 6;
                self->flags = m;
                self->busy = 1;
                fn_802aaa8c(self);
                sl[self->index].type = old;
                self->flags |= fl;
            }
        }
    }
    }

    {
    unsigned fl = self->flags;
    if (fl & 0x40000) {
        if (self->digit[2] == self->target[2]) {
            self->busy = 0;
            self->flags = fl & ~0x40000;
        } else {
            unsigned m = fl & 1536;
            if (!m) {
                Slot *sl = self->slots;
                int k = self->index * 72;
                int old = *(int *)((char *)sl + k);
                *(int *)((char *)sl + k) = fn_802a9058(self, 2, 16) == 1 ? 8 : 9;
                self->flags = m;
                self->busy = 1;
                fn_802aaa8c(self);
                sl[self->index].type = old;
                self->flags |= fl;
            }
        }
    }
    }

    if (!(self->flags & 8192)) {
        if (self->sound && self->sound->vt->playing(self->sound))
            self->sound->vt->stop(self->sound);
    }
    return 0;
}
