/*
 *
 * Copyright (c) 1994
 * Hewlett-Packard Company
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.  Hewlett-Packard Company makes no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied warranty.
 *
 *
 * Copyright (c) 1996,1997
 * Silicon Graphics Computer Systems, Inc.
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.  Silicon Graphics makes no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied warranty.
 */

// Iterator/proxy definitions from the preserved GCC 2.95.3 SGI STL.
// Empty random-access base carries only the iterator difference type.
typedef int ptrdiff_t;
template<class T,class D> struct random_access_iterator {typedef D difference_type;};
static const int __WORD_BIT=32;
struct _Bit_reference {
  unsigned int* _M_p;
  unsigned int _M_mask;
  _Bit_reference(unsigned int* __x, unsigned int __y) 
    : _M_p(__x), _M_mask(__y) {}

public:
  _Bit_reference() : _M_p(0), _M_mask(0) {}
  operator bool() const { return !(!(*_M_p & _M_mask)); }
  _Bit_reference& operator=(bool __x)
  {
    if (__x)  *_M_p |= _M_mask;
    else      *_M_p &= ~_M_mask;
    return *this;
  }
  _Bit_reference& operator=(const _Bit_reference& __x) 
    { return *this = bool(__x); }
  bool operator==(const _Bit_reference& __x) const
    { return bool(*this) == bool(__x); }
  bool operator<(const _Bit_reference& __x) const {
    return !bool(*this) && bool(__x);
  }
  void flip() { *_M_p ^= _M_mask; }
};

inline void swap(_Bit_reference __x, _Bit_reference __y)
{
  bool __tmp = __x;
  __x = __y;
  __y = __tmp;
}

struct BitIteratorBase {
  unsigned *word; unsigned bit;
  BitIteratorBase(unsigned *p,unsigned b):word(p),bit(b) {}
  void bump_up() {if(++bit==32) {bit=0;++word;}}
  void advance(int i) {
    int n=i+bit;
    word+=n/32; n%=32;
    if(n<0){bit=n+32;--word;}else bit=n;
  }
};
struct _Bit_iterator : BitIteratorBase {
  _Bit_iterator():BitIteratorBase(0,0) {}
  _Bit_iterator(unsigned *p,unsigned b):BitIteratorBase(p,b) {}
  _Bit_reference operator*() const {return _Bit_reference(word,1U<<bit);}
  _Bit_iterator& operator++(){bump_up();return *this;}
  _Bit_iterator operator++(int){_Bit_iterator old=*this;bump_up();return old;}
  _Bit_iterator& operator+=(int n){advance(n);return *this;}
  _Bit_iterator operator+(int n) const {_Bit_iterator old=*this;return old+=n;}
  bool operator!=(const _Bit_iterator& rhs) const {return word!=rhs.word || bit!=rhs.bit;}
};
typedef _Bit_iterator BitIterator;
typedef _Bit_reference BitReference;
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
inline void clear_bits(BitIterator start,BitIterator end) {while(end!=start) *start++=false;}
extern "C" void h2b_mark_channels_v5_801979fc(ChannelOwnerView *owner) {
    clear_bits(owner->beginBits(),owner->endBits());
    Record *record=owner->begin,*last=owner->end;
    Group *group=owner->data->groups;
    while(record!=last) {
        Record *current=record; Record *next=record+1;
        Group *selected=group; Group *nextGroup=group+1;
        if(current->key) {
            Record *stop=selected->end;
            for(Record *entry=selected->begin;entry!=stop;++entry) {
                if(entry->key<0) owner->bitAt((unsigned short)entry->key)=true;
            }
        }
        record=next; group=nextGroup;
    }
    owner->dirty=0;
}
