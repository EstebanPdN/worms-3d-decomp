// d31i: 0x8012b30c. Ten drifting ambient sky particles around the camera:
// fades each by age, height and distance and respawns it from the wind
// direction with a palette colour.
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    
    void normalize() { float f = 1.0f / len(); x *= f; y *= f; z *= f; }
    Vec &operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
    Vec &operator+=(const Vec &o) { x += o.x; y += o.y; z += o.z; return *this; }
};
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
struct Colour {
    unsigned char r, g, b, a;
    Colour() {}
};
inline Colour rgb(int r, int g, int b) { Colour c; c.r = r; c.g = g; c.b = b; c.a = 0; return c; }
extern Vec wind_8044b688[];
extern Colour palette_80450a60[];
extern int palette_ready_804af610;
inline void getWind(Vec &o) { o = wind_8044b688[0]; }
inline void put(Vec &o, float a, float b, float c) { o.x = a; o.y = b; o.z = c; }
struct Sky { char u0[28]; void *prop; unsigned times[10]; void *curve; };
struct View { struct ViewVt *vt; };
struct ViewVt { char u0[56]; Vec *(*pos)(View *); };
extern void *runtime_804b1788;
extern Vec wind_8044b688[];
extern float k15_8039d304[];
extern "C" Vec *points_80189518(void *);
extern "C" Colour *colours_80189760(void *);
extern "C" void *open_8018963c(void *);
extern "C" View *service_8015cd04(void *, int);
extern "C" void *ref_80342a74(void *);
extern "C" float height_80178df0(void *);
extern "C" float Vec__sqrt(float);
extern "C" float sinf_802e88ac(float);
extern "C" float frand_8015ff7c(Sky *);
extern "C" unsigned rand_8015ff5c(Sky *);
extern "C" int d31i_ambient_sky_8012b30c(Sky *self, unsigned now) {
    if (!palette_ready_804af610) {
        Colour *e = palette_80450a60;
        *e = rgb(255, 255, 255);
        *++e = rgb(255, 128, 128);
        *++e = rgb(128, 255, 255);
        *++e = rgb(128, 255, 128);
        palette_ready_804af610 = 1;
        *++e = rgb(255, 128, 255);
    }
    void *prop = self->prop;
    const float lim = 1000.0f;
    Vec *pts = points_80189518(prop);
    Colour *cols = colours_80189760(prop);
    open_8018963c(prop);
    View *view = service_8015cd04(runtime_804b1788, 4);
    Vec *cam = view->vt->pos(view);
    Vec p, q, wind;
    getWind(wind);
    float top = height_80178df0(ref_80342a74(self->curve)) + k15_8039d304[0];
    float h = cam->y;
    if (h > lim) h = lim;
    const float radius = 1200.0f;
    const float scale = 2880000.0f;
    float bright = 1.0f - h / lim;
    for (unsigned short i = 0; i <= 9; i++) {
        unsigned age = now - self->times[i];
        if (age < 1024) {
            p = wind - *cam;
            p.y = top;
            p.normalize();
            p *= radius;
            q = p - pts[i];
            float d = (q.x * q.x + q.z * q.z) / scale;
            if (d > 1.0f) d = 1.0f;
            d = 1.0f - d;
            Colour &c = *(Colour *)((i << 2) + (unsigned)cols);
            float s = sinf_802e88ac((float)age * 0.0009765625f * 3.1415927f);
            c.a = (unsigned char)(s * d * bright * 255.0f);
        } else {
            float ox = frand_8015ff7c(self) * 500.0f + -250.0f;
            float oz = frand_8015ff7c(self) * 500.0f + -250.0f;
            float r = frand_8015ff7c(self) * 1000.0f;
            p = wind;
            p.y = 0.0f;
            p.normalize();
            p *= r + radius;
            p += *cam;
            self->times[i] = now;
            p.x += ox;
            p.z += oz;
            *(Colour *)((i << 2) + (unsigned)cols) = palette_80450a60[rand_8015ff5c(self) % 5];
            Colour &c = *(Colour *)((i << 2) + (unsigned)cols);
            c.a = (unsigned char)((float)c.a * bright);
            put(pts[i], top, -p.x, p.z);
        }
    }
    return 0;
}
