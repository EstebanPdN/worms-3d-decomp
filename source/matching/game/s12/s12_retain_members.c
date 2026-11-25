/* Observed constructor: install a table and retain five initial interfaces. */
typedef struct S12HeldInterface S12HeldInterface;
typedef struct S12HeldMethods {
    void (*reserved[3])(void);
    void (*retain)(S12HeldInterface *);
} S12HeldMethods;
struct S12HeldInterface { S12HeldMethods *methods; };
typedef struct S12FiveMemberObject { void *vtable; char baseState[60]; S12HeldInterface *members[5]; } S12FiveMemberObject;
extern S12HeldInterface *lbl_804b05a8;
extern char lbl_80415aa0[];
extern int fn_801b5b30(S12FiveMemberObject *, void *);
S12FiveMemberObject *w3d_s12_retain_members_801b5d68(S12FiveMemberObject *object, void * arg_r4)
{
    S12HeldInterface *initial;
    fn_801b5b30(object, arg_r4);
    initial = lbl_804b05a8;
    object->vtable = lbl_80415aa0;
    object->members[0] = initial;
    if (initial) initial->methods->retain(initial);
    initial = lbl_804b05a8;
    object->members[1] = initial;
    if (initial) initial->methods->retain(initial);
    initial = lbl_804b05a8;
    object->members[2] = initial;
    if (initial) initial->methods->retain(initial);
    initial = lbl_804b05a8;
    object->members[3] = initial;
    if (initial) initial->methods->retain(initial);
    initial = lbl_804b05a8;
    object->members[4] = initial;
    if (initial) initial->methods->retain(initial);
    return object;
}
