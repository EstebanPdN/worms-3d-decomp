/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d27a_strike_camera_update_8002c840)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
atan2_802e7e5c = 0x802e7e5c;
g_direction_803728d0 = 0x803728d0;
g_target_803728b8 = 0x803728b8;
g_up_803728e4 = 0x803728e4;
sqrt_802e82c0 = 0x802e82c0;
tsonnet_b33_arena_801613f0 = 0x801613f0;
w3d_auto_800fc2f0 = 0x800fc2f0;
w3d_auto_80131b50 = 0x80131b50;
w3d_auto_80178df0 = 0x80178df0;
w3d_message_post_current = 0x8016239c;
SECTIONS {
  .text.w3d_d27a_strike_camera_update_8002c840 0x8002c840 : { *(.text.w3d_d27a_strike_camera_update_8002c840) }
  .rodata 0x80372928 : { *(.rodata) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; g_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
