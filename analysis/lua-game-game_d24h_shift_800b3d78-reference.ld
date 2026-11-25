/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24h_shift_800b3d78)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_d24h_shift_800b3d78 0x800b3d78 : { *(.text.w3d_d24h_shift_800b3d78) }
  .sdata 0x804b17e0 (NOLOAD) : {
    . = 0x0; lbl_804b17e0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
