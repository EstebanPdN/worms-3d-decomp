/*
** $Id: ldo.h,v 1.56 2002/12/04 17:29:32 roberto Exp $
** Stack and Call structure of Lua
** See Copyright Notice in lua.h
*/

#ifndef ldo_h
#define ldo_h


#include "lobject.h"
#include "lstate.h"
#include "lzio.h"


/*
** macro to control inclusion of some hard tests on stack reallocation
*/ 
#ifndef HARDSTACKTESTS
#define condhardstacktests(x)	{ /* empty */ }
#else
#define condhardstacktests(x)	x
#endif


#define luaD_checkstack(L,n)	\
  if ((char *)L->stack_last - (char *)L->top <= (n)*(int)sizeof(TObject)) \
    luaD_growstack(L, n); \
  else condhardstacktests(luaD_reallocstack(L, L->stacksize));


#define incr_top(L) {luaD_checkstack(L,1); L->top++;}

#define savestack(L,p)		((char *)(p) - (char *)L->stack)
#define restorestack(L,n)	((TObject *)((char *)L->stack + (n)))

#define saveci(L,p)		((char *)(p) - (char *)L->base_ci)
#define restoreci(L,n)		((CallInfo *)((char *)L->base_ci + (n)))


/* type of protected functions, to be ran by `runprotected' */
typedef Ptr32<void (Ptr32<lua_State>, Ptr32<void>)> Pfunc;

void luaD_resetprotection (Ptr32<lua_State> L);
int luaD_protectedparser (Ptr32<lua_State> L, Ptr32<ZIO> z, int bin);
void luaD_callhook (Ptr32<lua_State> L, int event, int line);
StkId luaD_precall (Ptr32<lua_State> L, StkId func);
void luaD_call (Ptr32<lua_State> L, StkId func, int nResults);
int luaD_pcall (Ptr32<lua_State> L, Pfunc func, Ptr32<void> u,
                ptrdiff_t oldtop, ptrdiff_t ef);
void luaD_poscall (Ptr32<lua_State> L, int wanted, StkId firstResult);
void luaD_reallocCI (Ptr32<lua_State> L, int newsize);
void luaD_reallocstack (Ptr32<lua_State> L, int newsize);
void luaD_growstack (Ptr32<lua_State> L, int n);

void luaD_throw (Ptr32<lua_State> L, int errcode);
int luaD_rawrunprotected (Ptr32<lua_State> L, Pfunc f, Ptr32<void> ud);


#endif
