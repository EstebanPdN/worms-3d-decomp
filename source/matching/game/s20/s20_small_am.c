/* Held-object handling, offset accumulation and id acceptance. */
typedef struct S20Obj { void **vtable; } S20Obj;
typedef struct S20F3 { float x, y, z; } S20F3;
typedef void (*S20CallV)(S20Obj *, int, S20F3 *);
extern S20Obj *fn_80164fc8(int);
extern float lbl_8038b27c[];

typedef void (*S20Call0)(S20Obj *);
extern void fn_800f6afc(char *);
extern void fn_8015af24(unsigned char);
extern void fn_8015aee8(unsigned char);

void w3d_s20_swap_handles_800f3028(char *self) {
    S20Obj *held;
    S20Obj **slot;
    unsigned int i;
    S20Obj *empty;
    fn_800f6afc(self);
    if (*(int *)(self + 3196) != *(int *)(self + 3192)) {
        held = *(S20Obj **)(self + 28);
        if (held != 0)
            ((S20Call0)held->vtable[4])(held);
        *(int *)(self + 28) = 0;
        for (i = 0, empty = 0, slot = (S20Obj **)(self + 88); i < 200; i++) {
            if (*slot != 0)
                ((S20Call0)(*slot)->vtable[4])(*slot);
            *slot = empty;
            slot++;
        }
        if (*(int *)(self + 3192) >= 0) {
            fn_8015af24(*(unsigned char *)(self + 3195));
            *(int *)(self + 3192) = -1;
        }
        fn_8015aee8(*(unsigned char *)(self + 3199));
        *(int *)(self + 3192) = *(int *)(self + 3196);
    }
}

extern int fn_8026cc60(void *);
extern int fn_8026c96c(char *, int);

void w3d_s20_replace_held_800f3524(char *self, S20Obj **holder, int arg) {
    S20Obj *held;
    S20Obj *old;
    held = *holder;
    if (held != 0)
        ((S20Call0)held->vtable[3])(held);
    old = *(S20Obj **)(self + 32);
    if (old != 0)
        ((S20Call0)old->vtable[4])(old);
    *(S20Obj **)(self + 32) = *holder;
    fn_8026c96c(self + 3072, fn_8026cc60(arg));
    fn_800f6afc(self);
    if (*(int *)(self + 3168) == 0)
        *(int *)(self + 3168) = 1;
    held = *holder;
    if (held != 0)
        ((S20Call0)held->vtable[4])(held);
}

extern char *fn_8003888c(void);
extern int fn_8021eb00(int);
extern char *lbl_804aaabc;
extern char *lbl_804abac0;

int w3d_s20_can_accept_id_800f899c(char *self, unsigned short *id) {
    unsigned int i;
    unsigned short *list;
    if (*(int *)(fn_8003888c() + 36) != 0 || (*(unsigned int *)(lbl_804aaabc + 240) & 0x800000) != 0)
        return 0;
    for (i = 0; i < *(unsigned int *)(self + 440); i++) {
        if (*id == ((unsigned short *)*(char **)(self + 436))[i]) return 0;
    }
    if (fn_8021eb00(*(int *)(*(char **)(lbl_804abac0 + 36) + 24)) == 0)
        return 0;
    return 1;
}

void w3d_s20_accumulate_offset_800e9528(char *self, int arg) {
    S20F3 offset;
    S20F3 *p = &offset;
    S20F3 *position = (S20F3 *)(self + 60);
    S20Obj *obj = fn_80164fc8(*(int *)(self + 192));
    ((S20CallV)obj->vtable[11])(obj, arg, position);
    offset.x = lbl_8038b27c[0];
    p->y = lbl_8038b27c[0];
    p->z = lbl_8038b27c[0];
    ((S20CallV)obj->vtable[15])(obj, arg, p);
    *(float *)(self + 60) += offset.x;
    position->y += p->y;
    position->z += p->z;
}
