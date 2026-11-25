/* Byte-identical copies of hand-matched leaf functions, written by
 * tools/gen_clone_units.py and verified identical to the original after
 * linking. Names are structural (address); the owning classes are unknown. */

struct w3d_flag_owner { char head[36]; unsigned int flags; };
int w3d_flag_set_801665cc(struct w3d_flag_owner *owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_80166604(struct w3d_flag_owner *owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_80169ae8(struct w3d_flag_owner *owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_80169b20(struct w3d_flag_owner *owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_8019c23c(struct w3d_flag_owner *owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_8019c274(struct w3d_flag_owner *owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_8019cad4(struct w3d_flag_owner *owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_8019cb0c(struct w3d_flag_owner *owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_801a520c(struct w3d_flag_owner *owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_801a5244(struct w3d_flag_owner *owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_801a6098(struct w3d_flag_owner *owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_801a60d0(struct w3d_flag_owner *owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_801a714c(struct w3d_flag_owner *owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_801a7184(struct w3d_flag_owner *owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_801a8070(struct w3d_flag_owner *owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_801a80a8(struct w3d_flag_owner *owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_801ab140(struct w3d_flag_owner *owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_801ab178(struct w3d_flag_owner *owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_801ac074(struct w3d_flag_owner *owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_801ac0ac(struct w3d_flag_owner *owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_801ac674(struct w3d_flag_owner *owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_801ac6ac(struct w3d_flag_owner *owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_801ae2b0(struct w3d_flag_owner *owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_801ae2e8(struct w3d_flag_owner *owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_801b0c10(struct w3d_flag_owner *owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_801b0c48(struct w3d_flag_owner *owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_801b1694(struct w3d_flag_owner *owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_801b16cc(struct w3d_flag_owner *owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_801b2174(struct w3d_flag_owner *owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_801b21ac(struct w3d_flag_owner *owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_801d3028(struct w3d_flag_owner *owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_801d3060(struct w3d_flag_owner *owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_801d4124(struct w3d_flag_owner *owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_801d415c(struct w3d_flag_owner *owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_801d4f30(struct w3d_flag_owner *owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_801d4f68(struct w3d_flag_owner *owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_801d5324(struct w3d_flag_owner *owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_801d535c(struct w3d_flag_owner *owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_801d5c98(struct w3d_flag_owner *owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_801d5cd0(struct w3d_flag_owner *owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}
