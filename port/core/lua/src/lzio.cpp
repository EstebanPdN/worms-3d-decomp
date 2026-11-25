#include "w3d_ptr.h"
extern "C" {
#line 1 "lzio.c"
/*
** $Id: lzio.c,v 1.24 2003/03/20 16:00:56 roberto Exp $
** a generic input stream interface
** See Copyright Notice in lua.h
*/


#include <string.h>

#define lzio_c

#include "lua.h"

#include "llimits.h"
#include "lmem.h"
#include "lzio.h"


int luaZ_fill (Ptr32<ZIO> z) {
  size_t size;
  Ptr32<const char> buff = z->reader(NULL, z->data, &size);
  if (buff == NULL || size == 0) return EOZ;
  z->n = size - 1;
  z->p = buff;
  return char2int(*(z->p++));
}


int luaZ_lookahead (Ptr32<ZIO> z) {
  if (z->n == 0) {
    int c = luaZ_fill(z);
    if (c == EOZ) return c;
    z->n++;
    z->p--;
  }
  return char2int(*z->p);
}


void luaZ_init (Ptr32<ZIO> z, lua_Chunkreader reader, Ptr32<void> data, Ptr32<const char> name) {
  z->reader = reader;
  z->data = data;
  z->name = name;
  z->n = 0;
  z->p = NULL;
}


/* --------------------------------------------------------------- read --- */
size_t luaZ_read (Ptr32<ZIO> z, Ptr32<void> b, size_t n) {
  while (n) {
    size_t m;
    if (z->n == 0) {
      if (luaZ_fill(z) == EOZ)
        return n;  /* return number of missing bytes */
      else {
        ++z->n;  /* filbuf removed first byte; put back it */
        --z->p;
      }
    }
    m = (n <= z->n) ? n : z->n;  /* min. between n and z->n */
    memcpy(b, z->p, m);
    z->n -= m;
    z->p += m;
    b = (char *)b + m;
    n -= m;
  }
  return 0;
}

/* ------------------------------------------------------------------------ */
Ptr32<char> luaZ_openspace (Ptr32<lua_State> L, Ptr32<Mbuffer> buff, size_t n) {
  if (n > buff->buffsize) {
    if (n < LUA_MINBUFFER) n = LUA_MINBUFFER;
    luaM_reallocvector(L, buff->buffer, buff->buffsize, n, char);
    buff->buffsize = n;
  }
  return buff->buffer;
}



}
