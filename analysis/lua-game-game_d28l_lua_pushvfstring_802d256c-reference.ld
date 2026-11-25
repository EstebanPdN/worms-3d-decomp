/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d28l_lua_pushvfstring_802d256c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
luaD_growstack = 0x802cff34;
luaS_newlstr = 0x802d5e30;
luaV_concat = 0x802d8698;
pushstr = 0x802d24ec;
s_803d9e18 = 0x803d9e18;
s_803d9e1c = 0x803d9e1c;
strchr = 0x802ef198;
SECTIONS {
  .text.d28l_lua_pushvfstring_802d256c 0x802d256c : { *(.text.d28l_lua_pushvfstring_802d256c) }
  .rodata 0x803d9e20 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
