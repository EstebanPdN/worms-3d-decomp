/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24h_in_range_800cc070)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800b0824 = 0x800b0824;
lbl_8045e788 = 0x8045e788;
SECTIONS {
  .text.w3d_d24h_in_range_800cc070 0x800cc070 : { *(.text.w3d_d24h_in_range_800cc070) }
  .rodata 0x80387d2c : { *(.rodata) }
  .sdata 0x804b1764 (NOLOAD) : {
    . = 0x0; lbl_804b1764 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
