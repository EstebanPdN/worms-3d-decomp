struct K1dRange { char *begin; char *end; };
struct K1dBuf { char pad[60]; struct K1dRange range; };
extern void *fn_802eee50();
int w3d_k1d_compact_buffer_801a6668(struct K1dBuf *b)
{
    struct K1dRange *r = &b->range;
    char *begin = r->begin;
    int n = r->end - begin;
    fn_802eee50(begin, r->end, 0);
    r->end = r->end - n;
    return 0;
}
// k1d: w3d_k1d_compact_buffer_801a6668|0x801a6668|Appears to move a pointer range back by its length after a zero-length copy and return zero.
