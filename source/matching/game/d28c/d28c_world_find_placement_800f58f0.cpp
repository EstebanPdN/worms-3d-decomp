// d28c: 0x800f58f0. Searches slots, objects and items for the next free placement whose mask and vector bounds fit, resuming from the three counters it is given, and writes them back on success. Names are inferred; classes are partial views.
struct Vec3 { float x, y, z; Vec3() {} Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; } };
template <class T> inline const T &maximum(const T &a, const T &b) { return a < b ? b : a; }
struct Item { char u0[32]; Vec3 pos; char u44[12]; union { unsigned short mask; unsigned flags; }; };
struct Count { int v; };
extern Count count_804af0c8;
struct Table { char u0[24]; int count; char u28[4]; Item *items[1];
    Item *at(int i) { count_804af0c8.v = count; Item **p = items; return p[i]; } };
struct Obj { char u0[60]; int type; char u64[16]; Table *table; };
struct Slots { int *first, *last; int size() const { return last - first; } int &operator[](int i) { return first[i]; } };
struct Group { char u0[4]; Slots slots; char u12[16]; int owner; };
struct World { char u0[40]; int start; char u44[36]; Obj **objs; int nobjs; char u88[900]; int have[506]; unsigned short used[16]; };
extern int need_8038c588[];
extern "C" int adjust_800f6c54(World *, Obj *);
extern "C" int mask_test_800f58dc(unsigned);
extern "C" int all_ge_800f5894(Vec3 *, Vec3 *);
extern "C" int place_test_800f68bc(World *, Group *, int, int, int);
extern "C" int d28c_world_find_placement_800f58f0(World *self, Group *g, int *pb, int *pa, int *pc) {
    unsigned tries = 0;
    int a0 = *pa;
    int i = maximum(a0, 0);
    int b0 = *pb;
    int j = maximum(b0, 0);
    int c0 = *pc;
    int k = maximum(c0, 0);
    for (; i < g->slots.size(); i++) {
        if (g->slots[i] == 0) {
            unsigned short mask = self->objs[g->owner]->table->at(i)->mask;
            Vec3 pos(self->objs[g->owner]->table->at(i)->pos);
            if (j != self->start) {
                do {
                    int type = self->objs[j]->type;
                    unsigned short *u = self->used; unsigned short n = u[type]; u = 0; if (n <= 15) {
                        if (self->have[type] >= need_8038c588[type] + adjust_800f6c54(self, self->objs[j])) {
                            Table *t = self->objs[j]->table;
                            int n = t->count;
                            Item **items = t->items;
                            for (; k < n; k++) {
                                if (items[k]->flags & mask) {
                                    if (mask_test_800f58dc(mask)) {
                                        Vec3 a(items[k]->pos), b(pos);
                                        if (!all_ge_800f5894(&a, &b)) continue;
                                        if (place_test_800f68bc(self, g, i, j, k) != 0) {
                                            if (tries++ > 40) return 0;
                                            continue;
                                        }
                                        *pb = j;
                                        *pa = i;
                                        *pc = k;
                                        return 1;
                                    } else {
                                        Vec3 a(pos), c(items[k]->pos);
                                        if (!all_ge_800f5894(&a, &c)) continue;
                                        if (place_test_800f68bc(self, g, i, j, k) != 0) {
                                            if (tries++ > 40) return 0;
                                            continue;
                                        }
                                        *pb = j;
                                        *pa = i;
                                        *pc = k;
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                    j++;
                    k = 0;
                    if (j >= self->nobjs) j = 0;
                } while (j != self->start);
            }
        }
        j = 0;
        k = 0;
    }
    return 0;
}
