/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(luaO_int2fb)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
luaD_growstack = 0x802cff34;
luaS_newlstr = 0x802d5e30;
strcat = 0x802ef108;
strcspn = 0x802ef380;
strlen = 0x802ef9c0;
strncat = 0x802efa70;
strncpy = 0x802efbfc;
w3d_ctype_table = 0x803db448;
w3d_lua_parse_number = 0x802d21f4;
SECTIONS {
  .text.luaO_int2fb 0x802d22ec : { *(.text.luaO_int2fb) }
  .text.luaO_log2 0x802d231c : { *(.text.luaO_log2) }
  .text.luaO_rawequalObj 0x802d23c0 : { *(.text.luaO_rawequalObj) }
  .text.luaO_str2d 0x802d2454 : { *(.text.luaO_str2d) }
  .text.pushstr 0x802d24ec : { *(.text.pushstr) }
  .text.luaO_chunkid 0x802d28fc : { *(.text.luaO_chunkid) }
  .rodata 0x803d9d18 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
