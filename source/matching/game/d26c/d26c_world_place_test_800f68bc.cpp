// d26c: 0x800f68bc. Trial-place a new instance into a group slot: reject when too deep or when a part test fails,
// or when it overlaps another group. Always destroys the instance and clears the slot. Names are inferred.
struct Inst { char u0[40]; float depth; };
struct InstVec {
    char u0[4]; Inst **start;
    Inst *&operator[](int i) { return start[i]; }
};
struct Group { InstVec items; };
struct GroupVec {
    Group **start, **finish;
    unsigned size() const { return finish - start; }
    Group *&operator[](unsigned i) { return start[i]; }
};
struct World { char u0[44]; GroupVec groups; };
extern "C" Inst *make_800f55e8(World *, int, int);
extern "C" void place_800f5c1c(World *, Group *, int, Inst *, int);
extern "C" int touch_800f6760(World *, Inst *);
extern "C" int plane_800f66ac(World *, Inst *);
extern "C" int frustum_800f6798(World *, Inst *);
extern "C" int overlap_800f65cc(World *, Group *, Inst *);
extern "C" void cleanup_800f6ca0(Inst *, int);
extern "C" int d26c_world_place_test_800f68bc(World *self, Group *g, int idx, void *what, void *where) {
    Inst *inst = make_800f55e8(self, (int)what, 0);
    place_800f5c1c(self, g, idx, inst, (int)where);
    if (inst->depth < -4.0f || !touch_800f6760(self, inst) || !plane_800f66ac(self, inst) || !frustum_800f6798(self, inst)) {
        if (inst) { cleanup_800f6ca0(inst, 3); }
        inst = 0;
        g->items[idx] = inst;
        return 1;
    }
    for (unsigned i = 0; i < self->groups.size(); i++) {
        Group *o = self->groups[i];
        if (o != g && overlap_800f65cc(self, o, inst)) {
            if (inst) { cleanup_800f6ca0(inst, 3); }
            inst = 0;
            g->items[idx] = inst;
            return 1;
        }
    }
    if (inst) { cleanup_800f6ca0(inst, 3); }
    inst = 0;
    g->items[idx] = inst;
    return 0;
}
