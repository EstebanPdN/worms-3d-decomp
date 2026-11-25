#include "w3d_ptr.h"
#line 1 "cx9c_string_find.cpp"
/* Observed: 4-byte stride and four-way unrolled equality search at 0x8035c220.
 * Type and search names are inferred; unspecified record fields remain opaque. */
extern "C" int cx9c_strcmp_802ef234(Ptr32<const char>,Ptr32<const char>);
static inline Ptr32<Ptr32<const char>> cx9c_search(Ptr32<Ptr32<const char>> last,Ptr32<Ptr32<const char>> first,Ptr32<const char> const &key)
{
    int groups=(last-first)>>2;
    for (;groups>0;--groups) {
        if (cx9c_strcmp_802ef234(*first,key)==0) return first; ++first;
        if (cx9c_strcmp_802ef234(*first,key)==0) return first; ++first;
        if (cx9c_strcmp_802ef234(*first,key)==0) return first; ++first;
        if (cx9c_strcmp_802ef234(*first,key)==0) return first; ++first;
    }
    switch (last-first) {
    case 3: {if (cx9c_strcmp_802ef234(*first,key)==0) return first;} ++first;
    case 2: {if (cx9c_strcmp_802ef234(*first,key)==0) return first;} ++first;
    case 1: if (cx9c_strcmp_802ef234(*first,key)==0) return first; ++first;
    case 0: default: return last;
    }
}

extern "C" Ptr32<Ptr32<const char>> w3d_cx9c_find_8035c220(Ptr32<Ptr32<const char>> first,Ptr32<Ptr32<const char>> last,Ptr32<const char> const &key) {return cx9c_search(last,first,key);}


