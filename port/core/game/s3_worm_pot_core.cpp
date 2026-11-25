#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s3_worm_pot_core.c"
typedef struct S3Interface S3Interface;
typedef struct S3InterfaceVtable {
    Ptr32<void (void)> slot0;
    Ptr32<void (void)> slot1;
    Ptr32<void (void)> slot2;
    Ptr32<void (Ptr32<S3Interface>)> retain;
    Ptr32<void (Ptr32<S3Interface>)> release;
    Ptr32<void (void)> slot5;
    Ptr32<void (void)> slot6;
    Ptr32<void (void)> slot7;
    Ptr32<void (void)> slot8;
    Ptr32<void (void)> slot9;
    Ptr32<void (Ptr32<S3Interface>, Ptr32<const void>)> position;
    Ptr32<void (Ptr32<S3Interface>, Ptr32<const char>)> text;
    Ptr32<void (Ptr32<S3Interface>, Ptr32<void>)> message;
} S3InterfaceVtable;
struct S3Interface { Ptr32<S3InterfaceVtable> vtable; };
typedef struct S3WormPot {
    Ptr32<void> vtable;
    unsigned char pad04[0x14-4];
    int owner;
    int pad18;
    int first;
    int second;
    unsigned int target;
    float current;
    int last_time;
    Ptr32<S3Interface> pot;
} S3WormPot;
typedef struct S3PotState { unsigned char pad00[0x3c]; int state; } S3PotState;
extern int w3d_ctor_8015fef0(Ptr32<S3WormPot>);
extern Ptr32<void> w3d_vtable_80410ec0[];
extern const float w3d_f32_803a0404[];
extern const float w3d_f32_803a0410[];
extern int w3d_auto_8015fb34(Ptr32<S3WormPot>, Ptr32<void>);
extern Ptr32<S3Interface> w3d_fn_80164fc8(int);
extern Ptr32<void> w3d_fn_800fc7f8(int);
extern void w3d_fn_800fd3e4(Ptr32<int>, Ptr32<void>, ...);
extern void w3d_fn_8011adf8(Ptr32<S3Interface>, Ptr32<int>, Ptr32<int>);
extern int w3d_global_804af3b4;
extern int w3d_fn_8020b680(Ptr32<void>);
extern Ptr32<void> w3d_global_80410a10[];
extern int w3d_global_804b178c;
extern int w3d_fn_80164514(int, int, int);
extern const char w3d_str_803a0430[];
extern void w3d_constructor_lookup_name(Ptr32<Ptr32<const char>>, Ptr32<Ptr32<S3Interface>>);
extern Ptr32<S3Interface> w3d_empty_80341584(Ptr32<S3Interface>);
extern void w3d_fn_8011afac(Ptr32<S3Interface>, Ptr32<void>);
extern Ptr32<S3PotState> w3d_auto_801797b4(Ptr32<S3Interface>);
extern char w3d_str_804b194c;
extern const char w3d_str_803a0438[];
extern int w3d_fn_802ec254(Ptr32<char>, Ptr32<const char>, ...);
void w3d_worm_pot_initialize_80140e88(Ptr32<S3WormPot>);
void w3d_worm_pot_update_text(Ptr32<S3WormPot>);

Ptr32<S3WormPot> w3d_worm_pot_construct(Ptr32<S3WormPot> self)
{
    w3d_ctor_8015fef0(self);
    self->vtable = w3d_vtable_80410ec0;
    self->current = w3d_f32_803a0404[0];
    self->pot = 0;
    self->target = 0;
    self->last_time = 0;
    return self;
}
int w3d_worm_pot_dispatch(Ptr32<S3WormPot> self, Ptr32<unsigned short> message)
{
    if (*message == 64) {
        if (w3d_auto_8015fb34(self, message) >= 0) {
            w3d_worm_pot_initialize_80140e88(self);
            return 0;
        }
        return 0x80004005;
    }
    return w3d_auto_8015fb34(self, message);
}

void w3d_worm_pot_set_second_text(Ptr32<S3WormPot> self, Ptr32<const char> text)
{
    Ptr32<S3Interface> object = w3d_fn_80164fc8(self->second);
    object->vtable->text(object, text);
}
void w3d_worm_pot_apply_message(Ptr32<S3WormPot> self, Ptr32<void> message)
{
    int first_value;
    int second_value;
    Ptr32<S3Interface> first = w3d_fn_80164fc8(self->first);
    Ptr32<S3Interface> second = w3d_fn_80164fc8(self->second);
    w3d_fn_800fc7f8(w3d::H(message));
    w3d_fn_800fd3e4(&first_value, message);
    w3d_fn_8011adf8(first, &first_value, &w3d_global_804af3b4);
    first->vtable->message(first, message);
    w3d_fn_800fd3e4(&second_value, message);
    w3d_fn_8011adf8(second, &second_value, &w3d_global_804af3b4);
    second->vtable->message(second, message);
}
#if 0 /* 0x80140e88: stack-local instruction scheduling differs after eight attempts. */
void w3d_worm_pot_initialize_80140e88(S3WormPot *self)
{
    struct { S3Interface *object; int unused; const char *key; } local;
    S3Interface *held;
    int id;
    void *data = w3d_global_80410a10;
    id = w3d_fn_8020b680(data);
    self->first = w3d_fn_80164514(w3d_global_804b178c, id, self->owner);
    id = w3d_fn_8020b680(data);
    self->second = w3d_fn_80164514(w3d_global_804b178c, id, self->owner);
    local.object = 0;
    local.key = w3d_str_803a0430;
    w3d_constructor_lookup_name(&local.key, &local.object);
    held = w3d_empty_80341584(local.object);
    if (held) held->vtable->retain(held);
    if (self->pot) self->pot->vtable->release(self->pot);
    self->pot = held;
    if (local.object) local.object->vtable->release(local.object);
}
#endif

void w3d_worm_pot_apply_pair(Ptr32<S3WormPot> self, Ptr32<void> first_message, Ptr32<void> second_message)
{
    Ptr32<S3Interface> first = w3d_fn_80164fc8(self->first);
    Ptr32<S3Interface> second = w3d_fn_80164fc8(self->second);
    w3d_fn_8011afac(second, second_message);
    w3d_fn_8011afac(first, first_message);
}
void w3d_worm_pot_update_text(Ptr32<S3WormPot> self)
{
    char text[16];
    int value = (int)self->current;
    Ptr32<S3Interface> first = w3d_fn_80164fc8(self->first);
    if (w3d_auto_801797b4(self->pot)->state == 1) {
        first->vtable->text(first, &w3d_str_804b194c);
    } else {
        w3d_fn_802ec254(text, w3d_str_803a0438, value);
        first->vtable->text(first, text);
    }
}

}
