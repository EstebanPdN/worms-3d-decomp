// Partial renderer view. Flags select split attribute streams or a shared
// stream, and byte versus halfword indices. FIFO writes preserve width/order.
struct d10a_IndexState {
 unsigned char unknown[0xa0];
 const void *cursor;
 const void *streams[4];
 unsigned flags;
};
union d10a_Fifo { unsigned char byte; unsigned short half; };
extern "C" void d10a_emit_indices_8016acac(unsigned attributes,unsigned count,d10a_IndexState *self)
{
 volatile d10a_Fifo *fifo=(volatile d10a_Fifo *)0xcc008000u;
 if ((int)self->flags < 0) {
   for(unsigned i=0;i<count;++i) {
     if(attributes&3) {
       if(self->flags&0x20000000u) fifo->byte=((const unsigned char *)self->streams[0])[i];
       else fifo->half=((const unsigned short *)self->streams[0])[i];
     }
     if(attributes&12) {
       if(self->flags&0x10000000u) fifo->byte=((const unsigned char *)self->streams[1])[i];
       else fifo->half=((const unsigned short *)self->streams[1])[i];
     }
     if(attributes&48) {
       if(self->flags&0x08000000u) fifo->byte=((const unsigned char *)self->streams[2])[i];
       else fifo->half=((const unsigned short *)self->streams[2])[i];
     }
     if(attributes&384) {
       if(self->flags&0x04000000u) fifo->byte=((const unsigned char *)self->streams[3])[i];
       else fifo->half=((const unsigned short *)self->streams[3])[i];
     }
   }
 } else if(self->flags&0x40000000u) {
   const unsigned char *p=(const unsigned char *)self->cursor;
   for(unsigned i=0;i<count;++i,++p) {
     if(attributes&2) fifo->byte=*p;
     if(attributes&12) fifo->byte=*p;
     if(attributes&48) fifo->byte=*p;
     if(attributes&384) fifo->byte=*p;
   }
   self->cursor=p;
 } else {
   const unsigned short *p=(const unsigned short *)self->cursor;
   for(unsigned i=0;i<count;++i,++p) {
     if(attributes&3) fifo->half=*p;
     if(attributes&12) fifo->half=*p;
     if(attributes&48) fifo->half=*p;
     if(attributes&384) fifo->half=*p;
   }
   self->cursor=p;
 }
}
