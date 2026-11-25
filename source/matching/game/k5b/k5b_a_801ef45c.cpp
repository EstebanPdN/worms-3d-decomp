struct K5bShared { void **vtable; };
inline void *operator new(unsigned int, void *place) { return place; }
struct W3dType_802097ec {
    W3dType_802097ec(const char *name, int a, int b);
    int word;
};
extern W3dType_802097ec lbl_804b05a0;
struct K5bTypeNode;
extern "C" void w3d_s21_insert_sorted_80200af8(K5bTypeNode *node);
struct K5bTypeNode {
    K5bTypeNode *next;
    const char *name;
    void *create;
    void *destroy;
    int priority;
    K5bTypeNode *parent;
    K5bTypeNode(const char *n, void *c, void *d, int p, K5bTypeNode *up)
    {
        name = n;
        create = c;
        destroy = d;
        priority = p;
        parent = up;
        w3d_s21_insert_sorted_80200af8(this);
    }
    K5bTypeNode(const char *n, void *d, int p, K5bTypeNode *up)
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
extern void *lbl_80417760[];
extern void *lbl_80417730[];
extern void *lbl_80417748[];
extern K5bTypeNode lbl_8045e14c;
extern K5bTypeNode lbl_8045e164;
extern struct K5bTypeNode lbl_8045e124[];
extern char lbl_803b0d2c[];
extern char lbl_803b0d34[];
extern char lbl_803b0d3c[];
extern "C" int w3d_k5b_shared_defaults_create_801edab8(void);
extern "C" int w3d_auto_801edbd4(void);
extern "C" int w3d_auto_801edc28(void);
extern "C" void *w3d_auto_801ede78(struct K5bShared *object);
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
        new (&lbl_8045e14c) K5bTypeNode(lbl_803b0d2c, (void *)w3d_k5b_shared_defaults_create_801edab8,
            (void *)w3d_auto_801edbd4, 90, lbl_8045e124);
        new (&lbl_804b05a0) W3dType_802097ec(lbl_803b0d34, 0, 0);
        new (&lbl_8045e164) K5bTypeNode(lbl_803b0d3c, (void *)w3d_auto_801edc28, 10, lbl_8045e124);
    }
}
// desc: w3d_k5b_field_types_sinit_801ef45c: Appears to be a static initializer: constructs the four shared field objects at 0x804b0590, registers the MFImpl and XMFieldArena type nodes and the MField name.
