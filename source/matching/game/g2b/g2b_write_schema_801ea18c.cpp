// Partial external ABI views; no external objects are locally constructed.
struct Writer {void**table;};
struct Header {unsigned unknown;unsigned short unknown4;unsigned char kind,flags;};
struct Object {void**table;Header header;};
struct Type {void**table;unsigned unknown[4];Type*next;unsigned unknown24[6];void**fields;};
extern char tag_803b0a1c[],key_803b0a24[],key_803b0a28[],key_803b0a38[],key_803b0a44[];
extern Type sentinel_80365788[];
extern "C" int fn_801eb0b0(void*,Writer*,Object*);
inline int writeByte(Writer*w,unsigned value,const char*key,bool omitted){return ((int(*)(Writer*,unsigned,const char*,bool))w->table[13])(w,value,key,omitted);}
extern "C" int g2b_write_schema_801ea18c(Object*self,Writer*writer){
 ((int(*)(Writer*,const char*,int,const char*))writer->table[39])(writer,tag_803b0a1c,4,key_803b0a24);
 unsigned flags=self->header.flags&13;
 writeByte(writer,flags,key_803b0a28,flags==0);
 writeByte(writer,0,key_803b0a38,true);
 writeByte(writer,0,key_803b0a44,true);
 Type*type=((Type*(*)(Object*))self->table[5])(self);
 while(type!=sentinel_80365788){
  int remaining=((int(*)(Type*))type->table[8])(type);
  for(int i=0;i<remaining;++i)fn_801eb0b0(*(void**)((char*)type->fields+(i<<2)),writer,self);
  type=type->next;
 }
 return 0;
}
