/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Pair templates (later batch): 16-bit stream transfer with byte swap and a
 * callback message builder. */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef int (*W3dTransfer)(void *, void *, int, int);
typedef int (*W3dSkip)(void *, int, int, int);

int w3d_transfer_swapped16_80201a14(void *self, unsigned short *buffer, unsigned int count)
{
    void *stream;
    int result;
    unsigned int i;
    unsigned short *p;
    if (!buffer) {
        stream = FIELD(self, void *, 20);
        return (*(W3dSkip *)(*(char **)stream + 28))(stream, count << 1, 1, 0);
    }
    stream = FIELD(self, void *, 20);
    result = (*(W3dTransfer *)(*(char **)stream + 20))(stream, buffer, count << 1, 0);
    for (i = 0; i < count; i++) {
        p = buffer++;
        *p = ((*p & 0xff) << 8) | (*p >> 8);
    }
    return result;
}

int w3d_transfer_swapped16_80201abc(void *self, unsigned short *buffer, unsigned int count)
{
    void *stream;
    int result;
    unsigned int i;
    unsigned short *p;
    if (!buffer) {
        stream = FIELD(self, void *, 20);
        return (*(W3dSkip *)(*(char **)stream + 28))(stream, count << 1, 1, 0);
    }
    stream = FIELD(self, void *, 20);
    result = (*(W3dTransfer *)(*(char **)stream + 20))(stream, buffer, count << 1, 0);
    for (i = 0; i < count; i++) {
        p = buffer++;
        *p = ((*p & 0xff) << 8) | (*p >> 8);
    }
    return result;
}
