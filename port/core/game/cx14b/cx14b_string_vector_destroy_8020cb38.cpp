#include "w3d_ptr.h"
#line 1 "cx14b_string_vector_destroy_8020cb38.cpp"

// PPC32 owner buffer +0, vector +12; each element occupies eight bytes.
struct String{char data[8];};struct Vector{Ptr32<String> begin; Ptr32<String> end; Ptr32<String> capacity;};struct Owner{Ptr32<void> buffer;char gap[8];Vector strings;};
extern "C" void free_801fe240(Ptr32<void>);extern "C" void finish_8020c5c4(Ptr32<String>);extern "C" void release_80341588(Ptr32<String>);extern "C" void storage_802134fc(Ptr32<void>);extern "C" void destroy_801fe1f8(Ptr32<void>);
extern "C" void w3d_cx14b_string_vector_destroy_8020cb38(Ptr32<Owner> self,int flags){if(self->buffer)free_801fe240(self->buffer);self->buffer=0;Ptr32<Vector> v=&self->strings;Ptr32<String> p=v->begin; Ptr32<String> end=v->end;if(p!=end)do{finish_8020c5c4(p);release_80341588(p);++p;}while(p!=end);if(v->begin)storage_802134fc(v->begin);if(flags&1)destroy_801fe1f8(self);}



