/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Pair template (later batch): three-word value setter that notifies an
 * attached object unconditionally (see families_j.c for the guarded form). */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct W3dTriple { int a; int b; int c; } W3dTriple;
typedef void (*W3dNotify)(void *, void *, int);

void w3d_set_triple_notify_8026d488(void *self, const W3dTriple *value)
{
    W3dTriple *current = &FIELD(self, W3dTriple, 44);
    int same = current->a == value->a && current->b == value->b && current->c == value->c;
    if (!same) {
        void *listener;
        FIELD(self, W3dTriple, 44) = *value;
        listener = FIELD(self, void *, 76);
        (*(W3dNotify *)(*(char **)listener + 84))(listener, &FIELD(self, W3dTriple, 44), 0);
    }
}

void w3d_set_triple_notify_8026d524(void *self, const W3dTriple *value)
{
    W3dTriple *current = &FIELD(self, W3dTriple, 32);
    int same = current->a == value->a && current->b == value->b && current->c == value->c;
    if (!same) {
        void *listener;
        FIELD(self, W3dTriple, 32) = *value;
        listener = FIELD(self, void *, 76);
        (*(W3dNotify *)(*(char **)listener + 76))(listener, &FIELD(self, W3dTriple, 32), 0);
    }
}
