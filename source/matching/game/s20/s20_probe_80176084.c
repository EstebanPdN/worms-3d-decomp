typedef struct S20Obj { void **vtable; } S20Obj;
typedef int (*S20ApplyF)(S20Obj *, char *, int, int, float);
typedef int (*S20ApplyI)(S20Obj *, char *, int, int, int);

int w3d_s20_apply_entries_float_80176084(S20Obj *self, char *entries, unsigned int count) {
    int result = 0;
    unsigned int i;
    for (i = 0; i < count; i++, entries += 16) {
        int r = ((S20ApplyF)self->vtable[11])(self, entries, *(unsigned char *)(entries + 4), *(int *)(entries + 8), *(float *)(entries + 12));
        if (r < 0)
            result = r;
    }
    return result;
}

int w3d_s20_apply_entries_zero_801762b8(S20Obj *self, char *entries, unsigned int count) {
    int result = 0;
    unsigned int i;
    for (i = 0; i < count; i++, entries += 12) {
        int r = ((S20ApplyI)self->vtable[15])(self, entries, 0, *(unsigned char *)(entries + 4), *(int *)(entries + 8));
        if (r < 0)
            result = r;
    }
    return result;
}
