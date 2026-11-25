struct Cx7bWordStream;
struct Cx7bWordStreamVtable { void *unknown[10]; int (*write)(Cx7bWordStream *,unsigned int,int,int); };
struct Cx7bWordStream { Cx7bWordStreamVtable *vtable; };
extern "C" int w3d_cx7b_stream_write_words_802043b8(Cx7bWordStream *self,const unsigned int *words,unsigned int count) {
 for(unsigned int i=0;i<count;++i) self->vtable->write(self,*words++,0,0);
 return 0;
}
