/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k4b_script_run_buffer_8019df00)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
luaL_loadbuffer = 0x802ddbd8;
lua_call = 0x802ce6e4;
SECTIONS {
  .text.w3d_k4b_script_run_buffer_8019df00 0x8019df00 : { *(.text.w3d_k4b_script_run_buffer_8019df00) }
  .rodata 0x803a9910 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
