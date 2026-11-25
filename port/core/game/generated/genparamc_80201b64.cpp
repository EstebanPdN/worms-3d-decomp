#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparamc_80201b64.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Pair templates (later batch): 32-bit stream transfer with byte swap,
 * first-success dispatch over children, and shared-string lowercasing. */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef Ptr32<int (Ptr32<void>, Ptr32<void>, int, int)> W3dTransfer;
typedef Ptr32<int (Ptr32<void>, int, int, int)> W3dSkip;
typedef Ptr32<int (Ptr32<void>, Ptr32<void>, int, Ptr32<void>)> W3dOffer;
extern const char lbl_803db449[];
Ptr32<unsigned short> fn_8020bc88(Ptr32<Ptr32<char>>, unsigned int);
void fn_8020bb2c(Ptr32<void>);

int w3d_transfer_swapped32_80201b64(Ptr32<void> self, Ptr32<unsigned int> buffer, unsigned int count)
{
    Ptr32<void> stream;
    int result;
    unsigned int i;
    Ptr32<unsigned int> p;
    if (!buffer) {
        stream = FIELD(self, void *, 20);
        return (*(Ptr32<W3dSkip>)(*(Ptr32<Ptr32<char>>)stream + 28))(stream, count << 2, 1, 0);
    }
    stream = FIELD(self, void *, 20);
    result = (*(Ptr32<W3dTransfer>)(*(Ptr32<Ptr32<char>>)stream + 20))(stream, buffer, count << 2, 0);
    for (i = 0; i < count; i++) {
        unsigned int v;
        p = buffer++;
        v = *p;
        *p = v;
    }
    return result;
}

int w3d_transfer_swapped32_80201c1c(Ptr32<void> self, Ptr32<unsigned int> buffer, unsigned int count)
{
    Ptr32<void> stream;
    int result;
    unsigned int i;
    Ptr32<unsigned int> p;
    if (!buffer) {
        stream = FIELD(self, void *, 20);
        return (*(Ptr32<W3dSkip>)(*(Ptr32<Ptr32<char>>)stream + 28))(stream, count << 2, 1, 0);
    }
    stream = FIELD(self, void *, 20);
    result = (*(Ptr32<W3dTransfer>)(*(Ptr32<Ptr32<char>>)stream + 20))(stream, buffer, count << 2, 0);
    for (i = 0; i < count; i++) {
        unsigned int v;
        p = buffer++;
        v = *p;
        *p = v;
    }
    return result;
}

int w3d_offer_to_children_8020a304(Ptr32<void> self, Ptr32<void> request, int flags, Ptr32<void> context)
{
    int result = 0x80004005;
    Ptr32<Ptr32<void>> end = FIELD(self, void **, 24);
    Ptr32<Ptr32<void>> it = FIELD(self, void **, 20);
    Ptr32<void> first = FIELD(self, void *, 32);
    if (first && (flags & 10)) {
        result = (*(Ptr32<W3dOffer>)(*(Ptr32<Ptr32<char>>)first + 28))(first, request, flags, context);
        if (result >= 0)
            return result;
    }
    for (; it != end; it++) {
        result = (*(Ptr32<W3dOffer>)(*(Ptr32<Ptr32<char>>)*it + 28))(*it, request, flags, context);
        if (result >= 0)
            return result;
    }
    return result;
}

int w3d_offer_to_children_8020a3b0(Ptr32<void> self, Ptr32<void> request, int flags, Ptr32<void> context)
{
    int result = 0x80004005;
    Ptr32<Ptr32<void>> end = FIELD(self, void **, 24);
    Ptr32<Ptr32<void>> it = FIELD(self, void **, 20);
    Ptr32<void> first = FIELD(self, void *, 32);
    if (first && (flags & 10)) {
        result = (*(Ptr32<W3dOffer>)(*(Ptr32<Ptr32<char>>)first + 32))(first, request, flags, context);
        if (result >= 0)
            return result;
    }
    for (; it != end; it++) {
        result = (*(Ptr32<W3dOffer>)(*(Ptr32<Ptr32<char>>)*it + 32))(*it, request, flags, context);
        if (result >= 0)
            return result;
    }
    return result;
}

void w3d_string_to_lower_8020c230(Ptr32<Ptr32<char>> string)
{
    Ptr32<char> text = *string;
    Ptr32<unsigned short> header = (Ptr32<unsigned short>)(text - 6);
    unsigned int length = header[1];
    unsigned int i;
    Ptr32<char> out;
    if (FIELD(text, unsigned short, -6) > 1) {
        Ptr32<unsigned short> copy = fn_8020bc88(string, length + 1);
        if (--FIELD(text, unsigned short, -6) == 0)
            fn_8020bb2c(header);
        copy[1] = length;
    }
    out = *string;
    for (i = 0; i < length; i++) {
        int c = (signed char)text[i];
        if ((c + lbl_803db449)[0] & 1)
            c += 32;
        out[i] = c;
    }
    out[i] = 0;
}

}
