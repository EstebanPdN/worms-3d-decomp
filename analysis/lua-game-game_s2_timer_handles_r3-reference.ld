/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_timer_destroy_8011c0ac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_base_destroy = 0x80161050;
w3d_base_destroy_8015ff2c = 0x8015ff2c;
w3d_fn_800fc43c = 0x800fc43c;
w3d_obj_80410a70 = 0x80410a70;
w3d_obj_80410ab0 = 0x80410ab0;
w3d_str_8039afd0 = 0x8039afd0;
SECTIONS {
  .text.w3d_timer_destroy_8011c0ac 0x8011c0ac : { *(.text.w3d_timer_destroy_8011c0ac) }
  .text.w3d_timer_clear_elapsed_8011d6a4 0x8011d6a4 : { *(.text.w3d_timer_clear_elapsed_8011d6a4) }
  .text.w3d_effect_destroy_8011dbc0 0x8011dbc0 : { *(.text.w3d_effect_destroy_8011dbc0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
