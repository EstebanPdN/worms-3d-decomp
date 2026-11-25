typedef int (*Transfer)(void *, void *, int, int);
typedef int (*Skip)(void *, int, int, int);
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
extern "C" int r27c_read_words_80201ea4(void *self, unsigned int *buffer, unsigned int count)
{
    void *stream;
    int result;
    unsigned int i;
    unsigned int *p;
    if (!buffer) {
        stream = FIELD(self, void *, 20);
        return (*(Skip *)(*(char **)stream + 28))(stream, count << 2, 1, 0);
    }
    stream = FIELD(self, void *, 20);
    result = (*(Transfer *)(*(char **)stream + 20))(stream, buffer, count << 2, 0);
    for (i = 0; i < count; i++) {
        unsigned int v;
        p = buffer++;
        v = *p;
        *p = (v << 24) | ((v << 8) & 0xff0000) | ((v >> 8) & 0xff00) | (v >> 24);
    }
    return result;
}
