/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k5a_rope_camera_reset_800cef44)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_80035714 = 0x80035714;
FUN_801613f0 = 0x801613f0;
strcmp = 0x802ef234;
w3d_cached_message_id = 0x8015f5a0;
w3d_f32_803880a4 = 0x803880a4;
w3d_message_post_current = 0x8016239c;
w3d_rope_enter_mode_800d0d6c = 0x800d0d6c;
w3d_string_80388094 = 0x80388094;
w3d_string_8038809c = 0x8038809c;
w3d_vtable_8040db38 = 0x8040db38;
SECTIONS {
  .text.k5a_rope_camera_reset_800cef44 0x800cef44 : { *(.text.k5a_rope_camera_reset_800cef44) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; w3d_camera_set_804aa8c8 = .;
    . = 0x40e8; w3d_message_804ae9b0 = .;
    . = 0x6e8c; w3d_message_pool_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
