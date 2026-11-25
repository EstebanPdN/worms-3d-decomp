/* hashtable::_M_copy_from for an eight-byte value, from unmodified STLport 4.5.3.
 * The bucket vector's members are separate functions admitted at their own addresses. */
#include "compat/stlport_sn_oom.h"
#include <hash_map>

typedef std::hash_map<unsigned, int>::_Ht D29sTable_8035ded0;
typedef _STL::vector<void *, _STL::allocator<void *> > D29sBuckets_8035ded0;
template <> void D29sBuckets_8035ded0::reserve(unsigned);
template <> void D29sBuckets_8035ded0::_M_fill_insert(void **, unsigned, void *const &);
template void D29sTable_8035ded0::_M_copy_from(const D29sTable_8035ded0 &);
