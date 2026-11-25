#include "w3d_ptr.h"
#line 1 "d29s_ranked_insert_80005a98.cpp"
/* Keeps the fifty lowest-ranked items sorted in an STLport vector. An item past the
 * cap and not better than the worst kept only lowers the best-rank mark; otherwise
 * it is inserted by rank, the overflow is dropped and the worst rank is refreshed. */
#include "compat/stlport_sn_oom.h"
#include <vector>

struct D29sRanked_80005a98 { char head[12]; short rank; };
struct D29sRankList_80005a98 {
    char head[32840];
    short worst;
    short best;
    _STL::vector <Ptr32<D29sRanked_80005a98> > items;
    char gap[8];
    int inserted;
};

extern "C" void d29s_ranked_insert_80005a98(Ptr32<D29sRankList_80005a98> list, Ptr32<D29sRanked_80005a98> item) {
    int rank = item->rank;
    int count = list->items.size();
    if (count < 50 || rank < list->worst) {
        if (rank <= list->best) {
            list->inserted++;
            int position = 0;
            for (int i = count - 1; i >= 0; i--) {
                if (list->items[i]->rank <= rank) {
                    position = i + 1;
                    break;
                }
            }
            list->items.insert(&list->items[position], item);
            if (count == 50) {
                if (list->worst < list->best)
                    list->best = list->worst;
                list->items.pop_back();
            }
            list->worst = list->items[list->items.size() - 1]->rank;
        }
    } else if (rank < list->best) {
        list->best = item->rank;
    }
}


