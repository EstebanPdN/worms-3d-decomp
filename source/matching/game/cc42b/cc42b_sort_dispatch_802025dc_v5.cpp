// Observed 12-byte callback records. Sort by descending signed priority,
// preserving equal-priority order, then call every entry and clear the range.
// Object prefix and range are partial views; full class identity is unknown.
struct cc42b_Queue;
struct cc42b_Entry {
    unsigned int context;
    void (*callback)(unsigned int, cc42b_Queue *);
    int priority;
};
inline void cc42b_exchange_entries(cc42b_Entry &left, cc42b_Entry &right) {
    cc42b_Entry temp=left; left=right; right=temp;
}
struct cc42b_EntryRange {
    cc42b_Entry *first, *last;
    cc42b_Entry *begin() { return first; }
    cc42b_Entry *end() { return last; }
    int size() { return last-first; }
    cc42b_Entry &operator[](int i) { return first[i]; }
    void sort() {
        for (int count=size(); count>0; --count) {
            for (int i=0,j=1; j<count; ++i,++j) {
                cc42b_Entry &right=(*this)[j];
                cc42b_Entry &left=(*this)[i];
                if (left.priority < right.priority) {
                    cc42b_exchange_entries(right,left);
                }
            }
        }
    }
    void clear() { cc42b_Entry *start=first; for (cc42b_Entry *p=start; p!=last; ++p) {} last=start; }
};
struct cc42b_Queue { unsigned char unknown00[44]; cc42b_EntryRange entries; };
extern "C" int cc42b_sort_dispatch_802025dc(cc42b_Queue *self) {
    self->entries.sort();
    cc42b_Entry *last=self->entries.end();
    for (cc42b_Entry *p=self->entries.begin(); p!=last; ++p) p->callback(p->context,self);
    self->entries.clear();
    return 0;
}
