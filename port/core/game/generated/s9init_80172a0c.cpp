#include "w3d_ptr.h"
#line 1 "s9init_80172a0c.cpp"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Inferred static type registration and zero-initialized shared resource slots. */
inline void *operator new(__SIZE_TYPE__,void *p) {return p;}
struct S9RegisteredType;
struct S9RegisteredType {
    int words[8];
    S9RegisteredType(Ptr32<char> name,Ptr32<char> base,Ptr32<void (void)> factory,int flags,int size);
};
struct S9StaticSlot {
    unsigned int value;
    void clear() { value=0; }
};
extern "C" {
extern S9RegisteredType lbl_80361b08;
extern char lbl_803e89c8[],lbl_80361f58[];
Ptr32<void> fn_8016fb54(void);

extern S9StaticSlot lbl_804b0128,lbl_804b012c,lbl_804b0130,lbl_804b0134,lbl_804b0138,lbl_804b013c,lbl_804b0140,lbl_804b0144,lbl_804b0148,lbl_804b014c,lbl_804b0150;
extern S9StaticSlot lbl_804b0124;
}
extern "C" {
extern S9RegisteredType lbl_80361bf8;
extern char lbl_803e8a70[],lbl_80361f58[];
Ptr32<void> fn_8018330c(void);

extern S9StaticSlot lbl_804b01d8,lbl_804b01dc,lbl_804b01e0,lbl_804b01e4,lbl_804b01e8,lbl_804b01ec,lbl_804b01f0,lbl_804b01f4,lbl_804b01f8,lbl_804b01fc,lbl_804b0200;
extern S9StaticSlot lbl_804b01d4;
}
extern "C" {
extern S9RegisteredType lbl_80361c28;
extern char lbl_803e8a8c[],lbl_80361f58[];
Ptr32<void> fn_80186a34(void);

extern S9StaticSlot lbl_804b0208,lbl_804b020c,lbl_804b0210,lbl_804b0214,lbl_804b0218,lbl_804b021c,lbl_804b0220,lbl_804b0224,lbl_804b0228,lbl_804b022c,lbl_804b0230;
extern S9StaticSlot lbl_804b0204;
}

extern "C" void s9_initialize_shared_properties_80172a0c(int initialize,int priority) {
    if(priority==0xffff && initialize) {
        new (&lbl_80361b08) S9RegisteredType(lbl_803e89c8,lbl_80361f58,(Ptr32<void (void)>)fn_8016fb54,0,0);
        lbl_804b0124.clear();
        lbl_804b0128.clear();
        lbl_804b012c.clear();
        lbl_804b0130.clear();
        lbl_804b0134.clear();
        lbl_804b0138.clear();
        lbl_804b013c.clear();
        lbl_804b0140.clear();
        lbl_804b0144.clear();
        lbl_804b0148.clear();
        lbl_804b014c.clear();
        lbl_804b0150.clear();

    }
}

extern "C" void s9_initialize_shared_properties_80184fe4(int initialize,int priority) {
    if(priority==0xffff && initialize) {
        new (&lbl_80361bf8) S9RegisteredType(lbl_803e8a70,lbl_80361f58,(Ptr32<void (void)>)fn_8018330c,0,0);
        lbl_804b01d4.clear();
        lbl_804b01d8.clear();
        lbl_804b01dc.clear();
        lbl_804b01e0.clear();
        lbl_804b01e4.clear();
        lbl_804b01e8.clear();
        lbl_804b01ec.clear();
        lbl_804b01f0.clear();
        lbl_804b01f4.clear();
        lbl_804b01f8.clear();
        lbl_804b01fc.clear();
        lbl_804b0200.clear();

    }
}

extern "C" void s9_initialize_shared_properties_8018893c(int initialize,int priority) {
    if(priority==0xffff && initialize) {
        new (&lbl_80361c28) S9RegisteredType(lbl_803e8a8c,lbl_80361f58,(Ptr32<void (void)>)fn_80186a34,0,0);
        lbl_804b0204.clear();
        lbl_804b0208.clear();
        lbl_804b020c.clear();
        lbl_804b0210.clear();
        lbl_804b0214.clear();
        lbl_804b0218.clear();
        lbl_804b021c.clear();
        lbl_804b0220.clear();
        lbl_804b0224.clear();
        lbl_804b0228.clear();
        lbl_804b022c.clear();
        lbl_804b0230.clear();

    }
}


