/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct S10TreeValue { char reserved[16]; int second, first; } S10TreeValue;
typedef struct S10TreeRoot { char reserved[8]; S10TreeValue *first; } S10TreeRoot;
typedef struct S10TreeContainer { char reserved[24]; S10TreeRoot *root; } S10TreeContainer;
extern S10TreeValue *fn_80351ef8(S10TreeValue *);

int w3d_s10_read_tree_value_801d2188(const S10TreeContainer *object, unsigned int index, int *first, int *second)
{
    S10TreeValue *volatile cursor = object->root->first;
    while (index--)
        cursor = fn_80351ef8(cursor);
    {
        S10TreeValue *current = cursor;
        *first = current->first;
        *second = current->second;
    }
    return 0;
}
