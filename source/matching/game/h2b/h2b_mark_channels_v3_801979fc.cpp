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

struct _Bit_iterator {
  typedef ptrdiff_t difference_type;
  typedef _Bit_reference  reference;
  typedef _Bit_reference* pointer;
  typedef _Bit_iterator   iterator;

  unsigned int* _M_p;
  unsigned int _M_offset;
  void bump_up() {
    if (_M_offset++ == __WORD_BIT - 1) {
      _M_offset = 0;
      ++_M_p;
    }
  }
  void bump_down() {
    if (_M_offset-- == 0) {
      _M_offset = __WORD_BIT - 1;
      --_M_p;
    }
  }

  _Bit_iterator() : _M_p(0), _M_offset(0) {}
  _Bit_iterator(unsigned int* __x, unsigned int __y) 
    : _M_p(__x), _M_offset(__y) {}
  reference operator*() const { return reference(_M_p, 1U << _M_offset); }
  iterator& operator++() {
    bump_up();
    return *this;
  }
  iterator operator++(int) {
    iterator __tmp = *this;
    bump_up();
    return __tmp;
  }
  iterator& operator--() {
    bump_down();
    return *this;
  }
  iterator operator--(int) {
    iterator __tmp = *this;
    bump_down();
    return __tmp;
  }
  iterator& operator+=(difference_type __i) {
    difference_type __n = __i + _M_offset;
    _M_p += __n / __WORD_BIT;
    __n = __n % __WORD_BIT;
    if (__n < 0) {
      _M_offset = (unsigned int) __n + __WORD_BIT;
      --_M_p;
    } else
      _M_offset = (unsigned int) __n;
    return *this;
  }
  iterator& operator-=(difference_type __i) {
    *this += -__i;
    return *this;
  }
  iterator operator+(difference_type __i) const {
    iterator __tmp = *this;
    return __tmp += __i;
  }
  iterator operator-(difference_type __i) const {
    iterator __tmp = *this;
    return __tmp -= __i;
  }
  difference_type operator-(iterator __x) const {
    return __WORD_BIT * (_M_p - __x._M_p) + _M_offset - __x._M_offset;
  }
  reference operator[](difference_type __i) { return *(*this + __i); }
  bool operator==(const iterator& __x) const {
    return _M_p == __x._M_p && _M_offset == __x._M_offset;
  }
  bool operator!=(const iterator& __x) const {
    return _M_p != __x._M_p || _M_offset != __x._M_offset;
  }
  bool operator<(iterator __x) const {
    return _M_p < __x._M_p || (_M_p == __x._M_p && _M_offset < __x._M_offset);
  }
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
extern "C" void h2b_mark_channels_v3_801979fc(ChannelOwnerView *owner) {
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
