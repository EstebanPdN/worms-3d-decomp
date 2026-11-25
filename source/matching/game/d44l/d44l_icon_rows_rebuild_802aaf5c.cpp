// GWMP8P rev0 0x802aaf5c. Rebuilds a menu's icon rows: for each row from
// first to last, removes and releases its five icons, then loads each icon
// by name from the row's name-order table starting two entries before the
// row's offset, wrapping at the table's count, scales and places it and adds
// it to the row's group.
extern "C" void fn_8020c5c4(void *), fn_80341588(void *);
struct Str {
    char *p;
    Str(const char *);
    Str(const Str &);
    ~Str() {
        fn_8020c5c4(this);
        fn_80341588(this);
    }
};
struct Vec {
    float x, y, z;
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
};
struct Res;
struct ResVt {
    char u0[12];
    void (*addRef)(Res *);
    void (*release)(Res *);
    char u20[56];
    void (*place)(Res *, const Vec &, int);
    char u80[4];
    void (*scale)(Res *, const Vec &, int);
    char u88[4];
    void (*add)(Res *, Res *, int);
    void (*remove)(Res *, Res *);
};
struct Res { ResVt *vt; };
struct Handle {
    Res *r;
    Handle() { r = 0; }
    Handle(const Handle &);
    ~Handle() { if (r) r->vt->release(r); }
};
struct Cell { int u0, h, u8; Res *icon; };
struct Row { Cell c[5]; };
struct Menu {
    char u0[248];
    Res *groups[3];
    char u260[816];
    Row rows[3];
    unsigned offset[3];
};
extern int base_804abb60;
extern const int order_803d6b7c[], order_803d6bd0[], order_803d6c24[];
extern const char *names_80403b2c[];
extern const int depth_80403b18[];
extern "C" int fn_8015adf4(const Str *, Res **, unsigned char);
extern "C" Res *fn_80343584(Res *);
inline Res *cast(const Handle &h) { return fn_80343584(h.r); }
inline void load(Res *&dest, const char *name, unsigned char kind) {
    const Str &s = Str(name);
    Handle h;
    fn_8015adf4(&s, &h.r, kind);
    Res *r = cast(h);
    if (r) r->vt->addRef(r);
    if (dest) dest->vt->release(dest);
    dest = r;
}
inline void place(Res *&icon, const Vec &a, const Vec &b) {
    icon->vt->scale(icon, a, 0);
    icon->vt->place(icon, b, 0);
}
#define GROUP (*(Res **)gp)
extern "C" void d44l_icon_rows_rebuild_802aaf5c(Menu *self, unsigned first, unsigned last) {
    unsigned char kind = base_804abb60 + 29;
    {
        for (unsigned i = first; i <= last; ) {
            char *base = (char *)&self->rows[0].c[0].icon;
            unsigned j = 0;
            unsigned next = i + 1;
            for (; j <= 4; j++) {
                int gp = (i << 2) + (int)self; gp += 248;
                Res *&icon = *(Res **)((int)(i * 80) + (int)base + j * 16);
                if (icon) {
                    GROUP->vt->remove(GROUP, icon);
                    Res *z = 0;
                    if (icon) icon->vt->release(icon);
                    icon = z;
                }
            }
            i = next;
        }
    }
    for (unsigned i = first; i <= last; i++) {
        char *base = (char *)&self->rows[0].c[0].icon;
        const int *order;
        unsigned count;
        if (i == 0) {
            count = 21;
            order = order_803d6b7c;
        } else if (i == 1) {
            count = 21;
            order = order_803d6bd0;
        } else {
            count = 16;
            order = order_803d6c24;
        }
        unsigned at;
        if (self->offset[i] > 1) {
            at = self->offset[i] - 2;
        } else {
            int v = self->offset[i] - 2; at = count + v;
        }
        for (int j = 0; j <= 4; j++) {
            Res *&icon = *(Res **)((int)(i * 80) + (int)base + j * 16);
            load(icon, names_80403b2c[order[at]], kind);
            place(icon, Vec(0.15f, 0.15f, 1.0f), Vec(0.0f, 0.0f, 0.2f));
            int gp = (i << 2) + (int)self; gp += 248;
            GROUP->vt->add(GROUP, icon, depth_80403b18[j]);
            at = (at + 1) % count;
        }
    }
}
