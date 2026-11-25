/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_sound_manager_update)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_f32_803b04b8 = 0x803b04b8;
w3d_f32_803b04cc = 0x803b04cc;
w3d_f32_803b04f4 = 0x803b04f4;
w3d_f32_803b04f8 = 0x803b04f8;
w3d_handle_storage_allocate = 0x80212fd4;
w3d_handle_storage_release = 0x802134fc;
w3d_heap_allocate_entry_a = 0x801fe1d8;
w3d_memcpy_802eee50 = 0x802eee50;
w3d_sound_emitter_advance = 0x801e13ac;
w3d_sound_emitter_construct_801e099c = 0x801e099c;
w3d_sound_emitter_list_count = 0x801e1944;
w3d_sound_emitter_list_destroy = 0x801e15f4;
w3d_sound_emitter_list_get = 0x801e194c;
w3d_sound_emitter_list_init = 0x801e15c8;
w3d_sound_emitter_list_remove_801e183c = 0x801e183c;
w3d_sound_emitter_vary_rate_801e1274 = 0x801e1274;
w3d_sound_emitter_vary_volume_801e1308 = 0x801e1308;
w3d_sound_get_base_rate_801df104 = 0x801df104;
w3d_sound_get_base_volume_801df1b4 = 0x801df1b4;
w3d_sound_get_category_801df288 = 0x801df288;
w3d_sound_get_range_801df1bc = 0x801df1bc;
w3d_sound_get_rate_spread_801df1cc = 0x801df1cc;
w3d_sound_get_volume_spread_801df1d4 = 0x801df1d4;
w3d_sound_system_get = 0x801e1118;
w3d_sound_voice_assign_801e4ce0 = 0x801e4ce0;
w3d_sound_voice_is_busy_801e4fcc = 0x801e4fcc;
w3d_sound_voice_is_free_801e5024 = 0x801e5024;
SECTIONS {
  .text.w3d_sound_manager_update 0x801e0380 : { *(.text.w3d_sound_manager_update) }
  .text.w3d_sound_manager_create_emitter 0x801e0680 : { *(.text.w3d_sound_manager_create_emitter) }
  .text.w3d_sound_emitter_set_float 0x801e0cbc : { *(.text.w3d_sound_emitter_set_float) }
  .text.w3d_sound_emitter_attach_801e117c 0x801e117c : { *(.text.w3d_sound_emitter_attach_801e117c) }
  .text.w3d_sound_emitter_update_attenuation 0x801e1424 : { *(.text.w3d_sound_emitter_update_attenuation) }
  .text.w3d_sound_emitter_list_insert 0x801e16b0 : { *(.text.w3d_sound_emitter_list_insert) }
  .text.w3d_sound_manager_set_voice_parameter 0x801e1a0c : { *(.text.w3d_sound_manager_set_voice_parameter) }
  .rodata 0x803b0500 : { *(.rodata) }
  .sdata 0x804ab80c (NOLOAD) : {
    . = 0x0; w3d_sound_config_804ab80c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
