// Inferred countdown/gain update. Observed state: interface +0, duration +4,
// remaining +8, scale +12. Vtable slots +0x24 and +0x34 remain external.
struct R25bGainTarget;
struct R25bGainMethods {
    void (*reserved0[9])();
    int (*ready)(R25bGainTarget *);
    void (*reserved1[3])();
    void (*setGain)(R25bGainTarget *, int, float);
};
struct R25bGainTarget { R25bGainMethods *methods; };
struct R25bGainState {
    R25bGainTarget *target;
    int duration;
    int remaining;
    float scale;
};
extern "C" int w3d_r25b_step_gain_801db06c(R25bGainState *state, int elapsed)
{
    state->remaining -= elapsed;
    if (state->remaining < 0)
        return 0;
    if (!state->target->methods->ready(state->target))
        return 0;
    state->target->methods->setGain(
        state->target, 1, (state->scale * float(state->remaining)) / float(state->duration));
    return 1;
}
