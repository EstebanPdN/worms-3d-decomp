/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_release_slot_node_80173504)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801720c0 = 0x801720c0;
fn_801859f8 = 0x801859f8;
fn_801ef048 = 0x801ef048;
fn_80343808 = 0x80343808;
SECTIONS {
  .text.w3d_release_slot_node_80173504 0x80173504 : { *(.text.w3d_release_slot_node_80173504) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
