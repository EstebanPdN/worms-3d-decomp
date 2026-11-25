#include "w3d_ptr.h"
#line 1 "g1b_apply_schema_801eb0fc.cpp"
// Partial external ABI views; no local object construction or owned data.
struct G1bInterface{Ptr32<Ptr32<void>> table;};
struct G1bSchemaHeader{unsigned unknown;unsigned short unknown4;unsigned char kind,flags;};
struct G1bSchema{Ptr32<G1bSchemaHeader> header;Ptr32<Ptr32<void>> table;};
extern "C" Ptr32<void> fn_801e9de4(Ptr32<void>,unsigned);
extern "C" Ptr32<void> fn_801eb2a8(Ptr32<G1bSchema>,Ptr32<const char>);
extern "C" Ptr32<Ptr32<const char>> fn_80200200(Ptr32<void>,Ptr32<const char>);
extern "C" int fn_802ed89c(Ptr32<const char>);
extern char key_803b0c38[],key_803b0c40[],key_803b0c4c[];
extern "C" int g1b_apply_schema_801eb0fc(Ptr32<G1bSchema> self,Ptr32<G1bInterface> reader,Ptr32<G1bInterface> object){
 if(self->header->flags&4)return 1;
 Ptr32<void> type=((Ptr32<Ptr32<void> (Ptr32<G1bInterface>)>)object->table[5])(object);
 Ptr32<void> member=fn_801e9de4(type,self->header->kind);
 unsigned version=((Ptr32<unsigned int (Ptr32<G1bInterface>, Ptr32<void>)>)reader->table[46])(reader,member);
 if(!(self->header->flags&32)){
  Ptr32<void> schema=fn_801eb2a8(self,key_803b0c38);
  if(schema){unsigned minimum=(unsigned char)fn_802ed89c(*fn_80200200(schema,key_803b0c40));if(version<minimum)return 1;}
  return ((Ptr32<int (Ptr32<G1bSchema>, Ptr32<G1bInterface>, Ptr32<G1bInterface>)>)self->table[7])(self,reader,object);
 }else{
  bool old=false;Ptr32<void> obsolete=fn_801eb2a8(self,key_803b0c4c);
  if(obsolete){unsigned minimum=(unsigned char)fn_802ed89c(*fn_80200200(obsolete,key_803b0c40));old=version<minimum;}
  if(!old)return 1;
  return ((Ptr32<int (Ptr32<G1bSchema>, Ptr32<G1bInterface>, Ptr32<G1bInterface>)>)self->table[7])(self,reader,0);
 }
}


