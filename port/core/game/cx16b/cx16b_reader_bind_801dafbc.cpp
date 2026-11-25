#include "w3d_ptr.h"
#line 1 "cx16b_reader_bind_801dafbc.cpp"
/* Observed holder with stream pointer +0, duplicated position +4/+8,
   and callback workspace +12. The input holder is consumed at function exit. */
struct Cx16bReadable { Ptr32<Ptr32<void>> vtable; };
struct Cx16bReader { Ptr32<Cx16bReadable> held; int position,limit; char workspace[1]; };
extern "C" void w3d_cx16b_reader_bind_801dafbc(Ptr32<Cx16bReader> self,Ptr32<Ptr32<Cx16bReadable>> input,int position)
{
    Ptr32<Cx16bReadable> incoming=*input;
    if(incoming)((Ptr32<void (Ptr32<Cx16bReadable>)>)incoming->vtable[3])(incoming);
    Ptr32<Cx16bReadable> old=self->held;
    if(old)((Ptr32<void (Ptr32<Cx16bReadable>)>)old->vtable[4])(old);
    Ptr32<Cx16bReadable> value=*input;
    self->position=position;
    self->held=value;
    self->limit=position;
    Ptr32<Cx16bReadable> stream=*input;
    ((Ptr32<void (Ptr32<Cx16bReadable>, int, Ptr32<void>)>)stream->vtable[16])(stream,1,self->workspace);
    Ptr32<Cx16bReadable> consumed=*input;
}


