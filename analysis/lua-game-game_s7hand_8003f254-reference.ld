/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8003f254)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801628B0 = 0x801628b0;
lbl_8040E8F8 = 0x8040e8f8;
SECTIONS {
  .text.w3d_auto_8003f254 0x8003f254 : { *(.text.w3d_auto_8003f254) }
  .sdata 0x804aa958 (NOLOAD) : {
    . = 0x0; lbl_804AA958 = .;
    . = 0x14; lbl_804AA96C = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
