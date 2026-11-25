// d25c: 0x800f94e8. Record an input while the service is recording (+432) and accepts it: push it
// on the D24fTimedWord queue at +332; past 100 records, create a list object, copy each field into its
// arrays, empty the queue and send the list to the sink at 0x804abac0. Names are inferred.
#include "d25c_input_queue.h"
struct Object;
struct ObjectVtable {
    void *unknown00[3];
    void (*retain)(Object *);       // +12
    void (*release)(Object *);      // +16
};
struct Object { ObjectVtable *vtable; };
struct Ref {
    Object *value;
    Ref(Object *o) : value(o) { if (value) value->vtable->retain(value); }
    ~Ref() { if (value) value->vtable->release(value); }
};
struct Sink { struct V { void *u[10]; void (*send)(Sink *, Object *); } *vtable; };
extern Sink *sink_804abac0;
struct Input {
    unsigned char u0[332];
    D24fVector<D24fTimedWord> queue;     // +332
    unsigned char utail[84];
    int active;             // +432
};
extern "C" int can_accept_800f899c(Input *, const D24fTimedWord *);
extern "C" Object *forward_8020b680(const void *);
extern "C" int *array_80240bf8(Object *, unsigned, int, void *);
extern "C" int *array_80240cc8(Object *, unsigned, int, void *);
extern "C" int *array_80240e68(Object *, unsigned, int, void *);
extern const unsigned char key_8041aa88[];
inline void flush(Input *self, D24fVector<D24fTimedWord> *q) {
    Ref h(forward_8020b680(key_8041aa88));
    D24fTimedWord *p = self->queue.start;
    Object *o = h.value;
    unsigned n = q->finish - p;
    int *ids = array_80240bf8(o, n, 0, 0);
    int *values = array_80240cc8(o, n, 0, 0);
    int *extras = array_80240e68(o, n, 0, 0);
    while (p != q->finish) {
        *ids++ = p->id;
        *values++ = p->due;
        *extras++ = p->extra;
        p++;
    }
    self->queue.clear();
    sink_804abac0->vtable->send(sink_804abac0, h.value);
}
extern "C" void d25c_input_process_16byte_800f94e8(Input *self, const D24fTimedWord *x) {
    if (self->active && can_accept_800f899c(self, x)) {
        self->queue.push_back(*x);
        if (self->queue.size() > 100) flush(self, &self->queue);
    }
}
