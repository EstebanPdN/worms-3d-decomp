#include "w3d_ptr.h"
#line 1 "d30c_input_flush_all_800f8018.cpp"
// d30c: 0x800f8018. While recording, flushes each non-empty input queue (plain, string, word, two words, float, two floats): builds a list object with one array per field, empties the queue and sends the list to the sink. Names are inferred.
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
    Ref(const Ref &);
    template <class W3dU> Ref(Ptr32<W3dU> w3d_p) : Ref((Object *)w3d_p.get()) {}
 Ref(Object *o) : value(o) { if (value) value->vtable->retain(value); }
    ~Ref() { if (value) value->vtable->release(value); }
};
struct Sink { struct V { Ptr32<void> u[10]; Ptr32<void (Ptr32<Sink>, Ptr32<Object>)> send; }; Ptr32<struct V> vtable; };
extern Ptr32<Sink> sink_804abac0;
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
extern "C" Ptr32<Object> forward_8020b680(Ptr32<const void>);
extern "C" Ptr32<int> array_80240bf8(Ptr32<Object>, unsigned, int, Ptr32<void>);
extern "C" Ptr32<int> array_80240cc8(Ptr32<Object>, unsigned, int, Ptr32<void>);
extern "C" Ptr32<D24fSharedString> array_80240d98(Ptr32<Object>, unsigned, int, Ptr32<void>);
extern "C" Ptr32<unsigned int> array_80240e68(Ptr32<Object>, unsigned, int, Ptr32<void>);
extern "C" Ptr32<unsigned int> array_80240f38(Ptr32<Object>, unsigned, int, Ptr32<void>);
extern "C" Ptr32<unsigned int> array_80241008(Ptr32<Object>, unsigned, int, Ptr32<void>);
extern "C" Ptr32<float> array_802410d8(Ptr32<Object>, unsigned, int, Ptr32<void>);
extern "C" Ptr32<float> array_802411a8(Ptr32<Object>, unsigned, int, Ptr32<void>);
extern "C" Ptr32<float> array_80241278(Ptr32<Object>, unsigned, int, Ptr32<void>);
extern const unsigned char key_8041aa68[], key_8041aa78[], key_8041aa88[], key_8041aa98[], key_8041aaa8[], key_8041aab8[];
extern "C" void d30c_input_flush_all_800f8018(Ptr32<Input> self) {
    if (self->active) {
        if (self->plain.size()) {
            Ref h(forward_8020b680(key_8041aa68));
            Ptr32<D24fTimedRecord> p = self->plain.start;
            Ptr32<Object> o = h.value;
            Ptr32<D24fVector < D24fTimedRecord >> q = &self->plain;
            unsigned n = q->finish - p;
            Ptr32<int> ids = array_80240bf8(o, n, 0, 0);
            Ptr32<int> values = array_80240cc8(o, n, 0, 0);
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
            Ptr32<D24fTimedString> p = self->strings.start;
            Ptr32<Object> o = h.value;
            Ptr32<D24fVector < D24fTimedString >> q = &self->strings;
            unsigned n = q->finish - p;
            Ptr32<int> ids = array_80240bf8(o, n, 0, 0);
            Ptr32<int> values = array_80240cc8(o, n, 0, 0);
            Ptr32<D24fSharedString> names = array_80240d98(o, n, 0, 0);
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
            Ptr32<D24fTimedWord> p = self->words.start;
            Ptr32<Object> o = h.value;
            Ptr32<D24fVector < D24fTimedWord >> q = &self->words;
            unsigned n = q->finish - p;
            Ptr32<int> ids = array_80240bf8(o, n, 0, 0);
            Ptr32<int> values = array_80240cc8(o, n, 0, 0);
            Ptr32<unsigned int> extras = array_80240e68(o, n, 0, 0);
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
            Ptr32<D24fTimedWord2> p = self->words2.start;
            Ptr32<Object> o = h.value;
            Ptr32<D24fVector < D24fTimedWord2 >> q = &self->words2;
            unsigned n = q->finish - p;
            Ptr32<int> ids = array_80240bf8(o, n, 0, 0);
            Ptr32<int> values = array_80240cc8(o, n, 0, 0);
            Ptr32<unsigned int> extras = array_80240f38(o, n, 0, 0);
            Ptr32<unsigned int> extras2 = array_80241008(o, n, 0, 0);
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
            Ptr32<D24fTimedFloat> p = self->floats.start;
            Ptr32<Object> o = h.value;
            Ptr32<D24fVector < D24fTimedFloat >> q = &self->floats;
            unsigned n = q->finish - p;
            Ptr32<int> ids = array_80240bf8(o, n, 0, 0);
            Ptr32<int> values = array_80240cc8(o, n, 0, 0);
            Ptr32<float> extras = array_802410d8(o, n, 0, 0);
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
            Ptr32<D24fTimedFloat2> p = self->floats2.start;
            Ptr32<Object> o = h.value;
            Ptr32<D24fVector < D24fTimedFloat2 >> q = &self->floats2;
            unsigned n = q->finish - p;
            Ptr32<int> ids = array_80240bf8(o, n, 0, 0);
            Ptr32<int> values = array_80240cc8(o, n, 0, 0);
            Ptr32<float> extras = array_802411a8(o, n, 0, 0);
            Ptr32<float> extras2 = array_80241278(o, n, 0, 0);
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


