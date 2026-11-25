/*
** $Id: lvm.h,v 1.47 2002/11/14 16:16:21 roberto Exp $
** Lua virtual machine
** See Copyright Notice in lua.h
*/

#ifndef lvm_h
#define lvm_h


#include "ldo.h"
#include "lobject.h"
#include "ltm.h"


#define tostring(L,o) ((ttype(o) == LUA_TSTRING) || (luaV_tostring(L, o)))

#define tonumber(o,n)	(ttype(o) == LUA_TNUMBER || \
                         (((o) = luaV_tonumber(o,n)) != NULL))

#define equalobj(L,o1,o2) \
	(ttype(o1) == ttype(o2) && luaV_equalval(L, o1, o2))


int luaV_lessthan (Ptr32<lua_State> L, Ptr32<const TObject> l, Ptr32<const TObject> r);
int luaV_equalval (Ptr32<lua_State> L, Ptr32<const TObject> t1, Ptr32<const TObject> t2);
Ptr32<const TObject> luaV_tonumber (Ptr32<const TObject> obj, Ptr32<TObject> n);
int luaV_tostring (Ptr32<lua_State> L, StkId obj);
Ptr32<const TObject> luaV_gettable (Ptr32<lua_State> L, Ptr32<const TObject> t, Ptr32<TObject> key,
                              int loop);
void luaV_settable (Ptr32<lua_State> L, Ptr32<const TObject> t, Ptr32<TObject> key, StkId val);
StkId luaV_execute (Ptr32<lua_State> L);
void luaV_concat (Ptr32<lua_State> L, int total, int last);

#endif
