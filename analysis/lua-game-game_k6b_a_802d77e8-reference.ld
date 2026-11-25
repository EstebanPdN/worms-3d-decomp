/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k6b_lua_undump_load_header_802d77e8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
LoadNumber = 0x802d7220;
LoadSignature = 0x802d770c;
TestSize = 0x802d7788;
ezgetc = 0x802d6fd0;
luaG_runerror = 0x802cfb10;
w3d_constant_802d7a54 = 0x802d7a54;
SECTIONS {
  .text.w3d_k6b_lua_undump_load_header_802d77e8 0x802d77e8 : { *(.text.w3d_k6b_lua_undump_load_header_802d77e8) }
  .rodata 0x803da318 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
