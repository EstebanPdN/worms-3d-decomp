/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_stream_slot_open)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_member_delete_backend = 0x801fe1f8;
w3d_aligned_allocate = 0x801fe2a8;
w3d_aligned_release = 0x801fe2e0;
w3d_disc_cancel_802f7a68 = 0x802f7a68;
w3d_disc_close_802f5320 = 0x802f5320;
w3d_disc_open_802f51e4 = 0x802f51e4;
w3d_disc_read_async_802f5568 = 0x802f5568;
w3d_lock_create_802fdb6c = 0x802fdb6c;
w3d_lock_destroy_802fdb94 = 0x802fdb94;
w3d_stream_read_done_801e4a4c = 0x801e4a4c;
w3d_stream_slot_refill_801e47e8 = 0x801e47e8;
w3d_stream_slot_start_801e4074 = 0x801e4074;
w3d_stream_table_8045d930 = 0x8045d930;
w3d_voice_create_80323d88 = 0x80323d88;
w3d_voice_free_803254e4 = 0x803254e4;
w3d_voice_set_volume_80324e7c = 0x80324e7c;
w3d_voice_start_80324920 = 0x80324920;
w3d_voice_stop_80326210 = 0x80326210;
SECTIONS {
  .text.w3d_stream_slot_open 0x801e3d44 : { *(.text.w3d_stream_slot_open) }
  .text.w3d_stream_slot_find 0x801e3e2c : { *(.text.w3d_stream_slot_find) }
  .text.w3d_stream_unlock 0x801e3e70 : { *(.text.w3d_stream_unlock) }
  .text.w3d_stream_lock 0x801e3eb8 : { *(.text.w3d_stream_lock) }
  .text.w3d_stream_member_construct_801e3f00 0x801e3f00 : { *(.text.w3d_stream_member_construct_801e3f00) }
  .text.w3d_stream_member_destroy_801e3f0c 0x801e3f0c : { *(.text.w3d_stream_member_destroy_801e3f0c) }
  .text.w3d_stream_member_open_801e3f3c 0x801e3f3c : { *(.text.w3d_stream_member_open_801e3f3c) }
  .text.w3d_stream_member_close_801e4020 0x801e4020 : { *(.text.w3d_stream_member_close_801e4020) }
  .text.w3d_stream_open_mono 0x801e4120 : { *(.text.w3d_stream_open_mono) }
  .text.w3d_stream_slot_play 0x801e4364 : { *(.text.w3d_stream_slot_play) }
  .text.w3d_stream_play 0x801e43c8 : { *(.text.w3d_stream_play) }
  .text.w3d_stream_is_open 0x801e4444 : { *(.text.w3d_stream_is_open) }
  .text.w3d_stream_mute 0x801e44ac : { *(.text.w3d_stream_mute) }
  .text.w3d_stream_unmute 0x801e4548 : { *(.text.w3d_stream_unmute) }
  .text.w3d_stream_close 0x801e45f0 : { *(.text.w3d_stream_close) }
  .text.w3d_stream_set_mix 0x801e46f4 : { *(.text.w3d_stream_set_mix) }
  .text.w3d_stream_slot_finish 0x801e4794 : { *(.text.w3d_stream_slot_finish) }
  .text.w3d_stream_voice_callback_801e4928 0x801e4928 : { *(.text.w3d_stream_voice_callback_801e4928) }
  .sdata 0x804ab85c (NOLOAD) : {
    . = 0x0; w3d_stream_system_804ab85c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
