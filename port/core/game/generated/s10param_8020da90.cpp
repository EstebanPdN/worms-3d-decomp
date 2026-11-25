#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s10param_8020da90.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct S10OutputStream S10OutputStream;
typedef Ptr32<void (Ptr32<S10OutputStream>, Ptr32<const char>, int, int)> S10Write;
struct S10OutputStream { Ptr32<S10Write> vtable; };
typedef struct S10Formatter { Ptr32<S10OutputStream> stream; unsigned int flags; } S10Formatter;
extern int fn_80212d4c(unsigned int, Ptr32<char>, unsigned int);
extern int fn_802ef9c0(Ptr32<const char>);
extern void fn_8020d600(Ptr32<S10Formatter>, int, int);

Ptr32<S10Formatter> w3d_s10_format_number_8020da90(Ptr32<S10Formatter> object, unsigned int value)
{
    char buffer[16];
    int length;
    int width;
    fn_80212d4c(value, buffer, object->flags >> 25);
    length = fn_802ef9c0(buffer);
    width = ((Ptr32<unsigned char>)&object->flags)[1];
    if (length < width)
        fn_8020d600(object, width - length, 32);
    object->stream->vtable[6](object->stream, buffer, length, 0);
    return object;
}

}
