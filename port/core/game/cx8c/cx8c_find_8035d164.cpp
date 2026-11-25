#include "w3d_ptr.h"
#line 1 "cx8c_find_8035d164.cpp"
/* Observed: 4-byte stride and four-way unrolled equality search at 0x8035d164.
 * Type and search names are inferred; unspecified record fields remain opaque. */
extern "C" Ptr32<int> w3d_cx8c_find_8035d164(Ptr32<int> first,Ptr32<int> last,const int &key)
{
    int groups=(last-first)>>2;
    for (;groups>0;--groups) {
        if (*first==key) return first; ++first;
        if (*first==key) return first; ++first;
        if (*first==key) return first; ++first;
        if (*first==key) return first; ++first;
    }
    switch (last-first) {
    case 3: {int n=key;int v=*first;if (v==n) return first;} ++first;
    case 2: {int n=key;int v=*first;if (v==n) return first;} ++first;
    case 1: if (*first==key) return first; ++first;
    case 0: default: return last;
    }
}


