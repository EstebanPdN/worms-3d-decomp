typedef float lua_Number;
typedef struct lua_State lua_State;
typedef struct K6bLoadState {
    lua_State *L;
    void *Z;
    void *b;
    int swap;
    const char *name;
} K6bLoadState;
extern void LoadSignature(K6bLoadState *S);
extern int ezgetc(K6bLoadState *S);
extern void luaG_runerror(lua_State *L, const char *format, ...);
extern int w3d_constant_802d7a54(void);
extern void TestSize(K6bLoadState *S, int s, const char *what);
extern lua_Number LoadNumber(K6bLoadState *S);
#define K6B_VERSION 0x50
#define K6B_VERSION0 0x50
#define K6B_V(v) v / 16, v % 16
#define K6B_LoadByte(S) (unsigned char)ezgetc(S)
void w3d_k6b_lua_undump_load_header_802d77e8(K6bLoadState *S)
{
    int version;
    lua_Number x, tx = 3.14159265358979323846E7;
    LoadSignature(S);
    version = K6B_LoadByte(S);
    if (version > K6B_VERSION)
        luaG_runerror(S->L, "%s too new: "
            "read version %d.%d; expected at most %d.%d",
            S->name, K6B_V(version), K6B_V(K6B_VERSION));
    if (version < K6B_VERSION0)
        luaG_runerror(S->L, "%s too old: "
            "read version %d.%d; expected at least %d.%d",
            S->name, K6B_V(version), K6B_V(K6B_VERSION0));
    S->swap = (w3d_constant_802d7a54() != K6B_LoadByte(S));
    TestSize(S, sizeof(int), "int");
    TestSize(S, sizeof(unsigned int), "size_t");
    TestSize(S, sizeof(unsigned int), "Instruction");
    TestSize(S, 6, "OP");
    TestSize(S, 8, "A");
    TestSize(S, 9, "B");
    TestSize(S, 9, "C");
    TestSize(S, sizeof(lua_Number), "number");
    x = LoadNumber(S);
    if ((long)x != (long)tx)
        luaG_runerror(S->L, "unknown number format in %s", S->name);
}
// desc: w3d_k6b_lua_undump_load_header_802d77e8: Appears to be Lua 5.0 lundump LoadHeader: check the signature, version 5.0, byte order, type sizes and the test number of a precompiled chunk.
