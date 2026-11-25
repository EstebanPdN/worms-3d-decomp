#include "w3d_ptr.h"
#line 1 "g2b_write_schema_801ea18c.cpp"
// Partial external ABI views; no external objects are locally constructed.
struct Writer {Ptr32<Ptr32<void>> table;};
struct Header {unsigned unknown;unsigned char flags,kind;unsigned short unknown4;};
struct Object {Ptr32<Ptr32<void>> table;Header header;};
struct Type {Ptr32<Ptr32<void>> table;unsigned unknown[4];Ptr32<Type> next;unsigned unknown24[6];Ptr32<Ptr32<void>> fields;};
extern char tag_803b0a1c[],key_803b0a24[],key_803b0a28[],key_803b0a38[],key_803b0a44[];
extern Type sentinel_80365788[];
extern "C" int fn_801eb0b0(Ptr32<void>,Ptr32<Writer>,Ptr32<Object>);
inline int writeByte(Ptr32<Writer> w,unsigned value,Ptr32<const char> key,bool omitted){return ((Ptr32<int (Ptr32<Writer>, unsigned int, Ptr32<const char>, bool)>)w->table[13])(w,value,key,omitted);}
extern "C" int g2b_write_schema_801ea18c(Ptr32<Object> self,Ptr32<Writer> writer){
 ((Ptr32<int (Ptr32<Writer>, Ptr32<const char>, int, Ptr32<const char>)>)writer->table[39])(writer,tag_803b0a1c,4,key_803b0a24);
 unsigned flags=self->header.flags&13;
 writeByte(writer,flags,key_803b0a28,flags==0);
 writeByte(writer,0,key_803b0a38,true);
 writeByte(writer,0,key_803b0a44,true);
 Ptr32<Type> type=((Ptr32<Ptr32<Type> (Ptr32<Object>)>)self->table[5])(self);
 while(type!=sentinel_80365788){
  int remaining=((Ptr32<int (Ptr32<Type>)>)type->table[8])(type);
  for(int i=0;i<remaining;++i)fn_801eb0b0(*(Ptr32<Ptr32<void>>)((Ptr32<char>)type->fields+(i<<2)),writer,self);
  type=type->next;
 }
 return 0;
}


