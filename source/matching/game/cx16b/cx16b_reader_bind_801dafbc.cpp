/* Observed holder with stream pointer +0, duplicated position +4/+8,
   and callback workspace +12. The input holder is consumed at function exit. */
struct Cx16bReadable { void **vtable; };
struct Cx16bReader { Cx16bReadable *held; int position,limit; char workspace[1]; };
extern "C" void w3d_cx16b_reader_bind_801dafbc(Cx16bReader *self,Cx16bReadable **input,int position)
{
    Cx16bReadable *incoming=*input;
    if(incoming)((void(*)(Cx16bReadable *))incoming->vtable[3])(incoming);
    Cx16bReadable *old=self->held;
    if(old)((void(*)(Cx16bReadable *))old->vtable[4])(old);
    Cx16bReadable *value=*input;
    self->position=position;
    self->held=value;
    self->limit=position;
    Cx16bReadable *stream=*input;
    ((void(*)(Cx16bReadable *,int,void *))stream->vtable[16])(stream,1,self->workspace);
    Cx16bReadable *consumed=*input;
    if(consumed)((void(*)(Cx16bReadable *))consumed->vtable[4])(consumed);
}
