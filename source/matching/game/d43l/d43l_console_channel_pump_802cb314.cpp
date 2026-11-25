// GWMP8P rev0 0x802cb314. Per-frame service for one console channel: sends a
// periodic ping, closes a dead input stream, moves pending bytes from the
// input stream into the ring buffer, echoes them with carriage returns
// expanded, cuts complete lines out of the ring and appends them to the
// channel's line list.
#include "compat/stlport_sn_oom.h"
#include <vector>
struct Str;
extern "C" void fn_8020c5c0(Str *), fn_8020c5c4(Str *), fn_80341588(Str *);
extern "C" unsigned short *fn_80341884(Str *);
extern "C" void fn_803426b8(void *);
struct Str {
    char *p;
    Str(int) {}
    Str(const char *);
    Str(const Str &o) { fn_8020c5c0(this); p = o.p; ++*fn_80341884(this); }
    ~Str() { Str *u = this; fn_8020c5c4(u); fn_80341588(u); }
    Str &operator=(const Str &);
};
struct Stream;
struct StreamVt {
    char u0[16];
    void (*destroy)(Stream *);
    int (*read)(Stream *, void *, unsigned, int);
    int (*write)(Stream *, const void *, unsigned, int);
    int (*put)(Stream *, const void *, unsigned, int);
    void (*lock)(Stream *, char **, unsigned *, char **, unsigned *);
    void (*skip)(Stream *, unsigned, int);
    char u40[12];
    unsigned (*room)(Stream *);
    int (*closed)(Stream *);
    char u60[8];
    unsigned (*avail)(Stream *);
};
struct Stream { StreamVt *vt; };
extern int count_804abcf0, tick_804abcec, on_804abce4, dirty_804abce8;
extern char ping_804b1960[8];
extern Stream *in_80473724[], *ping_80473764[], *out_804738a4[];
extern int b_804a9cf8[], a_80403f94[];
extern char buf_80473924[];
extern char nl_803d9178[];
extern void *t_804abcc8, *t_804abccc, *t_804abcd0;
extern std::vector<Str> lines_804737a4[];
extern "C" {
unsigned strlen(const char *);
void *memchr(const void *, int, unsigned);
void *memcpy(void *, const void *, unsigned);
void fn_802cc3d0(char *);
void fn_802cc0ac(Str *, void *, int);
void fn_802cbdf8(unsigned, const char *, int);
}
inline const unsigned &mn(const unsigned &a, const unsigned &b) { return b < a ? b : a; }
inline void write(Stream **t, int j, const char *p, unsigned m) {
    (*(Stream **)(j + (int)t))->vt->write(*(Stream **)(j + (int)t), p, m, 0);
}
#define AT(k, t) (*(Stream **)((ch << 2) + (int)(t)))
extern "C" void d43l_console_channel_pump_802cb314(unsigned ch) {
    if (--count_804abcf0 == 0) {
        Stream **tb = in_80473724;
        int v = ++tick_804abcec;
        count_804abcf0 = 100;
        Stream *s = tb[v & 15];
        if (s) s->vt->write(s, ping_804b1960, strlen(ping_804b1960), 0);
        s = ping_80473764[tick_804abcec & 15];
        if (s) s->vt->write(s, ping_804b1960, strlen(ping_804b1960), 0);
    }
    if (!on_804abce4 || ch > 15) return;
    Stream **t0 = in_80473724;
    Stream *cur = t0[ch];
    if (cur && cur->vt->closed(cur)) {
        Stream *nul = 0;
        if (AT(k, t0)) AT(k, t0)->vt->destroy(AT(k, t0));
        AT(k, t0) = nul;
        b_804a9cf8[ch] = (int)nul;
        a_80403f94[ch] = (int)nul;
        dirty_804abce8 = 1;
    }
    Stream **in = in_80473724;
    if (!AT(k, in)) return;
    unsigned room = AT(k, out_804738a4)->vt->room(AT(k, out_804738a4));
    unsigned avail = AT(k, in)->vt->avail(AT(k, in));
    unsigned n = mn(room, avail);
    n = mn(n, 256);
    AT(k, in)->vt->read(AT(k, in), buf_80473924, n, 0);
    char *a, *b;
    unsigned la, lb;
    unsigned left = n;
    char *c = (char *)memchr(buf_80473924, 13, left);
    char *p = buf_80473924;
    if (c) {
    do {
        unsigned m = c - p + 1;
        write(in_80473724, ch << 2, p, m);
        left -= m;
        p = c + 1;
        write(in_80473724, ch << 2, nl_803d9178, 1);
        c = (char *)memchr(p, 13, left);
    } while (c);
    }
    AT(k, in_80473724)->vt->write(AT(k, in_80473724), p, left, 0);
    int line = 0, got = 0;
    AT(k, out_804738a4)->vt->put(AT(k, out_804738a4), buf_80473924, n, 0);
    AT(k, out_804738a4)->vt->lock(AT(k, out_804738a4), &a, &la, &b, &lb);
    if (la && (c = (char *)memchr(a, 13, la))) {
        got = 1;
        line = c - a;
    }
    if (!line && lb && (c = (char *)memchr(b, 13, lb))) {
        got = 1;
        line = (c + la) - b;
    }
    int flag = 0;
    if (!line && !AT(k, out_804738a4)->vt->room(AT(k, out_804738a4))) {
        flag = 1;
        AT(k, out_804738a4)->vt->skip(AT(k, out_804738a4), la + lb, 0);
    }
    if (got) {
        AT(k, out_804738a4)->vt->lock(AT(k, out_804738a4), &a, &la, &b, &lb);
        AT(k, out_804738a4)->vt->skip(AT(k, out_804738a4), line + 1, 0);
        if (la > 255) {
            la = 255;
            lb = 0;
            flag = 1;
        } else if (la + lb > 255) {
            lb = 255 - la;
            flag = 1;
        }
        char text[256];
        memcpy(text, a, la);
        memcpy(text + la, b, lb);
        text[line] = 0;
        fn_802cc3d0(text);
        Str s(text);
        lines_804737a4[ch].push_back(s);
    }
    if (flag) {
        Str t(0);
        fn_803426b8((void *)&t);
        fn_802cc0ac(&t, t_804abcc8, 1);
        fn_802cc0ac(&t, t_804abccc, 1);
        fn_802cc0ac(&t, t_804abcd0, 1);
        fn_802cbdf8(ch, t.p, 9);
    }
}
