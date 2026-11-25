struct lua_State;
struct K6bStream { void **vtable; };
struct K6bFileService { void **vtable; };
struct K6bScriptHost {
    char head[20];
    lua_State *L;
};
struct K6bStreamRef {
    K6bStream *p;
    K6bStreamRef() : p(0) {}
    ~K6bStreamRef() { if (p != 0) ((void (*)(K6bStream *))p->vtable[4])(p); }
};
struct K6bChunkReader {
    K6bStream *stream;
    char buffer[16384];
};
typedef const char *(*K6bLuaReader)(lua_State *L, void *data, unsigned int *size);
extern "C" K6bFileService *fn_8020b884(void);
extern "C" const char *fn_8019dd80(lua_State *L, void *data, unsigned int *size);
extern "C" int lua_load(lua_State *L, K6bLuaReader reader, void *data, const char *chunkname);
extern "C" void lua_call(lua_State *L, int nargs, int nresults);
extern "C" int w3d_k6b_script_host_run_file_8019ddf4(K6bScriptHost *self, const char *name, K6bFileService *files)
{
    K6bStreamRef stream;
    int result;
    if (files == 0)
        files = fn_8020b884();
    result = ((int (*)(K6bFileService *, const char *, int, K6bStream **))files->vtable[6])(files, name, 1, &stream.p);
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
