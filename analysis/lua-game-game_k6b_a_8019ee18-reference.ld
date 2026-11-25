/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k6b_lua_iface_array_get_8019ee18)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lua_newuserdata = 0x802ce9d8;
lua_pushvalue = 0x802cd99c;
lua_setmetatable = 0x802ce5ec;
lua_touserdata = 0x802cde08;
w3d_s21_check_number_802dd10c = 0x802dd10c;
SECTIONS {
  .text.w3d_k6b_lua_iface_array_get_8019ee18 0x8019ee18 : { *(.text.w3d_k6b_lua_iface_array_get_8019ee18) }
  .sdata 0x804ab728 (NOLOAD) : {
    . = 0x0; lbl_804ab728 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
