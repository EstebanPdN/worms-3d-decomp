// d24c: 0x800e37c0 (432 bytes). Message handler of the particle emitter. Message 64:
// forward to the base and start on success, or return 0x80004005. Message 66: release
// held objects, then forward. First cached id: when the value is this owner, state 3.
// Second: when enabled and not yet transplanted, transplant (state 3 on success), and
// in mode 3 post each mesh item. Third: for settings kinds 2 and 3 clear the 16-word
// table at +284. Everything else forwards to the base. Names are inferred.
struct Message { unsigned short id; };
struct Settings {
    unsigned char u0[320];
    int kind;           // +320
    unsigned char u324[56];
    int mode;           // +380
    unsigned char u384[76];
    int enabled;        // +460
};
struct Mesh { struct V { void *u[5]; void *(*item)(Mesh *, unsigned); } *vtable; };
struct Emitter {
    unsigned char u0[28];
    int transplant;     // +28
    Mesh *mesh;         // +32
    unsigned char u36[96];
    int owner;          // +132
    unsigned char u136[4];
    unsigned count;     // +140
    unsigned char u144[12];
    void *resource;     // +156
    unsigned char u160[16];
    int state;          // +176
    unsigned char u180[104];
    int table[16];      // +284
};
extern "C" int base_8015fb34(Emitter *, Message *);
extern "C" void start_800e3e8c(Emitter *);
extern "C" void stop_800e41d8(Emitter *);
extern "C" int id_equals_8015f65c(unsigned short, int *);
extern "C" int value_80125ff8(Message *);
extern "C" void *identity_80341584(void *);
extern "C" Settings *settings_801797b4(void *);
extern "C" int transplant_800dfd8c(int *);
extern "C" void post_800de7f0(void *);
extern int a_804aed44, b_804aed4c, c_804aed6c;
extern "C" int d24c_emitter_handle_message_800e37c0(Emitter *self, Message *m) {
    unsigned short id = m->id;
    switch (id) {
    case 64:
        if (base_8015fb34(self, m) >= 0) {
            start_800e3e8c(self);
            return 0;
        }
        return 0x80004005;
    case 66:
        stop_800e41d8(self);
        break;
    default:
        if (id_equals_8015f65c(id, &a_804aed44)) {
            if (value_80125ff8(m) == self->owner) self->state = 3;
        } else if (id_equals_8015f65c(id, &b_804aed4c)) {
            Settings *s = settings_801797b4(identity_80341584(self->resource));
            if (s->enabled && self->transplant == 0 && transplant_800dfd8c(&self->transplant))
                self->state = 3;
            if (s->mode == 3) {
                for (unsigned i = 0; i < self->count; i++)
                    post_800de7f0(self->mesh->vtable->item(self->mesh, i));
            }
        } else if (id_equals_8015f65c(id, &c_804aed6c)) {
            switch (settings_801797b4(identity_80341584(self->resource))->kind) {
            case 2:
            case 3:
                for (int i = 15; i >= 0; i--) self->table[i] = 0;
                break;
            }
        }
        break;
    }
    return base_8015fb34(self, m);
}
