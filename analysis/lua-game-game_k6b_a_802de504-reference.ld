/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k6b_lua_gcinfo_802de504)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lua_getgccount = 0x802ce830;
lua_getgcthreshold = 0x802ce820;
lua_pushnumber = 0x802cdf40;
SECTIONS {
  .text.w3d_k6b_lua_gcinfo_802de504 0x802de504 : { *(.text.w3d_k6b_lua_gcinfo_802de504) }
  .rodata 0x803daa30 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
