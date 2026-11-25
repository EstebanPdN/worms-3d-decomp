#include "w3d_ptr.h"
#line 1 "d43k_pair_tree_insert_hint_80355fa0.cpp"
// GWMP8P rev0 0x80355fa0. Hinted insert of an ordered tree of records keyed
// on a word and a held interface pointer (_Rb_tree::insert_unique(iterator,
// value)), from unmodified STLport 4.5.3. The node insert 0x80355b6c and the
// plain insert 0x80355e40 live in their own units. The record size is taken
// from 0x80355b6c; set versus map is not witnessed here.
#include "compat/stlport_sn_oom.h"
#include <set>
struct D43kInterface;
struct D43kHeld {
    Ptr32<D43kInterface> pointer;
    bool operator<(const D43kHeld &o) const { return (unsigned)w3d::H(pointer) < (unsigned)w3d::H(o.pointer); }
};
struct D43kPairRecord {
    unsigned key;
    D43kHeld held;
    unsigned rest[15];
    bool operator<(const D43kPairRecord &o) const {
        return key < o.key || (key == o.key && held < o.held);
    }
};
typedef std::set<D43kPairRecord>::_Rep_type D43kPairTree;
template <> D43kPairTree::iterator D43kPairTree::_M_insert(Ptr32<_STL::_Rb_tree_node_base>, Ptr32<_STL::_Rb_tree_node_base>, const D43kPairTree::value_type &, Ptr32<_STL::_Rb_tree_node_base>);
template <> _STL::pair<D43kPairTree::iterator, bool> D43kPairTree::insert_unique(const D43kPairTree::value_type &);
template D43kPairTree::iterator D43kPairTree::insert_unique(D43kPairTree::iterator, const D43kPairTree::value_type &);


