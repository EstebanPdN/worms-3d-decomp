
struct Cx8bTextSink;
struct Cx8bTextSinkVtable {void *unknown00[6];int (*write)(Cx8bTextSink *,const char *,unsigned int,int);};
struct Cx8bTextSink {Cx8bTextSinkVtable *vtable;};
struct Cx8bBooleanWriter {Cx8bTextSink *sink;};
extern "C" char text_803b3230[],text_803b3238[];
extern "C" Cx8bBooleanWriter *w3d_cx8b_text_write_boolean_8020d878(Cx8bBooleanWriter *self,int value) {
 if(value) self->sink->vtable->write(self->sink,text_803b3230,4,0);
 else self->sink->vtable->write(self->sink,text_803b3238,5,0);
 return self;
}

