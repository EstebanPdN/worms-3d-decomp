// Recovery hypothesis: original receiver and observed scalar slots only.
// This externally constructed view does not claim a complete dynamic type.
struct F18aChild { char unknown0[68]; int immediate; char unknown72[20]; float value; };
struct F18aSync {
    char unknown0[208];
    void (**dispatch)();
    char unknown212[76];
    void *sink;
    F18aChild *child;
    char unknown296[12];
    float current, target;
};
extern const float pool_803cbdf8[], pool_803cbdfc[], pool_803cbe00[], pool_803cbe04[];
extern "C" void fn_802bc790(void *, float);
extern "C" void fn_80296410(F18aChild *, float);
inline float approach(float target, float current) {
    if (target != current) {
        float delta = target-current;
        if (delta < pool_803cbdf8[0] && delta > pool_803cbdfc[0]) current = target;
        else current = target * pool_803cbe00[0] + current * (pool_803cbe04[0]-pool_803cbe00[0]);
    }
    return current;
}
extern "C" int w3d_f18a_sync_value_8026e884(F18aSync *self) {
    ((void (*)(void *))self->dispatch[3])((char *)self + 28);
    F18aChild *child = self->child;
    if (child && child->value != self->current) {
        if (child->immediate) {
            self->current = child->value;
            self->target = child->value;
        } else self->target = child->value;
    }
    self->current = approach(self->target,self->current);
    if (self->sink) fn_802bc790(self->sink,self->current);
    if (self->child) fn_80296410(self->child,self->current);
    return 0;
}
