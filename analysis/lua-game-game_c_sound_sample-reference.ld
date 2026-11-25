/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_sound_allocate_aligned)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_member_delete_backend = 0x801fe1f8;
w3d_actor_node_destroy = 0x80210990;
w3d_aligned_allocate = 0x801fe2a8;
w3d_aligned_release = 0x801fe2e0;
w3d_audio_config_803b059c = 0x803b059c;
w3d_audio_configure_8033499c = 0x8033499c;
w3d_audio_open_80331928 = 0x80331928;
w3d_audio_select_80311640 = 0x80311640;
w3d_audio_set_mode_80311c44 = 0x80311c44;
w3d_audio_start_80313754 = 0x80313754;
w3d_f32_803b05f0 = 0x803b05f0;
w3d_f32_803b0600 = 0x803b0600;
w3d_heap_allocate_entry_a = 0x801fe1d8;
w3d_heap_compact_80209968 = 0x80209968;
w3d_heap_release = 0x80209920;
w3d_owner_list_remove = 0x8020fd2c;
w3d_sound_sample_base_vtable_80416bf8 = 0x80416bf8;
w3d_sound_sample_list_803656dc = 0x803656dc;
w3d_sound_sample_type_803b05b8 = 0x803b05b8;
w3d_sound_sample_vtable_80416de0 = 0x80416de0;
w3d_state_register = 0x8020fd04;
w3d_str_notset_803b05d8 = 0x803b05d8;
w3d_str_unused_803b05d0 = 0x803b05d0;
w3d_string_assign = 0x8020bd38;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_default = 0x803426b8;
w3d_string_release = 0x80341588;
w3d_type_cast_8020b460 = 0x8020b460;
SECTIONS {
  .text.w3d_sound_allocate_aligned 0x801e1958 : { *(.text.w3d_sound_allocate_aligned) }
  .text.w3d_sound_release_aligned 0x801e197c : { *(.text.w3d_sound_release_aligned) }
  .text.w3d_audio_hardware_init 0x801e199c : { *(.text.w3d_audio_hardware_init) }
  .text.w3d_sound_sample_list_get 0x801e1b08 : { *(.text.w3d_sound_sample_list_get) }
  .text.w3d_sound_sample_unlink 0x801e1b14 : { *(.text.w3d_sound_sample_unlink) }
  .text.w3d_sound_sample_create 0x801e1b58 : { *(.text.w3d_sound_sample_create) }
  .text.w3d_sound_sample_type_get 0x801e1bb8 : { *(.text.w3d_sound_sample_type_get) }
  .text.w3d_sound_sample_release 0x801e1bc4 : { *(.text.w3d_sound_sample_release) }
  .text.w3d_sound_sample_retain 0x801e1c20 : { *(.text.w3d_sound_sample_retain) }
  .text.w3d_sound_sample_cast 0x801e1c38 : { *(.text.w3d_sound_sample_cast) }
  .text.w3d_sound_sample_construct_801e1c80 0x801e1c80 : { *(.text.w3d_sound_sample_construct_801e1c80) }
  .text.w3d_sound_sample_destroy_801e1d68 0x801e1d68 : { *(.text.w3d_sound_sample_destroy_801e1d68) }
  .text.w3d_sound_sample_kind 0x801e1e10 : { *(.text.w3d_sound_sample_kind) }
  .text.w3d_sound_sample_set_name 0x801e1e18 : { *(.text.w3d_sound_sample_set_name) }
  .text.w3d_sound_sample_get_name 0x801e1e40 : { *(.text.w3d_sound_sample_get_name) }
  .text.w3d_sound_sample_set_18 0x801e1e48 : { *(.text.w3d_sound_sample_set_18) }
  .text.w3d_sound_sample_get_18 0x801e1e54 : { *(.text.w3d_sound_sample_get_18) }
  .text.w3d_sound_sample_set_40 0x801e1e5c : { *(.text.w3d_sound_sample_set_40) }
  .text.w3d_sound_sample_get_40 0x801e1e68 : { *(.text.w3d_sound_sample_get_40) }
  .text.w3d_sound_sample_set_path 0x801e2340 : { *(.text.w3d_sound_sample_set_path) }
  .text.w3d_sound_sample_set_1c 0x801e2368 : { *(.text.w3d_sound_sample_set_1c) }
  .text.w3d_sound_sample_set_24 0x801e2374 : { *(.text.w3d_sound_sample_set_24) }
  .text.w3d_sound_sample_set_28 0x801e2380 : { *(.text.w3d_sound_sample_set_28) }
  .text.w3d_sound_sample_set_2c_pair 0x801e238c : { *(.text.w3d_sound_sample_set_2c_pair) }
  .text.w3d_sound_sample_set_38_pair 0x801e23a0 : { *(.text.w3d_sound_sample_set_38_pair) }
  .text.w3d_sound_sample_set_34 0x801e23b4 : { *(.text.w3d_sound_sample_set_34) }
  .text.w3d_sound_sample_lipsync_level 0x801e2554 : { *(.text.w3d_sound_sample_lipsync_level) }
  .text.w3d_sound_sample_set_44 0x801e25cc : { *(.text.w3d_sound_sample_set_44) }
  .text.w3d_sound_sample_get_44 0x801e25d4 : { *(.text.w3d_sound_sample_get_44) }
  .rodata 0x803b05f8 : { *(.rodata) }
  .sdata 0x804b0564 (NOLOAD) : {
    . = 0x0; w3d_lipsync_heap_804b0564 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
