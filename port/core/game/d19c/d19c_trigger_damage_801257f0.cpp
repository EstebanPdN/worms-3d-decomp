#include "w3d_ptr.h"
#line 1 "d19c_trigger_damage_801257f0.cpp"
// d19c: 0x801257f0 (324 bytes). Damage a trigger: unless the trigger accepts
// any team (+52 == -1), only damage from the team owning it counts (team byte
// +213 of the record selected by the id read from +108). Subtract the damage,
// truncated to an integer, from the hit points (+48). At zero or below, mark
// it destroyed (+80), write "Trigger.Index", post the destroyed message and
// remove the trigger; otherwise write "Trigger.Index" and "Trigger.HitPoints"
// and post the damaged message. Messages are 8-byte arena records holding the
// cached message id and a shared payload. Meanings are inferred.
// Built with -mps-float: the damage stays in f31 across calls and the
// unflagged build differed only by the 8-byte frame gap below the register
// save area. The keys are external: "Trigger.Radius" from another function
// lies between them in the original string pool.
struct d19c_TeamRecord {
    unsigned char unknown00[213];
    unsigned char team;                  // +213
};
struct d19c_Trigger {
    unsigned char unknown00[44];
    int index;                           // +44
    int hit_points;                      // +48
    int team;                            // +52 (-1: any team)
    unsigned char unknown56[24];
    int destroyed;                       // +80
    unsigned char unknown84[24];
    Ptr32<void> owner_id_source;               // +108
};
struct d19c_Message {
    unsigned short id;
    Ptr32<const void> payload;
};
extern "C" unsigned d19c_read_id_80178c48(Ptr32<void>);
extern "C" Ptr32<d19c_TeamRecord> d19c_team_record_800fc6dc(unsigned);
extern "C" int d19c_property_write_800fc3b0(Ptr32<Ptr32<const char>>, int);
extern "C" Ptr32<d19c_Message> d19c_arena_alloc_801613f0(Ptr32<void>, unsigned);
extern "C" unsigned short d19c_cached_message_id_8015f5a0(Ptr32<void>, int);
extern "C" int d19c_message_post_8016239c(Ptr32<d19c_Message>);
extern "C" void d19c_trigger_destroy_8015fd1c(Ptr32<d19c_Trigger>);
extern const char d19c_trigger_index_key_8039b944[];       // "Trigger.Index"
extern const char d19c_trigger_hit_points_key_8039b964[];  // "Trigger.HitPoints"
extern Ptr32<void> d19c_message_arena_804b1754;
extern unsigned d19c_trigger_destroyed_message_804af564;
extern unsigned d19c_trigger_damaged_message_804af55c;
extern const unsigned char d19c_message_payload_8040db38[];

extern "C" void d19c_trigger_damage_801257f0(Ptr32<d19c_Trigger> self, float damage) {
    if (self->team != -1 && d19c_team_record_800fc6dc(d19c_read_id_80178c48(self->owner_id_source))->team != self->team)
        return;
    self->hit_points -= (int)damage;
    if (self->hit_points <= 0) {
        self->destroyed = 1;
        Ptr32<const char> key = d19c_trigger_index_key_8039b944;
        d19c_property_write_800fc3b0(&key, self->index);
        Ptr32<d19c_Message> message = d19c_arena_alloc_801613f0(d19c_message_arena_804b1754, 8);
        message->id = d19c_cached_message_id_8015f5a0(&d19c_trigger_destroyed_message_804af564, 1);
        message->payload = d19c_message_payload_8040db38;
        d19c_message_post_8016239c(message);
        d19c_trigger_destroy_8015fd1c(self);
    } else {
        Ptr32<const char> index_key = d19c_trigger_index_key_8039b944;
        d19c_property_write_800fc3b0(&index_key, self->index);
        Ptr32<const char> hit_points_key = d19c_trigger_hit_points_key_8039b964;
        d19c_property_write_800fc3b0(&hit_points_key, self->hit_points);
        Ptr32<d19c_Message> message = d19c_arena_alloc_801613f0(d19c_message_arena_804b1754, 8);
        message->id = d19c_cached_message_id_8015f5a0(&d19c_trigger_damaged_message_804af55c, 1);
        message->payload = d19c_message_payload_8040db38;
        d19c_message_post_8016239c(message);
    }
}


