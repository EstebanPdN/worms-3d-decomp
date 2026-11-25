// Observed partial field/callback views; complete class identities and sizes unknown.
struct d10b_SliderBase;
struct d10b_SliderVtable { unsigned int unknown00[3]; void (*update)(d10b_SliderBase *); };
struct d10b_SliderInput { unsigned char unknown00[68]; int immediate; unsigned char unknown48[20]; float value; };
struct d10b_SliderDisplay;
struct d10b_SliderOwner {
    unsigned char unknown00[208]; d10b_SliderVtable *base_table;
    unsigned char unknownd4[76]; d10b_SliderDisplay *display; d10b_SliderInput *input;
    unsigned char unknown128[12]; float current,target;
};
extern const float d10b_upper_epsilon_803cbdf8[], d10b_lower_epsilon_803cbdfc[], d10b_blend_803cbe00[],d10b_one_803cbe04[];
extern "C" void d10b_set_display_802bc790(d10b_SliderDisplay *,float);
extern "C" void d10b_set_input_80296410(d10b_SliderInput *,float);
extern "C" int d10b_update_slider_8026e884(d10b_SliderOwner *self) {
    self->base_table->update(reinterpret_cast<d10b_SliderBase *>(reinterpret_cast<unsigned char *>(self)+28));
    if (self->input && self->input->value!=self->current) {
        if (self->input->immediate) {
            self->current=self->input->value;
            self->target=self->input->value;
        } else self->target=self->input->value;
    }
    if (self->target!=self->current) {
        float target=self->target;
        float current=self->current;
        if (target-current<d10b_upper_epsilon_803cbdf8[0] && target-current>d10b_lower_epsilon_803cbdfc[0])
            self->current=target;
        else {
            float blend=d10b_blend_803cbe00[0];
            self->current=current*(d10b_one_803cbe04[0]-blend)+target*blend;
        }
    }
    if (self->display) d10b_set_display_802bc790(self->display,self->current);
    if (self->input) d10b_set_input_80296410(self->input,self->current);
    return 0;
}
