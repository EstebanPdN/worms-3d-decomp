/*
** $Id: ltable.h,v 1.44 2003/03/18 12:50:04 roberto Exp $
** Lua tables (hash)
** See Copyright Notice in lua.h
*/

#ifndef ltable_h
#define ltable_h

#include "lobject.h"


#define gnode(t,i)	(&(t)->node[i])
#define gkey(n)		(&(n)->i_key)
#define gval(n)		(&(n)->i_val)


Ptr32<const TObject> luaH_getnum (Ptr32<Table> t, int key);
Ptr32<TObject> luaH_setnum (Ptr32<lua_State> L, Ptr32<Table> t, int key);
Ptr32<const TObject> luaH_getstr (Ptr32<Table> t, Ptr32<TString> key);
Ptr32<const TObject> luaH_get (Ptr32<Table> t, Ptr32<const TObject> key);
Ptr32<TObject> luaH_set (Ptr32<lua_State> L, Ptr32<Table> t, Ptr32<const TObject> key);
Ptr32<Table> luaH_new (Ptr32<lua_State> L, int narray, int lnhash);
void luaH_free (Ptr32<lua_State> L, Ptr32<Table> t);
int luaH_next (Ptr32<lua_State> L, Ptr32<Table> t, StkId key);

/* exported only for debugging */
Ptr32<Node> luaH_mainposition (Ptr32<const Table> t, Ptr32<const TObject> key);


#endif
