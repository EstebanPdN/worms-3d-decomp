#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s3_worm_pot_tick.c"
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
extern void w3d_ctor_8015fef0(Ptr32<S3WormPot>);
extern Ptr32<void> w3d_vtable_80410ec0[];
extern const float w3d_f32_803a0404[];
extern const float w3d_f32_803a0410[];
extern int w3d_auto_8015fb34(Ptr32<S3WormPot>, Ptr32<void>);
extern Ptr32<S3Interface> w3d_fn_80164fc8(int);
extern void w3d_fn_800fc7f8(Ptr32<void>);
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
void w3d_worm_pot_update_text_80140fc8(Ptr32<S3WormPot>);

int w3d_worm_pot_tick(Ptr32<S3WormPot> self, int time)
{
    float value = self->current;
    unsigned int target = self->target;
    if ((int)value != target) {
        float next = (float)(time - self->last_time) * 0.08f + value;
        float limit = (float)target;
        if (next > limit) self->current = limit;
        else self->current = next;
        w3d_worm_pot_update_text_80140fc8(self);
    }
    self->last_time = time;
    return 0;
}

}
