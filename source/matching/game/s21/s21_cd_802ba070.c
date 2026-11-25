// desc: Appears to release the three objects held in an array at offset 224 through a helper and clear their slots.
struct S21Object { char pad[224]; void *slots[3]; };
extern void fn_8025e0c4(void *, int);
void w3d_s21_release_slots_802ba070(struct S21Object *self)
{
    void **slot = self->slots;
    unsigned i = 0;
    do {
        void *object = *slot;
        i++;
        if (object) {
            fn_8025e0c4(object, 3);
            *slot = 0;
        }
        slot++;
    } while (i <= 2);
}
