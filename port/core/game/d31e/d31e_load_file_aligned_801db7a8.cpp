#include "w3d_ptr.h"
#line 1 "d31e_load_file_aligned_801db7a8.cpp"
// (Worms 3D GameCube PAL, 0x801db7a8).
//
// Opens a disc file by name and reads it whole into a 32-byte aligned buffer
// filled first with 0xe0: from the audio heap at 0x804ab8b4 when the flag is
// set, otherwise from the general aligned allocator. On a read error frees
// the buffer and returns null without closing; on success closes the file
// and returns the buffer. Open, read and close signatures are read from the
// call sites; names are inferred.

struct FileInfo { char a[52]; unsigned length; char b[8]; };
struct Heap;
struct Reader;
extern Ptr32<Heap> g_heap;
extern "C" int fn_802f5258(Ptr32<const char>, Ptr32<FileInfo>);
extern "C" int fn_802f5320(Ptr32<FileInfo>);
extern "C" Ptr32<void> w3d_auto_802098fc(Ptr32<Heap>, unsigned, int);
extern "C" Ptr32<void> fn_801fe2a8(unsigned, int);
extern "C" Ptr32<void> memset(Ptr32<void>, int, unsigned);
extern "C" Ptr32<Reader> w3d_pair_instance_80343994();
extern "C" int fn_801fdcac(Ptr32<Reader>, Ptr32<FileInfo>, Ptr32<void>, unsigned, int);
extern "C" void w3d_heap_release(Ptr32<Heap>, Ptr32<void>);
extern "C" void w3d_auto_80209968(Ptr32<Heap>);
extern "C" void fn_801fe288(Ptr32<void>);
extern "C" Ptr32<void> w3d_d31e_load_file_aligned_801db7a8(Ptr32<void> self, Ptr32<const char> name, int useHeap)
{
    Ptr32<void> buf = 0;
    FileInfo info;
    if (fn_802f5258(name, &info)) {
        if (info.length) {
            unsigned size = (info.length + 31) & ~31;
            if (useHeap) buf = w3d_auto_802098fc(g_heap, size, 32);
            else buf = fn_801fe2a8(size, 32);
            if (buf) {
                memset(buf, 0xe0, size);
                if (fn_801fdcac(w3d_pair_instance_80343994(), &info, buf, size, 0)) {
                    if (useHeap) {
                        w3d_heap_release(g_heap, buf);
                        w3d_auto_80209968(g_heap);
                    } else {
                        fn_801fe288(buf);
                    }
                    buf = 0;
                } else {
                    fn_802f5320(&info);
                }
            }
        }
    }
    return buf;
}


