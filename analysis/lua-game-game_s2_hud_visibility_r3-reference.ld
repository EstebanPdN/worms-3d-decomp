/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_hud_visibility_8011ac1c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_empty_80343580 = 0x80343580;
w3d_engine_get_context = 0x80165254;
w3d_fn_8018d35c = 0x8018d35c;
w3d_fn_8018d434 = 0x8018d434;
SECTIONS {
  .text.w3d_hud_visibility_8011ac1c 0x8011ac1c : { *(.text.w3d_hud_visibility_8011ac1c) }
  .text.w3d_hud_position_8011acf4 0x8011acf4 : { *(.text.w3d_hud_position_8011acf4) }
  .text.w3d_hud_properties_8011adf8 0x8011adf8 : { *(.text.w3d_hud_properties_8011adf8) }
  .text.w3d_hud_release_resources_8011af40 0x8011af40 : { *(.text.w3d_hud_release_resources_8011af40) }
  .text.w3d_hud_set_visible_8011afac 0x8011afac : { *(.text.w3d_hud_set_visible_8011afac) }
  .sdata 0x804abab4 (NOLOAD) : {
    . = 0x0; w3d_global_804abab4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
