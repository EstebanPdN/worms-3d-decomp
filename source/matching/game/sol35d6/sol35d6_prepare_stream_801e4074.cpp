namespace Sol35d6PrepareStream {
struct Input { unsigned header[3]; unsigned bytes; };
struct State {
    unsigned char state; unsigned char unknown1[15];
    Input *input;
    unsigned char channel,mode; unsigned char unknown22[66];
    unsigned capacity,bytes; unsigned char *buffer;
    unsigned threshold,limit;
    unsigned char enabled; unsigned char unknown109[3];
    unsigned active,offset,ready,total;
};
extern "C" void *sol35d6_zero_802eefe0(void *,int,unsigned);
}
extern "C" unsigned sol35d6_prepare_stream_801e4074(
    Sol35d6PrepareStream::State *self, Sol35d6PrepareStream::Input *input,
    unsigned char channel,unsigned char mode) {
    using namespace Sol35d6PrepareStream;
    self->total=0;
    self->channel=channel;
    self->mode=mode;
    self->enabled=1;
    self->threshold=54912;
    self->limit=96096;
    self->capacity=27456;
    self->input=input;
    self->active=1;
    self->offset=0;
    self->ready=1;
    unsigned bytes=input->bytes;
    self->bytes=bytes;
    if (bytes<27456)
        sol35d6_zero_802eefe0(self->buffer+bytes,0,27456-bytes);
    else bytes=27456;
    self->state=2;
    return bytes;
}
typedef char Sol35d6StreamBufferOffset[(unsigned)&((Sol35d6PrepareStream::State*)0)->buffer==96?1:-1];
