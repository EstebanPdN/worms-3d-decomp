/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d31k_handle_table_free_8034b494)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801613f0 = 0x801613f0;
fn_8034b9bc = 0x8034b9bc;
lbl_8040db38 = 0x8040db38;
SECTIONS {
  .text.w3d_d31k_handle_table_free_8034b494 0x8034b494 : { *(.text.w3d_d31k_handle_table_free_8034b494) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; lbl_804b1754 = .;
    . = 0x13c; lbl_804b1890 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
