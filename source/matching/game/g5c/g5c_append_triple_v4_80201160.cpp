// Original call includes the legacy unprototyped PowerPC condition-register setup.
extern "C" void* memset(...);
extern "C" void* fn_80212fd4(unsigned);
extern "C" void* fn_803413d8(unsigned);
extern "C" void fn_802134fc(void*);
inline void* operator new(unsigned,void* p) {return p;}
struct Triple {
 unsigned a,b,c;
 Triple() {memset(this,0,sizeof(*this));}
 Triple(unsigned x,unsigned y,unsigned z):a(x),b(y),c(z){}
 Triple(const Triple& v) {unsigned x=v.a,y=v.b,z=v.c;a=x;b=y;c=z;}
};
inline const unsigned& larger(const unsigned& a,const unsigned& b){return a<b?b:a;}
inline Triple* copyRecords(Triple* first,Triple* last,Triple* out) {
 for(;first!=last;++first,++out)if(out)new(out)Triple(*first);
 return out;
}
inline Triple* fillRecords(Triple* out,unsigned count,const Triple& value) {
 if(count==1){if(out)new(out)Triple(value);++out;}
 else {for(unsigned remaining=count;remaining;--remaining,++out)if(out)new(out)Triple(value);}
 return out;
}
struct TripleVectorView {
 Triple* begin;
 Triple* end;
 unsigned allocatorState;
 Triple* capacity;
 void grow(Triple* position,unsigned count,const Triple& value) {
  unsigned oldSize=end-begin;
  unsigned newCount=oldSize+larger(oldSize,count);
  unsigned bytes;
  Triple* fresh;
  if(newCount){bytes=newCount*sizeof(Triple);fresh=(Triple*)fn_80212fd4(bytes);if(!fresh)fresh=(Triple*)fn_803413d8(bytes);}
  else {fresh=0;bytes=0;}
  Triple* out=copyRecords(begin,position,fresh);
  out=fillRecords(out,count,value);
  for(Triple* at=begin;at!=end;++at)at->~Triple();
  if(begin)fn_802134fc(begin);
  begin=fresh;capacity=(Triple*)((char*)fresh+bytes);end=out;
 }
};
struct Owner {char unknown[44];TripleVectorView records;};
extern "C" int g5c_append_triple_80201160(Owner* owner,unsigned a,unsigned b,unsigned c) {
 Triple temporary;
 if(owner->records.end!=owner->records.capacity){if(owner->records.end)new(owner->records.end)Triple(a,b,c);++owner->records.end;}
 else {temporary.a=a;temporary.b=b;temporary.c=c;owner->records.grow(owner->records.end,1,temporary);}
 return 0;
}
