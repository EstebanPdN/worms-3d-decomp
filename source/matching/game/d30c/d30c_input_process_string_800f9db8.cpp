// d30c: 0x800f9db8. Records a string input while the service is recording and accepts it; past 100 records builds a list object from the game queue at +60, empties the recording queue and sends the list on. Names are inferred.
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
    unsigned char u0[60];
    D24fVector<D24fTimedString> gameQueue;     // +60
    unsigned char u76[272];
    D24fVector<D24fTimedString> queue;     // +348
    unsigned char utail[68];
    int active;             // +432
};
extern "C" int can_accept_800f899c(Input *, const D24fTimedString *);
extern "C" Object *forward_8020b680(const void *);
extern "C" int *array_80240bf8(Object *, unsigned, int, void *);
extern "C" int *array_80240cc8(Object *, unsigned, int, void *);
extern "C" D24fSharedString *array_80240d98(Object *, unsigned, int, void *);
extern const unsigned char key_8041aa78[];
inline void flush(Input *self, D24fVector<D24fTimedString> *q) {
    Ref h(forward_8020b680(key_8041aa78));
    D24fVector<D24fTimedString> *g = &self->gameQueue;
    D24fTimedString *p = self->gameQueue.start;
    Object *o = h.value;
    unsigned n = g->finish - p;
    int *ids = array_80240bf8(o, n, 0, 0);
    int *values = array_80240cc8(o, n, 0, 0);
    D24fSharedString *names = array_80240d98(o, n, 0, 0);
    if (p != g->finish) do {
        *ids++ = p->id;
        *values++ = p->due;
        *names++ = p->name;
        p++;
    } while (p != g->finish);
    self->queue.clear();
    sink_804abac0->vtable->send(sink_804abac0, h.value);
}
extern "C" void d30c_input_process_string_800f9db8(Input *self, const D24fTimedString *x) {
    if (self->active && can_accept_800f899c(self, x)) {
        self->queue.push_back(*x);
        if (self->queue.size() > 100) flush(self, &self->queue);
    }
}
