// Structural names are inferred. Records have observed24-byte stride, id16/state20.
// Bit ranges have observed16-byte stride. Allocation extents and payload semantics are unknown.
typedef unsigned int cc28b_u32;
struct cc28b_Record_801998d8 { cc28b_u32 payload[4];unsigned short id;unsigned short unknown;unsigned short state;unsigned short tail;};
struct cc28b_RecordRange_801998d8 {cc28b_Record_801998d8 *first,*last,*capacity; cc28b_Record_801998d8* begin(){return first;} cc28b_Record_801998d8* end(){return last;}};
struct cc28b_Bits_801998d8 {cc28b_u32 *first,*last,*capacity;cc28b_u32 unknown;
 bool intersects(const cc28b_Bits_801998d8& other)const {cc28b_u32* p=first;cc28b_u32* q=other.first;for(;p!=last;++p,++q){if((*p&*q)!=0)return true;}return false;}
};
struct cc28b_Service_801998d8 {void **vtable;};
struct cc28b_Owner_801998d8 {char prefix[20];cc28b_Service_801998d8* service;char gap[8];cc28b_RecordRange_801998d8 records;char gap2[24];cc28b_Bits_801998d8* masks; cc28b_Bits_801998d8& mask(unsigned int id){return *(cc28b_Bits_801998d8*)((char*)masks+(id<<4));}};
extern "C" float lbl_803a86e8[],lbl_803a86ec[];
inline float* cc28b_weight_801998d8(cc28b_Service_801998d8* s,unsigned int id){return ((float*(*)(cc28b_Service_801998d8*,unsigned int))s->vtable[15])(s,id);}
inline void cc28b_set_801998d8(cc28b_Service_801998d8* s,unsigned int id,float v){((void(*)(cc28b_Service_801998d8*,unsigned int,float))s->vtable[16])(s,id,v);}
extern "C" void w3d_cc28b_normalize_801998d8(cc28b_Owner_801998d8* self){
 cc28b_Record_801998d8* p=self->records.begin();
 while(p!=self->records.end()){
  cc28b_Record_801998d8* next;
  if(p->state==1){
   float sum=lbl_803a86e8[0];
   cc28b_Record_801998d8* q=self->records.begin();
   while(q!=self->records.end()){
    cc28b_Record_801998d8* qnext;
    if(p!=q && self->mask(p->id).intersects(self->mask(q->id))){q->state=2;sum+=*cc28b_weight_801998d8(self->service,q->id);}
    qnext=q+1;q=qnext;
   }
   float own=*cc28b_weight_801998d8(self->service,p->id);
   float remainder=lbl_803a86ec[0]-own;
   if(sum!=lbl_803a86e8[0]){
    float ratio=remainder/sum;
    q=self->records.begin();
    while(q!=self->records.end()){
     cc28b_Record_801998d8* qnext;
     if(p!=q && self->mask(p->id).intersects(self->mask(q->id))){
      float v=*cc28b_weight_801998d8(self->service,q->id);
      cc28b_set_801998d8(self->service,q->id,ratio*v);
     }
     qnext=q+1;q=qnext;
    }
   }
  }
  next=p+1; p=next;
 }
}
