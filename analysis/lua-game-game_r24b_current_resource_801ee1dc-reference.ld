/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_r24b_current_resource_801ee1dc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_r24b_current_resource_801ee1dc 0x801ee1dc : { *(.text.w3d_r24b_current_resource_801ee1dc) }
  .sdata 0x804b05b0 (NOLOAD) : {
    . = 0x0; r24b_current_resource_804b05b0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
