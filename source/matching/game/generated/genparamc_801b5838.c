/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Family templates, 2026-10-22 (third session), seventh batch. */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef int (*W3dMethod3)(void *, void *, int);
typedef int (*W3dMethodP)(void *, void *, void *);
typedef struct W3dBlock16 { int words[16 / 4]; } W3dBlock16;
int fn_802047e0(void *, void *, int);
void *fn_80164fc8(void *);
extern char lbl_803b29c8[];
void fn_8020c510(void *, const char *, ...);

void w3d_copy_block16_801b5838(void *self, const void *source)
{
    FIELD(self, W3dBlock16, 20) = *(const W3dBlock16 *)source;
}

void w3d_copy_block16_801c8198(void *self, const void *source)
{
    FIELD(self, W3dBlock16, 24) = *(const W3dBlock16 *)source;
}

void w3d_copy_block16_801c81e8(void *self, const void *source)
{
    FIELD(self, W3dBlock16, 20) = *(const W3dBlock16 *)source;
}

void w3d_copy_block16_801d1860(void *self, const void *source)
{
    FIELD(self, W3dBlock16, 64) = *(const W3dBlock16 *)source;
}

int w3d_forward_virtual_8020017c(void *self, void *a, void *b)
{
    return (*(W3dMethodP *)(*(char **)self + 24))(self, a, b);
}

int w3d_forward_virtual_802001a8(void *self, void *a, void *b)
{
    return (*(W3dMethodP *)(*(char **)self + 24))(self, a, b);
}

int w3d_forward_virtual_802001d4(void *self, void *a, void *b)
{
    return (*(W3dMethodP *)(*(char **)self + 24))(self, a, b);
}

int w3d_forward_virtual_80200460(void *self, void *a, void *b)
{
    return (*(W3dMethodP *)(*(char **)self + 24))(self, a, b);
}

int w3d_write_swapped_word_802040e4(void *stream, unsigned int value)
{
    unsigned int swapped = (value << 24) | ((value << 8) & 0xff0000) | ((value >> 8) & 0xff00) | (value >> 24);
    return fn_802047e0(stream, &swapped, 4);
}

int w3d_write_swapped_word_8020412c(void *stream, unsigned int value)
{
    unsigned int swapped = (value << 24) | ((value << 8) & 0xff0000) | ((value >> 8) & 0xff00) | (value >> 24);
    return fn_802047e0(stream, &swapped, 4);
}

int w3d_write_swapped_word_80204574(void *stream, unsigned int value)
{
    unsigned int swapped = (value << 24) | ((value << 8) & 0xff0000) | ((value >> 8) & 0xff00) | (value >> 24);
    return fn_802047e0(stream, &swapped, 4);
}

int w3d_forward_to_held_8025ee60(void **self, void *argument)
{
    void *held = *self;
    return (*(W3dMethod3 *)(*(char **)held + 76))(held, argument, 0);
}

int w3d_call_with_owner_8025ee94(void **self, void *target)
{
    return (*(W3dMethod3 *)(*(char **)target + 92))(target, *self, 0);
}

int w3d_forward_to_held_802af220(void **self, void *argument)
{
    void *held = *self;
    return (*(W3dMethod3 *)(*(char **)held + 76))(held, argument, 0);
}

int w3d_call_with_owner_802af254(void **self, void *target)
{
    return (*(W3dMethod3 *)(*(char **)target + 92))(target, *self, 0);
}

int w3d_forward_to_held_802bbc90(void **self, void *argument)
{
    void *held = *self;
    return (*(W3dMethod3 *)(*(char **)held + 76))(held, argument, 0);
}

int w3d_call_with_owner_802bbcc4(void **self, void *target)
{
    return (*(W3dMethod3 *)(*(char **)target + 92))(target, *self, 0);
}
