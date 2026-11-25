// GWMP8P rev0 0x802a64a8. Lays out a panel's eight parts: computes the right
// edge and gap from the panel's width fields, scales and positions the first
// eight parts in two groups on stepped offsets, then shows or hides parts
// four to seven by the panel's mode and refreshes it.
struct Vec {
    float x, y, z;
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
};
struct Part;
struct PartVt { char u0[76]; void (*move)(Part *, const Vec &, int); char u80[4]; void (*scale)(Part *, const Vec &, int); void (*show)(Part *, int); };
struct Part { PartVt *vt; };
struct Self {
    char u0[276];
    Part *parts[8];
    char u308[36];
    float w344, w348, w352, w356, w360, w364, w368;
    char u372[248];
    int w620;
};
extern "C" void fn_802a6ce8(Self *);
inline Part *&slot(Self *s, unsigned i) { return *(Part **)((char *)s + i * 4 + 276); }
extern "C" void d44l_parts_layout_802a64a8(Self *self) {
    float step = (self->w368 - self->w364) * 0.25f;
    if (self->parts[0]) {
        float right;
        float gap;
        if (self->w620 == 4) {
            right = self->w360;
            gap = 0.0f;
        } else {
            float r = self->w360;
            gap = (r - self->w356) / 2.5f + 1.0f;
            right = r;
        }
        float d[8];
        d[0] = right - self->w344 - gap;
        d[1] = right - self->w348 - gap;
        d[2] = right - self->w352 - gap;
        d[3] = right - self->w356 - gap;
        d[4] = gap;
        d[5] = gap;
        d[6] = gap;
        d[7] = gap;
        float k = 0.5f;
        float h = step * k;
        for (unsigned i = 0; i <= 7; i++) {
            Vec v(d[i] * k, h, 1.0f);
            slot(self, i)->vt->scale(slot(self, i), v, 0);
        }
        step = step * 0.5f;
        float y = self->w364 + step;
        for (unsigned i = 0; i <= 7; i++) {
            float x;
            if (i <= 3)
                x = self->w360 - gap - d[i] * 0.5f;
            else
                x = self->w360 - gap * 0.5f;
            Vec v(x, y, 0.0f);
            slot(self, i)->vt->move(slot(self, i), v, 0);
            if (i == 3)
                y = self->w364 + step;
            else
                y += step + step;
        }
        for (unsigned i = 4; i <= 7; i++) {
            int gp = (i << 2) + (int)self; gp += 276;
            Part *p = *(Part **)gp;
            PartVt *t = p->vt;
            int on = 1;
            if (self->w620 == 4)
                on = 0;
            t->show(p, on);
        }
        fn_802a6ce8(self);
    }
}
