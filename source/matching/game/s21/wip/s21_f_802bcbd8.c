struct S21Slider { char pad[76]; float value; int mode; };
extern float lbl_803d82f8[];
extern float lbl_803d82fc[];
extern void fn_802bc570(void);
void w3d_s21_slider_set_value_802bcbd8(struct S21Slider *s, float value)
{
    if (s->value != value) {
        s->value = value;
        if (value < lbl_803d82f8[0])
            s->value = lbl_803d82f8[0];
        if (s->value > lbl_803d82fc[0])
            s->value = lbl_803d82fc[0];
        if (s->mode == 1)
            fn_802bc570();
    }
}
