#include "w3d_ptr.h"
#line 1 "d24k_handle_object_ctor_8022a180.cpp"
// Object constructor with 54 service handles (Worms 3D GameCube PAL, 0x8022a180).
//
// Runs the tagged base constructor 0x801ea0ec with the caller's tag, stores
// the table 0x8041a078, initializes the shared strings at +20 and +84 from the
// empty string 0x804b06a0 and sets the integer fields to their defaults (mostly
// 0; +56, +268, +280, +284, +288 and +328 are 1; +256 is 2; +264 is 10000; +272
// is 5000; +276 is 3000; +296 is 25; +300, +304 and +308 are 50; +316 is 60000;
// +320 is 1800000; +324 is 100). It then takes 54 retained handles to the
// service with key 0x80419f08 (0x8020b680), calls 0x802336ec with -1 and
// 0x802336fc with 0 on the 47th, releases all in reverse order and returns the
// object. Field roles are unknown.
//
// Handles are one word with a user copy constructor: the 54 result slots are 8
// bytes apart (sp+8 to sp+432); same handle family as
// d23a_worm_aim_start_80026e74. The lookup key is a local set among the last
// field stores, which gives the original's register choice for the constants.
struct SharedString;
extern "C" void d20e_string_init_8020c5c0(Ptr32<SharedString>);
extern "C" Ptr32<unsigned short> d20e_string_header_80341884(Ptr32<SharedString>);
struct SharedString {
    Ptr32<char> text;
    void init(const SharedString &other) {
        d20e_string_init_8020c5c0(this);
        text = other.text;
        ++*d20e_string_header_80341884(this);
    }
};
extern SharedString d20e_empty_804b06a0[];
struct Service;
struct ServiceVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<Service>)> retain;   // +12
    Ptr32<void (Ptr32<Service>)> release;  // +16
};
struct Service { Ptr32<ServiceVtable> vtable; };
extern "C" Ptr32<Service> fn_8020b680(Ptr32<const void>);
extern "C" void fn_802336ec(Ptr32<Service>, int);
extern "C" void fn_802336fc(Ptr32<Service>, int);
struct ServiceHandle {
 ServiceHandle(const ServiceHandle &);
    Ptr32<Service> value;
    template <class W3dU> ServiceHandle(Ptr32<W3dU> w3d_p) : ServiceHandle((Service *)w3d_p.get()) {}
 ServiceHandle(Service *s) : value(s) {
        if (value) {
            value->vtable->retain(value);
        }
    }
    ~ServiceHandle() {
        if (value) {
            value->vtable->release(value);
        }
    }
};
struct Object {
    Ptr32<void> vtable;
    char unknown04[16];
    SharedString name;
    int f24;
    int f28;
    int f32;
    int f36;
    int f40;
    int f44;
    int f48;
    int f52;
    int f56;
    int f60;
    int f64;
    int f68;
    int f72;
    int f76;
    int f80;
    SharedString text;
    int f88;
    int f92;
    int f96;
    int f100;
    int f104;
    int f108;
    int f112;
    int f116;
    int f120;
    int f124;
    int f128;
    int f132;
    int f136;
    int f140;
    int f144;
    int f148;
    int f152;
    int f156;
    int f160;
    int f164;
    int f168;
    int f172;
    int f176;
    int f180;
    int f184;
    int f188;
    int f192;
    int f196;
    int f200;
    int f204;
    int f208;
    int f212;
    int f216;
    int f220;
    int f224;
    int f228;
    int f232;
    int f236;
    int f240;
    int f244;
    int f248;
    int f252;
    int f256;
    int f260;
    int f264;
    int f268;
    int f272;
    int f276;
    int f280;
    int f284;
    int f288;
    int f292;
    int f296;
    int f300;
    int f304;
    int f308;
    int f312;
    int f316;
    int f320;
    int f324;
    int f328;
    int f332;
};
extern "C" Ptr32<void> fn_801ea0ec(Ptr32<Object>, int);
extern char vtable_8041a078[];
extern const char key_80419f08[];
extern "C" Ptr32<Object> w3d_d24k_handle_object_ctor_8022a180(Ptr32<Object> self, int tag) {
    fn_801ea0ec(self, tag);
    self->vtable = vtable_8041a078;
    self->name.init(d20e_empty_804b06a0[0]);
    self->f24 = 0;
    self->f28 = 0;
    self->f32 = 0;
    self->f36 = 0;
    self->f40 = 0;
    self->f44 = 0;
    self->f48 = 0;
    self->f52 = 0;
    self->f56 = 1;
    self->f60 = 0;
    self->f64 = 0;
    self->f68 = 0;
    self->f72 = 0;
    self->f76 = 0;
    self->f80 = 0;
    self->text.init(d20e_empty_804b06a0[0]);
    self->f88 = 0;
    self->f92 = 0;
    self->f96 = 0;
    self->f100 = 0;
    self->f104 = 0;
    self->f108 = 0;
    self->f112 = 0;
    self->f116 = 0;
    self->f120 = 0;
    self->f124 = 0;
    self->f128 = 0;
    self->f132 = 0;
    self->f136 = 0;
    self->f140 = 0;
    self->f144 = 0;
    self->f148 = 0;
    self->f152 = 0;
    self->f156 = 0;
    self->f160 = 0;
    self->f164 = 0;
    self->f168 = 0;
    self->f172 = 0;
    self->f176 = 0;
    self->f180 = 0;
    self->f184 = 0;
    self->f188 = 0;
    self->f192 = 0;
    self->f196 = 0;
    self->f200 = 0;
    self->f204 = 0;
    self->f208 = 0;
    self->f212 = 0;
    self->f216 = 0;
    self->f220 = 0;
    self->f224 = 0;
    self->f228 = 0;
    self->f232 = 0;
    self->f236 = 0;
    self->f240 = 0;
    self->f244 = 0;
    self->f248 = 0;
    self->f252 = 0;
    self->f256 = 2;
    self->f260 = 0;
    self->f264 = 10000;
    self->f268 = 1;
    self->f272 = 5000;
    self->f276 = 3000;
    self->f280 = 1;
    self->f284 = 1;
    self->f288 = 1;
    self->f292 = 0;
    self->f296 = 25;
    self->f300 = 50;
    self->f304 = 50;
    self->f308 = 50;
    self->f312 = 0;
    self->f316 = 60000;
    self->f320 = 1800000;
    Ptr32<const char> key = key_80419f08;
    self->f324 = 100;
    self->f328 = 1;
    self->f332 = 0;
    ServiceHandle h0(fn_8020b680(key));
    ServiceHandle h1(fn_8020b680(key));
    ServiceHandle h2(fn_8020b680(key));
    ServiceHandle h3(fn_8020b680(key));
    ServiceHandle h4(fn_8020b680(key));
    ServiceHandle h5(fn_8020b680(key));
    ServiceHandle h6(fn_8020b680(key));
    ServiceHandle h7(fn_8020b680(key));
    ServiceHandle h8(fn_8020b680(key));
    ServiceHandle h9(fn_8020b680(key));
    ServiceHandle h10(fn_8020b680(key));
    ServiceHandle h11(fn_8020b680(key));
    ServiceHandle h12(fn_8020b680(key));
    ServiceHandle h13(fn_8020b680(key));
    ServiceHandle h14(fn_8020b680(key));
    ServiceHandle h15(fn_8020b680(key));
    ServiceHandle h16(fn_8020b680(key));
    ServiceHandle h17(fn_8020b680(key));
    ServiceHandle h18(fn_8020b680(key));
    ServiceHandle h19(fn_8020b680(key));
    ServiceHandle h20(fn_8020b680(key));
    ServiceHandle h21(fn_8020b680(key));
    ServiceHandle h22(fn_8020b680(key));
    ServiceHandle h23(fn_8020b680(key));
    ServiceHandle h24(fn_8020b680(key));
    ServiceHandle h25(fn_8020b680(key));
    ServiceHandle h26(fn_8020b680(key));
    ServiceHandle h27(fn_8020b680(key));
    ServiceHandle h28(fn_8020b680(key));
    ServiceHandle h29(fn_8020b680(key));
    ServiceHandle h30(fn_8020b680(key));
    ServiceHandle h31(fn_8020b680(key));
    ServiceHandle h32(fn_8020b680(key));
    ServiceHandle h33(fn_8020b680(key));
    ServiceHandle h34(fn_8020b680(key));
    ServiceHandle h35(fn_8020b680(key));
    ServiceHandle h36(fn_8020b680(key));
    ServiceHandle h37(fn_8020b680(key));
    ServiceHandle h38(fn_8020b680(key));
    ServiceHandle h39(fn_8020b680(key));
    ServiceHandle h40(fn_8020b680(key));
    ServiceHandle h41(fn_8020b680(key));
    ServiceHandle h42(fn_8020b680(key));
    ServiceHandle h43(fn_8020b680(key));
    ServiceHandle h44(fn_8020b680(key));
    ServiceHandle h45(fn_8020b680(key));
    ServiceHandle h46(fn_8020b680(key));
    ServiceHandle h47(fn_8020b680(key));
    ServiceHandle h48(fn_8020b680(key));
    ServiceHandle h49(fn_8020b680(key));
    ServiceHandle h50(fn_8020b680(key));
    ServiceHandle h51(fn_8020b680(key));
    ServiceHandle h52(fn_8020b680(key));
    ServiceHandle h53(fn_8020b680(key));
    fn_802336ec(h46.value, -1);
    fn_802336fc(h46.value, 0);
    return self;
}


