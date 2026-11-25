/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Pair template (later batch): reference array assignment. */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef void (*W3dMethod)(void *);
#define VCALL(p, o) ((*(W3dMethod *)(*(char **)(p) + (o)))(p))
void fn_801f282c(void *, unsigned int);
void fn_80210b90(void *, unsigned int);

void *w3d_assign_refs_801f2b04(void *self, void *other)
{
    unsigned int i;
    fn_801f282c(self, FIELD(other, unsigned int, 0));
    for (i = 0; i < FIELD(other, unsigned int, 0); i++) {
        void **source = FIELD(other, void **, 8);
        void **target = FIELD(self, void **, 8);
        if (source[i])
            VCALL(source[i], 12);
        if (target[i])
            VCALL(target[i], 16);
        target[i] = source[i];
    }
    return self;
}

void *w3d_assign_refs_80210eb4(void *self, void *other)
{
    unsigned int i;
    fn_80210b90(self, FIELD(other, unsigned int, 0));
    for (i = 0; i < FIELD(other, unsigned int, 0); i++) {
        void **source = FIELD(other, void **, 8);
        void **target = FIELD(self, void **, 8);
        if (source[i])
            VCALL(source[i], 12);
        if (target[i])
            VCALL(target[i], 16);
        target[i] = source[i];
    }
    return self;
}
