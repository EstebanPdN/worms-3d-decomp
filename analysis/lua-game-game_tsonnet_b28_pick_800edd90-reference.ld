/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(tsonnet_b28_pick_800edd90)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80161080 = 0x80161080;
fn_801797b4 = 0x801797b4;
fn_8020bb2c = 0x8020bb2c;
fn_8020bd38 = 0x8020bd38;
fn_80341584 = 0x80341584;
lbl_8038b568 = 0x8038b568;
SECTIONS {
  .text.tsonnet_b28_pick_800edd90 0x800edd90 : { *(.text.tsonnet_b28_pick_800edd90) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
