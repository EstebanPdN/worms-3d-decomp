// Network page start (Worms 3D GameCube PAL, 0x8021a9dc).
// 
// Subscribes the page to six cached message ids, loads the RoundTimeRemaining, TurnTimeRemaining and
// HotSeatTimeRemaining settings into retained interfaces, clears the shared flags and active field,
// connects or refreshes depending on the active team, schedules a timeout message 30 seconds ahead,
// clears the team fields and computes the tick period. The holder is a one-word block-mode class.

typedef unsigned short u16;
struct Interface;
struct InterfaceTable {
    void *reserved[3];
    int (*retain)(Interface *);
    int (*release)(Interface *);
};
struct Interface { InterfaceTable *table; };
struct Msg;
struct Holder { Interface *p; Holder() {} Holder(const Holder &); };
struct Team { char pad[28]; int w28; char pad1[48 - 32]; Interface *w48; };
struct Owner { char pad[24]; Team *team; };
struct Net { char pad0[36]; Owner *owner; char h40[4]; char h44[4]; char pad1[52 - 48]; char h52[4]; char h56[4]; char pad2[64 - 60]; char h64[4]; char pad3[72 - 68]; char h72[4];
  Interface *round; Interface *turn; Interface *hotseat; void *pool; int active; char pad4[116 - 96]; int rate; int bit; int period; };
struct Cfg { char pad[240]; unsigned p0 : 11; unsigned b : 1; unsigned p1 : 20; };
struct Flags { char p0[96]; unsigned pad0 : 9; unsigned flag : 1; unsigned pad1 : 22; };
struct Ctl { char pad[432]; int w432; };
struct Key { const char *name; };
struct Ctx { char pad[52]; int now; };
extern Flags *global_804aac54; extern Ctl *global_804aaf48; extern Cfg *global_804aaabc; extern void *global_804b1754;
extern char cache_804b076c, cache_804b0774, cache_804b071c, cache_804b0754, cache_804b075c, cache_804b0784;
extern const char text_803b3b98[], text_803b3bac[], text_803b3bc0[];
extern "C" int msgid_8015f5a0(void *, int);
extern "C" int acquire_80162024(Net *, u16 *, void *);
extern "C" int lookup_800fc1b0(Key *, Interface **);
extern "C" Interface *cast_803426b4(Interface *);
extern "C" void fn_8021cd10(Net *);
extern "C" Team *active_8021ec2c(Owner *);
extern "C" void *object_80240994(Team *);
extern "C" int get_8021ed14(void *);
extern "C" void connect_8021adb8(Net *);
extern "C" void refresh_8021ad34(Net *);
extern "C" Msg *alloc_801613f0(void *, int);
extern "C" Msg *init_80125fdc(Msg *, u16, int);
extern "C" Ctx *context_80165254(void);
extern "C" void *pooladd_800c53a0(Msg *, int);
#define SUB(c, h) { u16 id = msgid_8015f5a0(&c, 1); acquire_80162024(self, &id, self->h); }
inline void load(Interface *&field, const char *name, Interface **value, int zero) {
    *value = (Interface *)zero;
    Key k; k.name = name;
    lookup_800fc1b0(&k, value);
    Interface *n = cast_803426b4(*value);
    if (n) n->table->retain(n);
    if (field) field->table->release(field);
    field = n;
    if (*value) (*value)->table->release(*value);
}
extern "C" void w3d_d27k_net_start_8021a9dc(Net *self) {
    Holder held;
    Interface **value = &held.p;
    int zero = 0;
    SUB(cache_804b076c, h40);
    SUB(cache_804b0774, h44);
    SUB(cache_804b071c, h52);
    SUB(cache_804b0754, h56);
    SUB(cache_804b075c, h64);
    SUB(cache_804b0784, h72);
    load(self->round, text_803b3b98, value, zero);
    load(self->turn, text_803b3bac, value, zero);
    load(self->hotseat, text_803b3bc0, value, zero);
    global_804aac54->flag = zero;
    global_804aaf48->w432 = zero;
    fn_8021cd10(self);
    self->active = zero;
    if (get_8021ed14(object_80240994(active_8021ec2c(self->owner)))) connect_8021adb8(self);
    else refresh_8021ad34(self);
    int z2 = 0;
    Msg *m = alloc_801613f0(global_804b1754, 12);
    Msg *i = init_80125fdc(m, msgid_8015f5a0(&cache_804b071c, 1), 0);
    self->pool = pooladd_800c53a0(i, context_80165254()->now + 30000);
    Team *t = self->owner->team;
    Interface *old = t->w48;
    t->w48 = (Interface *)z2;
    if (old) old->table->release(old);
    int *time = &self->owner->team->w28; *time = z2;
    self->bit = global_804aaabc->b;
    self->period = 1000 / self->rate * 180;
}
