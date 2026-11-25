/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d29e_buffer_for_tag_802078b4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8020777c = 0x8020777c;
w3d_cx10b_record_buffer_grow_80207514 = 0x80207514;
SECTIONS {
  .text.w3d_d29e_buffer_for_tag_802078b4 0x802078b4 : { *(.text.w3d_d29e_buffer_for_tag_802078b4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
