#include "w3d_ptr.h"
#line 1 "d20d_sample_index_80195bc4.cpp"
/*
 * 0x80195bc4: evaluate one track of a channel mixer on its own.
 *
 * Returns 0x80004005 when the mixer has no channels. Otherwise every output
 * value is cleared to the float at 0x803a8480, the channels are applied for
 * the track (0x80195fb0), the track's weight is saved and the virtual
 * set-weight (vtable slot 16) is called with the float at 0x803a8484; the
 * optional post-processing step (0x801979fc) runs when enabled, the saved
 * weight is restored through the same virtual call and the result is
 * finished (0x80196038). Returns 0.
 *
 * The track is bound by reference before its weight is read. Offsets are
 * observed; field names are inferred.
 */
struct D20dMixTrack { float weight, start, rate; };
struct D20dMixer;
typedef Ptr32<void (Ptr32<D20dMixer>, int, float)> D20dSetWeight;
struct D20dMixer {
    Ptr32<D20dSetWeight> vtable;
    unsigned char unknown04[20];
    Ptr32<float> first; Ptr32<float> last;
    unsigned char unknown20[8];
    Ptr32<D20dMixTrack> trackFirst; Ptr32<D20dMixTrack> trackLast;
    unsigned char unknown30[8];
    Ptr32<void> channelFirst; Ptr32<void> channelLast;
    unsigned char unknown40[56];
    int postprocess;
};

extern "C" {
extern float w3d_f32_803a8480[], w3d_f32_803a8484[];
void cc40b_apply_channels_80195fb0(Ptr32<D20dMixer> self, int index);
void fn_801979fc(Ptr32<D20dMixer> self);
void fn_80196038(Ptr32<D20dMixer> self);
unsigned int d20d_sample_index_80195bc4(Ptr32<D20dMixer> self, int index);
}

unsigned int d20d_sample_index_80195bc4(Ptr32<D20dMixer> self, int index)
{
    if (self->channelFirst == self->channelLast) return 0x80004005;
    Ptr32<float> v = self->first; Ptr32<float> end = self->last;
    if (v != end) {
        float zero = w3d_f32_803a8480[0];
        do { *v = zero; ++v; } while (v != end);
    }
    cc40b_apply_channels_80195fb0(self, index);
    D20dMixTrack &t = self->trackFirst[index];
    float old = t.weight;
    self->vtable[16](self, index, w3d_f32_803a8484[0]);
    if (self->postprocess) fn_801979fc(self);
    self->vtable[16](self, index, old);
    fn_80196038(self);
    return 0;
}


