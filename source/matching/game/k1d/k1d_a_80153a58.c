struct K1dRange { char *begin; char *end; };
struct K1dBuf { char pad[1344]; struct K1dRange range; };
extern void *fn_802eee50();
void w3d_k1d_compact_buffer_80153a58(struct K1dBuf *b)
{
    struct K1dRange *r = &b->range;
    char *begin = r->begin;
    int n = r->end - begin;
    fn_802eee50(begin, r->end, 0);
    r->end = r->end - n;
}
// k1d: w3d_k1d_compact_buffer_80153a58|0x80153a58|Appears to move a pointer range back by its length after a zero-length copy.
