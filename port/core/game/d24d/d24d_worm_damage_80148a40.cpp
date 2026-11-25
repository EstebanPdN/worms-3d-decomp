#include "w3d_ptr.h"
#line 1 "d24d_worm_damage_80148a40.cpp"
// d24d: 0x80148a40 (468 bytes). Apply a health change to a worm actor: skipped when
// +652 is set or the actor is in mode four. A positive amount on an actor with
// active links clears them. If the worm's state (+220) is nonzero: unless the
// stats object (+1252) reports +60 set, adds the amount to the worm's health
// (+164, through the handle record 0x800fc710) and posts the alliance update.
// A positive amount records the attacker from display +1124 in the 16-slot hit
// list (+1280, ends at -1) unless it is the worm itself, then posts a message
// with the worm id, and a second one if the owner matches. Finally runs the special
// action 0x80148ef0 when flagged. Message init returns the message, which is passed
// straight to the post call. Handle key 0xe3a8, out-of-line destructor 0x80178474.
struct d24d_Handle { int value; unsigned key; d24d_Handle() { value = 0; key = 58280; } ~d24d_Handle(); };
struct d24d_WormInfo { char pad[164]; int health; char pad2[52]; int state; };
struct d24d_Message { unsigned short id; Ptr32<void> data; };
struct d24d_WormActor;
extern "C" int d24d_mode_is_four_80153f38(Ptr32<d24d_WormActor>);
extern "C" int d24d_has_active_801510c4(Ptr32<d24d_WormActor>);
extern "C" void d24d_clear_links_8014df84(Ptr32<d24d_WormActor>, int);
extern "C" Ptr32<d24d_WormInfo> d24d_worm_info_800fc6dc(int);
struct d24d_Stats { char pad[60]; int locked; };
extern "C" Ptr32<d24d_Stats> d24d_stats_view_801797b4(Ptr32<void>);
extern "C" Ptr32<d24d_WormInfo> d24d_worm_handle_800fc710(int, const d24d_Handle &);
extern "C" void d24d_post_alliance_801533a4(Ptr32<d24d_WormActor>, int);
extern "C" Ptr32<void> d24d_display_803426b4(Ptr32<void>);
extern "C" int d24d_display_value_80178c48(Ptr32<void>);
extern Ptr32<void> d24d_arena_804b1754;
extern int d24d_hit_key_804afb60, d24d_owner_key_804afb68;
extern "C" Ptr32<void> d24d_arena_alloc_801613f0(Ptr32<void>, int);
extern "C" unsigned d24d_message_id_8015f5a0(Ptr32<int>, int);
extern "C" Ptr32<void> d24d_message_init_800a82f0(Ptr32<void>, unsigned short, int);
extern "C" int d24d_message_post_8016239c(Ptr32<void>);
extern "C" int d24d_owner_matches_8014c488(Ptr32<d24d_WormActor>);
extern "C" int d24d_special_flag_8014e9b4(Ptr32<d24d_WormActor>);
extern "C" void d24d_special_action_80148ef0(Ptr32<d24d_WormActor>);
extern char d24d_message_vtable_8040db38[];
struct d24d_WormActor { char pad[584]; int worm; char pad1[64]; int f652; char pad2[468]; Ptr32<void> attacker; char pad3[124]; Ptr32<void> stats; char pad4[24]; int hits[16]; };
extern "C" void d24d_worm_damage_80148a40(Ptr32<d24d_WormActor> self, int amount) {
    if (self->f652 != 0 || d24d_mode_is_four_80153f38(self)) return;
    if (d24d_has_active_801510c4(self) && amount > 0) d24d_clear_links_8014df84(self, 1);
    if (d24d_worm_info_800fc6dc(self->worm)->state == 0) return;
    if (d24d_stats_view_801797b4(self->stats)->locked == 0) {
        d24d_Handle h;
        Ptr32<d24d_WormInfo> w = d24d_worm_handle_800fc710(self->worm, h);
        w->health += amount;
        d24d_post_alliance_801533a4(self, amount);
    }
    if (amount > 0) {
        int who = d24d_display_value_80178c48(d24d_display_803426b4(self->attacker));
        if (who != self->worm) {
            for (int i = 0; i <= 15; i++) {
                if (self->hits[i] == who) break;
                if (self->hits[i] == -1) { self->hits[i] = who; break; }
            }
        }
        Ptr32<void> m = d24d_arena_alloc_801613f0(d24d_arena_804b1754, 12);
        d24d_message_post_8016239c(d24d_message_init_800a82f0(m, d24d_message_id_8015f5a0(&d24d_hit_key_804afb60, 1), self->worm));
        if (d24d_owner_matches_8014c488(self)) {
            Ptr32<d24d_Message> n = (Ptr32<d24d_Message>)d24d_arena_alloc_801613f0(d24d_arena_804b1754, 8);
            n->id = d24d_message_id_8015f5a0(&d24d_owner_key_804afb68, 1);
            n->data = d24d_message_vtable_8040db38;
            d24d_message_post_8016239c(n);
        }
    }
    if (d24d_special_flag_8014e9b4(self)) d24d_special_action_80148ef0(self);
}


