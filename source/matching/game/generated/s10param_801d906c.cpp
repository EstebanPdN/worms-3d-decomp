/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

struct S10Pixel { unsigned int value; void read(const void *); };
typedef void (S10Pixel::*S10PixelMethod)(const void *);
extern const S10PixelMethod lbl_803af6ec[];
extern const S10PixelMethod lbl_803af6e4[];
extern const S10PixelMethod lbl_803af6fc[];
extern const S10PixelMethod lbl_803af6f4[];
extern const S10PixelMethod lbl_803af704[];
extern const S10PixelMethod lbl_803af70c[];

extern "C" int w3d_s10_convert_pixels_801d906c(void *source, int unused1, unsigned int sourceStride, unsigned int columns, unsigned int rows, void *destination, int unused6, unsigned int destinationStride)
{
    S10PixelMethod input = lbl_803af6e4[0];
    S10PixelMethod output = lbl_803af6ec[0];
    S10Pixel pixel;
    unsigned int y = 0;
    for (; y < rows; ++y) {
        unsigned int x = 0;
        if (x < columns) {
            char *src = (char *)source + y * sourceStride;
            char *dst = (char *)destination + y * destinationStride;
            do {
                (pixel.*input)(src);
                src += 4;
                (pixel.*output)(dst);
                dst += 3;
                ++x;
            } while (x < columns);
        }
    }
    return 0;
}

extern "C" int w3d_s10_convert_pixels_801d9150(void *source, int unused1, unsigned int sourceStride, unsigned int columns, unsigned int rows, void *destination, int unused6, unsigned int destinationStride)
{
    S10PixelMethod input = lbl_803af6f4[0];
    S10PixelMethod output = lbl_803af6fc[0];
    S10Pixel pixel;
    unsigned int y = 0;
    for (; y < rows; ++y) {
        unsigned int x = 0;
        if (x < columns) {
            char *src = (char *)source + y * sourceStride;
            char *dst = (char *)destination + y * destinationStride;
            do {
                (pixel.*input)(src);
                src += 3;
                (pixel.*output)(dst);
                dst += 4;
                ++x;
            } while (x < columns);
        }
    }
    return 0;
}

extern "C" int w3d_s10_convert_pixels_801d9234(void *source, int unused1, unsigned int sourceStride, unsigned int columns, unsigned int rows, void *destination, int unused6, unsigned int destinationStride)
{
    S10PixelMethod input = lbl_803af6e4[0];
    S10PixelMethod output = lbl_803af704[0];
    S10Pixel pixel;
    unsigned int y = 0;
    for (; y < rows; ++y) {
        unsigned int x = 0;
        if (x < columns) {
            char *src = (char *)source + y * sourceStride;
            char *dst = (char *)destination + y * destinationStride;
            do {
                (pixel.*input)(src);
                src += 4;
                (pixel.*output)(dst);
                dst += 2;
                ++x;
            } while (x < columns);
        }
    }
    return 0;
}

extern "C" int w3d_s10_convert_pixels_801d9318(void *source, int unused1, unsigned int sourceStride, unsigned int columns, unsigned int rows, void *destination, int unused6, unsigned int destinationStride)
{
    S10PixelMethod input = lbl_803af70c[0];
    S10PixelMethod output = lbl_803af6fc[0];
    S10Pixel pixel;
    unsigned int y = 0;
    for (; y < rows; ++y) {
        unsigned int x = 0;
        if (x < columns) {
            char *src = (char *)source + y * sourceStride;
            char *dst = (char *)destination + y * destinationStride;
            do {
                (pixel.*input)(src);
                src += 2;
                (pixel.*output)(dst);
                dst += 4;
                ++x;
            } while (x < columns);
        }
    }
    return 0;
}

extern "C" int w3d_s10_convert_pixels_801d93fc(void *source, int unused1, unsigned int sourceStride, unsigned int columns, unsigned int rows, void *destination, int unused6, unsigned int destinationStride)
{
    S10PixelMethod input = lbl_803af6f4[0];
    S10PixelMethod output = lbl_803af704[0];
    S10Pixel pixel;
    unsigned int y = 0;
    for (; y < rows; ++y) {
        unsigned int x = 0;
        if (x < columns) {
            char *src = (char *)source + y * sourceStride;
            char *dst = (char *)destination + y * destinationStride;
            do {
                (pixel.*input)(src);
                src += 3;
                (pixel.*output)(dst);
                dst += 2;
                ++x;
            } while (x < columns);
        }
    }
    return 0;
}

extern "C" int w3d_s10_convert_pixels_801d94e0(void *source, int unused1, unsigned int sourceStride, unsigned int columns, unsigned int rows, void *destination, int unused6, unsigned int destinationStride)
{
    S10PixelMethod input = lbl_803af70c[0];
    S10PixelMethod output = lbl_803af6ec[0];
    S10Pixel pixel;
    unsigned int y = 0;
    for (; y < rows; ++y) {
        unsigned int x = 0;
        if (x < columns) {
            char *src = (char *)source + y * sourceStride;
            char *dst = (char *)destination + y * destinationStride;
            do {
                (pixel.*input)(src);
                src += 2;
                (pixel.*output)(dst);
                dst += 3;
                ++x;
            } while (x < columns);
        }
    }
    return 0;
}
