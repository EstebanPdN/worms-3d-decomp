/* FlyingPayloadGraphicEntity graphic component (0x8007018c, 0x800702a4,
 * 0x80070490): message handler, per-frame transform/clip update and the
 * pitch/roll clip blend control. Field and type names are inferred from the
 * original instructions. The component type record (original .data
 * 0x803e7c8c: name 0x8037c9c8, size 248, class block 0x8040eff0, registry
 * 0x8044fae8) is defined first so that its name string opens the .rodata of
 * this translation unit, as in the original (0x8037c9c8, followed by the
 * constant pools of 0x8007018c at 0x8037c9e4 and 0x80070490 at 0x8037c9ec).
 * Built with -mps-float (0x80070490 keeps 8 bytes below its FPR save area). */
struct Vec { float x, y, z; Vec() {} };
extern "C" void w3d_empty_80343740(Vec *);
struct Mat3 { Vec x, y, z; };
struct Matrix { Mat3 rotation; Vec translation; Matrix() { w3d_empty_80343740(&translation); } };
struct Object { void **vtable; };
struct Registry;
struct Settings {
    char unknown000[228]; int light;
    char unknown0e8[348]; int fly_clip;
    char unknown248[24]; float pitch_speed, roll_speed;
};
struct Controls {
    void **vtable;
    char unknown004[312];
    int roll_down, roll_up, pitch_down, pitch_up;
    const Mat3 *Orientation(int time) { return ((const Mat3 *(*)(Controls *, int))vtable[14])(this, time); }
};
struct Message { unsigned short id; unsigned short Id() const { return id; } };
struct Entity {
    void **vtable;
    char unknown004[24];
    void *owner;
    Object *mesh;
    char unknown024[24];
    Vec position;
    char unknown048[92];
    int last_time;
    char unknown0a8[20];
    int fly_control;
    int controls;
    int light_control;
    char unknown0c8[12];
    Object *member;
    float pitch, roll, roll_scale, pitch_scale;
    int pitch_clip, roll_clip;
    int cached;
};

struct ComponentType { const char *name; unsigned size; void *vtable; Registry *registry; int unknown10[3]; };
extern unsigned char w3d_class_8040eff0[];
extern Registry w3d_registry_8044fae8[];
ComponentType w3d_flying_payload_graphic_entity_type = {
    "FlyingPayloadGraphicEntity", 248, w3d_class_8040eff0, w3d_registry_8044fae8 };

extern "C" {
void *w3d_empty_80341584(void *);
Settings *w3d_auto_801797b4(void *);
int w3d_entity_handle_message_800e81a0(Entity *, Message *);
void w3d_cx16a_cache_clips_80070678(Entity *);
void w3d_empty_80070708(Entity *);
int w3d_message_id_equals_cache(unsigned int, void *);
void d17c_light_node_load_800e9830(Entity *, int);
int w3d_cc21b_play_named_clip_80181640(Object *, int, int *, int, float, float, float);
int w3d_mesh_instance_check_control(Object *, int, int);
void w3d_auto_800e9dc8(Entity *);
Controls *w3d_s20_lookup_handle_object_80164fc8(int);
int w3d_handle_member_query_801265ec(Object *, Vec *);
int w3d_d19a_set_clip_weight_80181884(Object *mesh, unsigned clip, float weight, float rate);
extern int w3d_message_804ad894;
}

inline const float &larger(const float &a, const float &b) { return a < b ? b : a; }
inline const float &smaller(const float &a, const float &b) { return b < a ? b : a; }

extern "C" int w3d_d19a_payload_graphic_message_8007018c(Entity *self, Message *message)
{
    unsigned short id = message->Id();
    switch (message->Id()) {
    case 64:
        if (w3d_entity_handle_message_800e81a0(self, message) >= 0) {
            w3d_cx16a_cache_clips_80070678(self);
            return 0;
        }
        return 0x80004005;
    case 66:
        w3d_empty_80070708(self);
        break;
    default:
        if (w3d_message_id_equals_cache(id, &w3d_message_804ad894)) {
            self->cached = 1;
            Settings *settings = w3d_auto_801797b4(w3d_empty_80341584(self->owner));
            d17c_light_node_load_800e9830(self, settings->light);
            self->fly_control = w3d_cc21b_play_named_clip_80181640(self->mesh, settings->fly_clip, &self->fly_control, 0, 1.0f, 0.0f, 0.0f);
            w3d_mesh_instance_check_control(self->mesh, self->fly_control, 1);
            if (self->light_control != -1)
                w3d_auto_800e9dc8(self);
        }
        break;
    }
    return w3d_entity_handle_message_800e81a0(self, message);
}

extern "C" float w3d_d19a_clip_blend_80070490(Entity *self, int decrease, int increase, float current, float speed, float scale, unsigned clip, int ticks);

extern "C" void w3d_d19a_payload_graphic_update_800702a4(Entity *self, int time)
{
    Settings *settings = w3d_auto_801797b4(w3d_empty_80341584(self->owner));
    Controls *controls = w3d_s20_lookup_handle_object_80164fc8(self->controls);
    Matrix transform;
    transform.translation = self->position;
    transform.rotation = Mat3(*controls->Orientation(time));
    ((void (*)(Object *, Matrix *))self->mesh->vtable[42])(self->mesh, &transform);
    if (self->member)
        w3d_handle_member_query_801265ec(self->member, &self->position);
    if (!self->cached) {
        int ticks = time - self->last_time;
        self->roll = w3d_d19a_clip_blend_80070490(self, controls->roll_down, controls->roll_up, self->roll, settings->roll_speed, self->roll_scale, self->roll_clip, ticks);
        self->pitch = w3d_d19a_clip_blend_80070490(self, controls->pitch_down, controls->pitch_up, self->pitch, settings->pitch_speed, self->pitch_scale, self->pitch_clip, ticks);
    }
    self->last_time = time;
}

extern "C" float w3d_d19a_clip_blend_80070490(Entity *self, int decrease, int increase, float current, float speed, float scale, unsigned clip, int ticks)
{
    bool active = false;
    if (decrease || increase)
        active = true;
    if (decrease)
        current = larger(-1.0f, current - speed * (float)ticks);
    else if (!active && current > 0.0f)
        current = larger(0.0f, current - speed * (float)ticks);
    else if (increase)
        current = smaller(1.0f, speed * (float)ticks + current);
    if (!active && current < 0.0f)
        current = smaller(0.0f, speed * (float)ticks + current);
    w3d_d19a_set_clip_weight_80181884(self->mesh, clip, scale * (current * 0.5f + 0.5f), 1.0f);
    return current;
}
