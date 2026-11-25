#include "w3d_ptr.h"
#line 1 "h1_stlport_find_int.cpp"
/* STLport find for random-access ranges of int (session b169b320): the
 * loop is unrolled four times and the remainder handled by a switch that
 * falls through. Five instantiations share the body. */

struct W3dRandomAccessTag { char w3d_empty; };

#define W3D_FIND_INT(NAME) \
extern "C" int *NAME(int *first, int *last, const int &val, const W3dRandomAccessTag &) \
{ \
    int trip_count = (last - first) >> 2; \
    for (; trip_count > 0; --trip_count) { \
        if (*first == val) return first; \
        ++first; \
        if (*first == val) return first; \
        ++first; \
        if (*first == val) return first; \
        ++first; \
        if (*first == val) return first; \
        ++first; \
    } \
    switch (last - first) { \
    case 3: \
        if (*first == val) return first; \
        ++first; \
    case 2: \
        if (*first == val) return first; \
        ++first; \
    case 1: \
        if (*first == val) return first; \
        ++first; \
    case 0: \
    default: \
        return last; \
    } \
}

W3D_FIND_INT(w3d_find_80356474)
W3D_FIND_INT(w3d_find_80356884)
W3D_FIND_INT(w3d_find_80356934)
W3D_FIND_INT(w3d_find_80359cec)
W3D_FIND_INT(w3d_find_8035c414)


