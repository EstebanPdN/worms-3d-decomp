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
    virtual void v0(), v1(), v2();
    virtual int Read(void *, unsigned, unsigned *);
    virtual void v4();
    virtual int Seek(int, int, unsigned *);
    virtual void v7();
    virtual int Stat(void *);
};
struct End { unsigned sig; unsigned short disk, start, here, total; unsigned size, offset; unsigned short comment; };
struct DirEntry { unsigned sig; short a, b, c, d, e, f; int crc; unsigned packed, full; unsigned short nameLen, extraLen, commentLen; short g, h; int attrs; unsigned local; };
struct Entry { char name[52]; unsigned offset; unsigned packed; unsigned full; };
struct Zip {
    char u0[20];
    Stream *stream;
    char u24[4];
    unsigned char opened;
    char u29[3];
    int count;
    Entry *entries;
};
extern int g_trace;
extern const char s_file[];
extern "C" int sol35d10_read_end_record_801f8c48(Zip *, End *, int);
extern "C" unsigned w3d_auto_801f87f0(void *);
extern "C" void *w3d_aligned_allocate_801fe2a8(unsigned, int);
extern "C" void *tsonnet_c26_temp_alloc_801fe0b8(unsigned);
extern "C" int w3d_auto_801f8b7c(Zip *, DirEntry *, void *);
extern "C" char *strncpy(char *, const char *, unsigned);
extern "C" void w3d_trace_stub_80347324(int *, const char *, ...);
extern "C" int w3d_d31e_read_zip_directory_801f8838(Zip *self)
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
    self->entries = (Entry *)w3d_aligned_allocate_801fe2a8(end.total << 6, 64);
    self->count = end.total;
    char *p = (char *)tsonnet_c26_temp_alloc_801fe0b8(end.size);
    self->stream->Seek(end.offset, 0, 0);
    self->stream->Read(p, end.size, 0);
    for (int i = 0; i < self->count; i++) {
        w3d_auto_801f8b7c(self, &de, p);
        strncpy(self->entries[i].name, p + 46, de.nameLen);
        self->entries[i].name[de.nameLen] = 0;
        int ofs = de.nameLen + 30; self->entries[i].offset = de.local + ofs;
        self->entries[i].packed = de.packed;
        self->entries[i].full = de.full;
        for (char *c = self->entries[i].name; *c; c++)
            if (*c == '\\') *c = '/';
        w3d_trace_stub_80347324(&g_trace, s_file, self->entries[i].name);
        int skip = de.nameLen + 46; p = p + (de.commentLen + skip + de.extraLen);
    }
    return 0;
}
