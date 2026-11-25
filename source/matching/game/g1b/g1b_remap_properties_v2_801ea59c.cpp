// Partial external type/property views only. No local external construction.
struct G1bProperty{unsigned unknown;unsigned short offset;unsigned char unknown6,flags;};
struct G1bType{unsigned unknown0;G1bType*next;unsigned unknown8[6];int flags;unsigned unknown36[6];void**begin,**end;};
extern "C" G1bType*fn_8020ff3c();
extern "C" char*fn_8020fe00(G1bType*);
extern "C" char*fn_8020fe18(G1bType*,char*);
extern "C" G1bProperty**fn_801e9db8(G1bType*,unsigned);
extern "C" int g1b_remap_properties_801ea59c(const unsigned*from,const unsigned*to,unsigned count){
 int changed=0;
 for(G1bType*type=fn_8020ff3c();type;type=type->next){
  if(((type->flags>>16)&15)==2){
   unsigned properties=type->end-type->begin;
   for(char*object=fn_8020fe00(type);object;object=fn_8020fe18(type,object)){
    for(unsigned i=0;i<properties;++i){
     G1bProperty*p=*fn_801e9db8(type,i);
     if(p->flags&1){unsigned*field=(unsigned*)(object+p->offset);
      for(unsigned j=0;j<count;++j)if(*field==from[j]){++changed;*field=to[j];break;}
     }
    }
   }
  }
 }
 return changed;
}
