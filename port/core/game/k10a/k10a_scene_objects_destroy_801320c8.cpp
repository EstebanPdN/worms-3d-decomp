#include "w3d_ptr.h"
#line 1 "k10a_scene_objects_destroy_801320c8.cpp"
// Appears to be the destructor of a service-derived scene object that owns about a hundred held interfaces, two strings, a small held array and a handle member.
// Member classes have real inline destructors; the explicit destructor call
// reproduces the compiler's reverse-order member cleanup before the base.
#define VCALL(p, T, o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p) + (o))))
extern Ptr32<const void> w3d_vtable_80410e80[];
extern "C" void w3d_string_base_finish(Ptr32<void> string);
extern "C" void w3d_string_release(Ptr32<void> string);
extern "C" void w3d_actor_handle_member_destroy(Ptr32<void> member, int flags);
extern "C" void w3d_handle_storage_release(Ptr32<void> storage);
extern "C" void w3d_base_destroy_8015ff2c(Ptr32<void> self, int flags);

struct K10aHeld
{
    Ptr32<void> held;
    ~K10aHeld() { if (held) VCALL(held, void (*)(void *), 16)(held); }
};

struct K10aString
{
    Ptr32<char> text;
    ~K10aString() { w3d_string_base_finish(this); w3d_string_release(this); }
};

struct K10aHandle
{
    Ptr32<void> word;
    ~K10aHandle() { w3d_actor_handle_member_destroy(this, 2); }
};

struct K10aStorage
{
    Ptr32<void> block;
    ~K10aStorage() { if (block) w3d_handle_storage_release(block); }
};

struct K10aObject
{
    Ptr32<const void> vtable;          // +0
    char pad4[24];
    K10aHeld held28;              // +28
    K10aHeld held32;              // +32
    K10aHeld held36;              // +36
    K10aHeld held40[3];        // +40
    char pad52[24];
    K10aHeld held76;              // +76
    K10aHeld held80;              // +80
    K10aHeld held84;              // +84
    K10aHeld held88;              // +88
    K10aHeld held92;              // +92
    K10aHeld held96;              // +96
    K10aHeld held100;              // +100
    K10aHeld held104;              // +104
    K10aHeld held108;              // +108
    char pad112[4];
    K10aString string116;              // +116
    K10aString string120;              // +120
    char pad124[40];
    K10aHeld held164;              // +164
    K10aHeld held168;              // +168
    K10aHeld held172;              // +172
    char pad176[8];
    K10aHeld held184;              // +184
    K10aHeld held188;              // +188
    K10aHeld held192;              // +192
    K10aHeld held196;              // +196
    K10aHeld held200;              // +200
    K10aHeld held204;              // +204
    K10aHeld held208;              // +208
    K10aHeld held212;              // +212
    K10aHeld held216;              // +216
    K10aHeld held220;              // +220
    K10aHeld held224;              // +224
    K10aHeld held228;              // +228
    K10aHeld held232;              // +232
    K10aHeld held236;              // +236
    K10aHeld held240;              // +240
    K10aHeld held244;              // +244
    K10aHeld held248;              // +248
    K10aHeld held252;              // +252
    K10aHeld held256;              // +256
    K10aHeld held260;              // +260
    K10aHeld held264;              // +264
    K10aHeld held268;              // +268
    K10aHeld held272;              // +272
    K10aHeld held276;              // +276
    K10aHeld held280;              // +280
    K10aHeld held284;              // +284
    K10aHeld held288;              // +288
    K10aHeld held292;              // +292
    K10aHeld held296;              // +296
    K10aHeld held300;              // +300
    K10aHeld held304;              // +304
    K10aHeld held308;              // +308
    K10aHeld held312;              // +312
    K10aHeld held316;              // +316
    K10aHeld held320;              // +320
    K10aHeld held324;              // +324
    K10aHeld held328;              // +328
    K10aHeld held332;              // +332
    K10aHeld held336;              // +336
    K10aHeld held340;              // +340
    K10aHeld held344;              // +344
    K10aHeld held348;              // +348
    K10aHeld held352;              // +352
    K10aHeld held356;              // +356
    K10aHeld held360;              // +360
    K10aHeld held364;              // +364
    K10aHeld held368;              // +368
    K10aHeld held372;              // +372
    K10aHeld held376;              // +376
    K10aHeld held380;              // +380
    K10aHeld held384;              // +384
    K10aHeld held388;              // +388
    K10aHeld held392;              // +392
    K10aHeld held396;              // +396
    K10aHeld held400;              // +400
    K10aHeld held404;              // +404
    K10aHeld held408;              // +408
    K10aHeld held412;              // +412
    K10aHeld held416;              // +416
    K10aHeld held420;              // +420
    K10aHeld held424;              // +424
    K10aHeld held428;              // +428
    K10aHeld held432;              // +432
    K10aHeld held436;              // +436
    K10aHeld held440;              // +440
    K10aHeld held444;              // +444
    K10aHeld held448;              // +448
    K10aHeld held452;              // +452
    K10aHeld held456;              // +456
    K10aHeld held460;              // +460
    K10aHeld held464;              // +464
    K10aHeld held468;              // +468
    char pad472[52];
    K10aHeld held524;              // +524
    K10aHeld held528;              // +528
    K10aHeld held532;              // +532
    K10aHeld held536;              // +536
    K10aHeld held540;              // +540
    K10aHeld held544;              // +544
    char pad548[48];
    K10aHeld held596;              // +596
    K10aHeld held600;              // +600
    char pad604[52];
    K10aString string656;              // +656
    char pad660[40];
    K10aHeld held700;              // +700
    K10aHeld held704;              // +704
    K10aHeld held708;              // +708
    K10aHeld held712;              // +712
    K10aHeld held716;              // +716
    K10aHandle handle720;              // +720
    ~K10aObject() {}
};

extern "C" void w3d_k10a_scene_objects_destroy_801320c8(Ptr32<void> self, int flags)
{
    Ptr32<K10aObject> o = (Ptr32<K10aObject>)self;
    o->vtable = w3d_vtable_80410e80;
    o->~K10aObject();
    w3d_base_destroy_8015ff2c(self, flags);
}


