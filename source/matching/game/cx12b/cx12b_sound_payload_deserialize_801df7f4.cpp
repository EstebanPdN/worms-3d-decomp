
// PPC32 payload members +20/+24/+28/+32 and stream slots +128/+160 are observed.
struct Stream;struct Vtable{void*unused[32];int(*word)(Stream*,unsigned int*,int);void*gap[7];int(*bytes)(Stream*,void*,unsigned int,int);};struct Stream{Vtable*vtable;};struct Sound{unsigned char opaque[20];unsigned int first_size;void*first;void*second;unsigned int second_size;};
extern "C" void release_801fe240(void*);extern "C" void*allocate_801fe220(unsigned int);
extern "C" int w3d_cx12b_sound_payload_deserialize_801df7f4(Sound*self,Stream*s){s->vtable->word(s,&self->first_size,0);if(self->first)release_801fe240(self->first);self->first=allocate_801fe220(self->first_size);s->vtable->bytes(s,self->first,self->first_size,0);s->vtable->word(s,&self->second_size,0);if(self->second)release_801fe240(self->second);self->second=allocate_801fe220(self->second_size);s->vtable->bytes(s,self->second,self->second_size,0);unsigned int a,b;s->vtable->word(s,&a,0);s->vtable->word(s,&b,0);return 0;}

