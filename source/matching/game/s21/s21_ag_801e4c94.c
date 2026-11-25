// desc: Appears to call a virtual slot through the vtable field at offset 28 and then clear four words of the object.
struct S21Object { int a; int b; int c; int d; char pad[12]; void **vtable; };
void w3d_s21_reset_801e4c94(struct S21Object *self)
{
    ((void (*)(struct S21Object *))self->vtable[3])(self);
    self->d = 0;
    self->b = 0;
    self->c = 0;
    self->a = 0;
}
