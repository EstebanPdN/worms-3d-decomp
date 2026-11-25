/* Reference counts in bitfields, object reset and small forwards. */
typedef struct S20Counted { char pad[28]; unsigned int count : 15; unsigned int rest : 17; } S20Counted;

int w3d_s20_add_count_80190438(S20Counted *self) {
    ++self->count;
    return 0;
}

int w3d_s20_release_count_80190458(S20Counted *self) {
    --self->count;
    return 0;
}

char *w3d_s20_reset_800f6c64(char *self) {
    char *a = self + 4;
    char *b = self + 16;
    *(int *)(a + 8) = 0;
    *(int *)(a + 4) = 0;
    *(int *)(self + 4) = 0;
    *(int *)(b + 8) = 0;
    *(int *)(b + 4) = 0;
    *(int *)(self + 28) = -1;
    *(int *)(self + 16) = 0;
    *(int *)(self + 32) = 0;
    *(int *)(self + 60) = 0;
    return self;
}

extern int fn_800fd504(int, int, int);
extern int lbl_803fcce0[];

int w3d_s20_forward_indexed_800fd4c8(int index, int value) {
    return fn_800fd504(lbl_803fcce0[index], index, value);
}

extern int fn_8020c3a0(char *, int);

int w3d_s20_shrink_range_801b25ac(char *self) {
    int length = *(int *)(self + 56) - *(int *)(self + 44);
    *(int *)(self + 56) = length;
    return fn_8020c3a0(self + 60, length);
}
