#include "w3d_ptr.h"
#line 1 "d29c_payload_explode_800ec6a8.cpp"
// d29c: 0x800ec6a8. Payload explosion: finishes at once when not armed; otherwise plays the effect and, if a flag is set, sends the end message; else plays the sound, sends the named event, runs the two trace assertions (PayloadLogicEntity.cpp lines 823 and 827), removes itself, explodes and optionally creates bomblets. Names are inferred; classes are partial views.
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
struct StringHeader { unsigned short refs; };
struct String {
    Ptr32<char> text;
    String(const String &);
    ~String();
};
extern "C" void string_init_8020c5c0(Ptr32<String>);
extern "C" Ptr32<StringHeader> string_header_80341884(Ptr32<String>);
extern "C" void string_finish_8020c5c4(Ptr32<String>);
extern "C" void string_release_80341588(Ptr32<String>);
inline String::String(const String &o) {
    string_init_8020c5c0(this);
    text = o.text;
    string_header_80341884(this)->refs++;
}
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
inline bool operator!=(const String &a, const char *b) { return strcmp(a.text, b) != 0; }
struct Object;
struct ObjectVtable { Ptr32<void> u[4]; Ptr32<void (Ptr32<Object>)> release; };
struct Object { Ptr32<ObjectVtable> vtable; };
struct Holder {
    Ptr32<Object> value;
    Holder() {}
    Holder(const Holder &);
    ~Holder() { if (value) value->vtable->release(value); }
};
struct Type { unsigned char unknown00[20]; Ptr32<const Type> parent; };
inline bool is_a(Ptr32<const Type> t, Ptr32<const Type> target) {
    while (t != target) {
        if (t == t->parent) return false;
        t = t->parent;
    }
    return true;
}
struct Desc { char u0[256]; int bomblets; char u260[88]; char soundA[20]; String name; char soundB[1]; };
struct Message { unsigned short id; Ptr32<Ptr32<void>> vtable; };
struct Payload {
    struct V { Ptr32<void> u[5]; Ptr32<Ptr32<const Type> (Ptr32<Payload>)> type; }; Ptr32<struct V> vtable;
    char u4[80]; int stamp; int a88; int a92; char u96[4]; Ptr32<Object> h100; char u104[16]; int a120; char u124[68]; Ptr32<void> h192;
};
struct Sink { struct V { Ptr32<void> u[24]; Ptr32<void (Ptr32<Sink>, Ptr32<const char>, Ptr32<void>)> send; }; Ptr32<struct V> vtable; };
struct Scene { char u[108]; Ptr32<Sink> sink; };
extern Ptr32<Scene> scene_804b1788;
extern Ptr32<void> heap_804b1754;
extern int id_804aef08;
extern Ptr32<void> vt_8040db38[];
extern const Type type_80361860[], type_803618f0[];
extern const char empty_8038b568[], temp_8038b56c[], missed_8038b588[], file_8038b4c4[];
extern "C" Ptr32<void> empty_80341584(Ptr32<void>);
extern "C" Ptr32<Desc> desc_801797b4(Ptr32<void>);
extern "C" void over_800ecb20(Ptr32<Payload>);
extern "C" void effect_800ed9c8(Ptr32<Payload>, int, Ptr32<void>);
extern "C" Ptr32<Message> alloc_801613f0(Ptr32<void>, int);
extern "C" short msg_id_8015f5a0(Ptr32<void>, int);
extern "C" int post_8015fc58(Ptr32<Payload>, Ptr32<Message>);
extern "C" int assert_80022e20(Ptr32<const char>, Ptr32<const char>, int, Ptr32<void>);
extern "C" void remove_8015fd1c(Ptr32<Payload>);
extern "C" void explode_800eca14(Ptr32<Payload>, Ptr32<void>);
extern "C" void bomblets_800ebad8(Ptr32<Payload>, Ptr32<void>, Ptr32<void>, Ptr32<void>);
extern "C" void d29c_payload_explode_800ec6a8(Ptr32<Payload> self, Ptr32<void> a, Ptr32<void> b, Ptr32<void> c) {
    Ptr32<Desc> d = desc_801797b4(empty_80341584(self->h192));
    if (self->a120 != 0 || self->a88 == 0) {
        over_800ecb20(self);
        return;
    }
        int z = self->a92;
        if (z != 0) {
            effect_800ed9c8(self, 0, d->soundB);
            if (self->h100) self->h100->vtable->release(self->h100);
            self->h100 = 0;
            Ptr32<Message> m = alloc_801613f0(heap_804b1754, 8);
            m->id = msg_id_8015f5a0(&id_804aef08, 1);
            m->vtable = vt_8040db38;
            post_8015fc58(self, m);
            self->stamp = -1;
        } else {
            effect_800ed9c8(self, 0, d->soundA);
            String s(d->name);
            if (s != empty_8038b568) scene_804b1788->sink->vtable->send(scene_804b1788->sink, s.text, a);
            Holder t;
            t.value = 0;
            if (is_a(self->vtable->type(self), type_80361860) || is_a(self->vtable->type(self), type_803618f0))
                assert_80022e20(temp_8038b56c, file_8038b4c4, 823, &t);
            Holder n;
            n.value = 0;
            if (is_a(self->vtable->type(self), type_80361860) || is_a(self->vtable->type(self), type_803618f0))
                assert_80022e20(missed_8038b588, file_8038b4c4, 827, &n);
            remove_8015fd1c(self);
            explode_800eca14(self, a);
            if (d->bomblets) bomblets_800ebad8(self, a, b, c);
        }
}


