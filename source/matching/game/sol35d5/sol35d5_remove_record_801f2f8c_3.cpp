// Inferred pair-key record collection, based on the complete original 184-byte body.
// GC32 address arithmetic follows the native byte-copy count. The external
// transfer at 802eee50 must support the original downward overlapping ranges;
// allocation ownership, object lifetime and cross-boundary aliasing stay external.
// The flag position is observed; its semantic name and complete classes are hypotheses.
extern "C" void *fn_802eee50(void *, const void *, unsigned, ...);
struct Record { unsigned first,second,third; };
struct Records {
    Record *begin,*end,*capacity;
    bool erase(Record *position) {
        if (position + 1 != end)
            fn_802eee50(position,position+1,(unsigned)end + (-12 - (unsigned)position));
        --end;
        return begin == end;
    }
};
struct Flags { unsigned high:2; unsigned empty:1; unsigned rest:29; };
struct Owner { unsigned prefix[8]; Flags flags; unsigned unknown; Records records; };
extern "C" unsigned sol35d5_remove_record_801f2f8c_3(Owner *owner, unsigned first,unsigned second) {
    Record *last=owner->records.end;
    Record *p=owner->records.begin;
    for (;p!=last;++p) {
        if (p->first==first && p->second==second) {
            owner->flags.empty=owner->records.erase(p);
            return 0;
        }
    }
    return 0x80004005u;
}
typedef char RecordSize[sizeof(Record)==12?1:-1];
typedef char BeginOffset[(unsigned)&((Owner*)0)->records.begin==40?1:-1];
typedef char EndOffset[(unsigned)&((Owner*)0)->records.end==44?1:-1];
typedef char FlagOffset[(unsigned)&((Owner*)0)->flags==32?1:-1];
