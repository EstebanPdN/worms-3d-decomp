/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_reset_800f6c64)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800fd504 = 0x800fd504;
fn_8020c3a0 = 0x8020c3a0;
lbl_803fcce0 = 0x803fcce0;
SECTIONS {
  .text.w3d_s20_reset_800f6c64 0x800f6c64 : { *(.text.w3d_s20_reset_800f6c64) }
  .text.w3d_s20_forward_indexed_800fd4c8 0x800fd4c8 : { *(.text.w3d_s20_forward_indexed_800fd4c8) }
  .text.w3d_s20_add_count_80190438 0x80190438 : { *(.text.w3d_s20_add_count_80190438) }
  .text.w3d_s20_release_count_80190458 0x80190458 : { *(.text.w3d_s20_release_count_80190458) }
  .text.w3d_s20_shrink_range_801b25ac 0x801b25ac : { *(.text.w3d_s20_shrink_range_801b25ac) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
