/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_worm_pot_construct)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_8015fb34 = 0x8015fb34;
w3d_auto_801797b4 = 0x801797b4;
w3d_ctor_8015fef0 = 0x8015fef0;
w3d_f32_803a0404 = 0x803a0404;
w3d_fn_800fc7f8 = 0x800fc7f8;
w3d_fn_800fd3e4 = 0x800fd3e4;
w3d_fn_8011adf8 = 0x8011adf8;
w3d_fn_8011afac = 0x8011afac;
w3d_fn_80164fc8 = 0x80164fc8;
w3d_fn_802ec254 = 0x802ec254;
w3d_str_803a0438 = 0x803a0438;
w3d_vtable_80410ec0 = 0x80410ec0;
w3d_worm_pot_initialize_80140e88 = 0x80140e88;
SECTIONS {
  .text.w3d_worm_pot_construct 0x80140940 : { *(.text.w3d_worm_pot_construct) }
  .text.w3d_worm_pot_dispatch 0x801409f8 : { *(.text.w3d_worm_pot_dispatch) }
  .text.w3d_worm_pot_set_second_text 0x80140d80 : { *(.text.w3d_worm_pot_set_second_text) }
  .text.w3d_worm_pot_apply_message 0x80140dc4 : { *(.text.w3d_worm_pot_apply_message) }
  .text.w3d_worm_pot_apply_pair 0x80140f70 : { *(.text.w3d_worm_pot_apply_pair) }
  .text.w3d_worm_pot_update_text 0x80140fc8 : { *(.text.w3d_worm_pot_update_text) }
  .sdata 0x804af3b4 (NOLOAD) : {
    . = 0x0; w3d_global_804af3b4 = .;
    . = 0x2598; w3d_str_804b194c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
