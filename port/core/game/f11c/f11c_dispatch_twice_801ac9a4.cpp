#include "w3d_ptr.h"
#line 1 "f11c_dispatch_twice_801ac9a4.cpp"
// Names, roles, types, qualifiers and layouts are inferred from original instructions.
struct F11c_Header400{unsigned short a,b,c,selector;};struct F11c_Node400{char unknown[16];int cached;unsigned unknown20;Ptr32<Ptr32<int (Ptr32<F11c_Node400>, Ptr32<F11c_Header400>)>> dispatch;int run(Ptr32<F11c_Header400> header){return dispatch[header->selector](this,header);}};
struct F11c_Peer400{Ptr32<Ptr32<void>> table;Ptr32<Ptr32<int (Ptr32<F11c_Node400>, Ptr32<F11c_Header400>)>> handlers() { return ((Ptr32<Ptr32<int (Ptr32<F11c_Node400>, Ptr32<F11c_Header400>)>> (*)(Ptr32<F11c_Peer400>))w3d::g2h(((w3d_u32 *)w3d::g2h(table.v))[10]))(this); }};
struct F11c_Owner400{Ptr32<Ptr32<void>> table;F11c_Node400 node;char unknown32[52];unsigned flags;int once(Ptr32<F11c_Header400> header){node.cached=((Ptr32<int (Ptr32<F11c_Owner400>)>)table[5])(this);Ptr32<F11c_Peer400> peer=((Ptr32<Ptr32<F11c_Peer400> (Ptr32<F11c_Owner400>)>)table[11])(this);node.dispatch=peer->handlers();int status=((Ptr32<int (Ptr32<F11c_Owner400>, Ptr32<F11c_Header400>)>)table[7])(this,header);if(status>=0){status=node.run(header);((Ptr32<void (Ptr32<F11c_Owner400>, Ptr32<F11c_Header400>)>)table[8])(this,header);}return status;}};
extern "C" int f11c_dispatch_801ac9a4(Ptr32<F11c_Owner400> self,Ptr32<F11c_Header400> header){if((self->flags&3)==3){self->flags&=~1u;int status=self->once(header);self->flags|=1;if(status<0)return status;}return self->once(header);}



