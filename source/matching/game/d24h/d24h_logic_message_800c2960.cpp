// Weapon logic message handler (Worms 3D GameCube PAL, 0x800c2960, 520 bytes).
//
// Field and message names are inferred. The id is read twice through the
// inline accessor, which gives the original's copy before the switch.

struct Arena;
extern Arena *lbl_804b1754;
extern "C" void *fn_801613f0(Arena *, unsigned);
struct Cache { unsigned short id; unsigned char u[6]; };
extern Cache lbl_804ae6ec, lbl_804ae6fc, lbl_804ae74c, lbl_804ae734, lbl_804ae6dc, lbl_804ae724;
extern "C" int fn_8015f5a0(Cache *, int);
extern "C" int fn_8016239c(void *);
extern "C" int fn_8015f65c(unsigned short, Cache *);
extern void *lbl_8040db38[];
struct Message { unsigned short id; void *vt; };
struct IdMessage { unsigned short id; unsigned short Id() const { return id; } };
struct Weapon;
struct WeaponVt { void *u[9]; int (*ready)(Weapon *); };
struct Weapon { WeaponVt *vt; };
struct Logic {
    unsigned char u0[28];
    void *owner;
    int state;
    unsigned char u36[4];
    Weapon *weapon;
    unsigned char u44[28];
    int time;
};
struct Info { unsigned char u[56]; int delay; };
struct Engine { unsigned char u[52]; int now; };
extern "C" int fn_8015fb34(Logic *, IdMessage *);
extern "C" int w3d_d24b_weapon_aim_start_800c2e44(Logic *);
extern "C" void fn_800c31f0(Logic *);
extern "C" int fn_800c3cf4(Logic *);
extern "C" void *fn_80341584(void *);
extern "C" Info *fn_801797b4(void *);
extern "C" Engine *fn_80165254();
extern "C" void fn_8015fd1c(Logic *);
inline void Post(Cache *c) {
    Message *m = (Message *)fn_801613f0(lbl_804b1754, 8);
    m->id = fn_8015f5a0(c, 1);
    m->vt = lbl_8040db38;
    fn_8016239c(m);
}
extern "C" int w3d_d24h_logic_message_800c2960(Logic *self, IdMessage *msg) {
    unsigned short id = msg->Id();
    switch (msg->Id()) {
    case 64:
        if (fn_8015fb34(self, msg) >= 0) {
            w3d_d24b_weapon_aim_start_800c2e44(self);
            goto done;
        }
        return 0x80004005;
    case 66:
        if (self->state != 0) Post(&lbl_804ae6ec);
        fn_800c31f0(self);
        break;
    default:
        if (fn_8015f65c(id, &lbl_804ae6fc)) {
            if (fn_800c3cf4(self) == 0) goto done;
            if (self->state == 0) {
                Post(&lbl_804ae74c);
                Post(&lbl_804ae734);
                Info *info = fn_801797b4(fn_80341584(self->owner));
                self->time = fn_80165254()->now + info->delay;
                self->state = 1;
            }
        } else if (fn_8015f65c(id, &lbl_804ae6dc)) {
            if (self->weapon && self->weapon->vt->ready(self->weapon)) self->state = 5;
            else { fn_8015fd1c(self); }
        } else if (fn_8015f65c(id, &lbl_804ae724)) {
            if (self->state == 3) self->state = 4;
        }
        break;
    }
    return fn_8015fb34(self, msg);
done:
    return 0;
}
