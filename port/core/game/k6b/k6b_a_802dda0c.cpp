#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k6b_a_802dda0c.c"
typedef struct lua_State lua_State;
typedef struct K6bFile {
    Ptr32<unsigned char> pointer;
    int read_count;
    int write_count;
    unsigned short flags;
} K6bFile;
typedef struct K6bLoadF {
    Ptr32<K6bFile> f;
    char buff[1024];
} K6bLoadF;
struct K6bReent {
    int error_number;
    Ptr32<K6bFile> stdin_file;
    Ptr32<K6bFile> stdout_file;
    Ptr32<K6bFile> stderr_file;
};
typedef Ptr32<Ptr32<const char> (Ptr32<lua_State>, Ptr32<void>, Ptr32<unsigned int>)> K6bChunkReader;
extern Ptr32<struct K6bReent> _impure_ptr;
extern const char _ctype_[];
extern int lua_gettop(Ptr32<lua_State> L);
extern void lua_pushlstring(Ptr32<lua_State> L, Ptr32<const char> s, unsigned int len);
extern Ptr32<const char> lua_pushfstring(Ptr32<lua_State> L, Ptr32<const char> format, ...);
extern Ptr32<const char> lua_tostring(Ptr32<lua_State> L, int index);
extern int lua_load(Ptr32<lua_State> L, K6bChunkReader reader, Ptr32<void> data, Ptr32<const char> chunkname);
extern void lua_settop(Ptr32<lua_State> L, int index);
extern void lua_remove(Ptr32<lua_State> L, int index);
extern Ptr32<K6bFile> fopen(Ptr32<const char> name, Ptr32<const char> mode);
extern int fclose(Ptr32<K6bFile> file);
extern int __srget(Ptr32<K6bFile> file);
extern int ungetc(int c, Ptr32<K6bFile> file);
extern Ptr32<const char> w3d_k6b_lua_getF_802dd934(Ptr32<lua_State> L, Ptr32<void> ud, Ptr32<unsigned int> size);
extern int w3d_k6b_lua_errfile_802dd9a0(Ptr32<lua_State> L, int name_index);
#define k6b_getc(fp) (--(fp)->read_count < 0 ? __srget(fp) : (int)w3d::AI(*(fp)->pointer++))
int w3d_k6b_lua_loadfile_802dda0c(Ptr32<lua_State> L, Ptr32<const char> filename)
{
    K6bLoadF lf;
    int status, readstatus;
    int c;
    int fnameindex = lua_gettop(L) + 1;
    if (filename == 0) {
        lua_pushlstring(L, "=stdin", sizeof("=stdin") - 1);
        lf.f = _impure_ptr->stdin_file;
    } else {
        lua_pushfstring(L, "@%s", w3d::VA(filename));
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

}
