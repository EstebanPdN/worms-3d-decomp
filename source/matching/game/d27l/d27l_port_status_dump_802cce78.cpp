// GWMP8P rev0 0x802cce78. Port status dump: builds a text report from a
// null-terminated header table, one line per port (0..15) formatted with or
// without the port name and coloured by the connected flag, a footer and a
// terminator, then writes it through the sink's table. Two arms of the
// append cross-jump in the original. Roles are inferred from constants and
// calls; format strings are external views.
extern "C" void fn_8020c5c4(void *), fn_80341588(void *);
struct Str {
    char *p;
    Str();
    Str(const Str &);
    ~Str() {
        fn_8020c5c4(this);
        fn_80341588(this);
    }
    unsigned short len() const { return *(unsigned short *)(p - 4); }
};
extern "C" void fn_8020c510(Str *, const char *, ...);
extern "C" void fn_802cd220(Str *);
extern "C" void fn_802cd128(Str *);
extern "C" void fn_802cc0ac(Str *, const char *, int);
struct Sink;
struct SinkVt { char u[24]; int (*write)(Sink *, const char *, unsigned short, int); };
struct Sink { SinkVt *vt; };
extern int active_804abce4;
extern const char *header_80403f7c[];
extern char names_804a9d38[16][128];
extern int connected_80473724[];
extern const char *footer_804abcc0;
extern const char s_803d9460[], s_803d948c[], s_803d94ac[], s_803d94b8[];
extern "C" void d27l_port_status_dump_802cce78(Sink *self) {
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
                fn_8020c510(&line, s_803d94ac, i, names_804a9d38[i]);
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
