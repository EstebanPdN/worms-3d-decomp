/* Worms 3D GameCube PAL 0x80061a80. Earthquake effect start: asserts the type is not one of the two world entity types, subscribes a message into +32, copies Earthquake.CameraShakeMagnitude and Earthquake.Length into the camera shake properties and sets Camera.Orbit.IgnoreInput, starts the Orbit sound, posts a message, reads the shake handle into +40 and fades with alpha from magnitude times 200 clamped to 255 over 1000 ms. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct Type { char u[20]; Type *parent; };
extern Type type_a_80361860[], type_b_803618f0[];
struct MessageSlot { int a, b; };
struct MsgId { short id; };
struct Key { const char *name; };
struct Msg { unsigned short id; void *data; };
struct State;
struct StateVt { char u[20]; Type *(*type)(State *); };
struct State {
    StateVt *vt; char u4[32 - 4]; int sub; int file; int fade;
    template <Type *T> bool isA() {
        Type *c = vt->type(this);
        Type *t = T;
        while (c != t) {
            if (c == c->parent) return false;
            c = c->parent;
        }
        return true;
    }
};
extern "C" {
int w3d_assert_80022e20(const char *, const char *, int, void *);
int w3d_cached_message_id(MessageSlot *, int);
int d24d_acquire_message_80162024(State *, MsgId *, int *);
int w3d_auto_800fc270(Key *, float *);
int w3d_cx7a_service_float_assign_800fc4c8(Key *, float);
int w3d_auto_800fc1f0(Key *, int *);
int s8_property_write_800fc3b0(Key *, int);
int s8_property_write_800fc43c(Key *, int);
int w3d_sound_80035714(void *, const char *, float);
void *tsonnet_b33_arena_801613f0(void *, int);
int w3d_message_post_current(Msg *);
int w3d_auto_800fc230(Key *, int *);
int w3d_s20_forward_global4_800fdd80(int, unsigned char, void *, int, int);
}
extern char s0_8037930c[], s1_80379318[], s2_80379334[], s3_80379354[], s4_8037936c[], s5_80379380[], s6_80379394[], s7_803793b0[], s8_803793b8[];
extern MessageSlot m0_804ad4f4, m1_804ad4fc;
extern void *sound_804aa8c8;
extern void *arena_804b1754;
extern char data_8040db38[];
extern char zero_8045e788[];
extern "C" void w3d_d29g_earthquake_start_80061a80(State *self)
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
    Msg *m = (Msg *)tsonnet_b33_arena_801613f0(arena_804b1754, 8);
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
