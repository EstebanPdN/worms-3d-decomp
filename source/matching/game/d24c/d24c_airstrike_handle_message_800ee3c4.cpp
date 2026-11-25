// d24c: 0x800ee3c4 (620 bytes). Message handler of the airstrike logic. Message 64:
// forward to the base and initialise on success, or return 0x80004005. Message 66: stop,
// then forward. First cached id, when the actor is not restricted: in state 0 enter state
// 2 and finish; in state 1 either post the targeting message and, per settings, post a
// target-id message (state 0) or finish, then optionally create and register the +464
// entity (state 2), or post the no-target message. Three more ids call finish, activate
// and countdown; the last removes the entity. Others forward to the base. Names are
// inferred. The empty case 2 gives the original's compare tree.
struct Message { unsigned short id; };
struct Settings { unsigned char u0[464]; int w464; unsigned char u468[36]; int w504; };
struct Strike {
    unsigned char u0[20];
    int id;            // +20
    unsigned char u24[4];
    void *resource;    // +28
    unsigned char u32[20];
    int state;         // +52
};
extern "C" int base_8015fb34(Strike *, Message *);
extern "C" void init_800ee638(Strike *);
extern "C" void stop_800ef614(Strike *);
extern "C" int id_equals_8015f65c(unsigned short, int *);
extern "C" int restricted_800ef788(Strike *);
extern "C" void finish_800ee934(Strike *);
extern "C" int target_800ef680(Strike *);
extern "C" void *identity_80341584(void *);
extern "C" Settings *settings_801797b4(void *);
extern "C" void *arena_801613f0(void *, int);
extern "C" short message_id_8015f5a0(int *, int);
extern "C" int post_8016239c(void *);
extern "C" void *msg_init_801190b4(void *, unsigned short, int);
extern "C" void *forward_8020b680(const void *);
extern "C" int fn_80164514(void *, void *, int);
extern "C" void activate_800eeadc(Strike *);
extern "C" void countdown_800eebf8(Strike *);
extern "C" void remove_8015fd1c(Strike *);
extern void *arena_804b1754;
extern void *service_804b178c;
extern const unsigned char message_vtable_8040db38[];
extern const unsigned char key_80410318[];
extern int a_804aef6c, b_804aef64, c_804aefac, d_804aeff4, e_804aef5c, m1_804aefc4, m2_804aef94, m3_804aef84;
struct Simple { short id; const void *vtable; };
inline void post_simple(int *cache) {
    Simple *m = (Simple *)arena_801613f0(arena_804b1754, 8);
    m->id = message_id_8015f5a0(cache, 1);
    m->vtable = message_vtable_8040db38;
    post_8016239c(m);
}
extern "C" int d24c_airstrike_handle_message_800ee3c4(Strike *self, Message *m) {
    unsigned short id = m->id;
    switch (id) {
    case 64:
        if (base_8015fb34(self, m) >= 0) {
            init_800ee638(self);
            goto handled;
        }
        return 0x80004005;
    case 66:
        stop_800ef614(self);
        break;
    default:
        if (id_equals_8015f65c(id, &a_804aef6c)) {
            if (restricted_800ef788(self)) {
                switch (self->state) {
                case 0:
                    self->state = 2;
                    finish_800ee934(self);
                    break;
                case 1:
                    if (target_800ef680(self)) {
                        Settings *s = settings_801797b4(identity_80341584(self->resource));
                        post_simple(&m1_804aefc4);
                        if (s->w504) {
                            void *t = arena_801613f0(arena_804b1754, 12);
                            post_8016239c(msg_init_801190b4(t, message_id_8015f5a0(&m2_804aef94, 1), self->id));
                            self->state = 0;
                        } else {
                            finish_800ee934(self);
                        }
                        if (s->w464) {
                            void *e = forward_8020b680(key_80410318);
                            fn_80164514(service_804b178c, e, self->id);
                            self->state = 2;
                        }
                    } else {
                        post_simple(&m3_804aef84);
                    }
                    break;
                case 2:
                    break;
                }
            }
            goto handled;
        }
        if (id_equals_8015f65c(id, &b_804aef64)) {
            finish_800ee934(self);
            goto handled;
        }
        if (id_equals_8015f65c(id, &c_804aefac)) {
            activate_800eeadc(self);
            goto handled;
        }
        if (id_equals_8015f65c(id, &d_804aeff4)) {
            countdown_800eebf8(self);
            goto handled;
        }
        if (id_equals_8015f65c(id, &e_804aef5c)) goto done;
        break;
    }
    return base_8015fb34(self, m);
done:
    remove_8015fd1c(self);
handled:
    return 0;
}
