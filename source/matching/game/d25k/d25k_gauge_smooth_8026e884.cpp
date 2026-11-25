// Gauge value smoothing update (Worms 3D GameCube PAL, 0x8026e884).
//
// Calls the base update through the table at +208 on the sub-object at +28,
// then follows the bound target: when its value at +92 differs from the
// current value, an active target (+68) snaps current and desired, otherwise
// only desired moves. Current then eases towards desired: a difference inside
// (-0.01f..0.01f, 0x803cbdfc/0x803cbdf8) snaps, anything else blends
// by the gain 0.25f at 0x803cbe00. Finally forwards the value to both bound widgets.
//
// The source repeats the member expressions with no locals: the `fmr` pair
// after the two loads is the copy GCSE makes for the later redundant reloads.

struct GaugeTarget {
    char unknown00[68];
    int active;
    char unknown48[20];
    float value;
};

struct Gauge {
    char unknown00[208];
    void **table;
    char unknownD4[76];
    void *first;
    GaugeTarget *second;
    char unknown128[12];
    float current;
    float desired;
};

extern float high_803cbdf8[];
extern float low_803cbdfc[];
extern float gain_803cbe00[];
extern float one_803cbe04[];
extern "C" void fn_802bc790(void *, float);
extern "C" void fn_80296410(void *, float);

extern "C" int w3d_d25k_gauge_smooth_8026e884(Gauge *s) {
    ((void (*)(void *))s->table[3])((char *)s + 28);
    GaugeTarget *t = s->second;
    if (t && t->value != s->current) {
        if (t->active) {
            s->current = t->value;
            s->desired = t->value;
        } else {
            s->desired = t->value;
        }
    }
    if (s->desired != s->current) {
        float delta = s->desired - s->current;
        if (delta < high_803cbdf8[0] && delta > low_803cbdfc[0]) {
            s->current = s->desired;
        } else {
            float gain = gain_803cbe00[0];
            s->current = s->current * (one_803cbe04[0] - gain) + s->desired * gain;
        }
    }
    if (s->first) fn_802bc790(s->first, s->current);
    if (s->second) fn_80296410(s->second, s->current);
    return 0;
}
