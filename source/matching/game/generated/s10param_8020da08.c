/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct S10OutputStream S10OutputStream;
typedef void (*S10Write)(S10OutputStream *, const char *, int, int);
struct S10OutputStream { S10Write *vtable; };
typedef struct S10Formatter { S10OutputStream *stream; unsigned int flags; } S10Formatter;
extern int fn_80212cf4(unsigned int, char *, unsigned int);
extern int fn_802ef9c0(const char *);
extern void fn_8020d600(S10Formatter *, int, int);

S10Formatter *w3d_s10_format_number_8020da08(S10Formatter *object, unsigned int value)
{
    char buffer[16];
    int length;
    int width;
    fn_80212cf4(value, buffer, object->flags >> 25);
    length = fn_802ef9c0(buffer);
    width = ((unsigned char *)&object->flags)[1];
    if (length < width)
        fn_8020d600(object, width - length, 32);
    object->stream->vtable[6](object->stream, buffer, length, 0);
    return object;
}
