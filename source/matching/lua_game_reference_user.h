#ifndef W3D_LUA_GAME_REFERENCE_USER_H
#define W3D_LUA_GAME_REFERENCE_USER_H
#include "lua_reference_user.h"

/* These are observed engine dependency interfaces. Their bodies are not
 * provided by this reference build, and remain separate recovery work. */
void *w3d_lua_reallocate(void *, unsigned long, unsigned long);
void w3d_lua_release(void *);
void w3d_lua_gc_boundary(lua_State *, int);
float w3d_lua_parse_number(const char *, char **);
#define l_realloc(block, oldsize, size) \
    w3d_lua_reallocate((block), (oldsize), (size))
#define l_free(block, oldsize) w3d_lua_release(block)
#define lua_str2number(text, end) w3d_lua_parse_number((text), (end))
#endif
