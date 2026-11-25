// Names, roles, types, qualifiers and layouts are inferred from original instructions.
struct F11c_Header400{unsigned short a,b,c,selector;};struct F11c_Node400{char unknown[16];int cached;unsigned unknown20;int(**dispatch)(F11c_Node400*,F11c_Header400*);int run(F11c_Header400*header){return dispatch[header->selector](this,header);}};
struct F11c_Peer400{void**table;int(**handlers())(F11c_Node400*,F11c_Header400*){return ((int(**(*)(F11c_Peer400*))(F11c_Node400*,F11c_Header400*))table[10])(this);}};
struct F11c_Owner400{void**table;F11c_Node400 node;char unknown32[52];unsigned flags;int once(F11c_Header400*header){node.cached=((int(*)(F11c_Owner400*))table[5])(this);F11c_Peer400*peer=((F11c_Peer400*(*)(F11c_Owner400*))table[11])(this);node.dispatch=peer->handlers();int status=((int(*)(F11c_Owner400*,F11c_Header400*))table[7])(this,header);if(status>=0){status=node.run(header);((void(*)(F11c_Owner400*,F11c_Header400*))table[8])(this,header);}return status;}};
extern "C" int f11c_dispatch_801ac9a4(F11c_Owner400*self,F11c_Header400*header){if((self->flags&3)==3){self->flags&=~1u;int status=self->once(header);self->flags|=1;if(status<0)return status;}return self->once(header);}

