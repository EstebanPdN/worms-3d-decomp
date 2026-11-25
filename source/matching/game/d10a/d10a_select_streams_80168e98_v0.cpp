// Inferred stream binding. Only accessed native subobject and descriptor fields
// are represented. Flags use declared bit widths; no full class size is claimed.
struct d10a_StreamDescriptor { unsigned char unknown[6]; unsigned short type; };
struct d10a_StreamInterface;
typedef int (*d10a_BindStream)(d10a_StreamInterface *,d10a_StreamDescriptor *);
struct d10a_StreamInterface { unsigned char unknown[24]; d10a_BindStream *handlers; };
struct d10a_StreamFlags {
 unsigned split:1, current_byte:1, position_byte:1, normal_byte:1, color_byte:1, texture_byte:1, other:26;
};
struct d10a_StreamOwner {
 unsigned unknown0;
 d10a_StreamInterface interface;
 unsigned char unknown32[128];
 void *current;
 void *position,*normal,*color,*texture;
 d10a_StreamFlags flags;
 unsigned unknown184,ready;
 unsigned char unknown192[100];
 unsigned attributes;
};
struct d10a_StreamSet {
 unsigned char unknown[24];
 d10a_StreamDescriptor *texture,*color,*normal,*position;
};
extern "C" int d10a_select_streams_80168e98(d10a_StreamInterface *input,d10a_StreamSet *set)
{
 d10a_StreamOwner *self=input?(d10a_StreamOwner *)((char *)input-4):0;
 d10a_StreamInterface *target=&self->interface;
 d10a_StreamDescriptor *descriptor=set->position;
 target->handlers[descriptor->type](target,descriptor);
 if(self->ready) {
   self->position=self->current;
   self->flags.position_byte=self->flags.current_byte;
   unsigned attributes=1;
   if(self->flags.position_byte) attributes=2;
   if(set->normal) {
     descriptor=set->normal;
     target->handlers[descriptor->type](target,descriptor);
     self->normal=self->current;
     self->flags.normal_byte=self->flags.current_byte;
     if(self->flags.normal_byte) attributes|=16; else attributes|=8;
   }
   if(set->color) {
     descriptor=set->color;
     target->handlers[descriptor->type](target,descriptor);
     self->color=self->current;
     self->flags.color_byte=self->flags.current_byte;
     if(self->flags.color_byte) attributes|=64; else attributes|=32;
   }
   if(set->texture) {
     descriptor=set->texture;
     target->handlers[descriptor->type](target,descriptor);
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
