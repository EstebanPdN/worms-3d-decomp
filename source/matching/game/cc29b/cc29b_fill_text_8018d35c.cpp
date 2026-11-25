// Names are inferred; native layouts are partial views of observed fields.
typedef unsigned int cc29b_u32;
struct cc29b_Header_8018d35c {cc29b_u32 tag;unsigned short kind;char unknown[18];int count;unsigned short locks;char tail[2];};
struct cc29b_Storage_8018d35c {char unknown[72];cc29b_Header_8018d35c* header;};
struct cc29b_Text_8018d35c {char prefix[116];void* resource;char gap[52];cc29b_Storage_8018d35c* storage;char gap2[4];unsigned short* first;unsigned short* last;char gap3[52];int mode;};
extern "C" void * fn_8034435c(void*);
extern "C" void* fn_801ef048(cc29b_Header_8018d35c**,int,int,int);
inline void* cc29b_lock_8018d35c(cc29b_Header_8018d35c** slot,int count){cc29b_Header_8018d35c* h=*slot;if(h->kind==1 && count==h->count){++h->locks;return h+1;}return fn_801ef048(slot,count,4,0);}
extern "C" cc29b_u32* fn_8018d4bc(cc29b_Text_8018d35c*,unsigned int*);
extern "C" int w3d_cc29b_fill_text_8018d35c(cc29b_Text_8018d35c* self,const cc29b_u32* value){
 fn_8034435c(self->resource);
 if(self->mode){unsigned int count;cc29b_u32* data=fn_8018d4bc(self,&count);for(unsigned int i=0;i<count;++i)*data++=*value;return 0;}
 else{cc29b_u32* data=(cc29b_u32*)cc29b_lock_8018d35c(&self->storage->header,1);*data=*value;return 0;}
}
