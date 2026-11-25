#include "w3d_ptr.h"
#line 1 "d26k_log_allocation_80217dac.cpp"
// Allocation log line (Worms 3D GameCube PAL, 0x80217dac).
// 
// Clears the file and line of the allocation record and, when the log descriptor
// 0x804aba90 is open, formats one colon-separated line in a 1024-byte buffer: three
// numbers, the record address, the allocator kind from the flag word (best, last,
// pool, profile or debug) and the source file and line when they fit, then writes
// it through 0x802e3294.

extern "C" Ptr32<char> number_80217cd4(int, int);
extern "C" Ptr32<char> append_80217c6c(Ptr32<char>, Ptr32<const char>, int);
extern "C" int strlen_802ef9c0(Ptr32<const char>);
extern "C" Ptr32<void> write_802e3294(int, Ptr32<char>, int, ...);
extern int global_804aba90;
extern const char text_803b3814[], text_803b381c[], text_803b3824[], text_803b382c[], text_803b3834[];
struct Allocation { char pad[36]; Ptr32<const char> file; int line; char pad2[48 - 44]; Ptr32<unsigned int> flags; };
extern "C" void w3d_d26k_log_allocation_80217dac(Ptr32<Allocation> self, int a, int b, int c) {
    Ptr32<const char> file = self->file;
    int line = self->line;
    Ptr32<unsigned int> flags = self->flags;
    self->file = 0;
    self->line = 0;
    if (global_804aba90 >= 0) {
        char text[1024];
        Ptr32<char> out = text;
        Ptr32<char> end = text + 1024;
        out = append_80217c6c(out, number_80217cd4(a, 0), 58);
        out = append_80217c6c(out, number_80217cd4(b, 0), 58);
        out = append_80217c6c(out, number_80217cd4(c, 1), 58);
        out = append_80217c6c(out, number_80217cd4((int)w3d::H(self), 0), 58);
        unsigned bits = *flags;
        if (bits & 64) out = append_80217c6c(out, text_803b3814, 58);
        else if (bits & 256) out = append_80217c6c(out, text_803b381c, 58);
        else if (bits & 128) out = append_80217c6c(out, text_803b3824, 58);
        else if (bits & 1024) out = append_80217c6c(out, text_803b382c, 58);
        else out = append_80217c6c(out, text_803b3834, 58);
        if (file != 0 && *file != 0 && line > 0 && out + strlen_802ef9c0(file) + 32 < end) {
            out = append_80217c6c(out, file, 44);
            out = append_80217c6c(out, number_80217cd4(line, 1), 58);
        }
        out[0] = 10;
        *++out = 0;
        write_802e3294(global_804aba90, text, out - text);
    }
}


