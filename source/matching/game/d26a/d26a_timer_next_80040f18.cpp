// GWMP8P rev0 0x80040f18. Runs whichever of two pending timers comes first.
// Field names are inferred from the original instructions.
struct Timer {
    char unknown00[8];
    float first;       /* +8 */
    float queued;      /* +12 */
    char unknown10[8];
    float second;      /* +24 */
};
extern "C" int w3d_fn_80040b0c(Timer *);
extern "C" int w3d_fn_80040d84(Timer *);

/* A negative time means "not pending". */
inline bool Sooner(const float &x, const float &y)
{
    if (!(x < 0.0f) && (y < 0.0f || x <= y)) return true;
    return false;
}

extern "C" int w3d_d26a_timer_next_80040f18(Timer *t)
{
    float none;
    if (Sooner(t->second, t->first)) {
        none = -1.0f;
        t->second = none;
        return w3d_fn_80040b0c(t);
    } else {
        if (Sooner(t->first, t->second)) {
            t->first = t->queued;
            none = -1.0f;
            t->queued = none;
            return w3d_fn_80040d84(t);
        }
        return 0;
    }
}
