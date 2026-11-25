// (Worms 3D GameCube PAL, 0x801e7270).
//
// Registers a hook for a class index on an object, unless the slot is locked
// (state 1, or state 2 when the new state is 0): stores the hook at +52 and
// the state at +64, then visits the class's direct children (iterating the
// actor type list and skipping non-children) and applies the hook with state
// 0 to every child whose state is still 0. Names are inferred.

struct Class { char u4[4]; Class *next; char u8[12]; Class *parent; char u24[8]; unsigned info; };
extern "C" Class *w3d_actor_types_first();
extern "C" Class *w3d_auto_8020ff34();
struct ChildIter {
    Class *root;
    Class *cur;
    unsigned second : 1;
    unsigned both : 1;
    unsigned rest : 30;
    ChildIter(Class *r) {
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
    ChildIter(Class *r, Class *c) { root = r; cur = c; }
    Class *operator*() const { return cur; }
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
struct ClassList { Class **begin; };
extern ClassList lbl_8045e080[];
typedef void (*Hook)();
struct Self { char u[52]; Hook *hooks; char u56[8]; unsigned char *states; };
extern "C" void w3d_d31e_set_class_hook_801e7270(Self *self, unsigned index, Hook hook, unsigned char state)
{
    unsigned char old = self->states[index];
    Class *c = *(Class **)((char *)lbl_8045e080[0].begin + (index << 2));
    if (old == 1) return;
    if (old == 2 && state == 0) return;
    *(Hook *)((char *)self->hooks + (index << 2)) = hook;
    self->states[index] = state;
    ChildIter it(c), end(c, 0);
    while (it != end) {
        unsigned i = (*it)->info >> 22;
        if (self->states[i] == 0) w3d_d31e_set_class_hook_801e7270(self, i, hook, 0);
        ++it;
    }
}
