#include "w3d_ptr.h"
#line 1 "d33s_path_store_80005e1c.cpp"
/* GWMP8P rev0 0x80005e1c. Walks back from the best node, removes each node from both search tables and stores the path. Layouts follow a_path_search.cpp; names are inferred. */
#include "compat/stlport_sn_oom.h"
#include <vector>
#include <stl/_algobase.h>
struct D33sPathNode { char u0[12]; short cost; char u14[2]; Ptr32<D33sPathNode> link; };
struct D33sPathWhere { int bucket, index; };
struct D33sPathTable { char u[16388]; };
extern "C" Ptr32<D33sPathNode> w3d_path_table_find(Ptr32<D33sPathTable>, Ptr32<const D33sPathNode>, Ptr32<D33sPathWhere>);
extern "C" void w3d_path_table_erase(Ptr32<D33sPathTable>, Ptr32<const D33sPathWhere>);
typedef _STL::vector <Ptr32<D33sPathNode> > D33sPathVec;
struct D33sPathSearch {
    char u0[4];
    D33sPathTable open, closed;
    Ptr32<D33sPathNode> current; Ptr32<D33sPathNode> best;
    int iterations, status, remaining, first_cost;
    D33sPathVec path;
    int cursor;
    void store_path();
};
void D33sPathSearch::store_path() {
    cursor = 0;
    if (best->link) first_cost = best->link->cost;
    D33sPathVec stack;
    stack.push_back(best);
    best = 0;
    Ptr32<D33sPathNode> n = 0;
    n = stack.back()->link;
    while (n) {
        stack.push_back(n);
        D33sPathWhere where;
        if (w3d_path_table_find(&closed, n, &where)) w3d_path_table_erase(&closed, &where);
        if (w3d_path_table_find(&open, n, &where)) w3d_path_table_erase(&open, &where);
        n = stack.back()->link;
    }
    current = 0;
    remaining = stack.size();
    for (int i = 0; i < remaining; i++) {
        Ptr32<D33sPathNode> x = stack.back();
        stack.pop_back();
        path.push_back(x);
    }
}


