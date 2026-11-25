// Observed native stream word operations; class and field names are inferred.
inline unsigned swap_word(unsigned value) {
    return (value << 24) | ((value & 0xff00) << 8) |
           ((value >> 8) & 0xff00) | (value >> 24);
}
extern "C" void *fn_802eee50(void *, const void *, unsigned, ...);
struct Record { unsigned first,second,third; };
struct Records {
    Record *begin,*end,*capacity;
    void erase(Record *position) {
        if (position + 1 != end)
            fn_802eee50(position,position+1,(unsigned)end - 12 - (unsigned)position);
        --end;
    }
};
struct Flags { unsigned high:2; unsigned empty:1; unsigned rest:29; };
struct Owner { unsigned prefix[8]; Flags flags; unsigned unknown; Records records; };
extern "C" unsigned sol35d5_remove_record_801f2f8c_v2(Owner *owner, unsigned first,unsigned second) {
    Record *last=owner->records.end;
    Record *p=owner->records.begin;
    for (;p!=last;++p) {
        if (p->first==first && p->second==second) {
            owner->records.erase(p);
            owner->flags.empty=(owner->records.begin==owner->records.end);
            return 0;
        }
    }
    return 0x80004005u;
}
