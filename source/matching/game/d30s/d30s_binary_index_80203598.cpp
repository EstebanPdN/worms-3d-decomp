/* GWMP8P rev0 0x80203598. Returns the index of a 16-byte identifier, adding it with the next
 * index when absent. Real STLport 4.5.3 map keyed by a one-word class, with memcmp ordering. */
#include "compat/stlport_sn_oom.h"
#include <map>
#include <string.h>
struct D30sKey { const void *p; D30sKey(const void *q) : p(q) {} };
struct D30sKeyLess { bool operator()(const D30sKey &a, const D30sKey &b) const { return memcmp(a.p, b.p, 16) < 0; } };
typedef std::map<D30sKey, int, D30sKeyLess> D30sBinaryIndex;
typedef D30sBinaryIndex::_Rep_type D30sBinaryTree;
template <> D30sBinaryTree::iterator D30sBinaryTree::insert_unique(D30sBinaryTree::iterator, const D30sBinaryTree::value_type &);
template <> void D30sBinaryTree::_M_erase(_STL::_Rb_tree_node<D30sBinaryTree::value_type> *);
struct D30sBinaryOwner { D30sBinaryIndex m; int count; };
extern "C" int d30s_binary_index_80203598(D30sBinaryOwner *self, const void *key) {
    D30sBinaryIndex::iterator i = self->m.find(key);
    if (i != self->m.end()) return (*i).second;
    self->m[key] = self->count;
    return self->count++;
}
