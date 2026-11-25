/* Advances a countdown-like value by subtracting a step. When it falls below
   the limit record's lower bound it is either set to that bound (when the flag
   is set) or the companion value is raised by rate times the shortfall, capped
   by the record's upper bound, and the value is set to the bound. Offsets are
   observed; field names and meanings are inferred. The two-float temporary is
   reached through separate pointers and sits in a 16-byte local because the
   original reserves that frame. */
typedef struct { char p0[52]; float lo; float hi; char p1[24]; float rate; } Limits;
typedef struct { char p0[136]; void *ctx; char p1[40]; float cur; float aux; } Obj;
typedef struct { float v[4]; } Tmp;
extern void *fn_80341584(void *);
extern Limits *fn_801797b4(void *);
static inline const float *pick(const float *a, const float *b) { return *b < *a ? b : a; }
void tsonnet_b30_ease_800d47f0(Obj *o, float dt, int snap) {
    Limits *l = fn_801797b4(fn_80341584(o->ctx));
    o->cur = o->cur - dt;
    if (o->cur < l->lo) {
        if (snap) {
            o->cur = l->lo;
        } else {
            Tmp t; float *a = &t.v[0]; float *b = &t.v[1];
            *a = l->rate * (l->lo - o->cur) + o->aux; *b = l->hi;
            o->aux = *pick(a, b);
            o->cur = l->lo;
        }
    }
}
