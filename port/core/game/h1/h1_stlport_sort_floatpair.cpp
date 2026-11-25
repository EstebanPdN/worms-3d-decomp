#include "w3d_ptr.h"
#line 1 "h1_stlport_sort_floatpair.cpp"
/* STLport sort for an array of 8-byte {float key, int value} pairs in
 * descending key order (session b169b320): sort, __introsort_loop,
 * __unguarded_partition, __final_insertion_sort, __insertion_sort,
 * __unguarded_insertion_sort_aux, __unguarded_linear_insert, __partial_sort,
 * make_heap, pop_heap and __adjust_heap. The comparator holds one byte and
 * is created by an out-of-line constructor (0x803515a0); copy_backward is
 * STLport's element loop because the pair is not a trivial type to it. */

struct W3dFloatPair
{
    float key;
    int value;
};
struct W3dFloatPairGreater
{
    unsigned char unused;
    bool operator()(const W3dFloatPair &a, const W3dFloatPair &b) const { return a.key > b.key; }
};
#define W3D_STL_THRESHOLD 16
extern "C" W3dFloatPairGreater w3d_auto_803515a0(int);
extern "C" void w3d_auto_803518f8(Ptr32<W3dFloatPair> first, Ptr32<W3dFloatPair> middle, Ptr32<W3dFloatPair> last, W3dFloatPairGreater comp);
static inline void w3d_push_heap(Ptr32<W3dFloatPair> first, int holeIndex, int topIndex, W3dFloatPair val, W3dFloatPairGreater comp)
{
    int parent = (holeIndex - 1) / 2;
    while (holeIndex > topIndex && comp(*(first + parent), val)) {
        *(first + holeIndex) = *(first + parent);
        holeIndex = parent;
        parent = (holeIndex - 1) / 2;
    }
    *(first + holeIndex) = val;
}
extern "C" void w3d_adjust_heap_803515ac(Ptr32<W3dFloatPair> first, int holeIndex, int len, W3dFloatPair val, W3dFloatPairGreater comp)
{
    int topIndex = holeIndex;
    int secondChild = 2 * holeIndex + 2;
    while (secondChild < len) {
        if (comp(*(first + secondChild), *(first + (secondChild - 1))))
            secondChild--;
        *(first + holeIndex) = *(first + secondChild);
        holeIndex = secondChild;
        secondChild = 2 * (secondChild + 1);
    }
    if (secondChild == len) {
        *(first + holeIndex) = *(first + (secondChild - 1));
        holeIndex = secondChild - 1;
    }
    w3d_push_heap(first, holeIndex, topIndex, val, comp);
}

static inline void w3d_make_heap_impl(Ptr32<W3dFloatPair> first, Ptr32<W3dFloatPair> last, W3dFloatPairGreater comp, Ptr32<W3dFloatPair>, Ptr32<int>)
{
    if (last - first < 2)
        return;
    int len = last - first;
    int parent = (len - 2) / 2;
    for (;;) {
        w3d_adjust_heap_803515ac(first, parent, len, W3dFloatPair(*(first + parent)), comp);
        if (parent == 0)
            return;
        parent--;
    }
}

extern "C" void w3d_make_heap_80351710(Ptr32<W3dFloatPair> first, Ptr32<W3dFloatPair> last, W3dFloatPairGreater comp)
{
    w3d_make_heap_impl(first, last, comp, (Ptr32<W3dFloatPair>)0, (Ptr32<int>)0);
}

static inline void w3d_pop_heap_into(Ptr32<W3dFloatPair> first, Ptr32<W3dFloatPair> last, Ptr32<W3dFloatPair> result, W3dFloatPair val, W3dFloatPairGreater comp)
{
    *result = *first;
    w3d_adjust_heap_803515ac(first, 0, last - first, val, comp);
}

extern "C" void w3d_pop_heap_803517a4(Ptr32<W3dFloatPair> first, Ptr32<W3dFloatPair> last, W3dFloatPairGreater comp)
{
    w3d_pop_heap_into(first, last - 1, last - 1, *(last - 1), comp);
}

static inline void w3d_sort_heap(Ptr32<W3dFloatPair> first, Ptr32<W3dFloatPair> last, W3dFloatPairGreater comp)
{
    while (last - first > 1)
        w3d_pop_heap_803517a4(first, last--, comp);
}

extern "C" void w3d_partial_sort_80351804(Ptr32<W3dFloatPair> first, Ptr32<W3dFloatPair> middle, Ptr32<W3dFloatPair> last, Ptr32<W3dFloatPair>, W3dFloatPairGreater comp)
{
    w3d_make_heap_80351710(first, middle, comp);
    for (Ptr32<W3dFloatPair> i = middle; i < last; ++i)
        if (comp(*i, *first))
            w3d_pop_heap_into(first, middle, i, *i, comp);
    w3d_sort_heap(first, middle, comp);
}


static inline const W3dFloatPair &w3d_median(const W3dFloatPair &a, const W3dFloatPair &b, const W3dFloatPair &c, W3dFloatPairGreater comp)
{
    if (comp(a, b))
        if (comp(b, c))
            return b;
        else if (comp(a, c))
            return c;
        else
            return a;
    else if (comp(a, c))
        return a;
    else if (comp(b, c))
        return c;
    else
        return b;
}
static inline void w3d_iter_swap(Ptr32<W3dFloatPair> a, Ptr32<W3dFloatPair> b)
{
    W3dFloatPair tmp = *a;
    *a = *b;
    *b = tmp;
}
static inline Ptr32<W3dFloatPair> w3d_copy_backward(Ptr32<W3dFloatPair> first, Ptr32<W3dFloatPair> last, Ptr32<W3dFloatPair> result)
{
    for (int n = last - first; n > 0; --n)
        *--result = *--last;
    return result;
}

extern "C" Ptr32<W3dFloatPair> w3d_unguarded_partition_80351928(Ptr32<W3dFloatPair> first, Ptr32<W3dFloatPair> last, W3dFloatPair pivot, W3dFloatPairGreater comp)
{
    for (;;) {
        while (comp(*first, pivot))
            ++first;
        --last;
        while (comp(pivot, *last))
            --last;
        if (!(first < last))
            return first;
        w3d_iter_swap(first, last);
        ++first;
    }
}

extern "C" void w3d_introsort_loop_803519dc(Ptr32<W3dFloatPair> first, Ptr32<W3dFloatPair> last, Ptr32<W3dFloatPair>, int depth_limit, W3dFloatPairGreater comp)
{
    while (last - first > W3D_STL_THRESHOLD) {
        if (depth_limit == 0) {
            w3d_auto_803518f8(first, last, last, comp);
            return;
        }
        --depth_limit;
        Ptr32<W3dFloatPair> cut =
            w3d_unguarded_partition_80351928(first, last,
                                             W3dFloatPair(w3d_median(*first, *(first + (last - first) / 2), *(last - 1), comp)),
                                             comp);
        w3d_introsort_loop_803519dc(cut, last, (Ptr32<W3dFloatPair>)0, depth_limit, comp);
        last = cut;
    }
}

extern "C" void w3d_unguarded_linear_insert_80351b34(Ptr32<W3dFloatPair> last, W3dFloatPair val, W3dFloatPairGreater comp)
{
    Ptr32<W3dFloatPair> next = last;
    --next;
    while (comp(val, *next)) {
        *last = *next;
        last = next;
        --next;
    }
    *last = val;
}

static inline void w3d_linear_insert(Ptr32<W3dFloatPair> first, Ptr32<W3dFloatPair> last, W3dFloatPair val, W3dFloatPairGreater comp)
{
    if (comp(val, *first)) {
        w3d_copy_backward(first, last, last + 1);
        *first = val;
    }
    else
        w3d_unguarded_linear_insert_80351b34(last, val, comp);
}

extern "C" void w3d_insertion_sort_80351b9c(Ptr32<W3dFloatPair> first, Ptr32<W3dFloatPair> last, W3dFloatPairGreater comp)
{
    if (first == last)
        return;
    for (Ptr32<W3dFloatPair> i = first + 1; i != last; ++i)
        w3d_linear_insert(first, i, *i, comp);
}

extern "C" void w3d_unguarded_insertion_sort_80351c74(Ptr32<W3dFloatPair> first, Ptr32<W3dFloatPair> last, Ptr32<W3dFloatPair>, W3dFloatPairGreater comp)
{
    for (Ptr32<W3dFloatPair> i = first; i != last; ++i)
        w3d_unguarded_linear_insert_80351b34(i, W3dFloatPair(*i), comp);
}

static inline void w3d_unguarded_insertion_sort(Ptr32<W3dFloatPair> first, Ptr32<W3dFloatPair> last, W3dFloatPairGreater comp)
{
    w3d_unguarded_insertion_sort_80351c74(first, last, (Ptr32<W3dFloatPair>)0, comp);
}

extern "C" void w3d_final_insertion_sort_80351cdc(Ptr32<W3dFloatPair> first, Ptr32<W3dFloatPair> last, W3dFloatPairGreater comp)
{
    if (last - first > W3D_STL_THRESHOLD) {
        w3d_insertion_sort_80351b9c(first, first + W3D_STL_THRESHOLD, comp);
        w3d_unguarded_insertion_sort(first + W3D_STL_THRESHOLD, last, comp);
    }
    else
        w3d_insertion_sort_80351b9c(first, last, comp);
}


static inline int w3d_lg(int n)
{
    int k;
    for (k = 0; n != 1; n >>= 1)
        ++k;
    return k;
}

extern "C" void w3d_sort_80351d58(Ptr32<W3dFloatPair> first, Ptr32<W3dFloatPair> last)
{
    if (first != last) {
        w3d_introsort_loop_803519dc(first, last, (Ptr32<W3dFloatPair>)0, w3d_lg(last - first) * 2, w3d_auto_803515a0(0));
        w3d_final_insertion_sort_80351cdc(first, last, w3d_auto_803515a0(0));
    }
}



