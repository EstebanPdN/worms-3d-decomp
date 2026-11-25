// desc: Appears to forward the object's value to a held interface through virtual slot 22 and call a function pointer of the owner on the embedded part when a flag is set.
struct S21Interface;
struct S21InterfaceMethods { void (*reserved[22])(void); void (*apply)(struct S21Interface *, int); };
struct S21Interface { struct S21InterfaceMethods *methods; };
struct S21Owner { char pad[56]; void (*notify)(void *); };
struct S21Object { char pad[28]; char part[148]; int enabled; char pad1[28]; struct S21Owner *owner; char pad2[8]; int value; char pad3[16]; struct S21Interface *held; };
void w3d_s21_sync_802b4e8c(struct S21Object *self)
{
    if (self->held)
        self->held->methods->apply(self->held, self->value);
    if (self->enabled)
        self->owner->notify(self->part);
}
