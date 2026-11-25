typedef struct S12HeldInterface S12HeldInterface;
typedef struct S12HeldMethods { void (*reserved[3])(void); void (*retain)(S12HeldInterface *); } S12HeldMethods;
struct S12HeldInterface { S12HeldMethods *methods; };
typedef struct S12RetainedMembers {
    void *vtable;
    char reserved_0004[40];
    S12HeldInterface *member_002c;
    S12HeldInterface *member_0030;
    S12HeldInterface *member_0034;
    S12HeldInterface *member_0038;
    S12HeldInterface *member_003c;
} S12RetainedMembers;
extern S12HeldInterface *lbl_804b05a8;
extern S12HeldInterface *lbl_804b05b0;
extern char lbl_80415028[];
extern int fn_801b4bcc(S12RetainedMembers *, void *);
S12RetainedMembers *w3d_s12_initialize_interfaces_801bea98(S12RetainedMembers *object, void * arg_r4)
{
    S12HeldInterface *initial;
    fn_801b4bcc(object, arg_r4);
    initial = lbl_804b05a8;
    object->vtable = lbl_80415028;
    object->member_002c = initial;
    if (initial) initial->methods->retain(initial);
    initial = lbl_804b05a8;
    object->member_0030 = initial;
    if (initial) initial->methods->retain(initial);
    initial = lbl_804b05a8;
    object->member_0034 = initial;
    if (initial) initial->methods->retain(initial);
    initial = lbl_804b05b0;
    object->member_0038 = initial;
    if (initial) initial->methods->retain(initial);
    initial = lbl_804b05a8;
    object->member_003c = initial;
    if (initial) initial->methods->retain(initial);
    return object;
}
