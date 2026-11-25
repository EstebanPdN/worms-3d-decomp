/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_collect_crate_copy_80017e28)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__20W3dCostBase_80006360 = 0x80006360;
_vt.15W3dCollectCrate = 0x8040d958;
SECTIONS {
  .text.w3d_collect_crate_copy_80017e28 0x80017e28 : { *(.text.w3d_collect_crate_copy_80017e28) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
