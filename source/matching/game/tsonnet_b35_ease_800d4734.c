/* Advances two coupled countdown-like values by a step. When the second value
   (+184) is above the limit record's floor it is reduced by step times rate;
   if that crosses the floor, the value is set to the floor and the step is
   reduced by the shortfall divided by the rate, otherwise the step becomes
   the global constant (zero). The first value (+180) then advances by the
   remaining step and is capped by the record's ceiling. The two-float
   temporary is reached through separate pointers and sits in a 16-byte local
   because the original reserves that frame. Offsets are observed; field
   names and meanings are inferred. */
typedef struct { char p0[64]; float hi; char p1[12]; float lo; float rate; } Limits;
typedef struct { char p0[136]; void *ctx; char p1[40]; float cur; float aux; } Obj;
typedef struct { float v[4]; } Tmp;
extern void *fn_80341584(void *);
extern Limits *fn_801797b4(void *);
extern float lbl_80388d20[];
static inline const float *pick(const float *a, const float *b) { return *b < *a ? b : a; }
void tsonnet_b35_ease_800d4734(Obj *o, float dt) {
    Limits *l = fn_801797b4(fn_80341584(o->ctx));
    if (o->aux > l->lo) {
        o->aux = o->aux - dt * l->rate;
        if (o->aux < l->lo) {
            dt = dt - (l->lo - o->aux) / l->rate;
            o->aux = l->lo;
        } else {
            dt = lbl_80388d20[0];
        }
    }
    {
        Tmp t; float *a = &t.v[0]; float *b = &t.v[1];
        *a = l->hi; *b = o->cur + dt;
        o->cur = *pick(a, b);
    }
}
