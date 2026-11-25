// Configuración de Lua del juego en el port. Equivale a lua_game_reference_user.h,
// con los punteros del núcleo. Los LUA_NUMBER son float como en GWMP8P.
#ifndef W3D_LUA_GAME_PORT_USER_H
#define W3D_LUA_GAME_PORT_USER_H
#define LUA_NUMBER float
Ptr32<void> w3d_lua_reallocate(Ptr32<void>, unsigned int, unsigned int);
void w3d_lua_release(Ptr32<void>);
typedef struct lua_State lua_State;
void w3d_lua_gc_boundary(Ptr32<lua_State>, int);
float w3d_lua_parse_number(Ptr32<const char>, Ptr32<Ptr32<char> >);
#define lua_userstateopen(state) (*(unsigned int *)((unsigned char *)(state) + 0x58) = 0U)
#define l_realloc(block, oldsize, size) w3d_lua_reallocate((block), (oldsize), (size))
#define l_free(block, oldsize) w3d_lua_release(block)
#define lua_str2number(text, end) w3d_lua_parse_number((text), (end))
#endif
