/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx9c_floorf_802e87d4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_cx9c_floorf_802e87d4 0x802e87d4 : { *(.text.w3d_cx9c_floorf_802e87d4) }
  .sdata 0x804ac2e0 (NOLOAD) : {
    . = 0x0; cx9c_huge_804ac2e0 = .;
    . = 0x4; cx9c_zero_804ac2e4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
