/*
** $Id: lundump.h,v 1.30 2003/04/07 20:34:20 lhf Exp $
** load pre-compiled Lua chunks
** See Copyright Notice in lua.h
*/

#ifndef lundump_h
#define lundump_h

#include "lobject.h"
#include "lzio.h"

/* load one chunk; from lundump.c */
Ptr32<Proto> luaU_undump (Ptr32<lua_State> L, Ptr32<ZIO> Z, Ptr32<Mbuffer> buff);

/* find byte order; from lundump.c */
int luaU_endianness (void);

/* dump one chunk; from ldump.c */
void luaU_dump (Ptr32<lua_State> L, Ptr32<const Proto> Main, lua_Chunkwriter w, Ptr32<void> data);

/* print one chunk; from print.c */
void luaU_print (Ptr32<const Proto> Main);

/* definitions for headers of binary files */
#define	LUA_SIGNATURE	"\033Lua"	/* binary files start with "<esc>Lua" */
#define	VERSION		0x50		/* last format change was in 5.0 */
#define	VERSION0	0x50		/* last major  change was in 5.0 */

/* a multiple of PI for testing native format */
/* multiplying by 1E7 gives non-trivial integer values */
#define	TEST_NUMBER	((lua_Number)3.14159265358979323846E7)

#endif
