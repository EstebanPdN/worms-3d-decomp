// Partial external ABI views; only three independent one-byte locals are constructed.
struct Reader {void**table;};
struct Header {unsigned unknown;unsigned short unknown4;unsigned char kind,flags;};
struct Object {void**table;Header header;};
struct Type {void**table;unsigned unknown[4];Type*next;unsigned unknown24[6];void**fields;};
extern char tag_804ab89c[5],key_803b0a24[],key_803b0a28[],key_803b0a38[],key_803b0a44[];
extern Type sentinel_80365788[];
extern "C" int fn_801eb0fc(void*,Reader*,Object*);
inline int readByte(Reader*r,unsigned char*p,const char*k){return ((int(*)(Reader*,unsigned char*,const char*))r->table[28])(r,p,k);}
extern "C" int g2b_read_schema_801ea2d8(Object*self,Reader*reader){
 int result=((int(*)(Reader*,const char*,int,const char*))reader->table[41])(reader,tag_804ab89c,4,key_803b0a24);
 if(result<0)return (int)0x80004005;
 Header*header=&self->header;
 unsigned char internal=header->flags;
 readByte(reader,&internal,key_803b0a28);
 header->flags=(header->flags&0xf2)|(internal&13);
 unsigned char user;
 readByte(reader,&user,key_803b0a38);
 unsigned char count=0;
 readByte(reader,&count,key_803b0a44);
 Type*type=((Type*(*)(Object*))self->table[5])(self);
 while(type!=sentinel_80365788){
  int remaining=((int(*)(Type*))type->table[8])(type);
  for(int i=0;i<remaining;++i)fn_801eb0fc(*(void**)((char*)type->fields+(i<<2)),reader,self);
  type=type->next;
 }
 return 0;
}
