/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Inlined STL-style vector erase-by-value. The original calls memcpy through
 * a variadic declaration (cr1 cleared) and folds copy()'s size to
 * (end - 1) - position; the vector is addressed afresh at each use. */
#define VEC(p, o) (*(W3dIntVector *)((char *)(p) + (o)))
extern "C" void *memcpy(...);
struct W3dIntVector {
    int *first;
    int *last;
    int *begin() { return first; }
    int *end() { return last; }
    void erase(int *position)
    {
        if (position + 1 != last)
            memcpy(position, position + 1, (last - (position + 1)) * 4);
        --last;
    }
};
extern "C" int fn_801190d0(void *);

extern "C" void w3d_remove_value_8008c3a8(void *self, void *object)
{
    int key = fn_801190d0(object);
    for (int *it = VEC(self, 296).begin(); it != VEC(self, 296).end(); ++it)
        if (*it == key) { VEC(self, 296).erase(it); return; }
}

extern "C" void w3d_remove_value_8008c49c(void *self, void *object)
{
    int key = fn_801190d0(object);
    for (int *it = VEC(self, 308).begin(); it != VEC(self, 308).end(); ++it)
        if (*it == key) { VEC(self, 308).erase(it); return; }
}

extern "C" void w3d_remove_value_8008c590(void *self, void *object)
{
    int key = fn_801190d0(object);
    for (int *it = VEC(self, 320).begin(); it != VEC(self, 320).end(); ++it)
        if (*it == key) { VEC(self, 320).erase(it); return; }
}

extern "C" void w3d_remove_value_8008c628(void *self, void *object)
{
    int key = fn_801190d0(object);
    for (int *it = VEC(self, 332).begin(); it != VEC(self, 332).end(); ++it)
        if (*it == key) { VEC(self, 332).erase(it); return; }
}
