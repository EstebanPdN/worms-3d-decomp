// GWMP8P rev0 0x800f5148. Grows the world by one random placement: collects
// candidate placements per layer type, draws a type weighted by the type
// budgets, then creates and links a mesh layer.
extern "C" void *memcpy(...);
extern "C" void *alloc_80212fd4(unsigned);
extern "C" void release_802134fc(void *);
template <class T> inline const T &maximum(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &minimum(const T &a, const T &b) { return b < a ? b : a; }
struct Layer { char u0[60]; int type; };
struct Holder { char u0[32]; Layer *layer; };
struct Entry { unsigned char u0, group, obj, item, slot; };
struct Words {
    Holder **start, **finish, **eos;
    unsigned size() const { return finish - start; }
    Holder *&operator[](int i) { return start[i]; }
    void push_back(Holder *const &x) {
        if (finish == eos) {
            unsigned used = (char *)finish - (char *)start;
            int a = used + 1;
            int b = used + (used >> 1);
            unsigned bytes = maximum(a, b) << 2;
            Holder **p = (Holder **)alloc_80212fd4(bytes);
            if (start) {
                memcpy(p, start, minimum(bytes, used));
                release_802134fc(start);
            }
            start = p;
            finish = (Holder **)((char *)p + used);
            eos = (Holder **)((char *)p + bytes);
        }
        *finish = x;
        finish++;
    }
};
struct World {
    char u0[40]; unsigned start; Words groups; char u56[24]; Layer **objs; unsigned nobjs;
    char u88[900]; int have[23]; char u1080[92]; Entry entries[23][16];
    unsigned short used[23]; char u3058[9]; unsigned char flag3067; char u3068[112]; unsigned heat;
};
extern int need_8038c588[];
extern int rare_8038c5e4[];
extern "C" unsigned rand_800f2cec(World *);
extern "C" int adjust_800f6c54(World *, Layer *);
extern "C" int find_800f58f0(World *, Holder *, int *, int *, int *, int);
extern "C" Holder *layer_800f55e8(World *, int, int);
extern "C" void place_800f5c1c(World *, Holder *, int, Holder *, int);
extern "C" int w3d_d45a_world_grow_group_800f5148(World *self) {
    int count = 0;
    for (unsigned i = 0; i < 23; i++) self->used[i] = 0;
    unsigned tries = 0;
    unsigned n = self->groups.size();
    unsigned g = rand_800f2cec(self) % n;
    Entry e;
    int j, k, l;
    for (unsigned t = 0; t < n && tries < 40; t++) {
        if (self->heat <= 4 || !rare_8038c5e4[self->groups[g]->layer->type]) {
            tries++;
            unsigned r = rand_800f2cec(self);
            self->start = r % self->nobjs;
            j = (self->start + 1) % self->nobjs;
            k = -1;
            l = -1;
            while (find_800f58f0(self, self->groups[g], &j, &k, &l, self->flag3067)) {
                tries = 0;
                count++;
                int type = self->objs[j]->type;
                e.slot = l;
                e.item = k;
                e.obj = j;
                e.group = g;
                self->entries[type][self->used[type]] = e;
                l = -1;
                self->used[type]++;
                j = (j + 1) % self->nobjs;
            }
            if ((unsigned)count > 15) break;
        }
        g = (g + 1) % n;
    }
    if (count > 0) {
    if (self->used[18]) self->used[12] = 0;
    if (self->used[19]) self->used[13] = 0;
    if (self->used[20]) self->used[14] = 0;
    int total = 0;
    for (unsigned i = 0; i < 23; i++) if (self->used[i]) total += self->have[i];
    Holder *result = 0;
    g = 0;
    total = rand_800f2cec(self) % total + 1;
    if (total > 0) { do { if (self->used[g]) total -= self->have[g]; if (total > 0) g++; else break; } while (1); }
    total = g;
    unsigned idx = rand_800f2cec(self) % self->used[total];
    self->have[total] -= need_8038c588[total] + adjust_800f6c54(self, self->objs[self->entries[total][idx].obj]);
    result = layer_800f55e8(self, self->entries[total][idx].obj, 1);
    place_800f5c1c(self, self->groups[self->entries[total][idx].group], self->entries[total][idx].item, result, self->entries[total][idx].slot);
    if (rare_8038c5e4[total]) {
        self->heat++;
    } else {
        self->heat--;
        if (self->heat > 1000) self->heat = 0;
    }
    self->groups.push_back(result);
    return 1;
    }
    return 0;
}
