/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d27a_entry_weight_pass_80018ce0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
g_score_8041d3b8 = 0x8041d3b8;
sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.w3d_d27a_entry_weight_pass_80018ce0 0x80018ce0 : { *(.text.w3d_d27a_entry_weight_pass_80018ce0) }
  .rodata 0x8036a8e0 : { *(.rodata) }
  .sdata 0x804aa6d8 (NOLOAD) : {
    . = 0x0; w3d_settings_804aa6d8 = .;
    . = 0x78; w3d_table_804aa750 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
