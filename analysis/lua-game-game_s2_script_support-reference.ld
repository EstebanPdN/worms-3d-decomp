/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_script_get_breakpoint_801029c8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lua_gettable = 0x802ce264;
lua_gettop = 0x802cd7f4;
lua_pcall = 0x802ce73c;
lua_pushstring = 0x802cdfd4;
lua_settop = 0x802cd808;
lua_type = 0x802cd9e8;
w3d_fn_800ffca4 = 0x800ffca4;
w3d_fn_801022ec = 0x801022ec;
w3d_fn_80102a34 = 0x80102a34;
w3d_get_800ffb60 = 0x800ffb60;
w3d_lua_panic = 0x80101f90;
w3d_str_80399394 = 0x80399394;
SECTIONS {
  .text.w3d_script_get_breakpoint_801029c8 0x801029c8 : { *(.text.w3d_script_get_breakpoint_801029c8) }
  .text.w3d_script_call_handler_801036f0 0x801036f0 : { *(.text.w3d_script_call_handler_801036f0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
