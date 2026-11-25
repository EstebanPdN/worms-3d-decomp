#include "w3d_ptr.h"
#line 1 "cx9c_link_record_range.cpp"
/* Observed PPC32: 36-byte records with halfword active/next +8/+10 and
 * index +20. Owner record pointer +0 and a halfword index table at +8.
 * The reference-returning min retains the original two stack temporaries. */
struct Cx9cRecord {unsigned int opaque[2];unsigned short active,next;unsigned int rest[2],index,tail[3];};
struct Cx9cOwner {Ptr32<Cx9cRecord> records;unsigned int unknown;unsigned short heads[1];};
static inline const int &cx9c_min(const int &a,const int &b) {return b<a?b:a;}
extern "C" void w3d_cx9c_link_record_range_8034aa64(Ptr32<Cx9cOwner> self,unsigned int head,unsigned short first,unsigned int last) {
 self->heads[head]=(unsigned short)first;
 for(unsigned short current=first;current<last;++current) {
  int following=current+1,final=last-1;
  self->records[current].next=(unsigned short)cx9c_min(following,final);
  self->records[current].active=1;
  self->records[current].index=current;
 }
}


