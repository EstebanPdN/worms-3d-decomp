/* Inferred random-access find over 64-byte records, original 0x8035a990.
 * Record key occupies bytes +16..31. The needle is a pointer-like handle
 * whose original accessor exposes 16 comparable bytes. Four comparisons
 * are unrolled, followed by a fall-through remainder switch.
 */
struct Cx9cFindRecord {unsigned char unknown_00[16],key[16],unknown_20[32];};
struct Cx9cFindKey;
extern "C" {
const unsigned char *cx9c_key_data_801fff3c(Cx9cFindKey *);
int cx9c_memcmp_802eedc0(const void *,const void *,unsigned int);
}
static inline bool cx9c_record_equal(const Cx9cFindRecord *record,Cx9cFindKey *key)
{const unsigned char *data=cx9c_key_data_801fff3c(key);
 return cx9c_memcmp_802eedc0(record->key,data,16)==0;}
struct Cx9cRecordPredicate {Cx9cFindKey *key;bool operator()(const Cx9cFindRecord &r)const {return cx9c_record_equal(&r,key);}};
static inline Cx9cFindRecord *cx9c_find_if(Cx9cFindRecord *first,Cx9cFindRecord *last,Cx9cRecordPredicate equal)
{
    int groups=(last-first)>>2;
    for (;groups>0;--groups) {
        if (equal(*first)) return first;
        ++first;
        if (equal(*first)) return first;
        ++first;
        if (equal(*first)) return first;
        ++first;
        if (equal(*first)) return first;
        ++first;
    }
    switch (last-first) {
    case 3: if (equal(*first)) return first; ++first;
    case 2: if (equal(*first)) return first; ++first;
    case 1: if (equal(*first)) return first;
    case 0:
    default:return last;
    }
}

extern "C" Cx9cFindRecord *w3d_cx9c_binary_record_find_8035a990(Cx9cFindRecord *first,Cx9cFindRecord *last,Cx9cFindKey *const &key) {Cx9cRecordPredicate equal;equal.key=key;return cx9c_find_if(first,last,equal);}
