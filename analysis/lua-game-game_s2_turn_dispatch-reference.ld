/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_land_clear_message_801040d0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_cached_message_id = 0x8015f5a0;
w3d_fn_8002a914 = 0x8002a914;
w3d_fn_8002a978 = 0x8002a978;
w3d_fn_800fc3b0 = 0x800fc3b0;
w3d_fn_80104be0 = 0x80104be0;
w3d_fn_80104d78 = 0x80104d78;
w3d_obj_8040db38 = 0x8040db38;
w3d_obj_80410638 = 0x80410638;
w3d_str_803995dc = 0x803995dc;
SECTIONS {
  .text.w3d_land_clear_message_801040d0 0x801040d0 : { *(.text.w3d_land_clear_message_801040d0) }
  .text.w3d_turn_state_construct_8010430c 0x8010430c : { *(.text.w3d_turn_state_construct_8010430c) }
  .text.w3d_turn_state_destroy_80104350 0x80104350 : { *(.text.w3d_turn_state_destroy_80104350) }
  .text.w3d_turn_clear_retreat_time_80104410 0x80104410 : { *(.text.w3d_turn_clear_retreat_time_80104410) }
  .text.w3d_service_update_delta_80104b90 0x80104b90 : { *(.text.w3d_service_update_delta_80104b90) }
  .sdata 0x804aafa0 (NOLOAD) : {
    . = 0x0; w3d_obj_804aafa0 = .;
    . = 0x4208; w3d_obj_804af1a8 = .;
    . = 0x68b4; w3d_obj_804b1854 = .;
    . = 0x68b8; w3d_obj_804b1858 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
