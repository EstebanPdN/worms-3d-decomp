// Header is the observed 32-byte prefix before inline element storage, not the full buffer size.
// Partial views inferred from offsets. The local retained handle owns one reference;
// its destructor releases that reference after the original write completes.
struct cc40a_Vertex { float x,y,z; };
struct cc40a_BufferHeader { unsigned char unknown00[4]; unsigned short mode; unsigned char unknown06[18]; unsigned int count; unsigned short locks; unsigned char unknown1e[2]; };
struct cc40a_Buffer;
struct cc40a_BufferVtable { void* unknown00[3]; int (*retain)(cc40a_Buffer*); int (*release)(cc40a_Buffer*); };
struct cc40a_Buffer { cc40a_BufferVtable* vtable; unsigned char unknown04[60]; cc40a_BufferHeader* storage; };
struct cc40a_Owner { unsigned char unknown00[48]; cc40a_Buffer* buffer; };
struct cc40a_VertexWriter { unsigned char unknown00[124]; int index; cc40a_Owner* owner; };
extern "C" cc40a_Vertex* cc40a_lock_801ef048(cc40a_BufferHeader**,unsigned int,unsigned int,unsigned int);
struct cc40a_RetainedBuffer {
 cc40a_Buffer* pointer;
 cc40a_RetainedBuffer(cc40a_Buffer* p):pointer(p){if(pointer)pointer->vtable->retain(pointer);}
 ~cc40a_RetainedBuffer(){if(pointer)pointer->vtable->release(pointer);}
};
inline cc40a_Vertex* cc40a_lockInline(cc40a_BufferHeader** storage) {
 cc40a_BufferHeader* header=*storage;
 unsigned int count=header->count;
 if(header->mode==1){++header->locks;return (cc40a_Vertex*)(header+1);}
 return cc40a_lock_801ef048(storage,count,12,2);
}
extern "C" int cc40a_vertex_write_801736a8(cc40a_VertexWriter* self,const cc40a_Vertex* value){
 cc40a_RetainedBuffer buffer(self->owner->buffer);
 cc40a_Vertex* data=cc40a_lockInline(&buffer.pointer->storage);
 data[self->index]=*value;
 return 0;
}
