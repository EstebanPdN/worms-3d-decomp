struct Sample { int delta; float value; };
struct History { Sample *samples; int count; int delta_sum; float value_sum; int index; int previous; };
extern "C" void r27b_history_8015d018(History *h, int current, float value) {
    if (!h->samples) return;
    int previous = h->previous;
    int delta = current - previous;
    if (previous == -1) delta = 0;
    Sample *sample = (Sample *)((char *)h->samples + (h->index << 3));
    h->value_sum = h->value_sum - sample->value + value;
    h->delta_sum = h->delta_sum - *(int *)((char *)h->samples + (h->index << 3)) + delta;
    sample->value = value;
    h->samples[h->index].delta = delta;
    if (++h->index >= h->count) h->index = 0;
    h->previous = current;
}
