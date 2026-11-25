extern void *FUN_8003671c(void *);
extern void w3d_auto_80036abc(void *, int, int, float);
extern int s8_property_write_800fc43c(void *name, int value);
struct S19Cam { char pad0[16]; int handle; };

void s19_update_shake_800364d0(struct S19Cam *self, int arg, float t)
{
    struct { const char *name; int extra[2]; } k;
    self->handle = self->handle + 1;
    w3d_auto_80036abc(FUN_8003671c(self), self->handle, arg, t);
    k.name = "Camera.Shake.Handle";
    s8_property_write_800fc43c(&k.name, self->handle);
}
