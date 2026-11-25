/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d20c_hud_meter_update_800f0a70)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_engine_get_context = 0x80165254;
w3d_f32_8038c21c = 0x8038c21c;
w3d_f32_8038c220 = 0x8038c220;
w3d_f32_8038c224 = 0x8038c224;
w3d_f32_8038c228 = 0x8038c228;
w3d_f32_8038c22c = 0x8038c22c;
w3d_level_ratio_800f12f0 = 0x800f12f0;
w3d_s20_lookup_handle_object_80164fc8 = 0x80164fc8;
w3d_sprite_colour_80189760 = 0x80189760;
w3d_sprite_vec2_8018963c = 0x8018963c;
w3d_sprite_vec2_80189884 = 0x80189884;
w3d_sprite_vec2_801898e0 = 0x801898e0;
w3d_sprite_vec3_80189518 = 0x80189518;
w3d_sprite_visible_80189704 = 0x80189704;
w3d_texture_size_80178ec4 = 0x80178ec4;
w3d_timer_80178d1c = 0x80178d1c;
SECTIONS {
  .text.d20c_hud_meter_update_800f0a70 0x800f0a70 : { *(.text.d20c_hud_meter_update_800f0a70) }
  .sdata 0x804aaabc (NOLOAD) : {
    . = 0x0; w3d_game_804aaabc = .;
    . = 0x4568; w3d_colour_804af024 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
