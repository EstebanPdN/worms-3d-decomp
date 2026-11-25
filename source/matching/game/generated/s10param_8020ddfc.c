/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct S10Registry { char reserved[34]; unsigned short count; } S10Registry;
extern S10Registry lbl_80463360;
extern void fn_8020df08(void *);
extern void fn_8020fd2c(S10Registry *, void *);

void w3d_s10_registry_remove_8020ddfc(void *object)
{
    fn_8020df08(object);
    fn_8020fd2c(&lbl_80463360, (char *)object + 4);
    --lbl_80463360.count;
}
