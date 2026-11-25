/* Observed: 4-byte stride and four-way unrolled equality search at 0x8035c220.
 * Type and search names are inferred; unspecified record fields remain opaque. */
extern "C" int cx9c_strcmp_802ef234(const char *,const char *);
static inline const char **cx9c_search(const char **last,const char **first,const char *const &key)
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

extern "C" const char **w3d_cx9c_find_8035c220(const char **first,const char **last,const char *const &key) {return cx9c_search(last,first,key);}
