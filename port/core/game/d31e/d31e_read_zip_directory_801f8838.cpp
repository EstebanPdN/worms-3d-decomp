#include "w3d_ptr.h"
#line 1 "d31e_read_zip_directory_801f8838.cpp"
// (Worms 3D GameCube PAL, 0x801f8838).
//
// Reads a ZIP central directory once: if already opened, returns 0 when the
// entry table exists, else E_FAIL. Otherwise seeks to find the file size,
// reads the end record 24 bytes before the end, and when its signature
// 0x06054b50 is wrong scans backwards byte by byte for it. Allocates 64-byte
// entries aligned to 64, reads the directory, and for each record copies the
// name (mapping backslash to slash), computes the data offset and stores the
// sizes, tracing each name. Names are inferred.

struct Stream {
    void w3d_r_v0() __asm__(W3D_SYM("_ZN6Stream2v0Ev")), w3d_r_v1() __asm__(W3D_SYM("_ZN6Stream2v1Ev")), w3d_r_v2() __asm__(W3D_SYM("_ZN6Stream2v2Ev"));
    int w3d_r_Read(Ptr32<void>, unsigned, Ptr32<unsigned int>) __asm__(W3D_SYM("_ZN6Stream4ReadEPvjPj"));
    void w3d_r_v4() __asm__(W3D_SYM("_ZN6Stream2v4Ev"));
    int w3d_r_Seek(int, int, Ptr32<unsigned int>) __asm__(W3D_SYM("_ZN6Stream4SeekEiiPj"));
    void w3d_r_v7() __asm__(W3D_SYM("_ZN6Stream2v7Ev"));
    int w3d_r_Stat(Ptr32<void>) __asm__(W3D_SYM("_ZN6Stream4StatEPv"));
 __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int Read(Ptr32<void> w3d_a0, unsigned int w3d_a1, Ptr32<unsigned int> w3d_a2) { return ((int (*)(w3d_u32, Ptr32<void>, unsigned int, Ptr32<unsigned int>))w3d::vfn(this->w3d_vptr_Stream, 5))(w3d::h2g(this), w3d_a0, w3d_a1, w3d_a2); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int Seek(int w3d_a0, int w3d_a1, Ptr32<unsigned int> w3d_a2) { return ((int (*)(w3d_u32, int, int, Ptr32<unsigned int>))w3d::vfn(this->w3d_vptr_Stream, 7))(w3d::h2g(this), w3d_a0, w3d_a1, w3d_a2); }  __attribute__((always_inline)) inline void v7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int Stat(Ptr32<void> w3d_a0) { return ((int (*)(w3d_u32, Ptr32<void>))w3d::vfn(this->w3d_vptr_Stream, 9))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_Stream; };
struct End { unsigned sig; unsigned short disk, start, here, total; unsigned size, offset; unsigned short comment; };
struct DirEntry { unsigned sig; short a, b, c, d, e, f; int crc; unsigned packed, full; unsigned short nameLen, extraLen, commentLen; short g, h; int attrs; unsigned local; };
struct Entry { char name[52]; unsigned offset; unsigned packed; unsigned full; };
struct Zip {
    char u0[20];
    Ptr32<Stream> stream;
    char u24[4];
    unsigned char opened;
    char u29[3];
    int count;
    Ptr32<Entry> entries;
};
extern int g_trace;
extern const char s_file[];
extern "C" int sol35d10_read_end_record_801f8c48(Ptr32<Zip>, Ptr32<End>, int);
extern "C" unsigned w3d_auto_801f87f0(Ptr32<void>);
extern "C" Ptr32<void> w3d_aligned_allocate_801fe2a8(unsigned, int);
extern "C" Ptr32<void> tsonnet_c26_temp_alloc_801fe0b8(unsigned);
extern "C" int w3d_auto_801f8b7c(Ptr32<Zip>, Ptr32<DirEntry>, Ptr32<void>);
extern "C" Ptr32<char> strncpy(Ptr32<char>, Ptr32<const char>, unsigned);
extern "C" void w3d_trace_stub_80347324(Ptr32<int>, Ptr32<const char>, ...);
extern "C" int w3d_d31e_read_zip_directory_801f8838(Ptr32<Zip> self)
{
    End end;
    char stat[16];
    DirEntry de;
    unsigned pos;
    unsigned word;
    unsigned got;
    int hr;
    if (self->opened) {
        if (self->entries) return 0;
        return 0x80004005;
    }
    goto start;
found:
    hr = sol35d10_read_end_record_801f8c48(self, &end, 0);
    goto check;
start:
    self->opened = 1;
    hr = 0;
    self->stream->Seek(0, 0, &pos);
    self->stream->Seek(0, 2, &pos);
    self->stream->Seek(0, 1, &pos);
    self->stream->Stat(stat);
    self->stream->Seek(pos - 24, 0, &pos);
    sol35d10_read_end_record_801f8c48(self, &end, 1);
    if (end.sig != 0x06054b50) {
        unsigned n = pos;
        hr = 0x80004005;
        if (n) {
            do {
                n--;
                self->stream->Seek(n, 0, 0);
                self->stream->Read(&word, 4, &got);
                unsigned s = w3d_auto_801f87f0(&word);
                end.sig = s;
                if (s == 0x06054b50) goto found;
            } while (n);
        }
    }
check:
    if (hr) return hr;
    self->entries = (Ptr32<Entry>)w3d_aligned_allocate_801fe2a8(end.total << 6, 64);
    self->count = end.total;
    Ptr32<char> p = (Ptr32<char>)tsonnet_c26_temp_alloc_801fe0b8(end.size);
    self->stream->Seek(end.offset, 0, 0);
    self->stream->Read(p, end.size, 0);
    for (int i = 0; i < self->count; i++) {
        w3d_auto_801f8b7c(self, &de, p);
        strncpy(self->entries[i].name, p + 46, de.nameLen);
        self->entries[i].name[de.nameLen] = 0;
        int ofs = de.nameLen + 30; self->entries[i].offset = de.local + ofs;
        self->entries[i].packed = de.packed;
        self->entries[i].full = de.full;
        for (Ptr32<char> c = self->entries[i].name; *c; c++)
            if (*c == '\\') *c = '/';
        w3d_trace_stub_80347324(&g_trace, s_file, w3d::VA(self->entries[i].name));
        int skip = de.nameLen + 46; p = p + (de.commentLen + skip + de.extraLen);
    }
    return 0;
}


