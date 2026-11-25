#include "w3d_ptr.h"
#line 1 "cc21a_audio_store_schedule_8012fff4.cpp"
// Observed layout through byte155. Semantic names remain offset-based.
struct Cc21aAudioState {Ptr32<void> vtable;char base[24];int field28,field32,field36,field40,field44,field48,field52,field56;char reserved60[12];int field72,field76;float field80,field84;int field88,field92,field96;float field100;int field104;float field108;int sample_rate,channels;int field120,field124,field128,field132,field136,field140,field144,field148,field152;};
extern "C" int cc21a_fn_8015fef0(Ptr32<Cc21aAudioState>);
extern "C" char cc21a_lbl_80410e40[];
extern "C" const float cc21a_lbl_8039dfe4[],cc21a_lbl_8039dfe8[];
extern "C" Ptr32<Cc21aAudioState> cc21a_audio_store_schedule_8012fff4(Ptr32<Cc21aAudioState> self){
cc21a_fn_8015fef0(self);float zero=cc21a_lbl_8039dfe4[0],one=cc21a_lbl_8039dfe8[0];self->vtable=cc21a_lbl_80410e40;
self->field32=-1;self->field100=one;self->field92=1;self->field28=0;self->field36=0;self->field40=0;self->field44=0;
self->field48=0;
self->field52=0;
self->field56=0;
self->field72=0;
self->field76=0;
self->field104=0;
self->field120=0;
self->field124=0;
self->field128=0;
self->field132=0;
self->field136=0;
self->field140=0;
self->field144=0;
self->field148=0;
self->field152=0;
self->field80=zero;
self->field88=0;
self->field84=zero;
self->field96=0;
self->field108=zero;self->sample_rate=22050;self->channels=2;return self;}

