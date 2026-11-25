/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k6b_lua_loadfile_802dda0c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__srget = 0x802ec1fc;
_ctype_ = 0x803db448;
fclose = 0x802eafcc;
fopen = 0x802eb4b4;
lua_gettop = 0x802cd7f4;
lua_load = 0x802ce7c0;
lua_pushfstring = 0x802ce07c;
lua_pushlstring = 0x802cdf60;
lua_remove = 0x802cd878;
lua_settop = 0x802cd808;
lua_tostring = 0x802cdd04;
ungetc = 0x802ec584;
w3d_k6b_lua_errfile_802dd9a0 = 0x802dd9a0;
w3d_k6b_lua_getF_802dd934 = 0x802dd934;
SECTIONS {
  .text.w3d_k6b_lua_loadfile_802dda0c 0x802dda0c : { *(.text.w3d_k6b_lua_loadfile_802dda0c) }
  .rodata 0x803da884 : { *(.rodata) }
  .sdata 0x804ac570 (NOLOAD) : {
    . = 0x0; _impure_ptr = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
