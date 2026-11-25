/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k6b_lua_iface_array_set_8019ed40)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8019e96c = 0x8019e96c;
lua_isuserdata = 0x802cdb24;
lua_pushvalue = 0x802cd99c;
lua_touserdata = 0x802cde08;
lua_type = 0x802cd9e8;
w3d_auto_801fffc8 = 0x801fffc8;
w3d_k5b_iface_array_field_set_801ef2ec = 0x801ef2ec;
w3d_s21_check_number_802dd10c = 0x802dd10c;
SECTIONS {
  .text.w3d_k6b_lua_iface_array_set_8019ed40 0x8019ed40 : { *(.text.w3d_k6b_lua_iface_array_set_8019ed40) }
  .sdata 0x804ab728 (NOLOAD) : {
    . = 0x0; lbl_804ab728 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
