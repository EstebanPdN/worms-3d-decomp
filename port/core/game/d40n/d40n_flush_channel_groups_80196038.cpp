#include "w3d_ptr.h"
#line 1 "d40n_flush_channel_groups_80196038.cpp"
// GWMP8P rev0 0x80196038. Sends active channel values to their sinks: walks
// the bindings with the value array and bit vector on real STLport 4.5.3,
// gathers values per sink group into a 32-entry buffer with a channel mask,
// and flushes each group when type or id changes, and the last one at the
// end. Names inferred.
#include "compat/stlport_sn_oom.h"
#include "compat/module_allocator.h"
#include <vector>
struct D40fSink {
    int u0;
    void w3d_r_s8() __asm__(W3D_SYM("_ZN8D40fSink2s8Ev")); void w3d_r_s12() __asm__(W3D_SYM("_ZN8D40fSink3s12Ev"));
    void w3d_r_Set(int id, unsigned mask, Ptr32<float> values) __asm__(W3D_SYM("_ZN8D40fSink3SetEijPf"));
 __attribute__((always_inline)) inline void s8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D40fSink, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D40fSink, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void Set(int w3d_a0, unsigned int w3d_a1, Ptr32<float> w3d_a2) { ((void (*)(w3d_u32, int, unsigned int, Ptr32<float>))w3d::vfn(this->w3d_vptr_D40fSink, 4))(w3d::h2g(this), w3d_a0, w3d_a1, w3d_a2); }  Ptr32<void> w3d_vptr_D40fSink; };
struct D40fBinding { int id; char u4; unsigned char type; unsigned char channel; char u7; Ptr32<D40fSink> sink; int u12; };
struct D40fMixer {
    char u0[24];
    Ptr32<float> values;
    char u28[28];
    _STL::vector<D40fBinding, ModuleAllocator<D40fBinding> > bindings;
    char u72[24];
    _STL::vector<bool, ModuleAllocator<bool> > active;
    void flush();
};
void D40fMixer::flush() {
    float buf[32];
    unsigned mask = 0;
    int type = 0xdeafbabe;
    int id = 0;
    Ptr32<D40fSink> sink = 0;
    const _STL::vector<bool, ModuleAllocator<bool> > &ca = active;
    _STL::vector<bool, ModuleAllocator<bool> >::const_iterator it = ca.begin();
    Ptr32<D40fBinding> e = bindings.begin();
    Ptr32<float> v = values;
    Ptr32<D40fBinding> last = bindings.end();
    do {
        if (e->type != type || e->id != id) {
            if (sink && mask) sink->Set(id, mask, buf);
            type = e->type;
            mask = 0;
            sink = e->sink;
            id = e->id;
        }
        unsigned char ch = e->channel;
        if (*it) {
            buf[ch] = *v;
            mask |= 1 << ch;
        }
        ++e;
        ++v;
        ++it;
    } while (e != last);
    if (sink && mask) { int lastId = bindings.rbegin()->id; sink->Set(lastId, mask, buf); }
}


