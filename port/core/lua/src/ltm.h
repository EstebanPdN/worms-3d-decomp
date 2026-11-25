/*
** $Id: ltm.h,v 1.41 2002/11/14 11:51:50 roberto Exp $
** Tag methods
** See Copyright Notice in lua.h
*/

#ifndef ltm_h
#define ltm_h


#include "lobject.h"


/*
* WARNING: if you change the order of this enumeration,
* grep "ORDER TM"
*/
typedef enum {
  TM_INDEX,
  TM_NEWINDEX,
  TM_GC,
  TM_MODE,
  TM_EQ,  /* last tag method with `fast' access */
  TM_ADD,
  TM_SUB,
  TM_MUL,
  TM_DIV,
  TM_POW,
  TM_UNM,
  TM_LT,
  TM_LE,
  TM_CONCAT,
  TM_CALL,
  TM_N		/* number of elements in the enum */
} TMS;



#define gfasttm(g,et,e) \
  (((et)->flags & (1u<<(e))) ? NULL : luaT_gettm(et, e, (g)->tmname[e]))

#define fasttm(l,et,e)	gfasttm(G(l), et, e)


Ptr32<const TObject> luaT_gettm (Ptr32<Table> events, TMS event, Ptr32<TString> ename);
Ptr32<const TObject> luaT_gettmbyobj (Ptr32<lua_State> L, Ptr32<const TObject> o, TMS event);
void luaT_init (Ptr32<lua_State> L);

extern Ptr32<const char> const luaT_typenames[];

#endif
