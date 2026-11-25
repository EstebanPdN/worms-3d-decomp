#include "w3d_ptr.h"
#line 1 "s9shared2_80186b5c.cpp"
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
extern char lbl_80412da8[];
extern float lbl_803a7b08[];
extern int lbl_804ab688;
extern char lbl_80414210[];
extern char lbl_80415bb0[];
extern char lbl_80415c00[];
extern char lbl_80415c10[];
extern char lbl_80415c30[];
extern char lbl_80415c80[];
extern char lbl_80415cb0[];
extern char lbl_804166b0[];
extern char lbl_80416750[];
extern Ptr32<S9SharedResource> lbl_804b0204;
extern Ptr32<S9SharedResource> lbl_804b0208;
extern Ptr32<S9SharedResource> lbl_804b020c;
extern Ptr32<S9SharedResource> lbl_804b0210;
extern Ptr32<S9SharedResource> lbl_804b0214;
extern Ptr32<S9SharedResource> lbl_804b0218;
extern Ptr32<S9SharedResource> lbl_804b021c;
extern Ptr32<S9SharedResource> lbl_804b0220;
extern Ptr32<S9SharedResource> lbl_804b0224;
extern Ptr32<S9SharedResource> lbl_804b0228;
extern Ptr32<S9SharedResource> lbl_804b022c;
extern Ptr32<S9SharedResource> lbl_804b0230;
struct S9SetOwner { Ptr32<void> vtable; char unknown4[44]; Ptr32<S9SharedResource> first; Ptr32<S9SharedResource> second; };

extern "C" Ptr32<void> s9_construct_resource_set_80186b5c(Ptr32<S9SetOwner> self)
{
    fn_801902e8(self);
    self->vtable=lbl_80412da8;
    self->first=0;
    self->second=0;
    if(!lbl_804ab688) {
        Ptr32<char> name_a=lbl_80415c10;
        {
            Ptr32<S9SharedResource> value=fn_8020b680(name_a);
            if(value)value->retain();
            if(lbl_804b0204)lbl_804b0204->release();
            lbl_804b0204=value;
        }
        {
            Ptr32<S9SharedResource> value=fn_8020b680(name_a);
            if(value)value->retain();
            if(lbl_804b0208)lbl_804b0208->release();
            lbl_804b0208=value;
        }
        {
            Ptr32<S9SharedResource> value=fn_8020b680(lbl_80415c80);
            if(value)value->retain();
            if(lbl_804b020c)lbl_804b020c->release();
            lbl_804b020c=value;
        }
        {
            Ptr32<S9SharedResource> value=fn_8020b680(lbl_80415bb0);
            if(value)value->retain();
            if(lbl_804b0210)lbl_804b0210->release();
            lbl_804b0210=value;
        }
        Ptr32<char> name_b=lbl_80415cb0;
        {
            Ptr32<S9SharedResource> value=fn_8020b680(name_b);
            if(value)value->retain();
            if(lbl_804b0214)lbl_804b0214->release();
            lbl_804b0214=value;
        }
        {
            Ptr32<S9SharedResource> value=fn_8020b680(name_b);
            if(value)value->retain();
            if(lbl_804b0218)lbl_804b0218->release();
            lbl_804b0218=value;
        }
        {
            Ptr32<S9SharedResource> value=fn_8020b680(lbl_80415c30);
            if(value)value->retain();
            if(lbl_804b021c)lbl_804b021c->release();
            lbl_804b021c=value;
        }
        Ptr32<char> name_c=lbl_80415c00;
        {
            Ptr32<S9SharedResource> value=fn_8020b680(name_c);
            if(value)value->retain();
            if(lbl_804b0220)lbl_804b0220->release();
            lbl_804b0220=value;
        }
        {
            Ptr32<S9SharedResource> value=fn_8020b680(name_c);
            if(value)value->retain();
            if(lbl_804b0224)lbl_804b0224->release();
            lbl_804b0224=value;
        }
        {
            Ptr32<S9SharedResource> value=fn_8020b680(lbl_804166b0);
            if(value)value->retain();
            if(lbl_804b0228)lbl_804b0228->release();
            lbl_804b0228=value;
        }
        {
            Ptr32<S9SharedResource> value=fn_8020b680(lbl_80414210);
            if(value)value->retain();
            if(lbl_804b022c)lbl_804b022c->release();
            lbl_804b022c=value;
        }
        {
            Ptr32<S9SharedResource> value=fn_8020b680(lbl_80416750);
            if(value)value->retain();
            if(lbl_804b0230)lbl_804b0230->release();
            lbl_804b0230=value;
        }
        lbl_804b0204->set32(3);
        lbl_804b0204->set36(1);
        lbl_804b0204->enable();
        lbl_804b0208->set32(7);
        lbl_804b0208->set36(1);
        lbl_804b0208->enable();
        lbl_804b020c->set52(0);
        lbl_804b020c->enable();
        lbl_804b0210->set28(4);
        float scalar=*lbl_803a7b08;
        lbl_804b0210->set32(1);
        lbl_804b0210->enable();
        lbl_804b0210->set24f(scalar);
        lbl_804b0214->set28(6);
        lbl_804b0214->set24(7);
        lbl_804b0214->enable();
        lbl_804b0218->set28(6);
        lbl_804b0218->set24(1);
        lbl_804b0218->enable();
        lbl_804b021c->set24(0);
        lbl_804b021c->enable();
        lbl_804b0220->set24(0);
        lbl_804b0220->enable();
        lbl_804b0224->set24(1);
        lbl_804b0224->enable();
    }
    lbl_804ab688++;
    return self;
}


