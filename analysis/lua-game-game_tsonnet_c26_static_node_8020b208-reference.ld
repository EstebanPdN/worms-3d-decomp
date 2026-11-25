/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(tsonnet_c26_static_node_8020b208)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
atexit = 0x802ed7e0;
fn_8020b1cc = 0x8020b1cc;
lbl_80419470 = 0x80419470;
lbl_804632e8 = 0x804632e8;
SECTIONS {
  .text.tsonnet_c26_static_node_8020b208 0x8020b208 : { *(.text.tsonnet_c26_static_node_8020b208) }
  .sdata 0x804b0690 (NOLOAD) : {
    . = 0x0; lbl_804b0690 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
