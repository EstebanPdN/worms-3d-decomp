#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s9acquire_80182a24.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Shared pool allocation, ownership transfer and initialization sequence. */
typedef Ptr32<void (Ptr32<void>)> S9PoolRefMethod;
typedef Ptr32<int (Ptr32<void>, Ptr32<void>, int)> S9PoolInitMethod;
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
extern unsigned short lbl_804ab644;
extern Ptr32<unsigned short> lbl_804ab640;
extern Ptr32<char> lbl_804ab634;
extern int lbl_804a89d8[];
extern int fn_80190438(Ptr32<void>, Ptr32<void>, int);
extern unsigned short lbl_804ab668;
extern Ptr32<unsigned short> lbl_804ab664;
extern Ptr32<char> lbl_804ab658;
extern unsigned short lbl_804ab690;
extern Ptr32<unsigned short> lbl_804ab68c;
extern Ptr32<char> lbl_804ab680;
extern unsigned short lbl_804b18b8;
extern Ptr32<unsigned short> lbl_804b18b4;
extern Ptr32<char> lbl_804b18b0;

int s9_pool_acquire_80182a24(Ptr32<void> source, Ptr32<Ptr32<void>> out, int priority)
{
    unsigned short available = lbl_804ab644;
    int index;
    int offset;
    Ptr32<char> base;
    Ptr32<void> entry;
    int result;
    if (!available) return 0x80004005;
    if (priority == 255) priority = FIELD(source, unsigned char, 26);
    index = lbl_804ab640[(unsigned short)(available - 1)];
    base = lbl_804ab634;
    lbl_804ab644 = available - 1;
    offset = index * 176;
    entry = (Ptr32<void>)w3d::G((offset + (int)w3d::H(base)));
    if (entry) FIELD(FIELD(entry,void *,0), S9PoolRefMethod,12)(entry);
    if (*out) FIELD(FIELD(*out,void *,0), S9PoolRefMethod,16)(*out);
    *out = entry;
    result = FIELD(FIELD((Ptr32<void>)w3d::G((offset + (int)w3d::H(base))),void *,0), S9PoolInitMethod,40)(entry,source,priority);
    if (result < 0) return result;
    lbl_804a89d8[FIELD(source, unsigned char,27)]++;
    return fn_80190438(source,out,255);
}

int s9_pool_acquire_801849ec(Ptr32<void> source, Ptr32<Ptr32<void>> out, int priority)
{
    unsigned short available = lbl_804ab668;
    int index;
    int offset;
    Ptr32<char> base;
    Ptr32<void> entry;
    int result;
    if (!available) return 0x80004005;
    if (priority == 255) priority = FIELD(source, unsigned char, 26);
    index = lbl_804ab664[(unsigned short)(available - 1)];
    base = lbl_804ab658;
    lbl_804ab668 = available - 1;
    offset = index * 172;
    entry = (Ptr32<void>)w3d::G((offset + (int)w3d::H(base)));
    if (entry) FIELD(FIELD(entry,void *,0), S9PoolRefMethod,12)(entry);
    if (*out) FIELD(FIELD(*out,void *,0), S9PoolRefMethod,16)(*out);
    *out = entry;
    result = FIELD(FIELD((Ptr32<void>)w3d::G((offset + (int)w3d::H(base))),void *,0), S9PoolInitMethod,40)(entry,source,priority);
    if (result < 0) return result;
    lbl_804a89d8[FIELD(source, unsigned char,27)]++;
    return fn_80190438(source,out,255);
}

int s9_pool_acquire_80188344(Ptr32<void> source, Ptr32<Ptr32<void>> out, int priority)
{
    unsigned short available = lbl_804ab690;
    int index;
    int offset;
    Ptr32<char> base;
    Ptr32<void> entry;
    int result;
    if (!available) return 0x80004005;
    if (priority == 255) priority = FIELD(source, unsigned char, 26);
    index = lbl_804ab68c[(unsigned short)(available - 1)];
    base = lbl_804ab680;
    lbl_804ab690 = available - 1;
    offset = index * 172;
    entry = (Ptr32<void>)w3d::G((offset + (int)w3d::H(base)));
    if (entry) FIELD(FIELD(entry,void *,0), S9PoolRefMethod,12)(entry);
    if (*out) FIELD(FIELD(*out,void *,0), S9PoolRefMethod,16)(*out);
    *out = entry;
    result = FIELD(FIELD((Ptr32<void>)w3d::G((offset + (int)w3d::H(base))),void *,0), S9PoolInitMethod,40)(entry,source,priority);
    if (result < 0) return result;
    lbl_804a89d8[FIELD(source, unsigned char,27)]++;
    return fn_80190438(source,out,255);
}

int s9_pool_acquire_8018afb0(Ptr32<void> source, Ptr32<Ptr32<void>> out, int priority)
{
    unsigned short available = lbl_804b18b8;
    int index;
    int offset;
    Ptr32<char> base;
    Ptr32<void> entry;
    int result;
    if (!available) return 0x80004005;
    if (priority == 255) priority = FIELD(source, unsigned char, 26);
    index = lbl_804b18b4[(unsigned short)(available - 1)];
    base = lbl_804b18b0;
    lbl_804b18b8 = available - 1;
    offset = index * 276;
    entry = (Ptr32<void>)w3d::G((offset + (int)w3d::H(base)));
    if (entry) FIELD(FIELD(entry,void *,0), S9PoolRefMethod,12)(entry);
    if (*out) FIELD(FIELD(*out,void *,0), S9PoolRefMethod,16)(*out);
    *out = entry;
    result = FIELD(FIELD((Ptr32<void>)w3d::G((offset + (int)w3d::H(base))),void *,0), S9PoolInitMethod,40)(entry,source,priority);
    if (result < 0) return result;
    lbl_804a89d8[FIELD(source, unsigned char,27)]++;
    return fn_80190438(source,out,255);
}

}
