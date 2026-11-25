typedef void (*S10ConvertMethod)(void *, const void *);
struct S10MemberConverter { int adjustment; S10ConvertMethod method; };
extern S10MemberConverter lbl_803af6ec[];
extern S10MemberConverter lbl_803af6e4[];
extern "C" int w3d_s10_convert_rows_801d906c(void *source, int unused1, unsigned int sourceStride, unsigned int columns, unsigned int rows, void *destination, int unused6, unsigned int destinationStride)
{
    S10MemberConverter output = lbl_803af6ec[0];
    S10MemberConverter input = lbl_803af6e4[0];
    unsigned int y = 0;
    unsigned int pixel;
    for (; y < rows; ++y) {
        unsigned int x = 0;
        if (x < columns) {
            char *dst = (char *)destination + y * destinationStride;
            char *src = (char *)source + y * sourceStride;
            do {
                input.method((char *)&pixel + (short)(input.adjustment >> 16), src);
                src += 4;
                output.method((char *)&pixel + (short)(output.adjustment >> 16), dst);
                dst += 3;
                ++x;
            } while (x < columns);
        }
    }
    return 0;
}
