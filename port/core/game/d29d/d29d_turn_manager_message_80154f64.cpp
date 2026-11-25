#include "w3d_ptr.h"
#line 1 "d29d_turn_manager_message_80154f64.cpp"
// GWMP8P rev0 0x80154f64. Turn manager message handler. Names are read from
// the trace strings in the original. Virtual slots are reference-ABI observations.
struct Obj;
struct ObjVt { char u0[12]; Ptr32<void (Ptr32<Obj>)> retain; Ptr32<void (Ptr32<Obj>)> release; };
struct Obj { Ptr32<ObjVt> vt; };
struct Ref {
    Ptr32<Obj> p;
    template <class W3dU> Ref(Ptr32<W3dU> w3d_p) : Ref((Obj *)w3d_p.get()) {}
 Ref(Obj *o) { p = o; if (p) p->vt->retain(p); }
    Ref(const Ref &);
    ~Ref() { if (p) p->vt->release(p); }
};
struct Msg { unsigned short id; unsigned short Id() const { return id; } };
struct Plain { short id; Ptr32<void> vt; };
struct Turns { char u0[20]; int f20; char u18[356]; int f380; };
extern "C" {
int base_8016293c(Ptr32<Turns>, Ptr32<Msg>);
void setup_80156ff0(Ptr32<Turns>);
void shutdown_80156f68(Ptr32<Turns>);
int equals_8015f65c(unsigned short, Ptr32<int>);
void publish_turn_change_80155e24(Ptr32<Turns>);
Ptr32<void> alloc_801613f0(Ptr32<void>, int);
short message_id_8015f5a0(Ptr32<int>, int);
int post_8016239c(Ptr32<void>);
void trace_80154f58(Ptr32<Turns>, Ptr32<const char>);
void publish_worm_count_801555f8(Ptr32<Turns>);
void publish_team_count_80155688(Ptr32<Turns>);
void publish_alliance_count_80155b44(Ptr32<Turns>);
int get_int_800fc1f0(Ptr32<Ptr32<const char>>, Ptr32<int>);
int next_team_80155784(Ptr32<Turns>, int);
int property_write_800fc43c(Ptr32<Ptr32<const char>>, int);
void remove_active_801554dc(Ptr32<Turns>);
void remove_current_80155ba4(Ptr32<Turns>);
void select_team_801560d8(Ptr32<Turns>);
void reset_with_message_80156190(Ptr32<Turns>);
void turns_reset_80156884(Ptr32<Turns>);
int value_800a830c(Ptr32<Msg>);
void add_worm_80156b24(Ptr32<Turns>, int);
void publish_team_worm_count_80155574(Ptr32<Turns>, int);
void turn_notify_80157490(Ptr32<Turns>);
void select_near_80158850(Ptr32<Turns>, Ptr32<Msg>);
void record_position_8015896c(Ptr32<Turns>, Ptr32<Msg>);
void select_enemy_80158bb0(Ptr32<Turns>, Ptr32<Msg>);
void select_opponent_801589c8(Ptr32<Turns>);
void advance_80155ff0(Ptr32<Turns>);
int retain_movement_80158af0(Ptr32<Turns>);
int release_movement_80158b4c(Ptr32<Turns>);
Ptr32<Obj> create_8020b680(Ptr32<void>);
int send_80164514(Ptr32<void>, Ptr32<Obj>, int);
void create_actor_80156ac4(Ptr32<Turns>, int);
}
extern Ptr32<void> heap_804b1754;
extern Ptr32<void> service_804b178c;
extern char desc_80410940[];
extern unsigned char vt_8040db38[];
extern const char str_803a2860[];
extern const char str_803a2880[];
extern const char str_803a2894[];
extern const char str_803a28b8[];
extern const char str_803a27f0[];
extern const char str_803a28e0[];
extern const char str_803a28fc[];
extern const char str_803a2918[];
extern const char str_803a2930[];
extern const char str_803a2950[];
extern const char str_803a2968[];
extern const char str_803a2984[];
extern const char str_803a299c[];
extern const char str_803a29a8[];
extern int cache_804afe48;
extern int cache_804afe40;
extern int cache_804afe58;
extern int cache_804afe60;
extern int cache_804aff70;
extern int cache_804aff68;
extern int cache_804afeb0;
extern int cache_804afef8;
extern int cache_804afe68;
extern int cache_804aff00;
extern int cache_804afea8;
extern int cache_804afe78;
extern int cache_804afe80;
extern int cache_804afec0;
extern int cache_804afed0;
extern int cache_804aff38;
extern int cache_804afee0;
extern int cache_804afea0;
extern int cache_804afe98;
extern int cache_804aff10;
extern int cache_804aff18;
extern int cache_804aff78;
extern int cache_804aff80;
extern int cache_804aff28;
extern int cache_804aff30;
extern int cache_804aff40;
inline void post_plain(Ptr32<int> cache) {
    Ptr32<Plain> p = (Ptr32<Plain>)alloc_801613f0(heap_804b1754, 8);
    p->id = message_id_8015f5a0(cache, 1);
    p->vt = vt_8040db38;
    post_8016239c(p);
}
extern "C" int d29d_turn_manager_message_80154f64(Ptr32<Turns> self, Ptr32<Msg> m) {
    unsigned short id = m->Id();
    switch (m->Id()) {
    case 64:
        if (base_8016293c(self, m) >= 0) { setup_80156ff0(self); goto zero; }
        return 0x80004005;
    case 66:
        shutdown_80156f68(self);
        goto base;
    }
    if (equals_8015f65c(id, &cache_804afe40)) {
        publish_turn_change_80155e24(self);
        post_plain(&cache_804afe48);
        self->f380 = 0;
        trace_80154f58(self, str_803a2860);
        goto zero;
    }
    if (equals_8015f65c(id, &cache_804afe58)) {
        publish_worm_count_801555f8(self);
        trace_80154f58(self, str_803a2880);
        goto zero;
    }
    if (equals_8015f65c(id, &cache_804afe60)) {
        publish_team_count_80155688(self);
        trace_80154f58(self, str_803a2894);
        goto zero;
    }
    if (equals_8015f65c(id, &cache_804aff70)) {
        publish_alliance_count_80155b44(self);
        trace_80154f58(self, str_803a28b8);
        goto zero;
    }
    if (equals_8015f65c(id, &cache_804aff68)) {
        Ptr32<const char> cur = str_803a27f0;
        int index;
        get_int_800fc1f0(&cur, &index);
        int next = next_team_80155784(self, index);
        Ptr32<const char> had = str_803a28e0;
        property_write_800fc43c(&had, next <= index);
    }
    if (equals_8015f65c(id, &cache_804afeb0)) {
        remove_active_801554dc(self);
        trace_80154f58(self, str_803a28fc);
        goto zero;
    }
    if (equals_8015f65c(id, &cache_804afef8)) {
        remove_current_80155ba4(self);
        publish_team_count_80155688(self);
        select_team_801560d8(self);
        trace_80154f58(self, str_803a2918);
        goto zero;
    }
    if (equals_8015f65c(id, &cache_804afe68)) {
        reset_with_message_80156190(self);
        turns_reset_80156884(self);
        trace_80154f58(self, str_803a2930);
        goto zero;
    }
    if (equals_8015f65c(id, &cache_804aff00)) {
        add_worm_80156b24(self, value_800a830c(m));
        trace_80154f58(self, str_803a2950);
        goto zero;
    }
    if (equals_8015f65c(id, &cache_804afea8)) {
        publish_team_worm_count_80155574(self, value_800a830c(m));
        trace_80154f58(self, str_803a2968);
    }
    if (equals_8015f65c(id, &cache_804afe78)) {
        select_team_801560d8(self);
        trace_80154f58(self, str_803a2984);
        goto zero;
    }
    if (equals_8015f65c(id, &cache_804afe80)) {
        turn_notify_80157490(self);
        goto zero;
    }
    if (equals_8015f65c(id, &cache_804afec0)) {
        select_near_80158850(self, m);
        goto zero;
    }
    if (equals_8015f65c(id, &cache_804afed0)) {
        record_position_8015896c(self, m);
        goto zero;
    }
    if (equals_8015f65c(id, &cache_804aff38)) {
        select_enemy_80158bb0(self, m);
        goto base;
    }
    if (equals_8015f65c(id, &cache_804afee0)) {
        select_opponent_801589c8(self);
        goto zero;
    }
    if (equals_8015f65c(id, &cache_804afe98)) {
        advance_80155ff0(self);
        trace_80154f58(self, str_803a299c);
        post_plain(&cache_804afea0);
        goto base;
    }
    if (equals_8015f65c(id, &cache_804aff10)) {
        retain_movement_80158af0(self);
        goto base;
    }
    if (equals_8015f65c(id, &cache_804aff18)) {
        release_movement_80158b4c(self);
        goto base;
    }
    if (equals_8015f65c(id, &cache_804aff78)) {
        retain_movement_80158af0(self);
        goto base;
    }
    if (equals_8015f65c(id, &cache_804aff80)) {
        release_movement_80158b4c(self);
        goto base;
    }
    if (equals_8015f65c(id, &cache_804aff28)) {
        Ref r(create_8020b680(desc_80410940));
        send_80164514(service_804b178c, r.p, self->f20);
        goto base;
    }
    if (equals_8015f65c(id, &cache_804aff30)) {
        create_actor_80156ac4(self, value_800a830c(m));
        trace_80154f58(self, str_803a29a8);
        goto base;
    }
    if (equals_8015f65c(id, &cache_804aff40)) {
        self->f380 = 1;
    }
base:
    return base_8016293c(self, m);
zero:
    return 0;
}


