#include "w3d_ptr.h"
#line 1 "d30s_string_index_80203370.cpp"
/* GWMP8P rev0 0x80203370. Returns the index of a string, adding it with the next index when
 * absent. Real STLport 4.5.3 map keyed by the one-word engine string, ordered by strcmp. */
#include "compat/stlport_sn_oom.h"
#include <map>
#include <string.h>
extern "C" void w3d_string_base_init(Ptr32<void>);
extern "C" Ptr32<unsigned short> w3d_string_header(Ptr32<const void>);
extern "C" void w3d_string_base_finish(Ptr32<void>);
extern "C" void w3d_string_release(Ptr32<void>);
struct D30sStr {
    Ptr32<char> text;
    D30sStr(const D30sStr &o) { w3d_string_base_init(this); text = o.text; ++*w3d_string_header(this); }
    ~D30sStr() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct D30sStrLess { bool operator()(const D30sStr &a, const D30sStr &b) const { return strcmp(a.text, b.text) < 0; }  char w3d_empty; };
typedef std::map<D30sStr, int, D30sStrLess> D30sStringIndex;
typedef D30sStringIndex::_Rep_type D30sStringTree;
template <> D30sStringTree::iterator D30sStringTree::insert_unique(D30sStringTree::iterator, const D30sStringTree::value_type &);
template <> void D30sStringTree::_M_erase(Ptr32<_STL::_Rb_tree_node < D30sStringTree::value_type >>);
struct D30sStringOwner { D30sStringIndex m; int count; };
extern "C" int d30s_string_index_80203370(Ptr32<D30sStringOwner> self, const D30sStr &key) {
    D30sStringIndex::iterator i = self->m.find(key);
    if (i != self->m.end()) return (*i).second;
    self->m[key] = self->count;
    return self->count++;
}


