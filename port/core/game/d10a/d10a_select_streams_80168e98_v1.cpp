#include "w3d_ptr.h"
#line 1 "d10a_select_streams_80168e98_v1.cpp"
// Inferred stream binding. Only accessed native subobject and descriptor fields
// are represented. Flags use declared bit widths; no full class size is claimed.
struct d10a_StreamDescriptor { unsigned char unknown[6]; unsigned short type; };
struct d10a_StreamInterface;
typedef Ptr32<int (Ptr32<d10a_StreamInterface>, Ptr32<d10a_StreamDescriptor>)> d10a_BindStream;
struct d10a_StreamInterface { unsigned char unknown[24]; Ptr32<d10a_BindStream> handlers;
 void bind(Ptr32<d10a_StreamDescriptor> descriptor) { handlers[descriptor->type](this,descriptor); }
};
struct d10a_StreamFlags {
 unsigned int other:26; unsigned int texture_byte:1; unsigned int color_byte:1; unsigned int normal_byte:1; unsigned int position_byte:1; unsigned int current_byte:1; unsigned int split:1;
};
struct d10a_StreamOwner {
 unsigned unknown0;
 d10a_StreamInterface interface;
 unsigned char unknown32[128];
 Ptr32<void> current;
 Ptr32<void> position; Ptr32<void> normal; Ptr32<void> color; Ptr32<void> texture;
 d10a_StreamFlags flags;
 unsigned unknown184,ready;
 unsigned char unknown192[100];
 unsigned attributes;
};
struct d10a_StreamSet {
 unsigned char unknown[24];
 Ptr32<d10a_StreamDescriptor> texture; Ptr32<d10a_StreamDescriptor> color; Ptr32<d10a_StreamDescriptor> normal; Ptr32<d10a_StreamDescriptor> position;
};
extern "C" int d10a_select_streams_80168e98(Ptr32<d10a_StreamInterface> input,Ptr32<d10a_StreamSet> set)
{
 Ptr32<d10a_StreamOwner> self=input?w3d::R((Ptr32<d10a_StreamOwner>)((Ptr32<char>)input-4)):0;
 Ptr32<d10a_StreamDescriptor> descriptor=set->position;
 self->interface.bind(descriptor);
 if(self->ready) {
   self->position=self->current;
   self->flags.position_byte=self->flags.current_byte;
   unsigned attributes=1;
   if(self->flags.position_byte) attributes=2;
   if(set->normal) {
     descriptor=set->normal;
     self->interface.bind(descriptor);
     self->normal=self->current;
     self->flags.normal_byte=self->flags.current_byte;
     if(self->flags.normal_byte) attributes|=16; else attributes|=8;
   }
   if(set->color) {
     descriptor=set->color;
     self->interface.bind(descriptor);
     self->color=self->current;
     self->flags.color_byte=self->flags.current_byte;
     if(self->flags.color_byte) attributes|=64; else attributes|=32;
   }
   if(set->texture) {
     descriptor=set->texture;
     self->interface.bind(descriptor);
     self->texture=self->current;
     self->flags.texture_byte=self->flags.current_byte;
     if(self->flags.texture_byte) attributes|=256; else attributes|=128;
   }
   self->attributes=attributes;
   self->current=0;
   self->flags.split=1;
 } else {
   self->current=0;
   self->flags.split=0;
 }
 return 0;
}


