// GWMP8P rev0 0x802bfc64. Scroll button update: picks the arrow glyph set,
// then colours the four edges and centre by state and scroll position. Glyph
// bytes and colour constants come from the original; field and state names
// are inferred.
struct Color {
    unsigned char r, g, b, a;
    Color() {}
    void set(unsigned char x, unsigned char y, unsigned char z, unsigned char w) { r = x; g = y; b = z; a = w; }
};
struct Button {
    unsigned flags;
    char u4[8];
    void *w12;
    char u16[4];
    void *visible;
    char u24[8];
    int state;
    float size;
    char u40[20];
    float x, y;
    void *owner;
    char u72[36];
    void *left, *right, *top, *bottom, *centre;
    bool on;
    void *w132;
};
extern "C" int fn_80173f88(void *, char *);
extern "C" int fn_80173df0(void *, Color *);
extern "C" unsigned char fn_802bfc48(Button *);
extern "C" float fn_80178df0(void *);
extern "C" void fn_802bd354(Button *);
extern "C" void d29l_button_update_colours_802bfc64(Button *self) {
    if (self->visible) {
        char ch[5];
        int on = (self->w12 != 0) & (self->w132 != 0) & self->on;
        int o = 0;
        if (on) o = 6;
        ch[0] = o + 67;
        fn_80173f88(self->left, &ch[0]);
        ch[1] = o + 68;
        fn_80173f88(self->right, &ch[1]);
        ch[2] = o + 69;
        fn_80173f88(self->top, &ch[2]);
        ch[3] = o + 70;
        fn_80173f88(self->bottom, &ch[3]);
        unsigned char t = o;
        void *ce = self->centre;
        ch[4] = self->state == 3 ? t + 71 : t + 72;
        fn_80173f88(ce, &ch[4]);
        unsigned char alpha = fn_802bfc48(self);
        if (!self->on) alpha = 255;
        unsigned char ca = alpha;
        if (self->x + self->y >= self->size + self->size) ca = 0;
        float w = fn_80178df0(self->owner);
        int r, g, b;
        if (self->on) { b = 255; g = 255; r = 255; }
        else { r = 255; g = 200; b = 200; }
        Color c;
        switch (self->state) {
        case 3: {
            float d = w + w;
            c.set(r, g, b, self->x >= d ? 0 : alpha);
            fn_80173df0(self->left, &c);
            c.set(r, g, b, self->y >= d ? 0 : alpha);
            fn_80173df0(self->right, &c);
            c.set(r, g, b, ca);
            fn_80173df0(self->centre, &c);
            fn_80173df0(self->top, &c);
            fn_80173df0(self->bottom, &c);
            break;
        }
        case 0:
            c.set(r, g, b, 0);
            fn_80173df0(self->left, &c);
            fn_80173df0(self->right, &c);
            fn_80173df0(self->top, &c);
            fn_80173df0(self->bottom, &c);
            c.set(r, g, b, (self->w12 != 0) & (self->w132 != 0) ? alpha : 0);
            fn_80173df0(self->centre, &c);
            break;
        case 1:
            c.set(r, g, b, 0);
            fn_80173df0(self->top, &c);
            fn_80173df0(self->bottom, &c);
            fn_80173df0(self->left, &c);
            fn_80173df0(self->right, &c);
            c.set(r, g, b, ca);
            fn_80173df0(self->centre, &c);
            break;
        case 2:
            c.set(r, g, b, 0);
            if (self->flags & 1) { r = 170; g = 170; b = 170; }
            fn_80173df0(self->left, &c);
            fn_80173df0(self->right, &c);
            fn_80173df0(self->top, &c);
            fn_80173df0(self->bottom, &c);
            c.set(r, g, b, ca);
            fn_80173df0(self->centre, &c);
            break;
        }
    }
    fn_802bd354(self);
}
