/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8003cfbc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_auto_8003cfbc 0x8003cfbc : { *(.text.w3d_auto_8003cfbc) }
  .text.w3d_auto_800a1524 0x800a1524 : { *(.text.w3d_auto_800a1524) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; lbl_804B1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
