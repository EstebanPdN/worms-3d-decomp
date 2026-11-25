/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24l_textbox_background_802b2e30)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__10D24lStringPCc = 0x8020bb54;
w3d_cast_80343df4 = 0x80343df4;
w3d_handle_set_name_8015adf4 = 0x8015adf4;
w3d_lookup_800fc1b0 = 0x800fc1b0;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_release_80341588 = 0x80341588;
SECTIONS {
  .text.d24l_textbox_background_802b2e30 0x802b2e30 : { *(.text.d24l_textbox_background_802b2e30) }
  .rodata 0x803d7c90 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
