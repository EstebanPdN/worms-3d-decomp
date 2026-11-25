// (Worms 3D GameCube PAL, 0x80202f34).
//
// Reads the 64-byte MOIK object file header into the reader and swaps its
// ten little-endian words to host order. Returns the read error, or E_FAIL
// after tracing a bad magic or a version above 0x2000000.

struct Reader { char u0[60]; int magic; unsigned version; unsigned a, b, c, d, e, f, g, h, i; };
inline unsigned Swap(unsigned x) { return x << 24 | (x & 0xff00) << 8 | (x >> 8 & 0xff00) | x >> 24; }
extern "C" void *memset(void *, int, unsigned long);
extern "C" int w3d_s21_read_forward_802025a8(Reader *, void *, int);
extern int g_trace;
extern "C" void w3d_trace_stub_80347324(int *, const char *, ...);
extern char lbl_803b2b54[];
extern char lbl_803b2b60[];
extern "C" int w3d_d33e_read_object_header_80202f34(Reader *r)
{
    memset(&r->magic, 0, 64);
    int hr = w3d_s21_read_forward_802025a8(r, &r->magic, 64);
    if (hr >= 0) {
    if (r->magic != 0x4d4f494b) goto bad;
    r->version = Swap(r->version);
    r->a = Swap(r->a);
    r->b = Swap(r->b);
    r->c = Swap(r->c);
    r->d = Swap(r->d);
    r->e = Swap(r->e);
    r->f = Swap(r->f);
    r->g = Swap(r->g);
    r->h = Swap(r->h);
    r->i = Swap(r->i);
    if (r->version <= 0x2000000) return 0;
    w3d_trace_stub_80347324(&g_trace, lbl_803b2b60);
    return 0x80004005;
bad:
    w3d_trace_stub_80347324(&g_trace, lbl_803b2b54);
    return 0x80004005;
    }
    return hr;
}
