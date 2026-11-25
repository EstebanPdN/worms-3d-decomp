// (Worms 3D GameCube PAL, 0x801f3a00).
//
// Registers a hook for a class index with override rules: the low two state
// bits select the rule. A locked slot (low bits 0 or 1, top bits clear)
// keeps its hook; a slot with low bits 2 or 3 accepts only new states 2 or
// 3. Stores hook at +20 and state at +52 when accepted. Unless the new state
// has low bit 1 set or the slot rule stops it, recurses into each direct
// child class with state 128 using the child iterator. Names are inferred.

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
    ChildIter(Class *r, int) { root = r; cur = 0; }
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
typedef void (*Hook)();
struct ClassList { Class **begin; };
extern ClassList lbl_8045e080[];
struct State { unsigned char top : 2; unsigned char mid : 4; unsigned char low : 2; };
struct Self { char u[20]; Hook *hooks; char u24[28]; State *states; };
extern "C" void w3d_d31e_set_class_hook_flagged_801f3a00(Self *self, unsigned index, Hook hook, unsigned char state)
{
    unsigned low = state & 3;
    Class *c = *(Class **)((char *)lbl_8045e080[0].begin + (index << 2));
    bool recurse = false;
    bool apply = true;
    if (low != 1 && low != 3) recurse = true;
    State old = self->states[index];
    switch (old.low) {
    case 2: case 3:
        apply = false; if (low == 2 || low == 3) apply = true;
        break;
    case 1:
        if (old.top == 0) apply = false;
        break;
    case 0:
        if (old.top == 0) { recurse = false; apply = false; }
        break;
    }
    if (apply) {
        *(Hook *)((char *)self->hooks + (index << 2)) = hook;
        *(unsigned char *)&self->states[index] = state;
    }
    if (!recurse) return;
    ChildIter it(c), end(c, 0);
    while (it != end) {
        w3d_d31e_set_class_hook_flagged_801f3a00(self, (*it)->info >> 22, hook, 128);
        ++it;
    }
}
