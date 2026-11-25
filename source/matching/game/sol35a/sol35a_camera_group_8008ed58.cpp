// Original entry 0x8008ed58, 296 bytes. PPC32 layout offsets are observed; names inferred.
// Apply each selected camera resource and its instance callback, then finish the group.
// Empty groups use the explicit single-entry flag. Return whether any instance has a nonzero u16 at +104.
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
#define VCALL(p,T,o) ((T)(*(void **)(*(char **)(p)+(o))))
struct Sol35aCameraEntry {void *resource,*instance;};extern void *sol35a_world_804ae5e4;extern "C" void sol35a_apply_80091970(void *,void *),sol35a_finish_8007bc2c(void *,void *);
extern "C" int sol35a_camera_group_8008ed58(void *self,Sol35aCameraEntry *entry){
 int active=0;void *indices=FIELD(entry->resource,void *,0x1d8);unsigned count=FIELD(indices,unsigned,0x18);unsigned short *begin=(unsigned short *)((char *)indices+32);
 if(count){FIELD(self,int,0x9b0)=1;void **objects=(void **)(FIELD(sol35a_world_804ae5e4,char *,0x2c)+32);for(unsigned i=0;i<count;++i){sol35a_apply_80091970(self,objects[begin[i]]);void *instance=FIELD(FIELD(objects[begin[i]],void *,0x2c),void *,32);((void (*)(void *,void *))FIELD(FIELD(self,void *,0xae8),void *,8))(self,instance);if(FIELD(instance,unsigned short,0x68))active=1;}sol35a_finish_8007bc2c(self,entry->resource);}else{if(FIELD(entry->resource,unsigned char,0x1c3)){FIELD(self,int,0x9b0)=0;sol35a_apply_80091970(self,entry->resource);((void (*)(void *,void *))FIELD(FIELD(self,void *,0xae8),void *,8))(self,entry->instance);if(FIELD(entry->instance,unsigned short,0x68))active=1;}}return active;
}
