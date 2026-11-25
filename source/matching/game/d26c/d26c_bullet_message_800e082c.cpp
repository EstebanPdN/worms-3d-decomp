// d26c: 0x800e082c. Message handler of a bullet: start on id 64, stop on id 66, react to the four cached ids, then hand
// the message to the base handler. Names are inferred.
struct Message { unsigned short id; unsigned short Id() const { return id; } };
struct Desc { char u0[460]; int auto_detonate; };
struct Bullet {
    char u0[28];
    int link;
    char u32[16];
    int w48;
    char u52[80];
    int owner_id;
    char u136[20];
    void *h156;
    char u160[16];
    int state;
};
extern "C" int base_8015fb34(Bullet *, Message *);
extern "C" void start_800e1420(Bullet *);
extern "C" void stop_800e1cbc(Bullet *);
extern "C" int id_equals_8015f65c(unsigned, int *);
extern "C" int value_80125ff8(Message *);
extern "C" void *empty_80341584(void *);
extern "C" Desc *desc_801797b4(void *);
extern "C" int link_800dfd8c(int *);
extern int id_804aece0, id_804aed00, id_804aece8, id_804aecf0;
extern "C" int d26c_bullet_message_800e082c(Bullet *self, Message *m) {
    unsigned short id = m->Id();
    switch (id) {
    case 64:
        if (base_8015fb34(self, m) >= 0) {
            start_800e1420(self);
            return 0;
        }
        return 0x80004005;
    case 66:
        stop_800e1cbc(self);
        return base_8015fb34(self, m);
    default:
        if (id_equals_8015f65c(id, &id_804aece0)) {
            if (value_80125ff8(m) == self->owner_id) self->state = 3;
        } else if (id_equals_8015f65c(id, &id_804aed00)) {
            if (desc_801797b4(empty_80341584(self->h156))->auto_detonate && self->link == 0 && link_800dfd8c(&self->link))
                self->state = 3;
        } else {
            int hit = id_equals_8015f65c(id, &id_804aece8);
            if (hit) {
                if (value_80125ff8(m) == self->owner_id) self->state = 1;
            } else if (id_equals_8015f65c(id, &id_804aecf0) && value_80125ff8(m) == self->owner_id) {
                self->w48 = 0;
                self->state = 0;
            }
        }
        break;
    }
    return base_8015fb34(self, m);
}
