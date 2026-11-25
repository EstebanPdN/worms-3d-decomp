typedef struct { int time; float value; } Entry;
typedef struct { Entry *entries; int count; int total; float sum; int index; int previous; } Ring;
void tterra_b26_ring_8015d018(Ring *p, int now, float value) {
    if (p->entries) {
        int previous = p->previous;
        int elapsed = now - previous;
        if (previous == -1) elapsed = 0;
        p->sum = (p->sum - p->entries[p->index].value) + value;
        p->total = (p->total - p->entries[p->index].time) + elapsed;
        p->entries[p->index].value = value;
        p->entries[p->index].time = elapsed;
        if (++p->index >= p->count) p->index = 0;
        p->previous = now;
    }
}
