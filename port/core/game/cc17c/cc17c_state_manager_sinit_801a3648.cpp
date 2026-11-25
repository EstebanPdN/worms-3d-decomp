#include "w3d_ptr.h"
#line 1 "cc17c_state_manager_sinit_801a3648.cpp"
inline void *operator new(__SIZE_TYPE__, void *place) { return place; }
/* Inferred static factory record (observed word offsets 0..20) and registration. */
struct Cc17cFactoryList;
typedef Ptr32<void (void)> Cc17cFactoryCallback;
struct Cc17cFactoryRecord {
    Ptr32<Cc17cFactoryRecord> next;
    Ptr32<char> name;
    Cc17cFactoryCallback first;
    Cc17cFactoryCallback second;
    int priority;
    Ptr32<Cc17cFactoryList> list;
};
/* STLport red-black tree node shape (20 bytes observed): color, parent, left, right, value. */
struct Cc17cTreeNode { int color; Ptr32<Cc17cTreeNode> parent; Ptr32<Cc17cTreeNode> left; Ptr32<Cc17cTreeNode> right; int value; };
extern "C" {
void fn_80200af8(Ptr32<Cc17cFactoryRecord>);
Ptr32<void> fn_8020fbd0(Ptr32<void>, Ptr32<void>, Ptr32<void>, Ptr32<void>, int, int);
Ptr32<void> fn_80212fd4(unsigned int);
Ptr32<void> fn_803413d8(unsigned int);
int fn_801a18bc(void);
int fn_801a188c(void);
Ptr32<void> fn_801a2478(void);
extern char lbl_803a9bf0[], lbl_803e8d80[], lbl_80362330[];
extern unsigned char lbl_80413a38[], lbl_80413a20[];
extern Cc17cFactoryRecord lbl_8045ce14;
extern Cc17cFactoryList lbl_8045cea4;
}
/* Three zeroed words (observed); inferred empty list/range object. */
struct Cc17cTriple { Ptr32<void> a; Ptr32<void> b; Ptr32<void> c; Cc17cTriple() { c = 0; b = 0; a = 0; } };
extern Cc17cTriple lbl_8045ce40;
struct Cc17cTree {
    unsigned int unknown_00;
    Ptr32<Cc17cTreeNode> header;
    unsigned int count;
    unsigned char compare;
    void initialize() {
        header = 0;
        Ptr32<Cc17cTreeNode> node = (Ptr32<Cc17cTreeNode>)fn_80212fd4(sizeof(Cc17cTreeNode));
        if (!node) node = (Ptr32<Cc17cTreeNode>)fn_803413d8(sizeof(Cc17cTreeNode));
        header = node;
        count = 0;
        compare = 0;
        header->color = 0;
        header->parent = 0;
        header->left = header;
        header->right = header;
    }
};
struct Cc17cStateManager {
    Ptr32<void> vptr;
    Cc17cTree tree;
};
extern Cc17cStateManager lbl_8045ce2c;
static inline void cc17c_state_manager_init(Ptr32<Cc17cStateManager> self)
{
    volatile char pad[16]; /* frame reservation; inferred STLport default-allocator temporaries */
    self->vptr = lbl_80413a38;
    self->tree.initialize();
    self->vptr = lbl_80413a20;
}
extern "C" void w3d_cc17c_sinit_801a3648(int init, int priority)
{
    if (priority == 0xffff && init) {
        Ptr32<Cc17cFactoryRecord> record = &lbl_8045ce14;
        record->name = lbl_803a9bf0;
        record->first = (Ptr32<void (void)>)fn_801a188c;
        record->second = (Ptr32<void (void)>)fn_801a18bc;
        record->list = &lbl_8045cea4;
        record->priority = 0;
        fn_80200af8(record);
        cc17c_state_manager_init(&lbl_8045ce2c);
        new (&lbl_8045ce40) Cc17cTriple;
        fn_8020fbd0(lbl_80362330, lbl_803e8d80, lbl_80362330, (Ptr32<void>)fn_801a2478, 0, 0);
    }
}


