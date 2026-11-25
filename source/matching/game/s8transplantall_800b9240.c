/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct S10Interface S10Interface;
typedef void (*S10InterfaceMethod)(S10Interface *);
struct S10Interface { S10InterfaceMethod *vtable; };
typedef struct S10InterfaceOwner { char reserved[8]; S10Interface *value; } S10InterfaceOwner;





void s8_transplant_800b9240(S10InterfaceOwner *object, S10Interface *value)
{
    if (value)
        value->vtable[3](value);
    if (object->value)
        object->value->vtable[4](object->value);
    object->value = value;
}
