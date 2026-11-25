/* Methods that run on the secondary base subobject of an object (this - 4, null-checked). */
extern void fn_801f6834(void *, void *, int);
extern int fn_801aa79c(void *, char *);

void w3d_s20_forward_base_pair_801aab20(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    fn_801f6834(item + 48, item + 112, *(int *)(base + 56));
    fn_801aa79c(self, item);
}

int w3d_s20_set_base_mode_801d5700(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    unsigned int flags = *(unsigned short *)(item + 40);
    if (*(int *)(base + 44) != 1)
        *(int *)(base + 44) = (flags >> 1) & 3;
    return 0;
}

typedef void (*S20Slot2)(void *, char *);

int w3d_s20_virtual_item_801ac378(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    char *vtable = *(char **)base;
    ((S20Slot2)*(void **)(vtable + 64))(base, item + 20);
    return 0;
}


extern int fn_8016beac(char *, char *);
typedef int (*S20Flush1)(char *);
int w3d_s20_flush_base_8016bf68(char *self) {
    char *base = self ? self - 4 : 0;
    if (*(int *)(base + 200) == 0)
        return 0;
    ((S20Flush1)fn_8016beac)(base);
    return 0;
}

extern int fn_801a3944(void *, int);

int w3d_s20_call_keep_base_field_801aaf6c(char *self, int arg) {
    char *base = self ? self - 4 : 0;
    int saved = *(int *)(base + 164);
    int result;
    *(int *)(base + 164) = arg;
    result = fn_801a3944(self, arg);
    *(int *)(base + 164) = saved;
    return result;
}

extern int fn_801689e4(char *, void *);

void w3d_s20_scoped_base_range_80168a9c(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    char *range = *(char **)(item + 60);
    *(int *)(base + 132) = *(int *)(range + 24);
    *(char **)(base + 128) = range + 32;
    fn_801689e4(self, (void *)item);
    *(char **)(base + 128) = 0;
}

typedef void (*S20Slot0)(void *);
typedef void *(*S20SlotObj)(void *);
typedef void (*S20SlotPut)(void *, char *);

int w3d_s20_dispatch_base_target_80166b14(char *self) {
    char *base = self ? self - 4 : 0;
    if (base != 0) {
        char *target = *(char **)(base + 44);
        if (target != 0) {
            ((S20Slot0)*(void **)(*(char **)target + 24))(target);
            return 0;
        }
    }
    return 1;
}

int w3d_s20_virtual_chain_item_801ac3bc(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    char *object = (char *)((S20SlotObj)*(void **)(*(char **)base + 52))(base);
    ((S20SlotPut)*(void **)(*(char **)object + 84))(object, item + 20);
    return 0;
}

extern void fn_80309404(int, float, int);

int w3d_s20_flush_base_scaled_8016bfb0(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    if (*(int *)(base + 200) == 0)
        return 0;
    fn_80309404(fn_8016beac(base, item), *(float *)(item + 200), 2);
    return 0;
}

typedef struct S20Temp { int words[6]; } S20Temp;
extern void fn_801f5b0c(S20Temp *, char *, int);

int w3d_s20_dispatch_temp_801a5c48(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    S20Temp temp;
    char *record = *(char **)(item + 20);
    char *tp = (char *)&temp;
    fn_801f5b0c((S20Temp *)tp, record + 32, *(int *)(record + 24));
    ((S20SlotPut)*(void **)(*(char **)base + 76))(base, tp);
    return 0;
}
