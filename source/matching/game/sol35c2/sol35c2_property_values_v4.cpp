// GC32 array header offsets are witnessed by original property accessors.
struct Header { unsigned int unknown0; unsigned short shared; unsigned char unknown6[18]; unsigned int count; unsigned short locks; unsigned char unknown30[2]; };
extern "C" void *fn_801ef048(Header **,unsigned int,unsigned int,int);
struct Array { Header *header;
 unsigned int size() const { return header->count; }
 void *lock(const unsigned int &size, int mode) {
  Header *h = header;
  if(h->shared == 1 && ((mode & 2) || size == h->count)) {
   ++h->locks;
   return h + 1;
  }
  return fn_801ef048(&header,size,4,mode);
 }
};
struct Block { unsigned char unknown0[88]; Array values; unsigned int unknown92; Array fallback; };
struct Link { unsigned char unknown0[48]; Block *block; };
struct Owner { unsigned char unknown0[168]; Link *link; };
extern "C" void *sol35c2_property_values_80189574(Owner *self) {
 Block *block = self->link->block;
 unsigned int count = block->values.size();
 void *data = block->values.lock(count,2);
 if(!count) {
  unsigned int fallback = block->fallback.size();
  if(!fallback) return 0;
  data = block->values.lock(fallback,0);
 }
 return data;
}
