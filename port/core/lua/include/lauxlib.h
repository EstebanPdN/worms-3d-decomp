/*
** $Id: lauxlib.h,v 1.60 2003/04/03 13:35:34 roberto Exp $
** Auxiliary functions for building Lua libraries
** See Copyright Notice in lua.h
*/


#ifndef lauxlib_h
#define lauxlib_h


#include <stddef.h>
#include <stdio.h>

#include "lua.h"


#ifndef LUALIB_API
#define LUALIB_API	LUA_API
#endif



typedef struct luaL_reg {
  Ptr32<const char> name;
  lua_CFunction func;
} luaL_reg;


LUALIB_API void luaL_openlib (Ptr32<lua_State> L, Ptr32<const char> libname,
                               Ptr32<const luaL_reg> l, int nup);
LUALIB_API int luaL_getmetafield (Ptr32<lua_State> L, int obj, Ptr32<const char> e);
LUALIB_API int luaL_callmeta (Ptr32<lua_State> L, int obj, Ptr32<const char> e);
LUALIB_API int luaL_typerror (Ptr32<lua_State> L, int narg, Ptr32<const char> tname);
LUALIB_API int luaL_argerror (Ptr32<lua_State> L, int numarg, Ptr32<const char> extramsg);
LUALIB_API Ptr32<const char> luaL_checklstring (Ptr32<lua_State> L, int numArg, Ptr32<size_t> l);
LUALIB_API Ptr32<const char> luaL_optlstring (Ptr32<lua_State> L, int numArg,
                                           Ptr32<const char> def, Ptr32<size_t> l);
LUALIB_API lua_Number luaL_checknumber (Ptr32<lua_State> L, int numArg);
LUALIB_API lua_Number luaL_optnumber (Ptr32<lua_State> L, int nArg, lua_Number def);

LUALIB_API void luaL_checkstack (Ptr32<lua_State> L, int sz, Ptr32<const char> msg);
LUALIB_API void luaL_checktype (Ptr32<lua_State> L, int narg, int t);
LUALIB_API void luaL_checkany (Ptr32<lua_State> L, int narg);

LUALIB_API int   luaL_newmetatable (Ptr32<lua_State> L, Ptr32<const char> tname);
LUALIB_API void  luaL_getmetatable (Ptr32<lua_State> L, Ptr32<const char> tname);
LUALIB_API Ptr32<void> luaL_checkudata (Ptr32<lua_State> L, int ud, Ptr32<const char> tname);

LUALIB_API void luaL_where (Ptr32<lua_State> L, int lvl);
LUALIB_API int luaL_error (Ptr32<lua_State> L, Ptr32<const char> fmt, ...);

LUALIB_API int luaL_findstring (Ptr32<const char> st, Ptr32<Ptr32<const char> const> lst);

LUALIB_API int luaL_ref (Ptr32<lua_State> L, int t);
LUALIB_API void luaL_unref (Ptr32<lua_State> L, int t, int ref);

LUALIB_API int luaL_getn (Ptr32<lua_State> L, int t);
LUALIB_API void luaL_setn (Ptr32<lua_State> L, int t, int n);

LUALIB_API int luaL_loadfile (Ptr32<lua_State> L, Ptr32<const char> filename);
LUALIB_API int luaL_loadbuffer (Ptr32<lua_State> L, Ptr32<const char> buff, size_t sz,
                                Ptr32<const char> name);



/*
** ===============================================================
** some useful macros
** ===============================================================
*/

#define luaL_argcheck(L, cond,numarg,extramsg) if (!(cond)) \
                                               luaL_argerror(L, numarg,extramsg)
#define luaL_checkstring(L,n)	(luaL_checklstring(L, (n), NULL))
#define luaL_optstring(L,n,d)	(luaL_optlstring(L, (n), (d), NULL))
#define luaL_checkint(L,n)	((int)luaL_checknumber(L, n))
#define luaL_checklong(L,n)	((long)luaL_checknumber(L, n))
#define luaL_optint(L,n,d)	((int)luaL_optnumber(L, n,(lua_Number)(d)))
#define luaL_optlong(L,n,d)	((long)luaL_optnumber(L, n,(lua_Number)(d)))


/*
** {======================================================
** Generic Buffer manipulation
** =======================================================
*/


#ifndef LUAL_BUFFERSIZE
#define LUAL_BUFFERSIZE	  BUFSIZ
#endif


typedef struct luaL_Buffer {
  Ptr32<char> p;			/* current position in buffer */
  int lvl;  /* number of strings in the stack (level) */
  Ptr32<lua_State> L;
  char buffer[LUAL_BUFFERSIZE];
} luaL_Buffer;

#define luaL_putchar(B,c) \
  ((void)((B)->p < ((B)->buffer+LUAL_BUFFERSIZE) || luaL_prepbuffer(B)), \
   (*(B)->p++ = (char)(c)))

#define luaL_addsize(B,n)	((B)->p += (n))

LUALIB_API void luaL_buffinit (Ptr32<lua_State> L, Ptr32<luaL_Buffer> B);
LUALIB_API Ptr32<char> luaL_prepbuffer (Ptr32<luaL_Buffer> B);
LUALIB_API void luaL_addlstring (Ptr32<luaL_Buffer> B, Ptr32<const char> s, size_t l);
LUALIB_API void luaL_addstring (Ptr32<luaL_Buffer> B, Ptr32<const char> s);
LUALIB_API void luaL_addvalue (Ptr32<luaL_Buffer> B);
LUALIB_API void luaL_pushresult (Ptr32<luaL_Buffer> B);


/* }====================================================== */



/*
** Compatibility macros and functions
*/

LUALIB_API int   lua_dofile (Ptr32<lua_State> L, Ptr32<const char> filename);
LUALIB_API int   lua_dostring (Ptr32<lua_State> L, Ptr32<const char> str);
LUALIB_API int   lua_dobuffer (Ptr32<lua_State> L, Ptr32<const char> buff, size_t sz,
                               Ptr32<const char> n);


#define luaL_check_lstr 	luaL_checklstring
#define luaL_opt_lstr 	luaL_optlstring 
#define luaL_check_number 	luaL_checknumber 
#define luaL_opt_number	luaL_optnumber
#define luaL_arg_check	luaL_argcheck
#define luaL_check_string	luaL_checkstring
#define luaL_opt_string	luaL_optstring
#define luaL_check_int	luaL_checkint
#define luaL_check_long	luaL_checklong
#define luaL_opt_int	luaL_optint
#define luaL_opt_long	luaL_optlong


#endif


