// GWMP8P rev0 0x801979fc. Rebuilds a playback object's vector<bool> on real
// STLport 4.5.3: clears every bit, then for each enabled track sets the bit
// named by each flagged sample of the source's matching column, and clears
// the dirty flag. Names inferred; sibling of d33j_set_track_source_801944d0.
#include "compat/stlport_sn_oom.h"
#include "compat/module_allocator.h"
#include <vector>
struct D40nKey { int enabled; int a, b; };
struct D40nSample { int flags; int a, b; unsigned short Index() const { return ((const unsigned short *)&flags)[1]; } };
struct D40nColumn { _STL::vector<D40nSample, ModuleAllocator<D40nSample> > samples; };
struct D40nSource { char u0[52]; D40nColumn *columns; };
struct D40nPlayback {
    char u0[40];
    _STL::vector<D40nKey, ModuleAllocator<D40nKey> > keys;
    char u56[16];
    D40nSource *source;
    char u76[20];
    _STL::vector<bool, ModuleAllocator<bool> > bits;
    int dirty;
    void update();
};
void D40nPlayback::update() {
    _STL::vector<bool, ModuleAllocator<bool> >::iterator it = bits.begin();
    _STL::vector<bool, ModuleAllocator<bool> >::iterator last = bits.end();
    while (it != last) *it++ = false;
    D40nKey *k = keys.begin();
    D40nColumn *col = source->columns;
    D40nKey *e = keys.end();
    for (; k != e; ++k, ++col) {
        if (k->enabled) {
            D40nSample *s = col->samples.begin();
            D40nSample *se = col->samples.end();
            for (; s != se; ++s) {
                if (s->flags < 0) bits[s->Index()] = true;
            }
        }
    }
    dirty = 0;
}
