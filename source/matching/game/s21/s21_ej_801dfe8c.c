// desc: Appears to shut down an object: it flushes and destroys each of the 32 objects in its slot array through the vtable pointer at offset 28, releases the held interface and returns zero.
struct S21Slot;
struct S21SlotMethods { void (*reserved[2])(void); void (*destroy)(struct S21Slot *, int); void (*flush)(struct S21Slot *); void (*reserved1[6])(void); void (*stop)(struct S21Slot *); };
struct S21Slot { char pad[28]; struct S21SlotMethods *methods; };
struct S21Ref;
struct S21RefMethods { void (*reserved[4])(void); void (*release)(struct S21Ref *); };
struct S21Ref { struct S21RefMethods *methods; };
struct S21Object { char pad[20]; struct S21Ref *held; char pad1[24]; struct S21Slot *slots[32]; };
int w3d_s21_shutdown_801dfe8c(struct S21Object *self)
{
    unsigned i = 0;
    struct S21Slot *none = 0;
    struct S21Slot **slot = self->slots;
    do {
        if (*slot) {
            (*slot)->methods->flush(*slot);
            (*slot)->methods->stop(*slot);
            if (*slot)
                (*slot)->methods->destroy(*slot, 3);
            *slot = none;
        }
        i++;
        slot++;
    } while (i <= 31);
    if (self->held)
        self->held->methods->release(self->held);
    self->held = 0;
    return 0;
}
