// desc: Appears to seek a memory stream: it reports the old position, computes the target from the start, the current position or the end according to the mode and fails with 0x90000002 or 0x90000003 for a bad mode or an out-of-range target.
struct S21Stream { char pad[28]; unsigned position; unsigned size; };
int w3d_s21_seek_80208e34(struct S21Stream *self, unsigned offset, int mode, unsigned *old_position)
{
    unsigned limit;
    if (old_position)
        *old_position = self->position;
    switch (mode) {
    case 0:
        limit = self->size;
        break;
    case 2: {
        unsigned end = self->size;
        offset = end + offset;
        limit = end;
        break;
    }
    case 1: {
        unsigned position = self->position;
        limit = self->size;
        offset += position;
        break;
    }
    default:
        return 0x90000002;
    }
    if (offset > limit)
        return 0x90000003;
    self->position = offset;
    return 0;
}
