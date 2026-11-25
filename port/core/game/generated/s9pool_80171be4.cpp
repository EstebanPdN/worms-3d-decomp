#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s9pool_80171be4.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Pool layouts and virtual methods inferred solely from observed offsets. */
typedef Ptr32<int (Ptr32<void>)> S9PoolMethod;
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
extern unsigned short lbl_804b18a4;
extern Ptr32<char> lbl_804b189c;
extern int fn_80185b0c(Ptr32<void>);
extern int fn_80190458(Ptr32<void>, Ptr32<void>);
extern int lbl_804a89d8[];
extern unsigned short lbl_804ab594;
extern Ptr32<unsigned short> lbl_804ab590;
extern unsigned short lbl_804ab58c;
extern Ptr32<char> lbl_804ab588;
extern unsigned short lbl_804ab610;
extern Ptr32<char> lbl_804ab60c;
extern unsigned short lbl_804ab644;
extern Ptr32<unsigned short> lbl_804ab640;
extern unsigned short lbl_804ab668;
extern Ptr32<unsigned short> lbl_804ab664;
extern unsigned short lbl_804ab65c;
extern Ptr32<char> lbl_804ab658;
extern unsigned short lbl_804ab690;
extern Ptr32<unsigned short> lbl_804ab68c;
extern unsigned short lbl_804ab684;
extern Ptr32<char> lbl_804ab680;
extern unsigned short lbl_804b18b8;
extern Ptr32<unsigned short> lbl_804b18b4;

int s9_pool_find_80171be4(int key)
{
    int index;
    for (index = 0; index < lbl_804b18a4; index++) {
        Ptr32<void> item = lbl_804b189c + index * 136;
        if (fn_80185b0c(item)) {
            item = (Ptr32<void>)w3d::G((index * 136 + (int)w3d::H(lbl_804b189c)));
            if (key == FIELD(FIELD(item, void *, 0), S9PoolMethod, 64)(item))
                break;
        }
    }
    return index == lbl_804b18a4 ? -1 : index;
}

int s9_pool_release_80174798(Ptr32<void> owner, Ptr32<void> item)
{
    int category;
    int id;
    fn_80190458(owner,item);
    { Ptr32<int> counts = lbl_804a89d8;
      category = FIELD(FIELD(item, void *, 0), S9PoolMethod, 48)(item);
      counts[category]--; }
    id = FIELD(FIELD(item, void *, 0), S9PoolMethod, 56)(item);
    lbl_804ab590[lbl_804ab594++] = id;
    return 0;
}

int s9_pool_find_80174884(int key)
{
    int index;
    for (index = 0; index < lbl_804ab58c; index++) {
        Ptr32<void> item = lbl_804ab588 + index * 172;
        if (fn_80185b0c(item)) {
            item = (Ptr32<void>)w3d::G((index * 172 + (int)w3d::H(lbl_804ab588)));
            if (key == FIELD(FIELD(item, void *, 0), S9PoolMethod, 64)(item))
                break;
        }
    }
    return index == lbl_804ab58c ? -1 : index;
}

int s9_pool_find_8017f8c4(int key)
{
    int index;
    for (index = 0; index < lbl_804ab610; index++) {
        Ptr32<void> item = lbl_804ab60c + index * 204;
        if (fn_80185b0c(item)) {
            item = (Ptr32<void>)w3d::G((index * 204 + (int)w3d::H(lbl_804ab60c)));
            if (key == FIELD(FIELD(item, void *, 0), S9PoolMethod, 64)(item))
                break;
        }
    }
    return index == lbl_804ab610 ? -1 : index;
}

int s9_pool_release_80182b20(Ptr32<void> owner, Ptr32<void> item)
{
    int category;
    int id;
    fn_80190458(owner,item);
    { Ptr32<int> counts = lbl_804a89d8;
      category = FIELD(FIELD(item, void *, 0), S9PoolMethod, 48)(item);
      counts[category]--; }
    id = FIELD(FIELD(item, void *, 0), S9PoolMethod, 56)(item);
    lbl_804ab640[lbl_804ab644++] = id;
    return 0;
}

int s9_pool_release_80184ae8(Ptr32<void> owner, Ptr32<void> item)
{
    int category;
    int id;
    fn_80190458(owner,item);
    { Ptr32<int> counts = lbl_804a89d8;
      category = FIELD(FIELD(item, void *, 0), S9PoolMethod, 48)(item);
      counts[category]--; }
    id = FIELD(FIELD(item, void *, 0), S9PoolMethod, 56)(item);
    lbl_804ab664[lbl_804ab668++] = id;
    return 0;
}

int s9_pool_find_80184d68(int key)
{
    int index;
    for (index = 0; index < lbl_804ab65c; index++) {
        Ptr32<void> item = lbl_804ab658 + index * 172;
        if (fn_80185b0c(item)) {
            item = (Ptr32<void>)w3d::G((index * 172 + (int)w3d::H(lbl_804ab658)));
            if (key == FIELD(FIELD(item, void *, 0), S9PoolMethod, 64)(item))
                break;
        }
    }
    return index == lbl_804ab65c ? -1 : index;
}

int s9_pool_release_80188440(Ptr32<void> owner, Ptr32<void> item)
{
    int category;
    int id;
    fn_80190458(owner,item);
    { Ptr32<int> counts = lbl_804a89d8;
      category = FIELD(FIELD(item, void *, 0), S9PoolMethod, 48)(item);
      counts[category]--; }
    id = FIELD(FIELD(item, void *, 0), S9PoolMethod, 56)(item);
    lbl_804ab68c[lbl_804ab690++] = id;
    return 0;
}

int s9_pool_find_801886c0(int key)
{
    int index;
    for (index = 0; index < lbl_804ab684; index++) {
        Ptr32<void> item = lbl_804ab680 + index * 172;
        if (fn_80185b0c(item)) {
            item = (Ptr32<void>)w3d::G((index * 172 + (int)w3d::H(lbl_804ab680)));
            if (key == FIELD(FIELD(item, void *, 0), S9PoolMethod, 64)(item))
                break;
        }
    }
    return index == lbl_804ab684 ? -1 : index;
}

int s9_pool_release_8018b0ac(Ptr32<void> owner, Ptr32<void> item)
{
    int category;
    int id;
    fn_80190458(owner,item);
    { Ptr32<int> counts = lbl_804a89d8;
      category = FIELD(FIELD(item, void *, 0), S9PoolMethod, 48)(item);
      counts[category]--; }
    id = FIELD(FIELD(item, void *, 0), S9PoolMethod, 56)(item);
    lbl_804b18b4[lbl_804b18b8++] = id;
    return 0;
}

}
