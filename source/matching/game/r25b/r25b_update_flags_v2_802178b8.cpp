// Inferred guarded flag update. Observed pointer at +0x30, word at pointee +0.
// Bit 0x2000 guards updates; bits 0x202 clear bit 0. Return is pre-update word.
struct R25bFlagOwner {
    unsigned char reserved[0x30];
    unsigned *flags;
};
extern "C" unsigned w3d_r25b_update_flags_v2_802178b8(
    R25bFlagOwner *owner, unsigned mask, int set)
{
    unsigned *flags = owner->flags;
    if (!mask && !set)
        return *flags;
    unsigned old = *flags;
    if ((old & 1) == 0) {
        if (old & 0x2000)
            return 0;
        *flags = old | 0x2000;
    }
    unsigned before = *flags;
    if (set)
        *flags = before | (mask & 31);
    else
        *flags = before & ~(mask & 31);
    if (*flags & 0x202)
        *flags = *flags & ~1u;
    *flags = *flags & ~0x2000u;
    return before;
}
