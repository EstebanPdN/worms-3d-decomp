#include "w3d_ptr.h"
#line 1 "d27k_net_start_8021a9dc.cpp"
// Network page start (Worms 3D GameCube PAL, 0x8021a9dc).
// 
// Subscribes the page to six cached message ids, loads the RoundTimeRemaining, TurnTimeRemaining and
// HotSeatTimeRemaining settings into retained interfaces, clears the shared flags and active field,
// connects or refreshes depending on the active team, schedules a timeout message 30 seconds ahead,
// clears the team fields and computes the tick period. The holder is a one-word block-mode class.

typedef unsigned short u16;
struct Interface;
struct InterfaceTable {
    Ptr32<void> reserved[3];
    Ptr32<int (Ptr32<Interface>)> retain;
    Ptr32<int (Ptr32<Interface>)> release;
};
struct Interface { Ptr32<InterfaceTable> table; };
struct Msg;
struct Holder { Ptr32<Interface> p; Holder() {} Holder(const Holder &); };
struct Team { char pad[28]; int w28; char pad1[48 - 32]; Ptr32<Interface> w48; };
struct Owner { char pad[24]; Ptr32<Team> team; };
struct Net { char pad0[36]; Ptr32<Owner> owner; char h40[4]; char h44[4]; char pad1[52 - 48]; char h52[4]; char h56[4]; char pad2[64 - 60]; char h64[4]; char pad3[72 - 68]; char h72[4];
  Ptr32<Interface> round; Ptr32<Interface> turn; Ptr32<Interface> hotseat; Ptr32<void> pool; int active; char pad4[116 - 96]; int rate; int bit; int period; };
struct Cfg { char pad[240]; unsigned int p1:20; unsigned int b:1; unsigned int p0:11; };
struct Flags { char p0[96]; unsigned int pad1:22; unsigned int flag:1; unsigned int pad0:9; };
struct Ctl { char pad[432]; int w432; };
struct Key { Ptr32<const char> name; };
struct Ctx { char pad[52]; int now; };
extern Ptr32<Flags> global_804aac54; extern Ptr32<Ctl> global_804aaf48; extern Ptr32<Cfg> global_804aaabc; extern Ptr32<void> global_804b1754;
extern char cache_804b076c, cache_804b0774, cache_804b071c, cache_804b0754, cache_804b075c, cache_804b0784;
extern const char text_803b3b98[], text_803b3bac[], text_803b3bc0[];
extern "C" int msgid_8015f5a0(Ptr32<void>, int);
extern "C" int acquire_80162024(Ptr32<Net>, Ptr32<u16>, Ptr32<void>);
extern "C" int lookup_800fc1b0(Ptr32<Key>, Ptr32<Ptr32<Interface>>);
extern "C" Ptr32<Interface> cast_803426b4(Ptr32<Interface>);
extern "C" void fn_8021cd10(Ptr32<Net>);
extern "C" Ptr32<Team> active_8021ec2c(Ptr32<Owner>);
extern "C" Ptr32<void> object_80240994(Ptr32<Team>);
extern "C" int get_8021ed14(Ptr32<void>);
extern "C" void connect_8021adb8(Ptr32<Net>);
extern "C" void refresh_8021ad34(Ptr32<Net>);
extern "C" Ptr32<Msg> alloc_801613f0(Ptr32<void>, int);
extern "C" Ptr32<Msg> init_80125fdc(Ptr32<Msg>, u16, int);
extern "C" Ptr32<Ctx> context_80165254(void);
extern "C" Ptr32<void> pooladd_800c53a0(Ptr32<Msg>, int);
#define SUB(c, h) { u16 id = msgid_8015f5a0(&c, 1); acquire_80162024(self, &id, self->h); }
inline void load(Ptr32<Interface> &field, Ptr32<const char> name, Ptr32<Ptr32<Interface>> value, int zero) {
    *value = (Ptr32<Interface>)w3d::G(zero);
    Key k; k.name = name;
    lookup_800fc1b0(&k, value);
    Ptr32<Interface> n = cast_803426b4(*value);
    if (n) n->table->retain(n);
    if (field) field->table->release(field);
    field = n;
    if (*value) (*value)->table->release(*value);
}
extern "C" void w3d_d27k_net_start_8021a9dc(Ptr32<Net> self) {
    Holder held;
    Ptr32<Ptr32<Interface>> value = &held.p;
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
    Ptr32<Msg> m = alloc_801613f0(global_804b1754, 12);
    Ptr32<Msg> i = init_80125fdc(m, msgid_8015f5a0(&cache_804b071c, 1), 0);
    self->pool = pooladd_800c53a0(i, context_80165254()->now + 30000);
    Ptr32<Team> t = self->owner->team;
    Ptr32<Interface> old = t->w48;
    t->w48 = (Ptr32<Interface>)w3d::G(z2);
    if (old) old->table->release(old);
    Ptr32<int> time = &self->owner->team->w28; *time = z2;
    self->bit = global_804aaabc->b;
    self->period = 1000 / self->rate * 180;
}


