/* Handle checks, bit masks, counted construction and lookups. */
typedef struct S20HandleHolder { char pad[140]; int handle; } S20HandleHolder;
extern void *fn_80164fc8(int);
extern void fn_800cd178(void *);

void w3d_s20_refresh_handle_8013f2f8(S20HandleHolder *self) {
    if (self->handle != -1) {
        void *object = fn_80164fc8(self->handle);
        if (object == 0)
            self->handle = -1;
        else
            fn_800cd178(object);
    }
}

extern void fn_803096b0(char *, int);

void w3d_s20_enable_slot_8016857c(char *self, int slot) {
    int offset = slot * 64 + 264;
    int bit = 1 << slot;
    fn_803096b0(self + offset, bit);
    *(unsigned int *)(self + 776) |= bit;
}

extern void * fn_801857f4(char *);
extern char lbl_80412068[];
extern int lbl_804ab580;

char *w3d_s20_construct_counted_80172b14(char *self) {
    int count;
    fn_801857f4(self);
    count = lbl_804ab580;
    *(char **)self = lbl_80412068;
    *(int *)(self + 128) = 0;
    lbl_804ab580 = count + 1;
    return self;
}

extern int fn_8017e22c(char *, void *, unsigned short *);

int w3d_s20_lookup_slot_8017ded8(char *self, int key) {
    unsigned short index;
    if (fn_8017e22c(self, key, &index) < 0)
        return 0;
    return *(int *)(self + index * 4 + 24);
}

extern int fn_801d60cc(char *, int, char *);
extern int fn_801a37a0(char *, char *);

int w3d_s20_notify_then_apply_801d6550(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    fn_801d60cc(base, 3, item);
    return fn_801a37a0(self, item);
}
