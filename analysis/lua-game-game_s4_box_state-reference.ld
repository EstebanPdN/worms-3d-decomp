/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_box_destroy)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_80178df0 = 0x80178df0;
w3d_base_destroy_8015ff2c = 0x8015ff2c;
w3d_border_name_80263bb8 = 0x80263bb8;
w3d_constructor_lookup_name = 0x800fc1b0;
w3d_empty_80342a74 = 0x80342a74;
w3d_f32_803d0810 = 0x803d0810;
w3d_f32_803d0838 = 0x803d0838;
w3d_global_804b06a0 = 0x804b06a0;
w3d_sound_stop_80263cfc = 0x80263cfc;
w3d_str_803d07a0 = 0x803d07a0;
w3d_str_803d0814 = 0x803d0814;
w3d_str_803d0828 = 0x803d0828;
w3d_string_assign = 0x8020bd38;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_base_init = 0x8020c5c0;
w3d_string_header = 0x80341884;
w3d_string_release = 0x80341588;
w3d_vtable_8041c230 = 0x8041c230;
SECTIONS {
  .text.w3d_s4_box_destroy 0x80294810 : { *(.text.w3d_s4_box_destroy) }
  .text.w3d_s4_box_reset 0x80295204 : { *(.text.w3d_s4_box_reset) }
  .text.w3d_s4_box_set_position 0x80295468 : { *(.text.w3d_s4_box_set_position) }
  .text.w3d_s4_box_stop_sound 0x802962f8 : { *(.text.w3d_s4_box_stop_sound) }
  .text.w3d_s4_box_update_border 0x80296498 : { *(.text.w3d_s4_box_update_border) }
  .text.w3d_s4_box_update_properties 0x80296598 : { *(.text.w3d_s4_box_update_properties) }
  .text.w3d_s4_box_border_thickness 0x802966f8 : { *(.text.w3d_s4_box_border_thickness) }
  .sdata 0x804aac54 (NOLOAD) : {
    . = 0x0; w3d_global_804aac54 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
