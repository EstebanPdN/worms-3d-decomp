#include "w3d_ptr.h"
#line 1 "s9shared_80183434.cpp"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Inferred resource fields and nested dirty-flag methods. */
struct S9SharedFlags {
    char unknown[4]; unsigned char bits; char w3d_tag_rest[3];
    void dirty() { bits|=2; }
    void enable() { bits|=1; }
};
struct S9SharedResource {
    Ptr32<Ptr32<void>> vtable;
    S9SharedFlags flags;
    char unknown12[12];
    union { int integer24; float float24; } value24;
    int value28,value32,value36,value40,value44,value48,value52;
    void retain() { ((Ptr32<void (Ptr32<S9SharedResource>)>)vtable[3])(this); }
    void release() { ((Ptr32<void (Ptr32<S9SharedResource>)>)vtable[4])(this); }
    void set24(int value) { value24.integer24=value;flags.dirty(); }
    void set24f(float value) { value24.float24=value;flags.dirty(); }
    void set28(int value) { value28=value;flags.dirty(); }
    void set32(int value) { value32=value;flags.dirty(); }
    void set36(int value) { value36=value;flags.dirty(); }
    void set52(int value) { value52=value;flags.dirty(); }
    void enable() { flags.enable(); }
};
extern "C" int fn_801902e8(Ptr32<void>);
extern "C" Ptr32<S9SharedResource> fn_8020b680(Ptr32<char>);
extern char lbl_80412bc8[];
extern float lbl_803a7998[];
extern int lbl_804ab660;
extern char lbl_80414210[];
extern char lbl_80415bb0[];
extern char lbl_80415c00[];
extern char lbl_80415c10[];
extern char lbl_80415c30[];
extern char lbl_80415c80[];
extern char lbl_80415cb0[];
extern char lbl_804166b0[];
extern char lbl_80416750[];
extern Ptr32<S9SharedResource> lbl_804b01d4;
extern Ptr32<S9SharedResource> lbl_804b01d8;
extern Ptr32<S9SharedResource> lbl_804b01dc;
extern Ptr32<S9SharedResource> lbl_804b01e0;
extern Ptr32<S9SharedResource> lbl_804b01e4;
extern Ptr32<S9SharedResource> lbl_804b01e8;
extern Ptr32<S9SharedResource> lbl_804b01ec;
extern Ptr32<S9SharedResource> lbl_804b01f0;
extern Ptr32<S9SharedResource> lbl_804b01f4;
extern Ptr32<S9SharedResource> lbl_804b01f8;
extern Ptr32<S9SharedResource> lbl_804b01fc;
extern Ptr32<S9SharedResource> lbl_804b0200;
struct S9SetOwner { Ptr32<void> vtable; char unknown4[40]; Ptr32<S9SharedResource> first; Ptr32<S9SharedResource> second; };

extern "C" Ptr32<void> s9_construct_resource_set_80183434(Ptr32<S9SetOwner> self)
{
    fn_801902e8(self);
    self->vtable=lbl_80412bc8;
    self->first=0;
    self->second=0;
    if(!lbl_804ab660) {
        Ptr32<char> name_a=lbl_80415c10;
        {
            Ptr32<S9SharedResource> value=fn_8020b680(name_a);
            if(value)value->retain();
            if(lbl_804b01d4)lbl_804b01d4->release();
            lbl_804b01d4=value;
        }
        {
            Ptr32<S9SharedResource> value=fn_8020b680(name_a);
            if(value)value->retain();
            if(lbl_804b01d8)lbl_804b01d8->release();
            lbl_804b01d8=value;
        }
        {
            Ptr32<S9SharedResource> value=fn_8020b680(lbl_80415c80);
            if(value)value->retain();
            if(lbl_804b01dc)lbl_804b01dc->release();
            lbl_804b01dc=value;
        }
        {
            Ptr32<S9SharedResource> value=fn_8020b680(lbl_80415bb0);
            if(value)value->retain();
            if(lbl_804b01e0)lbl_804b01e0->release();
            lbl_804b01e0=value;
        }
        Ptr32<char> name_b=lbl_80415cb0;
        {
            Ptr32<S9SharedResource> value=fn_8020b680(name_b);
            if(value)value->retain();
            if(lbl_804b01e4)lbl_804b01e4->release();
            lbl_804b01e4=value;
        }
        {
            Ptr32<S9SharedResource> value=fn_8020b680(name_b);
            if(value)value->retain();
            if(lbl_804b01e8)lbl_804b01e8->release();
            lbl_804b01e8=value;
        }
        {
            Ptr32<S9SharedResource> value=fn_8020b680(lbl_80415c30);
            if(value)value->retain();
            if(lbl_804b01ec)lbl_804b01ec->release();
            lbl_804b01ec=value;
        }
        Ptr32<char> name_c=lbl_80415c00;
        {
            Ptr32<S9SharedResource> value=fn_8020b680(name_c);
            if(value)value->retain();
            if(lbl_804b01f0)lbl_804b01f0->release();
            lbl_804b01f0=value;
        }
        {
            Ptr32<S9SharedResource> value=fn_8020b680(name_c);
            if(value)value->retain();
            if(lbl_804b01f4)lbl_804b01f4->release();
            lbl_804b01f4=value;
        }
        {
            Ptr32<S9SharedResource> value=fn_8020b680(lbl_804166b0);
            if(value)value->retain();
            if(lbl_804b01f8)lbl_804b01f8->release();
            lbl_804b01f8=value;
        }
        {
            Ptr32<S9SharedResource> value=fn_8020b680(lbl_80414210);
            if(value)value->retain();
            if(lbl_804b01fc)lbl_804b01fc->release();
            lbl_804b01fc=value;
        }
        {
            Ptr32<S9SharedResource> value=fn_8020b680(lbl_80416750);
            if(value)value->retain();
            if(lbl_804b0200)lbl_804b0200->release();
            lbl_804b0200=value;
        }
        lbl_804b01d4->set32(3);
        lbl_804b01d4->set36(1);
        lbl_804b01d4->enable();
        lbl_804b01d8->set32(7);
        lbl_804b01d8->set36(1);
        lbl_804b01d8->enable();
        lbl_804b01dc->set52(0);
        lbl_804b01dc->enable();
        lbl_804b01e0->set28(4);
        float scalar=*lbl_803a7998;
        lbl_804b01e0->set32(1);
        lbl_804b01e0->enable();
        lbl_804b01e0->set24f(scalar);
        lbl_804b01e4->set28(6);
        lbl_804b01e4->set24(7);
        lbl_804b01e4->enable();
        lbl_804b01e8->set28(6);
        lbl_804b01e8->set24(1);
        lbl_804b01e8->enable();
        lbl_804b01ec->set24(0);
        lbl_804b01ec->enable();
        lbl_804b01f0->set24(0);
        lbl_804b01f0->enable();
        lbl_804b01f4->set24(1);
        lbl_804b01f4->enable();
    }
    lbl_804ab660++;
    return self;
}


