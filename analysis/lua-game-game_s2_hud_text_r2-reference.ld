/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_hud_manager_construct_80119e10)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_base_destroy = 0x80161050;
w3d_actor_base_initialize = 0x80161014;
w3d_auto_8018c5b0 = 0x8018c5b0;
w3d_base_destroy_8015ff2c = 0x8015ff2c;
w3d_empty_8034380c = 0x8034380c;
w3d_f32_8039adcc = 0x8039adcc;
w3d_fn_80189518 = 0x80189518;
w3d_fn_8018963c = 0x8018963c;
w3d_fn_8018c8bc = 0x8018c8bc;
w3d_fn_8018d35c = 0x8018d35c;
w3d_fn_8018d434 = 0x8018d434;
w3d_getf_8018ca14 = 0x8018ca14;
w3d_obj_80410990 = 0x80410990;
w3d_obj_804109d0 = 0x804109d0;
w3d_obj_80410a20 = 0x80410a20;
SECTIONS {
  .text.w3d_hud_manager_construct_80119e10 0x80119e10 : { *(.text.w3d_hud_manager_construct_80119e10) }
  .text.w3d_hud_manager_destroy_80119e50 0x80119e50 : { *(.text.w3d_hud_manager_destroy_80119e50) }
  .text.w3d_hud_derived_destroy_8011a108 0x8011a108 : { *(.text.w3d_hud_derived_destroy_8011a108) }
  .text.w3d_hud_reset_transform_8011a304 0x8011a304 : { *(.text.w3d_hud_reset_transform_8011a304) }
  .text.w3d_hud_clear_assets_8011a370 0x8011a370 : { *(.text.w3d_hud_clear_assets_8011a370) }
  .text.w3d_hud_update_backing_8011a3dc 0x8011a3dc : { *(.text.w3d_hud_update_backing_8011a3dc) }
  .text.w3d_hud_text_destroy_8011aa98 0x8011aa98 : { *(.text.w3d_hud_text_destroy_8011aa98) }
  .rodata 0x8039add0 : { *(.rodata) }
  .sdata 0x804ab004 (NOLOAD) : {
    . = 0x0; w3d_obj_804ab004 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
