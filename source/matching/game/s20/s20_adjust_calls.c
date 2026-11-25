/* Methods that run on the secondary base subobject of an object (this - 4, null-checked). */
extern int fn_801a572c(void *, void *);
extern int fn_801a46bc(void *, void *, void *);
extern int fn_801ad790(void *, char *, char *);
extern int fn_801a59c0(void *, char *);
extern void fn_802cd99c(void *, int);
extern void fn_802ce148(void *, void *, int);
extern void fn_802cdfd4(void *, char *);
extern void fn_802cd8e0(void *, int);
extern void fn_802ce4d8(void *, int);

void w3d_s20_forward_base_field_801a59c0(char *self) {
    char *base = self ? self - 4 : 0;
    fn_801a572c(self, *(int *)(base + 0x18));
}

void w3d_s20_forward_base_field_801aac8c(char *self, int arg) {
    char *base = self ? self - 4 : 0;
    fn_801a46bc(self, arg, *(int *)(base + 0x38));
}

void w3d_s20_forward_base_range_801ad8fc(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    fn_801ad790(base, item, item + 20);
}

typedef int (*S20GetSlot)(void *);
typedef void (*S20PutSlot)(void *, int, char *);

int w3d_s20_apply_base_item_801a59f4(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    int result = fn_801a59c0(self, item);
    if (result >= 0) {
        char *vtable = *(char **)base;
        ((S20PutSlot)*(void **)(vtable + 0x50))(base, ((S20GetSlot)*(void **)(vtable + 0x40))(base), item + 20);
        result = 0;
    }
    return result;
}

void w3d_s20_lua_set_closure_field_801a0384(void *L, char *name, void *function, int index) {
    fn_802cd99c(L, index);
    fn_802ce148(L, function, 1);
    fn_802cdfd4(L, name);
    fn_802cd8e0(L, -2);
    fn_802ce4d8(L, -3);
}
