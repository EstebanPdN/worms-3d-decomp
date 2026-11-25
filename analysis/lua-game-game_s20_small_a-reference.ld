/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_forward_held_8019013c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801ad8c0 = 0x801ad8c0;
fn_8020b680 = 0x8020b680;
fn_8020c3a0 = 0x8020c3a0;
SECTIONS {
  .text.w3d_s20_forward_held_8019013c 0x8019013c : { *(.text.w3d_s20_forward_held_8019013c) }
  .text.w3d_s20_forward_derived_801ad934 0x801ad934 : { *(.text.w3d_s20_forward_derived_801ad934) }
  .text.w3d_s20_reset_range_801b2464 0x801b2464 : { *(.text.w3d_s20_reset_range_801b2464) }
  .text.w3d_s20_copy_pair_801c83e8 0x801c83e8 : { *(.text.w3d_s20_copy_pair_801c83e8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
