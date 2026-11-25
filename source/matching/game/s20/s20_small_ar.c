/* Vector set, table clearing and item registration. */
typedef struct S20V3 { int x; int y; int z; } S20V3;
typedef struct S20Obj { void **vtable; } S20Obj;
typedef void (*S20Call0)(S20Obj *);
extern int fn_80178b5c(char *);
extern void fn_8020bd38(char *, int);
extern int lbl_804a8dd8[];
extern int fn_8017ce10(char *, unsigned char *);
extern int fn_8017d288(char *, unsigned char *);

int w3d_s20_set_vector_if_changed_80178fa4(char *self, S20V3 *value) {
    char *owner = *(char **)(self + 4);
    S20V3 *current = (S20V3 *)(owner + 28);
    int same = 0;
    if (value->x == current->x && value->y == current->y)
        same = value->z == current->z;
    if (same != 0)
        return 1;
    *(S20V3 *)(*(char **)(self + 4) + 28) = *value;
    fn_80178b5c(self);
    return 0;
}

int w3d_s20_clear_tables_8017ccdc(char *self) {
    unsigned int i;
    unsigned int j;
    S20Obj **slot;
    S20Obj *empty;
    char *name;
    char *id;
    short none;
    for (i = 0, empty = 0, slot = (S20Obj **)(self + 24); i < 1920; i++) {
        if (*slot != 0)
            ((S20Call0)(*slot)->vtable[4])(*slot);
        *slot = empty;
        slot++;
    }
    j = 0;
    none = -1;
    id = self + 7708;
    name = self + 7704;
    for (; j < 256; j++) {
        fn_8020bd38(name, 0);
        *(short *)id = none;
        name += 8;
        id += 8;
    }
    *(int *)(self + 9752) = 0;
    return 0;
}

int w3d_s20_register_item_8017cd80(char *self, unsigned char *item) {
    int result;
    if (lbl_804a8dd8[*item] != 0)
        return 0x80004005;
    lbl_804a8dd8[*item] = 1;
    if (*(int *)(self + 9828) != 0)
        result = fn_8017ce10(self, item);
    else
        result = fn_8017d288(self, item);
    lbl_804a8dd8[*item] = 1;
    return result;
}
