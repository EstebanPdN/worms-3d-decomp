#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k6b_a_802d77e8.c"
typedef float lua_Number;
typedef struct lua_State lua_State;
typedef struct K6bLoadState {
    Ptr32<lua_State> L;
    Ptr32<void> Z;
    Ptr32<void> b;
    int swap;
    Ptr32<const char> name;
} K6bLoadState;
extern void LoadSignature(Ptr32<K6bLoadState> S);
extern int ezgetc(Ptr32<K6bLoadState> S);
extern void luaG_runerror(Ptr32<lua_State> L, Ptr32<const char> format, ...);
extern int w3d_constant_802d7a54(void);
extern void TestSize(Ptr32<K6bLoadState> S, int s, Ptr32<const char> what);
extern lua_Number LoadNumber(Ptr32<K6bLoadState> S);
#define K6B_VERSION 0x50
#define K6B_VERSION0 0x50
#define K6B_V(v) v / 16, v % 16
#define K6B_LoadByte(S) (unsigned char)ezgetc(S)
void w3d_k6b_lua_undump_load_header_802d77e8(Ptr32<K6bLoadState> S)
{
    int version;
    lua_Number x, tx = 3.14159265358979323846E7;
    LoadSignature(S);
    version = K6B_LoadByte(S);
    if (version > K6B_VERSION)
        luaG_runerror(S->L, "%s too new: "
            "read version %d.%d; expected at most %d.%d",
            w3d::VA(S->name), K6B_V(version), K6B_V(K6B_VERSION));
    if (version < K6B_VERSION0)
        luaG_runerror(S->L, "%s too old: "
            "read version %d.%d; expected at least %d.%d",
            w3d::VA(S->name), K6B_V(version), K6B_V(K6B_VERSION0));
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
    if ((int)x != (int)tx)
        luaG_runerror(S->L, "unknown number format in %s", w3d::VA(S->name));
}
// desc: w3d_k6b_lua_undump_load_header_802d77e8: Appears to be Lua 5.0 lundump LoadHeader: check the signature, version 5.0, byte order, type sizes and the test number of a precompiled chunk.

}
