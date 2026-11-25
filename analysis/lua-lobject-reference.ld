/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(luaO_int2fb)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
luaD_growstack = 0x802cff34;
luaS_newlstr = 0x802d5e30;
strlen = 0x802ef9c0;
SECTIONS {
  .text.luaO_int2fb 0x802d22ec : { *(.text.luaO_int2fb) }
  .text.luaO_log2 0x802d231c : { *(.text.luaO_log2) }
  .text.luaO_rawequalObj 0x802d23c0 : { *(.text.luaO_rawequalObj) }
  .text.pushstr 0x802d24ec : { *(.text.pushstr) }
  .text.luaO_pushvfstring 0x802d256c : { *(.text.luaO_pushvfstring) }
  .text.luaO_pushfstring 0x802d2868 : { *(.text.luaO_pushfstring) }
  .rodata 0x803d9d18 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
