
// PPC32: payload lengths +20/+32, payload pointers +24/+28. Virtual slots +84 and +152.
struct Stream{void**table;};struct Sound{char pad[20];unsigned countA;void*a;void*b;unsigned countB;};
inline int word(Stream*s,unsigned v){return ((int(*)(Stream*,unsigned,int,int))s->table[21])(s,v,0,0);}
inline int bytes(Stream*s,void*p,unsigned n){return ((int(*)(Stream*,void*,unsigned,int))s->table[38])(s,p,n,0);}
extern "C" int w3d_cx14b_sound_payload_serialize_801df704(Sound*self,Stream*s){word(s,self->countA);bytes(s,self->a,self->countA);word(s,self->countB);bytes(s,self->b,self->countB);word(s,1);word(s,2);return 0;}

