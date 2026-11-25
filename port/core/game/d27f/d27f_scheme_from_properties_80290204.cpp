#include "w3d_ptr.h"
#line 1 "d27f_scheme_from_properties_80290204.cpp"
// GWMP8P rev0 0x80290204. Writes the question-page (Q.*) properties into the
// current GM.SchemeData record. When Q.Persist-style flag property
// 0x803d02b4 is set, it first marks a changed scheme name with '* %s' or, in
// mode 1, restores the base name. It then stores 23 integer settings and the
// scheme name, copies 52 weapon slots through 0x8028fa34, and posts the FE.P
// message. Fields are named after their property string addresses; the unit
// owns no data.
// Observed handle, descriptor, string and team record views; roles inferred.
struct Obj { Ptr32<Ptr32<void>> table; };
inline void retain(Ptr32<Obj> p) { if (p) ((Ptr32<void (Ptr32<Obj>)>)p->table[3])(p); }
inline void release(Ptr32<Obj> p) { if (p) ((Ptr32<void (Ptr32<Obj>)>)p->table[4])(p); }
struct Handle {
    Ptr32<Obj> p;
    Handle() : p(0) {}
    template <class W3dU> Handle(Ptr32<W3dU> w3d_p) : Handle((Obj *)w3d_p.get()) {}
 Handle(Obj *x) : p(x) { retain(p); }
    Handle(const Handle &o) : p(o.p) { retain(p); }
    ~Handle() { release(p); }
    Handle &operator=(const Handle &o) { Ptr32<Obj> next = o.p; if (next) { retain(next); release(p); p = next; } return *this; }
};
struct Descriptor_80178474 { int zero; unsigned type; Descriptor_80178474() : zero(0), type(58280) {} ~Descriptor_80178474(); };
extern "C" void w3d_string_base_finish(Ptr32<void>), w3d_string_release(Ptr32<void>), w3d_string_release_header(Ptr32<void>);
struct String_803426b8 {
    Ptr32<char> text;
    String_803426b8();
    template <class W3dU> String_803426b8(Ptr32<W3dU> w3d_p) : String_803426b8((const char *)w3d_p.get()) {}
 String_803426b8(const char *);
    String_803426b8(const String_803426b8 &);
    unsigned Length() const { return ((Ptr32<unsigned short>)text)[-2]; }
    ~String_803426b8() { w3d_string_base_finish(this); w3d_string_release(this); }
    String_803426b8 &operator=(const String_803426b8 &other) {
        ++*(Ptr32<unsigned short>)(other.text - 6);
        Ptr32<char> old = text;
        Ptr32<unsigned short> header = (Ptr32<unsigned short>)(old - 6);
        unsigned short references = --*header;
        if (!references)
            w3d_string_release_header(header);
        text = other.text;
        return *this;
    }
};
typedef String_803426b8 String;
extern "C" void w3d_string_base_init(Ptr32<String>);
extern "C" Ptr32<unsigned short> w3d_string_header(Ptr32<String>);
inline String_803426b8::String_803426b8(const String_803426b8 &other) {
    w3d_string_base_init(this);
    text = other.text;
    ++*w3d_string_header(this);
}
inline void DebugNote(String) {}
extern "C" void w3d_auto_8015f558(Ptr32<void>, int);
struct CacheBase { int prefix[2]; ~CacheBase() { w3d_auto_8015f558(this, 2); } };
struct Cache_8015f704 : CacheBase { String name __attribute__((aligned(__alignof__(CacheBase)))); template <class W3dU> Cache_8015f704(Ptr32<W3dU> w3d_p) : Cache_8015f704((const char *)w3d_p.get()) {}
 Cache_8015f704(const char *); };
struct Key { Ptr32<const char> text; template <class W3dU> Key(Ptr32<W3dU> w3d_p) : Key((const char *)w3d_p.get()) {}
 Key(const char *p) : text(p) {} };
struct Scheme {
    char pad0[20];
    String name;
    Ptr32<void> slot_0430;
    Ptr32<void> slot_0428;
    Ptr32<void> slot_046c;
    Ptr32<void> slot_044c;
    Ptr32<void> slot_0438;
    Ptr32<void> slot_02ec;
    Ptr32<void> slot_02e4;
    Ptr32<void> slot_02dc;
    int value_0244;
    Ptr32<void> slot_0494;
    Ptr32<void> slot_02d4;
    Ptr32<void> slot_02cc;
    Ptr32<void> slot_02c4;
    Ptr32<void> slot_03f8;
    Ptr32<void> slot_02bc;
    char pad84[4];
    Ptr32<void> slot_037c;
    Ptr32<void> slot_0370;
    Ptr32<void> slot_0300;
    Ptr32<void> slot_02f8;
    Ptr32<void> slot_0400;
    Ptr32<void> slot_0478;
    Ptr32<void> slot_0414;
    Ptr32<void> slot_0368;
    Ptr32<void> slot_0360;
    Ptr32<void> slot_0460;
    Ptr32<void> slot_0408;
    Ptr32<void> slot_0358;
    Ptr32<void> slot_0350;
    Ptr32<void> slot_0348;
    Ptr32<void> slot_0340;
    Ptr32<void> slot_0338;
    Ptr32<void> slot_0330;
    Ptr32<void> slot_0324;
    Ptr32<void> slot_031c;
    Ptr32<void> slot_0310;
    Ptr32<void> slot_0308;
    Ptr32<void> slot_0384;
    int value_0254;
    int value_01dc;
    char pad184[4];
    Ptr32<void> slot_03f0;
    Ptr32<void> slot_03e8;
    Ptr32<void> slot_03e0;
    Ptr32<void> slot_03d4;
    Ptr32<void> slot_0484;
    char pad208[4];
    Ptr32<void> slot_03cc;
    Ptr32<void> slot_041c;
    Ptr32<void> slot_03c4;
    Ptr32<void> slot_0444;
    Ptr32<void> slot_03b8;
    Ptr32<void> slot_03b0;
    Ptr32<void> slot_03a8;
    Ptr32<void> slot_039c;
    Ptr32<void> slot_0394;
    Ptr32<void> slot_038c;
    int value_0298;
    int value_0290;
    int value_02a0;
    int value_0210;
    int value_01f0;
    int value_0228;
    int value_0218;
    int value_01e8;
    int value_0270;
    int value_0238;
    Ptr32<void> slot_0454;
    int value_0204;
    int value_01f8;
    int value_0264;
    int value_0278;
    int value_0220;
    int value_025c;
    int value_0230;
    int value_0284;
    int value_024c;
    int value_02b4;
};
extern char lbl_803d0174[], lbl_803d01ac[], lbl_803d01c0[], lbl_803d01dc[], lbl_803d01e8[], lbl_803d01f0[], lbl_803d01f8[], lbl_803d0204[], lbl_803d0210[], lbl_803d0218[], lbl_803d0220[], lbl_803d0228[], lbl_803d0230[], lbl_803d0238[], lbl_803d0244[], lbl_803d024c[], lbl_803d0254[], lbl_803d025c[], lbl_803d0264[], lbl_803d0270[], lbl_803d0278[], lbl_803d0284[], lbl_803d0290[], lbl_803d0298[], lbl_803d02a0[], lbl_803d02ac[], lbl_803d02b4[], lbl_803d02bc[], lbl_803d02c4[], lbl_803d02cc[], lbl_803d02d4[], lbl_803d02dc[], lbl_803d02e4[], lbl_803d02ec[], lbl_803d02f8[], lbl_803d0300[], lbl_803d0308[], lbl_803d0310[], lbl_803d031c[], lbl_803d0324[], lbl_803d0330[], lbl_803d0338[], lbl_803d0340[], lbl_803d0348[], lbl_803d0350[], lbl_803d0358[], lbl_803d0360[], lbl_803d0368[], lbl_803d0370[], lbl_803d037c[], lbl_803d0384[], lbl_803d038c[], lbl_803d0394[], lbl_803d039c[], lbl_803d03a8[], lbl_803d03b0[], lbl_803d03b8[], lbl_803d03c4[], lbl_803d03cc[], lbl_803d03d4[], lbl_803d03e0[], lbl_803d03e8[], lbl_803d03f0[], lbl_803d03f8[], lbl_803d0400[], lbl_803d0408[], lbl_803d0414[], lbl_803d041c[], lbl_803d0428[], lbl_803d0430[], lbl_803d0438[], lbl_803d0444[], lbl_803d044c[], lbl_803d0454[], lbl_803d0460[], lbl_803d046c[], lbl_803d0478[], lbl_803d0484[], lbl_803d0494[], lbl_803d04a4[], lbl_803d04b8[];
extern Ptr32<void> lbl_804b1754;
struct Message;
extern "C" int w3d_constructor_lookup_name(const Key &, Handle &);
extern "C" Ptr32<Obj> w3d_empty_80341584(Ptr32<Obj>);
extern "C" Ptr32<Obj> w3d_auto_80179598(Ptr32<Obj>, Ptr32<Descriptor_80178474>);
extern "C" int w3d_auto_800fc1f0(const Key &, Ptr32<int>);
extern "C" int w3d_auto_800fc2b0(Ptr32<const char> const &, Ptr32<Ptr32<const char>>);
extern "C" int s8_property_read_800fc550(const Key &, Ptr32<const char>);
extern "C" void w3d_string_format(Ptr32<String>, Ptr32<const char>, ...);
extern "C" void w3d_string_assign(Ptr32<String>, Ptr32<const char>);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" void w3d_auto_8028fa34(Ptr32<void>, Ptr32<void>, Ptr32<const char>);
extern "C" Ptr32<Message> tsonnet_b33_arena_801613f0(Ptr32<void>, int); Ptr32<Message> w3d_message_string_init(Ptr32<Message>, unsigned short, Ptr32<const char>);
extern "C" unsigned w3d_cached_message_id(Ptr32<Cache_8015f704>, int);
extern "C" int w3d_message_post_current(Ptr32<Message>);
extern "C" void d27f_scheme_from_properties_80290204(Ptr32<void> self, int mode) {
    Handle scheme;
    int value;
    w3d_auto_800fc1f0(lbl_803d02b4, &value);
    int refresh = 0;
    if (value != 0) {
        Ptr32<const char> current;
        w3d_auto_800fc2b0(lbl_803d02ac, &current);
        refresh = 1;
        Ptr32<const char> base;
        w3d_auto_800fc2b0(lbl_803d04a4, &base);
        String marked;
        if (mode == 1)
            s8_property_read_800fc550(lbl_803d02ac, base);
        else if (current[0] != '*' && strcmp(base, current) != 0) {
            Ptr32<const char> text;
            w3d_auto_800fc2b0(current, &text);
            w3d_string_format(&marked, lbl_803d04b8, w3d::VA(text));
            s8_property_read_800fc550(lbl_803d02ac, marked.text);
        }
    }
    if (w3d_constructor_lookup_name(lbl_803d0174, scheme) >= 0) {
        Descriptor_80178474 descriptor;
        Handle info;
        info = Handle(w3d_auto_80179598(w3d_empty_80341584(scheme.p), &descriptor));
        w3d_auto_800fc1f0(lbl_803d01dc, &value);
        ((Ptr32<Scheme>)info.p)->value_01dc = value;
        w3d_auto_800fc1f0(lbl_803d01e8, &value);
        ((Ptr32<Scheme>)info.p)->value_01e8 = value;
        w3d_auto_800fc1f0(lbl_803d01f0, &value);
        ((Ptr32<Scheme>)info.p)->value_01f0 = value;
        w3d_auto_800fc1f0(lbl_803d024c, &value);
        ((Ptr32<Scheme>)info.p)->value_024c = value;
        w3d_auto_800fc1f0(lbl_803d01f8, &value);
        ((Ptr32<Scheme>)info.p)->value_01f8 = value;
        w3d_auto_800fc1f0(lbl_803d0204, &value);
        ((Ptr32<Scheme>)info.p)->value_0204 = value;
        w3d_auto_800fc1f0(lbl_803d0210, &value);
        ((Ptr32<Scheme>)info.p)->value_0210 = value;
        w3d_auto_800fc1f0(lbl_803d0218, &value);
        ((Ptr32<Scheme>)info.p)->value_0218 = value;
        w3d_auto_800fc1f0(lbl_803d0220, &value);
        ((Ptr32<Scheme>)info.p)->value_0220 = value;
        w3d_auto_800fc1f0(lbl_803d0228, &value);
        ((Ptr32<Scheme>)info.p)->value_0228 = value;
        w3d_auto_800fc1f0(lbl_803d0230, &value);
        ((Ptr32<Scheme>)info.p)->value_0230 = value;
        w3d_auto_800fc1f0(lbl_803d0238, &value);
        ((Ptr32<Scheme>)info.p)->value_0238 = value;
        w3d_auto_800fc1f0(lbl_803d0244, &value);
        ((Ptr32<Scheme>)info.p)->value_0244 = value;
        w3d_auto_800fc1f0(lbl_803d0254, &value);
        ((Ptr32<Scheme>)info.p)->value_0254 = value;
        w3d_auto_800fc1f0(lbl_803d025c, &value);
        ((Ptr32<Scheme>)info.p)->value_025c = value;
        w3d_auto_800fc1f0(lbl_803d0264, &value);
        ((Ptr32<Scheme>)info.p)->value_0264 = value;
        w3d_auto_800fc1f0(lbl_803d0270, &value);
        ((Ptr32<Scheme>)info.p)->value_0270 = value;
        w3d_auto_800fc1f0(lbl_803d0278, &value);
        ((Ptr32<Scheme>)info.p)->value_0278 = value;
        w3d_auto_800fc1f0(lbl_803d0284, &value);
        ((Ptr32<Scheme>)info.p)->value_0284 = value;
        w3d_auto_800fc1f0(lbl_803d0290, &value);
        ((Ptr32<Scheme>)info.p)->value_0290 = value;
        w3d_auto_800fc1f0(lbl_803d0298, &value);
        ((Ptr32<Scheme>)info.p)->value_0298 = value;
        w3d_auto_800fc1f0(lbl_803d02a0, &value);
        ((Ptr32<Scheme>)info.p)->value_02a0 = value;
        w3d_auto_800fc1f0(lbl_803d02b4, &value);
        ((Ptr32<Scheme>)info.p)->value_02b4 = value != 0;
        String name;
        Ptr32<const char> text;
        w3d_auto_800fc2b0(lbl_803d02ac, &text);
        w3d_string_assign(&name, text);
        { Ptr32<Scheme> t = (Ptr32<Scheme>)info.p; t->name = name; }
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_02bc, lbl_803d02bc);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_02c4, lbl_803d02c4);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_02cc, lbl_803d02cc);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_02d4, lbl_803d02d4);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_02dc, lbl_803d02dc);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_02e4, lbl_803d02e4);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_02ec, lbl_803d02ec);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_02f8, lbl_803d02f8);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_0300, lbl_803d0300);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_0308, lbl_803d0308);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_0310, lbl_803d0310);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_031c, lbl_803d031c);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_0324, lbl_803d0324);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_0330, lbl_803d0330);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_0338, lbl_803d0338);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_0340, lbl_803d0340);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_0348, lbl_803d0348);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_0350, lbl_803d0350);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_0358, lbl_803d0358);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_0360, lbl_803d0360);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_0368, lbl_803d0368);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_0370, lbl_803d0370);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_037c, lbl_803d037c);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_0384, lbl_803d0384);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_038c, lbl_803d038c);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_0394, lbl_803d0394);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_039c, lbl_803d039c);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_03a8, lbl_803d03a8);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_03b0, lbl_803d03b0);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_03b8, lbl_803d03b8);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_03c4, lbl_803d03c4);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_03cc, lbl_803d03cc);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_03d4, lbl_803d03d4);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_03e0, lbl_803d03e0);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_03e8, lbl_803d03e8);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_03f0, lbl_803d03f0);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_03f8, lbl_803d03f8);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_0400, lbl_803d0400);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_0408, lbl_803d0408);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_0414, lbl_803d0414);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_041c, lbl_803d041c);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_0428, lbl_803d0428);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_0430, lbl_803d0430);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_0438, lbl_803d0438);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_0444, lbl_803d0444);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_044c, lbl_803d044c);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_0454, lbl_803d0454);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_0460, lbl_803d0460);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_046c, lbl_803d046c);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_0478, lbl_803d0478);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_0484, lbl_803d0484);
        w3d_auto_8028fa34(self, ((Ptr32<Scheme>)info.p)->slot_0494, lbl_803d0494);
    }
    if (refresh == 1) {
        Cache_8015f704 cache(lbl_803d01ac);
        Ptr32<Message> m = tsonnet_b33_arena_801613f0(lbl_804b1754, 12);
        w3d_message_post_current(w3d_message_string_init(m, w3d_cached_message_id(&cache, 1), lbl_803d01c0));
    }
}


