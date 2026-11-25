// External class and descriptor prefixes; no external objects are constructed here.
struct Metadata {unsigned unknown;unsigned short offset;unsigned char unknown6,flags;};
struct Property {Metadata*metadata;};
struct Type {unsigned unknown;Type*next;unsigned unknown8[6];unsigned flags;unsigned unknown36[6];Property**begin;Property**end;};
extern "C" Type*fn_8020ff3c();
extern "C" char*fn_8020fe00(Type*);
extern "C" char*fn_8020fe18(Type*,char*);
extern "C" Property*fn_801e9db8(Type*,unsigned);
extern "C" int h1b_remap_instances_v3_801ea59c(unsigned*oldTypes,unsigned*newTypes,unsigned count){
 int replacements=0;
 for(Type*type=fn_8020ff3c();type;type=type->next){
  if(((type->flags>>16)&15)==2){
   unsigned properties=type->end-type->begin;
   for(char*object=fn_8020fe00(type);object;object=fn_8020fe18(type,object)){
    for(unsigned i=0;i<properties;++i){
     Property*property=fn_801e9db8(type,i);
     if(property->metadata->flags&1){
      unsigned offset=property->metadata->offset;
      if(count){
       if(*(unsigned*)(object+offset)==oldTypes[0]){++replacements;*(unsigned*)(object+offset)=newTypes[0];}
       else{unsigned mapping=0;do{++mapping;if(count<=mapping)goto nextProperty;}while(*(unsigned*)(object+offset)!=oldTypes[mapping]);++replacements;*(unsigned*)(object+offset)=newTypes[mapping];}
      }
     }
    nextProperty:;
    }
   }
  }
 }
 return replacements;
}
