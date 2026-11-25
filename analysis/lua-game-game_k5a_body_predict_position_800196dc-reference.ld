/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k5a_body_predict_position_800196dc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_f32_8036a93c = 0x8036a93c;
SECTIONS {
  .text.k5a_body_predict_position_800196dc 0x800196dc : { *(.text.k5a_body_predict_position_800196dc) }
  .sdata 0x804aa6d8 (NOLOAD) : {
    . = 0x0; w3d_clock_804aa6d8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
