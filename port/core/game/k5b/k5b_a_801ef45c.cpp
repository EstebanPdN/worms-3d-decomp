#include "w3d_ptr.h"
#line 1 "k5b_a_801ef45c.cpp"
struct K5bShared { Ptr32<Ptr32<void>> vtable; };
inline void *operator new(__SIZE_TYPE__, void *place) { return place; }
struct W3dType_802097ec {
    W3dType_802097ec(Ptr32<const char> name, int a, int b);
    int word;
};
extern W3dType_802097ec lbl_804b05a0;
struct K5bTypeNode;
extern "C" void w3d_s21_insert_sorted_80200af8(Ptr32<K5bTypeNode> node);
struct K5bTypeNode {
    Ptr32<K5bTypeNode> next;
    Ptr32<const char> name;
    Ptr32<void> create;
    Ptr32<void> destroy;
    int priority;
    Ptr32<K5bTypeNode> parent;
    K5bTypeNode(Ptr32<const char> n, Ptr32<void> c, Ptr32<void> d, int p, Ptr32<K5bTypeNode> up)
    {
        name = n;
        create = c;
        destroy = d;
        priority = p;
        parent = up;
        w3d_s21_insert_sorted_80200af8(this);
    }
    K5bTypeNode(Ptr32<const char> n, Ptr32<void> d, int p, Ptr32<K5bTypeNode> up)
    {
        name = n;
        create = 0;
        destroy = d;
        priority = p;
        parent = up;
        w3d_s21_insert_sorted_80200af8(this);
    }
};
extern struct K5bShared lbl_804b0590;
extern struct K5bShared lbl_804b0594;
extern struct K5bShared lbl_804b0598;
extern struct K5bShared lbl_804b059c;
extern Ptr32<void> lbl_80417760[];
extern Ptr32<void> lbl_80417730[];
extern Ptr32<void> lbl_80417748[];
extern K5bTypeNode lbl_8045e14c;
extern K5bTypeNode lbl_8045e164;
extern struct K5bTypeNode lbl_8045e124[];
extern char lbl_803b0d2c[];
extern char lbl_803b0d34[];
extern char lbl_803b0d3c[];
extern "C" int w3d_k5b_shared_defaults_create_801edab8(void);
extern "C" int w3d_auto_801edbd4(void);
extern "C" int w3d_auto_801edc28(void);
extern "C" Ptr32<void> w3d_auto_801ede78(Ptr32<struct K5bShared> object);
extern "C" void w3d_k5b_field_types_sinit_801ef45c(int initialize, int priority)
{
    if (priority == 0xffff && initialize != 0) {
        w3d_auto_801ede78(&lbl_804b0590);
        w3d_auto_801ede78(&lbl_804b0594);
        lbl_804b0594.vtable = lbl_80417760;
        w3d_auto_801ede78(&lbl_804b0598);
        lbl_804b0598.vtable = lbl_80417730;
        w3d_auto_801ede78(&lbl_804b059c);
        lbl_804b059c.vtable = lbl_80417748;
        new (&lbl_8045e14c) K5bTypeNode(lbl_803b0d2c, (Ptr32<void>)w3d_k5b_shared_defaults_create_801edab8,
            (Ptr32<void>)w3d_auto_801edbd4, 90, lbl_8045e124);
        new (&lbl_804b05a0) W3dType_802097ec(lbl_803b0d34, 0, 0);
        new (&lbl_8045e164) K5bTypeNode(lbl_803b0d3c, (Ptr32<void>)w3d_auto_801edc28, 10, lbl_8045e124);
    }
}
// desc: w3d_k5b_field_types_sinit_801ef45c: Appears to be a static initializer: constructs the four shared field objects at 0x804b0590, registers the MFImpl and XMFieldArena type nodes and the MField name.


