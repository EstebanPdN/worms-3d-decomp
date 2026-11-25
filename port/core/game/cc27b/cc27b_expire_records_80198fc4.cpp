#include "w3d_ptr.h"
#line 1 "cc27b_expire_records_80198fc4.cpp"
// Observed 24-byte records; payload meanings and original type names remain unknown.
struct cc27b_TimedRecord {float time;unsigned int payload[5];};
struct cc27b_RecordRange {
 Ptr32<cc27b_TimedRecord> first; Ptr32<cc27b_TimedRecord> last; Ptr32<cc27b_TimedRecord> capacity;
 Ptr32<cc27b_TimedRecord> begin(){return first;} Ptr32<cc27b_TimedRecord> end(){return last;}
 Ptr32<cc27b_TimedRecord> erase(Ptr32<cc27b_TimedRecord> p){
  if(p+1!=last){Ptr32<cc27b_TimedRecord> src=p+1;Ptr32<cc27b_TimedRecord> dest=p;int count=last-src;for(;count>0;--count,++src,++dest)*dest=*src;}
  --last;return p;
 }
};
struct cc27b_TimedOwner {char prefix[24];float time;char gap[20];cc27b_RecordRange records;};
extern "C" void fn_8019a30c(Ptr32<cc27b_TimedOwner>,Ptr32<cc27b_TimedRecord>);
extern "C" void w3d_cc27b_expire_records_80198fc4(Ptr32<cc27b_TimedOwner> self){
 Ptr32<cc27b_TimedRecord> p=self->records.begin();
 while(p!=self->records.end()){
  if(p->time<=self->time){fn_8019a30c(self,p);p=self->records.erase(p);}else ++p;
 }
}


