#include "w3d_ptr.h"
#line 1 "s10param_801d906c.cpp"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

struct S10Pixel { unsigned int value; void read(Ptr32<const void>); };
typedef w3d::Pmf<S10Pixel, void(Ptr32<const void>)> S10PixelMethod;
extern const S10PixelMethod lbl_803af6ec[];
extern const S10PixelMethod lbl_803af6e4[];
extern const S10PixelMethod lbl_803af6fc[];
extern const S10PixelMethod lbl_803af6f4[];
extern const S10PixelMethod lbl_803af704[];
extern const S10PixelMethod lbl_803af70c[];

extern "C" int w3d_s10_convert_pixels_801d906c(Ptr32<void> source, int unused1, unsigned int sourceStride, unsigned int columns, unsigned int rows, Ptr32<void> destination, int unused6, unsigned int destinationStride)
{
    S10PixelMethod input = lbl_803af6e4[0];
    S10PixelMethod output = lbl_803af6ec[0];
    S10Pixel pixel;
    unsigned int y = 0;
    for (; y < rows; ++y) {
        unsigned int x = 0;
        if (x < columns) {
            Ptr32<char> src = (Ptr32<char>)source + y * sourceStride;
            Ptr32<char> dst = (Ptr32<char>)destination + y * destinationStride;
            do {
                (input)(&(pixel), src);
                src += 4;
                (output)(&(pixel), dst);
                dst += 3;
                ++x;
            } while (x < columns);
        }
    }
    return 0;
}

extern "C" int w3d_s10_convert_pixels_801d9150(Ptr32<void> source, int unused1, unsigned int sourceStride, unsigned int columns, unsigned int rows, Ptr32<void> destination, int unused6, unsigned int destinationStride)
{
    S10PixelMethod input = lbl_803af6f4[0];
    S10PixelMethod output = lbl_803af6fc[0];
    S10Pixel pixel;
    unsigned int y = 0;
    for (; y < rows; ++y) {
        unsigned int x = 0;
        if (x < columns) {
            Ptr32<char> src = (Ptr32<char>)source + y * sourceStride;
            Ptr32<char> dst = (Ptr32<char>)destination + y * destinationStride;
            do {
                (input)(&(pixel), src);
                src += 3;
                (output)(&(pixel), dst);
                dst += 4;
                ++x;
            } while (x < columns);
        }
    }
    return 0;
}

extern "C" int w3d_s10_convert_pixels_801d9234(Ptr32<void> source, int unused1, unsigned int sourceStride, unsigned int columns, unsigned int rows, Ptr32<void> destination, int unused6, unsigned int destinationStride)
{
    S10PixelMethod input = lbl_803af6e4[0];
    S10PixelMethod output = lbl_803af704[0];
    S10Pixel pixel;
    unsigned int y = 0;
    for (; y < rows; ++y) {
        unsigned int x = 0;
        if (x < columns) {
            Ptr32<char> src = (Ptr32<char>)source + y * sourceStride;
            Ptr32<char> dst = (Ptr32<char>)destination + y * destinationStride;
            do {
                (input)(&(pixel), src);
                src += 4;
                (output)(&(pixel), dst);
                dst += 2;
                ++x;
            } while (x < columns);
        }
    }
    return 0;
}

extern "C" int w3d_s10_convert_pixels_801d9318(Ptr32<void> source, int unused1, unsigned int sourceStride, unsigned int columns, unsigned int rows, Ptr32<void> destination, int unused6, unsigned int destinationStride)
{
    S10PixelMethod input = lbl_803af70c[0];
    S10PixelMethod output = lbl_803af6fc[0];
    S10Pixel pixel;
    unsigned int y = 0;
    for (; y < rows; ++y) {
        unsigned int x = 0;
        if (x < columns) {
            Ptr32<char> src = (Ptr32<char>)source + y * sourceStride;
            Ptr32<char> dst = (Ptr32<char>)destination + y * destinationStride;
            do {
                (input)(&(pixel), src);
                src += 2;
                (output)(&(pixel), dst);
                dst += 4;
                ++x;
            } while (x < columns);
        }
    }
    return 0;
}

extern "C" int w3d_s10_convert_pixels_801d93fc(Ptr32<void> source, int unused1, unsigned int sourceStride, unsigned int columns, unsigned int rows, Ptr32<void> destination, int unused6, unsigned int destinationStride)
{
    S10PixelMethod input = lbl_803af6f4[0];
    S10PixelMethod output = lbl_803af704[0];
    S10Pixel pixel;
    unsigned int y = 0;
    for (; y < rows; ++y) {
        unsigned int x = 0;
        if (x < columns) {
            Ptr32<char> src = (Ptr32<char>)source + y * sourceStride;
            Ptr32<char> dst = (Ptr32<char>)destination + y * destinationStride;
            do {
                (input)(&(pixel), src);
                src += 3;
                (output)(&(pixel), dst);
                dst += 2;
                ++x;
            } while (x < columns);
        }
    }
    return 0;
}

extern "C" int w3d_s10_convert_pixels_801d94e0(Ptr32<void> source, int unused1, unsigned int sourceStride, unsigned int columns, unsigned int rows, Ptr32<void> destination, int unused6, unsigned int destinationStride)
{
    S10PixelMethod input = lbl_803af70c[0];
    S10PixelMethod output = lbl_803af6ec[0];
    S10Pixel pixel;
    unsigned int y = 0;
    for (; y < rows; ++y) {
        unsigned int x = 0;
        if (x < columns) {
            Ptr32<char> src = (Ptr32<char>)source + y * sourceStride;
            Ptr32<char> dst = (Ptr32<char>)destination + y * destinationStride;
            do {
                (input)(&(pixel), src);
                src += 2;
                (output)(&(pixel), dst);
                dst += 3;
                ++x;
            } while (x < columns);
        }
    }
    return 0;
}


