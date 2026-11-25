/* STLport sorting and heap algorithms over arrays of object pointers
 * (session b169b320), from _algo.c and _heap.c: __unguarded_partition,
 * __introsort_loop (median inlined; depth exhausted -> partial_sort via an
 * already recovered forwarder), __unguarded_linear_insert, __insertion_sort
 * (trivial copy_backward = memmove), __unguarded_insertion_sort_aux,
 * __final_insertion_sort, __adjust_heap (with __push_heap inlined),
 * make_heap, pop_heap and __partial_sort. Three instantiations: objects
 * ordered by the unsigned key at offset 0, and ascending and descending
 * orderings by the float at offset 8 (whose comparison GCC materializes as
 * a bool). The empty
 * comparator is passed by value, so every call site stores a one-byte
 * copy on the stack. */

extern "C" void *memmove(void *, const void *, unsigned int);
#define W3D_STL_THRESHOLD 16

static inline void *w3d_copy_trivial_backward(const void *first, const void *last, void *result)
{
    const int num = (const char *)last - (const char *)first;
    return (num > 0) ? memmove((char *)result - num, first, num) : result;
}

struct W3dKeyed
{
    unsigned int key;
};
struct W3dKeyLess
{
    bool operator()(const W3dKeyed *a, const W3dKeyed *b) const { return a->key < b->key; }
};

struct W3dScored
{
    int unknown_00;
    int unknown_04;
    float score;
};
struct W3dScoreLess
{
    bool operator()(const W3dScored *a, const W3dScored *b) const { return a->score < b->score; }
};
struct W3dScoreGreater
{
    bool operator()(const W3dScored *a, const W3dScored *b) const { return a->score > b->score; }
};

#define W3D_STLPORT_SORT_SET(T, CMP, ADJ, MAKE, POP, PSORT, PART, INTRO, ULI, INS, UINS, FINS, FWD) \
extern "C" void FWD(T **first, T **middle, T **last, CMP comp); \
static inline void w3d_push_heap_##ADJ(T ** first, int holeIndex, int topIndex, T *val, CMP comp) \
{ \
    int parent = (holeIndex - 1) / 2; \
    while (holeIndex > topIndex && comp(*(first + parent), val)) { \
        *(first + holeIndex) = *(first + parent); \
        holeIndex = parent; \
        parent = (holeIndex - 1) / 2; \
    } \
    *(first + holeIndex) = val; \
} \
extern "C" void ADJ(T ** first, int holeIndex, int len, T *val, CMP comp) \
{ \
    int topIndex = holeIndex; \
    int secondChild = 2 * holeIndex + 2; \
    while (secondChild < len) { \
        if (comp(*(first + secondChild), *(first + (secondChild - 1)))) \
            secondChild--; \
        *(first + holeIndex) = *(first + secondChild); \
        holeIndex = secondChild; \
        secondChild = 2 * (secondChild + 1); \
    } \
    if (secondChild == len) { \
        *(first + holeIndex) = *(first + (secondChild - 1)); \
        holeIndex = secondChild - 1; \
    } \
    w3d_push_heap_##ADJ(first, holeIndex, topIndex, val, comp); \
} \
\
extern "C" void MAKE(T ** first, T ** last, CMP comp) \
{ \
    if (last - first < 2) \
        return; \
    int len = last - first; \
    int parent = (len - 2) / 2; \
    for (;;) { \
        ADJ(first, parent, len, *(first + parent), comp); \
        if (parent == 0) \
            return; \
        parent--; \
    } \
} \
\
static inline void w3d_pop_heap_into_##ADJ(T ** first, T ** last, T ** result, T *val, CMP comp) \
{ \
    *result = *first; \
    ADJ(first, 0, last - first, val, comp); \
} \
\
extern "C" void POP(T ** first, T ** last, CMP comp) \
{ \
    w3d_pop_heap_into_##ADJ(first, last - 1, last - 1, *(last - 1), comp); \
} \
\
static inline void w3d_sort_heap_##ADJ(T ** first, T ** last, CMP comp) \
{ \
    while (last - first > 1) \
        POP(first, last--, comp); \
} \
\
extern "C" void PSORT(T ** first, T ** middle, T ** last) \
{ \
    CMP comp; \
    MAKE(first, middle, comp); \
    for (T ** i = middle; i < last; ++i) \
        if (comp(*i, *first)) \
            w3d_pop_heap_into_##ADJ(first, middle, i, *i, comp); \
    w3d_sort_heap_##ADJ(first, middle, comp); \
} \
\
\
static inline T *const &w3d_median_##ADJ(T *const &a, T *const &b, T *const &c, CMP comp) \
{ \
    if (comp(a, b)) \
        if (comp(b, c)) \
            return b; \
        else if (comp(a, c)) \
            return c; \
        else \
            return a; \
    else if (comp(a, c)) \
        return a; \
    else if (comp(b, c)) \
        return c; \
    else \
        return b; \
} \
static inline void w3d_iter_swap_##ADJ(T ** a, T ** b) \
{ \
    T *tmp = *a; \
    *a = *b; \
    *b = tmp; \
} \
static inline T ** w3d_copy_backward_##ADJ(T ** first, T ** last, T ** result) \
{ \
    return (T **)w3d_copy_trivial_backward(first, last, result); \
} \
\
extern "C" T ** PART(T ** first, T ** last, T *pivot, CMP comp) \
{ \
    for (;;) { \
        while (comp(*first, pivot)) \
            ++first; \
        --last; \
        while (comp(pivot, *last)) \
            --last; \
        if (!(first < last)) \
            return first; \
        w3d_iter_swap_##ADJ(first, last); \
        ++first; \
    } \
} \
\
extern "C" void INTRO(T ** first, T ** last, T **, int depth_limit, CMP comp) \
{ \
    while (last - first > W3D_STL_THRESHOLD) { \
        if (depth_limit == 0) { \
            FWD(first, last, last, comp); \
            return; \
        } \
        --depth_limit; \
        T ** cut = \
            PART(first, last, \
                                             (T *)(w3d_median_##ADJ(*first, *(first + (last - first) / 2), *(last - 1), comp)), \
                                             comp); \
        INTRO(cut, last, (T **)0, depth_limit, comp); \
        last = cut; \
    } \
} \
\
extern "C" void ULI(T ** last, T *val, CMP comp) \
{ \
    T ** next = last; \
    --next; \
    while (comp(val, *next)) { \
        *last = *next; \
        last = next; \
        --next; \
    } \
    *last = val; \
} \
\
static inline void w3d_linear_insert_##ADJ(T ** first, T ** last, T *val, CMP comp) \
{ \
    if (comp(val, *first)) { \
        w3d_copy_backward_##ADJ(first, last, last + 1); \
        *first = val; \
    } \
    else \
        ULI(last, val, comp); \
} \
\
extern "C" void INS(T ** first, T ** last, CMP comp) \
{ \
    if (first == last) \
        return; \
    for (T ** i = first + 1; i != last; ++i) \
        w3d_linear_insert_##ADJ(first, i, *i, comp); \
} \
\
extern "C" void UINS(T ** first, T ** last, T **, CMP comp) \
{ \
    for (T ** i = first; i != last; ++i) \
        ULI(i, (T *)(*i), comp); \
} \
\
static inline void w3d_unguarded_insertion_sort_##ADJ(T ** first, T ** last, CMP comp) \
{ \
    UINS(first, last, (T **)0, comp); \
} \
\
extern "C" void FINS(T ** first, T ** last, CMP comp) \
{ \
    if (last - first > W3D_STL_THRESHOLD) { \
        INS(first, first + W3D_STL_THRESHOLD, comp); \
        w3d_unguarded_insertion_sort_##ADJ(first + W3D_STL_THRESHOLD, last, comp); \
    } \
    else \
        INS(first, last, comp); \
}

W3D_STLPORT_SORT_SET(W3dKeyed, W3dKeyLess,
    w3d_adjust_heap_803539f8, w3d_make_heap_80353ad0, w3d_pop_heap_80353b54, w3d_partial_sort_80353b9c,
    w3d_unguarded_partition_80353ca8, w3d_introsort_loop_80353d1c, w3d_unguarded_linear_insert_80353e44,
    w3d_insertion_sort_80353e74, w3d_unguarded_insertion_sort_80353f18, w3d_final_insertion_sort_80353f70,
    w3d_stl_forward_80353c78)
W3D_STLPORT_SORT_SET(W3dScored, W3dScoreLess,
    w3d_adjust_heap_80354080, w3d_make_heap_80354198, w3d_pop_heap_8035421c, w3d_partial_sort_80354264,
    w3d_unguarded_partition_8035437c, w3d_introsort_loop_80354408, w3d_unguarded_linear_insert_80354560,
    w3d_insertion_sort_803545ac, w3d_unguarded_insertion_sort_8035465c, w3d_final_insertion_sort_803546b4,
    w3d_stl_forward_8035434c)
W3D_STLPORT_SORT_SET(W3dScored, W3dScoreGreater,
    w3d_adjust_heap_803547c4, w3d_make_heap_803548dc, w3d_pop_heap_80354960, w3d_partial_sort_803549a8,
    w3d_unguarded_partition_80354ac0, w3d_introsort_loop_80354b4c, w3d_unguarded_linear_insert_80354ca4,
    w3d_insertion_sort_80354cf0, w3d_unguarded_insertion_sort_80354da0, w3d_final_insertion_sort_80354df8,
    w3d_stl_forward_80354a90)
