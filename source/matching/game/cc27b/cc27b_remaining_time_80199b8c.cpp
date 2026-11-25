// Observed two 24-byte interval ranges; semantic names are inferred.
// Keep the reference-returning comparison: its ProDG branch tree is proved.
struct cc27b_Interval {float start,end;unsigned int payload[3],flags;};
struct cc27b_Intervals {cc27b_Interval *first,*last,*capacity;unsigned int reserved;cc27b_Interval* begin(){return first;}cc27b_Interval* end(){return last;}};
struct cc27b_IntervalOwner {char prefix[24];float time;unsigned int reserved;cc27b_Intervals active,pending;};
inline const float& cc27b_maximum(const float& a,const float& b){return a<b?b:a;}
extern "C" int w3d_cc27b_remaining_time_80199b8c(cc27b_IntervalOwner* self,float* result){
 cc27b_Interval* p=self->active.begin();
 *result=self->time;
 for(;p!=self->active.end();++p){
  *result=cc27b_maximum(*result,p->end);
  if(p->flags&0x8000){*result-=self->time;return 0;}
 }
 for(p=self->pending.begin();p!=self->pending.end();++p){
  *result=cc27b_maximum(*result,p->end);
  if(p->flags&0x8000){*result-=self->time;return 0;}
 }
 *result-=self->time;return 1;
}
