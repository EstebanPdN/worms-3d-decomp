/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k6b_lua_print_802ddd4c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fputs = 0x802eb5a0;
lbl_803da8a8 = 0x803da8a8;
lbl_803da8b4 = 0x803da8b4;
lbl_803da8e0 = 0x803da8e0;
lbl_803da8e4 = 0x803da8e4;
luaL_error = 0x802dce74;
lua_call = 0x802ce6e4;
lua_gettable = 0x802ce264;
lua_gettop = 0x802cd7f4;
lua_pushstring = 0x802cdfd4;
lua_pushvalue = 0x802cd99c;
lua_settop = 0x802cd808;
lua_tostring = 0x802cdd04;
SECTIONS {
  .text.w3d_k6b_lua_print_802ddd4c 0x802ddd4c : { *(.text.w3d_k6b_lua_print_802ddd4c) }
  .sdata 0x804ac570 (NOLOAD) : {
    . = 0x0; _impure_ptr = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
