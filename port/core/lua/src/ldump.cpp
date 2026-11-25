#include "w3d_ptr.h"
extern "C" {
#line 1 "ldump.c"
/*
** $Id: ldump.c,v 1.4 2003/02/11 23:52:12 lhf Exp $
** save bytecodes
** See Copyright Notice in lua.h
*/

#include <stddef.h>

#define ldump_c

#include "lua.h"

#include "lobject.h"
#include "lopcodes.h"
#include "lstate.h"
#include "lundump.h"

#define DumpVector(b,n,size,D)	DumpBlock(b,(n)*(size),D)
#define DumpLiteral(s,D)	DumpBlock("" s,(sizeof(s))-1,D)

typedef struct {
 Ptr32<lua_State> L;
 lua_Chunkwriter write;
 Ptr32<void> data;
} DumpState;

static void DumpBlock(Ptr32<const void> b, size_t size, Ptr32<DumpState> D)
{
 lua_unlock(D->L);
 (*D->write)(D->L,b,size,D->data);
 lua_lock(D->L);
}

static void DumpByte(int y, Ptr32<DumpState> D)
{
 char x=(char)y;
 DumpBlock(&x,sizeof(x),D);
}

static void DumpInt(int x, Ptr32<DumpState> D)
{
 DumpBlock(&x,sizeof(x),D);
}

static void DumpSize(size_t x, Ptr32<DumpState> D)
{
 DumpBlock(&x,sizeof(x),D);
}

static void DumpNumber(lua_Number x, Ptr32<DumpState> D)
{
 DumpBlock(&x,sizeof(x),D);
}

static void DumpString(Ptr32<TString> s, Ptr32<DumpState> D)
{
 if (s==NULL || getstr(s)==NULL)
  DumpSize(0,D);
 else
 {
  size_t size=s->tsv.len+1;		/* include trailing '\0' */
  DumpSize(size,D);
  DumpBlock(getstr(s),size,D);
 }
}

static void DumpCode(Ptr32<const Proto> f, Ptr32<DumpState> D)
{
 DumpInt(f->sizecode,D);
 DumpVector(f->code,f->sizecode,sizeof(*f->code),D);
}

static void DumpLocals(Ptr32<const Proto> f, Ptr32<DumpState> D)
{
 int i,n=f->sizelocvars;
 DumpInt(n,D);
 for (i=0; i<n; i++)
 {
  DumpString(f->locvars[i].varname,D);
  DumpInt(f->locvars[i].startpc,D);
  DumpInt(f->locvars[i].endpc,D);
 }
}

static void DumpLines(Ptr32<const Proto> f, Ptr32<DumpState> D)
{
 DumpInt(f->sizelineinfo,D);
 DumpVector(f->lineinfo,f->sizelineinfo,sizeof(*f->lineinfo),D);
}

static void DumpUpvalues(Ptr32<const Proto> f, Ptr32<DumpState> D)
{
 int i,n=f->sizeupvalues;
 DumpInt(n,D);
 for (i=0; i<n; i++) DumpString(f->upvalues[i],D);
}

static void DumpFunction(Ptr32<const Proto> f, Ptr32<const TString> p, Ptr32<DumpState> D);

static void DumpConstants(Ptr32<const Proto> f, Ptr32<DumpState> D)
{
 int i,n;
 DumpInt(n=f->sizek,D);
 for (i=0; i<n; i++)
 {
  Ptr32<const TObject> o=&f->k[i];
  DumpByte(ttype(o),D);
  switch (ttype(o))
  {
   case LUA_TNUMBER:
	DumpNumber(nvalue(o),D);
	break;
   case LUA_TSTRING:
	DumpString(tsvalue(o),D);
	break;
   case LUA_TNIL:
	break;
   default:
	lua_assert(0);			/* cannot happen */
	break;
  }
 }
 DumpInt(n=f->sizep,D);
 for (i=0; i<n; i++) DumpFunction(f->p[i],f->source,D);
}

static void DumpFunction(Ptr32<const Proto> f, Ptr32<const TString> p, Ptr32<DumpState> D)
{
 DumpString((f->source==p) ? NULL : f->source,D);
 DumpInt(f->lineDefined,D);
 DumpByte(f->nups,D);
 DumpByte(f->numparams,D);
 DumpByte(f->is_vararg,D);
 DumpByte(f->maxstacksize,D);
 DumpLines(f,D);
 DumpLocals(f,D);
 DumpUpvalues(f,D);
 DumpConstants(f,D);
 DumpCode(f,D);
}

static void DumpHeader(Ptr32<DumpState> D)
{
 DumpLiteral(LUA_SIGNATURE,D);
 DumpByte(VERSION,D);
 DumpByte(luaU_endianness(),D);
 DumpByte(sizeof(int),D);
 DumpByte(sizeof(size_t),D);
 DumpByte(sizeof(Instruction),D);
 DumpByte(SIZE_OP,D);
 DumpByte(SIZE_A,D);
 DumpByte(SIZE_B,D);
 DumpByte(SIZE_C,D);
 DumpByte(sizeof(lua_Number),D);
 DumpNumber(TEST_NUMBER,D);
}

/*
** dump function as precompiled chunk
*/
void luaU_dump (Ptr32<lua_State> L, Ptr32<const Proto> Main, lua_Chunkwriter w, Ptr32<void> data)
{
 DumpState D;
 D.L=L;
 D.write=w;
 D.data=data;
 DumpHeader(&D);
 DumpFunction(Main,NULL,&D);
}


}
