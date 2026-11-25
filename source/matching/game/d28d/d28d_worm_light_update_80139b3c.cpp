// GWMP8P rev0 0x80139b3c. Worm light update. Field names are inferred from
// use. The 1.0 literal in k3 and its later literal uses make the constant
// copy that the compiler's global CSE keeps across the call.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
inline Vec operator-(const Vec &a) { Vec r; r.x = -a.x; r.y = -a.y; r.z = -a.z; return r; }
inline const float &fminB(const float &a, const float &b) { return b < a ? b : a; }
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
struct Plain { float x, y, z; };
struct Rgb : Plain { Rgb &operator=(const Rgb &o) { Plain::operator=(o); return *this; } };
struct Light { char u0[120]; Rgb diffuse; Rgb ambient; char u90[12]; Rgb dir; };
struct Colours { char u0[416]; void *a; void *b; };
struct Worm {
    char u0[52]; Vec pos; char u40[48]; int index; char u74[60]; float shadeTarget; float shade;
    char ub8[328]; Vec lightDir; char u20c[72]; Light *light1; Light *light2; float level; float levelTarget;
};
extern "C" void *same_80342fa4(void *);
extern "C" const Rgb *colour_80178ec4(void *);
extern "C" void test_800b0824(const Vec &, const Vec &, const Vec &, int, int);
extern Colours *colours_804ab400;
extern int current_804ab3b0;
extern unsigned traceFrac_804b1764;
extern "C" void d28d_worm_light_update_80139b3c(Worm *self) {
    if (self->levelTarget > self->level) self->level = fminB(self->level + 0.05f, self->levelTarget);
    else self->level = fmax(self->level - 0.05f, self->levelTarget);
    if (self->shadeTarget > self->shade) self->shade = fminB(self->shade + 0.05f, self->shadeTarget);
    else self->shade = fminB(self->shade - 0.05f, self->shadeTarget);
    Rgb c;
    c = *colour_80178ec4(same_80342fa4(colours_804ab400->a));
    Rgb a;
    a.x = c.x; a.y = c.y; a.z = c.z;
    c = *colour_80178ec4(same_80342fa4(colours_804ab400->b));
    Rgb b;
    b.x = c.x * self->level; b.y = c.y * self->level; b.z = c.z * self->level;
    self->light2->diffuse = b;
    self->light2->ambient = a;
    float k3 = 1.0f;
    float k1 = k3 - self->shade * 0.5f;
    float k2 = self->shade * 0.2f + k3;
    k3 -= self->shade * 0.4f;
    b.x *= k1;
    b.y *= k2;
    if (b.y > 1.0f) b.y = 1.0f;
    b.z *= k3;
    a.x *= k1;
    a.y *= k2;
    if (a.y > 1.0f) a.y = 1.0f;
    a.z *= k3;
    self->light1->diffuse = b;
    self->light1->ambient = a;
    Rgb n;
    n.x = -self->lightDir.x; n.y = -self->lightDir.y; n.z = -self->lightDir.z;
    self->light1->dir = n;
    self->light2->dir = n;
    if (current_804ab3b0 == self->index) {
        Vec p;
        Vec zero(0.0f, 0.0f, 0.0f);
        p = self->pos + self->lightDir;
        test_800b0824(p, self->lightDir, zero, 300, 1);
        if (traceFrac_804b1764 < 300) self->levelTarget = (float)traceFrac_804b1764 / 300.0f;
        else self->levelTarget = 1.0f;
    }
}
