
// Inferred native land setup; offsets and call sequence verified against the DOL.
typedef unsigned int cc35a_u32;
struct cc35a_Land_800a51f8 { char reserved[20]; cc35a_u32 route; char gap[4]; const char* file; };
extern "C" {
extern char cc35a_type_8040f818[],cc35a_type_8040f7c8[],cc35a_type_80410680[],cc35a_type_8040fb28[],cc35a_type_80410d70[];
extern const char cc35a_text_80381004[],cc35a_text_80381014[],cc35a_text_80381020[];
extern cc35a_u32 cc35a_cache_804ae240[2],cc35a_cache_804ae248[2];
extern void *cc35a_service_804b178c,*cc35a_arena_804b1754;
cc35a_u32 cc35a_type_8020b680(void*);
int cc35a_route_80164514(void*,void *,cc35a_u32);
int cc35a_property_800fc2b0(const char**,const char**);
void *cc35a_alloc_801613f0(void*,unsigned int);
unsigned int cc35a_id_8015f5a0(void*,int);
void *cc35a_message_8010a8e0(void*,unsigned short,const char*);
void cc35a_send_8015fc58(void*,void*);
void cc35a_format_8020c510(const char**,const char*,...);
void cc35a_finish_800a5390(void*);
}
extern "C" void cc35a_land_setup_800a51f8(cc35a_Land_800a51f8* self) {
 { cc35a_u32 type=cc35a_type_8020b680(cc35a_type_8040f818); cc35a_route_80164514(cc35a_service_804b178c,(void *)type,self->route); }
 { cc35a_u32 type=cc35a_type_8020b680(cc35a_type_8040f7c8); cc35a_route_80164514(cc35a_service_804b178c,(void *)type,self->route); }
 const char* name=cc35a_text_80381004; const char* materials=0;
 cc35a_property_800fc2b0(&name,&materials);
 void* message=cc35a_alloc_801613f0(cc35a_arena_804b1754,12);
 unsigned short id=cc35a_id_8015f5a0(cc35a_cache_804ae240,1);
 cc35a_send_8015fc58(self,cc35a_message_8010a8e0(message,id,materials));
 const char* filename=0; const char* filekey=cc35a_text_80381014;
 cc35a_property_800fc2b0(&filekey,&filename);
 if(filename && *filename) cc35a_format_8020c510(&self->file,cc35a_text_80381020,filename);
 void* secondMessage=cc35a_alloc_801613f0(cc35a_arena_804b1754,12);
 unsigned short secondId=cc35a_id_8015f5a0(cc35a_cache_804ae248,1);
 cc35a_send_8015fc58(self,cc35a_message_8010a8e0(secondMessage,secondId,self->file));
 { cc35a_u32 type=cc35a_type_8020b680(cc35a_type_80410680); cc35a_route_80164514(cc35a_service_804b178c,(void *)type,self->route); }
 { cc35a_u32 type=cc35a_type_8020b680(cc35a_type_8040fb28); cc35a_route_80164514(cc35a_service_804b178c,(void *)type,self->route); }
 { cc35a_u32 type=cc35a_type_8020b680(cc35a_type_80410d70); cc35a_route_80164514(cc35a_service_804b178c,(void *)type,self->route); }
 cc35a_finish_800a5390(self);
}
