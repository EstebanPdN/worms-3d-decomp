#include "w3d_ptr.h"
#line 1 "g2b_read_schema_v3_801ea2d8.cpp"
// Partial external ABI views; only three independent one-byte locals are constructed.
struct Reader {Ptr32<Ptr32<void>> table;};
struct Header {unsigned unknown;unsigned char flags,kind;unsigned short unknown4;};
struct Object {Ptr32<Ptr32<void>> table;Header header;};
struct Type {Ptr32<Ptr32<void>> table;unsigned unknown[4];Ptr32<Type> next;unsigned unknown24[6];Ptr32<Ptr32<void>> fields;};
extern char tag_804ab89c[5],key_803b0a24[],key_803b0a28[],key_803b0a38[],key_803b0a44[];
extern Type sentinel_80365788[];
extern "C" int fn_801eb0fc(Ptr32<void>,Ptr32<Reader>,Ptr32<Object>);
inline int readByte(Ptr32<Reader> r,Ptr32<unsigned char> p,Ptr32<const char> k){return ((Ptr32<int (Ptr32<Reader>, Ptr32<unsigned char>, Ptr32<const char>)>)r->table[28])(r,p,k);}
extern "C" int g2b_read_schema_801ea2d8(Ptr32<Object> self,Ptr32<Reader> reader){
 int result=((Ptr32<int (Ptr32<Reader>, Ptr32<const char>, int, Ptr32<const char>)>)reader->table[41])(reader,tag_804ab89c,4,key_803b0a24);
 if(result<0)return (int)0x80004005;
 Ptr32<Header> header=&self->header;
 unsigned char internal=header->flags;
 readByte(reader,&internal,key_803b0a28);
 header->flags=(header->flags&0xf2)|(internal&13);
 unsigned char user;
 readByte(reader,&user,key_803b0a38);
 unsigned char count=0;
 readByte(reader,&count,key_803b0a44);
 Ptr32<Type> type=((Ptr32<Ptr32<Type> (Ptr32<Object>)>)self->table[5])(self);
 while(type!=sentinel_80365788){
  int remaining=((Ptr32<int (Ptr32<Type>)>)type->table[8])(type);
  for(int i=0;i<remaining;++i)fn_801eb0fc(*(Ptr32<Ptr32<void>>)((Ptr32<char>)type->fields+(i<<2)),reader,self);
  type=type->next;
 }
 return 0;
}


