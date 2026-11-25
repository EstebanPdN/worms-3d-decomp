// (Worms 3D GameCube PAL, 0x801a6b44).
//
// Clone visitor over an object tree, entered through a secondary-base
// pointer: decides by 0x801a69a8 whether a node is shared (returns an
// existing clone or the node) or copied; for a copy, walks the class
// properties from last to first and, for each object-valued property (type
// 24), reads the child, queries the object interface, and when its class
// derives from 0x80365788 replaces it with the clone found by 0x801a688c or,
// in deep mode, the result of visiting it. Handles array properties by index
// and single properties through member-function getters and setters. Returns
// 0, 1 if already handled, or the negative error.

inline void *operator new(unsigned int, void *place) throw() { return place; }
struct Prop;
struct Class { char u0[20]; Class *parent; char u24[36]; Prop **first; Prop **last; };
struct Desc { char u0[4]; unsigned short id; unsigned char arg; unsigned char flags; int type; };
extern "C" Prop *w3d_s21_vector_get_801e9db8(Class *, unsigned);
extern "C" int w3d_auto_801fffc8(int);
extern Class lbl_80365788[];
extern char lbl_8040c960[];
struct Node;
struct Unknown {
    virtual int Query(const void *iid, Node **out);
    virtual void AddRef(); virtual int Release();
    virtual Class *GetClass();
};
struct Node : Unknown { char u4[2]; unsigned short id; };
struct Ref {
    Node *p;
    Ref() { p = 0; }
    Ref(Node *q) { p = q; if (q) q->AddRef(); }
    Ref(const Ref &o);
    ~Ref() { if (p) p->Release(); }
    Node *operator->() const { return p; }
    Node &operator*() const { return *p; }
};
struct PropBase {
    Desc *desc;
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
    virtual Node **Array(Node *, int, int, unsigned *);
};
struct Prop : PropBase {
    int u8;
    Node *(Node::*get)();
    void (Node::*set)(Node *);
};
struct Tree;
extern "C" int f11c_hierarchy_801a69a8(Tree *, Node *);
extern "C" Node *w3d_s20_find_value_801a688c(Tree *, Node *);
extern "C" void w3d_s10_assign_interface_801a66c0(Tree *, Node *);
extern "C" int w3d_s20_find_or_create_801a692c(Tree *, Node *);
extern "C" void w3d_k5b_iface_array_field_set_801ef2ec(Node *, int, int, Node *, unsigned);
struct Iface {
    char u0[24]; int (**table)(Iface *, Node *);
    int Visit(Node *n) { return table[n->id](this, n); }
};
struct TreeBase {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual Node *Current();
};
struct Tree : TreeBase {
    char iface[40];
    int mode;
    char u48[24];
    int stop;
    Iface *I() { return (Iface *)iface; }
};
static inline bool IsA(Class *t, Class *k) {
    while (t != k) {
        Class *p = t->parent;
        if (t == p) return false;
        t = p;
    }
    return true;
}
extern "C" int w3d_d32e_clone_node_tree_801a6b44(char *ip, Node *x)
{
    Tree *self = ip ? (Tree *)(ip - 4) : 0;
    int m = f11c_hierarchy_801a69a8(self, x);
    self->stop = 0;
    if (m == 1) {
        Node *v = w3d_s20_find_value_801a688c(self, x);
        if (v) w3d_s10_assign_interface_801a66c0(self, v);
        else w3d_s10_assign_interface_801a66c0(self, x);
        return 0;
    }
    int r = w3d_s20_find_or_create_801a692c(self, x);
    if (r < 0) return r;
    if (r == 1) return 1;
    Ref cur = self->Current();
    bool any = self->mode != 0;
    Class *c = cur->GetClass();
    int i = c->last - c->first;
    while (i--) {
        Prop *q = w3d_s21_vector_get_801e9db8(c, i);
        if (w3d_auto_801fffc8(q->desc->type) == 24) {
            if (q->desc->flags & 1) {
                unsigned n;
                Node **arr = q->Array(cur.p, 0, 2, &n);
                for (unsigned j = 0; j < n; j++) {
                    Node *e = arr[j];
                    if (e) {
                        Ref o;
                        if (e->Query(lbl_8040c960, &o.p) >= 0) {
                            if (IsA(o->GetClass(), lbl_80365788)) {
                                Node *on = o.p;
                                Node *v = w3d_s20_find_value_801a688c(self, on);
                                if (!v) {
                                    if (any) {
                                        w3d_s10_assign_interface_801a66c0(self, 0);
                                        self->I()->Visit(on);
                                        v = self->Current();
                                    } else v = on;
                                }
                                if (v != on)
                                    w3d_k5b_iface_array_field_set_801ef2ec(cur.p, q->desc->id, q->desc->arg, v, j);
                            }
                        }
                    }
                }
            } else {
                Node *e = ((*cur).*(q->get))();
                if (e) {
                    Ref o;
                    if (e->Query(lbl_8040c960, &o.p) >= 0) {
                        if (IsA(o->GetClass(), lbl_80365788)) {
                            Node *on = o.p;
                            Node *v = w3d_s20_find_value_801a688c(self, on);
                            if (!v) {
                                if (any) {
                                    w3d_s10_assign_interface_801a66c0(self, 0);
                                    self->I()->Visit(on);
                                    v = self->Current();
                                } else v = on;
                            }
                            if (v != on) ((*cur).*(q->set))(v);
                        }
                    }
                }
            }
        }
    }
    w3d_s10_assign_interface_801a66c0(self, cur.p);
    return 0;
}
