/*
** $Id: ldebug.h,v 1.32 2002/11/18 11:01:55 roberto Exp $
** Auxiliary functions from Debug Interface module
** See Copyright Notice in lua.h
*/

#ifndef ldebug_h
#define ldebug_h


#include "lstate.h"


#define pcRel(pc, p)	(cast(int, (pc) - (p)->code) - 1)

#define getline(f,pc)	(((f)->lineinfo) ? (f)->lineinfo[pc] : 0)

#define resethookcount(L)	(L->hookcount = L->basehookcount)


void luaG_inithooks (Ptr32<lua_State> L);
void luaG_typeerror (Ptr32<lua_State> L, Ptr32<const TObject> o, Ptr32<const char> opname);
void luaG_concaterror (Ptr32<lua_State> L, StkId p1, StkId p2);
void luaG_aritherror (Ptr32<lua_State> L, Ptr32<const TObject> p1, Ptr32<const TObject> p2);
int luaG_ordererror (Ptr32<lua_State> L, Ptr32<const TObject> p1, Ptr32<const TObject> p2);
void luaG_runerror (Ptr32<lua_State> L, Ptr32<const char> fmt, ...);
void luaG_errormsg (Ptr32<lua_State> L);
int luaG_checkcode (Ptr32<const Proto> pt);


#endif
