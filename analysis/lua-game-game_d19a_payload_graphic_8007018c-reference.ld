/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d19a_payload_graphic_message_8007018c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d17c_light_node_load_800e9830 = 0x800e9830;
w3d_auto_800e9dc8 = 0x800e9dc8;
w3d_auto_801797b4 = 0x801797b4;
w3d_cc21b_play_named_clip_80181640 = 0x80181640;
w3d_cx16a_cache_clips_80070678 = 0x80070678;
w3d_d19a_set_clip_weight_80181884 = 0x80181884;
w3d_empty_80070708 = 0x80070708;
w3d_empty_80341584 = 0x80341584;
w3d_empty_80343740 = 0x80343740;
w3d_entity_handle_message_800e81a0 = 0x800e81a0;
w3d_handle_member_query_801265ec = 0x801265ec;
w3d_mesh_instance_check_control = 0x8018179c;
w3d_message_id_equals_cache = 0x8015f65c;
w3d_s20_lookup_handle_object_80164fc8 = 0x80164fc8;
SECTIONS {
  .text.w3d_d19a_payload_graphic_message_8007018c 0x8007018c : { *(.text.w3d_d19a_payload_graphic_message_8007018c) }
  .text.w3d_d19a_payload_graphic_update_800702a4 0x800702a4 : { *(.text.w3d_d19a_payload_graphic_update_800702a4) }
  .text.w3d_d19a_clip_blend_80070490 0x80070490 : { *(.text.w3d_d19a_clip_blend_80070490) }
  .rodata 0x8037c9c8 : { *(.rodata) }
  .sdata 0x804ad894 (NOLOAD) : {
    . = 0x0; w3d_message_804ad894 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
