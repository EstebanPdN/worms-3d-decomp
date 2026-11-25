// d20b: 0x8007df5c (432 bytes). Upload a 256-colour palette: lock the
// source's RGB byte array (+48; a resident array only counts the lock),
// convert every entry to RGBA4444 (top nibble of each channel, opaque alpha)
// into the target's palette (+372), then derive two colour vectors from the
// first and last entries: the first entry compressed towards mid grey (75%
// contrast) sets the ambient value (+2784), and the last entry minus that
// colour sets the range value (+2788). Returns 0.
// The conversion loop advances the source pointer by two bytes and indexes
// it with the entry number (three bytes per entry), as the original
// address arithmetic shows. Built with -mfast-cast (byte to float
// conversions through psq_l) and -mps-float: without -mps-float the build
// differs only by the 8-byte frame gap below the saved FPR. The float
// literals form this function's constant pool at 0x8037ce98.
struct d20b_Vec3 { float x, y, z; };
struct d20b_ArrayHeader {
    unsigned char unknown00[4];
    unsigned short kind;                 // +4
    unsigned char unknown06[18];
    int count;                           // +24
    unsigned short locks;                // +28
    unsigned char unknown30[2];
    unsigned char data[1];               // +32
};
struct d20b_ArrayRef { d20b_ArrayHeader *header; };
struct d20b_Source { unsigned char unknown00[48]; d20b_ArrayRef palette; };
struct d20b_Target {
    unsigned char unknown0000[372];
    unsigned short *palette;             // +372
    unsigned char unknown0376[2408];
    void *ambient;                       // +2784
    void *range;                         // +2788
};
extern "C" void *d20b_array_reserve_801ef048(d20b_ArrayRef *, int, int, int);
extern "C" void *d20b_as_value_80342fa4(void *);
extern "C" int d20b_set_vector_80178fa4(void *, const d20b_Vec3 *);

static inline unsigned char *d20b_lock(d20b_ArrayRef *array) {
    d20b_ArrayHeader *header = array->header;
    int count = header->count;
    if (header->kind == 1) {
        ++header->locks;
        return header->data;
    }
    return (unsigned char *)d20b_array_reserve_801ef048(array, count, 1, 2);
}

extern "C" int d20b_palette_upload_8007df5c(d20b_Target *self, d20b_Source *source) {
    unsigned char *rgb = d20b_lock(&source->palette);
    int i;
    const unsigned char *p;
    for (i = 0, p = rgb; i < 256; p += 2, i++) {
        const unsigned char *c = p + i;
        self->palette[i] = ((c[0] & 0xf0) << 8) | ((c[1] & 0xf0) << 4) | (c[2] & 0xf0) | 0x0f;
    }
    float contrast = 0.75f;
    d20b_Vec3 v;
    v.x = (float)rgb[0] / 255.0f * contrast + (1.0f - contrast) * 0.5f;
    v.y = (float)rgb[1] / 255.0f * contrast + (1.0f - contrast) * 0.5f;
    v.z = (float)rgb[2] / 255.0f * contrast + (1.0f - contrast) * 0.5f;
    d20b_set_vector_80178fa4(d20b_as_value_80342fa4(self->ambient), &v);
    v.x = (float)rgb[765] / 255.0f - v.x;
    v.y = (float)rgb[766] / 255.0f - v.y;
    v.z = (float)rgb[767] / 255.0f - v.z;
    d20b_set_vector_80178fa4(d20b_as_value_80342fa4(self->range), &v);
    return 0;
}
