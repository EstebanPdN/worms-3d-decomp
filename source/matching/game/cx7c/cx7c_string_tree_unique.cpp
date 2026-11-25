/* Inferred STLport red-black tree insertion. Node offsets: color +0,
 * parent +4, left +8, right +12, value +16. Table header +4/count +8.
 * Public names describe structure, not original game class identity.
 */
inline void *operator new(unsigned int,void *p) throw() {return p;}
struct Cx7cTreeNode {int color;Cx7cTreeNode *parent,*left,*right;};
struct Cx7cTreeIterator {
    Cx7cTreeNode *node;
    Cx7cTreeIterator(Cx7cTreeNode *p):node(p) {}
    Cx7cTreeIterator(const Cx7cTreeIterator &other):node(other.node) {}
};
extern "C" {
void *cx7c_allocate_80212fd4(unsigned int);
void *cx7c_allocation_fallback_803413d8(unsigned int);
void cx7c_rebalance_80352404(Cx7cTreeNode *,Cx7cTreeNode *&);
}
static inline void *cx7c_tree_allocate(unsigned int size) {
    void *p=cx7c_allocate_80212fd4(size);
    if (!p) p=cx7c_allocation_fallback_803413d8(size);
    return p;
}
struct Cx7cTreeString;
extern "C" {
void cx7c_string_base_init_8020c5c0(Cx7cTreeString *);
unsigned short *cx7c_string_header_80341884(Cx7cTreeString *);
int cx7c_strcmp_802ef234(const char *,const char *);
}
struct Cx7cTreeString {
    char *data;
    Cx7cTreeString(const Cx7cTreeString &other) {
        cx7c_string_base_init_8020c5c0(this);
        data=other.data;
        ++*cx7c_string_header_80341884(this);
    }
};
struct Cx7cTreeValue {
    Cx7cTreeString key;unsigned int payload;
    Cx7cTreeValue(const Cx7cTreeValue &other):key(other.key),payload(other.payload) {}
};
struct Cx7cValueNode:Cx7cTreeNode {Cx7cTreeValue value;};
struct Cx7cTree {
    unsigned int unknown_00;Cx7cTreeNode *header;unsigned int count;
    Cx7cTreeNode *create(const Cx7cTreeValue &value) {
        Cx7cValueNode *node=(Cx7cValueNode *)cx7c_tree_allocate(sizeof(Cx7cValueNode));
        new (&node->value) Cx7cTreeValue(value);
        return node;
    }
};
struct Cx7cInsertResult {
    Cx7cTreeIterator iterator;bool inserted;
    Cx7cInsertResult(const Cx7cTreeIterator &it,const bool &yes):iterator(it),inserted(yes) {}
};
extern "C" Cx7cTreeNode *cx7c_tree_predecessor_803526a0(Cx7cTreeNode *);
extern "C" Cx7cTreeIterator cx7c_tree_insert_8035a464(Cx7cTree *,Cx7cTreeNode *,Cx7cTreeNode *,const Cx7cTreeValue &,Cx7cTreeNode *);
extern "C" Cx7cInsertResult w3d_cx7c_string_tree_insert_unique_8035a5e4(Cx7cTree *self,const Cx7cTreeValue &value)
{
    Cx7cTreeNode *parent=self->header;
    Cx7cTreeNode *child=parent->parent;
    bool goes_left=true;
    while (child) {
        parent=child;
        goes_left=cx7c_strcmp_802ef234(value.key.data,((Cx7cValueNode *)parent)->value.key.data)<0;
        child=goes_left?parent->left:parent->right;
    }
    Cx7cTreeIterator position(parent);
    if (goes_left) {
        Cx7cTreeIterator first(self->header->left);
        if (position.node==first.node)
            return Cx7cInsertResult(cx7c_tree_insert_8035a464(self,child,parent,value,0),true);
        position.node=cx7c_tree_predecessor_803526a0(position.node);
    }
    goes_left=cx7c_strcmp_802ef234(((Cx7cValueNode *)position.node)->value.key.data,value.key.data)<0;
    if (goes_left)
        return Cx7cInsertResult(cx7c_tree_insert_8035a464(self,child,parent,value,0),true);
    return Cx7cInsertResult(position,goes_left);
}
