// Original GameCube PAL body; semantic names inferred. Layouts are observed source views.
typedef unsigned int cc29b_u32;
struct cc29b_Header_8018d4bc {cc29b_u32 tag;unsigned short kind;char unknown[18];int count;unsigned short locks;char tail[2];};
struct cc29b_Storage_8018d4bc {char unknown[72];cc29b_Header_8018d4bc* header;};
struct cc29b_Text_8018d4bc {char prefix[116];void* resource;char gap[52];cc29b_Storage_8018d4bc* storage;char gap2[4];unsigned short* first;unsigned short* last;char gap3[52];int mode;};
extern "C" void * fn_8034435c(void*);
extern "C" void* fn_801ef048(cc29b_Header_8018d4bc**,int,int,int);
inline void* cc29b_lock_8018d4bc(cc29b_Header_8018d4bc** slot,int count){cc29b_Header_8018d4bc* h=*slot;if(h->kind==1 && count==h->count){++h->locks;return h+1;}return fn_801ef048(slot,count,4,0);}
extern "C" void* w3d_cc29b_lock_text_8018d4bc(cc29b_Text_8018d4bc* self,int* count){
 *count=self->last-self->first;fn_8034435c(self->resource);
 if(self->mode){void* data=cc29b_lock_8018d4bc(&self->storage->header,*count*2);return (char*)data+*count*4;}
 return cc29b_lock_8018d4bc(&self->storage->header,*count);
}
