struct S21Gauge { char pad[288]; int source; int notify; int active; char pad1[8]; float target; float current; };
extern void fn_8026fc98(struct S21Gauge *, int);
extern float fn_802bc93c(void *, int, int);
extern void fn_80296410(void *, float);
void w3d_s21_gauge_sync_8026f948(struct S21Gauge *self, int mode, int store_target)
{
    if (self->active && self->source) {
        float value;
        if (mode != -1)
            fn_8026fc98(self, 0);
        value = fn_802bc93c(self->source, mode, 1);
        self->current = value;
        if (store_target)
            self->target = value;
        if (self->notify)
            fn_80296410(self->notify, value);
    }
}
