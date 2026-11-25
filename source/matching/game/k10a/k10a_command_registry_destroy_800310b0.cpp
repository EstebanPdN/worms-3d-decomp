// Appears to be the destructor of a service-derived registry that owns about a hundred held interfaces, storage blocks, an item list, owner and mode members and a handle.
// Member classes have real inline destructors; the explicit destructor call
// reproduces the compiler's reverse-order member cleanup before the base.
#define VCALL(p, T, o) ((T)(*(void **)(*(char **)(p) + (o))))
extern const void *w3d_vtable_8040e588[];
extern "C" void w3d_string_base_finish(void *string);
extern "C" void w3d_string_release(void *string);
extern "C" void w3d_actor_handle_member_destroy(void *member, int flags);
extern "C" void w3d_handle_storage_release(void *storage);
extern "C" void w3d_k8a_item_list_destroy_800363a0(void *list, int flags);
extern "C" void w3d_cx9c_release_owner_80343df8(void *owner, int flags);
extern "C" void w3d_service_mode_destroy(void *mode, int flags);
extern "C" void w3d_service_destroy_801628ec(void *self, int flags);

struct K10aHeld
{
    void *held;
    ~K10aHeld() { if (held) VCALL(held, void (*)(void *), 16)(held); }
};

struct K10aString
{
    char *text;
    ~K10aString() { w3d_string_base_finish(this); w3d_string_release(this); }
};

struct K10aHandle
{
    void *word;
    ~K10aHandle() { w3d_actor_handle_member_destroy(this, 2); }
};

struct K10aStorage
{
    void *block;
    ~K10aStorage() { if (block) w3d_handle_storage_release(block); }
};

struct K10aItemList
{
    void *word;
    ~K10aItemList() { w3d_k8a_item_list_destroy_800363a0(this, 2); }
};

struct K10aOwner
{
    void *word;
    ~K10aOwner() { w3d_cx9c_release_owner_80343df8(this, 0); }
};

struct K10aMode
{
    void *word;
    ~K10aMode() { w3d_service_mode_destroy(this, 2); }
};

struct K10aObject
{
    const void *vtable;          // +0
    char pad4[28];
    K10aMode mode32;              // +32
    char pad36[72];
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
    char pad312[4];
    K10aStorage storage316;              // +316
    char pad320[8];
    K10aMode mode328;              // +328
    char pad332[72];
    K10aOwner owner404;              // +404
    char pad408[212];
    K10aHeld held620;              // +620
    K10aHeld held624;              // +624
    K10aHeld held628;              // +628
    K10aHeld held632;              // +632
    K10aHeld held636;              // +636
    K10aHeld held640;              // +640
    K10aHeld held644;              // +644
    K10aHeld held648;              // +648
    K10aHeld held652;              // +652
    K10aHeld held656;              // +656
    K10aHeld held660;              // +660
    K10aHeld held664;              // +664
    K10aHeld held668;              // +668
    K10aHeld held672;              // +672
    K10aHeld held676;              // +676
    K10aHeld held680;              // +680
    K10aHeld held684;              // +684
    K10aHeld held688;              // +688
    K10aHeld held692;              // +692
    K10aHeld held696;              // +696
    K10aHeld held700;              // +700
    K10aHeld held704;              // +704
    K10aHeld held708;              // +708
    K10aHeld held712;              // +712
    K10aHeld held716;              // +716
    K10aHeld held720;              // +720
    K10aHeld held724;              // +724
    char pad728[20];
    K10aHeld held748;              // +748
    K10aHeld held752;              // +752
    K10aHeld held756;              // +756
    K10aHeld held760;              // +760
    K10aHeld held764;              // +764
    K10aHeld held768;              // +768
    K10aHeld held772;              // +772
    K10aHeld held776;              // +776
    K10aHeld held780;              // +780
    K10aHeld held784;              // +784
    K10aHeld held788;              // +788
    K10aHeld held792;              // +792
    K10aHeld held796;              // +796
    K10aHeld held800;              // +800
    K10aHeld held804;              // +804
    K10aStorage storage808;              // +808
    char pad812[12];
    K10aHeld held824;              // +824
    K10aItemList itemlist828;              // +828
    char pad832[28];
    K10aHeld held860;              // +860
    K10aHandle handle864;              // +864
    ~K10aObject() {}
};

extern "C" void w3d_k10a_command_registry_destroy_800310b0(void *self, int flags)
{
    K10aObject *o = (K10aObject *)self;
    o->vtable = w3d_vtable_8040e588;
    o->~K10aObject();
    w3d_service_destroy_801628ec(self, flags);
}
