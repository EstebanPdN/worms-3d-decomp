#include "w3d_ptr.h"
#line 1 "s2_retreat_states_r2.cpp"
/* Retreat and surrender state transitions. */
extern "C" {
struct S2Virtual { Ptr32<Ptr32<void>> vtable; };
inline void s2_replace(Ptr32<S2Virtual> &slot, Ptr32<S2Virtual> replacement) {
    if (replacement) ((Ptr32<void (Ptr32<S2Virtual>)>)replacement->vtable[3])(replacement);
    if (slot) ((Ptr32<void (Ptr32<S2Virtual>)>)slot->vtable[4])(slot);
    slot = replacement;
}
struct S2Retreat { Ptr32<void> vtable; unsigned char pad04[60]; Ptr32<S2Virtual> actor; int state; unsigned int elapsed; };
struct S2Surrender { Ptr32<Ptr32<void>> vtable; unsigned char pad04[44]; int pending; unsigned char pad34[12]; int launched; Ptr32<S2Virtual> token; unsigned int stamp; };
struct S2Message { unsigned short id, reserved; Ptr32<void> vtable; };
struct S2Key { Ptr32<const char> text; };
struct S2Reference { int value, tag; };
struct S2Context { unsigned char pad00[52]; unsigned int stamp; };
struct S2Type { unsigned char pad00[20]; Ptr32<S2Type> parent;
    int matches(Ptr32<S2Type> target) {
        Ptr32<S2Type> type = this;
        while (type != target) {
            Ptr32<S2Type> next = type->parent;
            if (type == next) return 0;
            type = next;
        }
        return 1;
    }
};
int w3d_fn_8002a914(Ptr32<void>);
void w3d_fn_8002a978(Ptr32<void>, int);
void w3d_fn_8002ae70(Ptr32<void>);
void w3d_fn_8002addc(Ptr32<void>);
void w3d_fn_8002af78(Ptr32<void>);
int w3d_scene_timer_is_one_8006e71c();
int w3d_fn_800fc3b0(Ptr32<S2Key>, int);
void w3d_constructor_lookup_name(Ptr32<S2Key>, Ptr32<Ptr32<S2Virtual>>);
Ptr32<void> w3d_empty_803426b4(Ptr32<void>);
Ptr32<void> w3d_auto_80178c48(Ptr32<void>);
Ptr32<unsigned char> w3d_fn_800fc710(int, Ptr32<S2Reference>);
void w3d_fn_80178474(Ptr32<S2Reference>, int);
Ptr32<void> w3d_fn_801613f0(Ptr32<void>, int);
int w3d_cached_message_id(Ptr32<void>, int);
int w3d_message_post_current(Ptr32<void>);
int w3d_auto_800fcea0();
Ptr32<S2Context> w3d_engine_get_context();
int w3d_fn_80022e20(Ptr32<const char>, Ptr32<const char>, int, Ptr32<Ptr32<S2Virtual>>);
extern unsigned char w3d_obj_804107f8[], w3d_obj_80410850[], w3d_obj_8040db38[];
extern unsigned int w3d_obj_804af2b8, w3d_obj_804af2bc, w3d_obj_804af2c0, w3d_obj_804af2c8, w3d_obj_804af2d0, w3d_obj_804af2d8, w3d_obj_804af2e0, w3d_obj_804af2e8, w3d_obj_804af2f0, w3d_obj_804af2f8, w3d_obj_804af300;
extern Ptr32<void> w3d_obj_804b1754;
extern const char w3d_str_80399f90[], w3d_str_80399f9c[], w3d_str_80399ff4[], w3d_str_8039a000[], w3d_str_8039a014[];
extern const float w3d_f32_80399ff0[];
extern unsigned char w3d_type_80361860[], w3d_type_803618f0[];


Ptr32<S2Retreat> w3d_retreat_construct_8010dadc(Ptr32<S2Retreat> self)
{
    struct { unsigned int first, second; } scratch;
    w3d_fn_8002a914(self);
    self->actor = 0;
    self->vtable = w3d_obj_804107f8;
    self->state = 0;
    return self;
}


void w3d_retreat_destroy_8010db24(Ptr32<S2Retreat> self, int flags)
{
    self->vtable = w3d_obj_804107f8;
    if (self->actor) ((Ptr32<void (Ptr32<S2Virtual>)>)self->actor->vtable[4])(self->actor);
    w3d_fn_8002a978(self, flags);
}


int w3d_retreat_tick_8010dc0c(Ptr32<S2Retreat> self, unsigned int now)
{
    if (!w3d_scene_timer_is_one_8006e71c()) {
        if (!w3d_obj_804af2bc) {
            w3d_obj_804af2b8 = now;
            w3d_obj_804af2bc = 1;
        }
        unsigned int delta = now - w3d_obj_804af2b8;
        w3d_obj_804af2b8 = now;
        switch (self->state) {
        case 1:
            self->elapsed += delta;
            if (self->elapsed > 1999) self->state = 2;
            break;
        case 2:
            S2Reference reference;
            reference.value = 0;
            reference.tag = 0xe3a8;Ptr32<unsigned char> actor = w3d_fn_800fc710((int)w3d::H((w3d_auto_80178c48((Ptr32<void>)w3d_empty_803426b4(self->actor)))), &reference);
            *(Ptr32<unsigned short>)(actor + 170) = 0;
            w3d_fn_8002ae70(self);
            self->state = 0;
            w3d_fn_80178474(&reference, 2);
            break;
        }
    }
    return 20;
}


#if 0 /* 3 attempts; property-key address setup differs */
void w3d_retreat_reset_8010dce8(S2Retreat *self)
{
    struct { S2Key time, actor; } local;
    local.time.text = w3d_str_80399f90;
    w3d_fn_800fc3b0(&local.time, 0);
    local.actor.text = w3d_str_80399f9c;
    w3d_constructor_lookup_name(&local.actor, &self->actor);
}
#endif


void w3d_retreat_launch_8010dd44(Ptr32<S2Retreat> self)
{
    if (!self->state) {
        Ptr32<S2Message> message = (Ptr32<S2Message>)w3d_fn_801613f0(w3d_obj_804b1754, 8);
        message->id = w3d_cached_message_id(&w3d_obj_804af2c0, 1);
        message->vtable = w3d_obj_8040db38;
        w3d_message_post_current(message);
        self->elapsed = 0;
        self->state = 1;
        w3d_fn_8002addc(self);
    }
}


Ptr32<S2Surrender> w3d_surrender_construct_8010df80(Ptr32<S2Surrender> self)
{
    struct { unsigned int first, second; } scratch;
    w3d_fn_8002a914(self);
    self->token = 0;
    self->vtable = (Ptr32<Ptr32<void>>)w3d_obj_80410850;
    self->launched = 0;
    return self;
}


void w3d_surrender_destroy_8010dfc8(Ptr32<S2Surrender> self, int flags)
{
    self->vtable = (Ptr32<Ptr32<void>>)w3d_obj_80410850;
    if (self->token) ((Ptr32<void (Ptr32<S2Virtual>)>)self->token->vtable[4])(self->token);
    w3d_fn_8002a978(self, flags);
}


int w3d_surrender_tick_8010e0b0(Ptr32<S2Surrender> self, unsigned int now)
{
    if (!w3d_scene_timer_is_one_8006e71c() && self->launched && (float)now > (float)self->stamp + w3d_f32_80399ff0[0]) {
        Ptr32<S2Message> message_804af2c8 = (Ptr32<S2Message>)w3d_fn_801613f0(w3d_obj_804b1754, 8);
        message_804af2c8->id = w3d_cached_message_id(&w3d_obj_804af2c8, 1);
        message_804af2c8->vtable = w3d_obj_8040db38;
        w3d_message_post_current(message_804af2c8);
        Ptr32<S2Message> message_804af300 = (Ptr32<S2Message>)w3d_fn_801613f0(w3d_obj_804b1754, 8);
        message_804af300->id = w3d_cached_message_id(&w3d_obj_804af300, 1);
        message_804af300->vtable = w3d_obj_8040db38;
        w3d_message_post_current(message_804af300);
        if (!w3d_auto_800fcea0()) {
        Ptr32<S2Message> message_804af2f8 = (Ptr32<S2Message>)w3d_fn_801613f0(w3d_obj_804b1754, 8);
        message_804af2f8->id = w3d_cached_message_id(&w3d_obj_804af2f8, 1);
        message_804af2f8->vtable = w3d_obj_8040db38;
        w3d_message_post_current(message_804af2f8);
        }
        Ptr32<S2Message> message_804af2d0 = (Ptr32<S2Message>)w3d_fn_801613f0(w3d_obj_804b1754, 8);
        message_804af2d0->id = w3d_cached_message_id(&w3d_obj_804af2d0, 1);
        message_804af2d0->vtable = w3d_obj_8040db38;
        w3d_message_post_current(message_804af2d0);
        if (self->token) ((Ptr32<void (Ptr32<S2Virtual>)>)self->token->vtable[4])(self->token);
        self->token = 0;
    }
    return 20;
}


void w3d_surrender_reset_8010e22c(Ptr32<S2Surrender> self)
{
    struct { S2Key time; int reserved; } local;
    local.time.text = w3d_str_80399ff4;
    w3d_fn_800fc3b0(&local.time, 0);
    s2_replace(self->token, 0);
    self->stamp = 0;
}


void w3d_surrender_launch_8010e298(Ptr32<S2Surrender> self)
{
    if (!self->launched) {
        self->launched = 1;
        w3d_fn_8002af78(self);
        Ptr32<S2Message> message_804af2d8 = (Ptr32<S2Message>)w3d_fn_801613f0(w3d_obj_804b1754, 8);
        message_804af2d8->id = w3d_cached_message_id(&w3d_obj_804af2d8, 1);
        message_804af2d8->vtable = w3d_obj_8040db38;
        w3d_message_post_current(message_804af2d8);
        self->stamp = w3d_engine_get_context()->stamp;
        if (((Ptr32<Ptr32<S2Type> (Ptr32<S2Surrender>)>)self->vtable[5])(self)->matches((Ptr32<S2Type>)w3d_type_80361860) ||
            ((Ptr32<Ptr32<S2Type> (Ptr32<S2Surrender>)>)self->vtable[5])(self)->matches((Ptr32<S2Type>)w3d_type_803618f0))
            w3d_fn_80022e20(w3d_str_8039a000, w3d_str_8039a014, 131, &self->token);
        self->pending = 0;
        Ptr32<S2Message> message_804af2e0 = (Ptr32<S2Message>)w3d_fn_801613f0(w3d_obj_804b1754, 8);
        message_804af2e0->id = w3d_cached_message_id(&w3d_obj_804af2e0, 1);
        message_804af2e0->vtable = w3d_obj_8040db38;
        w3d_message_post_current(message_804af2e0);
        Ptr32<S2Message> message_804af2f0 = (Ptr32<S2Message>)w3d_fn_801613f0(w3d_obj_804b1754, 8);
        message_804af2f0->id = w3d_cached_message_id(&w3d_obj_804af2f0, 1);
        message_804af2f0->vtable = w3d_obj_8040db38;
        w3d_message_post_current(message_804af2f0);
        Ptr32<S2Message> message_804af2e8 = (Ptr32<S2Message>)w3d_fn_801613f0(w3d_obj_804b1754, 8);
        message_804af2e8->id = w3d_cached_message_id(&w3d_obj_804af2e8, 1);
        message_804af2e8->vtable = w3d_obj_8040db38;
        w3d_message_post_current(message_804af2e8);
    }
}

}


