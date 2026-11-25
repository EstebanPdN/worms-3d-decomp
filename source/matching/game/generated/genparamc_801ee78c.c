/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Pair templates (later batch): text split on newlines and inline reference
 * array resize. */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef void (*W3dMethod)(void *);
#define VCALL(p, o) ((*(W3dMethod *)(*(char **)(p) + (o)))(p))
int fn_802086dc(void *, const char *, unsigned int);
int fn_80208994(void *, const char *, unsigned int);

void *w3d_resize_refs_801ee78c(void *self, unsigned int count)
{
    unsigned int old = FIELD(self, unsigned int, 24);
    void **items = (void **)((char *)self + 32);
    if (old < count) {
        unsigned int i;
        for (i = old; i < count; i++)
            items[i] = 0;
    } else {
        unsigned int j;
        for (j = count; j < old; j++)
            VCALL(items[j], 16);
    }
    FIELD(self, unsigned int, 24) = count;
    return self;
}

void *w3d_resize_refs_801eeb58(void *self, unsigned int count)
{
    unsigned int old = FIELD(self, unsigned int, 24);
    void **items = (void **)((char *)self + 32);
    if (old < count) {
        unsigned int i;
        for (i = old; i < count; i++)
            items[i] = 0;
    } else {
        unsigned int j;
        for (j = count; j < old; j++)
            VCALL(items[j], 16);
    }
    FIELD(self, unsigned int, 24) = count;
    return self;
}

int w3d_write_lines_8020863c(void *self, const char *text, unsigned int length)
{
    unsigned int start = 0;
    unsigned int i;
    for (i = 0; i < length; i++) {
        if (text[i] == '\n') {
            int result = fn_802086dc(self, text + start, i - start + 1);
            if (result < 0)
                return result;
            FIELD(self, int, 36) = 1;
            start = i + 1;
        }
    }
    if (start != length)
        return fn_802086dc(self, text + start, length - start);
    return 0;
}

int w3d_write_lines_802088f4(void *self, const char *text, unsigned int length)
{
    unsigned int start = 0;
    unsigned int i;
    for (i = 0; i < length; i++) {
        if (text[i] == '\n') {
            int result = fn_80208994(self, text + start, i - start + 1);
            if (result < 0)
                return result;
            FIELD(self, int, 28) = 1;
            start = i + 1;
        }
    }
    if (start != length)
        return fn_80208994(self, text + start, length - start);
    return 0;
}
