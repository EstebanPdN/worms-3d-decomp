// d32i: 0x8010aeb0. Emits a contour piece's triangles into a strip: looks up
// three vertices per triangle, adds them, then adds the low and high detail
// tiles selected from the vertex info.
struct Run { unsigned short value; unsigned short length; };
struct Cursor {
    Run *table;
    int index;
    int left;
    int pos;
    void Seek(int to) {
        int d = to - pos;
        left += d;
        pos += d;
        if (left < 0) {
            do {
                index--;
                left += table[index].length;
            } while (left < 0);
        } else {
            while (left >= table[index].length) {
                left -= table[index].length;
                index++;
            }
        }
    }
};
struct Strip {
    unsigned char unknown00[28];
    Cursor cursor;     // +28
    unsigned char unknown2c[636];
    unsigned *info;    // +680
    unsigned char unknown2ac[340];
    unsigned char low[768];   // +1024
    unsigned char high[1];    // +1792
};
struct Record { int a, b, c, offset; };
extern "C" void emit_8010ad24(Strip *, unsigned, unsigned, unsigned, unsigned char);
extern "C" void low_8010adb0(Strip *, unsigned, unsigned, unsigned, unsigned char, unsigned char);
extern "C" void high_8010ae30(Strip *, unsigned, unsigned, unsigned, unsigned char, unsigned char);
inline bool Far(unsigned word) { unsigned lim = 0xfd00; return (word & 0xff00) > lim; }
inline unsigned Info(unsigned i, unsigned *t) { return t[i]; }
extern "C" void d32i_strip_emit_triangles_8010aeb0(Strip *self, char *verts, int z, int *data, int x, int y) {
    int i;
    int *p = data;
    int n = *p;
    p++;
    unsigned char flip = ((unsigned char *)p)[3];
    p++;
    int base = x + (y << 5) + (z << 10);
    char *row = verts + x * 72 + y * 1296;
    for (i = 0; i < n; i++) {
        unsigned a = *(unsigned short *)(row + (p[0] << 2));
        unsigned b = *(unsigned short *)((p[1] << 2) + (int)row);
        unsigned c = *(unsigned short *)((p[2] << 2) + (int)row);
        emit_8010ad24(self, a, b, c, flip);
                Cursor *cur = &self->cursor;
        cur->Seek(base + p[3]);
        unsigned v = *(unsigned short *)((cur->index << 2) + (int)self->cursor.table);
        unsigned *info = self->info;
        unsigned w = v;
        if (!Far(info[a]) || !Far(info[b]) || !Far(info[c]))
            low_8010adb0(self, a, b, c, self->low[w & 0xff], flip);
        { unsigned t = Info(a, self->info); if (t & 0xff00) goto high; t = Info(b, self->info); if (t & 0xff00) goto high; t = Info(c, self->info); if (t & 0xff00) high:
            high_8010ae30(self, a, b, c, self->high[v >> 8], flip);
        }
        p += 4;
        flip = 1 - flip;
    }
}
