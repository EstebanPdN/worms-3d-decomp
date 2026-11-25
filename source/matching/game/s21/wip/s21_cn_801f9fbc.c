// desc: Appears to validate an index for modes two and three against the element count of a pointer vector, returning minus one for other modes or out-of-range indices.
// desc: Appears to validate an index for modes two and three against the element count of a pointer vector, returning minus one for other modes or out-of-range indices.
struct S21Vector { int *begin; int *end; };
int w3d_s21_checked_index_801f9fbc(struct S21Vector *vector, int mode, int index)
{
    int position = -1;
    if (mode == 2)
        goto select;
    if (mode <= 2)
        goto low;
    if (mode == 3)
        goto select;
    goto fail;
low:
    if (mode < 0)
        goto fail;
    goto check;
select:
    position = index;
    goto check;
fail:
    return -1;
check:
    if (position < 0)
        goto fail;
    if ((unsigned)position < (unsigned)(vector->end - vector->begin))
        return position;
    goto fail;
}
