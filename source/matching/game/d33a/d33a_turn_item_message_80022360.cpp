// GWMP8P rev0 0x80022360. Message handler of an object that keeps a queue of
// turn items: ids 64 and 66 have fixed follow-ups, three cached ids act on
// the first queued item, and the third can finish the item, which posts
// motion messages and two local actions. Names are inferred from the
// original instructions.
extern char t_8040dbe8[], t_8040dcc8[];
extern const char s_8036c464[];
struct Table { char pad[12]; void (*f0c)(void *); char pad2[4]; void (*run)(void *); };
struct Item { char pad[12]; int kind; Table *t; int **info; };
struct Msg { unsigned short id; };
struct Motion { char pad[8]; int kind; };
struct Action;
extern "C" void s19_dtor_80021468(Action *, int);
struct Action {
    int pad; int a; int b; int c; Table *t; const char *name;
    Action(int mode, int zero) {
        name = s_8036c464;
        c = 15;
        b = mode;
        a = zero;
        t = (Table *)t_8040dbe8;
    }
    Action(int zero) {
        a = zero;
        c = 7;
        b = 1;
        t = (Table *)t_8040dcc8;
    }
    ~Action() { s19_dtor_80021468(this, 0); }
    void Run() { t->run(this); }
};
struct Team { char pad[48]; int mode; };
struct Game { char pad[312]; int cur; Team **teams; Team *Cur() { return *(Team **)((char *)teams + (cur << 2)); } };
extern Game *g_804aa8c8;
extern void *g_arena_804b1754;
extern int g_804aa6e0, g_804aa6e4;
extern unsigned short id_804aca30, id_804aca28, id_804aca38;
struct Self { char pad[28]; Item **first; Item **last; };
extern "C" int w3d_auto_8015fb34(Self *, Msg *);
extern "C" int w3d_message_id_equals_cache(unsigned short, unsigned short *);
extern "C" void w3d_auto_80022964(Self *);
extern "C" void w3d_auto_800229ec(Self *);
extern "C" void w3d_auto_80022634(Self *);
extern "C" void *tsonnet_b33_arena_801613f0(void *, int);
extern "C" Motion *w3d_motion_message_construct_80131a84(void *);
extern "C" int w3d_message_post_current(Motion *);
extern "C" int w3d_d33a_turn_item_message_80022360(Self *self, Msg *msg)
{
    switch (msg->id) {
    case 64:
        if (w3d_auto_8015fb34(self, msg) >= 0) {
            w3d_auto_80022964(self);
            return 0;
        }
        return 0x80004005;
    case 66:
        w3d_auto_800229ec(self);
        return w3d_auto_8015fb34(self, msg);
    default:
        if (w3d_message_id_equals_cache(msg->id, &id_804aca30)) {
            if (self->last - self->first) {
                Item *i = *self->first;
                if (i->kind == 14) i->t->f0c(i);
            }
        }
        if (w3d_message_id_equals_cache(msg->id, &id_804aca28)) {
            if (self->last - self->first) {
                Item *i = *self->first;
                i->t->f0c(i);
            }
        }
        if (w3d_message_id_equals_cache(msg->id, &id_804aca38)) {
            if (self->last - self->first) {
                Item *i = *self->first;
                bool done = false; int flag = 0;
                if (i->kind == 5) {
                    int v = **i->info;
                    switch (v) {
                    case 0: case 3: case 4: case 5:
                        done = true; flag = 1;
                        break;
                    case 7: case 9: case 10:
                        if (v == 7) {
                            Motion *m = w3d_motion_message_construct_80131a84(tsonnet_b33_arena_801613f0(g_arena_804b1754, 236));
                            m->kind = 17;
                            w3d_message_post_current(m);
                        }
                        done = true;
                        break;
                    case 1:
                        i->t->f0c(i);
                        break;
                    case 2:
                        break;
                    }
                } else {
                    done = true; flag = 1;
                }
                if (done) {
                    if (flag) g_804aa6e0 = 1;
                    else g_804aa6e4 = 1;
                    flag = 0;
                    w3d_auto_80022634(self);
                    Motion *m = w3d_motion_message_construct_80131a84(tsonnet_b33_arena_801613f0(g_arena_804b1754, 236));
                    m->kind = flag;
                    w3d_message_post_current(m);
                    int mode = g_804aa8c8->Cur()->mode;
                    if (mode == 1) {
                        Action a(mode, flag);
                        a.Run();
                    }
                    {
                        Action a(flag);
                        a.Run();
                    }
                }
            }
        }
        break;
    }
    return w3d_auto_8015fb34(self, msg);
}
