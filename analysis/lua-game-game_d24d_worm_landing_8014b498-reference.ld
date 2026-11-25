/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24d_worm_landing_8014b498)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._11d24d_Handle = 0x80178474;
d24d_arena_alloc_801613f0 = 0x801613f0;
d24d_effect_800e5ca4 = 0x800e5ca4;
d24d_fall_ratio_803a13ac = 0x803a13ac;
d24d_ground_effect_800fdc80 = 0x800fdc80;
d24d_landing_blocked_8014df28 = 0x8014df28;
d24d_message_id_8015f5a0 = 0x8015f5a0;
d24d_message_init_800a82f0 = 0x800a82f0;
d24d_message_post_8016239c = 0x8016239c;
d24d_message_vtable_8040db38 = 0x8040db38;
d24d_owner_matches_8014c488 = 0x8014c488;
d24d_part_large_803a13c4 = 0x803a13c4;
d24d_part_small_803a13dc = 0x803a13dc;
d24d_setting_read_800fc270 = 0x800fc270;
d24d_worm_handle_800fc710 = 0x800fc710;
d24d_worm_knock_sound_80153aac = 0x80153aac;
SECTIONS {
  .text.d24d_worm_landing_8014b498 0x8014b498 : { *(.text.d24d_worm_landing_8014b498) }
  .rodata 0x803a13f0 : { *(.rodata) }
  .sdata 0x804ab3e8 (NOLOAD) : {
    . = 0x0; d24d_part_count_804ab3e8 = .;
    . = 0x4780; d24d_owner_key_804afb68 = .;
    . = 0x4878; d24d_landed_key_804afc60 = .;
    . = 0x636c; d24d_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
