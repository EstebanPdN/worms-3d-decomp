#include "w3d_ptr.h"
#line 1 "cx14b_stream_nodes_collect_801f9038.cpp"

// PPC32: stream +20, current node +28; node payload +56; result records are twelve bytes.
struct Node{char pad[56];unsigned payload;};struct Owner{char pad[20];Ptr32<void> stream;unsigned unknown;Ptr32<Node> current;};struct Record{unsigned payload;Ptr32<Node> node;unsigned kind;};
extern "C" Ptr32<Node> first_801f8de0(Ptr32<void>);extern "C" Ptr32<Node> next_801f8df8(Ptr32<void>,Ptr32<Node>);
extern "C" int w3d_cx14b_stream_nodes_collect_801f9038(Ptr32<Owner> self,Ptr32<Record> output,unsigned count,Ptr32<unsigned int> written){if(!self->stream)return 0x80004005;*written=0;unsigned i=0;if(i<count){Ptr32<Record> out=output;do{Ptr32<Node> p=self->current;if(!p)self->current=first_801f8de0(self->stream);else self->current=next_801f8df8(self->stream,p);out->payload=self->current->payload;out->node=self->current;out->kind=2;++out;++i;}while(i<count);}return 0;}




