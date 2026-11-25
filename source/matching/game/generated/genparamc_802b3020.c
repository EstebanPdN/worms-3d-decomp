/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Family templates, 2026-10-22 (third session), ninth batch. */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct W3dTriple { int a; int b; int c; } W3dTriple;
typedef void (*W3dNotify)(void *, void *, int);

void w3d_set_triple_802b3020(void *self, const W3dTriple *value)
{
    W3dTriple *current = &FIELD(self, W3dTriple, 68);
    int same = current->a == value->a && current->b == value->b && current->c == value->c;
    if (!same) {
        void *listener;
        FIELD(self, W3dTriple, 68) = *value;
        listener = FIELD(self, void *, 28);
        if (listener)
            (*(W3dNotify *)(*(char **)listener + 76))(listener, &FIELD(self, W3dTriple, 68), 0);
    }
}

void w3d_set_triple_802c61fc(void *self, const W3dTriple *value)
{
    W3dTriple *current = &FIELD(self, W3dTriple, 60);
    int same = current->a == value->a && current->b == value->b && current->c == value->c;
    if (!same) {
        void *listener;
        FIELD(self, W3dTriple, 60) = *value;
        listener = FIELD(self, void *, 28);
        if (listener)
            (*(W3dNotify *)(*(char **)listener + 76))(listener, &FIELD(self, W3dTriple, 60), 0);
    }
}

void w3d_set_triple_802c71d8(void *self, const W3dTriple *value)
{
    W3dTriple *current = &FIELD(self, W3dTriple, 112);
    int same = current->a == value->a && current->b == value->b && current->c == value->c;
    if (!same) {
        void *listener;
        FIELD(self, W3dTriple, 112) = *value;
        listener = FIELD(self, void *, 28);
        if (listener)
            (*(W3dNotify *)(*(char **)listener + 76))(listener, &FIELD(self, W3dTriple, 112), 0);
    }
}
