/*
** $Id: lzio.h,v 1.15 2003/03/20 16:00:56 roberto Exp $
** Buffered streams
** See Copyright Notice in lua.h
*/


#ifndef lzio_h
#define lzio_h

#include "lua.h"


#define EOZ	(-1)			/* end of stream */

typedef struct Zio ZIO;


#define char2int(c)	cast(int, cast(unsigned char, (c)))

#define zgetc(z)  (((z)->n--)>0 ?  char2int(*(z)->p++) : luaZ_fill(z))

#define zname(z)	((z)->name)

void luaZ_init (Ptr32<ZIO> z, lua_Chunkreader reader, Ptr32<void> data, Ptr32<const char> name);
size_t luaZ_read (Ptr32<ZIO> z, Ptr32<void> b, size_t n);	/* read next n bytes */
int luaZ_lookahead (Ptr32<ZIO> z);



typedef struct Mbuffer {
  Ptr32<char> buffer;
  size_t buffsize;
} Mbuffer;


Ptr32<char> luaZ_openspace (Ptr32<lua_State> L, Ptr32<Mbuffer> buff, size_t n);

#define luaZ_initbuffer(L, buff) ((buff)->buffer = NULL, (buff)->buffsize = 0)

#define luaZ_sizebuffer(buff)	((buff)->buffsize)
#define luaZ_buffer(buff)	((buff)->buffer)

#define luaZ_resizebuffer(L, buff, size) \
	(luaM_reallocvector(L, (buff)->buffer, (buff)->buffsize, size, char), \
	(buff)->buffsize = size)

#define luaZ_freebuffer(L, buff)	luaZ_resizebuffer(L, buff, 0)


/* --------- Private Part ------------------ */

struct Zio {
  size_t n;			/* bytes still unread */
  Ptr32<const char> p;		/* current position in buffer */
  lua_Chunkreader reader;
  Ptr32<void> data;			/* additional data */
  Ptr32<const char> name;
};


int luaZ_fill (Ptr32<ZIO> z);

#endif
