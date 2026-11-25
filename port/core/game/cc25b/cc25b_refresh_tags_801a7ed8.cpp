#include "w3d_ptr.h"
#line 1 "cc25b_refresh_tags_801a7ed8.cpp"
typedef unsigned int cc25b_u32;
typedef unsigned short cc25b_u16;
extern cc25b_u32 cc25b_global_80363c14[];
extern cc25b_u32 cc25b_global_80363c64[];
struct cc25b_TagRecord {
 unsigned char prefix[6]; cc25b_u16 tag; unsigned char rest[76];
 bool setTag(const cc25b_u32 &value) {
  if(tag==(cc25b_u16)value) return false;
  tag=(cc25b_u16)value; return true;
 }
};
struct cc25b_TagOwner {
 unsigned char prefix[180];
 Ptr32<Ptr32<cc25b_TagRecord>> first; Ptr32<Ptr32<cc25b_TagRecord>> last;
 unsigned char gap[16];
 Ptr32<Ptr32<cc25b_TagRecord>> secondFirst; Ptr32<Ptr32<cc25b_TagRecord>> secondLast;
};
extern "C" void w3d_cc25b_refresh_tags_801a7ed8(Ptr32<cc25b_TagOwner> self) {
 cc25b_u32 firstTag=cc25b_global_80363c14[0]>>22;
 Ptr32<Ptr32<cc25b_TagRecord>> end=self->last;
 for(Ptr32<Ptr32<cc25b_TagRecord>> it=self->first;it!=end;++it) {
  Ptr32<cc25b_TagRecord> p=*it;
  Ptr32<cc25b_TagRecord> last=p+511;
  do {
   if(!p->setTag(firstTag)) goto second;
   ++p;
  } while(p<=last);
 }
second:
 cc25b_u32 secondTag=cc25b_global_80363c64[0]>>22;
Ptr32<Ptr32<cc25b_TagRecord>> it2=self->secondFirst;
Ptr32<Ptr32<cc25b_TagRecord>> end2=self->secondLast;
 for(;it2!=end2;++it2) {
  Ptr32<cc25b_TagRecord> p=*it2;
  int count=32;
  do {
   if(!p->setTag(secondTag)) return;
   ++p;
  } while(--count);
 }
}


