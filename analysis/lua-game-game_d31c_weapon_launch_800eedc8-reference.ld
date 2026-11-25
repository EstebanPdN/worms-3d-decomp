/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d31c_weapon_launch_800eedc8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
add_80164514 = 0x80164514;
arena_801613f0 = 0x801613f0;
assign_800eb65c = 0x800eb65c;
cached_id_8015f5a0 = 0x8015f5a0;
cast_801797b4 = 0x801797b4;
cosf_802e86d4 = 0x802e86d4;
create_8020b680 = 0x8020b680;
empty_80341584 = 0x80341584;
empty_8040db38 = 0x8040db38;
euler_801a3eb0 = 0x801a3eb0;
forward_804494b0 = 0x804494b0;
i_8040ebf8 = 0x8040ebf8;
i_8040ec68 = 0x8040ec68;
i_8040f3e8 = 0x8040f3e8;
i_8040f750 = 0x8040f750;
i_8040fd78 = 0x8040fd78;
i_80410cc0 = 0x80410cc0;
pending_800ecec0 = 0x800ecec0;
position_800eb8d0 = 0x800eb8d0;
post_8016239c = 0x8016239c;
read_float_800fc270 = 0x800fc270;
read_int_800fc1f0 = 0x800fc1f0;
read_vec_800fc2f0 = 0x800fc2f0;
s_ball_8038bdb0 = 0x8038bdb0;
s_cow_8038b9ac = 0x8038b9ac;
s_donkey_8038b9cc = 0x8038b9cc;
s_eye_8038be2c = 0x8038be2c;
s_index_8038bd9c = 0x8038bd9c;
s_loc_8038be40 = 0x8038be40;
s_missile_8038b8f8 = 0x8038b8f8;
s_pidgeon_8038b920 = 0x8038b920;
s_power_8038be20 = 0x8038be20;
s_sheep_8038b94c = 0x8038b94c;
s_super_8038ba20 = 0x8038ba20;
s_vel_8038bdc4 = 0x8038bdc4;
s_woman_8038b9bc = 0x8038b9bc;
sinf_802e88ac = 0x802e88ac;
sqrt_802e82c0 = 0x802e82c0;
strcmp_802ef234 = 0x802ef234;
team_800fc7f8 = 0x800fc7f8;
velocity_800eb8f0 = 0x800eb8f0;
worm_800fc6dc = 0x800fc6dc;
zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.d31c_weapon_launch_800eedc8 0x800eedc8 : { *(.text.d31c_weapon_launch_800eedc8) }
  .rodata 0x8038be60 : { *(.rodata) }
  .sdata 0x804aab4c (NOLOAD) : {
    . = 0x0; clock_804aab4c = .;
    . = 0x4468; cache_804aefb4 = .;
    . = 0x6c08; arena_804b1754 = .;
    . = 0x6c40; world_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
