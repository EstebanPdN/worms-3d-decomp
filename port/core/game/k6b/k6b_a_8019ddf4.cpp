#include "w3d_ptr.h"
#line 1 "k6b_a_8019ddf4.cpp"
struct lua_State;
struct K6bStream { Ptr32<Ptr32<void>> vtable; };
struct K6bFileService { Ptr32<Ptr32<void>> vtable; };
struct K6bScriptHost {
    char head[20];
    Ptr32<lua_State> L;
};
struct K6bStreamRef {
    Ptr32<K6bStream> p;
    K6bStreamRef() : p(0) {}
    ~K6bStreamRef() { if (p != 0) ((Ptr32<void (Ptr32<K6bStream>)>)p->vtable[4])(p); }
};
struct K6bChunkReader {
    Ptr32<K6bStream> stream;
    char buffer[16384];
};
typedef Ptr32<Ptr32<const char> (Ptr32<lua_State>, Ptr32<void>, Ptr32<unsigned int>)> K6bLuaReader;
extern "C" Ptr32<K6bFileService> fn_8020b884(void);
extern "C" Ptr32<const char> fn_8019dd80(Ptr32<lua_State> L, Ptr32<void> data, Ptr32<unsigned int> size);
extern "C" int lua_load(Ptr32<lua_State> L, K6bLuaReader reader, Ptr32<void> data, Ptr32<const char> chunkname);
extern "C" void lua_call(Ptr32<lua_State> L, int nargs, int nresults);
extern "C" int w3d_k6b_script_host_run_file_8019ddf4(Ptr32<K6bScriptHost> self, Ptr32<const char> name, Ptr32<K6bFileService> files)
{
    K6bStreamRef stream;
    int result;
    if (files == 0)
        files = fn_8020b884();
    result = ((Ptr32<int (Ptr32<K6bFileService>, Ptr32<const char>, int, Ptr32<Ptr32<K6bStream>>)>)files->vtable[6])(files, name, 1, &stream.p);
    if (result < 0)
        return result;
    K6bChunkReader reader;
    reader.stream = stream.p;
    if (lua_load(self->L, fn_8019dd80, &reader, name) == 0) {
        lua_call(self->L, 0, 0);
        return 0;
    }
    return 0x80004005;
}
// desc: w3d_k6b_script_host_run_file_8019ddf4: Appears to open a script through the file service (default 0x8020b884), load it into the Lua state at +20 with the stream reader 0x8019dd80 and run it.


