#include "w3d_ptr.h"
#line 1 "d40j_reset_queue_times_80164070.cpp"
/* GWMP8P rev0 0x80164070. Rewrites the task manager's three category timer queues
 * after a time reset: each real STLport 4.5.3 priority_queue of {handle, value}
 * records is popped into a temporary, with every value except -1 replaced by the
 * new time, and assigned back. Then the manager's two time fields are set. Names are inferred. */
#include "compat/stlport_sn_oom.h"
#include <queue>
#include <vector>
struct D31sQueueRecord { int handle; int value; D31sQueueRecord(int h, int v) : handle(h), value(v) {} };
struct D31sQueueLess : _STL::binary_function<D31sQueueRecord, D31sQueueRecord, bool> {
    bool operator()(const D31sQueueRecord &a, const D31sQueueRecord &b) const;
};
typedef _STL::vector<D31sQueueRecord> D31sQueueVector;
typedef _STL::priority_queue<D31sQueueRecord, D31sQueueVector, D31sQueueLess> Q;
template <> D31sQueueVector &D31sQueueVector::operator=(const D31sQueueVector &);
namespace _STL {
template <> void pop_heap(Ptr32<D31sQueueRecord>, Ptr32<D31sQueueRecord>, D31sQueueLess);
template <> void push_heap(Ptr32<D31sQueueRecord>, Ptr32<D31sQueueRecord>, D31sQueueLess);
}
struct Cat { Ptr32<Q> queue; int u4; int u8; };
struct Table { char u[40]; Cat cats[3]; };
extern "C" void set_time_8034b3f8(Ptr32<Table>, int);
extern "C" void set_time2_8034b408(Ptr32<Table>, int);
struct Mgr { char u[28]; Ptr32<Table> table; };
extern "C" void empty_801651e4(Ptr32<Mgr>);
static inline void Each(Ptr32<Table> t, int value) {
    for (unsigned i = 0; i <= 2; i++) {
        if (t->cats[i].queue) {
            Q tmp;
            Ptr32<Q> src = t->cats[i].queue;
            while (src->size()) {
                const D31sQueueRecord &r = src->top();
                if (r.value == -1)
                    tmp.push(D31sQueueRecord(r.handle, -1));
                else
                    tmp.push(D31sQueueRecord(r.handle, value));
                src->pop();
            }
            *src = tmp;
        }
    }
    set_time_8034b3f8(t, value);
    set_time2_8034b408(t, value);
    
}
extern "C" int w3d_d40j_reset_queue_times_80164070(Ptr32<Mgr> self, int value) { Each(self->table, value); empty_801651e4(self); return 0; }


