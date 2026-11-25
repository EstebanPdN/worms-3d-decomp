/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_reset_vectors_800e67d0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800dc6a8 = 0x800dc6a8;
fn_800ddd14 = 0x800ddd14;
fn_8015af24 = 0x8015af24;
fn_8015fef0 = 0x8015fef0;
fn_802e82c0 = 0x802e82c0;
lbl_8038af94 = 0x8038af94;
lbl_8038b5cc = 0x8038b5cc;
lbl_804102e8 = 0x804102e8;
SECTIONS {
  .text.w3d_s20_reset_vectors_800e67d0 0x800e67d0 : { *(.text.w3d_s20_reset_vectors_800e67d0) }
  .text.w3d_s20_forward_position_800e705c 0x800e705c : { *(.text.w3d_s20_forward_position_800e705c) }
  .text.w3d_s20_set_normalized_direction_800ecfe0 0x800ecfe0 : { *(.text.w3d_s20_set_normalized_direction_800ecfe0) }
  .text.w3d_s20_construct_cleared_800efe34 0x800efe34 : { *(.text.w3d_s20_construct_cleared_800efe34) }
  .text.w3d_s20_release_held_pair_800f339c 0x800f339c : { *(.text.w3d_s20_release_held_pair_800f339c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
