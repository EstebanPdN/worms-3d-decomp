#include "w3d_ptr.h"
#line 1 "d24g_super_sheep_start_80070fec.cpp"
/* Worms 3D GameCube PAL 0x80070fec. Super Sheep start-up: subscribes to twelve cached messages with slots +364..+408, reads CommentaryPanel.Comment into +360, clears its state, posts the Flying commentary message, rotates its matrix at +124 by -pi/2 about the axis index 2, runs its start-up steps and, when the handle resolves, assigns the SuperSheepFlyCamera name and plays the start sound, then forwards the team colours to 0x800fdc80. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Mat { float m[9]; };
struct Vec { float x, y, z; Vec(float a, float b, float c) { x = a; y = b; z = c; } };
struct Key { Ptr32<const char> name; template <class W3dU> Key(Ptr32<W3dU> w3d_p) : Key((const char *)w3d_p.get()) {}
 Key(const char *n) { name = n; } };
struct String { Ptr32<char> text; };
struct Team { char u[152]; unsigned char a, b; };
struct Context { char u[52]; int value; };
struct Self;
struct Vt { Ptr32<void> u[18]; Ptr32<void (Ptr32<Self>)> step72; Ptr32<void (Ptr32<Self>)> step76; };
struct Self {
    Ptr32<Vt> vtable;
    char u4[16];
    Ptr32<void> handle;      /* +20 */
    char u24[60];
    int time;          /* +84 */
    char u88[36];
    Mat matrix;        /* +124 */
    char u160[32];
    Ptr32<void> object192;   /* +192 */
    char u196[108];
    String name;       /* +304 */
    int z308, z312, z316, z320, z324, z328, z332;
    float f336, f340, f344, f348;
    int contextValue;  /* +352 */
    int time356;       /* +356 */
    int comment;       /* +360 */
    int slots[12];     /* +364 */
};
extern MessageCache msg_804ad8c4, msg_804ad8cc, msg_804ad8d4, msg_804ad8dc, msg_804ad8e4, msg_804ad8ec, msg_804ad8f4, msg_804ad8fc, msg_804ad904, msg_804ad90c, msg_804ad914, msg_804ad91c, msg_804ad92c;
extern "C" int message_id_8015f5a0(Ptr32<MessageCache>, int);
extern "C" int subscribe_80162024(Ptr32<Self>, const unsigned short &, Ptr32<void>);
extern "C" int read_resource_800fc1b0(Ptr32<const Key>, Ptr32<int>);
extern "C" Ptr32<void> empty_80341584(Ptr32<void>);
extern "C" Ptr32<Team> team_801797b4(Ptr32<void>);
extern "C" Ptr32<Context> context_80165254();
extern Ptr32<void> arena_804b1754;
extern int g_804aaae8, g_804aaaec;
struct Message;
extern "C" Ptr32<Message> arena_alloc_801613f0(Ptr32<void>, int);
extern "C" Ptr32<Message> message_string_init_8010a8e0(Ptr32<Message>, int, Ptr32<const char>);
extern "C" int message_post_8016239c(Ptr32<Message>);
extern "C" void rotation_801a3eb0(Ptr32<const Vec>, int, Ptr32<Mat>);
extern "C" void multiply_801f606c(Ptr32<Mat>, Ptr32<const Mat>, Ptr32<const Mat>);
extern "C" void step_800ed784(Ptr32<Self>);
extern "C" void events_800ed090(Ptr32<Self>);
extern "C" Ptr32<void> lookup_80164fc8(Ptr32<void>);
extern "C" void string_assign_8020bd38(Ptr32<String>, Ptr32<const char>);
extern "C" void play_800edd1c(Ptr32<Self>);
extern "C" int forward_800fdc80(int, int, Ptr32<void>, int, int, int);
extern const char s_8037ca60[], s_8037ca78[], s_8037ca80[];
extern char sfx_8045e788[];
extern "C" void w3d_d24g_super_sheep_start_80070fec(Ptr32<Self> self)
{
    int zero = 0;
    Mat tmp, result;
    subscribe_80162024(self, message_id_8015f5a0(&msg_804ad8c4, 1), self->slots + 0);
    subscribe_80162024(self, message_id_8015f5a0(&msg_804ad8cc, 1), self->slots + 1);
    subscribe_80162024(self, message_id_8015f5a0(&msg_804ad8d4, 1), self->slots + 2);
    subscribe_80162024(self, message_id_8015f5a0(&msg_804ad8dc, 1), self->slots + 3);
    subscribe_80162024(self, message_id_8015f5a0(&msg_804ad8e4, 1), self->slots + 4);
    subscribe_80162024(self, message_id_8015f5a0(&msg_804ad8ec, 1), self->slots + 5);
    subscribe_80162024(self, message_id_8015f5a0(&msg_804ad8f4, 1), self->slots + 6);
    subscribe_80162024(self, message_id_8015f5a0(&msg_804ad8fc, 1), self->slots + 7);
    subscribe_80162024(self, message_id_8015f5a0(&msg_804ad904, 1), self->slots + 8);
    subscribe_80162024(self, message_id_8015f5a0(&msg_804ad90c, 1), self->slots + 9);
    subscribe_80162024(self, message_id_8015f5a0(&msg_804ad914, 1), self->slots + 10);
    subscribe_80162024(self, message_id_8015f5a0(&msg_804ad91c, 1), self->slots + 11);
    { Key k(s_8037ca60); read_resource_800fc1b0(&k, &self->comment); }Ptr32<Team> team = team_801797b4((Ptr32<void>)empty_80341584(self->object192));
    self->z308 = zero;
    self->z312 = zero;
    self->z316 = zero;
    self->z320 = zero;
    self->z324 = zero;
    self->z328 = zero;
    self->contextValue = context_80165254()->value;
    self->z332 = zero;
    self->f336 = 0.0f;
    self->f344 = 0.0f;
    self->f340 = 0.0f;
    self->f348 = 0.0f;
    g_804aaae8 = zero;
    g_804aaaec = zero;
    Ptr32<Message> message = arena_alloc_801613f0(arena_804b1754, 12);
    message_post_8016239c(message_string_init_8010a8e0(message, (unsigned short)message_id_8015f5a0(&msg_804ad92c, 1), s_8037ca78));
    Vec v(-1.5707964f, 0.0f, 0.0f);
    rotation_801a3eb0(&v, 2, &tmp);
    multiply_801f606c(&result, &tmp, &self->matrix);
    self->matrix = result;
    self->vtable->step76(self);
    self->vtable->step72(self);
    step_800ed784(self);
    events_800ed090(self);
    self->time356 = self->time;
    if (lookup_80164fc8(self->handle)) {
        string_assign_8020bd38(&self->name, s_8037ca80);
        play_800edd1c(self);
    }
    forward_800fdc80(team->b, team->a, sfx_8045e788, 500, -1, -1);
}


