#include "w3d_ptr.h"
#line 1 "k10a_name_registry_destroy_80069e94.cpp"
// Appears to be the destructor of a service-derived name registry: it clears a
// global, then its members are destroyed in reverse order - two strings, an array
// of 768 strings, four held interfaces, a name list and forty more held
// interfaces - before the service base.
#define VCALL(p, T, o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p) + (o))))
extern Ptr32<const void> w3d_vtable_8040ef98[];
extern Ptr32<void> w3d_global_804aaabc;
extern "C" void w3d_string_base_finish(Ptr32<void> string);
extern "C" void w3d_string_release(Ptr32<void> string);
extern "C" void w3d_name_list_destroy_800c45b8(Ptr32<void> list, int flags);
extern "C" void w3d_service_destroy_801628ec(Ptr32<void> self, int flags);

struct K10aString
{
    Ptr32<char> text;
    ~K10aString() { w3d_string_base_finish(this); w3d_string_release(this); }
};

struct K10aHeld
{
    Ptr32<void> held;
    ~K10aHeld() { if (held) VCALL(held, void (*)(void *), 16)(held); }
};

struct K10aNameList
{
    char words[56];
    ~K10aNameList() { w3d_name_list_destroy_800c45b8(this, 2); }
};

struct K10aObject
{
    Ptr32<const void> vtable;          // +0
    char pad4[24];
    K10aHeld held28;              // +28
    K10aHeld held32;              // +32
    K10aHeld held36;              // +36
    K10aHeld held40;              // +40
    K10aHeld held44;              // +44
    K10aHeld held48;              // +48
    K10aHeld held52;              // +52
    K10aHeld held56;              // +56
    K10aHeld held60;              // +60
    K10aHeld held64;              // +64
    K10aHeld held68;              // +68
    K10aHeld held72;              // +72
    K10aHeld held76;              // +76
    K10aHeld held80;              // +80
    K10aHeld held84;              // +84
    K10aHeld held88;              // +88
    K10aHeld held92;              // +92
    K10aHeld held96;              // +96
    K10aHeld held100;              // +100
    K10aHeld held104;              // +104
    K10aHeld held108;              // +108
    K10aHeld held112;              // +112
    K10aHeld held116;              // +116
    K10aHeld held120;              // +120
    K10aHeld held124;              // +124
    K10aHeld held128;              // +128
    K10aHeld held132;              // +132
    K10aHeld held136;              // +136
    K10aHeld held140;              // +140
    K10aHeld held144;              // +144
    K10aHeld held148;              // +148
    K10aHeld held152;              // +152
    K10aHeld held156;              // +156
    K10aHeld held160;              // +160
    K10aHeld held164;              // +164
    K10aHeld held168;              // +168
    K10aHeld held172;              // +172
    K10aHeld held176;              // +176
    K10aHeld held180;              // +180
    K10aHeld held184;              // +184
    K10aNameList names;          // +188
    K10aHeld held244;              // +244
    K10aHeld held248;              // +248
    K10aHeld held252;              // +252
    K10aHeld held256;              // +256
    char pad260[4];
    K10aString table[768];       // +264
    char pad3336[4];
    K10aString second;           // +3340
    K10aString third;            // +3344
    ~K10aObject() { w3d_global_804aaabc = 0; }
};

extern "C" void w3d_k10a_name_registry_destroy_80069e94(Ptr32<void> self, int flags)
{
    Ptr32<K10aObject> o = (Ptr32<K10aObject>)self;
    o->vtable = w3d_vtable_8040ef98;
    o->~K10aObject();
    w3d_service_destroy_801628ec(self, flags);
}


