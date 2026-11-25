/*
** $Id: lcode.h,v 1.38 2002/12/11 12:34:22 roberto Exp $
** Code generator for Lua
** See Copyright Notice in lua.h
*/

#ifndef lcode_h
#define lcode_h

#include "llex.h"
#include "lobject.h"
#include "lopcodes.h"
#include "lparser.h"


/*
** Marks the end of a patch list. It is an invalid value both as an absolute
** address, and as a list link (would link an element to itself).
*/
#define NO_JUMP (-1)


/*
** grep "ORDER OPR" if you change these enums
*/
typedef enum BinOpr {
  OPR_ADD, OPR_SUB, OPR_MULT, OPR_DIV, OPR_POW,
  OPR_CONCAT,
  OPR_NE, OPR_EQ,
  OPR_LT, OPR_LE, OPR_GT, OPR_GE,
  OPR_AND, OPR_OR,
  OPR_NOBINOPR
} BinOpr;

#define binopistest(op)	((op) >= OPR_NE)

typedef enum UnOpr { OPR_MINUS, OPR_NOT, OPR_NOUNOPR } UnOpr;


#define getcode(fs,e)	((fs)->f->code[(e)->info])

#define luaK_codeAsBx(fs,o,A,sBx)	luaK_codeABx(fs,o,A,(sBx)+MAXARG_sBx)

int luaK_code (Ptr32<FuncState> fs, Instruction i, int line);
int luaK_codeABx (Ptr32<FuncState> fs, OpCode o, int A, unsigned int Bx);
int luaK_codeABC (Ptr32<FuncState> fs, OpCode o, int A, int B, int C);
void luaK_fixline (Ptr32<FuncState> fs, int line);
void luaK_nil (Ptr32<FuncState> fs, int from, int n);
void luaK_reserveregs (Ptr32<FuncState> fs, int n);
void luaK_checkstack (Ptr32<FuncState> fs, int n);
int luaK_stringK (Ptr32<FuncState> fs, Ptr32<TString> s);
int luaK_numberK (Ptr32<FuncState> fs, lua_Number r);
void luaK_dischargevars (Ptr32<FuncState> fs, Ptr32<expdesc> e);
int luaK_exp2anyreg (Ptr32<FuncState> fs, Ptr32<expdesc> e);
void luaK_exp2nextreg (Ptr32<FuncState> fs, Ptr32<expdesc> e);
void luaK_exp2val (Ptr32<FuncState> fs, Ptr32<expdesc> e);
int luaK_exp2RK (Ptr32<FuncState> fs, Ptr32<expdesc> e);
void luaK_self (Ptr32<FuncState> fs, Ptr32<expdesc> e, Ptr32<expdesc> key);
void luaK_indexed (Ptr32<FuncState> fs, Ptr32<expdesc> t, Ptr32<expdesc> k);
void luaK_goiftrue (Ptr32<FuncState> fs, Ptr32<expdesc> e);
void luaK_goiffalse (Ptr32<FuncState> fs, Ptr32<expdesc> e);
void luaK_storevar (Ptr32<FuncState> fs, Ptr32<expdesc> var, Ptr32<expdesc> e);
void luaK_setcallreturns (Ptr32<FuncState> fs, Ptr32<expdesc> var, int nresults);
int luaK_jump (Ptr32<FuncState> fs);
void luaK_patchlist (Ptr32<FuncState> fs, int list, int target);
void luaK_patchtohere (Ptr32<FuncState> fs, int list);
void luaK_concat (Ptr32<FuncState> fs, Ptr32<int> l1, int l2);
int luaK_getlabel (Ptr32<FuncState> fs);
void luaK_prefix (Ptr32<FuncState> fs, UnOpr op, Ptr32<expdesc> v);
void luaK_infix (Ptr32<FuncState> fs, BinOpr op, Ptr32<expdesc> v);
void luaK_posfix (Ptr32<FuncState> fs, BinOpr op, Ptr32<expdesc> v1, Ptr32<expdesc> v2);


#endif
