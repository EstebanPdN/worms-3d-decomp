#include "w3d_ptr.h"
#line 1 "d27l_port_status_dump_802cce78.cpp"
// GWMP8P rev0 0x802cce78. Port status dump: builds a text report from a
// null-terminated header table, one line per port (0..15) formatted with or
// without the port name and coloured by the connected flag, a footer and a
// terminator, then writes it through the sink's table. Two arms of the
// append cross-jump in the original. Roles are inferred from constants and
// calls; format strings are external views.
extern "C" void fn_8020c5c4(Ptr32<void>), fn_80341588(Ptr32<void>);
struct Str {
    Ptr32<char> p;
    Str();
    Str(const Str &);
    ~Str() {
        fn_8020c5c4(this);
        fn_80341588(this);
    }
    unsigned short len() const { return *(Ptr32<unsigned short>)(p - 4); }
};
extern "C" void fn_8020c510(Ptr32<Str>, Ptr32<const char>, ...);
extern "C" void fn_802cd220(Ptr32<Str>);
extern "C" void fn_802cd128(Ptr32<Str>);
extern "C" void fn_802cc0ac(Ptr32<Str>, Ptr32<const char>, int);
struct Sink;
struct SinkVt { char u[24]; Ptr32<int (Ptr32<Sink>, Ptr32<const char>, unsigned short, int)> write; };
struct Sink { Ptr32<SinkVt> vt; };
extern int active_804abce4;
extern Ptr32<const char> header_80403f7c[];
extern char names_804a9d38[16][128];
extern int connected_80473724[];
extern Ptr32<const char> footer_804abcc0;
extern const char s_803d9460[], s_803d948c[], s_803d94ac[], s_803d94b8[];
extern "C" void d27l_port_status_dump_802cce78(Ptr32<Sink> self) {
    if (active_804abce4) {
        Str out;
        fn_802cd220(&out);
        fn_802cd128(&out);
        int n = 0; while (header_80403f7c[n]) { fn_802cc0ac(&out, header_80403f7c[n++], 1); }
        for (unsigned i = 0; i <= 15; i++) {
            Str line;
            if (names_804a9d38[i] == s_803d9460) {
                fn_8020c510(&line, s_803d948c, i);
                fn_802cc0ac(&out, line.p, 8);
            } else {
                fn_8020c510(&line, s_803d94ac, i, w3d::VA(names_804a9d38[i]));
                if (connected_80473724[i])
                    fn_802cc0ac(&out, line.p, 8);
                else
                    fn_802cc0ac(&out, line.p, 7);
            }
        }
        fn_802cc0ac(&out, footer_804abcc0, 7);
        fn_802cc0ac(&out, s_803d94b8, 9);
        self->vt->write(self, out.p, out.len(), 0);
    }
}


