struct Ring { char *base; unsigned cursor; unsigned capacity; unsigned boundary; };
extern "C" void *t263_ring_allocate_801613f0(Ring *ring, unsigned size) {
    unsigned total = ((size + 3) & ~3u) + 4;
    if (total > ring->capacity - ring->cursor) ring->cursor = 0;
    unsigned *entry = (unsigned *)(ring->base + ring->cursor);
    ring->cursor += total;
    *entry = total;
    return entry + 1;
}
