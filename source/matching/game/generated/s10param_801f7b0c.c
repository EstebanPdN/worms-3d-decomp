/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct S10Registry { char reserved[34]; unsigned short count; } S10Registry;
extern S10Registry lbl_8045e7b8;
extern void fn_801f7c18(void *);
extern void fn_8020fd2c(S10Registry *, void *);

void w3d_s10_registry_remove_801f7b0c(void *object)
{
    fn_801f7c18(object);
    fn_8020fd2c(&lbl_8045e7b8, (char *)object + 4);
    --lbl_8045e7b8.count;
}
