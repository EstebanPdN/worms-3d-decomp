/* Worms 3D GameCube PAL 0x80068874. First-person camera message handler: start and stop messages with the base handler; on the camera mode message reads Camera.CurrentMode, stores whether it is 1 in +396 and updates; two messages select shots 3 and 6 (the latter unless shot 8 is active); one aims when first-person is on; others go to the base handler. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Msg { unsigned short id; unsigned short Id() const { return id; } };
struct Key { const char *text; };
struct Self { char u0[116]; int shot; char u120[276]; int firstPerson; };
extern MessageCache c_804ad650, c_804ad658, c_804ad660, c_804ad638;
extern const char s_8037a858[];
extern "C" int base_8015fb34(Self *, Msg *);
extern "C" void start_80068a14(Self *);
extern "C" void stop_80069430(Self *);
extern "C" int id_equals_8015f65c(int, MessageCache *);
extern "C" int read_800fc230(Key *, int *);
extern "C" void update_8006947c(Self *);
extern "C" void set_shot_80069630(Self *, int);
extern "C" void aim_800697ac(Self *);
extern "C" int w3d_d24g_camera_messages_80068874(Self *self, Msg *msg)
{
    unsigned short id = msg->Id();
    switch (msg->Id()) {
    case 64:
        if (base_8015fb34(self, msg) >= 0) {
            start_80068a14(self);
            break;
        }
        return 0x80004005;
    case 66:
        stop_80069430(self);
        return base_8015fb34(self, msg);
    default:
        if (id_equals_8015f65c(id, &c_804ad650)) {
            Key key;
            int mode;
            key.text = s_8037a858;
            read_800fc230(&key, &mode);
            self->firstPerson = mode == 1;
            update_8006947c(self);
        } else if (id_equals_8015f65c(id, &c_804ad658)) {
            set_shot_80069630(self, 3);
        } else if (id_equals_8015f65c(id, &c_804ad660)) {
            if (self->shot != 8) set_shot_80069630(self, 6);
        } else if (!id_equals_8015f65c(id, &c_804ad638)) {
            return base_8015fb34(self, msg);
        } else if (self->firstPerson) {
            aim_800697ac(self);
        }
    }
    return 0;
}
