// Structural types/names inferred from original offsets. Descriptor labels are original external data.
typedef unsigned int cc28b_u32;
struct cc28b_MapEntry_8018b88c {unsigned short unicode,mapped,index;};
struct cc28b_Owner_8018b88c {char prefix[32];void* group;char gap[32];cc28b_MapEntry_8018b88c* map;cc28b_u32 count;};
struct cc28b_Writer_8018b88c {void **vtable;};
extern "C" int fn_801904c0(cc28b_Owner_8018b88c*,cc28b_Writer_8018b88c*);
extern "C" char lbl_803a7db4[],lbl_803a7dc0[],lbl_803a7dcc[],lbl_803a7dd4[],lbl_803a7de0[];
inline int cc28b_write_group_8018b88c(cc28b_Writer_8018b88c* w,void* v,char* name){return ((int(*)(cc28b_Writer_8018b88c*,void*,char*))w->vtable[8])(w,v,name);}
inline int cc28b_write_count_8018b88c(cc28b_Writer_8018b88c* w,cc28b_u32 v,char* name,int zero){return ((int(*)(cc28b_Writer_8018b88c*,cc28b_u32,char*,int))w->vtable[21])(w,v,name,zero);}
inline int cc28b_write_short_8018b88c(cc28b_Writer_8018b88c* w,unsigned short v,char* name,int zero){return ((int(*)(cc28b_Writer_8018b88c*,unsigned short,char*,int))w->vtable[17])(w,v,name,zero);}
extern "C" int w3d_cc28b_describe_map_8018b88c(cc28b_Owner_8018b88c* self,cc28b_Writer_8018b88c* writer){
 int result=fn_801904c0(self,writer);
 if(result>=0){
  unsigned int i=0;
  cc28b_write_group_8018b88c(writer,self->group,lbl_803a7db4);
  cc28b_write_count_8018b88c(writer,self->count,lbl_803a7dc0,0);
  cc28b_MapEntry_8018b88c* p=self->map;
  for(;i<self->count;++i,++p){
   cc28b_write_short_8018b88c(writer,p->index,lbl_803a7dcc,0);
   cc28b_write_short_8018b88c(writer,p->mapped,lbl_803a7dd4,0);
   cc28b_write_short_8018b88c(writer,p->unicode,lbl_803a7de0,0);
  }
  result=0;
 }
 return result;
}
