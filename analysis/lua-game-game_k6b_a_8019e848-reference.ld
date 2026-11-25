/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k6b_lua_send_message_8019e848)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801ef200 = 0x801ef200;
lua_touserdata = 0x802cde08;
w3d_s21_check_number_802dd10c = 0x802dd10c;
SECTIONS {
  .text.w3d_k6b_lua_send_message_8019e848 0x8019e848 : { *(.text.w3d_k6b_lua_send_message_8019e848) }
  .sdata 0x804ab728 (NOLOAD) : {
    . = 0x0; lbl_804ab728 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
