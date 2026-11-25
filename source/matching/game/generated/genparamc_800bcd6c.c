/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Pair templates (later batch): destructor with a member array of
 * interface references, and a masked walk over a global vector. */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct W3dPtrVector { void **first; void **last; void **end_of_storage; } W3dPtrVector;
extern W3dPtrVector lbl_8043bb64;
void fn_800b5f2c(void *, void *);
int fn_800b5fc0(void *, void *);

void w3d_collect_selected_800bcd6c(void *self)
{
    unsigned int bit = 1;
    void **it = lbl_8043bb64.first;
    void **end = lbl_8043bb64.last;
    char *out = (char *)self + 256;
    if (it != end) {
        unsigned int *mask = (unsigned int *)((char *)self + 128);
        do {
            if (*mask & bit) {
                fn_800b5f2c(*it, out);
                out += 12;
            }
            bit <<= 1;
            if (bit == 0) {
                bit = 1;
                mask++;
            }
            it++;
        } while (it != end);
    }
}

void w3d_collect_selected_800bd8a0(void *self)
{
    unsigned int bit = 1;
    void **it = lbl_8043bb64.first;
    void **end = lbl_8043bb64.last;
    char *out = (char *)self + 256;
    if (it != end) {
        unsigned int *mask = (unsigned int *)((char *)self + 128);
        do {
            if (*mask & bit) {
                fn_800b5fc0(*it, out);
                out += 12;
            }
            bit <<= 1;
            if (bit == 0) {
                bit = 1;
                mask++;
            }
            it++;
        } while (it != end);
    }
}
