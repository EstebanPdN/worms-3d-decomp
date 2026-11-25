#include "w3d_ptr.h"
#line 1 "d29g_earthquake_start_80061a80.cpp"
/* Worms 3D GameCube PAL 0x80061a80. Earthquake effect start: asserts the type is not one of the two world entity types, subscribes a message into +32, copies Earthquake.CameraShakeMagnitude and Earthquake.Length into the camera shake properties and sets Camera.Orbit.IgnoreInput, starts the Orbit sound, posts a message, reads the shake handle into +40 and fades with alpha from magnitude times 200 clamped to 255 over 1000 ms. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct Type { char u[20]; Ptr32<Type> parent; };
extern Type type_a_80361860[], type_b_803618f0[];
struct MessageSlot { int a, b; };
struct MsgId { short id; };
struct Key { Ptr32<const char> name; };
struct Msg { unsigned short id; Ptr32<void> data; };
struct State;
struct StateVt { char u[20]; Ptr32<Ptr32<Type> (Ptr32<State>)> type; };
struct State {
    Ptr32<StateVt> vt; char u4[32 - 4]; int sub; int file; int fade;
    template <Type *T> bool isA() {
        Ptr32<Type> c = vt->type(this);
        Ptr32<Type> t = T;
        while (c != t) {
            if (c == c->parent) return false;
            c = c->parent;
        }
        return true;
    }
};
extern "C" {
int w3d_assert_80022e20(Ptr32<const char>, Ptr32<const char>, int, Ptr32<void>);
int w3d_cached_message_id(Ptr32<MessageSlot>, int);
int d24d_acquire_message_80162024(Ptr32<State>, Ptr32<MsgId>, Ptr32<int>);
int w3d_auto_800fc270(Ptr32<Key>, Ptr32<float>);
int w3d_cx7a_service_float_assign_800fc4c8(Ptr32<Key>, float);
int w3d_auto_800fc1f0(Ptr32<Key>, Ptr32<int>);
int s8_property_write_800fc3b0(Ptr32<Key>, int);
int s8_property_write_800fc43c(Ptr32<Key>, int);
int w3d_sound_80035714(Ptr32<void>, Ptr32<const char>, float);
Ptr32<void> tsonnet_b33_arena_801613f0(Ptr32<void>, int);
int w3d_message_post_current(Ptr32<Msg>);
int w3d_auto_800fc230(Ptr32<Key>, Ptr32<int>);
int w3d_s20_forward_global4_800fdd80(int, unsigned char, Ptr32<void>, int, int);
}
extern char s0_8037930c[], s1_80379318[], s2_80379334[], s3_80379354[], s4_8037936c[], s5_80379380[], s6_80379394[], s7_803793b0[], s8_803793b8[];
extern MessageSlot m0_804ad4f4, m1_804ad4fc;
extern Ptr32<void> sound_804aa8c8;
extern Ptr32<void> arena_804b1754;
extern char data_8040db38[];
extern char zero_8045e788[];
extern "C" void w3d_d29g_earthquake_start_80061a80(Ptr32<State> self)
{
    if (self->isA<type_a_80361860>() || self->isA<type_b_803618f0>())
        w3d_assert_80022e20(s0_8037930c, s1_80379318, 123, &self->file);
    MsgId id;
    id.id = w3d_cached_message_id(&m0_804ad4f4, 1);
    d24d_acquire_message_80162024(self, &id, &self->sub);
    Key k0 = {s2_80379334};
    float time;
    w3d_auto_800fc270(&k0, &time);
    Key k1 = {s3_80379354};
    w3d_cx7a_service_float_assign_800fc4c8(&k1, time);
    Key k2 = {s4_8037936c};
    int value;
    w3d_auto_800fc1f0(&k2, &value);
    Key k3 = {s5_80379380};
    s8_property_write_800fc3b0(&k3, value);
    Key k4 = {s6_80379394};
    s8_property_write_800fc43c(&k4, 1);
    w3d_sound_80035714(sound_804aa8c8, s7_803793b0, 1.0f);
    Ptr32<Msg> m = (Ptr32<Msg>)tsonnet_b33_arena_801613f0(arena_804b1754, 8);
    m->id = w3d_cached_message_id(&m1_804ad4fc, 1);
    m->data = data_8040db38;
    w3d_message_post_current(m);
    Key k5 = {s8_803793b8};
    w3d_auto_800fc230(&k5, &self->fade);
    float a = time * 200.0f;
    unsigned char alpha;
    if (a > 255.0f) alpha = 255;
    else alpha = (unsigned char)a;
    w3d_s20_forward_global4_800fdd80(0, alpha, zero_8045e788, 1000, 0);
}


