/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d15d_actor_check_track_camera_801506f8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_camera_target_position = 0x80150b38;
w3d_auto_801797b4 = 0x801797b4;
w3d_constructor_lookup_name = 0x800fc1b0;
w3d_empty_80341584 = 0x80341584;
w3d_fn_80035b50 = 0x80035b50;
w3d_fn_80121330 = 0x80121330;
w3d_fn_80150828 = 0x80150828;
w3d_fn_802e82c0 = 0x802e82c0;
w3d_str_803a1800 = 0x803a1800;
SECTIONS {
  .text.d15d_actor_check_track_camera_801506f8 0x801506f8 : { *(.text.d15d_actor_check_track_camera_801506f8) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; w3d_scene_804aa8c8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
