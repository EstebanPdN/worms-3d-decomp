
// PPC32 owner buffer +0, vector +12; each element occupies eight bytes.
struct String{char data[8];};struct Vector{String*begin,*end,*capacity;};struct Owner{void*buffer;char gap[8];Vector strings;};
extern "C" void free_801fe240(void*);extern "C" void finish_8020c5c4(String*);extern "C" void release_80341588(String*);extern "C" void storage_802134fc(void*);extern "C" void destroy_801fe1f8(void*);
extern "C" void w3d_cx14b_string_vector_destroy_8020cb38(Owner*self,int flags){if(self->buffer)free_801fe240(self->buffer);self->buffer=0;Vector*v=&self->strings;String*p=v->begin,*end=v->end;if(p!=end)do{finish_8020c5c4(p);release_80341588(p);++p;}while(p!=end);if(v->begin)storage_802134fc(v->begin);if(flags&1)destroy_801fe1f8(self);}

