/* Camera manager message handler (0x80031bb4): message 64 runs the base handler
 * (0x8016293c; a negative result returns 0x80004005) and the start-up 0x8003379c;
 * message 66 runs 0x80035388. Otherwise forwards the message to the current camera
 * (virtual +28 of its interface at +72) and dispatches the cached ids: slot
 * forwarding (0x800fd4c8), spectator and network slots (0x800a7e14), camera mode
 * changes (0x80035714), weapon cameras, the shake (0x800364d0..0x8003694c) and the
 * input flags and counters of two input states (+728, +596). The base handler runs
 * at the end of every path. Field and type names are inferred from the original
 * instructions. Strings and globals are external views of original data; the unit
 * owns no data. */
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Message {
    unsigned short id;
    unsigned short Id() const { return id; }
};
struct PropertyKey { const char *name; };
struct Vec3 { float x, y, z; };
struct Camera;
struct CameraInterface {
    void *unknown00[6];
    int (*activate)(Camera *);            /* +24 */
    int (*handle)(Camera *, Message *);   /* +28 */
};
struct Camera {
    char unknown00[60];
    const char *name;          /* +60 */
    char unknown64[8];
    CameraInterface *secondary; /* +72 */
};
struct CameraVector {
    Camera **first;
    Camera *&operator[](int i) { return first[i]; }
};
struct Object;
struct ObjectVtable { void *unknown00[4]; void (*release)(Object *); };
struct Object { ObjectVtable *vtable; };
struct InputState {
    unsigned flags;            /* +0 */
    float time;                /* +4 */
    int x;                     /* +8 */
    int y;                     /* +12 */
    int z;                     /* +16 */
};
struct Team { char unknown00[24]; void *team; };
struct Network { char unknown00[36]; Team *session; };
struct CameraManager {
    char unknown00[312];
    int current;               /* +312 */
    CameraVector cameras;      /* +316 */
    char unknown320[84];
    char service[184];         /* +404 */
    int locked;                /* +588 */
    int active;                /* +592 */
    InputState second;         /* +596 */
    char unknown616[112];
    InputState first;          /* +728 */
    char unknown748[48];
    Object *object796;         /* +796 */
    Object *object800;         /* +800 */
    Object *object804;         /* +804 */
    char unknown808[16];
    Object *pitching;          /* +824 */
    char shake[4];             /* +828 */
    Camera *Current() { return cameras[current]; }
};
extern "C" int w3d_base_handler_8016293c(CameraManager *, Message *);
extern "C" void w3d_start_8003379c(CameraManager *);
extern "C" void w3d_stop_80035388(CameraManager *);
extern "C" int w3d_message_equals_8015f620(MessageCache *, unsigned short);
extern "C" int w3d_message_id_equals_8015f65c(unsigned short, MessageCache *);
extern "C" int w3d_forward_800fd4c8(int, int);
extern "C" int w3d_active_team_80020834(void *);
extern "C" int w3d_current_team_8021eb00(void *);
extern "C" void w3d_select_slot_800a7e14(int, const char *);
extern "C" int w3d_string_property_800fc2b0(PropertyKey *, const char **);
extern "C" int w3d_int_property_800fc1f0(PropertyKey *, int *);
extern "C" int w3d_float_property_800fc270(PropertyKey *, float *);
extern "C" int strcmp(const char *, const char *);
extern "C" int w3d_set_mode_80035714(CameraManager *, const char *, float);
extern "C" int w3d_service_ready_8015ab1c(void *);
extern "C" void w3d_service_attach_800a9620(void *, Camera *);
extern "C" void w3d_mode_80032bb0(CameraManager *, int);
extern "C" void w3d_no_target_800358b4(CameraManager *);
extern "C" void w3d_toggle_80032c84(CameraManager *, int, int);
extern "C" int w3d_update_value_80178d28(Object *, int *);
extern "C" void w3d_on_800329a4(CameraManager *, Message *);
extern "C" void w3d_shake_set_800364d0(void *, int, float);
extern "C" void w3d_shake_apply_800368ac(void *, int);
extern "C" void w3d_motion_velocity_800668b8(Vec3 *, Message *);
extern "C" float w3d_motion_a_800668fc(Message *);
extern "C" float w3d_motion_b_800668dc(Message *);
extern "C" void w3d_shake_impact_8003694c(void *, float, float, Vec3 *);
extern "C" const char *w3d_message_text_8010a8fc(Message *);
extern "C" void w3d_play_8003591c(CameraManager *, const char *, int);
extern "C" int w3d_message_worm_800a830c(Message *);
extern "C" void w3d_message_position_800a8334(Message *, int *, int *);
extern void *w3d_team_state_804b1760;
extern Network *w3d_network_804abac0;
extern float w3d_constant_803732c8[], w3d_constant_803732cc[];
extern MessageCache w3d_message_804acd84, w3d_message_804acd8c, w3d_message_804acd94, w3d_message_804acd9c, w3d_message_804acda4, w3d_message_804acdac, w3d_message_804acdb4, w3d_message_804acdbc, w3d_message_804acdc4, w3d_message_804acdcc, w3d_message_804acdd4, w3d_message_804acddc, w3d_message_804acde4, w3d_message_804acdec, w3d_message_804acdf4, w3d_message_804acdfc, w3d_message_804ace04, w3d_message_804ace0c, w3d_message_804ace14, w3d_message_804ace1c, w3d_message_804ace24, w3d_message_804ace2c, w3d_message_804ace34, w3d_message_804ace3c, w3d_message_804ace44, w3d_message_804ace4c, w3d_message_804ace54, w3d_message_804ace5c, w3d_message_804ace64, w3d_message_804ace6c, w3d_message_804ace74, w3d_message_804ace7c, w3d_message_804ace84, w3d_message_804ace8c, w3d_message_804ace94, w3d_message_804ace9c, w3d_message_804acea4, w3d_message_804aceac, w3d_message_804aceb4, w3d_message_804acebc, w3d_message_804acec4, w3d_message_804acecc, w3d_message_804aced4, w3d_message_804acedc, w3d_message_804acee4, w3d_message_804aceec, w3d_message_804acef4, w3d_message_804acefc, w3d_message_804acf04, w3d_message_804acf0c, w3d_message_804acf14, w3d_message_804acf1c, w3d_message_804acf34, w3d_message_804acf3c, w3d_message_804acf44, w3d_message_804acf54, w3d_message_804acf5c, w3d_message_804acf94, w3d_message_804acf9c, w3d_message_804acfa4, w3d_message_804acfac, w3d_message_804acfb4, w3d_message_804acfbc, w3d_message_804acfc4, w3d_message_804acfcc, w3d_message_804acfd4, w3d_message_804acfdc, w3d_message_804acfe4, w3d_message_804acfec, w3d_message_804acff4;
extern "C" char w3d_string_80373224[], w3d_string_80373230[], w3d_string_80373244[],
    w3d_string_80373260[], w3d_string_80373268[], w3d_string_8037327c[], w3d_string_8037328c[],
    w3d_string_80373294[], w3d_string_803732a8[], w3d_string_803732c0[];

inline bool Differs(const char *a, const char *b) { return strcmp(a, b) != 0; }

extern "C" int w3d_d24a_camera_manager_message_80031bb4(CameraManager *self, Message *message)
{
    unsigned short id = message->Id();
    switch (message->Id()) {
    case 64:
        if (w3d_base_handler_8016293c(self, message) >= 0) {
            w3d_start_8003379c(self);
            return 0;
        }
        return 0x80004005;
    case 66:
        w3d_stop_80035388(self);
        break;
    default:
        self->Current()->secondary->handle(self->Current(), message);
        if (w3d_message_equals_8015f620(&w3d_message_804acfbc, message->id)) {
            w3d_forward_800fd4c8(3, 2);
        } else {
        int hit1, hit2, hit3, hit4;
        int hit = w3d_message_equals_8015f620(&w3d_message_804acfb4, message->id);
        if (hit) {
            w3d_forward_800fd4c8(7, 2);
            w3d_forward_800fd4c8(4, 2);
            w3d_forward_800fd4c8(3, 2);
            w3d_forward_800fd4c8(13, 2);
            w3d_forward_800fd4c8(11, 2);
            w3d_forward_800fd4c8(10, 2);
        } else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acfac)) {
            if (w3d_active_team_80020834(w3d_team_state_804b1760)) {
                self->active = 0;
                self->locked = 1;
                w3d_select_slot_800a7e14(1, w3d_string_80373224);
            } else {
                int result;
                if (w3d_network_804abac0 && w3d_network_804abac0->session->team && (result = w3d_current_team_8021eb00(w3d_network_804abac0->session->team)) == 0) {
                    self->active = result;
                    self->locked = 1;
                    w3d_select_slot_800a7e14(2, w3d_string_80373230);
                } else {
                    self->locked = 0;
                    w3d_select_slot_800a7e14(1, 0);
                    w3d_select_slot_800a7e14(2, 0);
                }
            }
            const char *name;
            {
                PropertyKey key;
                key.name = w3d_string_80373244;
                w3d_string_property_800fc2b0(&key, &name);
            }
            const char *current = self->Current()->name;
            if (strcmp(name, w3d_string_80373260) == 0 && strcmp(current, w3d_string_80373260) == 0) {
                PropertyKey lastKey;
                int last;
                lastKey.name = w3d_string_80373268;
                w3d_int_property_800fc1f0(&lastKey, &last);
                PropertyKey activeKey;
                int active;
                activeKey.name = w3d_string_8037327c;
                w3d_int_property_800fc1f0(&activeKey, &active);
                if (last != active) w3d_set_mode_80035714(self, name, w3d_constant_803732c8[0]);
            } else {
                w3d_set_mode_80035714(self, name, w3d_constant_803732c8[0]);
            }
        } else if ((hit1 = w3d_message_id_equals_8015f65c(id, &w3d_message_804acf04)) != 0) {
            if (self->locked && (hit2 = self->active) == 0) {
                void *service = self->service;
                if (w3d_service_ready_8015ab1c(service)) {
                    w3d_service_attach_800a9620(service, self->Current());
                    w3d_mode_80032bb0(self, 19);
                    self->second.flags &= 0x007fffff;
                    float time = w3d_constant_803732c8[0];
                    InputState *state = &self->second;
                    state->time = time;
                    state->x = hit2;
                    state->y = hit2;
                    state->z = hit2;
                    self->active = 1;
                    self->second.flags &= ~0x00600000;
                } else {
                    w3d_no_target_800358b4(self);
                }
            }
        } else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acf0c)) {
            if (self->locked) self->active = hit1;
        } else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acf94)) {
            w3d_toggle_80032c84(self, 0, 0);
        } else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acf9c)) {
            w3d_toggle_80032c84(self, 1, 0);
        } else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acfa4)) {
            w3d_toggle_80032c84(self, 0, 1);
        } else if ((hit3 = w3d_message_id_equals_8015f65c(id, &w3d_message_804acf54)) != 0) {
            Object *pitching = self->pitching;
            int on = 1;
            w3d_update_value_80178d28(pitching, &on);
        } else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acf5c)) {
            int off = hit3;
            w3d_update_value_80178d28(self->pitching, &off);
        } else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acf44)) {
            if (Differs(self->Current()->name, w3d_string_8037328c))
                w3d_set_mode_80035714(self, w3d_string_8037328c, w3d_constant_803732cc[0]);
            else
                w3d_set_mode_80035714(self, w3d_string_80373260, w3d_constant_803732c8[0]);
        } else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acf1c) || w3d_message_id_equals_8015f65c(id, &w3d_message_804acf14)) {
            self->Current()->secondary->activate(self->Current());
        } else if ((hit4 = w3d_message_id_equals_8015f65c(id, &w3d_message_804acf34)) != 0) {
            w3d_set_mode_80035714(self, w3d_string_80373260, w3d_constant_803732c8[0]);
            w3d_on_800329a4(self, message);
        } else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acf3c)) {
            if (self->object804) self->object804->vtable->release(self->object804);
            self->object804 = (Object *)hit4;
            if (self->object800) self->object800->vtable->release(self->object800);
            self->object800 = (Object *)hit4;
            if (self->object796) self->object796->vtable->release(self->object796);
            self->object796 = (Object *)hit4;
        } else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acfc4)) {
            PropertyKey typeKey;
            int type;
            typeKey.name = w3d_string_80373294;
            w3d_int_property_800fc1f0(&typeKey, &type);
            PropertyKey magnitudeKey;
            float magnitude;
            magnitudeKey.name = w3d_string_803732a8;
            w3d_float_property_800fc270(&magnitudeKey, &magnitude);
            w3d_shake_set_800364d0(self->shake, type, magnitude);
        } else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acfcc)) {
            w3d_shake_apply_800368ac(self->shake, w3d_message_worm_800a830c(message));
        } else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acfec)) {
            Vec3 velocity;
            w3d_motion_velocity_800668b8(&velocity, message);
            float a = w3d_motion_a_800668fc(message);
            w3d_shake_impact_8003694c(self->shake, a, w3d_motion_b_800668dc(message), &velocity);
        } else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acfd4)) {
            w3d_play_8003591c(self, w3d_message_text_8010a8fc(message), 1);
        } else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acfdc)) {
            w3d_play_8003591c(self, w3d_message_text_8010a8fc(message), 0);
        } else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acfe4)) {
            w3d_set_mode_80035714(self, w3d_string_803732c0, w3d_constant_803732cc[0]);
        } else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acff4)) {
            w3d_set_mode_80035714(self, w3d_string_80373260, w3d_constant_803732c8[0]);
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acd84)) {
            self->first.flags |= 0x08000000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acd8c)) {
            self->first.flags &= ~0x08000000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acd94)) {
            self->first.flags |= 0x04000000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acd9c)) {
            self->first.flags &= ~0x04000000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acda4)) {
            self->first.flags |= 0x02000000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acdac)) {
            self->first.flags &= ~0x02000000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acdb4)) {
            self->first.flags |= 0x01000000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acdbc)) {
            self->first.flags &= ~0x01000000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acdc4)) {
            self->first.flags |= 0x20000000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acdcc)) {
            self->first.flags &= ~0x20000000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acdd4)) {
            self->first.flags |= 0x10000000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acddc)) {
            self->first.flags &= ~0x10000000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acde4)) {
            self->first.flags |= 0x80000000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acdec)) {
            self->first.flags &= ~0x80000000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acdf4)) {
            self->first.flags |= 0x40000000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acdfc)) {
            self->first.flags &= ~0x40000000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804ace04)) {
            int fx, fy;
            w3d_message_position_800a8334(message, &fx, &fy);
            self->first.x += fx;
            self->first.y += fy;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804ace0c)) {
            self->first.z += w3d_message_worm_800a830c(message);
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804ace14)) {
            self->first.flags |= 0x00400000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804ace1c)) {
            self->first.flags &= ~0x00400000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804ace24)) {
            self->first.flags |= 0x00200000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804ace2c)) {
            self->first.flags &= ~0x00200000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804ace34)) { }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804ace3c)) { }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804ace44)) {
            self->second.flags |= 0x08000000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804ace4c)) {
            self->second.flags &= ~0x08000000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804ace54)) {
            self->second.flags |= 0x04000000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804ace5c)) {
            self->second.flags &= ~0x04000000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804ace64)) {
            self->second.flags |= 0x02000000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804ace6c)) {
            self->second.flags &= ~0x02000000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804ace74)) {
            self->second.flags |= 0x01000000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804ace7c)) {
            self->second.flags &= ~0x01000000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804ace84)) {
            self->second.flags |= 0x20000000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804ace8c)) {
            self->second.flags &= ~0x20000000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804ace94)) {
            self->second.flags |= 0x10000000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804ace9c)) {
            self->second.flags &= ~0x10000000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acea4)) {
            self->second.flags |= 0x80000000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804aceac)) {
            self->second.flags &= ~0x80000000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804aceb4)) {
            self->second.flags |= 0x40000000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acebc)) {
            self->second.flags &= ~0x40000000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acec4)) {
            int sx, sy;
            w3d_message_position_800a8334(message, &sx, &sy);
            self->second.x += sx;
            self->second.y += sy;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acecc)) {
            self->second.z += w3d_message_worm_800a830c(message);
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804aced4)) {
            self->second.flags |= 0x00400000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acedc)) {
            self->second.flags &= ~0x00400000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acee4)) {
            self->second.flags |= 0x00200000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804aceec)) {
            self->second.flags &= ~0x00200000;
        }
        else if (w3d_message_id_equals_8015f65c(id, &w3d_message_804acef4)) { }
        else w3d_message_id_equals_8015f65c(id, &w3d_message_804acefc);
        }
        break;
    }
    return w3d_base_handler_8016293c(self, message);
}
