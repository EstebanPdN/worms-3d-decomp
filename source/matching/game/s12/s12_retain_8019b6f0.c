typedef struct S12HeldInterface S12HeldInterface;
typedef struct S12HeldMethods { void (*reserved[3])(void); void (*retain)(S12HeldInterface *); } S12HeldMethods;
struct S12HeldInterface { S12HeldMethods *methods; };
typedef struct S12RetainedMembers {
    void *vtable;
    char reserved_0004[16];
    S12HeldInterface *member_0014;
    S12HeldInterface *member_0018;
    S12HeldInterface *member_001c;
    S12HeldInterface *member_0020;
} S12RetainedMembers;
extern S12HeldInterface *lbl_804b05a8;
extern S12HeldInterface *lbl_804b05b0;
extern char lbl_80413530[];
extern void * fn_801ea0ec(S12RetainedMembers *, int);
S12RetainedMembers *w3d_s12_initialize_interfaces_8019b6f0(S12RetainedMembers *object, void * arg_r4)
{
    S12HeldInterface *initial;
    fn_801ea0ec(object, arg_r4);
    initial = lbl_804b05b0;
    object->vtable = lbl_80413530;
    object->member_0014 = initial;
    if (initial) initial->methods->retain(initial);
    initial = lbl_804b05a8;
    object->member_0018 = initial;
    if (initial) initial->methods->retain(initial);
    initial = lbl_804b05a8;
    object->member_001c = initial;
    if (initial) initial->methods->retain(initial);
    initial = lbl_804b05a8;
    object->member_0020 = initial;
    if (initial) initial->methods->retain(initial);
    return object;
}
