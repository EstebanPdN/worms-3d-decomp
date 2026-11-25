/* Worms 3D GameCube PAL 0x80051df8. Music message handler: start and stop messages with the base handler; one message copies a vector value; one loads the named sound into +80, sets its position from the camera and starts it; others go to the base handler. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct String;
extern "C" void string_finish_8020c5c4(String *);
extern "C" void string_release_80341588(String *);
struct String {
    char *text;
    String(const char *);
    ~String() { string_finish_8020c5c4(this); string_release_80341588(this); }
    String(const String &);
};
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) { x = a; y = b; z = c; }
};
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Msg { unsigned short id; unsigned short Id() const { return id; } };
struct Effect { struct V { void *u[5]; int (*start)(Effect *); void *u24[8]; int (*set_vec)(Effect *, int, Vec3 *); } *vtable; };
struct Sound { struct V { void *u[23]; int (*load)(Sound *, const char *, Effect **); } *vtable; };
struct Camera { struct V { void *u[14]; Vec3 *(*position)(Camera *); } *vtable; };
struct App { char u0[48]; Camera *camera; char u52[56]; Sound *sound; };
struct Self { char u0[80]; Effect *effect; };
extern App *app_804b1788;
extern MessageCache c_804ad478, c_804ad480;
extern "C" int base_8016293c(Self *, Msg *);
extern "C" void init_80051f94(Self *);
extern "C" void shutdown_80052004(Self *);
extern "C" int id_equals_8015f65c(int, MessageCache *);
extern "C" Vec3 *msg_vec_80126034(Msg *);
extern "C" const char *msg_text_8010a8fc(Msg *);
extern "C" int w3d_d24g_music_messages_80051df8(Self *self, Msg *msg)
{
    unsigned short id = msg->Id();
    switch (msg->Id()) {
    case 64:
        if (base_8016293c(self, msg) >= 0) {
            init_80051f94(self);
            break;
        }
        return 0x80004005;
    case 66:
        shutdown_80052004(self);
        return base_8016293c(self, msg);
    default:
        if (id_equals_8015f65c(id, &c_804ad478)) {
            Vec3 *m = msg_vec_80126034(msg);
            Vec3 v(m->x, m->y, m->z);
        } else if (!id_equals_8015f65c(id, &c_804ad480)) {
            return base_8016293c(self, msg);
        } else {
            String name(msg_text_8010a8fc(msg));
            app_804b1788->sound->vtable->load(app_804b1788->sound, name.text, &self->effect);
            Vec3 *c = app_804b1788->camera->vtable->position(app_804b1788->camera);
            Vec3 p(c->x, c->y, c->z);
            self->effect->vtable->set_vec(self->effect, 3, &p);
            self->effect->vtable->start(self->effect);
        }
    }
    return 0;
}
