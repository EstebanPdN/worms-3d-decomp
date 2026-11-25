/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24l_text_list_lines_8029f598)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__10D24lStringPCc = 0x8020bb54;
fn_8020c0fc = 0x8020c0fc;
fn_8029f48c = 0x8029f48c;
fn_8029f714 = 0x8029f714;
lbl_804b06a0 = 0x804b06a0;
strchr = 0x802ef198;
w3d_release_header_8020bb2c = 0x8020bb2c;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_header_80341884 = 0x80341884;
w3d_string_init_8020c5c0 = 0x8020c5c0;
w3d_string_release_80341588 = 0x80341588;
w3d_truncate_8020c3a0 = 0x8020c3a0;
SECTIONS {
  .text.d24l_text_list_lines_8029f598 0x8029f598 : { *(.text.d24l_text_list_lines_8029f598) }
  .rodata 0x803d1dd8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
