/* Worms 3D GameCube PAL 0x8006f62c. Camera system start: queries 0x8015a6b8, reads Camera.Entity.TaskId into +76 and Camera.Data, applies the data, then either computes the three vectors at +4..+28 and starts the camera task with them, or copies them from the source object, and posts eight camera-mode messages (Fire, Flying, WormAiming, WormFirstPersonAiming, WormMoving, WormRoping, UtilityGirder, CameraSelect). Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Key { const char *text; };
struct Words { int a, b, c; };
struct Task { struct V { void *u[11]; void (*start)(Task *, int, Words *); } *vtable; };
struct Context { char u[52]; int time; };
struct Source { int unknown; Words a, b, c; };
struct Self { int unknown; Words a, b, c; char u40[36]; int task; char u80[28]; int active; };
extern "C" void query_8015a6b8(void *);
extern "C" int read_800fc230(Key *, int *);
extern "C" int read_800fc2b0(Key *, const char **);
extern "C" void set_data_8006fc24(Self *, const char *);
extern "C" void compute_8006fca0(Self *, Words *, Words *, Words *);
extern "C" Context *context_80165254();
extern "C" Task *lookup_80164fc8(int);
extern "C" int message_id_8015f5a0(MessageCache *, int);
extern "C" void *arena_alloc_801613f0(void *, int);
extern "C" int message_post_8016239c(void *);
extern "C" void *message_string_8010a8e0(void *, int, const char *);
extern void *arena_804b1754;
extern MessageCache msg_804ad880, msg_804ad878;
extern const char s_8037c8c4[], s_8037c8dc[], s_8037c8e8[], s_8037c8f0[], s_8037c8f8[], s_8037c904[], s_8037c91c[], s_8037c928[], s_8037c934[], s_8037c944[];
#define POST_TEXT(cache, text) { \
    void *m = arena_alloc_801613f0(arena_804b1754, 12); \
    message_post_8016239c(message_string_8010a8e0(m, (unsigned short)message_id_8015f5a0(cache, 1), text)); \
}
extern "C" void w3d_d24g_camera_system_start_8006f62c(Self *self, Source *source)
{
    query_8015a6b8((void *)self);
    { Key key; key.text = s_8037c8c4; read_800fc230(&key, &self->task); }
    const char *data;
    { Key key; key.text = s_8037c8dc; read_800fc2b0(&key, &data); }
    set_data_8006fc24(self, data);
    if (self->active) {
        compute_8006fca0(self, &self->a, &self->b, &self->c);
        int time = context_80165254()->time;
        Task *task = lookup_80164fc8(self->task);
        task->vtable->start(task, time, &self->a);
    } else {
        self->a = source->a;
        self->b = source->b;
        self->c = source->c;
    }
    POST_TEXT(&msg_804ad880, s_8037c8e8)
    POST_TEXT(&msg_804ad880, s_8037c8f0)
    POST_TEXT(&msg_804ad878, s_8037c8f8)
    POST_TEXT(&msg_804ad878, s_8037c904)
    POST_TEXT(&msg_804ad878, s_8037c91c)
    POST_TEXT(&msg_804ad878, s_8037c928)
    POST_TEXT(&msg_804ad878, s_8037c934)
    POST_TEXT(&msg_804ad878, s_8037c944)
}
