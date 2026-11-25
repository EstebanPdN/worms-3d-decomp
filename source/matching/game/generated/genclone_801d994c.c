/* Byte-identical copies of hand-matched leaf functions, written by
 * tools/gen_clone_units.py and verified identical to the original after
 * linking. Names are structural (address); the owning classes are unknown. */

struct w3d_flag_owner { char head[36]; unsigned int flags; };
int w3d_flag_set_801d994c(struct w3d_flag_owner *owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_801d9984(struct w3d_flag_owner *owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_801e8390(struct w3d_flag_owner *owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_801e83c8(struct w3d_flag_owner *owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}
