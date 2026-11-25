/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_mesh_instance_advance)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_f32_803a7850 = 0x803a7850;
w3d_f32_803a7854 = 0x803a7854;
w3d_f32_803a7858 = 0x803a7858;
w3d_f32_803a788c = 0x803a788c;
w3d_mesh_instance_finish_8017b348 = 0x8017b348;
w3d_mesh_instance_stop_801819f4 = 0x801819f4;
w3d_mesh_instance_update_child_8017a07c = 0x8017a07c;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_base_init = 0x8020c5c0;
w3d_string_header = 0x80341884;
w3d_string_release = 0x80341588;
w3d_text_compare_802ef234 = 0x802ef234;
SECTIONS {
  .text.w3d_mesh_instance_advance 0x8018136c : { *(.text.w3d_mesh_instance_advance) }
  .text.w3d_mesh_instance_owner_flags 0x80181478 : { *(.text.w3d_mesh_instance_owner_flags) }
  .text.w3d_mesh_instance_shutdown 0x801814ac : { *(.text.w3d_mesh_instance_shutdown) }
  .text.w3d_mesh_instance_find_clip 0x80181598 : { *(.text.w3d_mesh_instance_find_clip) }
  .text.w3d_mesh_instance_play_index 0x801816d0 : { *(.text.w3d_mesh_instance_play_index) }
  .text.w3d_mesh_instance_check_control 0x8018179c : { *(.text.w3d_mesh_instance_check_control) }
  .text.w3d_mesh_instance_control_3c 0x801817e0 : { *(.text.w3d_mesh_instance_control_3c) }
  .text.w3d_mesh_instance_is_playing 0x80181ccc : { *(.text.w3d_mesh_instance_is_playing) }
  .text.w3d_mesh_instance_control_34 0x80181d00 : { *(.text.w3d_mesh_instance_control_34) }
  .text.w3d_mesh_instance_clip_length_named 0x80181d30 : { *(.text.w3d_mesh_instance_clip_length_named) }
  .text.w3d_mesh_instance_clip_length_index 0x80181de4 : { *(.text.w3d_mesh_instance_clip_length_index) }
  .sdata 0x804ab5fc (NOLOAD) : {
    . = 0x0; w3d_scene_list_804ab5fc = .;
    . = 0x2c; w3d_mesh_active_count_804ab628 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
