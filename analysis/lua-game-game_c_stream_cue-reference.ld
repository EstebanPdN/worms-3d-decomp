/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_stream_player_new_cue)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
memcpy = 0x802eee50;
w3d_actor_member_delete_backend = 0x801fe1f8;
w3d_actor_node_destroy = 0x80210990;
w3d_f32_803b0660 = 0x803b0660;
w3d_handle_storage_allocate = 0x80212fd4;
w3d_handle_storage_release = 0x802134fc;
w3d_heap_allocate_entry_a = 0x801fe1d8;
w3d_stream_channel_stop_801e5dfc = 0x801e5dfc;
w3d_stream_cue_base_vtable_80416a90 = 0x80416a90;
w3d_stream_cue_construct_801e34b0 = 0x801e34b0;
w3d_stream_cue_vtable_80416ee0 = 0x80416ee0;
SECTIONS {
  .text.w3d_stream_player_new_cue 0x801e3268 : { *(.text.w3d_stream_player_new_cue) }
  .text.w3d_stream_player_remove_cue_801e337c 0x801e337c : { *(.text.w3d_stream_player_remove_cue_801e337c) }
  .text.w3d_stream_player_set_output 0x801e344c : { *(.text.w3d_stream_player_set_output) }
  .text.w3d_stream_cue_destroy 0x801e3528 : { *(.text.w3d_stream_cue_destroy) }
  .text.w3d_stream_cue_start 0x801e35a4 : { *(.text.w3d_stream_cue_start) }
  .text.w3d_stream_cue_stop 0x801e35b4 : { *(.text.w3d_stream_cue_stop) }
  .text.w3d_stream_cue_pause 0x801e35c4 : { *(.text.w3d_stream_cue_pause) }
  .text.w3d_stream_cue_resume 0x801e35dc : { *(.text.w3d_stream_cue_resume) }
  .text.w3d_stream_cue_is_audible 0x801e35f8 : { *(.text.w3d_stream_cue_is_audible) }
  .text.w3d_stream_cue_query_sample 0x801e361c : { *(.text.w3d_stream_cue_query_sample) }
  .text.w3d_stream_cue_has_property 0x801e365c : { *(.text.w3d_stream_cue_has_property) }
  .text.w3d_stream_cue_not_implemented_801e367c 0x801e367c : { *(.text.w3d_stream_cue_not_implemented_801e367c) }
  .text.w3d_stream_cue_set_float 0x801e3688 : { *(.text.w3d_stream_cue_set_float) }
  .text.w3d_stream_cue_set_vector 0x801e36a8 : { *(.text.w3d_stream_cue_set_vector) }
  .text.w3d_stream_cue_not_implemented_801e36ec 0x801e36ec : { *(.text.w3d_stream_cue_not_implemented_801e36ec) }
  .text.w3d_stream_cue_get_float 0x801e36f8 : { *(.text.w3d_stream_cue_get_float) }
  .text.w3d_stream_cue_get_vector 0x801e3778 : { *(.text.w3d_stream_cue_get_vector) }
  .text.w3d_stream_cue_shutdown 0x801e37b0 : { *(.text.w3d_stream_cue_shutdown) }
  .text.w3d_stream_cue_detach 0x801e3824 : { *(.text.w3d_stream_cue_detach) }
  .text.w3d_stream_player_current_801e3880 0x801e3880 : { *(.text.w3d_stream_player_current_801e3880) }
  .text.w3d_stream_cue_advance_801e3888 0x801e3888 : { *(.text.w3d_stream_cue_advance_801e3888) }
  .text.w3d_stream_cue_update_attenuation_801e38a4 0x801e38a4 : { *(.text.w3d_stream_cue_update_attenuation_801e38a4) }
  .text.w3d_stream_player_set_channel_parameter 0x801e38b8 : { *(.text.w3d_stream_player_set_channel_parameter) }
  .text.w3d_stream_cue_get_position_set 0x801e3988 : { *(.text.w3d_stream_cue_get_position_set) }
  .sdata 0x804ab84c (NOLOAD) : {
    . = 0x0; w3d_stream_player_current_804ab84c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
