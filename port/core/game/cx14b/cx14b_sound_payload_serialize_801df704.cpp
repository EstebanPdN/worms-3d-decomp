#include "w3d_ptr.h"
#line 1 "cx14b_sound_payload_serialize_801df704.cpp"

// PPC32: payload lengths +20/+32, payload pointers +24/+28. Virtual slots +84 and +152.
struct Stream{Ptr32<Ptr32<void>> table;};struct Sound{char pad[20];unsigned countA;Ptr32<void> a;Ptr32<void> b;unsigned countB;};
inline int word(Ptr32<Stream> s,unsigned v){return ((Ptr32<int (Ptr32<Stream>, unsigned int, int, int)>)s->table[21])(s,v,0,0);}
inline int bytes(Ptr32<Stream> s,Ptr32<void> p,unsigned n){return ((Ptr32<int (Ptr32<Stream>, Ptr32<void>, unsigned int, int)>)s->table[38])(s,p,n,0);}
extern "C" int w3d_cx14b_sound_payload_serialize_801df704(Ptr32<Sound> self,Ptr32<Stream> s){word(s,self->countA);bytes(s,self->a,self->countA);word(s,self->countB);bytes(s,self->b,self->countB);word(s,1);word(s,2);return 0;}



