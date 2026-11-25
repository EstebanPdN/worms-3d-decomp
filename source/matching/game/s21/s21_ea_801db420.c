// desc: Appears to start an object once: when not yet started it calls virtual slot 36, marks it started and returns the slot's result, otherwise it returns 0x80004005.
struct S21Object;
struct S21Methods { void (*reserved[36])(void); int (*start)(struct S21Object *); };
struct S21Object { struct S21Methods *methods; char pad[172]; int started; };
int w3d_s21_start_once_801db420(struct S21Object *self)
{
    int status;
    if (self->started == 0) {
        status = self->methods->start(self);
        self->started = 1;
    } else
        status = 0x80004005;
    return status;
}
