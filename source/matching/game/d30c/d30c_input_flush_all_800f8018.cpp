// d30c: 0x800f8018. While recording, flushes each non-empty input queue (plain, string, word, two words, float, two floats): builds a list object with one array per field, empties the queue and sends the list to the sink. Names are inferred.
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
    Ref(const Ref &);
    Ref(Object *o) : value(o) { if (value) value->vtable->retain(value); }
    ~Ref() { if (value) value->vtable->release(value); }
};
struct Sink { struct V { void *u[10]; void (*send)(Sink *, Object *); } *vtable; };
extern Sink *sink_804abac0;
struct Input {
    unsigned char u0[316];
    D24fVector<D24fTimedRecord> plain;    // +316
    D24fVector<D24fTimedWord> words;      // +332
    D24fVector<D24fTimedString> strings;  // +348
    D24fVector<D24fTimedWord2> words2;    // +364
    D24fVector<D24fTimedFloat> floats;    // +380
    D24fVector<D24fTimedFloat2> floats2;  // +396
    unsigned char utail[20];
    int active;             // +432
};
extern "C" Object *forward_8020b680(const void *);
extern "C" int *array_80240bf8(Object *, unsigned, int, void *);
extern "C" int *array_80240cc8(Object *, unsigned, int, void *);
extern "C" D24fSharedString *array_80240d98(Object *, unsigned, int, void *);
extern "C" unsigned *array_80240e68(Object *, unsigned, int, void *);
extern "C" unsigned *array_80240f38(Object *, unsigned, int, void *);
extern "C" unsigned *array_80241008(Object *, unsigned, int, void *);
extern "C" float *array_802410d8(Object *, unsigned, int, void *);
extern "C" float *array_802411a8(Object *, unsigned, int, void *);
extern "C" float *array_80241278(Object *, unsigned, int, void *);
extern const unsigned char key_8041aa68[], key_8041aa78[], key_8041aa88[], key_8041aa98[], key_8041aaa8[], key_8041aab8[];
extern "C" void d30c_input_flush_all_800f8018(Input *self) {
    if (self->active) {
        if (self->plain.size()) {
            Ref h(forward_8020b680(key_8041aa68));
            D24fTimedRecord *p = self->plain.start;
            Object *o = h.value;
            D24fVector<D24fTimedRecord> *q = &self->plain;
            unsigned n = q->finish - p;
            int *ids = array_80240bf8(o, n, 0, 0);
            int *values = array_80240cc8(o, n, 0, 0);
            if (p != q->finish) do {
                *ids++ = p->id;
                *values++ = p->due;
                p++;
            } while (p != q->finish);
            self->plain.clear();
            sink_804abac0->vtable->send(sink_804abac0, h.value);
        }
        if (self->strings.size()) {
            Ref h(forward_8020b680(key_8041aa78));
            D24fTimedString *p = self->strings.start;
            Object *o = h.value;
            D24fVector<D24fTimedString> *q = &self->strings;
            unsigned n = q->finish - p;
            int *ids = array_80240bf8(o, n, 0, 0);
            int *values = array_80240cc8(o, n, 0, 0);
            D24fSharedString *names = array_80240d98(o, n, 0, 0);
            if (p != q->finish) do {
                *ids++ = p->id;
                *values++ = p->due;
                *names++ = p->name;
                p++;
            } while (p != q->finish);
            self->strings.clear();
            sink_804abac0->vtable->send(sink_804abac0, h.value);
        }
        if (self->words.size()) {
            Ref h(forward_8020b680(key_8041aa88));
            D24fTimedWord *p = self->words.start;
            Object *o = h.value;
            D24fVector<D24fTimedWord> *q = &self->words;
            unsigned n = q->finish - p;
            int *ids = array_80240bf8(o, n, 0, 0);
            int *values = array_80240cc8(o, n, 0, 0);
            unsigned *extras = array_80240e68(o, n, 0, 0);
            while (p != q->finish) {
                *ids++ = p->id;
                *values++ = p->due;
                *extras++ = p->extra;
                p++;
            }
            self->words.clear();
            sink_804abac0->vtable->send(sink_804abac0, h.value);
        }
        if (self->words2.size()) {
            Ref h(forward_8020b680(key_8041aa98));
            D24fTimedWord2 *p = self->words2.start;
            Object *o = h.value;
            D24fVector<D24fTimedWord2> *q = &self->words2;
            unsigned n = q->finish - p;
            int *ids = array_80240bf8(o, n, 0, 0);
            int *values = array_80240cc8(o, n, 0, 0);
            unsigned *extras = array_80240f38(o, n, 0, 0);
            unsigned *extras2 = array_80241008(o, n, 0, 0);
            while (p != q->finish) {
                *ids++ = p->id;
                *values++ = p->due;
                *extras++ = p->extra;
                *extras2++ = p->extra2;
                p++;
            }
            self->words2.clear();
            sink_804abac0->vtable->send(sink_804abac0, h.value);
        }
        if (self->floats.size()) {
            Ref h(forward_8020b680(key_8041aaa8));
            D24fTimedFloat *p = self->floats.start;
            Object *o = h.value;
            D24fVector<D24fTimedFloat> *q = &self->floats;
            unsigned n = q->finish - p;
            int *ids = array_80240bf8(o, n, 0, 0);
            int *values = array_80240cc8(o, n, 0, 0);
            float *extras = array_802410d8(o, n, 0, 0);
            while (p != q->finish) {
                *ids++ = p->id;
                *values++ = p->due;
                *extras++ = p->extra;
                p++;
            }
            self->floats.clear();
            sink_804abac0->vtable->send(sink_804abac0, h.value);
        }
        if (self->floats2.size()) {
            Ref h(forward_8020b680(key_8041aab8));
            D24fTimedFloat2 *p = self->floats2.start;
            Object *o = h.value;
            D24fVector<D24fTimedFloat2> *q = &self->floats2;
            unsigned n = q->finish - p;
            int *ids = array_80240bf8(o, n, 0, 0);
            int *values = array_80240cc8(o, n, 0, 0);
            float *extras = array_802411a8(o, n, 0, 0);
            float *extras2 = array_80241278(o, n, 0, 0);
            while (p != q->finish) {
                *ids++ = p->id;
                *values++ = p->due;
                *extras++ = p->extra;
                *extras2++ = p->extra2;
                p++;
            }
            self->floats2.clear();
            sink_804abac0->vtable->send(sink_804abac0, h.value);
        }
    }
}
