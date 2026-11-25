// Partial external descriptors and owner; external pointer ranges have no fixed extent.
struct Callback {unsigned unknown;unsigned short unknown4,index;unsigned char unknown8[3],flags;unsigned unknown12[2];unsigned short slot;};
struct Secondary {char unknown[24];void**callbacks;};
struct Owner {char unknown[24];Secondary*secondary;char unknown28[8];Callback**defaults;char unknown40[20];Callback**current;};
extern unsigned count_804b18d8;
extern "C" int g2b_apply_callbacks_801a2bf4(Owner*self,Callback**items,unsigned count){
 Secondary*secondary=self->secondary;
 void**table=secondary->callbacks;
 unsigned seen=0;
 for(unsigned i=0;i<count;++i){
  Callback*item=*items++;
  if(!(item->flags&4)){
   unsigned slot=item->slot;
   if(self->current[slot]!=item || (item->flags&2)){
    if(item->flags&2)item->flags&=0xfd;
    ((int(*)(Secondary*,Callback*))table[item->index])(secondary,item);
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
   if(*current!=item || (item->flags&2)){
    if(item->flags&2)item->flags&=0xfd;
    ((int(*)(Secondary*,Callback*))table[item->index])(secondary,item);
    *current=item;
   }
  }
 }
 return 0;
}
