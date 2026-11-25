// Partial external descriptors and owner; external pointer ranges have no fixed extent.
struct Header {unsigned short unknown,index;unsigned char unknown4[3],flags;unsigned char getFlags()const{return flags;}void setFlags(unsigned char f){flags=f;}};
struct Callback {unsigned unknown;Header header;unsigned unknown12[2];unsigned short slot;};
struct Secondary {char unknown[24];void**callbacks;};
struct Owner {char unknown[24];Secondary*secondary;char unknown28[8];Callback**defaults;char unknown40[20];Callback**current;};
extern unsigned count_804b18d8;
extern "C" int g2b_apply_callbacks_801a2bf4(Owner*self,Callback**items,unsigned count){
 Secondary*secondary=self->secondary;
 void**table=secondary->callbacks;
 unsigned seen=0;
 for(unsigned i=0;i<count;++i){
  Callback*item=*items++;
  Header*header=&item->header;
  unsigned flags=header->getFlags();
  if((flags^4)&4){
   unsigned slot=item->slot;
   if(self->current[slot]!=item || ((flags>>1)&1)){
    if((flags>>1)&1)header->setFlags(flags&0xfd);
    ((int(*)(Secondary*,Callback*))table[item->header.index])(secondary,item);
    self->current[slot]=item;
   }
   seen|=1U<<slot;
  }
 }
 Callback**current=self->current;
 Callback**defaults=self->defaults;
 unsigned end=1U<<count_804b18d8;
 for(unsigned mask=2;mask!=end;mask<<=1){
  ++current;++defaults;
  if(!(seen&mask)){
   Callback*item=*defaults;
   if(*current!=item || ((item->header.getFlags()>>1)&1)){
    if((item->header.getFlags()>>1)&1)item->header.setFlags(item->header.getFlags()&0xfd);
    ((int(*)(Secondary*,Callback*))table[item->header.index])(secondary,item);
    *current=item;
   }
  }
 }
 return 0;
}
