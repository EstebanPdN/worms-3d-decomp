/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f1a_scaled_vector_query_800b0788)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800b0824 = 0x800b0824;
lbl_803823a4 = 0x803823a4;
lbl_803823a8 = 0x803823a8;
lbl_803823ac = 0x803823ac;
SECTIONS {
  .text.w3d_f1a_scaled_vector_query_800b0788 0x800b0788 : { *(.text.w3d_f1a_scaled_vector_query_800b0788) }
  .sdata 0x804b1764 (NOLOAD) : {
    . = 0x0; lbl_804b1764 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
