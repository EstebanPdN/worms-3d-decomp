struct T265Position { unsigned unknown[7]; unsigned position; unsigned length; };
extern "C" unsigned t265_seek_80208e34(T265Position *self, unsigned offset, int origin, unsigned *old_position)
{
    unsigned limit;
    if (old_position) *old_position = self->position;
    switch (origin) {
    case 0: limit = self->length; break;
    case 2: offset = self->length + offset; limit = self->length; break;
    case 1: offset += self->position; limit = self->length; break;
    default: return 0x90000002;
    }
    if (offset > limit) return 0x90000003;
    self->position = offset;
    return 0;
}
