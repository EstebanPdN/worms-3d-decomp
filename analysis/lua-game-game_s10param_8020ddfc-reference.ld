/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s10_registry_remove_8020ddfc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8020df08 = 0x8020df08;
fn_8020fd2c = 0x8020fd2c;
lbl_80463360 = 0x80463360;
SECTIONS {
  .text.w3d_s10_registry_remove_8020ddfc 0x8020ddfc : { *(.text.w3d_s10_registry_remove_8020ddfc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
