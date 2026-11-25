/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24z_floor_802e75d0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_d24z_floor_802e75d0 0x802e75d0 : { *(.text.w3d_d24z_floor_802e75d0) }
  .sdata 0x804ac100 (NOLOAD) : {
    . = 0x0; d24z_huge_804ac100 = .;
    . = 0x8; d24z_lit_d_0_804ac108 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
