/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d30j_remove_node_children_80164cec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8034b494 = 0x8034b494;
lbl_8040db38 = 0x8040db38;
tsonnet_b33_arena_801613f0 = 0x801613f0;
w3d_cx9c_append_interface_8034b9bc = 0x8034b9bc;
SECTIONS {
  .text.d30j_remove_node_children_80164cec 0x80164cec : { *(.text.d30j_remove_node_children_80164cec) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; lbl_804b1754 = .;
    . = 0x13c; lbl_804b1890 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
