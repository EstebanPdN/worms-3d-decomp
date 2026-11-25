struct K1dArena { char *base; unsigned cursor; unsigned limit; unsigned mark; };
void *w3d_k1d_arena_alloc_801613f0(struct K1dArena *a, unsigned size)
{
    unsigned n = ((size + 3) & ~3u) + 4;
    unsigned off;
    char *p;
    if (n > a->limit - a->cursor) a->cursor = 0;
    off = a->cursor;
    p = a->base + off;
    if (off < a->mark) { }
    a->cursor = off + n;
    *(unsigned *)p = n;
    return p + 4;
}
// k1d: w3d_k1d_arena_alloc_801613f0|0x801613f0|Appears to allocate a size-prefixed block from a ring buffer and wrap the cursor when it does not fit.
