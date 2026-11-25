/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc36b_curve_prepare_801968e8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc36b_curve_scratch_804a91d8 = 0x804a91d8;
SECTIONS {
  .text.w3d_cc36b_curve_prepare_801968e8 0x801968e8 : { *(.text.w3d_cc36b_curve_prepare_801968e8) }
  .rodata 0x803a84d8 : { *(.rodata) }
  .sdata 0x804b18d0 (NOLOAD) : {
    . = 0x0; cc36b_curve_origin_804b18d0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
