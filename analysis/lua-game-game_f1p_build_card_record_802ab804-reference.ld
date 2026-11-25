/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_build_card_record_802ab804)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802efbfc = 0x802efbfc;
fn_802fa988 = 0x802fa988;
SECTIONS {
  .text.w3d_build_card_record_802ab804 0x802ab804 : { *(.text.w3d_build_card_record_802ab804) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
