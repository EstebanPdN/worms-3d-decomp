namespace Sol35d6PrepareStreamV2 {
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
inline unsigned sol35d6_prepare_stream_impl(
    Sol35d6PrepareStreamV2::State *self, Sol35d6PrepareStreamV2::Input *input,
    unsigned char channel,unsigned char mode, unsigned zero,unsigned one,
    unsigned capacity,unsigned threshold,unsigned limit) {
    using namespace Sol35d6PrepareStreamV2;
    self->total=zero;
    self->channel=channel;
    self->mode=mode;
    self->enabled=one;
    self->threshold=threshold;
    self->limit=limit;
    self->capacity=capacity;
    self->input=input;
    self->active=one;
    self->offset=zero;
    self->ready=one;
    unsigned bytes=input->bytes;
    self->bytes=bytes;
    if (bytes<capacity)
        sol35d6_zero_802eefe0(self->buffer+bytes,0,capacity-bytes);
    else bytes=capacity;
    self->state=2;
    return bytes;
}
typedef char Sol35d6StreamBufferOffset[(unsigned)&((Sol35d6PrepareStreamV2::State*)0)->buffer==96?1:-1];

extern "C" unsigned sol35d6_prepare_stream_801e4074_v2(Sol35d6PrepareStreamV2::State *self,
    Sol35d6PrepareStreamV2::Input *input,unsigned char channel,unsigned char mode) {
    return sol35d6_prepare_stream_impl(self,input,channel,mode,0,1,27456,54912,96096);
}
