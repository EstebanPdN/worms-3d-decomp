/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc17b_display_list_save_8016afc8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80166fd0 = 0x80166fd0;
fn_802eee50 = 0x802eee50;
fn_802fa988 = 0x802fa988;
fn_8030bd80 = 0x8030bd80;
SECTIONS {
  .text.w3d_cc17b_display_list_save_8016afc8 0x8016afc8 : { *(.text.w3d_cc17b_display_list_save_8016afc8) }
  .sdata 0x804b1884 (NOLOAD) : {
    . = 0x0; allocator_804b1884 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
