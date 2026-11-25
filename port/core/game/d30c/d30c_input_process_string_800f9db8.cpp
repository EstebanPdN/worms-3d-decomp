#include "w3d_ptr.h"
#line 1 "d30c_input_process_string_800f9db8.cpp"
// d30c: 0x800f9db8. Records a string input while the service is recording and accepts it; past 100 records builds a list object from the game queue at +60, empties the recording queue and sends the list on. Names are inferred.
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
    unsigned char u0[60];
    D24fVector<D24fTimedString> gameQueue;     // +60
    unsigned char u76[272];
    D24fVector<D24fTimedString> queue;     // +348
    unsigned char utail[68];
    int active;             // +432
};
extern "C" int can_accept_800f899c(Ptr32<Input>, Ptr32<const D24fTimedString>);
extern "C" Ptr32<Object> forward_8020b680(Ptr32<const void>);
extern "C" Ptr32<int> array_80240bf8(Ptr32<Object>, unsigned, int, Ptr32<void>);
extern "C" Ptr32<int> array_80240cc8(Ptr32<Object>, unsigned, int, Ptr32<void>);
extern "C" Ptr32<D24fSharedString> array_80240d98(Ptr32<Object>, unsigned, int, Ptr32<void>);
extern const unsigned char key_8041aa78[];
inline void flush(Ptr32<Input> self, Ptr32<D24fVector < D24fTimedString >> q) {
    Ref h(forward_8020b680(key_8041aa78));
    Ptr32<D24fVector < D24fTimedString >> g = &self->gameQueue;
    Ptr32<D24fTimedString> p = self->gameQueue.start;
    Ptr32<Object> o = h.value;
    unsigned n = g->finish - p;
    Ptr32<int> ids = array_80240bf8(o, n, 0, 0);
    Ptr32<int> values = array_80240cc8(o, n, 0, 0);
    Ptr32<D24fSharedString> names = array_80240d98(o, n, 0, 0);
    if (p != g->finish) do {
        *ids++ = p->id;
        *values++ = p->due;
        *names++ = p->name;
        p++;
    } while (p != g->finish);
    self->queue.clear();
    sink_804abac0->vtable->send(sink_804abac0, h.value);
}
extern "C" void d30c_input_process_string_800f9db8(Ptr32<Input> self, Ptr32<const D24fTimedString> x) {
    if (self->active && can_accept_800f899c(self, x)) {
        self->queue.push_back(*x);
        if (self->queue.size() > 100) flush(self, &self->queue);
    }
}


