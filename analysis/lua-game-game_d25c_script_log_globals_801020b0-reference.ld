/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25c_script_log_globals_801020b0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
log_801022b0 = 0x801022b0;
lua_next = 0x802ce8c0;
lua_pushnil = 0x802cdf24;
lua_settop = 0x802cd808;
lua_tostring = 0x802cdd04;
lua_type = 0x802cd9e8;
string_append_8020bf2c = 0x8020bf2c;
string_finish_8020c5c4 = 0x8020c5c4;
string_header_80341884 = 0x80341884;
string_init_8020c5c0 = 0x8020c5c0;
string_release_80341588 = 0x80341588;
SECTIONS {
  .text.d25c_script_log_globals_801020b0 0x801020b0 : { *(.text.d25c_script_log_globals_801020b0) }
  .rodata 0x80398dd8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
