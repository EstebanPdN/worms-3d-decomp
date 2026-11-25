// Constructor of a shared-resource effect (Worms 3D GameCube PAL, 0x8016fc7c).
//
// Same template as s9_construct_resource_set_80183434: the first instance
// lazily acquires twelve shared resources and sets their values and flags.
// Here the owner also has two embedded descriptors (0x802109dc) and an
// allocated 28-byte record with an embedded empty vector.

/* Inferred resource fields and nested dirty-flag methods. */
struct S9SharedFlags {
    char unknown[7]; unsigned char bits;
    void dirty() { bits|=2; }
    void enable() { bits|=1; }
};
struct S9SharedResource {
    void **vtable;
    S9SharedFlags flags;
    char unknown12[12];
    union { int integer24; float float24; } value24;
    int value28,value32,value36,value40,value44,value48,value52;
    void retain() { ((void (*)(S9SharedResource *))vtable[3])(this); }
    void release() { ((void (*)(S9SharedResource *))vtable[4])(this); }
    void set24(int value) { value24.integer24=value;flags.dirty(); }
    void set24f(float value) { value24.float24=value;flags.dirty(); }
    void set28(int value) { value28=value;flags.dirty(); }
    void set32(int value) { value32=value;flags.dirty(); }
    void set36(int value) { value36=value;flags.dirty(); }
    void set52(int value) { value52=value;flags.dirty(); }
    void enable() { flags.enable(); }
};

extern "C" int fn_801902e8(void *);
extern "C" void fn_802109dc(void *);
extern "C" S9SharedResource *fn_8020b680(char *);
extern "C" void *fn_801fe1d8(unsigned);
extern char lbl_80412008[];
extern float lbl_803a65a8[];
extern int lbl_804b1898;
extern char lbl_80415c10[];
extern char lbl_80415c80[];
extern char lbl_80415bb0[];
extern char lbl_80415cb0[];
extern char lbl_80415c30[];
extern char lbl_80415c00[];
extern char lbl_804166b0[];
extern char lbl_80414210[];
extern char lbl_80416750[];
extern S9SharedResource *lbl_804b0124;
extern S9SharedResource *lbl_804b0128;
extern S9SharedResource *lbl_804b012c;
extern S9SharedResource *lbl_804b0130;
extern S9SharedResource *lbl_804b0134;
extern S9SharedResource *lbl_804b0138;
extern S9SharedResource *lbl_804b013c;
extern S9SharedResource *lbl_804b0140;
extern S9SharedResource *lbl_804b0144;
extern S9SharedResource *lbl_804b0148;
extern S9SharedResource *lbl_804b014c;
extern S9SharedResource *lbl_804b0150;
struct Alloc { Alloc() {} Alloc(const Alloc &) {} };
struct Proxy : Alloc { void *data; Proxy(const Alloc &a, void *p) : Alloc(a), data(p) {} };
struct VecBase { void *start,*finish; Proxy end; VecBase(const Alloc &a) : start(0), finish(0), end(a,0) {} };
struct Vec : VecBase { Vec(const Alloc &a=Alloc()) : VecBase(a) {} };
struct Third { int a,b,c; Third() { c=0; b=0; } };
struct Record { Vec v; Third third; Record() { third.a=0; } void *operator new(unsigned n) { return fn_801fe1d8(n); } };
struct Owner { void *vtable; char unknown4[48]; char first_descriptor[12]; char second_descriptor[12]; int held; Record *record; };

extern "C" void *d24j_construct_resource_set_8016fc7c(Owner *self)
{
    fn_801902e8(self);
    self->vtable=lbl_80412008;
    fn_802109dc(self->first_descriptor);
    fn_802109dc(self->second_descriptor);
    self->held=0;
    if(!lbl_804b1898) {
        char *name_0=lbl_80415c10;
        {
            S9SharedResource *value=fn_8020b680(name_0);
            if(value)value->retain();
            if(lbl_804b0124)lbl_804b0124->release();
            lbl_804b0124=value;
        }
        {
            S9SharedResource *value=fn_8020b680(name_0);
            if(value)value->retain();
            if(lbl_804b0128)lbl_804b0128->release();
            lbl_804b0128=value;
        }
        {
            S9SharedResource *value=fn_8020b680(lbl_80415c80);
            if(value)value->retain();
            if(lbl_804b012c)lbl_804b012c->release();
            lbl_804b012c=value;
        }
        {
            S9SharedResource *value=fn_8020b680(lbl_80415bb0);
            if(value)value->retain();
            if(lbl_804b0130)lbl_804b0130->release();
            lbl_804b0130=value;
        }
        char *name_3=lbl_80415cb0;
        {
            S9SharedResource *value=fn_8020b680(name_3);
            if(value)value->retain();
            if(lbl_804b0134)lbl_804b0134->release();
            lbl_804b0134=value;
        }
        {
            S9SharedResource *value=fn_8020b680(name_3);
            if(value)value->retain();
            if(lbl_804b0138)lbl_804b0138->release();
            lbl_804b0138=value;
        }
        {
            S9SharedResource *value=fn_8020b680(lbl_80415c30);
            if(value)value->retain();
            if(lbl_804b013c)lbl_804b013c->release();
            lbl_804b013c=value;
        }
        char *name_5=lbl_80415c00;
        {
            S9SharedResource *value=fn_8020b680(name_5);
            if(value)value->retain();
            if(lbl_804b0140)lbl_804b0140->release();
            lbl_804b0140=value;
        }
        {
            S9SharedResource *value=fn_8020b680(name_5);
            if(value)value->retain();
            if(lbl_804b0144)lbl_804b0144->release();
            lbl_804b0144=value;
        }
        {
            S9SharedResource *value=fn_8020b680(lbl_804166b0);
            if(value)value->retain();
            if(lbl_804b0148)lbl_804b0148->release();
            lbl_804b0148=value;
        }
        {
            S9SharedResource *value=fn_8020b680(lbl_80414210);
            if(value)value->retain();
            if(lbl_804b014c)lbl_804b014c->release();
            lbl_804b014c=value;
        }
        {
            S9SharedResource *value=fn_8020b680(lbl_80416750);
            if(value)value->retain();
            if(lbl_804b0150)lbl_804b0150->release();
            lbl_804b0150=value;
        }
        lbl_804b0124->set32(3);
        lbl_804b0124->set36(1);
        lbl_804b0124->enable();
        lbl_804b0128->set32(7);
        lbl_804b0128->set36(1);
        lbl_804b0128->enable();
        lbl_804b012c->set52(0);
        lbl_804b012c->enable();
        lbl_804b0130->set28(4);
        float scalar=*lbl_803a65a8;
        lbl_804b0130->set32(1);
        lbl_804b0130->enable();
        lbl_804b0130->set24f(scalar);
        lbl_804b0134->set28(6);
        lbl_804b0134->set24(7);
        lbl_804b0134->enable();
        lbl_804b0138->set28(6);
        lbl_804b0138->set24(1);
        lbl_804b0138->enable();
        lbl_804b013c->set24(0);
        lbl_804b013c->enable();
        lbl_804b0140->set24(0);
        lbl_804b0140->enable();
        lbl_804b0144->set24(1);
        lbl_804b0144->enable();
    }
    lbl_804b1898++;
    self->record=new Record;
    return self;
}
