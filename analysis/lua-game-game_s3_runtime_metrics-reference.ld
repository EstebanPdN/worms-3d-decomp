/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_runtime_reset_time)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_member_delete_backend = 0x801fe1f8;
w3d_clock_801fe45c = 0x801fe45c;
w3d_engine_get_context = 0x80165254;
w3d_handle_storage_release = 0x802134fc;
w3d_history_record = 0x8015d018;
w3d_history_reset = 0x8015cfa0;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_runtime_reset_time 0x8015cbe0 : { *(.text.w3d_runtime_reset_time) }
  .text.w3d_runtime_pause_retain 0x8015cc24 : { *(.text.w3d_runtime_pause_retain) }
  .text.w3d_runtime_pause_release 0x8015cc64 : { *(.text.w3d_runtime_pause_release) }
  .text.w3d_runtime_is_paused 0x8015ccbc : { *(.text.w3d_runtime_is_paused) }
  .text.w3d_runtime_service_request 0x8015cd04 : { *(.text.w3d_runtime_service_request) }
  .text.w3d_runtime_service_bind_view 0x8015cd34 : { *(.text.w3d_runtime_service_bind_view) }
  .text.w3d_history_tick 0x8015ce60 : { *(.text.w3d_history_tick) }
  .text.w3d_history_construct 0x8015ced4 : { *(.text.w3d_history_construct) }
  .text.w3d_text_owner_destroy 0x8015d1ac : { *(.text.w3d_text_owner_destroy) }
  .text.w3d_text_owner_make_handle 0x8015d278 : { *(.text.w3d_text_owner_make_handle) }
  .rodata 0x803a4400 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
