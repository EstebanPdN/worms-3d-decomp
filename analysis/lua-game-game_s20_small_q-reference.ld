/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_forward_if_enabled_800e6834)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800dc740 = 0x800dc740;
fn_800e68f0 = 0x800e68f0;
fn_80161e38 = 0x80161e38;
fn_801a0b80 = 0x801a0b80;
SECTIONS {
  .text.w3d_s20_forward_if_enabled_800e6834 0x800e6834 : { *(.text.w3d_s20_forward_if_enabled_800e6834) }
  .text.w3d_s20_apply_list_80161dd4 0x80161dd4 : { *(.text.w3d_s20_apply_list_80161dd4) }
  .text.w3d_s20_replace_target_80174820 0x80174820 : { *(.text.w3d_s20_replace_target_80174820) }
  .text.w3d_s20_set_block_and_notify_801a0910 0x801a0910 : { *(.text.w3d_s20_set_block_and_notify_801a0910) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
