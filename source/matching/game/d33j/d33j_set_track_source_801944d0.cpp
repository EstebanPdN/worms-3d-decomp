/* GWMP8P rev0 0x801944d0. Attaches a track source to a playback object: retains the source, sizes the real
 * STLport 4.5.3 key and track vectors to the source's track count, counts each column's samples with a
 * negative id into a temporary array, stores those counts in the tracks and adds the track storage to a
 * global statistic. Then marks the object dirty and resizes the vector<bool> to the source's bit count,
 * new bits set. Names and field meanings are inferred. */
#include "compat/stlport_sn_oom.h"
#include "compat/module_allocator.h"
#include <vector>
extern "C" void *memset(void *, int, unsigned);
extern int track_bytes_804ab6e8;
struct D33jKey { float x, y, z; ~D33jKey() {} };
struct D33jWord { int v; ~D33jWord() {} };
struct D33jTrack { int counted; _STL::vector<D33jWord, ModuleAllocator<D33jWord> > words; };
struct D33jSample { int id; int a, b; ~D33jSample() {} };
struct D33jColumn { _STL::vector<D33jSample, ModuleAllocator<D33jSample> > samples; };
struct D33jInfo { int u0; unsigned tracks; unsigned bits; };
struct D33jSourceApi {
    virtual void s0();
    virtual void retain();
    virtual void release();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual D33jInfo *info();
};
struct D33jSource : D33jSourceApi { char u4[48]; _STL::vector<D33jColumn, ModuleAllocator<D33jColumn> > columns; };
struct D33jHandle {
    D33jSource *p;
    D33jSource *operator->() const { return p; }
    D33jHandle &operator=(D33jSource *q) { if (q) q->retain(); if (p) p->release(); p = q; return *this; }
};
typedef _STL::vector<D33jKey, ModuleAllocator<D33jKey> > D33jKeys;
typedef _STL::vector<D33jTrack, ModuleAllocator<D33jTrack> > D33jTracks;
template <> void D33jKeys::_M_fill_insert(D33jKey *, unsigned, const D33jKey &);
template <> void D33jTracks::_M_fill_insert(D33jTrack *, unsigned, const D33jTrack &);
struct D33jPlayback {
    char u0[40];
    D33jKeys keys;
    char u56[16];
    D33jHandle source;
    char u76[4];
    D33jTracks tracks;
    _STL::vector<bool, ModuleAllocator<bool> > bits;
    int dirty;
    int attach(D33jSource *s);
};
int D33jPlayback::attach(D33jSource *s) {
    source = s;
    D33jInfo *info = s->info();
    D33jKey def;
    def.x = def.y = 0.0f;
    def.z = 1.0f;
    keys.resize(info->tracks, def);
    int *counts = new int[info->tracks];
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
    delete[] counts;
    dirty = 1;
    bits.resize(info->bits, true);
    return 0;
}
