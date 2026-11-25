#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparamc_801ee78c.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Pair templates (later batch): text split on newlines and inline reference
 * array resize. */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef Ptr32<void (Ptr32<void>)> W3dMethod;
#define VCALL(p, o) ((*(W3dMethod *)w3d::AG(*(Ptr32<char> *)w3d::AG(p) + (o)))(p))
int fn_802086dc(Ptr32<void>, Ptr32<const char>, unsigned int);
int fn_80208994(Ptr32<void>, Ptr32<const char>, unsigned int);

Ptr32<void> w3d_resize_refs_801ee78c(Ptr32<void> self, unsigned int count)
{
    unsigned int old = FIELD(self, unsigned int, 24);
    Ptr32<Ptr32<void>> items = (Ptr32<Ptr32<void>>)((Ptr32<char>)self + 32);
    if (old < count) {
        unsigned int i;
        for (i = old; i < count; i++)
            items[i] = 0;
    } else {
        unsigned int j;
        for (j = count; j < old; j++)
            VCALL(items[j], 16);
    }
    FIELD(self, unsigned int, 24) = count;
    return self;
}

Ptr32<void> w3d_resize_refs_801eeb58(Ptr32<void> self, unsigned int count)
{
    unsigned int old = FIELD(self, unsigned int, 24);
    Ptr32<Ptr32<void>> items = (Ptr32<Ptr32<void>>)((Ptr32<char>)self + 32);
    if (old < count) {
        unsigned int i;
        for (i = old; i < count; i++)
            items[i] = 0;
    } else {
        unsigned int j;
        for (j = count; j < old; j++)
            VCALL(items[j], 16);
    }
    FIELD(self, unsigned int, 24) = count;
    return self;
}

int w3d_write_lines_8020863c(Ptr32<void> self, Ptr32<const char> text, unsigned int length)
{
    unsigned int start = 0;
    unsigned int i;
    for (i = 0; i < length; i++) {
        if (text[i] == '\n') {
            int result = fn_802086dc(self, text + start, i - start + 1);
            if (result < 0)
                return result;
            FIELD(self, int, 36) = 1;
            start = i + 1;
        }
    }
    if (start != length)
        return fn_802086dc(self, text + start, length - start);
    return 0;
}

int w3d_write_lines_802088f4(Ptr32<void> self, Ptr32<const char> text, unsigned int length)
{
    unsigned int start = 0;
    unsigned int i;
    for (i = 0; i < length; i++) {
        if (text[i] == '\n') {
            int result = fn_80208994(self, text + start, i - start + 1);
            if (result < 0)
                return result;
            FIELD(self, int, 28) = 1;
            start = i + 1;
        }
    }
    if (start != length)
        return fn_80208994(self, text + start, length - start);
    return 0;
}

}
