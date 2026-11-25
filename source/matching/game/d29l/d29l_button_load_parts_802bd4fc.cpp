// GWMP8P rev0 0x802bd4fc. Scroll button setup: loads the FE.Box sprite five
// times from the font index, stores the five parts, sets their glyphs and
// adds them to the group, then lays them out. Strings, glyph bytes and
// vtable slots come from the original; field names are inferred.
extern "C" void fn_8020c5c0(void *), fn_8020c5c4(void *), fn_80341588(void *);
struct Header { unsigned short refs, length, capacity; };
extern "C" Header *fn_80341884(void *);
struct Str {
    char *p;
    Str();
    Str(const Str &o) {
        fn_8020c5c0(this);
        p = o.p;
        Header *h = fn_80341884(this);
        ++h->refs;
    }
    ~Str() { fn_8020c5c4(this); fn_80341588(this); }
};
struct Res;
struct ResVt { char u0[12]; void (*acquire)(Res *); void (*destroy)(Res *); };
struct Res { ResVt *vt; };
struct Ref {
    Res *p;
    void operator=(Res *q) {
        if (q) q->vt->acquire(q);
        if (p) p->vt->destroy(p);
        p = q;
    }
};
struct Held {
    Res *r;
    Held() : r(0) {}
    Held(const Held &);
    ~Held() { if (r) r->vt->destroy(r); }
};
struct Group;
struct GroupVt { char u0[92]; void (*add)(Group *, Res *, int); };
struct Group { GroupVt *vt; };
struct Button {
    char u0[12];
    void *w12;
    char u16[16];
    int state;
    char u36[60];
    Group *group;
    char u100[8];
    Ref left, right, top, bottom, centre;
    int on;
    char u132[7];
    unsigned char font;
};
extern "C" void fn_8020bd38(Str *, const char *);
extern "C" int fn_80263608(Str, int);
extern "C" int fn_8015adf4(Str *, Held *, int);
extern "C" Res *fn_8034357c(Res *);
extern "C" int fn_80173f88(Res *, char *);
extern "C" void fn_802bd8cc(Button *), fn_802bd354(Button *);
extern const char box_803d838c[];
extern "C" void d29l_button_load_parts_802bd4fc(Button *self) {
    int o = 0;
    Str name;
    if (self->w12 && self->on == 1) o = 6;
    fn_8020bd38(&name, box_803d838c);
    fn_80263608(name, 0);
    Held h;
    fn_8015adf4(&name, &h, (unsigned char)(self->font + 29));
    self->left = fn_8034357c(h.r);
    fn_8015adf4(&name, &h, (unsigned char)(self->font + 29));
    self->right = fn_8034357c(h.r);
    fn_8015adf4(&name, &h, (unsigned char)(self->font + 29));
    self->top = fn_8034357c(h.r);
    fn_8015adf4(&name, &h, (unsigned char)(self->font + 29));
    self->centre = fn_8034357c(h.r);
    fn_8015adf4(&name, &h, (unsigned char)(self->font + 29));
    self->bottom = fn_8034357c(h.r);
    char ch[6];
    { Res *l = self->left.p; ch[0] = o + 67; fn_80173f88(l, &ch[0]); }
    ch[1] = o + 68;
    fn_80173f88(self->right.p, &ch[1]);
    ch[2] = o + 69;
    fn_80173f88(self->top.p, &ch[2]);
    ch[3] = o + 70;
    fn_80173f88(self->bottom.p, &ch[3]);
    self->group->vt->add(self->group, self->left.p, 0);
    self->group->vt->add(self->group, self->right.p, 0);
    self->group->vt->add(self->group, self->top.p, 0);
    self->group->vt->add(self->group, self->bottom.p, 0);
    self->group->vt->add(self->group, self->centre.p, 0);
    switch (self->state) {
    case 3:
        { Res *c = self->centre.p; ch[4] = o + 71; fn_80173f88(c, &ch[4]); }
    case 0: case 1: case 2:
        { Res *c = self->centre.p; ch[5] = o + 72; fn_80173f88(c, &ch[5]); }
    }
    fn_802bd8cc(self);
    fn_802bd354(self);
}
