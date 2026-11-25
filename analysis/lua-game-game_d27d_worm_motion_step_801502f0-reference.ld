/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27d_worm_motion_step_801502f0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
acos_802e79e0 = 0x802e79e0;
advance_8014c6f4 = 0x8014c6f4;
applyMotion_80153f80 = 0x80153f80;
arena_801613f0 = 0x801613f0;
blocked_80146b84 = 0x80146b84;
collided_801418c4 = 0x801418c4;
constrain_8014b40c = 0x8014b40c;
level_80178df0 = 0x80178df0;
limit_8014c89c = 0x8014c89c;
limit_8014c978 = 0x8014c978;
motion_direction_80146f10 = 0x80146f10;
msg_init_800a82f0 = 0x800a82f0;
msgid_8015f5a0 = 0x8015f5a0;
owner_8014c488 = 0x8014c488;
post_8016239c = 0x8016239c;
sqrt_802e82c0 = 0x802e82c0;
stuck_8014c4f4 = 0x8014c4f4;
zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.d27d_worm_motion_step_801502f0 0x801502f0 : { *(.text.d27d_worm_motion_step_801502f0) }
  .rodata 0x803a17e4 : { *(.rodata) }
  .sdata 0x804afc60 (NOLOAD) : {
    . = 0x0; cache_804afc60 = .;
    . = 0x1af4; arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
