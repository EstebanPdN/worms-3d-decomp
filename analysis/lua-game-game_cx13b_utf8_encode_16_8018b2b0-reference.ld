/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx13b_utf8_encode_16_8018b2b0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_cx13b_utf8_encode_16_8018b2b0 0x8018b2b0 : { *(.text.w3d_cx13b_utf8_encode_16_8018b2b0) }
  .sdata 0x804b0234 (NOLOAD) : {
    . = 0x0; buffer_804b0234 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
