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
extern unsigned int fread(void *buffer, unsigned int size, unsigned int count, K6bFile *file);
const char *w3d_k6b_lua_getF_802dd934(lua_State *L, void *ud, unsigned int *size)
{
    K6bLoadF *lf = (K6bLoadF *)ud;
    (void)L;
    if (lf->f->flags & 0x20) return 0;
    *size = fread(lf->buff, 1, 1024, lf->f);
    return (*size > 0) ? lf->buff : 0;
}
// desc: w3d_k6b_lua_getF_802dd934: Appears to be Lua 5.0 lauxlib getF: return NULL at end of file, else fread up to 1024 bytes into the LoadF buffer and return it when nonempty.
