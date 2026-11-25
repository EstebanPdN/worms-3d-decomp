#include "w3d_ptr.h"
#line 1 "s2_teleport_state_r2.cpp"
/* Teleport weapon state lifecycle and message dispatch. */
extern "C" {
struct S2WeaponObject { Ptr32<Ptr32<void>> vtable; };
struct S2Weapon { Ptr32<Ptr32<void>> vtable; unsigned char pad04[16]; int id; unsigned char pad18[4]; Ptr32<S2WeaponObject> deleteSubscription; Ptr32<S2WeaponObject> fireSubscription; int fired; Ptr32<S2WeaponObject> payload; Ptr32<S2WeaponObject> worm; };
struct S2WormState { unsigned char pad00[260]; int remote; };
struct S2WeaponMessage { unsigned short id, reserved; Ptr32<void> vtable; int value; };
struct S2WeaponKey { Ptr32<const char> text; };
struct S2WeaponRef { Ptr32<S2WeaponObject> value; int reserved;
    S2WeaponRef() { value = 0; }
    ~S2WeaponRef() { if (value) ((Ptr32<void (Ptr32<S2WeaponObject>)>)value->vtable[4])(value); }
};
void w3d_actor_base_initialize(Ptr32<S2Weapon>);
void w3d_actor_base_destroy(Ptr32<S2Weapon>, int);
void w3d_constructor_lookup_name(Ptr32<S2WeaponKey>, Ptr32<Ptr32<S2WeaponObject>>);
Ptr32<S2WeaponObject> w3d_empty_803426b4(Ptr32<S2WeaponObject>);
int w3d_auto_8015fb34(Ptr32<S2Weapon>, Ptr32<unsigned short>);
void w3d_auto_8015fd1c(Ptr32<S2Weapon>);
void w3d_teleport_setup_80119590(Ptr32<S2Weapon>);
void w3d_teleport_shutdown_801196d8(Ptr32<S2Weapon>);
void w3d_teleport_fire_80119794(Ptr32<S2Weapon>);
int w3d_teleport_has_target_80119aa8(Ptr32<S2Weapon>);
int w3d_fn_8015f65c(int, Ptr32<void>);
Ptr32<void> w3d_fn_801613f0(Ptr32<void>, int);
int w3d_cached_message_id(Ptr32<void>, int);
int w3d_message_post_current(Ptr32<void>);
int w3d_fn_80162024(Ptr32<S2Weapon>, Ptr32<unsigned short>, Ptr32<Ptr32<S2WeaponObject>>);
int w3d_fn_800fc43c(Ptr32<S2WeaponKey>, int);
Ptr32<S2WeaponObject> w3d_auto_80178c48(Ptr32<S2WeaponObject>);
Ptr32<S2WormState> w3d_fn_800fc6dc(int);
int w3d_fn_80035714(Ptr32<void>, Ptr32<const char>, float);
Ptr32<void> w3d_message_string_init(Ptr32<void>, unsigned short, Ptr32<const char>);
void w3d_fn_800fc230(Ptr32<S2WeaponKey>, Ptr32<int>);
extern unsigned char w3d_obj_80410950[], w3d_obj_8040db38[];
extern unsigned int w3d_obj_804af31c, w3d_obj_804af324, w3d_obj_804af32c, w3d_obj_804af354, w3d_obj_804af35c, w3d_obj_804af37c, w3d_obj_804af384, w3d_obj_804af394, w3d_obj_804af39c;
extern Ptr32<void> w3d_obj_804b1754; extern Ptr32<void> w3d_obj_804aa8c8;
extern const char w3d_str_8039aacc[], w3d_str_8039aadc[], w3d_str_8039aaf8[], w3d_str_8039ab00[], w3d_str_8039abc4[], w3d_str_8039abd8[];
extern const float w3d_f32_8039ab10[];


Ptr32<S2WeaponMessage> w3d_target_id_message_801190b4(Ptr32<S2WeaponMessage> self, unsigned short id, int target)
{
    self->id = id;
    self->vtable = w3d_obj_8040db38;
    self->value = target;
    return self;
}


#if 0 /* 2 attempts; two local-address setup instructions differ */
S2Weapon *w3d_teleport_construct_801192ec(S2Weapon *self)
{
    w3d_actor_base_initialize(self);
    self->vtable = (void **)w3d_obj_80410950;
    self->deleteSubscription = 0;
    self->fireSubscription = 0;
    self->payload = 0;
    self->worm = 0;
    self->fired = 0;
    struct { S2WeaponObject *actor; int reserved; S2WeaponKey key; } local;
    local.key.text = w3d_str_8039aacc;
    local.actor = 0;
    w3d_constructor_lookup_name(&local.key, &local.actor);
    S2WeaponObject *worm = w3d_empty_803426b4(local.actor);
    if (worm) ((void (*)(S2WeaponObject *))worm->vtable[3])(worm);
    if (self->worm) ((void (*)(S2WeaponObject *))self->worm->vtable[4])(self->worm);
    self->worm = worm;
    if (local.actor) ((void (*)(S2WeaponObject *))local.actor->vtable[4])(local.actor);
    return self;
}
#endif


void w3d_teleport_destroy_801193bc(Ptr32<S2Weapon> self, int flags)
{
    self->vtable = (Ptr32<Ptr32<void>>)w3d_obj_80410950;
    if (self->worm) ((Ptr32<void (Ptr32<S2WeaponObject>)>)self->worm->vtable[4])(self->worm);
    if (self->payload) ((Ptr32<void (Ptr32<S2WeaponObject>)>)self->payload->vtable[4])(self->payload);
    if (self->fireSubscription) ((Ptr32<void (Ptr32<S2WeaponObject>)>)self->fireSubscription->vtable[4])(self->fireSubscription);
    if (self->deleteSubscription) ((Ptr32<void (Ptr32<S2WeaponObject>)>)self->deleteSubscription->vtable[4])(self->deleteSubscription);
    w3d_actor_base_destroy(self, flags);
}


#if 0 /* 3 attempts; switch temporary and branch layout differ */
int w3d_teleport_dispatch_80119470(S2Weapon *self, unsigned short *message)
{
    int id = *message;
    switch (id) {
    case 64:
        if (w3d_auto_8015fb34(self, message) >= 0) {
            w3d_teleport_setup_80119590(self);
            goto success;
        } else return 0x80004005;
    case 66:
        w3d_teleport_shutdown_801196d8(self);
        break;
    default:
        if (w3d_fn_8015f65c(id, &w3d_obj_804af32c)) {
            if (w3d_teleport_has_target_80119aa8(self)) w3d_teleport_fire_80119794(self);
            else {
                S2WeaponMessage *message_804af35c = (S2WeaponMessage *)w3d_fn_801613f0(w3d_obj_804b1754, 8);
                message_804af35c->id = w3d_cached_message_id(&w3d_obj_804af35c, 1);
                message_804af35c->vtable = w3d_obj_8040db38;
                w3d_message_post_current(message_804af35c);
            }
        } else if (!w3d_fn_8015f65c(id, &w3d_obj_804af31c)) {
            break;
        } else w3d_auto_8015fd1c(self);
        goto success;
    }
    return w3d_auto_8015fb34(self, message);
success:
    return 0;
}
#endif


void w3d_teleport_setup_80119590(Ptr32<S2Weapon> self)
{
    unsigned short deleteMessage = w3d_cached_message_id(&w3d_obj_804af31c, 1);
    w3d_fn_80162024(self, &deleteMessage, &self->deleteSubscription);
    unsigned short fireMessage = w3d_cached_message_id(&w3d_obj_804af32c, 1);
    w3d_fn_80162024(self, &fireMessage, &self->fireSubscription);
    S2WeaponKey key;
    key.text = w3d_str_8039aadc;
    w3d_fn_800fc43c(&key, 0);
    Ptr32<S2WeaponMessage> message = (Ptr32<S2WeaponMessage>)w3d_fn_801613f0(w3d_obj_804b1754, 12);
    w3d_message_post_current(w3d_target_id_message_801190b4(message, (unsigned short)w3d_cached_message_id(&w3d_obj_804af324, 1), self->id));
    if (w3d_fn_800fc6dc((int)w3d::H((w3d_auto_80178c48(self->worm))))->remote) {
        Ptr32<S2WeaponMessage> message_804af39c = (Ptr32<S2WeaponMessage>)w3d_fn_801613f0(w3d_obj_804b1754, 8);
        message_804af39c->id = w3d_cached_message_id(&w3d_obj_804af39c, 1);
        message_804af39c->vtable = w3d_obj_8040db38;
        w3d_message_post_current(message_804af39c);
        w3d_fn_80035714(w3d_obj_804aa8c8, w3d_str_8039aaf8, w3d_f32_8039ab10[0]);
        Ptr32<void> disable = w3d_fn_801613f0(w3d_obj_804b1754, 12);
        w3d_message_post_current(w3d_message_string_init(disable, (unsigned short)w3d_cached_message_id(&w3d_obj_804af384, 1), w3d_str_8039ab00));
    }
}


void w3d_teleport_shutdown_801196d8(Ptr32<S2Weapon> self)
{
    Ptr32<void> enable = w3d_fn_801613f0(w3d_obj_804b1754, 12);
    w3d_message_post_current(w3d_message_string_init(enable, (unsigned short)w3d_cached_message_id(&w3d_obj_804af37c, 1), w3d_str_8039ab00));
    Ptr32<S2WeaponMessage> message_804af394 = (Ptr32<S2WeaponMessage>)w3d_fn_801613f0(w3d_obj_804b1754, 8);
    message_804af394->id = w3d_cached_message_id(&w3d_obj_804af394, 1);
    message_804af394->vtable = w3d_obj_8040db38;
    w3d_message_post_current(message_804af394);
    if (w3d_fn_800fc6dc((int)w3d::H((w3d_auto_80178c48(self->worm))))->remote && !self->fired) w3d_teleport_fire_80119794(self);
}


#if 0 /* 2 attempts; two property-output address setup instructions differ */
int w3d_teleport_has_target_80119aa8(S2Weapon *self)
{
    S2WeaponMessage *message_804af354 = (S2WeaponMessage *)w3d_fn_801613f0(w3d_obj_804b1754, 8);
    message_804af354->id = w3d_cached_message_id(&w3d_obj_804af354, 1);
    message_804af354->vtable = w3d_obj_8040db38;
    w3d_message_post_current(message_804af354);
    S2WeaponKey targetKey;
    int hasTarget;
    S2WeaponKey cameraKey;
    int cameraMode;
    targetKey.text = w3d_str_8039abc4;
    w3d_fn_800fc230(&targetKey, &hasTarget);
    cameraKey.text = w3d_str_8039abd8;
    w3d_fn_800fc230(&cameraKey, &cameraMode);
    return hasTarget && cameraMode != 2;
}
#endif

}


