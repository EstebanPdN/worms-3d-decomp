typedef struct S20Obj { void **vtable; } S20Obj;
typedef void (*S20Call0)(S20Obj *);
extern int fn_80177eb0(char *, char *, unsigned short *);

int w3d_s20_bind_slot_80176664(char *self, char *name, S20Obj **holder) {
    unsigned short index;
    int result;
    S20Obj **table;
    unsigned int offset;
    result = fn_80177eb0(self, name, &index);
    if (result < 0) {
        if (*holder != 0)
            ((S20Call0)(*holder)->vtable[4])(*holder);
        return result;
    }
    table = *(S20Obj ***)(self + 24);
    offset = index * 4;
    if (*(S20Obj **)((char *)table + offset) != 0)
        ((S20Call0)(*(S20Obj **)((char *)table + offset))->vtable[3])(*(S20Obj **)((char *)table + offset));
    if (*holder != 0)
        ((S20Call0)(*holder)->vtable[4])(*holder);
    *holder = *(S20Obj **)((char *)table + offset);
    return 0;
}
