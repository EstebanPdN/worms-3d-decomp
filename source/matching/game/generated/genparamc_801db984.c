/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Pair template (later batch): typed child walk. */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef int (*W3dGetInt)(void *);
typedef void (*W3dMethodP)(void *, void *);
#define ITEM(self, i) (FIELD(items, void **, 8)[i])

int w3d_update_typed_children_801db984(void *self, void *argument)
{
    unsigned int i;
    for (i = 0; i < FIELD(self, unsigned int, 48); i++) {
        char *items = (char *)self + 48;
        if ((*(W3dGetInt *)(*(char **)ITEM(self, i) + 28))(ITEM(self, i)) == 1
            || (*(W3dGetInt *)(*(char **)ITEM(self, i) + 28))(ITEM(self, i)) == 2)
            (*(W3dMethodP *)(*(char **)ITEM(self, i) + 64))(ITEM(self, i), argument);
    }
    return 0;
}

int w3d_update_typed_children_801dbadc(void *self, void *argument)
{
    unsigned int i;
    for (i = 0; i < FIELD(self, unsigned int, 48); i++) {
        char *items = (char *)self + 48;
        if ((*(W3dGetInt *)(*(char **)ITEM(self, i) + 28))(ITEM(self, i)) == 1
            || (*(W3dGetInt *)(*(char **)ITEM(self, i) + 28))(ITEM(self, i)) == 2)
            (*(W3dMethodP *)(*(char **)ITEM(self, i) + 68))(ITEM(self, i), argument);
    }
    return 0;
}
