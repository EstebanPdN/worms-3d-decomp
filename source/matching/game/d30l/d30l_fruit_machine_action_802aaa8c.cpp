// GWMP8P rev0 0x802aaa8c. Fruit-machine menu action: when idle, stops the
// current slot's clip, plays its intro and caption, then applies the
// selected action: nudges one of three reels up or down modulo its symbol
// count (mulhwu forms mean unsigned), or starts all three reels with random
// stop times. Strings and literals are from the original; field names are
// inferred.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
};
struct Str { char *p; unsigned length() const { return *(unsigned short *)(p - 4); }
    const char *str() const { return p; } };
struct Node;
struct NodeVt { char u[96]; void (*set)(Node *, const char *, const Vec &); };
struct Node { NodeVt *vt; };
struct Scene { char u[108]; Node *root; };
struct Slot {
    int type;
    char u4[32];
    int clip;
    int intro;
    char u44[4];
    int anim;
    char name[16];
    Str text;
};
struct Menu {
    char u0[244];
    void *model;
    void *reel[3];
    char u260[8];
    Slot slots[11];
    int handle[3];
    int index;
    char u1076[240];
    unsigned digit[3];
    char u1328[12];
    unsigned flags;
    int next[3];
    char u1356[20];
    int busy;
};
struct Ctx { char u[52]; int a52; };
extern "C" {
int fn_8018179c(void *, int, int);
int fn_80181640(void *, const char *, int *, float, float, float, int);
void fn_802ab24c(Menu *);
void fn_802ab630(Menu *, int);
Ctx *fn_80165254();
unsigned fn_80162ba8();
}
extern Scene *scene_804b1788;
extern "C" void d30l_fruit_machine_action_802aaa8c(Menu *self) {
    float zero = 0.0f, one = 1.0f;
    Vec unused(zero, zero, one);
    if (self->flags) return;
    if (self->slots[self->index].clip)
        fn_8018179c(self->model, self->slots[self->index].anim, 0);
    if (!self->busy) {
        if (self->slots[self->index].intro)
            fn_80181640(self->model, (const char *)self->slots[self->index].intro, (int *)self->slots[self->index].name, one, zero, zero, 0);
        if (self->slots[self->index].text.length()) {
            Vec v;
            Vec *p = &v;
            p->x = zero; p->y = zero; p->z = one;
            scene_804b1788->root->vt->set(scene_804b1788->root, self->slots[self->index].text.str(), *p);
        }
    }
    self->flags |= 4;
    switch (self->slots[self->index].type) {
    case 2:
        self->digit[0] = (self->digit[0] + 1) % 21;
        fn_802ab24c(self);
        fn_802ab630(self, 0);
        self->flags |= 8;
        fn_80181640(self->reel[0], "NudgeUp_Loop", &self->handle[0], 1.0f, 0.0f, 0.0f, 0);
        break;
    case 3:
        { unsigned d = self->digit[0]; self->digit[0] = d == 0 ? 20 : d - 1; }
        fn_802ab24c(self);
        fn_802ab630(self, 0);
        self->flags |= 16;
        fn_80181640(self->reel[0], "NudgeDown_Loop", &self->handle[0], 1.0f, 0.0f, 0.0f, 0);
        break;
    case 5:
        self->digit[1] = (self->digit[1] + 1) % 21;
        fn_802ab24c(self);
        fn_802ab630(self, 1);
        self->flags |= 64;
        fn_80181640(self->reel[1], "NudgeUp_Loop", &self->handle[1], 1.0f, 0.0f, 0.0f, 0);
        break;
    case 6:
        { unsigned d = self->digit[1]; self->digit[1] = d == 0 ? 20 : d - 1; }
        fn_802ab24c(self);
        fn_802ab630(self, 1);
        self->flags |= 128;
        fn_80181640(self->reel[1], "NudgeDown_Loop", &self->handle[1], 1.0f, 0.0f, 0.0f, 0);
        break;
    case 8:
        self->digit[2] = (self->digit[2] + 1) % 16;
        fn_802ab24c(self);
        fn_802ab630(self, 2);
        self->flags |= 512;
        fn_80181640(self->reel[2], "NudgeUp_Loop", &self->handle[2], 1.0f, 0.0f, 0.0f, 0);
        break;
    case 9:
        { unsigned d = self->digit[2]; self->digit[2] = d == 0 ? 15 : d - 1; }
        fn_802ab24c(self);
        fn_802ab630(self, 2);
        self->flags |= 1024;
        fn_80181640(self->reel[2], "NudgeDown_Loop", &self->handle[2], 1.0f, 0.0f, 0.0f, 0);
        break;
    case 1:
        break;
    case 10:
        if (!self->busy) {
            self->flags |= 0x1000;
            fn_80181640(self->reel[0], "Spin_Intro", &self->handle[0], 1.0f, 0.0f, 0.0f, 0);
            fn_80181640(self->reel[1], "Spin_Intro", &self->handle[1], 1.0f, 0.0f, 0.0f, 0);
            fn_80181640(self->reel[2], "Spin_Intro", &self->handle[2], 1.0f, 0.0f, 0.0f, 0);
            int now = fn_80165254()->a52;
            unsigned r = fn_80162ba8() % 5000 + 1000;
            self->next[0] = now + r;
            r = fn_80162ba8() % 1000 + 500;
            self->next[1] = self->next[0] + r;
            r = fn_80162ba8() % 1000 + 500;
            self->next[2] = self->next[1] + r;
        }
        break;
    }
}
