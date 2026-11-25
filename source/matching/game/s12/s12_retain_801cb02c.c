typedef struct S12HeldInterface S12HeldInterface;
typedef struct S12HeldMethods { void (*reserved[3])(void); void (*retain)(S12HeldInterface *); } S12HeldMethods;
struct S12HeldInterface { S12HeldMethods *methods; };
typedef struct S12RetainedMembers {
    void *vtable;
    char reserved_0004[16];
    S12HeldInterface *member_0014;
    S12HeldInterface *member_0018;
    S12HeldInterface *member_001c;
} S12RetainedMembers;
extern S12HeldInterface *lbl_804b05a8;
extern char lbl_80416258[];
extern void * fn_801ea0ec(S12RetainedMembers *, int);
S12RetainedMembers *w3d_s12_initialize_interfaces_801cb02c(S12RetainedMembers *object, void * arg_r4)
{
    S12HeldInterface *initial;
    fn_801ea0ec(object, arg_r4);
    initial = lbl_804b05a8;
    object->vtable = lbl_80416258;
    object->member_0014 = initial;
    if (initial) initial->methods->retain(initial);
    initial = lbl_804b05a8;
    object->member_0018 = initial;
    if (initial) initial->methods->retain(initial);
    initial = lbl_804b05a8;
    object->member_001c = initial;
    if (initial) initial->methods->retain(initial);
    return object;
}
