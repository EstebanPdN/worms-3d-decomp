/*
** $Id: lfunc.h,v 1.21 2003/03/18 12:50:04 roberto Exp $
** Auxiliary functions to manipulate prototypes and closures
** See Copyright Notice in lua.h
*/

#ifndef lfunc_h
#define lfunc_h


#include "lobject.h"


Ptr32<Proto> luaF_newproto (Ptr32<lua_State> L);
Ptr32<Closure> luaF_newCclosure (Ptr32<lua_State> L, int nelems);
Ptr32<Closure> luaF_newLclosure (Ptr32<lua_State> L, int nelems, Ptr32<TObject> e);
Ptr32<UpVal> luaF_findupval (Ptr32<lua_State> L, StkId level);
void luaF_close (Ptr32<lua_State> L, StkId level);
void luaF_freeproto (Ptr32<lua_State> L, Ptr32<Proto> f);
void luaF_freeclosure (Ptr32<lua_State> L, Ptr32<Closure> c);

Ptr32<const char> luaF_getlocalname (Ptr32<const Proto> func, int local_number, int pc);


#endif
