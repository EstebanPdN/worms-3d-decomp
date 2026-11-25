#include "w3d_ptr.h"
#line 1 "cc40b_apply_channels_80195fb0.cpp"
// Original 0x80195fb0; ProDG 3.7. Default external 0x803a84a4: 00000000 (decoded independently).
// Signed flags, low unsigned index, unsigned sample count, and unconditional first iteration are preserved.
// The 24-byte sample stride and observed fields are partial views, not recovered original declarations.
// Inferred partial channel views. No full class or allocation-size claim.
struct cc40b_ChannelSample { unsigned char unknown[4]; float value; unsigned char tail[16]; };
struct cc40b_ChannelPayload { Ptr32<cc40b_ChannelSample> samples; unsigned short sample; unsigned short unknown; };
struct cc40b_ChannelEntry { int flags_and_index; cc40b_ChannelPayload payload; };
struct cc40b_ChannelRange { Ptr32<cc40b_ChannelEntry> begin; Ptr32<cc40b_ChannelEntry> end; unsigned reserved[2]; };
struct cc40b_ChannelTable { unsigned char unknown[52]; Ptr32<cc40b_ChannelRange> ranges; };
struct cc40b_ChannelOwner { unsigned char unknown[24]; Ptr32<float> values; unsigned char gap[44]; Ptr32<cc40b_ChannelTable> table; };
inline float &cc40b_indexed(Ptr32<float> values,unsigned short index) { return values[index]; }
extern float cc40b_default_803a84a4[];
extern "C" void cc40b_apply_channels_80195fb0(Ptr32<cc40b_ChannelOwner> self,int index) {
    float fallback=cc40b_default_803a84a4[0];
    Ptr32<cc40b_ChannelRange> range=self->table->ranges+index;
    Ptr32<cc40b_ChannelEntry> entry=range->begin;
    Ptr32<cc40b_ChannelEntry> end=range->end;
    do {
        Ptr32<cc40b_ChannelPayload> payload=&entry->payload;
        if (entry->flags_and_index<0 && payload->samples) {
            if (payload->sample==0) cc40b_indexed(self->values,(unsigned short)entry->flags_and_index)=fallback;
            else cc40b_indexed(self->values,(unsigned short)entry->flags_and_index)=payload->samples[payload->sample-1].value;
        }
        ++entry;
    } while(entry!=end);
}


