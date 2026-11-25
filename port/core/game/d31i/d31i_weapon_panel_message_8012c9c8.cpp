#include "w3d_ptr.h"
#line 1 "d31i_weapon_panel_message_8012c9c8.cpp"
// d31i: 0x8012c9c8. Weapon panel message handler: init and refresh messages,
// camera mode and turn messages, the Cow.Fall sound, weapon rows 0 to 11 and
// selection posts.
struct Vec3 { float x, y, z; Vec3() {} Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; } };
struct Key { Ptr32<const char> name; };
struct Message { unsigned short id; unsigned short Id() const { return id; } };
struct Item { unsigned char unknown00[60]; Ptr32<const char> kind; };
struct Stack { unsigned char unknown00[312]; int top; Ptr32<Ptr32<Item>> items; };
struct Descriptor_80178474 {
    Ptr32<void> value;
    unsigned tag;
    Descriptor_80178474() : value(0), tag(58280) {}
    ~Descriptor_80178474();
};
struct Camera;
struct CameraVt { unsigned char unknown00[56]; Ptr32<Ptr32<const Vec3> (Ptr32<Camera>)> position; };
struct Camera { Ptr32<CameraVt> vt; };
struct Audio;
struct AudioVt { unsigned char unknown00[96]; Ptr32<void (Ptr32<Audio>, Ptr32<const char>, Ptr32<Vec3>)> play; };
struct Audio { Ptr32<AudioVt> vt; };
struct Service { unsigned char unknown00[48]; Ptr32<Camera> camera; unsigned char unknown34[56]; Ptr32<Audio> audio; };
struct Target { unsigned char unknown00[132]; int weapon; };
struct Context { unsigned char unknown00[52]; int time; };
struct Panel {
    unsigned char unknown00[28];
    Ptr32<void> o28;
    unsigned char unknown20[40];
    int ready;              // +72
    int created;            // +76
    unsigned char b80;      // +80
    unsigned char b81;      // +81
};
struct Posted { unsigned short id; Ptr32<void> vt; };
extern "C" int base_8015fb34(Ptr32<Panel>, Ptr32<Message>);
extern "C" void init_8012d0a4(Ptr32<Panel>);
extern "C" void refresh_8012d894(Ptr32<Panel>);
extern "C" int eq_8015f65c(unsigned, Ptr32<int>);
extern "C" int read_uint_800fc230(Ptr32<Key>, Ptr32<int>);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" int inner_80178c48(Ptr32<void>);
extern "C" int message_id_8015f5a0(Ptr32<void>, int);
extern "C" int get_800a830c(Ptr32<Message>);
extern "C" Ptr32<Context> context_80165254();
extern "C" void post16_800f90e8(int, int, int);
extern "C" Ptr32<Target> target_800fc710(int, Ptr32<Descriptor_80178474>);
extern "C" Ptr32<void> arena_801613f0(Ptr32<void>, int);
extern "C" int post_8016239c(Ptr32<void>);
extern "C" void select_8012c7cc(Ptr32<Panel>, unsigned);
extern "C" void finish_8012f77c(Ptr32<Panel>);
extern Ptr32<void> arena_804b1754;
extern Ptr32<Service> service_804b1788;
extern Ptr32<Stack> stack_804aa8c8;
extern Ptr32<void> vt_8040db38[];
extern int id_804af724, id_804af63c, id_804af644, id_804af64c, id_804af624, id_804af69c, id_804af61c, id_804af67c, id_804af684, id_804af62c, id_804af654, id_804af65c, id_804af66c;
extern int id_804af6b4;
extern int id_804af6bc;
extern int id_804af6c4;
extern int id_804af6cc;
extern int id_804af6d4;
extern int id_804af6dc;
extern int id_804af6e4;
extern int id_804af6ec;
extern int id_804af6f4;
extern int id_804af6fc;
extern int id_804af704;
extern int id_804af70c;
extern const char s_8039d9b4[], s_8039d9c8[], s_8039d9d4[];
extern "C" int d31i_weapon_panel_message_8012c9c8(Ptr32<Panel> self, Ptr32<Message> m) {
    unsigned short id = m->Id();
    switch (m->Id()) {
    case 64:
        if (base_8015fb34(self, m) < 0) goto fail;
        init_8012d0a4(self);
        goto done;
    case 66:
        if (base_8015fb34(self, m) >= 0) {
            refresh_8012d894(self);
            goto done;
        }
    fail:
        return 0x80004005;
    }
    if (eq_8015f65c(id, &id_804af724)) {
        Key k = {s_8039d9b4};
        int mode;
        read_uint_800fc230(&k, &mode);
        if (mode != 14) goto done;
        goto bump;
    }
    int a;
    a = eq_8015f65c(id, &id_804af63c);
    if (a) goto ready;
    if (eq_8015f65c(id, &id_804af644)) {
        self->ready = a;
        self->b81++;
        goto done;
    }
    if (eq_8015f65c(id, &id_804af64c)) {
    ready:
        self->ready = 1;
        goto done;
    }
    if (eq_8015f65c(id, &id_804af624)) goto bump;
    if (eq_8015f65c(id, &id_804af69c)) {
        Vec3 v(*service_804b1788->camera->vt->position(service_804b1788->camera));
        v.z += 10.0f;
        service_804b1788->audio->vt->play(service_804b1788->audio, s_8039d9c8, &v);
        goto done;
    }
    if (eq_8015f65c(id, &id_804af61c)) {
        {
            Ptr32<Stack> st = stack_804aa8c8;
            bool path = strcmp((*(Ptr32<Ptr32<Item>>)((Ptr32<char>)st->items + (st->top << 2)))->kind, s_8039d9d4) == 0;
            if (self->created == 0 && self->ready != 0 && !path) {
                if (inner_80178c48(self->o28) >= 0) self->b80++;
                goto done;
            }
        }
    bump:
        if (self->created) self->b81++;
        goto done;
    }
    a = eq_8015f65c(id, &id_804af67c);
    if (a) {
        int pid = (unsigned short)message_id_8015f5a0(&id_804af684, 1);
        int v = get_800a830c(m);
        post16_800f90e8(pid, v, context_80165254()->time + 10);
        goto done;
    }
    if (eq_8015f65c(id, &id_804af684)) {
        Descriptor_80178474 d;
        Ptr32<Target> t = target_800fc710(inner_80178c48(self->o28), &d);
        t->weapon = get_800a830c(m);
        Ptr32<Posted> p = (Ptr32<Posted>)arena_801613f0(arena_804b1754, 8);
        p->id = message_id_8015f5a0(&id_804af62c, 1);
        p->vt = vt_8040db38;
        post_8016239c(p);
        self->b81++;
        goto done;
    }
    if (eq_8015f65c(id, &id_804af6b4)) { select_8012c7cc(self, 0); goto done; }
    if (eq_8015f65c(id, &id_804af6bc)) { select_8012c7cc(self, 1); goto done; }
    if (eq_8015f65c(id, &id_804af6c4)) { select_8012c7cc(self, 2); goto done; }
    if (eq_8015f65c(id, &id_804af6cc)) { select_8012c7cc(self, 3); goto done; }
    if (eq_8015f65c(id, &id_804af6d4)) { select_8012c7cc(self, 4); goto done; }
    if (eq_8015f65c(id, &id_804af6dc)) { select_8012c7cc(self, 5); goto done; }
    if (eq_8015f65c(id, &id_804af6e4)) { select_8012c7cc(self, 6); goto done; }
    if (eq_8015f65c(id, &id_804af6ec)) { select_8012c7cc(self, 7); goto done; }
    if (eq_8015f65c(id, &id_804af6f4)) { select_8012c7cc(self, 8); goto done; }
    if (eq_8015f65c(id, &id_804af6fc)) { select_8012c7cc(self, 9); goto done; }
    if (eq_8015f65c(id, &id_804af704)) { select_8012c7cc(self, 10); goto done; }
    if (eq_8015f65c(id, &id_804af70c)) { select_8012c7cc(self, 11); goto done; }
    if (eq_8015f65c(id, &id_804af654)) {
        if (self->created) {
            Ptr32<Posted> p = (Ptr32<Posted>)arena_801613f0(arena_804b1754, 8);
            p->id = message_id_8015f5a0(&id_804af65c, 1);
            p->vt = vt_8040db38;
            post_8016239c(p);
        }
        goto done;
    }
    if (!eq_8015f65c(id, &id_804af66c)) return base_8015fb34(self, m);
    if (self->created) finish_8012f77c(self);
done:
    return 0;
}


