/* Mode-slot release (session b169b320, from the Codex cx9c near-miss
 * layout): resets the mode in slot index, then re-applies it with each of
 * the two shared arguments whose per-slot enable flag is set. The array
 * element in the loop is addressed as offset + base, the operand order of
 * the original indexed load. */

struct W3dMode;
struct W3dModeFlags
{
    unsigned int enabled[2];
};
struct W3dModeSlots
{
    W3dMode *modes[3];             /* 0x00 */
    W3dModeFlags flags[3];         /* 0x0c */
    void *arguments[2];            /* 0x24 */
};
extern "C" int w3d_mode_reset_8020ad18(W3dMode *mode);
extern "C" int w3d_mode_apply_8020abe0(W3dMode *mode, void *argument);

extern "C" void w3d_mode_slots_release_8035a32c(W3dModeSlots *self, unsigned int index)
{
    w3d_mode_reset_8020ad18(self->modes[index]);
    for (unsigned int i = 0; i < 2; i++)
        if (self->flags[index].enabled[i])
            w3d_mode_apply_8020abe0(*(W3dMode **)((index << 2) + (unsigned int)self->modes), self->arguments[i]);
}
