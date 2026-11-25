// GWMP8P rev0 0x802cc5e0. Polls connected clients: for each idle client,
// reads key characters and, for a hexadecimal digit naming a free port,
// moves the client to that port and greets it; Q says goodbye and closes it;
// any other choice re-sends the status list. Busy clients are released.
// Roles come from the digit strings, the send calls and the data strings;
// the address forms keep the original index-first indexed loads.
extern "C" void fn_8020c5c4(void *), fn_80341588(void *);
struct Str {
    char *p;
    Str();
    Str(const Str &);
    ~Str() {
        fn_8020c5c4(this);
        fn_80341588(this);
    }
};
struct Port;
struct PortVt {
    char u0[12];
    void (*addRef)(Port *);
    void (*release)(Port *);
    int (*read)(Port *, char *, int, int);
    char u24[20];
    void (*close)(Port *);
    char u48[8];
    int (*busy)(Port *);
    char u60[8];
    int (*available)(Port *);
};
struct Port { PortVt *vt; };
extern int open_804abce4, attached_804abce8;
extern const char *line_804abcb0, *line_804abcb4, *line_804abcb8, *line_804abcbc, *head_804abcd8, *tail_804abcdc;
extern Port *ports_80473724[];
extern Port *clients_80473764[];
extern int w_80403f94[];
extern int w_804a9cf8[];
extern char names_804a9d38[16][128];
extern const char lower_803d9464[], upper_803d9478[], s_803d9460[], s_803d9448[];
extern "C" char *strchr(const char *, int);
extern "C" void fn_802cc0ac(Str *, const char *, int);
extern "C" void fn_802cc01c(Port *, const char *, int);
extern "C" void fn_802cce78(Port *);
extern "C" void fn_802cd14c(int), fn_802cd07c(int), fn_802cd2e0(int, int);
extern "C" void fn_802cbdf8(int, const char *, int);
extern "C" void fn_802cbe9c(int, const char *, int);
#define CL(i) (*(Port **)(((int)(i) << 2) + (int)clients_80473764))
#define PT(i) (*(Port **)(((int)(i) << 2) + (int)ports_80473724))
inline void drop(Port *&p, Port *z) { if (p) p->vt->release(p); p = z; }
extern "C" void d28l_ports_accept_clients_802cc5e0() {
    if (open_804abce4) {
        for (unsigned i = 0; i <= 15; i++) {
            if (!CL(i)) continue;
            if (!CL(i)->vt->busy(CL(i))) {
                while (CL(i)->vt->available(CL(i))) {
                    const char *lower = lower_803d9464;
                    char ch;
                    CL(i)->vt->read(CL(i), &ch, 1, 0);
                    const char *base = lower;
                    const char *up = upper_803d9478;
                    const char *hit = strchr(lower, ch);
                    if (!hit) {
                        hit = strchr(up, ch);
                        base = up;
                        if (!hit) continue;
                    }
                    int id = hit - base;
                    if (id == 16) {
                        Port *z = 0;
                        Str s;
                        fn_802cc0ac(&s, s_803d9448, 9);
                        fn_802cc0ac(&s, line_804abcb0, 9);
                        fn_802cc0ac(&s, line_804abcb4, 9);
                        fn_802cc0ac(&s, line_804abcb8, 9);
                        fn_802cc0ac(&s, line_804abcbc, 9);
                        fn_802cc01c(CL(i), s.p, 9);
                        CL(i)->vt->close(CL(i));
                        drop(CL(i), z);
                        break;
                    }
                    const char *name = names_804a9d38[id];
                    if (name != s_803d9460) {
                        if (!PT(id)) {
                        if (CL(i)) CL(i)->vt->addRef(CL(i));
                        if (PT(id)) PT(id)->vt->release(PT(id));
                        w_804a9cf8[id] = 1;
                        PT(id) = CL(i);
                        drop(CL(i), 0);
                        w_80403f94[id] = 1;
                        fn_802cd14c(id);
                        fn_802cd07c(id);
                        fn_802cbdf8(id, head_804abcd8, 1);
                        fn_802cbe9c(id, name, 1);
                        fn_802cbdf8(id, tail_804abcdc, 9);
                        fn_802cd2e0(id, 1);
                        attached_804abce8 = 1;
                        break;
                        }
                        fn_802cce78(CL(i));
                    } else {
                        fn_802cce78(CL(i));
                    }
                }
            } else {
                Port *z = 0;
                drop(CL(i), z);
            }
        }
    }
}
