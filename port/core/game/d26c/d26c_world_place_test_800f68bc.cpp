#include "w3d_ptr.h"
#line 1 "d26c_world_place_test_800f68bc.cpp"
// d26c: 0x800f68bc. Trial-place a new instance into a group slot: reject when too deep or when a part test fails,
// or when it overlaps another group. Always destroys the instance and clears the slot. Names are inferred.
struct Inst { char u0[40]; float depth; };
struct InstVec {
    char u0[4]; Ptr32<Ptr32<Inst>> start;
    Ptr32<Inst> & operator[](int i) { return start[i]; }
};
struct Group { InstVec items; };
struct GroupVec {
    Ptr32<Ptr32<Group>> start; Ptr32<Ptr32<Group>> finish;
    unsigned size() const { return finish - start; }
    Ptr32<Group> & operator[](unsigned i) { return start[i]; }
};
struct World { char u0[44]; GroupVec groups; };
extern "C" Ptr32<Inst> make_800f55e8(Ptr32<World>, int, int);
extern "C" void place_800f5c1c(Ptr32<World>, Ptr32<Group>, int, Ptr32<Inst>, int);
extern "C" int touch_800f6760(Ptr32<World>, Ptr32<Inst>);
extern "C" int plane_800f66ac(Ptr32<World>, Ptr32<Inst>);
extern "C" int frustum_800f6798(Ptr32<World>, Ptr32<Inst>);
extern "C" int overlap_800f65cc(Ptr32<World>, Ptr32<Group>, Ptr32<Inst>);
extern "C" void cleanup_800f6ca0(Ptr32<Inst>, int);
extern "C" int d26c_world_place_test_800f68bc(Ptr32<World> self, Ptr32<Group> g, int idx, Ptr32<void> what, Ptr32<void> where) {
    Ptr32<Inst> inst = make_800f55e8(self, (int)w3d::H(what), 0);
    place_800f5c1c(self, g, idx, inst, (int)w3d::H(where));
    if (inst->depth < -4.0f || !touch_800f6760(self, inst) || !plane_800f66ac(self, inst) || !frustum_800f6798(self, inst)) {
        if (inst) { cleanup_800f6ca0(inst, 3); }
        inst = 0;
        g->items[idx] = inst;
        return 1;
    }
    for (unsigned i = 0; i < self->groups.size(); i++) {
        Ptr32<Group> o = self->groups[i];
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


