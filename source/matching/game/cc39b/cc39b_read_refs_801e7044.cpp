// Partial interfaces: only the observed virtual release/read slots are typed.
// The leading argument is unused in the original; errors exit before replacement.
typedef unsigned int cc39b_u32;
struct cc39b_Ref;
struct cc39b_RefTable { void (*slots[4])();void (*release)(cc39b_Ref *); };
struct cc39b_Ref { cc39b_RefTable *vtable; };
struct cc39b_Reader;
struct cc39b_ReaderTable { void (*slots[8])();int (*read)(cc39b_Reader *,cc39b_Ref **,cc39b_u32); };
struct cc39b_Reader { cc39b_ReaderTable *vtable; };
extern "C" int cc39b_read_refs_801e7044(void *,cc39b_Reader *reader,cc39b_Ref **items,cc39b_u32 mode,cc39b_u32 count) {
 for(cc39b_u32 i=0;i<count;++i) {
  cc39b_Ref *incoming=0;
  int result=reader->vtable->read(reader,&incoming,mode);
  if(result<0) return result;
  if(items[i]) items[i]->vtable->release(items[i]);
  items[i]=incoming;
 }
 return 0;
}
