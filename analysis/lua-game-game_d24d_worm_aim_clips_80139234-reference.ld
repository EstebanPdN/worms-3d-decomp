/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24d_worm_aim_clips_80139234)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d24d_aim_pigeon_8039f3ac = 0x8039f3ac;
d24d_blend_value_8013c844 = 0x8013c844;
d24d_empty_8039f59c = 0x8039f59c;
d24d_hold_quake_8039f660 = 0x8039f660;
d24d_mesh_fade_80181884 = 0x80181884;
d24d_mesh_fade_named_80181814 = 0x80181814;
d24d_play_clip_80135a70 = 0x80135a70;
d24d_play_named_801359ec = 0x801359ec;
d24d_resource_lookup_800fc330 = 0x800fc330;
d24d_resource_table_803eb63c = 0x803eb63c;
d24d_worm_info_800fc6dc = 0x800fc6dc;
strcmp = 0x802ef234;
SECTIONS {
  .text.d24d_worm_aim_clips_80139234 0x80139234 : { *(.text.d24d_worm_aim_clips_80139234) }
  .rodata 0x8039f66c : { *(.rodata) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; d24d_game_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
