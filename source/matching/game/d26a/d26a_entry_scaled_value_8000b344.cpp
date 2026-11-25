// GWMP8P rev0 0x8000b344. Scaled value of a table entry, clamped to the
// entry limit and optionally pushed towards it by rate and t. Names are
// inferred from the original instructions.
struct Entry {
    char unknown00[12];
    float scale;       /* +12 */
    char unknown10[12];
    int limit;         /* +28 */
    float rate;        /* +32 */
};
struct Table {
    Entry **items;
    Entry *&operator[](int i) { return items[i]; }
};
struct Settings {
    char unknown00[84];
    float minimum;     /* +84 */
    char unknown58[8];
    float factor;      /* +96 */
};
struct Self {
    char unknown00[64];
    unsigned char locked;   /* +64 */
};
extern Table *w3d_table_804aa750;
extern Settings *w3d_settings_804aa6d8;

extern "C" float w3d_d26a_entry_scaled_value_8000b344(Self *self, int index, float t, float v)
{
    Entry *e = (*w3d_table_804aa750)[index];
    Settings *s = w3d_settings_804aa6d8;
    float m = s->factor;
    float base = m;
    float limit = (float)e->limit;
    int clamped = 0;
    if (v >= limit) {
        float lowest = s->minimum;
        v = limit;
        clamped = 1;
        if (v < lowest) v = lowest;
    }
    if (t != 0.0f && !clamped && !self->locked) {
        float r = e->rate;
        m = 1.0f;
        float k = r * t + m;
        v = (limit - v) * r * t + v;
        m = base * k;
        if (v > limit) v = limit;
    }
    m *= v;
    return m * e->scale;
}
