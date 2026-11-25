// (Worms 3D GameCube PAL, 0x801e39bc).
//
// Builds the peak overview of a 16-bit sound buffer: copies the samples,
// smooths them with a running average over rate/smooth samples, reduces them
// to count = samples/rate*pointRate points by taking the absolute peak of
// each block, applies a one-pole smear (gain 0.2, decay 0.8), normalises to
// the highest peak and stores each point as a byte 0..255. Returns E_FAIL
// without data. Field names are inferred from the arithmetic.

extern "C" void *w3d_heap_allocate_entry_b(unsigned);
extern "C" void w3d_task_array_release(void *);
extern "C" void *memcpy(void *, const void *, unsigned);
struct Wave {
    short *data; unsigned bytes; unsigned rate; unsigned smooth; unsigned pointRate;
    unsigned char *points; unsigned count;
};
extern "C" int w3d_d27e_wave_peaks_801e39bc(Wave *w) {
    w->points = 0;
    w->count = 0;
    if (!w->data) return 0x80004005;
    int n = w->bytes / 2;
    short *in = (short *)w3d_heap_allocate_entry_b(n * 2);
    short *smoothed = (short *)w3d_heap_allocate_entry_b(n * 2);
    float *peaks = (float *)w3d_heap_allocate_entry_b(n * 4);
    memcpy(in, w->data, w->bytes);
    int window = w->rate / w->smooth;
    int i, k;
    for (i = 0; i < n; ++i) {
        float sum = 0.0f;
        for (k = 0; k < window; ++k) { if (i - k >= 0) sum += (float)in[i - k]; }
        smoothed[i] = (short)(sum / (float)window);
    }
    unsigned count = (unsigned)((float)n / (float)w->rate * (float)w->pointRate);
    w->points = (unsigned char *)w3d_heap_allocate_entry_b(count);
    w->count = count;
    int per = (unsigned)n / count;
    float top = 0.0f;
    i = 0;
    if (i < (int)count) {
        float zero = top;
        do {
            float peak = zero;
            float v = peak;
            for (k = 0; k < per; ++k) {
                if (i * per + k < n) v = __builtin_fabsf((float)smoothed[i * per + k]);
                if (v > peak) peak = v;
            }
            peaks[i] = peak;
            if (peak > top) top = peak;
            ++i;
        } while (i < (int)count);
    }
    float tail = 0.0f;
    float gain = 0.2f;
    float decay = 0.8f;
    for (i = 0; i < (int)count; ++i) {
        float v = peaks[i] * gain + tail;
        peaks[i] = v;
        tail = v * decay;
    }
    if (top != 0.0f) {
        for (i = 0; i < (int)count; ++i) peaks[i] /= top;
    }
    for (i = 0; i < (int)count; ++i) w->points[i] = (unsigned char)(peaks[i] * 255.0f);
    if (in) w3d_task_array_release(in);
    if (smoothed) w3d_task_array_release(smoothed);
    if (peaks) w3d_task_array_release(peaks);
    return 0;
}
