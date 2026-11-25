typedef struct S12HeldInterface S12HeldInterface;
typedef struct S12HeldMethods { void (*reserved[3])(void); void (*retain)(S12HeldInterface *); } S12HeldMethods;
struct S12HeldInterface { S12HeldMethods *methods; };
typedef struct S12RetainedMembers {
    void *vtable;
    char reserved_0004[24];
    S12HeldInterface *member_001c;
    S12HeldInterface *member_0020;
    S12HeldInterface *member_0024;
    S12HeldInterface *member_0028;
} S12RetainedMembers;
extern S12HeldInterface *lbl_804b05a8;
extern S12HeldInterface *lbl_804b05ac;
extern char lbl_80416280[];
extern int fn_801c90c0(S12RetainedMembers *, void *);
S12RetainedMembers *w3d_s12_initialize_interfaces_801cab48(S12RetainedMembers *object, void * arg_r4)
{
    S12HeldInterface *initial;
    fn_801c90c0(object, arg_r4);
    initial = lbl_804b05ac;
    object->vtable = lbl_80416280;
    object->member_001c = initial;
    if (initial) initial->methods->retain(initial);
    initial = lbl_804b05ac;
    object->member_0020 = initial;
    if (initial) initial->methods->retain(initial);
    initial = lbl_804b05a8;
    object->member_0024 = initial;
    if (initial) initial->methods->retain(initial);
    initial = lbl_804b05a8;
    object->member_0028 = initial;
    if (initial) initial->methods->retain(initial);
    return object;
}
