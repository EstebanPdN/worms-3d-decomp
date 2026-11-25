/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(next)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
luaF_newproto = 0x802d0da4;
luaH_new = 0x802d68d8;
luaK_checkstack = 0x802da168;
luaK_code = 0x802db334;
luaK_codeABC = 0x802db414;
luaK_codeABx = 0x802db454;
luaK_concat = 0x802da0ec;
luaK_dischargevars = 0x802da46c;
luaK_exp2RK = 0x802da984;
luaK_exp2anyreg = 0x802da8d0;
luaK_exp2nextreg = 0x802da874;
luaK_exp2val = 0x802da94c;
luaK_fixline = 0x802db318;
luaK_getlabel = 0x802d9e1c;
luaK_goiffalse = 0x802dad44;
luaK_goiftrue = 0x802dac98;
luaK_indexed = 0x802daecc;
luaK_infix = 0x802dafd4;
luaK_jump = 0x802d9d08;
luaK_nil = 0x802d9c64;
luaK_numberK = 0x802da398;
luaK_patchlist = 0x802da068;
luaK_patchtohere = 0x802da0ac;
luaK_posfix = 0x802db120;
luaK_prefix = 0x802daf08;
luaK_reserveregs = 0x802da1c8;
luaK_self = 0x802dab1c;
luaK_setcallreturns = 0x802da40c;
luaK_storevar = 0x802daa1c;
luaK_stringK = 0x802da364;
luaM_growaux = 0x802d2068;
luaM_realloc = 0x802d2108;
luaO_int2fb = 0x802d22ec;
luaO_log2 = 0x802d231c;
luaO_pushfstring = 0x802d2868;
luaS_newlstr = 0x802d5e30;
luaX_checklimit = 0x802db500;
luaX_lex = 0x802dc550;
luaX_setinput = 0x802db7c0;
luaX_syntaxerror = 0x802db5f8;
luaX_token2str = 0x802db678;
strlen = 0x802ef9c0;
SECTIONS {
  .text.next 0x802d2a34 : { *(.text.next) }
  .text.lookahead 0x802d2a9c : { *(.text.lookahead) }
  .text.error_expected 0x802d2ad0 : { *(.text.error_expected) }
  .text.testnext 0x802d2b24 : { *(.text.testnext) }
  .text.check 0x802d2b60 : { *(.text.check) }
  .text.check_match 0x802d2ba4 : { *(.text.check_match) }
  .text.str_checkname 0x802d2c4c : { *(.text.str_checkname) }
  .text.init_exp 0x802d2c9c : { *(.text.init_exp) }
  .text.codestring 0x802d2cb4 : { *(.text.codestring) }
  .text.checkname 0x802d2cf8 : { *(.text.checkname) }
  .text.luaI_registerlocalvar 0x802d2d38 : { *(.text.luaI_registerlocalvar) }
  .text.new_localvar 0x802d2dc4 : { *(.text.new_localvar) }
  .text.adjustlocalvars 0x802d2e34 : { *(.text.adjustlocalvars) }
  .text.removevars 0x802d2e88 : { *(.text.removevars) }
  .text.new_localvarstr 0x802d2ed4 : { *(.text.new_localvarstr) }
  .text.create_local 0x802d2f30 : { *(.text.create_local) }
  .text.indexupvalue 0x802d2f6c : { *(.text.indexupvalue) }
  .text.searchvar 0x802d30a4 : { *(.text.searchvar) }
  .text.markupval 0x802d30f0 : { *(.text.markupval) }
  .text.singlevaraux 0x802d3124 : { *(.text.singlevaraux) }
  .text.singlevar 0x802d3204 : { *(.text.singlevar) }
  .text.adjust_assign 0x802d3254 : { *(.text.adjust_assign) }
  .text.code_params 0x802d32fc : { *(.text.code_params) }
  .text.enterblock 0x802d3380 : { *(.text.enterblock) }
  .text.leaveblock 0x802d33ac : { *(.text.leaveblock) }
  .text.pushclosure 0x802d3424 : { *(.text.pushclosure) }
  .text.open_func 0x802d352c : { *(.text.open_func) }
  .text.close_func 0x802d35d0 : { *(.text.close_func) }
  .text.luaY_parser 0x802d371c : { *(.text.luaY_parser) }
  .text.luaY_field 0x802d37c8 : { *(.text.luaY_field) }
  .text.luaY_index 0x802d3824 : { *(.text.luaY_index) }
  .text.recfield 0x802d3878 : { *(.text.recfield) }
  .text.closelistfield 0x802d3960 : { *(.text.closelistfield) }
  .text.lastlistfield 0x802d39e0 : { *(.text.lastlistfield) }
  .text.listfield 0x802d3a8c : { *(.text.listfield) }
  .text.constructor 0x802d3af0 : { *(.text.constructor) }
  .text.parlist 0x802d3c9c : { *(.text.parlist) }
  .text.body 0x802d3d58 : { *(.text.body) }
  .text.explist1 0x802d3e08 : { *(.text.explist1) }
  .text.funcargs 0x802d3e74 : { *(.text.funcargs) }
  .text.prefixexp 0x802d3ff4 : { *(.text.prefixexp) }
  .text.primaryexp 0x802d4098 : { *(.text.primaryexp) }
  .text.simpleexp 0x802d4198 : { *(.text.simpleexp) }
  .text.getunopr 0x802d42bc : { *(.text.getunopr) }
  .text.getbinopr 0x802d42e4 : { *(.text.getbinopr) }
  .text.subexpr 0x802d43f4 : { *(.text.subexpr) }
  .text.expr 0x802d4534 : { *(.text.expr) }
  .text.block_follow 0x802d4558 : { *(.text.block_follow) }
  .text.block 0x802d4590 : { *(.text.block) }
  .text.check_conflict 0x802d45dc : { *(.text.check_conflict) }
  .text.assignment 0x802d4688 : { *(.text.assignment) }
  .text.cond 0x802d47dc : { *(.text.cond) }
  .text.whilestat 0x802d4838 : { *(.text.whilestat) }
  .text.repeatstat 0x802d4a00 : { *(.text.repeatstat) }
  .text.exp1 0x802d4a94 : { *(.text.exp1) }
  .text.forbody 0x802d4ad8 : { *(.text.forbody) }
  .text.fornum 0x802d4bd4 : { *(.text.fornum) }
  .text.forlist 0x802d4cf0 : { *(.text.forlist) }
  .text.forstat 0x802d4dfc : { *(.text.forstat) }
  .text.test_then_block 0x802d4ec4 : { *(.text.test_then_block) }
  .text.ifstat 0x802d4f14 : { *(.text.ifstat) }
  .text.localfunc 0x802d5008 : { *(.text.localfunc) }
  .text.localstat 0x802d5098 : { *(.text.localstat) }
  .text.funcname 0x802d5140 : { *(.text.funcname) }
  .text.funcstat 0x802d51b4 : { *(.text.funcstat) }
  .text.exprstat 0x802d5224 : { *(.text.exprstat) }
  .text.retstat 0x802d5294 : { *(.text.retstat) }
  .text.breakstat 0x802d538c : { *(.text.breakstat) }
  .text.statement 0x802d543c : { *(.text.statement) }
  .text.chunk 0x802d55a8 : { *(.text.chunk) }
  .rodata 0x803d9e64 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
