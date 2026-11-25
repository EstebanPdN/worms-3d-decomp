// External sixteen-byte vector header; element storage belongs to the original allocator.
inline void *operator new(unsigned,void*p){return p;}
extern "C" void *fn_80212fd4(unsigned);
extern "C" void *fn_803413d8(unsigned);
extern "C" void fn_802134fc(void*);
extern "C" void *fn_802eeef4(void*,const void*,unsigned);
inline const unsigned&maximum(const unsigned&a,const unsigned&b){return a<b?b:a;}
struct WordVector {unsigned*begin;unsigned*end;unsigned unknown;unsigned*limit;
 void insert(const unsigned&value){
  unsigned count=end-begin;unsigned added=1;
  unsigned newCount=count+maximum(count,added);
  unsigned bytes;unsigned*memory;
  if(newCount){bytes=newCount*sizeof(unsigned);memory=(unsigned*)fn_80212fd4(bytes);if(!memory)memory=(unsigned*)fn_803413d8(bytes);}
  else{memory=0;bytes=0;}
  unsigned*oldEnd=end;unsigned*cursor;
  if(begin!=oldEnd){unsigned length=(char*)oldEnd-(char*)begin;cursor=(unsigned*)((char*)fn_802eeef4(memory,begin,length)+length);}else cursor=memory;
  for(unsigned n=added;n;--n){*cursor=value;++cursor;}
  if(begin)fn_802134fc(begin);
  begin=memory;limit=(unsigned*)((char*)memory+bytes);end=cursor;
 }
 void push(const unsigned&value){if(end!=limit){if(end)new(end)unsigned(value);++end;}else insert(value);}
};
extern "C" int h1b_append_word_v1_801f9df8(WordVector*self,unsigned value){self->push(value);return 0;}
