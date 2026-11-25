#include "w3d_ptr.h"
#line 1 "d25c_input_process_float2_800fb60c.cpp"
// d25c: 0x800fb60c. Record an input while the service is recording (+432) and accepts it: push it
// on the D24fTimedFloat2 queue at +396; past 100 records, create a list object, copy each field into its
// arrays, empty the queue and send the list to the sink at 0x804abac0. Names are inferred.
#include "d25c_input_queue.h"
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<Object>)> retain;       // +12
    Ptr32<void (Ptr32<Object>)> release;      // +16
};
struct Object { Ptr32<ObjectVtable> vtable; };
struct Ref {
    Ptr32<Object> value;
    template <class W3dU> Ref(Ptr32<W3dU> w3d_p) : Ref((Object *)w3d_p.get()) {}
 Ref(Object *o) : value(o) { if (value) value->vtable->retain(value); }
    ~Ref() { if (value) value->vtable->release(value); }
};
struct Sink { struct V { Ptr32<void> u[10]; Ptr32<void (Ptr32<Sink>, Ptr32<Object>)> send; }; Ptr32<struct V> vtable; };
extern Ptr32<Sink> sink_804abac0;
struct Input {
    unsigned char u0[396];
    D24fVector<D24fTimedFloat2> queue;     // +396
    unsigned char utail[20];
    int active;             // +432
};
extern "C" int can_accept_800f899c(Ptr32<Input>, Ptr32<const D24fTimedFloat2>);
extern "C" Ptr32<Object> forward_8020b680(Ptr32<const void>);
extern "C" Ptr32<int> array_80240bf8(Ptr32<Object>, unsigned, int, Ptr32<void>);
extern "C" Ptr32<int> array_80240cc8(Ptr32<Object>, unsigned, int, Ptr32<void>);
extern "C" Ptr32<float> array_802411a8(Ptr32<Object>, unsigned, int, Ptr32<void>);
extern "C" Ptr32<float> array_80241278(Ptr32<Object>, unsigned, int, Ptr32<void>);
extern const unsigned char key_8041aab8[];
inline void flush(Ptr32<Input> self, Ptr32<D24fVector < D24fTimedFloat2 >> q) {
    Ref h(forward_8020b680(key_8041aab8));
    Ptr32<D24fTimedFloat2> p = self->queue.start;
    Ptr32<Object> o = h.value;
    unsigned n = q->finish - p;
    Ptr32<int> ids = array_80240bf8(o, n, 0, 0);
    Ptr32<int> values = array_80240cc8(o, n, 0, 0);
    Ptr32<float> as = array_802411a8(o, n, 0, 0);
    Ptr32<float> bs = array_80241278(o, n, 0, 0);
    while (p != q->finish) {
        *ids++ = p->id;
        *values++ = p->due;
        *as++ = p->extra;
        *bs++ = p->extra2;
        p++;
    }
    self->queue.clear();
    sink_804abac0->vtable->send(sink_804abac0, h.value);
}
extern "C" void d25c_input_process_float2_800fb60c(Ptr32<Input> self, Ptr32<const D24fTimedFloat2> x) {
    if (self->active && can_accept_800f899c(self, x)) {
        self->queue.push_back(*x);
        if (self->queue.size() > 100) flush(self, &self->queue);
    }
}


