/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_validate_and_flag_801745bc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_s20_validate_and_flag_801745bc 0x801745bc : { *(.text.w3d_s20_validate_and_flag_801745bc) }
  .text.w3d_s20_release_held_80174620 0x80174620 : { *(.text.w3d_s20_release_held_80174620) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
