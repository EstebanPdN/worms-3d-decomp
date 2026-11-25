#include "w3d_ptr.h"
#line 1 "d18d_blend_channels_80195ea8.cpp"
// d18d: 0x80195ea8 (264 bytes). Blend one channel group of an animation
// blender: for every entry of group `index`, start from the stored channel
// value (or 0 when `reset` is set); entries with the sign bit set are first
// recorded in the group's evaluation cache, evaluated through 0x801961a8 at
// `time`, and blended as value * weight + base. Built with -mps-float (SN
// paired-single mode: one reserved 8-byte slot per saved FPR).
// Containers are vector-like views (start/finish/end_of_storage) indexed
// through an inline operator[]; only the fields used here are named.
template <class T> struct D18dVec {
    Ptr32<T> start;
    Ptr32<T> finish;
    Ptr32<T> end_of_storage;
    T &operator[](int i) { return start[i]; }
};
struct D18dBlendEntry {
    int flags_and_index;  // sign bit: evaluated; low halfword: channel index
    unsigned words[2];
};
struct D18dBlendRange { Ptr32<D18dBlendEntry> begin; Ptr32<D18dBlendEntry> end; unsigned unknown[2]; };
struct D18dBlendTable { unsigned char unknown[52]; Ptr32<D18dBlendRange> ranges; };
struct D18dBlendCache { unsigned unknown; D18dVec <Ptr32<D18dBlendEntry> > entries; unsigned tail; };
struct D18dBlendOwner {
    unsigned char unknown[24];
    D18dVec<float> values;            // +24
    unsigned char gap[36];
    Ptr32<D18dBlendTable> table;            // +72
    unsigned gap2;
    D18dVec<D18dBlendCache> caches;   // +80
};
extern "C" {
float w3d_blend_evaluate_801961a8(Ptr32<Ptr32<D18dBlendEntry>> slot, float time);
void d18d_blend_channels_80195ea8(Ptr32<D18dBlendOwner> self, int index, int reset, float weight, float time);
}
void d18d_blend_channels_80195ea8(Ptr32<D18dBlendOwner> self, int index, int reset, float weight, float time)
{
    Ptr32<D18dBlendRange> range = self->table->ranges + index;
    Ptr32<D18dBlendEntry> entry = range->begin; Ptr32<D18dBlendEntry> end = range->end;
    int cached = 0;
    do {
        float base;
        if (reset) base = 0.0f;
        else base = self->values[(unsigned short)entry->flags_and_index];
        if (entry->flags_and_index < 0) {
            self->caches[index].entries[cached] = entry;
            float value = w3d_blend_evaluate_801961a8(&self->caches[index].entries[cached], time);
            ++cached;
            self->values[(unsigned short)entry->flags_and_index] = value * weight + base;
        } else {
            self->values[(unsigned short)entry->flags_and_index] = base;
        }
        ++entry;
    } while (entry != end);
}


