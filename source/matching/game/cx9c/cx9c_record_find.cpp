/* Observed: 12-byte stride and four-way unrolled equality search at 0x8035c0ac.
 * Type and search names are inferred; unspecified record fields remain opaque. */
struct Cx9cRecord {unsigned int key,unknown_04,unknown_08;};
struct Cx9cEqual {unsigned int value;bool operator()(const Cx9cRecord &record) const {return value==record.key;}};
static inline Cx9cRecord *cx9c_find_if(Cx9cRecord *first,Cx9cRecord *last,Cx9cEqual equal)
{
    int groups=(last-first)>>2;
    for (;groups>0;--groups) {
        if (equal(*first)) return first; ++first;
        if (equal(*first)) return first; ++first;
        if (equal(*first)) return first; ++first;
        if (equal(*first)) return first; ++first;
    }
    switch (last-first) {
    case 3: if (equal(*first)) return first; ++first;
    case 2: if (equal(*first)) return first; ++first;
    case 1: if (equal(*first)) return first; ++first;
    case 0: default: return last;
    }
}

extern "C" Cx9cRecord *w3d_cx9c_find_8035c0ac(Cx9cRecord *first,Cx9cRecord *last,const unsigned int &key) {Cx9cEqual equal;equal.value=key;return cx9c_find_if(first,last,equal);}
