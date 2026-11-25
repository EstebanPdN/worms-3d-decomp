/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k6b_node_init_8020fc60)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8020fe64 = 0x8020fe64;
lbl_80419598 = 0x80419598;
lbl_804195c0 = 0x804195c0;
w3d_auto_801ffe58 = 0x801ffe58;
SECTIONS {
  .text.w3d_k6b_node_init_8020fc60 0x8020fc60 : { *(.text.w3d_k6b_node_init_8020fc60) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
