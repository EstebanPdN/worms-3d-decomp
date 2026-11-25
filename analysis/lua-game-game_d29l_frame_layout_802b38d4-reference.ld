/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d29l_frame_layout_802b38d4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802ae5f8 = 0x802ae5f8;
SECTIONS {
  .text.d29l_frame_layout_802b38d4 0x802b38d4 : { *(.text.d29l_frame_layout_802b38d4) }
  .rodata 0x803d7cf4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
