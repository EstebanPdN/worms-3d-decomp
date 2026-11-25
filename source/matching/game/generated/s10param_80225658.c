/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct S10StringObject { void *vtable; char reserved[112]; char *name; } S10StringObject;
extern int fn_8021ef08(S10StringObject *, void *);
extern void fn_8020c5c0(char **);
extern unsigned short *fn_80341884(char **);
extern char *lbl_804b06a0[];
extern char lbl_8041a2f8[];

S10StringObject *w3d_s10_string_ctor_80225658(S10StringObject *object, void * arg_r4)
{
    char **empty = lbl_804b06a0;
    char **name = &object->name;
    fn_8021ef08(object, arg_r4);
    object->vtable = lbl_8041a2f8;
    fn_8020c5c0(name);
    *name = *empty;
    ++*fn_80341884(name);
    return object;
}
