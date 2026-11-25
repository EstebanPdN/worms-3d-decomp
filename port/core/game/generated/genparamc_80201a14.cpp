#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparamc_80201a14.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Pair templates (later batch): 16-bit stream transfer with byte swap and a
 * callback message builder. */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef Ptr32<int (Ptr32<void>, Ptr32<void>, int, int)> W3dTransfer;
typedef Ptr32<int (Ptr32<void>, int, int, int)> W3dSkip;

int w3d_transfer_swapped16_80201a14(Ptr32<void> self, Ptr32<unsigned short> buffer, unsigned int count)
{
    Ptr32<void> stream;
    int result;
    unsigned int i;
    Ptr32<unsigned short> p;
    if (!buffer) {
        stream = FIELD(self, void *, 20);
        return (*(Ptr32<W3dSkip>)(*(Ptr32<Ptr32<char>>)stream + 28))(stream, count << 1, 1, 0);
    }
    stream = FIELD(self, void *, 20);
    result = (*(Ptr32<W3dTransfer>)(*(Ptr32<Ptr32<char>>)stream + 20))(stream, buffer, count << 1, 0);
    for (i = 0; i < count; i++) {
        p = buffer++;
        *p = *p;
    }
    return result;
}

int w3d_transfer_swapped16_80201abc(Ptr32<void> self, Ptr32<unsigned short> buffer, unsigned int count)
{
    Ptr32<void> stream;
    int result;
    unsigned int i;
    Ptr32<unsigned short> p;
    if (!buffer) {
        stream = FIELD(self, void *, 20);
        return (*(Ptr32<W3dSkip>)(*(Ptr32<Ptr32<char>>)stream + 28))(stream, count << 1, 1, 0);
    }
    stream = FIELD(self, void *, 20);
    result = (*(Ptr32<W3dTransfer>)(*(Ptr32<Ptr32<char>>)stream + 20))(stream, buffer, count << 1, 0);
    for (i = 0; i < count; i++) {
        p = buffer++;
        *p = *p;
    }
    return result;
}

}
