
// PPC32: stream +20, current node +28; node payload +56; result records are twelve bytes.
struct Node{char pad[56];unsigned payload;};struct Owner{char pad[20];void*stream;unsigned unknown;Node*current;};struct Record{unsigned payload;Node*node;unsigned kind;};
extern "C" Node* first_801f8de0(void*);extern "C" Node* next_801f8df8(void*,Node*);
extern "C" int w3d_cx14b_stream_nodes_collect_801f9038(Owner*self,Record*output,unsigned count,unsigned*written){if(!self->stream)return 0x80004005;*written=0;unsigned i=0;if(i<count){Record*out=output;do{Node*p=self->current;if(!p)self->current=first_801f8de0(self->stream);else self->current=next_801f8df8(self->stream,p);out->payload=self->current->payload;out->node=self->current;out->kind=2;++out;++i;}while(i<count);}return 0;}


