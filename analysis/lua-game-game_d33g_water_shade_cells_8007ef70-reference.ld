/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d33g_water_shade_cells_8007ef70)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
collect_800bcd6c = 0x800bcd6c;
collect_800bd8a0 = 0x800bd8a0;
lbl_8043add8 = 0x8043add8;
trace_800b0cf8 = 0x800b0cf8;
SECTIONS {
  .text.w3d_d33g_water_shade_cells_8007ef70 0x8007ef70 : { *(.text.w3d_d33g_water_shade_cells_8007ef70) }
  .rodata 0x8037cf14 : { *(.rodata) }
  .sdata 0x804b1764 (NOLOAD) : {
    . = 0x0; lbl_804b1764 = .;
    . = 0x7c; lbl_804b17e0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
