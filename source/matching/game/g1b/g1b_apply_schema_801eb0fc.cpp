// Partial external ABI views; no local object construction or owned data.
struct G1bInterface{void**table;};
struct G1bSchemaHeader{unsigned unknown;unsigned short unknown4;unsigned char kind,flags;};
struct G1bSchema{G1bSchemaHeader*header;void**table;};
extern "C" void*fn_801e9de4(void*,unsigned);
extern "C" void*fn_801eb2a8(G1bSchema*,const char*);
extern "C" const char**fn_80200200(void*,const char*);
extern "C" int fn_802ed89c(const char*);
extern char key_803b0c38[],key_803b0c40[],key_803b0c4c[];
extern "C" int g1b_apply_schema_801eb0fc(G1bSchema*self,G1bInterface*reader,G1bInterface*object){
 if(self->header->flags&4)return 1;
 void*type=((void*(*)(G1bInterface*))object->table[5])(object);
 void*member=fn_801e9de4(type,self->header->kind);
 unsigned version=((unsigned(*)(G1bInterface*,void*))reader->table[46])(reader,member);
 if(!(self->header->flags&32)){
  void*schema=fn_801eb2a8(self,key_803b0c38);
  if(schema){unsigned minimum=(unsigned char)fn_802ed89c(*fn_80200200(schema,key_803b0c40));if(version<minimum)return 1;}
  return ((int(*)(G1bSchema*,G1bInterface*,G1bInterface*))self->table[7])(self,reader,object);
 }else{
  bool old=false;void*obsolete=fn_801eb2a8(self,key_803b0c4c);
  if(obsolete){unsigned minimum=(unsigned char)fn_802ed89c(*fn_80200200(obsolete,key_803b0c40));old=version<minimum;}
  if(!old)return 1;
  return ((int(*)(G1bSchema*,G1bInterface*,G1bInterface*))self->table[7])(self,reader,0);
 }
}
