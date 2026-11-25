#include "w3d_ptr.h"
extern "C" {
#line 1 "lstring.c"
/*
** $Id: lstring.c,v 1.78 2002/12/04 17:38:31 roberto Exp $
** String table (keeps all strings handled by Lua)
** See Copyright Notice in lua.h
*/


#include <string.h>

#define lstring_c

#include "lua.h"

#include "lmem.h"
#include "lobject.h"
#include "lstate.h"
#include "lstring.h"



void luaS_freeall (Ptr32<lua_State> L) {
  lua_assert(G(L)->strt.nuse==0);
  luaM_freearray(L, G(L)->strt.hash, G(L)->strt.size, Ptr32<TString>);
}


void luaS_resize (Ptr32<lua_State> L, int newsize) {
  Ptr32<Ptr32<GCObject>> newhash = luaM_newvector(L, newsize, Ptr32<GCObject>);
  Ptr32<stringtable> tb = &G(L)->strt;
  int i;
  for (i=0; i<newsize; i++) newhash[i] = NULL;
  /* rehash */
  for (i=0; i<tb->size; i++) {
    Ptr32<GCObject> p = tb->hash[i];
    while (p) {  /* for each node in the list */
      Ptr32<GCObject> next = p->gch.next;  /* save next */
      lu_hash h = gcotots(p)->tsv.hash;
      int h1 = lmod(h, newsize);  /* new position */
      lua_assert(cast(int, h%newsize) == lmod(h, newsize));
      p->gch.next = newhash[h1];  /* chain it */
      newhash[h1] = p;
      p = next;
    }
  }
  luaM_freearray(L, tb->hash, tb->size, Ptr32<TString>);
  tb->size = newsize;
  tb->hash = newhash;
}


static Ptr32<TString> newlstr (Ptr32<lua_State> L, Ptr32<const char> str, size_t l, lu_hash h) {
  Ptr32<TString> ts = cast(TString *, luaM_malloc(L, sizestring(l)));
  Ptr32<stringtable> tb;
  ts->tsv.len = l;
  ts->tsv.hash = h;
  ts->tsv.marked = 0;
  ts->tsv.tt = LUA_TSTRING;
  ts->tsv.reserved = 0;
  memcpy(ts+1, str, l*sizeof(char));
  ((char *)(ts+1))[l] = '\0';  /* ending 0 */
  tb = &G(L)->strt;
  h = lmod(h, tb->size);
  ts->tsv.next = tb->hash[h];  /* chain new entry */
  tb->hash[h] = valtogco(ts);
  tb->nuse++;
  if (tb->nuse > cast(ls_nstr, tb->size) && tb->size <= MAX_INT/2)
    luaS_resize(L, tb->size*2);  /* too crowded */
  return ts;
}


Ptr32<TString> luaS_newlstr (Ptr32<lua_State> L, Ptr32<const char> str, size_t l) {
  Ptr32<GCObject> o;
  lu_hash h = (lu_hash)l;  /* seed */
  size_t step = (l>>5)+1;  /* if string is too long, don't hash all its chars */
  size_t l1;
  for (l1=l; l1>=step; l1-=step)  /* compute hash */
    h = h ^ ((h<<5)+(h>>2)+(unsigned char)(str[l1-1]));
  for (o = G(L)->strt.hash[lmod(h, G(L)->strt.size)];
       o != NULL;
       o = o->gch.next) {
    Ptr32<TString> ts = gcotots(o);
    if (ts->tsv.len == l && (memcmp(str, getstr(ts), l) == 0))
      return ts;
  }
  return newlstr(L, str, l, h);  /* not found */
}


Ptr32<Udata> luaS_newudata (Ptr32<lua_State> L, size_t s) {
  Ptr32<Udata> u;
  u = cast(Udata *, luaM_malloc(L, sizeudata(s)));
  u->uv.marked = (1<<1);  /* is not finalized */
  u->uv.tt = LUA_TUSERDATA;
  u->uv.len = s;
  u->uv.metatable = hvalue(defaultmeta(L));
  /* chain it on udata list */
  u->uv.next = G(L)->rootudata;
  G(L)->rootudata = valtogco(u);
  return u;
}


}
