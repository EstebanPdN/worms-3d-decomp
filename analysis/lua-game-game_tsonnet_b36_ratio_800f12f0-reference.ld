/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(tsonnet_b36_ratio_800f12f0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80178d1c = 0x80178d1c;
fn_80342a78 = 0x80342a78;
lbl_8038c30c = 0x8038c30c;
lbl_8038c310 = 0x8038c310;
SECTIONS {
  .text.tsonnet_b36_ratio_800f12f0 0x800f12f0 : { *(.text.tsonnet_b36_ratio_800f12f0) }
  .rodata 0x8038c318 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
