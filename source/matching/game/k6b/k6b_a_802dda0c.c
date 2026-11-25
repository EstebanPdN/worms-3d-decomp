typedef struct lua_State lua_State;
typedef struct K6bFile {
    unsigned char *pointer;
    int read_count;
    int write_count;
    unsigned short flags;
} K6bFile;
typedef struct K6bLoadF {
    K6bFile *f;
    char buff[1024];
} K6bLoadF;
struct K6bReent {
    int error_number;
    K6bFile *stdin_file;
    K6bFile *stdout_file;
    K6bFile *stderr_file;
};
typedef const char *(*K6bChunkReader)(lua_State *L, void *ud, unsigned int *size);
extern struct K6bReent *_impure_ptr;
extern const char _ctype_[];
extern int lua_gettop(lua_State *L);
extern void lua_pushlstring(lua_State *L, const char *s, unsigned int len);
extern const char *lua_pushfstring(lua_State *L, const char *format, ...);
extern const char *lua_tostring(lua_State *L, int index);
extern int lua_load(lua_State *L, K6bChunkReader reader, void *data, const char *chunkname);
extern void lua_settop(lua_State *L, int index);
extern void lua_remove(lua_State *L, int index);
extern K6bFile *fopen(const char *name, const char *mode);
extern int fclose(K6bFile *file);
extern int __srget(K6bFile *file);
extern int ungetc(int c, K6bFile *file);
extern const char *w3d_k6b_lua_getF_802dd934(lua_State *L, void *ud, unsigned int *size);
extern int w3d_k6b_lua_errfile_802dd9a0(lua_State *L, int name_index);
#define k6b_getc(fp) (--(fp)->read_count < 0 ? __srget(fp) : (int)(*(fp)->pointer++))
int w3d_k6b_lua_loadfile_802dda0c(lua_State *L, const char *filename)
{
    K6bLoadF lf;
    int status, readstatus;
    int c;
    int fnameindex = lua_gettop(L) + 1;
    if (filename == 0) {
        lua_pushlstring(L, "=stdin", sizeof("=stdin") - 1);
        lf.f = _impure_ptr->stdin_file;
    } else {
        lua_pushfstring(L, "@%s", filename);
        lf.f = fopen(filename, "r");
    }
    if (lf.f == 0) return w3d_k6b_lua_errfile_802dd9a0(L, fnameindex);
    c = ungetc(k6b_getc(lf.f), lf.f);
    if (!(((_ctype_ + 1)[c] & 8) || ((_ctype_ + 1)[c] & (16 | 1 | 2 | 4 | 128))) && lf.f != _impure_ptr->stdin_file) {
        fclose(lf.f);
        lf.f = fopen(filename, "rb");
        if (lf.f == 0) return w3d_k6b_lua_errfile_802dd9a0(L, fnameindex);
    }
    status = lua_load(L, w3d_k6b_lua_getF_802dd934, &lf, lua_tostring(L, -1));
    readstatus = (lf.f->flags & 0x40) != 0;
    if (lf.f != _impure_ptr->stdin_file) fclose(lf.f);
    if (readstatus) {
        lua_settop(L, fnameindex);
        return w3d_k6b_lua_errfile_802dd9a0(L, fnameindex);
    }
    lua_remove(L, fnameindex);
    return status;
}
// desc: w3d_k6b_lua_loadfile_802dda0c: Appears to be Lua 5.0 lauxlib luaL_loadfile: open the file (or stdin), reopen binary chunks in rb mode, load it through getF and report read errors.
