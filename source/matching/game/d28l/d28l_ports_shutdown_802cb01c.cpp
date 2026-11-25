// GWMP8P rev0 0x802cb01c. Port shutdown: if open, for each of the sixteen
// ports and client slots, sends any idle connection a four-line closing
// message, releases its handles and clears its entries, then releases the
// listener and clears the open flag. Roles are inferred from the release and
// send calls.
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
struct PortVt { char u0[16]; void (*release)(Port *); char u20[36]; int (*busy)(Port *); };
struct Port { PortVt *vt; };
extern int open_804abce4;
extern const char *line_804abcb0, *line_804abcb4, *line_804abcb8, *line_804abcbc;
extern Port *ports_80473724[];
extern Port *ports_804738a4[];
extern int w_80403f94[];
extern int w_804a9cf8[];
extern Port *clients_80473764[];
extern Port *clients_804738e4[];
extern Port *listener_804b10b0;
extern "C" void fn_802cd14c(unsigned), fn_802cd07c(unsigned);
extern "C" void fn_802cc0ac(Str *, const char *, int);
extern "C" void fn_802cbdf8(unsigned, const char *, int);
extern "C" void fn_802cd198(Port *), fn_802cd0c8(Port *);
extern "C" void fn_802cc01c(Port *, const char *, int);
inline void drop(Port *&p, Port *z) { if (p) p->vt->release(p); p = z; }
extern "C" void d28l_ports_shutdown_802cb01c() {
    if (open_804abce4) {
        for (unsigned i = 0; i <= 15; i++) {
            if (ports_80473724[i] && !ports_80473724[i]->vt->busy(ports_80473724[i])) {
                fn_802cd14c(i);
                fn_802cd07c(i);
                Str s;
                fn_802cc0ac(&s, line_804abcb0, 1);
                fn_802cc0ac(&s, line_804abcb4, 1);
                fn_802cc0ac(&s, line_804abcb8, 1);
                fn_802cc0ac(&s, line_804abcbc, 1);
                fn_802cbdf8(i, s.p, 1);
            }
            Port *z = 0;
            drop(ports_80473724[i], z);
            drop(ports_804738a4[i], z);
            drop(ports_80473724[i], z);
            drop(ports_804738a4[i], z);
            w_804a9cf8[i] = 0;
            w_80403f94[i] = 0;
        }
        for (unsigned i = 0; i <= 15; i++) {
            if (clients_80473764[i] && !clients_80473764[i]->vt->busy(clients_80473764[i])) {
                fn_802cd198(clients_80473764[i]);
                fn_802cd0c8(clients_80473764[i]);
                Str s;
                fn_802cc0ac(&s, line_804abcb0, 1);
                fn_802cc0ac(&s, line_804abcb4, 1);
                fn_802cc0ac(&s, line_804abcb8, 1);
                fn_802cc0ac(&s, line_804abcbc, 1);
                fn_802cc01c(clients_80473764[i], s.p, 9);
            }
            Port *z = 0;
            drop(clients_80473764[i], z);
            drop(clients_804738e4[i], z);
        }
        drop(listener_804b10b0, 0);
        drop(listener_804b10b0, 0);
        open_804abce4 = 0;
    }
}
