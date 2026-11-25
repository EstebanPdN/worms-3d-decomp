#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "c1_stl_sort.c"
/* Sorting helpers instantiated by the compiler for three 4-byte element
 * types (0x80353c78.., 0x8035434c.., 0x80354a90..). Each sort runs an
 * introspective sort to depth 2*floor(log2(n)) and then a final insertion
 * pass; the comparison functor is an empty object passed by value. The
 * per-type loop and insertion routines stay external.
 */
typedef struct W3dLess {
    unsigned char unused;
} W3dLess;

typedef int W3dSortItem;

void w3d_fn_80353b9c(Ptr32<W3dSortItem> a, Ptr32<W3dSortItem> b, Ptr32<W3dSortItem> c, int d, W3dLess less);
void w3d_fn_80354264(Ptr32<W3dSortItem> a, Ptr32<W3dSortItem> b, Ptr32<W3dSortItem> c, int d, W3dLess less);
void w3d_fn_803549a8(Ptr32<W3dSortItem> a, Ptr32<W3dSortItem> b, Ptr32<W3dSortItem> c, int d, W3dLess less);
void w3d_fn_80353d1c(Ptr32<W3dSortItem> first, Ptr32<W3dSortItem> last, Ptr32<W3dSortItem> hint, int depth, W3dLess less);
void w3d_fn_80354408(Ptr32<W3dSortItem> first, Ptr32<W3dSortItem> last, Ptr32<W3dSortItem> hint, int depth, W3dLess less);
void w3d_fn_80354b4c(Ptr32<W3dSortItem> first, Ptr32<W3dSortItem> last, Ptr32<W3dSortItem> hint, int depth, W3dLess less);
void w3d_fn_80353f70(Ptr32<W3dSortItem> first, Ptr32<W3dSortItem> last, W3dLess less);
void w3d_fn_803546b4(Ptr32<W3dSortItem> first, Ptr32<W3dSortItem> last, W3dLess less);
void w3d_fn_80354df8(Ptr32<W3dSortItem> first, Ptr32<W3dSortItem> last, W3dLess less);

void w3d_stl_forward_80353c78(Ptr32<W3dSortItem> a, Ptr32<W3dSortItem> b, Ptr32<W3dSortItem> c)
{
    W3dLess less;
    less.unused = 0;
    w3d_fn_80353b9c(a, b, c, 0, less);
}

static __inline__ int w3d_sort_depth(int n)
{
    int k;
    for (k = 0; n != 1; n >>= 1)
        ++k;
    return k;
}

static __inline__ W3dLess w3d_less(void)
{
    W3dLess less;
    less.unused = 0;
    return less;
}

void w3d_stl_sort_80353ff0(Ptr32<W3dSortItem> first, Ptr32<W3dSortItem> last)
{
    if (first != last) {
        w3d_fn_80353d1c(first, last, 0, w3d_sort_depth(last - first) * 2, w3d_less());
        w3d_fn_80353f70(first, last, w3d_less());
    }
}

void w3d_stl_forward_8035434c(Ptr32<W3dSortItem> a, Ptr32<W3dSortItem> b, Ptr32<W3dSortItem> c)
{
    W3dLess less;
    less.unused = 0;
    w3d_fn_80354264(a, b, c, 0, less);
}

void w3d_stl_sort_80354734(Ptr32<W3dSortItem> first, Ptr32<W3dSortItem> last)
{
    if (first != last) {
        w3d_fn_80354408(first, last, 0, w3d_sort_depth(last - first) * 2, w3d_less());
        w3d_fn_803546b4(first, last, w3d_less());
    }
}

void w3d_stl_forward_80354a90(Ptr32<W3dSortItem> a, Ptr32<W3dSortItem> b, Ptr32<W3dSortItem> c)
{
    W3dLess less;
    less.unused = 0;
    w3d_fn_803549a8(a, b, c, 0, less);
}

void w3d_stl_sort_80354e78(Ptr32<W3dSortItem> first, Ptr32<W3dSortItem> last)
{
    if (first != last) {
        w3d_fn_80354b4c(first, last, 0, w3d_sort_depth(last - first) * 2, w3d_less());
        w3d_fn_80354df8(first, last, w3d_less());
    }
}

}
