/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_matches_handle_8013f168)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800da7bc = 0x800da7bc;
fn_801190d0 = 0x801190d0;
fn_80164fc8 = 0x80164fc8;
fn_80167094 = 0x80167094;
SECTIONS {
  .text.w3d_s20_matches_handle_8013f168 0x8013f168 : { *(.text.w3d_s20_matches_handle_8013f168) }
  .text.w3d_s20_push_pending_8016703c 0x8016703c : { *(.text.w3d_s20_push_pending_8016703c) }
  .text.w3d_s20_drop_reference_8019ab0c 0x8019ab0c : { *(.text.w3d_s20_drop_reference_8019ab0c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
