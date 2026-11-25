/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_turns_publish_team_worm_count)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_factory_80410ef0 = 0x80410ef0;
w3d_fn_800fc1f0 = 0x800fc1f0;
w3d_fn_800fc43c = 0x800fc43c;
w3d_fn_800fc6dc = 0x800fc6dc;
w3d_fn_800fc7f8 = 0x800fc7f8;
w3d_fn_8015668c = 0x8015668c;
w3d_fn_80164514 = 0x80164514;
w3d_fn_8020b680 = 0x8020b680;
w3d_str_803a27ac = 0x803a27ac;
w3d_str_803a2a14 = 0x803a2a14;
w3d_str_803a2a20 = 0x803a2a20;
w3d_str_803a2a6c = 0x803a2a6c;
SECTIONS {
  .text.w3d_turns_publish_team_worm_count 0x80155574 : { *(.text.w3d_turns_publish_team_worm_count) }
  .text.w3d_turns_publish_worm_count 0x801555f8 : { *(.text.w3d_turns_publish_worm_count) }
  .text.w3d_turns_publish_team_count 0x80155688 : { *(.text.w3d_turns_publish_team_count) }
  .text.w3d_turns_next_team 0x80155784 : { *(.text.w3d_turns_next_team) }
  .text.w3d_turns_team_has_eligible 0x80155850 : { *(.text.w3d_turns_team_has_eligible) }
  .text.w3d_turns_publish_alliance_count 0x80155b44 : { *(.text.w3d_turns_publish_alliance_count) }
  .text.w3d_turns_create_actor_for_entity 0x80156ac4 : { *(.text.w3d_turns_create_actor_for_entity) }
  .text.w3d_turns_get_active_actor 0x80156f88 : { *(.text.w3d_turns_get_active_actor) }
  .sdata 0x804b178c (NOLOAD) : {
    . = 0x0; w3d_global_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
