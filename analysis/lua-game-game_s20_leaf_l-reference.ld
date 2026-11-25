/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_append_node_80178a98)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_803fe440 = 0x803fe440;
lbl_804a89d8 = 0x804a89d8;
SECTIONS {
  .text.w3d_s20_append_node_80178a98 0x80178a98 : { *(.text.w3d_s20_append_node_80178a98) }
  .text.w3d_s20_replace_target_801795d4 0x801795d4 : { *(.text.w3d_s20_replace_target_801795d4) }
  .text.w3d_s20_clear_target_80179770 0x80179770 : { *(.text.w3d_s20_clear_target_80179770) }
  .text.w3d_s20_static_init_801797c0 0x801797c0 : { *(.text.w3d_s20_static_init_801797c0) }
  .text.w3d_s20_lookup_by_virtual_8017988c 0x8017988c : { *(.text.w3d_s20_lookup_by_virtual_8017988c) }
  .text.w3d_s20_test_zero_entry_8017d508 0x8017d508 : { *(.text.w3d_s20_test_zero_entry_8017d508) }
  .text.w3d_s20_set_flag_8017dc78 0x8017dc78 : { *(.text.w3d_s20_set_flag_8017dc78) }
  .sdata 0x804b0158 (NOLOAD) : {
    . = 0x0; lbl_804b0158 = .;
    . = 0x4; lbl_804b015c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
