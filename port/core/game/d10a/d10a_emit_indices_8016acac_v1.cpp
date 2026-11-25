#include "w3d_ptr.h"
#line 1 "d10a_emit_indices_8016acac_v1.cpp"
// Partial renderer view. Flags select split attribute streams or a shared
// stream, and byte versus halfword indices. FIFO writes preserve width/order.
struct d10a_IndexState {
 unsigned char unknown[0xa0];
 Ptr32<const void> cursor;
 Ptr32<const void> streams[4];
 unsigned flags;
};
union d10a_Fifo { struct { char w3d_gap_byte[1]; unsigned char byte; }; unsigned short half; };
extern volatile d10a_Fifo d10a_fifo_cc008000[];
extern "C" void d10a_emit_indices_8016acac(unsigned attributes,unsigned count,Ptr32<d10a_IndexState> self)
{
 if ((int)self->flags < 0) {
   for(unsigned i=0;i<count;++i) {
     if(attributes&3) {
       if(self->flags&0x20000000u) d10a_fifo_cc008000[0].byte=((Ptr32<const unsigned char>)self->streams[0])[i];
       else d10a_fifo_cc008000[0].half=((Ptr32<const unsigned short>)self->streams[0])[i];
     }
     if(attributes&12) {
       if(self->flags&0x10000000u) d10a_fifo_cc008000[0].byte=((Ptr32<const unsigned char>)self->streams[1])[i];
       else d10a_fifo_cc008000[0].half=((Ptr32<const unsigned short>)self->streams[1])[i];
     }
     if(attributes&48) {
       if(self->flags&0x08000000u) d10a_fifo_cc008000[0].byte=((Ptr32<const unsigned char>)self->streams[2])[i];
       else d10a_fifo_cc008000[0].half=((Ptr32<const unsigned short>)self->streams[2])[i];
     }
     if(attributes&384) {
       if(self->flags&0x04000000u) d10a_fifo_cc008000[0].byte=((Ptr32<const unsigned char>)self->streams[3])[i];
       else d10a_fifo_cc008000[0].half=((Ptr32<const unsigned short>)self->streams[3])[i];
     }
   }
 } else if(self->flags&0x40000000u) {
   Ptr32<const unsigned char> p=(Ptr32<const unsigned char>)self->cursor;
   for(unsigned i=0;i<count;++i,++p) {
     if(attributes&2) d10a_fifo_cc008000[0].byte=*p;
     if(attributes&12) d10a_fifo_cc008000[0].byte=*p;
     if(attributes&48) d10a_fifo_cc008000[0].byte=*p;
     if(attributes&384) d10a_fifo_cc008000[0].byte=*p;
   }
   self->cursor=p;
 } else {
   Ptr32<const unsigned short> p=(Ptr32<const unsigned short>)self->cursor;
   for(unsigned i=0;i<count;++i,++p) {
     if(attributes&3) d10a_fifo_cc008000[0].half=*p;
     if(attributes&12) d10a_fifo_cc008000[0].half=*p;
     if(attributes&48) d10a_fifo_cc008000[0].half=*p;
     if(attributes&384) d10a_fifo_cc008000[0].half=*p;
   }
   self->cursor=p;
 }
}


