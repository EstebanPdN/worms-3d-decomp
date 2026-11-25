// Observed fields only. Integer total/cursor/time words are signed in comparisons;
// the value total and sample value are single precision, contrary to the raw decompiler casts.
struct cc44a_Sample { int elapsed; float value; };
struct cc44a_SampleRing {
    cc44a_Sample *samples;
    int capacity;
    int elapsedTotal;
    float valueTotal;
    int cursor;
    int lastTime;
};
extern "C" void cc44a_sample_ring_8015d018(cc44a_SampleRing *self, int time, float value) {
    if (!self->samples) return;
    int elapsed = time - self->lastTime;
    switch (self->lastTime) { case -1: elapsed = 0; break; }
    cc44a_Sample *sample = self->cursor + self->samples;
    self->valueTotal = (self->valueTotal - sample->value) + value;
    self->elapsedTotal = (self->elapsedTotal - sample->elapsed) + elapsed;
    sample->value = value;
    self->samples[self->cursor].elapsed = elapsed;
    if (++self->cursor >= self->capacity) self->cursor = 0;
    self->lastTime = time;
}
