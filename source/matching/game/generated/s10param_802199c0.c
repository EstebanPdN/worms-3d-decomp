/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct S10Interface S10Interface;
typedef void (*S10InterfaceMethod)(S10Interface *);
struct S10Interface { S10InterfaceMethod *vtable; };
typedef struct S10InterfaceOwner { char reserved[20]; S10Interface *value; } S10InterfaceOwner;

void w3d_s10_assign_interface_802199c0(S10InterfaceOwner *object, S10Interface *value)
{
    if (value)
        value->vtable[3](value);
    if (object->value)
        object->value->vtable[4](object->value);
    object->value = value;
}
