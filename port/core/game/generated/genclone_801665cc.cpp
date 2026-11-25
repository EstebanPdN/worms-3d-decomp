#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genclone_801665cc.c"
/* Byte-identical copies of hand-matched leaf functions, written by
 * tools/gen_clone_units.py and verified identical to the original after
 * linking. Names are structural (address); the owning classes are unknown. */

struct w3d_flag_owner { char head[36]; unsigned int flags; };
int w3d_flag_set_801665cc(Ptr32<struct w3d_flag_owner> owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_80166604(Ptr32<struct w3d_flag_owner> owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_80169ae8(Ptr32<struct w3d_flag_owner> owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_80169b20(Ptr32<struct w3d_flag_owner> owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_8019c23c(Ptr32<struct w3d_flag_owner> owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_8019c274(Ptr32<struct w3d_flag_owner> owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_8019cad4(Ptr32<struct w3d_flag_owner> owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_8019cb0c(Ptr32<struct w3d_flag_owner> owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_801a520c(Ptr32<struct w3d_flag_owner> owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_801a5244(Ptr32<struct w3d_flag_owner> owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_801a6098(Ptr32<struct w3d_flag_owner> owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_801a60d0(Ptr32<struct w3d_flag_owner> owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_801a714c(Ptr32<struct w3d_flag_owner> owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_801a7184(Ptr32<struct w3d_flag_owner> owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_801a8070(Ptr32<struct w3d_flag_owner> owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_801a80a8(Ptr32<struct w3d_flag_owner> owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_801ab140(Ptr32<struct w3d_flag_owner> owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_801ab178(Ptr32<struct w3d_flag_owner> owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_801ac074(Ptr32<struct w3d_flag_owner> owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_801ac0ac(Ptr32<struct w3d_flag_owner> owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_801ac674(Ptr32<struct w3d_flag_owner> owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_801ac6ac(Ptr32<struct w3d_flag_owner> owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_801ae2b0(Ptr32<struct w3d_flag_owner> owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_801ae2e8(Ptr32<struct w3d_flag_owner> owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_801b0c10(Ptr32<struct w3d_flag_owner> owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_801b0c48(Ptr32<struct w3d_flag_owner> owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_801b1694(Ptr32<struct w3d_flag_owner> owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_801b16cc(Ptr32<struct w3d_flag_owner> owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_801b2174(Ptr32<struct w3d_flag_owner> owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_801b21ac(Ptr32<struct w3d_flag_owner> owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_801d3028(Ptr32<struct w3d_flag_owner> owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_801d3060(Ptr32<struct w3d_flag_owner> owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_801d4124(Ptr32<struct w3d_flag_owner> owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_801d415c(Ptr32<struct w3d_flag_owner> owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_801d4f30(Ptr32<struct w3d_flag_owner> owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_801d4f68(Ptr32<struct w3d_flag_owner> owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_801d5324(Ptr32<struct w3d_flag_owner> owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_801d535c(Ptr32<struct w3d_flag_owner> owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

int w3d_flag_set_801d5c98(Ptr32<struct w3d_flag_owner> owner, int bit, int on)
{
    if (on)
        owner->flags |= 1 << bit;
    else
        owner->flags &= ~(1 << bit);
    return 0;
}

int w3d_flag_test_801d5cd0(Ptr32<struct w3d_flag_owner> owner, int bit)
{
    return (owner->flags & (1 << bit)) != 0;
}

}
