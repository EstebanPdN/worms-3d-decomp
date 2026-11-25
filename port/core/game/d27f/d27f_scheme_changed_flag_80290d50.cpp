#include "w3d_ptr.h"
#line 1 "d27f_scheme_changed_flag_80290d50.cpp"
// GWMP8P rev0 0x80290d50. Handles the scheme page's leave buttons, and
// otherwise compares the Q.* properties with GM.SchemeData: 23 integer
// settings, the name and 52 weapon slots through 0x8028fa7c. It stores
// whether anything differs into the named value property (kinds 0 or 1).
// Leaving asks for confirmation for user schemes and posts the no-team
// message otherwise. Fields are named after their property string addresses;
// the unit owns no data.
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
    Ptr32<const char> c_str() const { return text; }
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
};
struct MessageCache { unsigned short id; char unknown[6]; };
struct Message;
struct NoTeamMessage { unsigned short id; Ptr32<void> table; };
extern MessageCache lbl_804b0d4c, lbl_804b0d54;
extern Ptr32<void> lbl_804b1754;
extern char lbl_8040db38[];
extern char lbl_803d0174[], lbl_803d01dc[], lbl_803d01e8[], lbl_803d01f0[], lbl_803d01f8[], lbl_803d0204[], lbl_803d0210[], lbl_803d0218[], lbl_803d0220[], lbl_803d0228[], lbl_803d0230[], lbl_803d0238[], lbl_803d0244[], lbl_803d024c[], lbl_803d0254[], lbl_803d025c[], lbl_803d0264[], lbl_803d0270[], lbl_803d0278[], lbl_803d0284[], lbl_803d0290[], lbl_803d0298[], lbl_803d02a0[], lbl_803d02ac[], lbl_803d02bc[], lbl_803d02c4[], lbl_803d02cc[], lbl_803d02d4[], lbl_803d02dc[], lbl_803d02e4[], lbl_803d02ec[], lbl_803d02f8[], lbl_803d0300[], lbl_803d0308[], lbl_803d0310[], lbl_803d031c[], lbl_803d0324[], lbl_803d0330[], lbl_803d0338[], lbl_803d0340[], lbl_803d0348[], lbl_803d0350[], lbl_803d0358[], lbl_803d0360[], lbl_803d0368[], lbl_803d0370[], lbl_803d037c[], lbl_803d0384[], lbl_803d038c[], lbl_803d0394[], lbl_803d039c[], lbl_803d03a8[], lbl_803d03b0[], lbl_803d03b8[], lbl_803d03c4[], lbl_803d03cc[], lbl_803d03d4[], lbl_803d03e0[], lbl_803d03e8[], lbl_803d03f0[], lbl_803d03f8[], lbl_803d0400[], lbl_803d0408[], lbl_803d0414[], lbl_803d041c[], lbl_803d0428[], lbl_803d0430[], lbl_803d0438[], lbl_803d0444[], lbl_803d044c[], lbl_803d0454[], lbl_803d0460[], lbl_803d046c[], lbl_803d0478[], lbl_803d0484[], lbl_803d0494[], lbl_803d04c0[], lbl_803d04d4[], lbl_803d04e4[], lbl_803d04fc[];
extern "C" int w3d_constructor_lookup_name(Ptr32<const char> const &, Handle &);
extern "C" Ptr32<Obj> w3d_empty_80341584(Ptr32<Obj>); Ptr32<Obj> w3d_empty_803426b4(Ptr32<Obj>); Ptr32<Obj> w3d_constructor_native_c_80342a78(Ptr32<Obj>);
extern "C" Ptr32<Scheme> w3d_auto_801797b4(Ptr32<Obj>);
extern "C" int w3d_auto_800fc1f0(Ptr32<const char> const &, Ptr32<int>);
extern "C" int w3d_auto_800fc2b0(Ptr32<const char> const &, Ptr32<Ptr32<const char>>);
extern "C" void w3d_string_assign(Ptr32<String>, Ptr32<const char>);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" int w3d_s4_scheme_is_user_802931d4(Ptr32<void>);
extern "C" int w3d_s4_frontend_name_8028fa7c(Ptr32<void>, Ptr32<const char>, Ptr32<void>);
extern "C" int s9_update_value_80178c54(Ptr32<Obj>, Ptr32<int>), s9_update_value_80178d28(Ptr32<Obj>, Ptr32<int>);
extern "C" Ptr32<void> tsonnet_b33_arena_801613f0(Ptr32<void>, int);
extern "C" Ptr32<Message> w3d_message_string_init(Ptr32<void>, unsigned short, Ptr32<const char>);
extern "C" unsigned w3d_cached_message_id(Ptr32<MessageCache>, int);
extern "C" int w3d_message_post_current(Ptr32<void>);
inline int Same(Ptr32<const char> a, Ptr32<const char> b) { return strcmp(a, b) == 0; }
inline bool operator!=(const String &a, const String &b) { return strcmp(a.text, b.text) != 0; }
extern "C" void d27f_scheme_changed_flag_80290d50(Ptr32<void> self, String name) {
    if (name.Length() == 0)
        return;
    if (strcmp(name.text, lbl_803d04c0) == 0) {
        if (!w3d_s4_scheme_is_user_802931d4(self))
            goto not_user;
        Ptr32<void> m = tsonnet_b33_arena_801613f0(lbl_804b1754, 12);
        w3d_message_post_current(w3d_message_string_init(m, w3d_cached_message_id(&lbl_804b0d4c, 1), lbl_803d04d4));
        return;
    }
    if (Same(name.text, lbl_803d04e4)) {
        if (w3d_s4_scheme_is_user_802931d4(self)) {
            Ptr32<void> m = tsonnet_b33_arena_801613f0(lbl_804b1754, 12);
            w3d_message_post_current(w3d_message_string_init(m, w3d_cached_message_id(&lbl_804b0d4c, 1), lbl_803d04fc));
            return;
        }
    not_user:
        Ptr32<NoTeamMessage> n = (Ptr32<NoTeamMessage>)tsonnet_b33_arena_801613f0(lbl_804b1754, 8);
        n->id = w3d_cached_message_id(&lbl_804b0d54, 1);
        n->table = lbl_8040db38;
        w3d_message_post_current(n);
        return;
    }
    Handle value;
    int changed = 0;
    if (w3d_constructor_lookup_name(name.c_str(), value) < 0) {
        DebugNote(name);
        return;
    }
    int kind = ((Ptr32<int (Ptr32<Obj>)>)value.p->table[6])(value.p);
    if (kind > 1)
        return;
    if (kind < 0)
        return;
    Handle store;
    if (w3d_constructor_lookup_name(lbl_803d0174, store) < 0)
        return;
    Ptr32<Scheme> s = w3d_auto_801797b4(w3d_empty_80341584(store.p));
    int number;
    w3d_auto_800fc1f0(lbl_803d01dc, &number);
    if (s->value_01dc != number)
        changed = 1;
    w3d_auto_800fc1f0(lbl_803d01dc, &number);
    if (s->value_01dc != number)
        changed = 1;
    w3d_auto_800fc1f0(lbl_803d01e8, &number);
    if (s->value_01e8 != number)
        changed = 1;
    w3d_auto_800fc1f0(lbl_803d01f0, &number);
    if (s->value_01f0 != number)
        changed = 1;
    w3d_auto_800fc1f0(lbl_803d024c, &number);
    if (s->value_024c != number)
        changed = 1;
    w3d_auto_800fc1f0(lbl_803d01f8, &number);
    if (s->value_01f8 != number)
        changed = 1;
    w3d_auto_800fc1f0(lbl_803d0204, &number);
    if (s->value_0204 != number)
        changed = 1;
    w3d_auto_800fc1f0(lbl_803d0210, &number);
    if (s->value_0210 != number)
        changed = 1;
    w3d_auto_800fc1f0(lbl_803d0218, &number);
    if (s->value_0218 != number)
        changed = 1;
    w3d_auto_800fc1f0(lbl_803d0220, &number);
    if (s->value_0220 != number)
        changed = 1;
    w3d_auto_800fc1f0(lbl_803d0228, &number);
    if (s->value_0228 != number)
        changed = 1;
    w3d_auto_800fc1f0(lbl_803d0230, &number);
    if (s->value_0230 != number)
        changed = 1;
    w3d_auto_800fc1f0(lbl_803d0238, &number);
    if (s->value_0238 != number)
        changed = 1;
    w3d_auto_800fc1f0(lbl_803d0244, &number);
    if (s->value_0244 != number)
        changed = 1;
    w3d_auto_800fc1f0(lbl_803d0254, &number);
    if (s->value_0254 != number)
        changed = 1;
    w3d_auto_800fc1f0(lbl_803d025c, &number);
    if (s->value_025c != number)
        changed = 1;
    w3d_auto_800fc1f0(lbl_803d0264, &number);
    if (s->value_0264 != number)
        changed = 1;
    w3d_auto_800fc1f0(lbl_803d0270, &number);
    if (s->value_0270 != number)
        changed = 1;
    w3d_auto_800fc1f0(lbl_803d0278, &number);
    if (s->value_0278 != number)
        changed = 1;
    w3d_auto_800fc1f0(lbl_803d0284, &number);
    if (s->value_0284 != number)
        changed = 1;
    w3d_auto_800fc1f0(lbl_803d0290, &number);
    if (s->value_0290 != number)
        changed = 1;
    w3d_auto_800fc1f0(lbl_803d0298, &number);
    if (s->value_0298 != number)
        changed = 1;
    w3d_auto_800fc1f0(lbl_803d02a0, &number);
    if (s->value_02a0 != number)
        changed = 1;
    String typed;
    String current;
    Ptr32<const char> text;
    w3d_auto_800fc2b0(lbl_803d02ac, &text);
    w3d_string_assign(&typed, text);
    current = s->name;
    if (typed != current)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d02bc, s->slot_02bc) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d02c4, s->slot_02c4) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d02cc, s->slot_02cc) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d02d4, s->slot_02d4) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d02dc, s->slot_02dc) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d02e4, s->slot_02e4) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d02ec, s->slot_02ec) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d02f8, s->slot_02f8) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d0300, s->slot_0300) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d0308, s->slot_0308) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d0310, s->slot_0310) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d031c, s->slot_031c) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d0324, s->slot_0324) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d0330, s->slot_0330) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d0338, s->slot_0338) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d0340, s->slot_0340) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d0348, s->slot_0348) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d0350, s->slot_0350) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d0358, s->slot_0358) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d0360, s->slot_0360) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d0368, s->slot_0368) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d0370, s->slot_0370) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d037c, s->slot_037c) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d0384, s->slot_0384) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d038c, s->slot_038c) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d0394, s->slot_0394) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d039c, s->slot_039c) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d03a8, s->slot_03a8) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d03b0, s->slot_03b0) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d03b8, s->slot_03b8) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d03c4, s->slot_03c4) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d03cc, s->slot_03cc) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d03d4, s->slot_03d4) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d03e0, s->slot_03e0) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d03e8, s->slot_03e8) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d03f0, s->slot_03f0) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d03f8, s->slot_03f8) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d0400, s->slot_0400) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d0408, s->slot_0408) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d0414, s->slot_0414) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d041c, s->slot_041c) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d0428, s->slot_0428) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d0430, s->slot_0430) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d0438, s->slot_0438) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d0444, s->slot_0444) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d044c, s->slot_044c) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d0454, s->slot_0454) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d0460, s->slot_0460) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d046c, s->slot_046c) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d0478, s->slot_0478) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d0484, s->slot_0484) == 1)
        changed = 1;
    if (w3d_s4_frontend_name_8028fa7c(self, lbl_803d0494, s->slot_0494) == 1)
        changed = 1;
    switch (((Ptr32<int (Ptr32<Obj>)>)value.p->table[6])(value.p)) {
    case 0:
        s9_update_value_80178c54(w3d_empty_803426b4(value.p), &changed);
        break;
    case 1:
        s9_update_value_80178d28(w3d_constructor_native_c_80342a78(value.p), &changed);
        break;
    }
}


