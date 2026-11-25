/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc29a_controller_indicator_80024990)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc29a_encode_8018b2b0 = 0x8018b2b0;
cc29a_set_8018c5b0 = 0x8018c5b0;
cc29a_text_80343580 = 0x80343580;
SECTIONS {
  .text.cc29a_controller_indicator_80024990 0x80024990 : { *(.text.cc29a_controller_indicator_80024990) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
