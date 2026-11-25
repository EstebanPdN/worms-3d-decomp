// External interfaces remain partial ABI views, never locally allocated.
struct G1bInterface{void**table;};
inline void retain(G1bInterface*p){if(p)((void(*)(G1bInterface*))p->table[3])(p);}
inline void release(G1bInterface*p){if(p)((void(*)(G1bInterface*))p->table[4])(p);}
struct G1bHeld{G1bInterface*p;G1bHeld(G1bInterface*q):p(q){retain(p);}~G1bHeld(){release(p);}};
struct G1bStream;
extern "C" void*fn_80207fec(G1bStream*);
extern "C" void fn_8020803c(G1bStream*,int);
extern "C" int fn_802080a0(G1bStream*,const char*,int);
// Complete six-word stream: constructor writes through20; embedded original
// instance starts132 and its following member is156 in allocated164-byte owner.
struct G1bStream{unsigned prefix[5];G1bInterface*resource;G1bStream(){fn_80207fec(this);}~G1bStream(){fn_8020803c(this,2);}};
extern "C" G1bInterface*fn_8020b680(const void*);
extern "C" void fn_802199c0(G1bInterface*,G1bInterface*);
extern "C" void fn_80347324(void*,const char*,...);
extern unsigned logger_804b0640,counter_804b069c;
extern char message_803b3104[],message_803b3130[];
extern unsigned char key_80419848[],key_80418de0[];
extern "C" int g1b_load_object_8020b6e8(const char*path,void*out){
 G1bStream stream;int result=fn_802080a0(&stream,path,1);
 if(result<0){if(counter_804b069c==0)fn_80347324(&logger_804b0640,message_803b3104,path);}
 else{
  G1bHeld service(fn_8020b680(key_80419848));
  G1bHeld reader(fn_8020b680(key_80418de0));
  fn_802199c0(service.p,stream.resource);
  ((void(*)(G1bInterface*,G1bInterface*))reader.p->table[5])(reader.p,service.p);
  result=((int(*)(G1bInterface*,void*,int))reader.p->table[8])(reader.p,out,0);
  if(result<0)fn_80347324(&logger_804b0640,message_803b3130,path);
 }
 return result;
}
