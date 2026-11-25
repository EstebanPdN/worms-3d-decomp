/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24l_textbox_cursor_802a2524)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__10D24lStringPCc = 0x8020bb54;
w3d_as_8034357c = 0x8034357c;
w3d_read_800fc270 = 0x800fc270;
w3d_set_name_8015adf4 = 0x8015adf4;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_release_80341588 = 0x80341588;
SECTIONS {
  .text.d24l_textbox_cursor_802a2524 0x802a2524 : { *(.text.d24l_textbox_cursor_802a2524) }
  .rodata 0x803d1f94 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
