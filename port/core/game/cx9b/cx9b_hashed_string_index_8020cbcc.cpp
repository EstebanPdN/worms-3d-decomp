#include "w3d_ptr.h"
#line 1 "cx9b_hashed_string_index_8020cbcc.cpp"

struct Entry { Ptr32<const char> text; unsigned short value; unsigned short next; };
struct StringIndex { Ptr32<unsigned short> buckets; unsigned int mask; unsigned int count; Ptr32<Entry> entries; };
extern "C" int compare_802ef234(Ptr32<const char>,Ptr32<const char>);
extern "C" int w3d_cx9b_hashed_string_index_8020cbcc(Ptr32<StringIndex> self,Ptr32<const char> text,Ptr32<unsigned short> result) {
 Ptr32<const unsigned char> cursor=(Ptr32<const unsigned char>)text;
 unsigned int hash=5381;
 unsigned int byte=*cursor++;
 while(byte) {hash=((hash<<5)+hash)^byte;byte=*cursor++;}
 unsigned int link=self->buckets[hash&self->mask];
 while(link) {
  unsigned int index=link-1;
  Ptr32<Entry> entry=(Ptr32<Entry>)((Ptr32<unsigned char>)self->entries+(index<<3));
  if(compare_802ef234(entry->text,text)==0) { *result=entry->value;return 0; }
  link=entry->next;
 }
 return (int)0x80004005;
}




