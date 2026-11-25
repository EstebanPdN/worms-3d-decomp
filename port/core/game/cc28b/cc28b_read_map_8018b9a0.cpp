#include "w3d_ptr.h"
#line 1 "cc28b_read_map_8018b9a0.cpp"
// Structural names are inferred. Native handle is a sufficient reconstruction model,
// not recovery of the original declaration/sizeof. Observed pointer slot is stack8.
// Group retain/release and descriptor field order are preserved from original DOL.
typedef unsigned int cc28b_u32;
struct cc28b_Object_8018b9a0 {Ptr32<Ptr32<void>> vtable;};
inline void cc28b_retain_8018b9a0(Ptr32<cc28b_Object_8018b9a0> p){((Ptr32<void (Ptr32<cc28b_Object_8018b9a0>)>)p->vtable[3])(p);}
inline void cc28b_release_8018b9a0(Ptr32<cc28b_Object_8018b9a0> p){((Ptr32<void (Ptr32<cc28b_Object_8018b9a0>)>)p->vtable[4])(p);}
struct cc28b_Handle_8018b9a0 {Ptr32<cc28b_Object_8018b9a0> object;cc28b_Handle_8018b9a0():object(0){}~cc28b_Handle_8018b9a0(){if(object)cc28b_release_8018b9a0(object);}};
struct cc28b_MapEntry_8018b9a0 {unsigned short unicode,mapped,index;};
struct cc28b_Owner_8018b9a0 {char prefix[32];Ptr32<cc28b_Object_8018b9a0> group;char gap[32];Ptr32<cc28b_MapEntry_8018b9a0> map;cc28b_u32 count;};
struct cc28b_Reader_8018b9a0 {Ptr32<Ptr32<void>> vtable;};
extern "C" int fn_80190538(Ptr32<cc28b_Owner_8018b9a0>,Ptr32<cc28b_Reader_8018b9a0>);
extern "C" char lbl_803a7db4[],lbl_803a7dc0[],lbl_803a7dcc[],lbl_803a7dd4[],lbl_803a7de0[];
extern "C" void fn_801fe240(Ptr32<void>);
extern "C" Ptr32<void> fn_801fe220(unsigned int);
inline int cc28b_read_group_8018b9a0(Ptr32<cc28b_Reader_8018b9a0> r,Ptr32<cc28b_Handle_8018b9a0> h,Ptr32<char> name){return ((Ptr32<int (Ptr32<cc28b_Reader_8018b9a0>, Ptr32<cc28b_Handle_8018b9a0>, Ptr32<char>)>)r->vtable[8])(r,h,name);}
inline int cc28b_read_count_8018b9a0(Ptr32<cc28b_Reader_8018b9a0> r,Ptr32<cc28b_u32> n,Ptr32<char> name){return ((Ptr32<int (Ptr32<cc28b_Reader_8018b9a0>, Ptr32<cc28b_u32>, Ptr32<char>)>)r->vtable[32])(r,n,name);}
inline int cc28b_read_short_8018b9a0(Ptr32<cc28b_Reader_8018b9a0> r,Ptr32<unsigned short> v,Ptr32<char> name){return ((Ptr32<int (Ptr32<cc28b_Reader_8018b9a0>, Ptr32<unsigned short>, Ptr32<char>)>)r->vtable[30])(r,v,name);}
extern "C" int w3d_cc28b_read_map_8018b9a0(Ptr32<cc28b_Owner_8018b9a0> self,Ptr32<cc28b_Reader_8018b9a0> reader){
 int result=fn_80190538(self,reader);
 if(result>=0){{
  cc28b_Handle_8018b9a0 handle;
  cc28b_read_group_8018b9a0(reader,&handle,lbl_803a7db4);
  cc28b_read_count_8018b9a0(reader,&self->count,lbl_803a7dc0);
  Ptr32<cc28b_Object_8018b9a0> p=handle.object;if(p)cc28b_retain_8018b9a0(p);if(self->group)cc28b_release_8018b9a0(self->group);self->group=p;
  if(self->map)fn_801fe240(self->map);
  self->map=(Ptr32<cc28b_MapEntry_8018b9a0>)fn_801fe220(self->count*6);Ptr32<cc28b_MapEntry_8018b9a0> entry=self->map;
  for(unsigned int i=0;i<self->count;++i,++entry){
   cc28b_read_short_8018b9a0(reader,&entry->index,lbl_803a7dcc);
   cc28b_read_short_8018b9a0(reader,&entry->mapped,lbl_803a7dd4);
   cc28b_read_short_8018b9a0(reader,&entry->unicode,lbl_803a7de0);
  }
  }result=0;
 }
 return result;
}


