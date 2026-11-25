// GWMP8P rev0, 0x80355b6c: inferred ordered-tree node insertion.
// GC32 node header 16 bytes; value 68 bytes, complete allocation 84 bytes.
// Value: word +0, retained interface +4, counted-reference array +8 (12 bytes),
// 48-byte member +20 with observed aggregate copies of 36 and 12 bytes.
// The second key word is the held pointer's unsigned GC32 representation.
// Original names, STL identities and member semantics remain unknown.
// Native virtual retain slot +12 requires the four-byte thunk table ABI.
// This partial view recovers construction only, not complete member lifetimes.
// Requires live compatible interfaces, valid source/storage/tree bounds and
// external allocation/counted-copy/rebalance contracts. No portable or
// whole-game/runtime/hardware equivalence is established by isolated matching.
inline void *operator new(unsigned int,void *p) throw() {return p;}
struct Sol35f8bPairTreeNode {int color;Sol35f8bPairTreeNode *parent,*left,*right;};
struct Sol35f8bPairTreeIterator {
    Sol35f8bPairTreeNode *node;
    Sol35f8bPairTreeIterator(Sol35f8bPairTreeNode *p):node(p) {}
    Sol35f8bPairTreeIterator(const Sol35f8bPairTreeIterator &other):node(other.node) {}
};
extern "C" {
void *sol35f8b_allocate_80212fd4(unsigned int);
void *sol35f8b_allocation_fallback_803413d8(unsigned int);
void sol35f8b_rebalance_80352404(Sol35f8bPairTreeNode *,Sol35f8bPairTreeNode *&);
}
static inline void *sol35f8b_tree_allocate(unsigned int size) {
    void *p=sol35f8b_allocate_80212fd4(size);
    if (!p) p=sol35f8b_allocation_fallback_803413d8(size);
    return p;
}
struct Sol35f8bPairInterface {
    virtual void slot0()=0;
    virtual void retain()=0;
    virtual void release()=0;
};
struct Sol35f8bPairHeld {
    Sol35f8bPairInterface *pointer;
    Sol35f8bPairHeld(const Sol35f8bPairHeld &o):pointer(o.pointer) {if(pointer)pointer->retain();}
};
struct Sol35f8bPairRefs;
extern "C" Sol35f8bPairRefs *sol35f8b_copy_refs_801f2698(Sol35f8bPairRefs *,const Sol35f8bPairRefs *);
struct Sol35f8bPairRefs {
    unsigned count;
    unsigned short capacity,growth;
    Sol35f8bPairInterface **slots;
    Sol35f8bPairRefs(const Sol35f8bPairRefs &o) {sol35f8b_copy_refs_801f2698(this,&o);}
};
struct Sol35f8bPairBlock36 {unsigned words[9];};
struct Sol35f8bPairTail12 {unsigned words[3];};
struct Sol35f8bPairBody48 {
    Sol35f8bPairBlock36 block;
    Sol35f8bPairTail12 tail;
    Sol35f8bPairBody48(const Sol35f8bPairBody48 &o):block(o.block),tail(o.tail) {}
};
struct Sol35f8bPairTreeValue {
    unsigned key;
    Sol35f8bPairHeld held;
    Sol35f8bPairRefs refs;
    Sol35f8bPairBody48 body;
};
struct Sol35f8bPairValueNode:Sol35f8bPairTreeNode {Sol35f8bPairTreeValue value;};
struct Sol35f8bPairTree {
    unsigned int unknown_00;Sol35f8bPairTreeNode *header;unsigned int count;
    Sol35f8bPairTreeNode *create(const Sol35f8bPairTreeValue &value) {
        Sol35f8bPairValueNode *node=(Sol35f8bPairValueNode *)sol35f8b_tree_allocate(sizeof(Sol35f8bPairValueNode));
        new (&node->value) Sol35f8bPairTreeValue(value);
        return node;
    }
};
static inline bool pair_less(const Sol35f8bPairTreeValue &a,const Sol35f8bPairValueNode *b) {
 return a.key<b->value.key || (a.key==b->value.key && (unsigned)a.held.pointer<(unsigned)b->value.held.pointer);
}
typedef char Sol35f8bPairNodeSize[sizeof(Sol35f8bPairValueNode)==84?1:-1];
extern "C" Sol35f8bPairTreeIterator sol35f8b_pair_record_insert_80355b6c(Sol35f8bPairTree *self,Sol35f8bPairTreeNode *child,Sol35f8bPairTreeNode *parent,const Sol35f8bPairTreeValue &value,Sol35f8bPairTreeNode *special)
{
    Sol35f8bPairTreeNode *node;
    if (parent==self->header || (!special && (child || pair_less(value,(Sol35f8bPairValueNode *)parent)))) {
        node=self->create(value);
        parent->left=node;
        if (parent==self->header) {
            self->header->parent=node;
            self->header->right=node;
        } else if (parent==self->header->left) self->header->left=node;
    } else {
        node=self->create(value);
        parent->right=node;
        if (parent==self->header->right) self->header->right=node;
    }
    node->parent=parent;
    node->left=0;
    node->right=0;
    sol35f8b_rebalance_80352404(node,self->header->parent);
    ++self->count;
    return Sol35f8bPairTreeIterator(node);
}
