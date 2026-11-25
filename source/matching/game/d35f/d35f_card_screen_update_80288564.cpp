// GWMP8P rev0 0x80288564. Memory card screen update: runs the slide-in and
// slide-out fades of the panel, tinting all its text boxes with the fade
// alpha, and in the idle state pulses the highlight, updates the current
// slot display and steps the card guide state. Built with -mfast-cast -mps-
// float. Names are inferred.
struct Colour {
    signed char r, g, b, a;
    Colour(int x, int y, int z, int w) { r = x; g = y; b = z; a = w; }
};
extern "C" int fn_8018d434(void *, const Colour &);
extern "C" int fn_8018d35c(void *, const Colour &);
extern "C" void fn_802b30c0(void *, float, float);
extern "C" float fn_802e88ac(float);
extern "C" void fn_802aba0c(void *);
extern "C" int fn_802aba68(void *, int);
struct Card { char pad[36]; int base; };
struct Entry { int a, b; };
struct Tips { char pad[20]; Entry entry[1]; };
struct Screen;
extern "C" void fn_80288c7c(Screen *, int, int, int), fn_80289eec(Screen *, int), fn_80289df8(Screen *), fn_80289914(Screen *);
extern "C" void *fn_80344278();
extern "C" void fn_801fe3b0(void *, int);
extern int lbl_804abbe0, lbl_804abb5c;
extern float lbl_803cf924[];
struct Screen {
    char pad0[28]; int status; char pad32[88];
    int guide; char pad124[12]; Card *card; int active; char pad144[544]; int page; char pad692[8]; int focus; int state; unsigned char pulse; char pad709[163];
    void *parts[8]; void *extra[5]; void *last; char pad928[28]; unsigned partCount, extraCount; int delay; Tips *tips; char pad972[20];
    void *panel; char pad996[8]; float x, y, fade; unsigned flags;
    void Tint(const Colour &c, const Colour &d) {
        for (unsigned i = 0; i < partCount; i++) { fn_8018d35c(parts[i], c); fn_8018d434(parts[i], d); }
        for (unsigned i = 0; i < extraCount; i++) { fn_8018d35c(extra[i], c); fn_8018d434(extra[i], d); }
        if (last) { fn_8018d35c(last, c); fn_8018d434(last, d); }
    }
};
extern "C" int d35f_card_screen_update_80288564(Screen *self, unsigned time) {
    int tip = 0;
    if (self->state == 2) {
        float t = 1.0f - self->fade * lbl_803cf924[0];
        float off = (1.0f - t) * 100.0f;
        float a = t * t;
        float px = (self->x + self->x + 60.0f) * a + 20.0f;
        fn_802b30c0(self->panel, px, self->y + self->y + 40.0f + off);
        a *= 255.0f;
        unsigned char alpha = (unsigned char)a;
        Colour white(-1, -1, -1, alpha);
        Colour black(0, 0, 0, alpha);
        for (unsigned i = 0; i < self->partCount; i++) { fn_8018d35c(self->parts[i], white); fn_8018d434(self->parts[i], black); }
        for (unsigned i = 0; i < self->extraCount; i++) { fn_8018d35c(self->extra[i], white); fn_8018d434(self->extra[i], black); }
        if (self->last) { do { fn_8018d35c(self->last, white); } while (0); fn_8018d434(self->last, black); }
        self->fade -= 1.0f;
        if (self->fade < 0.0f) {
            fn_802b30c0(self->panel, self->x + self->x + 60.0f + 20.0f, self->y + self->y + 40.0f);
            if (self->fade < -1.0f)
                self->state = 1;
        }
    } else if (self->state == 3) {
        float t = 1.0f - self->fade * lbl_803cf924[0];
        float off = (1.0f - t) * 100.0f;
        float a = t * t;
        float px = (self->x + self->x + 60.0f) * a + 20.0f;
        fn_802b30c0(self->panel, px, self->y + self->y + 40.0f + off);
        a *= 255.0f;
        unsigned char alpha = (unsigned char)a;
        Colour white(-1, -1, -1, alpha);
        Colour black(0, 0, 0, alpha);
        for (unsigned i = 0; i < self->partCount; i++) { fn_8018d35c(self->parts[i], white); fn_8018d434(self->parts[i], black); }
        for (unsigned i = 0; i < self->extraCount; i++) { fn_8018d35c(self->extra[i], white); fn_8018d434(self->extra[i], black); }
        if (self->last) { do { fn_8018d35c(self->last, white); } while (0); fn_8018d434(self->last, black); }
        self->fade += 1.0f;
        if (self->fade >= 10.0f) {
            self->delay = 3;
            self->state = 1;
            self->flags |= 0x4000000;
        }
    } else if (self->state == 1) {
        self->pulse = (unsigned char)((fn_802e88ac((float)time * 0.005f) + 1.0f) * 128.0f);
        if (self->active == 0)
            fn_802aba0c(&self->guide);
        else {
            fn_80288c7c(self, self->status, self->guide, self->active);
            if (self->tips && (int)self->flags < 0)
                tip = self->tips->entry[self->page].a;
        }
        int active = self->active;
        self->flags &= 0x7fffffff;
        if (active) {
            int r = fn_802aba68(&self->guide, tip);
            self->status = r;
            if (r >= 0) if (r == 1 && (self->flags & 0x10000000)) {
                fn_80289eec(self, self->card->base + 8268);
                self->flags &= ~0x10000000;
            }
        } else if (lbl_804abbe0) {
            fn_80289df8(self);
            lbl_804abbe0 = 0;
        }
        if (self->status == 4)
            fn_801fe3b0(fn_80344278(), 1);
        if ((self->flags & 0x4000000) && self->delay && --self->delay == 0) {
            fn_80289914(self);
            lbl_804abb5c = self->focus;
        }
        if (self->tips == 0)
            self->flags &= ~0x8000000;
    }
    return 20;
}
