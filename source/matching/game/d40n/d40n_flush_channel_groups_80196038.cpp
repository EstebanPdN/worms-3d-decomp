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
    virtual void s8(); virtual void s12();
    virtual void Set(int id, unsigned mask, float *values);
};
struct D40fBinding { int id; char u4; unsigned char type; unsigned char channel; char u7; D40fSink *sink; int u12; };
struct D40fMixer {
    char u0[24];
    float *values;
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
    D40fSink *sink = 0;
    const _STL::vector<bool, ModuleAllocator<bool> > &ca = active;
    _STL::vector<bool, ModuleAllocator<bool> >::const_iterator it = ca.begin();
    D40fBinding *e = bindings.begin();
    float *v = values;
    D40fBinding *last = bindings.end();
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
