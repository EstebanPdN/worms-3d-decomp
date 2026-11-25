#include "w3d_ptr.h"
#line 1 "d32i_strip_emit_triangles_8010aeb0.cpp"
// d32i: 0x8010aeb0. Emits a contour piece's triangles into a strip: looks up
// three vertices per triangle, adds them, then adds the low and high detail
// tiles selected from the vertex info.
struct Run { unsigned short value; unsigned short length; };
struct Cursor {
    Ptr32<Run> table;
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
    Ptr32<unsigned int> info;    // +680
    unsigned char unknown2ac[340];
    unsigned char low[768];   // +1024
    unsigned char high[1];    // +1792
};
struct Record { int a, b, c, offset; };
extern "C" void emit_8010ad24(Ptr32<Strip>, unsigned, unsigned, unsigned, unsigned char);
extern "C" void low_8010adb0(Ptr32<Strip>, unsigned, unsigned, unsigned, unsigned char, unsigned char);
extern "C" void high_8010ae30(Ptr32<Strip>, unsigned, unsigned, unsigned, unsigned char, unsigned char);
inline bool Far(unsigned word) { unsigned lim = 0xfd00; return (word & 0xff00) > lim; }
inline unsigned Info(unsigned i, Ptr32<unsigned int> t) { return t[i]; }
extern "C" void d32i_strip_emit_triangles_8010aeb0(Ptr32<Strip> self, Ptr32<char> verts, int z, Ptr32<int> data, int x, int y) {
    int i;
    Ptr32<int> p = data;
    int n = *p;
    p++;
    unsigned char flip = ((Ptr32<unsigned char>)p)[0];
    p++;
    int base = x + (y << 5) + (z << 10);
    Ptr32<char> row = verts + x * 72 + y * 1296 + 2; /* vínculo B: mitad alta (PPC +0, anfitrión +2) */
    for (i = 0; i < n; i++) {
        unsigned a = *(Ptr32<unsigned short>)(row + (p[0] << 2));
        unsigned b = *(Ptr32<unsigned short>)w3d::G(((p[1] << 2) + (int)w3d::H(row)));
        unsigned c = *(Ptr32<unsigned short>)w3d::G(((p[2] << 2) + (int)w3d::H(row)));
        emit_8010ad24(self, a, b, c, flip);
                Ptr32<Cursor> cur = &self->cursor;
        cur->Seek(base + p[3]);
        unsigned v = *(Ptr32<unsigned short>)w3d::G(((cur->index << 2) + (int)w3d::H(self->cursor.table)));
        Ptr32<unsigned int> info = self->info;
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


