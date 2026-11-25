/* Advances a clamped value by the elapsed count since the previous call.
   The elapsed count (unsigned) is scaled by a global factor and subtracted
   from the value when a flag is set, otherwise added. The value is then
   limited between two global bounds through pointer-returning min/max
   helpers (the bounds live in stack slots whose addresses are taken, as the
   original does), and the result is passed to slot 13 of the two held
   objects. Offsets are observed; field names and meanings are inferred. */
struct Obj;
typedef struct { char pad[52]; void (*set)(struct Obj *, int, float); } VT;
typedef struct Obj { VT *vtable; } Obj;
typedef struct {
    char p0[28];
    Obj *first;
    Obj *second;
    float value;
    unsigned flag;
    char p1[4];
    unsigned stamp;
} Fade;
extern float lbl_8038c3f8[];
extern float lbl_8038c3fc[];
extern float lbl_8038c400[];
static inline float *b37_min(float *a, float *b) { return *a < *b ? a : b; }
static inline float *b37_max(float *a, float *b) { return *a < *b ? b : a; }
void tsonnet_b37_fade_800f1b58(Fade *f, unsigned now)
{
    unsigned elapsed = now - f->stamp;
    float conv;
    float step;
    float hi;
    float lo;
    float *pv;
    float *ph;
    float *pl;
    conv = (float)elapsed;
    f->stamp = now;
    step = conv * lbl_8038c3f8[0];
    if (f->flag) f->value -= step; else f->value += step;
    lo = lbl_8038c3fc[0];
    hi = lbl_8038c400[0];
    pv = &f->value;
    pl = &lo;
    ph = &hi;
    f->value = *b37_max(b37_min(pv, ph), pl);
    f->first->vtable->set(f->first, 1, f->value);
    f->second->vtable->set(f->second, 1, f->value);
}
