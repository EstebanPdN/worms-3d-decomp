// External ABI views only. None are locally constructed.
struct Header {unsigned unknown;unsigned short kind;unsigned char unknown6[18];int count;unsigned short locks;};
extern "C" void*fn_801ef048(Header**,int,int,int);
struct Array {Header*header;void*lock(int count,int stride,int mode){Header*h=header;if(h->kind==1 && count==h->count){++h->locks;return (char*)h+32;}return fn_801ef048(&header,count,stride,mode);}};
struct Item {unsigned unknown,value,unknown8;unsigned tags;};
struct Range {Item**begin,**end;unsigned unknown[2];};
struct RangeStorage;
struct Commands {unsigned unknown[5];Array words;};
struct Owner {unsigned unknown[44];Commands*commands;unsigned unknown180[15];void*table240;unsigned unknown244[2];void*table252;unsigned unknown256[3];void*table268;unsigned unknown272[3];unsigned dirty;Range*begin;Range*end;};
inline unsigned lookup(void*storage,unsigned index){return *(unsigned*)((char*)storage+(index<<2));}
extern "C" Commands*g4b_build_commands_801a9478(Owner*self){
 int capacity=0;unsigned index=0;
 Range*range=self->begin;
 unsigned count=self->end-range;
 for(;index<count;++index,++range)capacity+=(range->end-range->begin)*3;
 Commands*commands=self->commands;
 unsigned*begin=(unsigned*)commands->words.lock(capacity,4,1);
 unsigned*out=begin;
 unsigned previousGroup=~0U,previousIndex=~0U,previousMode=0;
 for(unsigned i=0;i<count;++i){
  Range*r=(Range*)((char*)self->begin+(i<<4));
  Item**last=r->end;
  for(Item**cursor=r->begin;cursor!=last;++cursor){
   unsigned group=(*cursor)->tags&127;
   if(previousGroup!=group){*out++=lookup(self->table252,group);previousGroup=group;}
   unsigned itemIndex=*(unsigned short*)&(*cursor)->tags;
   if(previousIndex!=itemIndex){*out++=lookup(self->table240,itemIndex);previousIndex=itemIndex;}
   unsigned mode=((*cursor)->tags>>7)&511;
   if(previousMode!=mode){*out++=lookup(self->table268,mode);previousMode=mode;}
   *out++=(*cursor)->value;
  }
 }
 commands->words.lock(out-begin,4,0);self->dirty=0;return commands;
}
