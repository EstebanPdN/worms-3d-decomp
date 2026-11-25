/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24b_projectile_message_8009b670)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_arena_alloc_801613f0 = 0x801613f0;
w3d_as_weapon_801797b4 = 0x801797b4;
w3d_base_finish_8015fd1c = 0x8015fd1c;
w3d_base_handle_8015fb34 = 0x8015fb34;
w3d_cached_message_id_8015f5a0 = 0x8015f5a0;
w3d_engine_context_80165254 = 0x80165254;
w3d_identity_80341584 = 0x80341584;
w3d_int_read_800fc230 = 0x800fc230;
w3d_int_write_800fc43c = 0x800fc43c;
w3d_message_equals_8015f65c = 0x8015f65c;
w3d_message_post_8016239c = 0x8016239c;
w3d_restricted_8009d7e4 = 0x8009d7e4;
w3d_sound_refresh_8009c0cc = 0x8009c0cc;
w3d_start_8009c248 = 0x8009c248;
w3d_stop_8009c5e8 = 0x8009c5e8;
w3d_string_80380078 = 0x80380078;
w3d_string_80380088 = 0x80380088;
w3d_string_803800a0 = 0x803800a0;
w3d_vtable_8040db38 = 0x8040db38;
SECTIONS {
  .text.w3d_d24b_projectile_message_8009b670 0x8009b670 : { *(.text.w3d_d24b_projectile_message_8009b670) }
  .rodata 0x803800e4 : { *(.rodata) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; w3d_camera_804aa8c8 = .;
    . = 0x3738; w3d_message_804ae000 = .;
    . = 0x3740; w3d_message_804ae008 = .;
    . = 0x3750; w3d_message_804ae018 = .;
    . = 0x3758; w3d_message_804ae020 = .;
    . = 0x3760; w3d_message_804ae028 = .;
    . = 0x3788; w3d_message_804ae050 = .;
    . = 0x3798; w3d_message_804ae060 = .;
    . = 0x37e0; w3d_message_804ae0a8 = .;
    . = 0x6e8c; w3d_message_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
