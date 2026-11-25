/* Push with overflow flush, bump allocation, reference adjust and handle compare. */
extern void fn_80167094(char *);

void w3d_s20_push_pending_8016703c(char *self, int value) {
    char *items;
    int offset;
    if (*(unsigned int *)(self + 5256) > 1023)
        fn_80167094(self);
    items = self + 1160;
    offset = *(int *)(self + 5256) * 4;
    *(int *)(items + offset) = value;
    *(int *)(self + 5256) += 1;
}

typedef struct S20Object { void **vtable; } S20Object;
typedef struct S20Counter { void **vtable; char pad[76]; unsigned char count; } S20Counter;
typedef struct S20Holder20 { char pad[20]; S20Object *inner; } S20Holder20;

void w3d_s20_drop_reference_8019ab0c(S20Holder20 *self, char *item) {
    S20Object *first = ((S20Object *(*)(S20Object *))self->inner->vtable[7])(self->inner);
    S20Counter *second = ((S20Counter *(*)(S20Object *, int))first->vtable[9])(first, *(unsigned short *)(item + 16));
    second->count -= 1;
}

extern int fn_801190d0(void *);
extern void *fn_80164fc8(int);
extern int fn_800da7bc(void *);

int w3d_s20_matches_handle_8013f168(char *self, int handle) {
    void *object = fn_80164fc8(fn_801190d0(handle));
    return object ? fn_800da7bc(object) == *(int *)(self + 112) : 0;
}
