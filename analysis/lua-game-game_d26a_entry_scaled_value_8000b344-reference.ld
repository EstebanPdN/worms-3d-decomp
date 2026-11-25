/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d26a_entry_scaled_value_8000b344)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_d26a_entry_scaled_value_8000b344 0x8000b344 : { *(.text.w3d_d26a_entry_scaled_value_8000b344) }
  .rodata 0x80369c40 : { *(.rodata) }
  .sdata 0x804aa6d8 (NOLOAD) : {
    . = 0x0; w3d_settings_804aa6d8 = .;
    . = 0x78; w3d_table_804aa750 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
