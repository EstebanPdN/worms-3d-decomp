// Observed partial field/callback views; complete class identities and sizes unknown.
struct sol35e_SliderBase;
struct sol35e_SliderVtable { unsigned int unknown00[3]; void (*update)(sol35e_SliderBase *); };
struct sol35e_SliderInput { unsigned char unknown00[68]; int immediate; unsigned char unknown48[20]; float value; };
struct sol35e_SliderDisplay;
struct sol35e_SliderOwner {
    unsigned char unknown00[208]; sol35e_SliderVtable *base_table;
    unsigned char unknownd4[76]; sol35e_SliderDisplay *display; sol35e_SliderInput *input;
    unsigned char unknown128[12]; float current,target;
};
extern const float sol35e_upper_epsilon_803cbdf8[], sol35e_lower_epsilon_803cbdfc[], sol35e_blend_803cbe00[],sol35e_one_803cbe04[];
extern "C" void sol35e_set_display_802bc790(sol35e_SliderDisplay *,float);
extern "C" void sol35e_set_input_80296410(sol35e_SliderInput *,float);
inline void sol35e_blend_slider(float target,float current,float &out) {
 if(target!=current) {
  if(target-current<sol35e_upper_epsilon_803cbdf8[0] && target-current>sol35e_lower_epsilon_803cbdfc[0]) out=target;
  else {float blend=sol35e_blend_803cbe00[0];out=current*(sol35e_one_803cbe04[0]-blend)+target*blend;}
 }
}
extern "C" int sol35e_update_slider_8026e884(sol35e_SliderOwner *self) {
    self->base_table->update(reinterpret_cast<sol35e_SliderBase *>(reinterpret_cast<unsigned char *>(self)+28));
    if (self->input && self->input->value!=self->current) {
        if (self->input->immediate) {
            self->current=self->input->value;
            self->target=self->input->value;
        } else self->target=self->input->value;
    }
    float target=self->target;float current=self->current;sol35e_blend_slider(target,current,self->current);
    if (self->display) sol35e_set_display_802bc790(self->display,self->current);
    if (self->input) sol35e_set_input_80296410(self->input,self->current);
    return 0;
}
