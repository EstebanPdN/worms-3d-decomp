#include "w3d_ptr.h"
#line 1 "cx12b_sound_payload_deserialize_801df7f4.cpp"

// PPC32 payload members +20/+24/+28/+32 and stream slots +128/+160 are observed.
struct Stream;struct Vtable{Ptr32<void> unused[32];Ptr32<int (Ptr32<Stream>, Ptr32<unsigned int>, int)> word;Ptr32<void> gap[7];Ptr32<int (Ptr32<Stream>, Ptr32<void>, unsigned int, int)> bytes;};struct Stream{Ptr32<Vtable> vtable;};struct Sound{unsigned char opaque[20];unsigned int first_size;Ptr32<void> first;Ptr32<void> second;unsigned int second_size;};
extern "C" void release_801fe240(Ptr32<void>);extern "C" Ptr32<void> allocate_801fe220(unsigned int);
extern "C" int w3d_cx12b_sound_payload_deserialize_801df7f4(Ptr32<Sound> self,Ptr32<Stream> s){s->vtable->word(s,&self->first_size,0);if(self->first)release_801fe240(self->first);self->first=allocate_801fe220(self->first_size);s->vtable->bytes(s,self->first,self->first_size,0);s->vtable->word(s,&self->second_size,0);if(self->second)release_801fe240(self->second);self->second=allocate_801fe220(self->second_size);s->vtable->bytes(s,self->second,self->second_size,0);unsigned int a,b;s->vtable->word(s,&a,0);s->vtable->word(s,&b,0);return 0;}



