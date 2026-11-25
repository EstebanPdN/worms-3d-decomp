#include "w3d_ptr.h"
#line 1 "d33j_set_track_source_801944d0.cpp"
/* GWMP8P rev0 0x801944d0. Attaches a track source to a playback object: retains the source, sizes the real
 * STLport 4.5.3 key and track vectors to the source's track count, counts each column's samples with a
 * negative id into a temporary array, stores those counts in the tracks and adds the track storage to a
 * global statistic. Then marks the object dirty and resizes the vector<bool> to the source's bit count,
 * new bits set. Names and field meanings are inferred. */
#include "compat/stlport_sn_oom.h"
#include "compat/module_allocator.h"
#include <vector>
extern "C" Ptr32<void> memset(Ptr32<void>, int, unsigned);
extern int track_bytes_804ab6e8;
struct D33jKey { float x, y, z; ~D33jKey() {} };
struct D33jWord { int v; ~D33jWord() {} };
struct D33jTrack { int counted; _STL::vector<D33jWord, ModuleAllocator<D33jWord> > words; };
struct D33jSample { int id; int a, b; ~D33jSample() {} };
struct D33jColumn { _STL::vector<D33jSample, ModuleAllocator<D33jSample> > samples; };
struct D33jInfo { int u0; unsigned tracks; unsigned bits; };
struct D33jSourceApi {
    void w3d_r_s0() __asm__(W3D_SYM("_ZN13D33jSourceApi2s0Ev"));
    void w3d_r_retain() __asm__(W3D_SYM("_ZN13D33jSourceApi6retainEv"));
    void w3d_r_release() __asm__(W3D_SYM("_ZN13D33jSourceApi7releaseEv"));
    void w3d_r_s3() __asm__(W3D_SYM("_ZN13D33jSourceApi2s3Ev"));
    void w3d_r_s4() __asm__(W3D_SYM("_ZN13D33jSourceApi2s4Ev"));
    void w3d_r_s5() __asm__(W3D_SYM("_ZN13D33jSourceApi2s5Ev"));
    Ptr32<D33jInfo> w3d_r_info() __asm__(W3D_SYM("_ZN13D33jSourceApi4infoEv"));
 __attribute__((always_inline)) inline void s0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D33jSourceApi, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void retain() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D33jSourceApi, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D33jSourceApi, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D33jSourceApi, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D33jSourceApi, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D33jSourceApi, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<D33jInfo> info() { return ((Ptr32<D33jInfo> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D33jSourceApi, 8))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_D33jSourceApi; };
struct D33jSource : D33jSourceApi { char u4[48] __attribute__((aligned(__alignof__(D33jSourceApi)))); _STL::vector<D33jColumn, ModuleAllocator<D33jColumn> > columns; };
struct D33jHandle {
    Ptr32<D33jSource> p;
    Ptr32<D33jSource> operator->() const { return p; }
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((D33jSource *)w3d_p.get()); }
 D33jHandle &operator=(D33jSource *q) { if (q) q->retain(); if (p) p->release(); p = q; return *this; }
};
typedef _STL::vector<D33jKey, ModuleAllocator<D33jKey> > D33jKeys;
typedef _STL::vector<D33jTrack, ModuleAllocator<D33jTrack> > D33jTracks;
template <> void D33jKeys::_M_fill_insert(Ptr32<D33jKey>, unsigned, const D33jKey &);
template <> void D33jTracks::_M_fill_insert(Ptr32<D33jTrack>, unsigned, const D33jTrack &);
struct D33jPlayback {
    char u0[40];
    D33jKeys keys;
    char u56[16];
    D33jHandle source;
    char u76[4];
    D33jTracks tracks;
    _STL::vector<bool, ModuleAllocator<bool> > bits;
    int dirty;
    int attach(Ptr32<D33jSource> s);
};
int D33jPlayback::attach(Ptr32<D33jSource> s) {
    source = s;
    Ptr32<D33jInfo> info = s->info();
    D33jKey def;
    def.x = def.y = 0.0f;
    def.z = 1.0f;
    keys.resize(info->tracks, def);
    Ptr32<int> counts = w3d::new_array<int>(info->tracks);
    memset(counts, 0, info->tracks * 4);
    unsigned i;
    for (i = 0; i < info->tracks; ++i) {
        for (unsigned j = 0; j < source->columns[i].samples.size(); ++j) {
            if (source->columns[i].samples[j].id < 0) counts[i]++;
        }
    }
    {
        D33jTrack t;
        tracks.resize(info->tracks, t);
    }
    for (i = 0; i < info->tracks; ++i) tracks[i].counted = counts[i];
    track_bytes_804ab6e8 += info->tracks * 20;
    w3d::delete_array(counts);
    dirty = 1;
    bits.resize(info->bits, true);
    return 0;
}


