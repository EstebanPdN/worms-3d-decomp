// Observed partial field/callback views; complete class identities and sizes unknown.
struct d11b_SliderBase;
struct d11b_SliderVtable { unsigned int unknown00[3]; void (*update)(d11b_SliderBase *); };
struct d11b_SliderInput { unsigned char unknown00[68]; int immediate; unsigned char unknown48[20]; float value; };
struct d11b_SliderDisplay;
struct d11b_SliderOwner {
    unsigned char unknown00[208]; d11b_SliderVtable *base_table;
    unsigned char unknownd4[76]; d11b_SliderDisplay *display; d11b_SliderInput *input;
    unsigned char unknown128[12]; float current,target;
};
extern const float d11b_upper_epsilon_803cbdf8[], d11b_lower_epsilon_803cbdfc[], d11b_blend_803cbe00[],d11b_one_803cbe04[];
extern "C" void d11b_set_display_802bc790(d11b_SliderDisplay *,float);
extern "C" void d11b_set_input_80296410(d11b_SliderInput *,float);
static inline float d11b_blend_slider(float target,float current) {
    if (target!=current) {
        if (target-current<d11b_upper_epsilon_803cbdf8[0] && target-current>d11b_lower_epsilon_803cbdfc[0]) return target;
        float blend=d11b_blend_803cbe00[0];
        return current*(d11b_one_803cbe04[0]-blend)+target*blend;
    }
    return current;
}
extern "C" int d11b_update_slider_8026e884(d11b_SliderOwner *self) {
    self->base_table->update(reinterpret_cast<d11b_SliderBase *>(reinterpret_cast<unsigned char *>(self)+28));
    if (self->input && self->input->value!=self->current) {
        if (self->input->immediate) {
            self->current=self->input->value;
            self->target=self->input->value;
        } else self->target=self->input->value;
    }
    self->current=d11b_blend_slider(self->target,self->current);
    if (self->display) d11b_set_display_802bc790(self->display,self->current);
    if (self->input) d11b_set_input_80296410(self->input,self->current);
    return 0;
}
