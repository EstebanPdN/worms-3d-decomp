/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_attach_record_80168e28)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801a3ba0 = 0x801a3ba0;
fn_801a3d90 = 0x801a3d90;
fn_801a4874 = 0x801a4874;
fn_801aa79c = 0x801aa79c;
fn_801f57d4 = 0x801f57d4;
fn_801f5970 = 0x801f5970;
fn_801f5c1c = 0x801f5c1c;
SECTIONS {
  .text.w3d_s20_attach_record_80168e28 0x80168e28 : { *(.text.w3d_s20_attach_record_80168e28) }
  .text.w3d_s20_dispatch_temp_801a5cb0 0x801a5cb0 : { *(.text.w3d_s20_dispatch_temp_801a5cb0) }
  .text.w3d_s20_dispatch_temp_801a5d18 0x801a5d18 : { *(.text.w3d_s20_dispatch_temp_801a5d18) }
  .text.w3d_s20_dispatch_temp_801a5d88 0x801a5d88 : { *(.text.w3d_s20_dispatch_temp_801a5d88) }
  .text.w3d_s20_handle_item_target_801aaee8 0x801aaee8 : { *(.text.w3d_s20_handle_item_target_801aaee8) }
  .text.w3d_s20_apply_item_mode_801d567c 0x801d567c : { *(.text.w3d_s20_apply_item_mode_801d567c) }
  .text.w3d_s20_apply_item_mode_801d5730 0x801d5730 : { *(.text.w3d_s20_apply_item_mode_801d5730) }
  .text.w3d_s20_apply_item_mode_801d59d0 0x801d59d0 : { *(.text.w3d_s20_apply_item_mode_801d59d0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
