// Packed-bit iterator and proxy lifetimes reconstructed from the original
// copies, increments and signed division. External object views are never
// constructed locally. These iterators contain exactly a word pointer and bit.
struct BitReference {
    unsigned *word; unsigned mask;
    BitReference(unsigned *p, unsigned m):word(p),mask(m) {}
    BitReference& operator=(bool value) {
        if(value) *word |= mask; else *word &= ~mask;
        return *this;
    }
};
struct BitIterator {
    unsigned *word; unsigned bit;
    BitIterator() {}
    BitIterator(const BitIterator& other):word(other.word),bit(other.bit) {}
    BitIterator(unsigned *p,unsigned b):word(p),bit(b) {}
    BitReference operator*() const { return BitReference(word,1U << bit); }
    BitIterator& operator++() {
        if (++bit == 32) {bit=0; ++word;} return *this;
    }
    BitIterator operator++(int) {BitIterator old=*this; ++*this; return old;}
    BitIterator& operator+=(int offset) {
        int n=offset+bit;
        word+=n/32;
        n=n%32;
        if(n<0){bit=n+32; --word;}else bit=n;
        return *this;
    }
    BitIterator operator+(int offset) const {BitIterator copy=*this;return copy+=offset;}
    BitReference operator[](int offset) const {return *(*this+offset);}
};
inline bool operator!=(const BitIterator& a,const BitIterator& b) {return a.word!=b.word || a.bit!=b.bit;}
struct Record {int key; unsigned unknown[2];};
struct Group {Record *begin,*end; unsigned unknown[2];};
struct ChannelDataView {unsigned unknown[13]; Group *groups;};
struct ChannelOwnerView {
    unsigned unknown0[10]; Record *begin,*end;
    unsigned unknown30[6]; ChannelDataView *data;
    unsigned unknown4c[5]; BitIterator first,last;
    unsigned unknown70[2]; unsigned dirty;
    BitIterator beginBits() const {return first;}
    BitIterator endBits() const {return last;}
    BitReference bitAt(int n) {return *(beginBits()+n);}
};
extern "C" void h2b_mark_channels_v1_801979fc(ChannelOwnerView *owner) {
    BitIterator start=owner->beginBits(), end=owner->endBits();
    while(end!=start) *start++=false;
    Record *record=owner->begin,*last=owner->end;
    Group *group=owner->data->groups;
    while(record!=last) {
        Record *current=record; ++record;
        Group *selected=group; ++group;
        if(current->key) {
            Record *stop=selected->end;
            for(Record *entry=selected->begin;entry!=stop;++entry) {
                if(entry->key<0) owner->bitAt((unsigned short)entry->key)=true;
            }
        }
    }
    owner->dirty=0;
}
