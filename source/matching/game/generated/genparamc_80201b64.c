/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Pair templates (later batch): 32-bit stream transfer with byte swap,
 * first-success dispatch over children, and shared-string lowercasing. */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef int (*W3dTransfer)(void *, void *, int, int);
typedef int (*W3dSkip)(void *, int, int, int);
typedef int (*W3dOffer)(void *, void *, int, void *);
extern const char lbl_803db449[];
unsigned short *fn_8020bc88(char **, unsigned int);
void fn_8020bb2c(void *);

int w3d_transfer_swapped32_80201b64(void *self, unsigned int *buffer, unsigned int count)
{
    void *stream;
    int result;
    unsigned int i;
    unsigned int *p;
    if (!buffer) {
        stream = FIELD(self, void *, 20);
        return (*(W3dSkip *)(*(char **)stream + 28))(stream, count << 2, 1, 0);
    }
    stream = FIELD(self, void *, 20);
    result = (*(W3dTransfer *)(*(char **)stream + 20))(stream, buffer, count << 2, 0);
    for (i = 0; i < count; i++) {
        unsigned int v;
        p = buffer++;
        v = *p;
        *p = (v << 24) | ((v << 8) & 0xff0000) | ((v >> 8) & 0xff00) | (v >> 24);
    }
    return result;
}

int w3d_transfer_swapped32_80201c1c(void *self, unsigned int *buffer, unsigned int count)
{
    void *stream;
    int result;
    unsigned int i;
    unsigned int *p;
    if (!buffer) {
        stream = FIELD(self, void *, 20);
        return (*(W3dSkip *)(*(char **)stream + 28))(stream, count << 2, 1, 0);
    }
    stream = FIELD(self, void *, 20);
    result = (*(W3dTransfer *)(*(char **)stream + 20))(stream, buffer, count << 2, 0);
    for (i = 0; i < count; i++) {
        unsigned int v;
        p = buffer++;
        v = *p;
        *p = (v << 24) | ((v << 8) & 0xff0000) | ((v >> 8) & 0xff00) | (v >> 24);
    }
    return result;
}

int w3d_offer_to_children_8020a304(void *self, void *request, int flags, void *context)
{
    int result = 0x80004005;
    void **end = FIELD(self, void **, 24);
    void **it = FIELD(self, void **, 20);
    void *first = FIELD(self, void *, 32);
    if (first && (flags & 10)) {
        result = (*(W3dOffer *)(*(char **)first + 28))(first, request, flags, context);
        if (result >= 0)
            return result;
    }
    for (; it != end; it++) {
        result = (*(W3dOffer *)(*(char **)*it + 28))(*it, request, flags, context);
        if (result >= 0)
            return result;
    }
    return result;
}

int w3d_offer_to_children_8020a3b0(void *self, void *request, int flags, void *context)
{
    int result = 0x80004005;
    void **end = FIELD(self, void **, 24);
    void **it = FIELD(self, void **, 20);
    void *first = FIELD(self, void *, 32);
    if (first && (flags & 10)) {
        result = (*(W3dOffer *)(*(char **)first + 32))(first, request, flags, context);
        if (result >= 0)
            return result;
    }
    for (; it != end; it++) {
        result = (*(W3dOffer *)(*(char **)*it + 32))(*it, request, flags, context);
        if (result >= 0)
            return result;
    }
    return result;
}

void w3d_string_to_lower_8020c230(char **string)
{
    char *text = *string;
    unsigned short *header = (unsigned short *)(text - 6);
    unsigned int length = header[1];
    unsigned int i;
    char *out;
    if (FIELD(text, unsigned short, -6) > 1) {
        unsigned short *copy = fn_8020bc88(string, length + 1);
        if (--FIELD(text, unsigned short, -6) == 0)
            fn_8020bb2c(header);
        copy[1] = length;
    }
    out = *string;
    for (i = 0; i < length; i++) {
        int c = (signed char)text[i];
        if ((c + lbl_803db449)[0] & 1)
            c += 32;
        out[i] = c;
    }
    out[i] = 0;
}
