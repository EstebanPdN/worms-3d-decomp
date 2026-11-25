// GWMP8P rev0 0x8034f9e8. vector<Entry>::_M_fill_insert from unmodified
// STLport 4.5.3 over the module allocator. Entry is one word plus a vector
// of one-word records, with its own inline copy and assignment; the vector's
// assignment is 0x8034f81c.
#include "compat/stlport_sn_oom.h"
#include <vector>
#include "compat/module_allocator.h"
struct D29sRecord4_8034f81c { int word; };
typedef std::vector<D29sRecord4_8034f81c, ModuleAllocator<D29sRecord4_8034f81c> > D29sVector_8034f81c;
template <> D29sVector_8034f81c &D29sVector_8034f81c::operator=(const D29sVector_8034f81c &);
struct D42kEntry {
    int key;
    D29sVector_8034f81c items;
    D42kEntry(const D42kEntry &o) : key(o.key), items(o.items) {}
    D42kEntry &operator=(const D42kEntry &o) { key = o.key; items = o.items; return *this; }
    ~D42kEntry() {}
};
typedef std::vector<D42kEntry, ModuleAllocator<D42kEntry> > D42kEntries;
template void D42kEntries::_M_fill_insert(D42kEntry *, unsigned, const D42kEntry &);
