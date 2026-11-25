/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(luaX_init)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
luaD_throw = 0x802cfc7c;
luaO_chunkid = 0x802d28fc;
luaO_pushfstring = 0x802d2868;
luaO_str2d = 0x802d2454;
luaS_newlstr = 0x802d5e30;
luaZ_fill = 0x802d9a50;
luaZ_openspace = 0x802d9c08;
strlen = 0x802ef9c0;
w3d_ctype_table = 0x803db448;
SECTIONS {
  .text.luaX_init 0x802db48c : { *(.text.luaX_init) }
  .text.luaX_checklimit 0x802db500 : { *(.text.luaX_checklimit) }
  .text.luaX_errorline 0x802db55c : { *(.text.luaX_errorline) }
  .text.luaX_error 0x802db5d4 : { *(.text.luaX_error) }
  .text.luaX_syntaxerror 0x802db5f8 : { *(.text.luaX_syntaxerror) }
  .text.luaX_token2str 0x802db678 : { *(.text.luaX_token2str) }
  .text.luaX_lexerror 0x802db6cc : { *(.text.luaX_lexerror) }
  .text.inclinenumber 0x802db730 : { *(.text.inclinenumber) }
  .text.luaX_setinput 0x802db7c0 : { *(.text.luaX_setinput) }
  .text.readname 0x802db8a4 : { *(.text.readname) }
  .text.read_numeral 0x802db98c : { *(.text.read_numeral) }
  .text.read_long_string 0x802dbdb8 : { *(.text.read_long_string) }
  .text.read_string 0x802dc120 : { *(.text.read_string) }
  .text.luaX_lex 0x802dc550 : { *(.text.luaX_lex) }
  .rodata 0x803da568 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
