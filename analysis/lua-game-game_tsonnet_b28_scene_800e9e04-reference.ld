/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(tsonnet_b28_scene_800e9e04)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015adf4 = 0x8015adf4;
fn_801797b4 = 0x801797b4;
fn_80341584 = 0x80341584;
lbl_8038b1f8 = 0x8038b1f8;
strcmp = 0x802ef234;
SECTIONS {
  .text.tsonnet_b28_scene_800e9e04 0x800e9e04 : { *(.text.tsonnet_b28_scene_800e9e04) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
