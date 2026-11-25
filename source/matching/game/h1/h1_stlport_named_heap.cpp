/* STLport heap operations on {object handle, priority} entries (session
 * b169b320): push_heap (with __push_heap inlined), __adjust_heap and
 * pop_heap. The comparator puts higher priorities first and orders equal
 * priorities by the names of the objects the handles resolve to (a missing
 * object sorts last); its operator() is inlined at every comparison. */

struct W3dNamedObject;
struct W3dNamedObjectVtable
{
    void *unknown_00[5];
    void *(*name_string)(W3dNamedObject *self);   /* 0x14 */
};
struct W3dNamedObject
{
    W3dNamedObjectVtable *vtable;
};
extern "C" W3dNamedObject *w3d_s20_lookup_handle_object_80164fc8(int handle);
extern "C" const char *w3d_auto_801ffea8(void *string);
extern "C" int strcmp(const char *, const char *);

struct W3dNamedEntry
{
    int handle;
    unsigned int priority;
};

/* Higher priority first; equal priorities order by object name. */
struct W3dNamedEntryGreater
{
    unsigned char unused;
    bool operator()(const W3dNamedEntry &a, const W3dNamedEntry &b) const
    {
        if (a.priority == b.priority) {
            W3dNamedObject *oa = w3d_s20_lookup_handle_object_80164fc8(a.handle);
            W3dNamedObject *ob = w3d_s20_lookup_handle_object_80164fc8(b.handle);
            if (oa == 0 || ob == 0)
                return oa != 0;
            return strcmp(w3d_auto_801ffea8(oa->vtable->name_string(oa)),
                          w3d_auto_801ffea8(ob->vtable->name_string(ob))) == 1;
        }
        return a.priority > b.priority;
    }
};

static inline void w3d_push_heap(W3dNamedEntry *first, int holeIndex, int topIndex, W3dNamedEntry val, W3dNamedEntryGreater comp)
{
    int parent = (holeIndex - 1) / 2;
    while (holeIndex > topIndex && comp(*(first + parent), val)) {
        *(first + holeIndex) = *(first + parent);
        holeIndex = parent;
        parent = (holeIndex - 1) / 2;
    }
    *(first + holeIndex) = val;
}
extern "C" void w3d_adjust_heap_8034a568(W3dNamedEntry *first, int holeIndex, int len, W3dNamedEntry val, W3dNamedEntryGreater comp);
static inline void w3d_push_heap_aux(W3dNamedEntry *first, W3dNamedEntry *last, W3dNamedEntryGreater comp, int *, W3dNamedEntry *)
{
    w3d_push_heap(first, int((last - first) - 1), int(0), W3dNamedEntry(*(last - 1)), comp);
}

extern "C" void w3d_push_heap_8034a400(W3dNamedEntry *first, W3dNamedEntry *last, W3dNamedEntryGreater comp)
{
    w3d_push_heap_aux(first, last, comp, (int *)0, (W3dNamedEntry *)0);
}

extern "C" void w3d_adjust_heap_8034a568(W3dNamedEntry *first, int holeIndex, int len, W3dNamedEntry val, W3dNamedEntryGreater comp)
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

static inline void w3d_pop_heap_into(W3dNamedEntry *first, W3dNamedEntry *last, W3dNamedEntry *result, W3dNamedEntry val, W3dNamedEntryGreater comp)
{
    *result = *first;
    w3d_adjust_heap_8034a568(first, 0, last - first, val, comp);
}

extern "C" void w3d_pop_heap_8034a7fc(W3dNamedEntry *first, W3dNamedEntry *last, W3dNamedEntryGreater comp)
{
    w3d_pop_heap_into(first, last - 1, last - 1, *(last - 1), comp);
}

