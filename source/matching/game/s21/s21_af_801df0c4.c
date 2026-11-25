// desc: Appears to ask a stream object through a virtual slot to process this object's embedded block at offset 24 and return zero.
struct S21Stream;
struct S21StreamMethods { void (*reserved[37])(void); void (*process)(struct S21Stream *, void *, int); };
struct S21Stream { struct S21StreamMethods *methods; };
struct S21Block { char pad[24]; char block[4]; };
int w3d_s21_stream_process_801df0c4(struct S21Block *self, struct S21Stream *stream)
{
    stream->methods->process(stream, self->block, 0);
    return 0;
}
