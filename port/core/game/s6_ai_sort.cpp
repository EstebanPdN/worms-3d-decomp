#include "w3d_ptr.h"
#line 1 "s6_ai_sort.cpp"
extern "C" {
struct S6Plan { int kind; float cost; };
struct S6Plans { Ptr32<Ptr32<S6Plan>> begin; Ptr32<Ptr32<S6Plan>> end; Ptr32<Ptr32<S6Plan>> limit; };
void w3d_ai_sort_costs_800076c4(Ptr32<S6Plans> plans, int unused) {
    int index = 0;
    int sorted = 0;
    int count = plans->end - plans->begin;
    while (sorted < count - 1) {
        Ptr32<S6Plan> left = plans->begin[index];
        Ptr32<S6Plan> right = plans->begin[index+1];
        if (left->cost > right->cost) {
            plans->begin[index] = right;
            plans->begin[index+1] = left;
            sorted = 0;
            index++;
        } else if (index == sorted) {
            sorted++;
            index = sorted;
        } else {
            index++;
        }
        if (index == count - 1) index = sorted;
    }
}
}


