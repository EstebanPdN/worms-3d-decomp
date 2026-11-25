#include "w3d_ptr.h"
#line 1 "cc40a_vertex_write_801736a8.cpp"
// Header is the observed 32-byte prefix before inline element storage, not the full buffer size.
// Partial views inferred from offsets. The local retained handle owns one reference;
// its destructor releases that reference after the original write completes.
struct cc40a_Vertex { float x,y,z; };
struct cc40a_BufferHeader { unsigned char unknown00[4]; unsigned short mode; unsigned char unknown06[18]; unsigned int count; unsigned short locks; unsigned char unknown1e[2]; };
struct cc40a_Buffer;
struct cc40a_BufferVtable { Ptr32<void> unknown00[3]; Ptr32<int (Ptr32<cc40a_Buffer>)> retain; Ptr32<int (Ptr32<cc40a_Buffer>)> release; };
struct cc40a_Buffer { Ptr32<cc40a_BufferVtable> vtable; unsigned char unknown04[60]; Ptr32<cc40a_BufferHeader> storage; };
struct cc40a_Owner { unsigned char unknown00[48]; Ptr32<cc40a_Buffer> buffer; };
struct cc40a_VertexWriter { unsigned char unknown00[124]; int index; Ptr32<cc40a_Owner> owner; };
extern "C" Ptr32<cc40a_Vertex> cc40a_lock_801ef048(Ptr32<Ptr32<cc40a_BufferHeader>>,unsigned int,unsigned int,unsigned int);
struct cc40a_RetainedBuffer {
 Ptr32<cc40a_Buffer> pointer;
 template <class W3dU> cc40a_RetainedBuffer(Ptr32<W3dU> w3d_p) : cc40a_RetainedBuffer((cc40a_Buffer *)w3d_p.get()) {}
 cc40a_RetainedBuffer(cc40a_Buffer* p):pointer(p){if(pointer)pointer->vtable->retain(pointer);}
 ~cc40a_RetainedBuffer(){if(pointer)pointer->vtable->release(pointer);}
};
inline Ptr32<cc40a_Vertex> cc40a_lockInline(Ptr32<Ptr32<cc40a_BufferHeader>> storage) {
 Ptr32<cc40a_BufferHeader> header=*storage;
 unsigned int count=header->count;
 if(header->mode==1){++header->locks;return (Ptr32<cc40a_Vertex>)(header+1);}
 return cc40a_lock_801ef048(storage,count,12,2);
}
extern "C" int cc40a_vertex_write_801736a8(Ptr32<cc40a_VertexWriter> self,Ptr32<const cc40a_Vertex> value){
 cc40a_RetainedBuffer buffer(self->owner->buffer);
 Ptr32<cc40a_Vertex> data=cc40a_lockInline(&buffer.pointer->storage);
 data[self->index]=*value;
 return 0;
}


