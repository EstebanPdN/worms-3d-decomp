/* Flag test helper (session 47b5d14a). */

typedef struct W3dFlagged_801fb0c0 {
    char pad[264];
    unsigned int flags;     /* +264 */
} W3dFlagged_801fb0c0;

int w3d_h1_flag_or_forced_801fb0c0(W3dFlagged_801fb0c0 *p, int forced)
{
    if (!forced) {
        if (p->flags & 0x20000000)
            return 1;
        return 0;
    }
    return 1;
}
