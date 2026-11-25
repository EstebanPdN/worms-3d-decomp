// (Worms 3D GameCube PAL, 0x801e7e24).
//
// Initializes an actor and its children: on first use creates the worker
// from class record 0x803657d8, keeps it in the reference at +48, sets its
// owner and flag and attaches it to the parent's worker (or null for a
// root); then sets up hooks through 0x801e7658, recurses into each direct
// child found with the child iterator, and calls the worker's prepare slot.
// Bracketed by 0x8020b5c8(-1) and 0x8020b5d0. Returns 0. Names are inferred.

struct Actor;
struct ActorBase { char u0[4]; Actor *next; char u8[12]; };
struct Actor;
struct Worker;
struct Ref {
    Worker *p;
    Ref &operator=(Worker *q);
};
extern "C" Actor *w3d_actor_types_first();
extern "C" Actor *w3d_auto_8020ff34();
struct Actor : ActorBase {
    Actor *parent;
    char u24[24];
    Ref worker;
};
struct ChildIter {
    Actor *root;
    Actor *cur;
    unsigned second : 1;
    unsigned both : 1;
    unsigned rest : 30;
    ChildIter(Actor *r) {
        second = 0;
        both = 0;
        root = r;
        cur = w3d_actor_types_first();
        while (cur == r || (cur && cur->parent != r)) cur = cur->next;
        if (!cur && both) {
            cur = w3d_auto_8020ff34();
            second = 1;
            while (cur == r || (cur && cur->parent != r)) cur = cur->next;
        }
    }
    ChildIter(Actor *r, int) { root = r; cur = 0; }
    Actor *operator*() const { return cur; }
    bool operator!=(const ChildIter &o) const { return root != o.root || cur != o.cur; }
    ChildIter &operator++() {
        if (cur) {
            do {
                cur = cur->next;
            } while (cur == root || (cur && cur->parent != root));
            if (!cur) {
                if (!second) {
                    if (both) {
                        cur = w3d_auto_8020ff34();
                        second = 1;
                        while (cur == root || (cur && cur->parent != root)) cur = cur->next;
                    }
                }
            }
        }
        return *this;
    }
};
struct WorkerBase {
    virtual void v0(); virtual void AddRef(); virtual void Release(); virtual void v3(), v4(), v5();
    virtual void attach(Worker *);
    virtual void v7();
    virtual int prepare();
};
struct Worker : WorkerBase {
    char u4[28];
    unsigned b0 : 1;
    unsigned b1 : 1;
    unsigned rest : 30;
    char u36[28];
    Actor *owner;
};
inline Ref &Ref::operator=(Worker *q) {
    if (q) q->AddRef();
    if (p) p->Release();
    p = q;
    return *this;
}
struct ClassInfo;
extern ClassInfo k_803657d8[];
extern "C" Worker *w3d_r24b_invoke_ready_callback_8020fcb4(const ClassInfo *);
extern "C" int w3d_constant_8020b5c8(int);
extern "C" void w3d_empty_8020b5d0();
extern "C" int fn_801e7658(Actor *);
extern "C" int w3d_d31e_init_actor_tree_801e7e24(Actor *self)
{
    w3d_constant_8020b5c8(-1);
    if (!self->worker.p) {
        self->worker = w3d_r24b_invoke_ready_callback_8020fcb4(k_803657d8);
        Worker *o = self->worker.p;
        o->owner = self;
        o->b1 = 1;
        if (self->parent == self) o->attach(0);
        else o->attach(self->parent->worker.p);
    }
    fn_801e7658(self);
    ChildIter it(self), end(self, 0);
    while (it != end) {
        w3d_d31e_init_actor_tree_801e7e24(*it);
        ++it;
    }
    self->worker.p->prepare();
    w3d_empty_8020b5d0();
    return 0;
}
