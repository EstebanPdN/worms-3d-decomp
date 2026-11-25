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
extern "C" void d11b_set_display_802bc790(d11b_SliderDisplay *,float);
extern "C" void d11b_set_input_80296410(d11b_SliderInput *,float);
extern "C" int d11b_update_slider_8026e884(d11b_SliderOwner *self) {
    self->base_table->update(reinterpret_cast<d11b_SliderBase *>(reinterpret_cast<unsigned char *>(self)+28));
    if (self->input && self->input->value!=self->current) {
        if (self->input->immediate) {
            self->current=self->input->value;
            self->target=self->input->value;
        } else self->target=self->input->value;
    }
    if (self->target!=self->current) {
        float target=self->target;
        float current=self->current;
        if (target-current<0.009999999776482582f && target-current>-0.009999999776482582f)
            self->current=target;
        else {
            float blend=0.25f;
            self->current=current*(1.0f-blend)+target*blend;
        }
    }
    if (self->display) d11b_set_display_802bc790(self->display,self->current);
    if (self->input) d11b_set_input_80296410(self->input,self->current);
    return 0;
}
