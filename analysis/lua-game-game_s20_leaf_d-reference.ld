/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_vector_all_ge_800f5894)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_80399f28 = 0x80399f28;
lbl_803a84b8 = 0x803a84b8;
lbl_804a91d8 = 0x804a91d8;
SECTIONS {
  .text.w3d_s20_vector_all_ge_800f5894 0x800f5894 : { *(.text.w3d_s20_vector_all_ge_800f5894) }
  .text.w3d_s20_point_in_rect_8010b594 0x8010b594 : { *(.text.w3d_s20_point_in_rect_8010b594) }
  .text.w3d_s20_evaluate_cubic_8019661c 0x8019661c : { *(.text.w3d_s20_evaluate_cubic_8019661c) }
  .text.w3d_s20_scan_high_nibbles_801b0b10 0x801b0b10 : { *(.text.w3d_s20_scan_high_nibbles_801b0b10) }
  .sdata 0x804b18d0 (NOLOAD) : {
    . = 0x0; lbl_804b18d0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
