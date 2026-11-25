typedef struct S20V3 { int x; int y; int z; } S20V3;
typedef struct S20Obj {
    short id;
    short pad;
    char *vtable;
    int a;
    int b;
    S20V3 v1;
    S20V3 v2;
    S20V3 v3;
} S20Obj;
extern char lbl_8040db38[];
char *w3d_s20_construct_three_vectors_800e7c78(char *self, short id, int a, int b, S20V3 *v1, S20V3 *v2, S20V3 *v3) {
    *(short *)self = id;
    *(int *)(self + 8) = a;
    *(char **)(self + 4) = lbl_8040db38;
    *(int *)(self + 12) = b;
    *(S20V3 *)(self + 16) = *v1;
    *(S20V3 *)(self + 28) = *v2;
    *(S20V3 *)(self + 40) = *v3;
    return self;
}
typedef struct S20Obj2 { void **vtable; } S20Obj2;
void w3d_s20_release_held_800f34a0(char *self) {
    S20Obj2 *held = *(S20Obj2 **)(self + 888);
    *(int *)(self + 3168) = 0;
    if (held != 0)
        ((void (*)(S20Obj2 *))held->vtable[4])(held);
    *(int *)(self + 888) = 0;
}
