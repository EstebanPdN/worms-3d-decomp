/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(luaK_nil)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
luaH_get = 0x802d6ca0;
luaH_set = 0x802d6d30;
luaM_growaux = 0x802d2068;
luaP_opmodes = 0x803d9e40;
luaX_syntaxerror = 0x802db5f8;
SECTIONS {
  .text.luaK_nil 0x802d9c64 : { *(.text.luaK_nil) }
  .text.luaK_jump 0x802d9d08 : { *(.text.luaK_jump) }
  .text.luaK_condjump 0x802d9d68 : { *(.text.luaK_condjump) }
  .text.luaK_fixjump 0x802d9d9c : { *(.text.luaK_fixjump) }
  .text.luaK_getlabel 0x802d9e1c : { *(.text.luaK_getlabel) }
  .text.luaK_getjump 0x802d9e2c : { *(.text.luaK_getjump) }
  .text.getjumpcontrol 0x802d9e64 : { *(.text.getjumpcontrol) }
  .text.need_value 0x802d9ea0 : { *(.text.need_value) }
  .text.patchtestreg 0x802d9f24 : { *(.text.patchtestreg) }
  .text.luaK_patchlistaux 0x802d9f4c : { *(.text.luaK_patchlistaux) }
  .text.luaK_dischargejpc 0x802da01c : { *(.text.luaK_dischargejpc) }
  .text.luaK_patchlist 0x802da068 : { *(.text.luaK_patchlist) }
  .text.luaK_patchtohere 0x802da0ac : { *(.text.luaK_patchtohere) }
  .text.luaK_concat 0x802da0ec : { *(.text.luaK_concat) }
  .text.luaK_checkstack 0x802da168 : { *(.text.luaK_checkstack) }
  .text.luaK_reserveregs 0x802da1c8 : { *(.text.luaK_reserveregs) }
  .text.freereg 0x802da204 : { *(.text.freereg) }
  .text.freeexp 0x802da228 : { *(.text.freeexp) }
  .text.addk 0x802da258 : { *(.text.addk) }
  .text.luaK_stringK 0x802da364 : { *(.text.luaK_stringK) }
  .text.luaK_numberK 0x802da398 : { *(.text.luaK_numberK) }
  .text.nil_constant 0x802da3cc : { *(.text.nil_constant) }
  .text.luaK_setcallreturns 0x802da40c : { *(.text.luaK_setcallreturns) }
  .text.luaK_dischargevars 0x802da46c : { *(.text.luaK_dischargevars) }
  .text.code_label 0x802da560 : { *(.text.code_label) }
  .text.discharge2reg 0x802da5b0 : { *(.text.discharge2reg) }
  .text.discharge2anyreg 0x802da6d0 : { *(.text.discharge2anyreg) }
  .text.luaK_exp2reg 0x802da724 : { *(.text.luaK_exp2reg) }
  .text.luaK_exp2nextreg 0x802da874 : { *(.text.luaK_exp2nextreg) }
  .text.luaK_exp2anyreg 0x802da8d0 : { *(.text.luaK_exp2anyreg) }
  .text.luaK_exp2val 0x802da94c : { *(.text.luaK_exp2val) }
  .text.luaK_exp2RK 0x802da984 : { *(.text.luaK_exp2RK) }
  .text.luaK_storevar 0x802daa1c : { *(.text.luaK_storevar) }
  .text.luaK_self 0x802dab1c : { *(.text.luaK_self) }
  .text.invertjump 0x802dabac : { *(.text.invertjump) }
  .text.jumponcond 0x802dabe8 : { *(.text.jumponcond) }
  .text.luaK_goiftrue 0x802dac98 : { *(.text.luaK_goiftrue) }
  .text.luaK_goiffalse 0x802dad44 : { *(.text.luaK_goiffalse) }
  .text.codenot 0x802dade4 : { *(.text.codenot) }
  .text.luaK_indexed 0x802daecc : { *(.text.luaK_indexed) }
  .text.luaK_prefix 0x802daf08 : { *(.text.luaK_prefix) }
  .text.luaK_infix 0x802dafd4 : { *(.text.luaK_infix) }
  .text.codebinop 0x802db08c : { *(.text.codebinop) }
  .text.luaK_posfix 0x802db120 : { *(.text.luaK_posfix) }
  .text.luaK_fixline 0x802db318 : { *(.text.luaK_fixline) }
  .text.luaK_code 0x802db334 : { *(.text.luaK_code) }
  .text.luaK_codeABC 0x802db414 : { *(.text.luaK_codeABC) }
  .text.luaK_codeABx 0x802db454 : { *(.text.luaK_codeABx) }
  .rodata 0x803da4d8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
