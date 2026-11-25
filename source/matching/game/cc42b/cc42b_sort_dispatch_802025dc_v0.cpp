// Observed 12-byte callback records. Sort by descending signed priority,
// preserving equal-priority order, then call every entry and clear the range.
// Object prefix and range are partial views; full class identity is unknown.
struct cc42b_Queue;
struct cc42b_Entry {
    unsigned int context;
    void (*callback)(unsigned int, cc42b_Queue *);
    int priority;
};
struct cc42b_EntryRange {
    cc42b_Entry *first, *last;
    cc42b_Entry *begin() { return first; }
    cc42b_Entry *end() { return last; }
    int size() { return last-first; }
    void clear() { for (cc42b_Entry *p=first; p!=last; ++p) {} last=first; }
};
struct cc42b_Queue { unsigned char unknown00[44]; cc42b_EntryRange entries; };
extern "C" int cc42b_sort_dispatch_802025dc(cc42b_Queue *self) {
    for (int count=self->entries.size(); count>0; --count) {
        for (int i=0; i<count-1; ++i) {
            if (self->entries.first[i].priority < self->entries.first[i+1].priority) {
                cc42b_Entry temp=self->entries.first[i+1];
                self->entries.first[i+1]=self->entries.first[i];
                self->entries.first[i]=temp;
            }
        }
    }
    cc42b_Entry *last=self->entries.end();
    for (cc42b_Entry *p=self->entries.begin(); p!=last; ++p) p->callback(p->context,self);
    self->entries.clear();
    return 0;
}
