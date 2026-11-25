/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct S10PointerRange { char reserved[52]; void **begin; void **end; } S10PointerRange;

void **w3d_s10_range_data_801fc3b0(const S10PointerRange *object, int *count)
{
    *count = object->end - object->begin;
    if (*count == 0)
        return 0;
    return object->begin;
}
