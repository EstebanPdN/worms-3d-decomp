/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k6b_lua_callalert_802ddc0c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fprintf = 0x802eb50c;
lbl_803da898 = 0x803da898;
lbl_803da8a0 = 0x803da8a0;
lua_call = 0x802ce6e4;
lua_gettable = 0x802ce264;
lua_insert = 0x802cd8e0;
lua_pushstring = 0x802cdfd4;
lua_settop = 0x802cd808;
lua_tostring = 0x802cdd04;
lua_type = 0x802cd9e8;
SECTIONS {
  .text.w3d_k6b_lua_callalert_802ddc0c 0x802ddc0c : { *(.text.w3d_k6b_lua_callalert_802ddc0c) }
  .sdata 0x804ac570 (NOLOAD) : {
    . = 0x0; _impure_ptr = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
