inline void *operator new(unsigned int, void *place) { return place; }
/* Inferred static factory record (observed word offsets 0..20) and registration. */
struct Cc17cFactoryList;
typedef void (*Cc17cFactoryCallback)(void);
struct Cc17cFactoryRecord {
    Cc17cFactoryRecord *next;
    char *name;
    Cc17cFactoryCallback first;
    Cc17cFactoryCallback second;
    int priority;
    Cc17cFactoryList *list;
};
/* STLport red-black tree node shape (20 bytes observed): color, parent, left, right, value. */
struct Cc17cTreeNode { int color; Cc17cTreeNode *parent; Cc17cTreeNode *left; Cc17cTreeNode *right; int value; };
extern "C" {
void fn_80200af8(Cc17cFactoryRecord *);
void *fn_8020fbd0(void *, void *, void *, void *, int, int);
void *fn_80212fd4(unsigned int);
void *fn_803413d8(unsigned int);
int fn_801a18bc(void);
int fn_801a188c(void);
void * fn_801a2478(void);
extern char lbl_803a9bf0[], lbl_803e8d80[], lbl_80362330[];
extern unsigned char lbl_80413a38[], lbl_80413a20[];
extern Cc17cFactoryRecord lbl_8045ce14;
extern Cc17cFactoryList lbl_8045cea4;
}
/* Three zeroed words (observed); inferred empty list/range object. */
struct Cc17cTriple { void *a; void *b; void *c; Cc17cTriple() { c = 0; b = 0; a = 0; } };
extern Cc17cTriple lbl_8045ce40;
struct Cc17cTree {
    unsigned int unknown_00;
    Cc17cTreeNode *header;
    unsigned int count;
    unsigned char compare;
    void initialize() {
        header = 0;
        Cc17cTreeNode *node = (Cc17cTreeNode *)fn_80212fd4(sizeof(Cc17cTreeNode));
        if (!node) node = (Cc17cTreeNode *)fn_803413d8(sizeof(Cc17cTreeNode));
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
    void *vptr;
    Cc17cTree tree;
};
extern Cc17cStateManager lbl_8045ce2c;
static inline void cc17c_state_manager_init(Cc17cStateManager *self)
{
    volatile char pad[16]; /* frame reservation; inferred STLport default-allocator temporaries */
    self->vptr = lbl_80413a38;
    self->tree.initialize();
    self->vptr = lbl_80413a20;
}
extern "C" void w3d_cc17c_sinit_801a3648(int init, int priority)
{
    if (priority == 0xffff && init) {
        Cc17cFactoryRecord *record = &lbl_8045ce14;
        record->name = lbl_803a9bf0;
        record->first = (void (*)(void))fn_801a188c;
        record->second = (void (*)(void))fn_801a18bc;
        record->list = &lbl_8045cea4;
        record->priority = 0;
        fn_80200af8(record);
        cc17c_state_manager_init(&lbl_8045ce2c);
        new (&lbl_8045ce40) Cc17cTriple;
        fn_8020fbd0(lbl_80362330, lbl_803e8d80, lbl_80362330, (void *)fn_801a2478, 0, 0);
    }
}
