/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_dispatch_base_target_80166b14)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801689e4 = 0x801689e4;
fn_8016beac = 0x8016beac;
fn_801a3944 = 0x801a3944;
fn_801aa79c = 0x801aa79c;
fn_801f5b0c = 0x801f5b0c;
fn_801f6834 = 0x801f6834;
fn_80309404 = 0x80309404;
SECTIONS {
  .text.w3d_s20_dispatch_base_target_80166b14 0x80166b14 : { *(.text.w3d_s20_dispatch_base_target_80166b14) }
  .text.w3d_s20_scoped_base_range_80168a9c 0x80168a9c : { *(.text.w3d_s20_scoped_base_range_80168a9c) }
  .text.w3d_s20_flush_base_8016bf68 0x8016bf68 : { *(.text.w3d_s20_flush_base_8016bf68) }
  .text.w3d_s20_flush_base_scaled_8016bfb0 0x8016bfb0 : { *(.text.w3d_s20_flush_base_scaled_8016bfb0) }
  .text.w3d_s20_dispatch_temp_801a5c48 0x801a5c48 : { *(.text.w3d_s20_dispatch_temp_801a5c48) }
  .text.w3d_s20_forward_base_pair_801aab20 0x801aab20 : { *(.text.w3d_s20_forward_base_pair_801aab20) }
  .text.w3d_s20_call_keep_base_field_801aaf6c 0x801aaf6c : { *(.text.w3d_s20_call_keep_base_field_801aaf6c) }
  .text.w3d_s20_virtual_item_801ac378 0x801ac378 : { *(.text.w3d_s20_virtual_item_801ac378) }
  .text.w3d_s20_virtual_chain_item_801ac3bc 0x801ac3bc : { *(.text.w3d_s20_virtual_chain_item_801ac3bc) }
  .text.w3d_s20_set_base_mode_801d5700 0x801d5700 : { *(.text.w3d_s20_set_base_mode_801d5700) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
