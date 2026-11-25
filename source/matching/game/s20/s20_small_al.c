/* Position query through a sub-object and indexed table apply. */
typedef struct S20V3 { int x; int y; int z; } S20V3;
typedef struct S20Obj { void **vtable; } S20Obj;
typedef int (*S20Call1)(S20Obj *, char *);
extern unsigned short fn_80343740(S20V3 *);
extern int fn_801a3190(char *, int, void *);

int w3d_s20_query_position_800e25dc(char *self, S20V3 *out) {
    struct {
        S20V3 scratch[3];
        S20V3 position;
    } local;
    S20Obj *sub;
    int result;
    S20V3 *scratch = local.scratch;
    S20V3 *position = &local.position;
    fn_80343740(position);
    sub = *(S20Obj **)(self + 300);
    if (sub == 0) {
        return 0x80004005;
    }
    result = ((S20Call1)sub->vtable[31])(sub, (char *)scratch);
    *out = *position;
    return result;
}

int w3d_s20_apply_indexed_801a3164(char *self, int index) {
    int *entry;
    entry = (int *)(*(char **)(self + 48) + index * 4);
    return fn_801a3190(self, index, *entry);
}
