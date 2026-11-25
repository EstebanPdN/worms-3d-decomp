/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d21c_low_gravity_start_800f71a0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_cached_message_id = 0x8015f5a0;
w3d_handle_destroy_80178474 = 0x80178474;
w3d_key_worm_disable_movement_ref_8038c970 = 0x8038c970;
w3d_message_arena_801613f0 = 0x801613f0;
w3d_message_int_init = 0x800a82f0;
w3d_message_post_current = 0x8016239c;
w3d_s20_forward_global_800e5ca4 = 0x800e5ca4;
w3d_s20_lookup_handle_object_80164fc8 = 0x80164fc8;
w3d_settings_read_800fc330 = 0x800fc330;
w3d_settings_read_float_800fc270 = 0x800fc270;
w3d_settings_read_int_800fc1f0 = 0x800fc1f0;
w3d_settings_write_float_800fc4c8 = 0x800fc4c8;
w3d_settings_write_int_800fc43c = 0x800fc43c;
w3d_turns_get_active_actor = 0x80156f88;
w3d_vtable_8040db38 = 0x8040db38;
w3d_worm_record_800fc710 = 0x800fc710;
SECTIONS {
  .text.d21c_low_gravity_start_800f71a0 0x800f71a0 : { *(.text.d21c_low_gravity_start_800f71a0) }
  .rodata 0x8038c988 : { *(.rodata) }
  .sdata 0x804ab400 (NOLOAD) : {
    . = 0x0; w3d_turns_804ab400 = .;
    . = 0x3cd0; w3d_message_804af0d0 = .;
    . = 0x3cd8; w3d_message_804af0d8 = .;
    . = 0x3ce0; w3d_message_804af0e0 = .;
    . = 0x3cf0; w3d_message_804af0f0 = .;
    . = 0x3cf8; w3d_message_804af0f8 = .;
    . = 0x6354; w3d_message_pool_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
