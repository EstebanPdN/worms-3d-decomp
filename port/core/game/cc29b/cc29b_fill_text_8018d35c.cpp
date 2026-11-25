#include "w3d_ptr.h"
#line 1 "cc29b_fill_text_8018d35c.cpp"
// Names are inferred; native layouts are partial views of observed fields.
typedef unsigned int cc29b_u32;
struct cc29b_Header_8018d35c {cc29b_u32 tag;unsigned short kind;char unknown[18];int count;unsigned short locks;char tail[2];};
struct cc29b_Storage_8018d35c {char unknown[72];Ptr32<cc29b_Header_8018d35c> header;};
struct cc29b_Text_8018d35c {char prefix[116];Ptr32<void> resource;char gap[52];Ptr32<cc29b_Storage_8018d35c> storage;char gap2[4];Ptr32<unsigned short> first;Ptr32<unsigned short> last;char gap3[52];int mode;};
extern "C" Ptr32<void> fn_8034435c(Ptr32<void>);
extern "C" Ptr32<void> fn_801ef048(Ptr32<Ptr32<cc29b_Header_8018d35c>>,int,int,int);
inline Ptr32<void> cc29b_lock_8018d35c(Ptr32<Ptr32<cc29b_Header_8018d35c>> slot,int count){Ptr32<cc29b_Header_8018d35c> h=*slot;if(h->kind==1 && count==h->count){++h->locks;return h+1;}return fn_801ef048(slot,count,4,0);}
extern "C" Ptr32<cc29b_u32> fn_8018d4bc(Ptr32<cc29b_Text_8018d35c>,Ptr32<unsigned int>);
extern "C" int w3d_cc29b_fill_text_8018d35c(Ptr32<cc29b_Text_8018d35c> self,Ptr32<const cc29b_u32> value){
 fn_8034435c(self->resource);
 if(self->mode){unsigned int count;Ptr32<cc29b_u32> data=fn_8018d4bc(self,&count);for(unsigned int i=0;i<count;++i)*data++=*value;return 0;}
 else{Ptr32<cc29b_u32> data=(Ptr32<cc29b_u32>)cc29b_lock_8018d35c(&self->storage->header,1);*data=*value;return 0;}
}


