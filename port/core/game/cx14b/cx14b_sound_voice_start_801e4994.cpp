#include "w3d_ptr.h"
#line 1 "cx14b_sound_voice_start_801e4994.cpp"
// PPC32 slot offsets are observed, field meanings inferred. Header starts +16; SDK file subobject starts +24.
struct Header{Ptr32<const char> name;unsigned short rate;unsigned short pad;unsigned offset,length;char data[1];};
struct Slot{unsigned char state;char pad0[7];Ptr32<Slot> next; Ptr32<Slot> previous;Ptr32<Header> header;unsigned char volume,pan;char pad1[2];char file[60];unsigned voice,block,length;Ptr32<unsigned char> buffer;unsigned readPosition,capacity;unsigned char active;char pad2[3];unsigned enabled,pending,playing,zero;};

extern "C" void voice_80324920(unsigned,unsigned char,unsigned char,int,int,int);extern "C" void rate_80324e7c(unsigned,unsigned short);extern "C" void data_80324224(unsigned,Ptr32<void>);extern "C" void range_803238fc(unsigned,int,unsigned,int,int);extern "C" int start_80325bb8(unsigned);extern "C" int advance_801e47e8(Ptr32<Slot>);extern "C" int close_802f5320(Ptr32<void>);
extern "C" int w3d_cx14b_sound_voice_start_801e4994(Ptr32<Slot> self){voice_80324920(self->voice,self->volume,self->pan,0,0,0);rate_80324e7c(self->voice,self->header->rate);data_80324224(self->voice,self->header->data);range_803238fc(self->voice,0,self->capacity>>1,0,0);int ok=start_80325bb8(self->voice);if(ok){self->state=4;advance_801e47e8(self);return 1;}self->state=0;close_802f5320(self->file);return 0;}



