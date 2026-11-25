#include "w3d_ptr.h"
#line 1 "d28l_ports_accept_clients_802cc5e0.cpp"
// GWMP8P rev0 0x802cc5e0. Polls connected clients: for each idle client,
// reads key characters and, for a hexadecimal digit naming a free port,
// moves the client to that port and greets it; Q says goodbye and closes it;
// any other choice re-sends the status list. Busy clients are released.
// Roles come from the digit strings, the send calls and the data strings;
// the address forms keep the original index-first indexed loads.
extern "C" void fn_8020c5c4(Ptr32<void>), fn_80341588(Ptr32<void>);
struct Str {
    Ptr32<char> p;
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
    Ptr32<void (Ptr32<Port>)> addRef;
    Ptr32<void (Ptr32<Port>)> release;
    Ptr32<int (Ptr32<Port>, Ptr32<char>, int, int)> read;
    char u24[20];
    Ptr32<void (Ptr32<Port>)> close;
    char u48[8];
    Ptr32<int (Ptr32<Port>)> busy;
    char u60[8];
    Ptr32<int (Ptr32<Port>)> available;
};
struct Port { Ptr32<PortVt> vt; };
extern int open_804abce4, attached_804abce8;
extern Ptr32<const char> line_804abcb0; extern Ptr32<const char> line_804abcb4; extern Ptr32<const char> line_804abcb8; extern Ptr32<const char> line_804abcbc; extern Ptr32<const char> head_804abcd8; extern Ptr32<const char> tail_804abcdc;
extern Ptr32<Port> ports_80473724[];
extern Ptr32<Port> clients_80473764[];
extern int w_80403f94[];
extern int w_804a9cf8[];
extern char names_804a9d38[16][128];
extern const char lower_803d9464[], upper_803d9478[], s_803d9460[], s_803d9448[];
extern "C" Ptr32<char> strchr(Ptr32<const char>, int);
extern "C" void fn_802cc0ac(Ptr32<Str>, Ptr32<const char>, int);
extern "C" void fn_802cc01c(Ptr32<Port>, Ptr32<const char>, int);
extern "C" void fn_802cce78(Ptr32<Port>);
extern "C" void fn_802cd14c(int), fn_802cd07c(int), fn_802cd2e0(int, int);
extern "C" void fn_802cbdf8(int, Ptr32<const char>, int);
extern "C" void fn_802cbe9c(int, Ptr32<const char>, int);
#define CL(i) (*(Ptr32<Port> *)w3d::AG(((int)w3d::AI(i) << 2) + (int)w3d::AI(clients_80473764)))
#define PT(i) (*(Ptr32<Port> *)w3d::AG(((int)w3d::AI(i) << 2) + (int)w3d::AI(ports_80473724)))
inline void drop(Ptr32<Port> &p, Ptr32<Port> z) { if (p) p->vt->release(p); p = z; }
extern "C" void d28l_ports_accept_clients_802cc5e0() {
    if (open_804abce4) {
        for (unsigned i = 0; i <= 15; i++) {
            if (!CL(i)) continue;
            if (!CL(i)->vt->busy(CL(i))) {
                while (CL(i)->vt->available(CL(i))) {
                    Ptr32<const char> lower = lower_803d9464;
                    char ch;
                    CL(i)->vt->read(CL(i), &ch, 1, 0);
                    Ptr32<const char> base = lower;
                    Ptr32<const char> up = upper_803d9478;
                    Ptr32<const char> hit = strchr(lower, ch);
                    if (!hit) {
                        hit = strchr(up, ch);
                        base = up;
                        if (!hit) continue;
                    }
                    int id = hit - base;
                    if (id == 16) {
                        Ptr32<Port> z = 0;
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
                    Ptr32<const char> name = names_804a9d38[id];
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
                Ptr32<Port> z = 0;
                drop(CL(i), z);
            }
        }
    }
}


